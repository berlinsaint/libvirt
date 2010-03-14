/* Automatically generated by remote_generate_stubs.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */

static int remoteDispatchAuthList (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_auth_list_ret *ret);
static int remoteDispatchAuthPolkit (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_auth_polkit_ret *ret);
static int remoteDispatchAuthSaslInit (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_auth_sasl_init_ret *ret);
static int remoteDispatchAuthSaslStart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_auth_sasl_start_args *args, remote_auth_sasl_start_ret *ret);
static int remoteDispatchAuthSaslStep (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_auth_sasl_step_args *args, remote_auth_sasl_step_ret *ret);
static int remoteDispatchClose (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, void *ret);
static int remoteDispatchDomainAttachDevice (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_attach_device_args *args, void *ret);
static int remoteDispatchDomainBlockPeek (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_block_peek_args *args, remote_domain_block_peek_ret *ret);
static int remoteDispatchDomainBlockStats (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_block_stats_args *args, remote_domain_block_stats_ret *ret);
static int remoteDispatchDomainCoreDump (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_core_dump_args *args, void *ret);
static int remoteDispatchDomainCreate (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_create_args *args, void *ret);
static int remoteDispatchDomainCreateLinux (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_create_linux_args *args, remote_domain_create_linux_ret *ret);
static int remoteDispatchDomainDefineXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_define_xml_args *args, remote_domain_define_xml_ret *ret);
static int remoteDispatchDomainDestroy (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_destroy_args *args, void *ret);
static int remoteDispatchDomainDetachDevice (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_detach_device_args *args, void *ret);
static int remoteDispatchDomainDumpXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_dump_xml_args *args, remote_domain_dump_xml_ret *ret);
static int remoteDispatchDomainGetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_autostart_args *args, remote_domain_get_autostart_ret *ret);
static int remoteDispatchDomainGetInfo (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_info_args *args, remote_domain_get_info_ret *ret);
static int remoteDispatchDomainGetMaxMemory (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_max_memory_args *args, remote_domain_get_max_memory_ret *ret);
static int remoteDispatchDomainGetMaxVcpus (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_max_vcpus_args *args, remote_domain_get_max_vcpus_ret *ret);
static int remoteDispatchDomainGetOsType (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_os_type_args *args, remote_domain_get_os_type_ret *ret);
static int remoteDispatchDomainGetSchedulerParameters (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_scheduler_parameters_args *args, remote_domain_get_scheduler_parameters_ret *ret);
static int remoteDispatchDomainGetSchedulerType (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_scheduler_type_args *args, remote_domain_get_scheduler_type_ret *ret);
static int remoteDispatchDomainGetVcpus (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_get_vcpus_args *args, remote_domain_get_vcpus_ret *ret);
static int remoteDispatchDomainInterfaceStats (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_interface_stats_args *args, remote_domain_interface_stats_ret *ret);
static int remoteDispatchDomainLookupById (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_lookup_by_id_args *args, remote_domain_lookup_by_id_ret *ret);
static int remoteDispatchDomainLookupByName (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_lookup_by_name_args *args, remote_domain_lookup_by_name_ret *ret);
static int remoteDispatchDomainLookupByUuid (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_lookup_by_uuid_args *args, remote_domain_lookup_by_uuid_ret *ret);
static int remoteDispatchDomainMemoryPeek (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_memory_peek_args *args, remote_domain_memory_peek_ret *ret);
static int remoteDispatchDomainMigrateFinish (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_migrate_finish_args *args, remote_domain_migrate_finish_ret *ret);
static int remoteDispatchDomainMigratePerform (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_migrate_perform_args *args, void *ret);
static int remoteDispatchDomainMigratePrepare (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_migrate_prepare_args *args, remote_domain_migrate_prepare_ret *ret);
static int remoteDispatchDomainPinVcpu (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_pin_vcpu_args *args, void *ret);
static int remoteDispatchDomainReboot (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_reboot_args *args, void *ret);
static int remoteDispatchDomainRestore (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_restore_args *args, void *ret);
static int remoteDispatchDomainResume (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_resume_args *args, void *ret);
static int remoteDispatchDomainSave (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_save_args *args, void *ret);
static int remoteDispatchDomainSetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_set_autostart_args *args, void *ret);
static int remoteDispatchDomainSetMaxMemory (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_set_max_memory_args *args, void *ret);
static int remoteDispatchDomainSetMemory (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_set_memory_args *args, void *ret);
static int remoteDispatchDomainSetSchedulerParameters (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_set_scheduler_parameters_args *args, void *ret);
static int remoteDispatchDomainSetVcpus (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_set_vcpus_args *args, void *ret);
static int remoteDispatchDomainShutdown (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_shutdown_args *args, void *ret);
static int remoteDispatchDomainSuspend (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_suspend_args *args, void *ret);
static int remoteDispatchDomainUndefine (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_domain_undefine_args *args, void *ret);
static int remoteDispatchFindStoragePoolSources (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_find_storage_pool_sources_args *args, remote_find_storage_pool_sources_ret *ret);
static int remoteDispatchGetCapabilities (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_get_capabilities_ret *ret);
static int remoteDispatchGetHostname (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_get_hostname_ret *ret);
static int remoteDispatchGetMaxVcpus (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_get_max_vcpus_args *args, remote_get_max_vcpus_ret *ret);
static int remoteDispatchGetType (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_get_type_ret *ret);
static int remoteDispatchGetVersion (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_get_version_ret *ret);
static int remoteDispatchListDefinedDomains (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_defined_domains_args *args, remote_list_defined_domains_ret *ret);
static int remoteDispatchListDefinedNetworks (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_defined_networks_args *args, remote_list_defined_networks_ret *ret);
static int remoteDispatchListDefinedStoragePools (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_defined_storage_pools_args *args, remote_list_defined_storage_pools_ret *ret);
static int remoteDispatchListDomains (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_domains_args *args, remote_list_domains_ret *ret);
static int remoteDispatchListNetworks (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_networks_args *args, remote_list_networks_ret *ret);
static int remoteDispatchListStoragePools (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_list_storage_pools_args *args, remote_list_storage_pools_ret *ret);
static int remoteDispatchNetworkCreate (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_create_args *args, void *ret);
static int remoteDispatchNetworkCreateXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_create_xml_args *args, remote_network_create_xml_ret *ret);
static int remoteDispatchNetworkDefineXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_define_xml_args *args, remote_network_define_xml_ret *ret);
static int remoteDispatchNetworkDestroy (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_destroy_args *args, void *ret);
static int remoteDispatchNetworkDumpXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_dump_xml_args *args, remote_network_dump_xml_ret *ret);
static int remoteDispatchNetworkGetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_get_autostart_args *args, remote_network_get_autostart_ret *ret);
static int remoteDispatchNetworkGetBridgeName (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_get_bridge_name_args *args, remote_network_get_bridge_name_ret *ret);
static int remoteDispatchNetworkLookupByName (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_lookup_by_name_args *args, remote_network_lookup_by_name_ret *ret);
static int remoteDispatchNetworkLookupByUuid (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_lookup_by_uuid_args *args, remote_network_lookup_by_uuid_ret *ret);
static int remoteDispatchNetworkSetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_set_autostart_args *args, void *ret);
static int remoteDispatchNetworkUndefine (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_network_undefine_args *args, void *ret);
static int remoteDispatchNodeGetCellsFreeMemory (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_node_get_cells_free_memory_args *args, remote_node_get_cells_free_memory_ret *ret);
static int remoteDispatchNodeGetFreeMemory (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_node_get_free_memory_ret *ret);
static int remoteDispatchNodeGetInfo (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_node_get_info_ret *ret);
static int remoteDispatchNumOfDefinedDomains (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_defined_domains_ret *ret);
static int remoteDispatchNumOfDefinedNetworks (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_defined_networks_ret *ret);
static int remoteDispatchNumOfDefinedStoragePools (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_defined_storage_pools_ret *ret);
static int remoteDispatchNumOfDomains (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_domains_ret *ret);
static int remoteDispatchNumOfNetworks (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_networks_ret *ret);
static int remoteDispatchNumOfStoragePools (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, void *args, remote_num_of_storage_pools_ret *ret);
static int remoteDispatchOpen (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_open_args *args, void *ret);
static int remoteDispatchStoragePoolBuild (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_build_args *args, void *ret);
static int remoteDispatchStoragePoolCreate (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_create_args *args, void *ret);
static int remoteDispatchStoragePoolCreateXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_create_xml_args *args, remote_storage_pool_create_xml_ret *ret);
static int remoteDispatchStoragePoolDefineXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_define_xml_args *args, remote_storage_pool_define_xml_ret *ret);
static int remoteDispatchStoragePoolDelete (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_delete_args *args, void *ret);
static int remoteDispatchStoragePoolDestroy (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_destroy_args *args, void *ret);
static int remoteDispatchStoragePoolDumpXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_dump_xml_args *args, remote_storage_pool_dump_xml_ret *ret);
static int remoteDispatchStoragePoolGetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_get_autostart_args *args, remote_storage_pool_get_autostart_ret *ret);
static int remoteDispatchStoragePoolGetInfo (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_get_info_args *args, remote_storage_pool_get_info_ret *ret);
static int remoteDispatchStoragePoolListVolumes (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_list_volumes_args *args, remote_storage_pool_list_volumes_ret *ret);
static int remoteDispatchStoragePoolLookupByName (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_lookup_by_name_args *args, remote_storage_pool_lookup_by_name_ret *ret);
static int remoteDispatchStoragePoolLookupByUuid (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_lookup_by_uuid_args *args, remote_storage_pool_lookup_by_uuid_ret *ret);
static int remoteDispatchStoragePoolLookupByVolume (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_lookup_by_volume_args *args, remote_storage_pool_lookup_by_volume_ret *ret);
static int remoteDispatchStoragePoolNumOfVolumes (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_num_of_volumes_args *args, remote_storage_pool_num_of_volumes_ret *ret);
static int remoteDispatchStoragePoolRefresh (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_refresh_args *args, void *ret);
static int remoteDispatchStoragePoolSetAutostart (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_set_autostart_args *args, void *ret);
static int remoteDispatchStoragePoolUndefine (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_pool_undefine_args *args, void *ret);
static int remoteDispatchStorageVolCreateXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_create_xml_args *args, remote_storage_vol_create_xml_ret *ret);
static int remoteDispatchStorageVolDelete (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_delete_args *args, void *ret);
static int remoteDispatchStorageVolDumpXml (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_dump_xml_args *args, remote_storage_vol_dump_xml_ret *ret);
static int remoteDispatchStorageVolGetInfo (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_get_info_args *args, remote_storage_vol_get_info_ret *ret);
static int remoteDispatchStorageVolGetPath (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_get_path_args *args, remote_storage_vol_get_path_ret *ret);
static int remoteDispatchStorageVolLookupByKey (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_lookup_by_key_args *args, remote_storage_vol_lookup_by_key_ret *ret);
static int remoteDispatchStorageVolLookupByName (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_lookup_by_name_args *args, remote_storage_vol_lookup_by_name_ret *ret);
static int remoteDispatchStorageVolLookupByPath (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_storage_vol_lookup_by_path_args *args, remote_storage_vol_lookup_by_path_ret *ret);
static int remoteDispatchSupportsFeature (struct qemud_server *server, struct qemud_client *client, remote_message_header *req, remote_supports_feature_args *args, remote_supports_feature_ret *ret);