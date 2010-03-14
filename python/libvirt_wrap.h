/*
 * libvirt_wrap.h: type wrappers for libvir python bindings
 *
 * Copyright (C) 2005 Red Hat, Inc.
 *
 * Daniel Veillard <veillard@redhat.com>
 */

#include <Python.h>
#include "libvirt/libvirt.h"
#include "libvirt/virterror.h"

#ifdef __GNUC__
#ifdef ATTRIBUTE_UNUSED
#undef ATTRIBUTE_UNUSED
#endif
#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif /* ATTRIBUTE_UNUSED */
#else
#define ATTRIBUTE_UNUSED
#endif

#define PyvirConnect_Get(v) (((v) == Py_None) ? NULL : \
        (((PyvirConnect_Object *)(v))->obj))

typedef struct {
    PyObject_HEAD
    virConnectPtr obj;
} PyvirConnect_Object;


#define PyvirDomain_Get(v) (((v) == Py_None) ? NULL : \
        (((PyvirDomain_Object *)(v))->obj))

typedef struct {
    PyObject_HEAD
    virDomainPtr obj;
} PyvirDomain_Object;


#define PyvirNetwork_Get(v) (((v) == Py_None) ? NULL : \
        (((PyvirNetwork_Object *)(v))->obj))

typedef struct {
    PyObject_HEAD
    virNetworkPtr obj;
} PyvirNetwork_Object;


#define PyvirStoragePool_Get(v) (((v) == Py_None) ? NULL : \
        (((PyvirStoragePool_Object *)(v))->obj))

typedef struct {
    PyObject_HEAD
    virStoragePoolPtr obj;
} PyvirStoragePool_Object;


#define PyvirStorageVol_Get(v) (((v) == Py_None) ? NULL : \
        (((PyvirStorageVol_Object *)(v))->obj))

typedef struct {
    PyObject_HEAD
    virStorageVolPtr obj;
} PyvirStorageVol_Object;


PyObject * libvirt_intWrap(int val);
PyObject * libvirt_longWrap(long val);
PyObject * libvirt_ulongWrap(unsigned long val);
PyObject * libvirt_longlongWrap(long long val);
PyObject * libvirt_charPtrWrap(char *str);
PyObject * libvirt_constcharPtrWrap(const char *str);
PyObject * libvirt_charPtrConstWrap(const char *str);
PyObject * libvirt_virConnectPtrWrap(virConnectPtr node);
PyObject * libvirt_virDomainPtrWrap(virDomainPtr node);
PyObject * libvirt_virNetworkPtrWrap(virNetworkPtr node);
PyObject * libvirt_virStoragePoolPtrWrap(virStoragePoolPtr node);
PyObject * libvirt_virStorageVolPtrWrap(virStorageVolPtr node);


/* Provide simple macro statement wrappers (adapted from GLib, in turn from Perl):
 *  LIBVIRT_STMT_START { statements; } LIBVIRT_STMT_END;
 *  can be used as a single statement, as in
 *  if (x) LIBVIRT_STMT_START { ... } LIBVIRT_STMT_END; else ...
 *
 *  When GCC is compiling C code in non-ANSI mode, it will use the
 *  compiler __extension__ to wrap the statements within `({' and '})' braces.
 *  When compiling on platforms where configure has defined
 *  HAVE_DOWHILE_MACROS, statements will be wrapped with `do' and `while (0)'.
 *  For any other platforms (SunOS4 is known to have this issue), wrap the
 *  statements with `if (1)' and `else (void) 0'.
 */
#if !(defined (LIBVIRT_STMT_START) && defined (LIBVIRT_STMT_END))
# if defined (__GNUC__) && !defined (__STRICT_ANSI__) && !defined (__cplusplus)
#  define LIBVIRT_STMT_START (void) __extension__ (
#  define LIBVIRT_STMT_END )
# else /* !(__GNUC__ && !__STRICT_ANSI__ && !__cplusplus) */
#  if defined (HAVE_DOWHILE_MACROS)
#   define LIBVIRT_STMT_START do
#   define LIBVIRT_STMT_END while (0)
#  else /* !HAVE_DOWHILE_MACROS */
#   define LIBVIRT_STMT_START if (1)
#   define LIBVIRT_STMT_END else (void) 0
#  endif /* !HAVE_DOWHILE_MACROS */
# endif /* !(__GNUC__ && !__STRICT_ANSI__ && !__cplusplus) */
#endif

#define LIBVIRT_BEGIN_ALLOW_THREADS			\
  LIBVIRT_STMT_START {					\
    PyThreadState *_save = NULL;			\
    if (PyEval_ThreadsInitialized())			\
      _save = PyEval_SaveThread();

#define LIBVIRT_END_ALLOW_THREADS                           \
  if (PyEval_ThreadsInitialized())			    \
    PyEval_RestoreThread(_save);			    \
    } LIBVIRT_STMT_END

#define LIBVIRT_ENSURE_THREAD_STATE			\
  LIBVIRT_STMT_START {					\
    PyGILState_STATE _save = PyGILState_UNLOCKED;	\
    if (PyEval_ThreadsInitialized())			\
      _save = PyGILState_Ensure();

#define LIBVIRT_RELEASE_THREAD_STATE                           \
  if (PyEval_ThreadsInitialized())			       \
    PyGILState_Release(_save);				       \
  } LIBVIRT_STMT_END
