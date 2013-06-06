/*
 * Copyright (C) 2011-2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * License along with this library;  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 */


#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <selinux/selinux.h>
#include <selinux/context.h>

#include "internal.h"
#include "testutils.h"
#include "testutilsqemu.h"
#include "qemu/qemu_domain.h"
#include "viralloc.h"
#include "virerror.h"
#include "virfile.h"
#include "virlog.h"
#include "security/security_manager.h"
#include "virstring.h"

#define VIR_FROM_THIS VIR_FROM_NONE

static virCapsPtr caps;
static virDomainXMLOptionPtr xmlopt;

static virSecurityManagerPtr mgr;

typedef struct testSELinuxFile testSELinuxFile;

struct testSELinuxFile {
    char *file;
    char *context;
};


static int
testSELinuxMungePath(char **path)
{
    char *tmp;

    if (virAsprintf(&tmp, "%s/securityselinuxlabeldata%s",
                    abs_builddir, *path) < 0) {
        virReportOOMError();
        return -1;
    }

    VIR_FREE(*path);
    *path = tmp;
    return 0;
}

static int
testSELinuxLoadFileList(const char *testname,
                        testSELinuxFile **files,
                        size_t *nfiles)
{
    int ret = -1;
    char *path = NULL;
    FILE *fp = NULL;

    *files = NULL;
    *nfiles = 0;

    if (virAsprintf(&path, "%s/securityselinuxlabeldata/%s.txt",
                    abs_srcdir, testname) < 0) {
        virReportOOMError();
        goto cleanup;
    }

    if (!(fp = fopen(path, "r"))) {
        goto cleanup;
    }

    while (!feof(fp)) {
        char *line;
        char *file, *context;
        if (VIR_ALLOC_N(line, 1024) < 0) {
            virReportOOMError();
            goto cleanup;
        }
        if (!fgets(line, 1024, fp)) {
            if (!feof(fp))
                goto cleanup;
            break;
        }

        char *tmp = strchr(line, ';');
        *tmp = '\0';
        tmp++;

        if (virAsprintf(&file, "%s/securityselinuxlabeldata%s", abs_builddir, line) < 0) {
            VIR_FREE(line);
            virReportOOMError();
            goto cleanup;
        }
        if (*tmp != '\0' && *tmp != '\n') {
            if (VIR_STRDUP(context, tmp) < 0) {
                VIR_FREE(line);
                VIR_FREE(file);
                goto cleanup;
            }

            tmp = strchr(context, '\n');
            *tmp = '\0';
        } else {
            context = NULL;
        }

        if (VIR_EXPAND_N(*files, *nfiles, 1) < 0) {
            virReportOOMError();
            goto cleanup;
        }

        (*files)[(*nfiles)-1].file = file;
        (*files)[(*nfiles)-1].context = context;
    }

    ret = 0;

cleanup:
    VIR_FORCE_FCLOSE(fp);
    VIR_FREE(path);
    return ret;
}


static virDomainDefPtr
testSELinuxLoadDef(const char *testname)
{
    char *xmlfile = NULL;
    char *xmlstr = NULL;
    virDomainDefPtr def = NULL;
    size_t i;

    if (virAsprintf(&xmlfile, "%s/securityselinuxlabeldata/%s.xml",
                    abs_srcdir, testname) < 0) {
        virReportOOMError();
        goto cleanup;
    }

    if (virFileReadAll(xmlfile, 1024*1024, &xmlstr) < 0) {
        goto cleanup;
    }

    if (!(def = virDomainDefParseString(xmlstr, caps, xmlopt,
                                        QEMU_EXPECTED_VIRT_TYPES,
                                        0)))
        goto cleanup;

    for (i = 0; i < def->ndisks; i++) {
        if (def->disks[i]->type != VIR_DOMAIN_DISK_TYPE_FILE &&
            def->disks[i]->type != VIR_DOMAIN_DISK_TYPE_BLOCK)
            continue;

        if (testSELinuxMungePath(&def->disks[i]->src) < 0)
            goto cleanup;
    }

    for (i = 0; i < def->nserials; i++) {
        if (def->serials[i]->source.type != VIR_DOMAIN_CHR_TYPE_FILE &&
            def->serials[i]->source.type != VIR_DOMAIN_CHR_TYPE_PIPE &&
            def->serials[i]->source.type != VIR_DOMAIN_CHR_TYPE_DEV &&
            def->serials[i]->source.type != VIR_DOMAIN_CHR_TYPE_UNIX)
            continue;

        if (def->serials[i]->source.type == VIR_DOMAIN_CHR_TYPE_UNIX) {
            if (testSELinuxMungePath(&def->serials[i]->source.data.nix.path) < 0)
                goto cleanup;
        } else {
            if (testSELinuxMungePath(&def->serials[i]->source.data.file.path) < 0)
                goto cleanup;
        }
    }

    if (def->os.kernel &&
        testSELinuxMungePath(&def->os.kernel) < 0)
        goto cleanup;
    if (def->os.initrd &&
        testSELinuxMungePath(&def->os.initrd) < 0)
        goto cleanup;

cleanup:
    VIR_FREE(xmlfile);
    VIR_FREE(xmlstr);
    return def;
}


static int
testSELinuxCreateDisks(testSELinuxFile *files, size_t nfiles)
{
    size_t i;

    if (virFileMakePath(abs_builddir "/securityselinuxlabeldata") < 0)
        return -1;

    for (i = 0; i < nfiles; i++) {
        if (virFileTouch(files[i].file, 0600) < 0)
            return -1;
    }
    return 0;
}

static int
testSELinuxDeleteDisks(testSELinuxFile *files, size_t nfiles)
{
    size_t i;

    for (i = 0; i < nfiles; i++) {
        if (unlink(files[i].file) < 0)
            return -1;
    }
    return 0;
}

static int
testSELinuxCheckLabels(testSELinuxFile *files, size_t nfiles)
{
    size_t i;
    security_context_t ctx;

    for (i = 0; i < nfiles; i++) {
        if (getfilecon(files[i].file, &ctx) < 0) {
            if (errno == ENODATA) {
                ctx = NULL;
            } else {
                virReportSystemError(errno,
                                     "Cannot read label on %s",
                                     files[i].file);
                return -1;
            }
        }
        if (!STREQ_NULLABLE(files[i].context, ctx)) {
            virReportError(VIR_ERR_INTERNAL_ERROR,
                           "File %s context '%s' did not match epected '%s'",
                           files[i].file, ctx, files[i].context);
            return -1;
        }
    }
    return 0;
}

static int
testSELinuxLabeling(const void *opaque)
{
    const char *testname = opaque;
    int ret = -1;
    testSELinuxFile *files = NULL;
    size_t nfiles = 0;
    size_t i;
    virDomainDefPtr def = NULL;

    if (testSELinuxLoadFileList(testname, &files, &nfiles) < 0)
        goto cleanup;

    if (testSELinuxCreateDisks(files, nfiles) < 0)
        goto cleanup;

    if (!(def = testSELinuxLoadDef(testname)))
        goto cleanup;

    if (virSecurityManagerSetAllLabel(mgr, def, NULL) < 0)
        goto cleanup;

    if (testSELinuxCheckLabels(files, nfiles) < 0)
        goto cleanup;

    ret = 0;

cleanup:
    if (testSELinuxDeleteDisks(files, nfiles) < 0)
        goto cleanup;

    virDomainDefFree(def);
    for (i = 0; i < nfiles; i++) {
        VIR_FREE(files[i].file);
        VIR_FREE(files[i].context);
    }
    VIR_FREE(files);
    if (ret < 0 && virTestGetVerbose()) {
        virErrorPtr err = virGetLastError();
        fprintf(stderr, "%s\n", err ? err->message : "<unknown>");
    }
    return ret;
}



static int
mymain(void)
{
    int ret = 0;

    if (!(mgr = virSecurityManagerNew("selinux", "QEMU", false, true, false))) {
        virErrorPtr err = virGetLastError();
        if (err->code == VIR_ERR_CONFIG_UNSUPPORTED)
            return EXIT_AM_SKIP;

        fprintf(stderr, "Unable to initialize security driver: %s\n",
                err->message);
        return EXIT_FAILURE;
    }

    if ((caps = testQemuCapsInit()) == NULL)
        return EXIT_FAILURE;

    if (!(xmlopt = virQEMUDriverCreateXMLConf(NULL)))
        return EXIT_FAILURE;

#define DO_TEST_LABELING(name) \
    if (virtTestRun("Labelling " # name, 1, testSELinuxLabeling, name) < 0) \
        ret = -1;                                                       \

    setcon((security_context_t)"system_r:system_u:libvirtd_t:s0:c0.c1023");

    DO_TEST_LABELING("disks");
    DO_TEST_LABELING("kernel");
    DO_TEST_LABELING("chardev");

    return (ret == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

VIRT_TEST_MAIN_PRELOAD(mymain, abs_builddir "/.libs/libsecurityselinuxhelper.so")
