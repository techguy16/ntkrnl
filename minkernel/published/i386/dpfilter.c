//
// Component filter levels.
//

ULONG Kd_SYSTEM_Mask = 0;
ULONG Kd_SMSS_Mask = 0;
ULONG Kd_SETUP_Mask = 0;
ULONG Kd_NTFS_Mask = 0;
ULONG Kd_FSTUB_Mask = 0;
ULONG Kd_CRASHDUMP_Mask = 0;
ULONG Kd_CDAUDIO_Mask = 0;
ULONG Kd_CDROM_Mask = 0;
ULONG Kd_CLASSPNP_Mask = 0;
ULONG Kd_DISK_Mask = 0;
ULONG Kd_REDBOOK_Mask = 0;
ULONG Kd_STORPROP_Mask = 0;
ULONG Kd_SCSIPORT_Mask = 0;
ULONG Kd_SCSIMINIPORT_Mask = 0;
ULONG Kd_CONFIG_Mask = 0;
ULONG Kd_I8042PRT_Mask = 0;
ULONG Kd_SERMOUSE_Mask = 0;
ULONG Kd_LSERMOUS_Mask = 0;
ULONG Kd_KBDHID_Mask = 0;
ULONG Kd_MOUHID_Mask = 0;
ULONG Kd_KBDCLASS_Mask = 0;
ULONG Kd_MOUCLASS_Mask = 0;
ULONG Kd_TWOTRACK_Mask = 0;
ULONG Kd_WMILIB_Mask = 0;
ULONG Kd_ACPI_Mask = 0;
ULONG Kd_AMLI_Mask = 0;
ULONG Kd_HALIA64_Mask = 0;
ULONG Kd_VIDEO_Mask = 0;
ULONG Kd_SVCHOST_Mask = 0;
ULONG Kd_VIDEOPRT_Mask = 0;
ULONG Kd_TCPIP_Mask = 0;
ULONG Kd_DMSYNTH_Mask = 0;
ULONG Kd_NTOSPNP_Mask = 0;
ULONG Kd_FASTFAT_Mask = 0;
ULONG Kd_SAMSS_Mask = 0;
ULONG Kd_PNPMGR_Mask = 0;
ULONG Kd_NETAPI_Mask = 0;
ULONG Kd_SCSERVER_Mask = 0;
ULONG Kd_SCCLIENT_Mask = 0;
ULONG Kd_SERIAL_Mask = 0;
ULONG Kd_SERENUM_Mask = 0;
ULONG Kd_UHCD_Mask = 0;
ULONG Kd_RPCPROXY_Mask = 0;
ULONG Kd_AUTOCHK_Mask = 0;
ULONG Kd_DCOMSS_Mask = 0;
ULONG Kd_UNIMODEM_Mask = 0;
ULONG Kd_SIS_Mask = 0;
ULONG Kd_FLTMGR_Mask = 0;
ULONG Kd_WMICORE_Mask = 0;
ULONG Kd_BURNENG_Mask = 0;
ULONG Kd_IMAPI_Mask = 0;
ULONG Kd_SXS_Mask = 0;
ULONG Kd_FUSION_Mask = 0;
ULONG Kd_IDLETASK_Mask = 0;
ULONG Kd_SOFTPCI_Mask = 0;
ULONG Kd_TAPE_Mask = 0;
ULONG Kd_MCHGR_Mask = 0;
ULONG Kd_IDEP_Mask = 0;
ULONG Kd_PCIIDE_Mask = 0;
ULONG Kd_FLOPPY_Mask = 0;
ULONG Kd_FDC_Mask = 0;
ULONG Kd_TERMSRV_Mask = 0;
ULONG Kd_W32TIME_Mask = 0;
ULONG Kd_PREFETCHER_Mask = 0;
ULONG Kd_RSFILTER_Mask = 0;
ULONG Kd_FCPORT_Mask = 0;
ULONG Kd_PCI_Mask = 0;
ULONG Kd_DMIO_Mask = 0;
ULONG Kd_DMCONFIG_Mask = 0;
ULONG Kd_DMADMIN_Mask = 0;
ULONG Kd_WSOCKTRANSPORT_Mask = 0;
ULONG Kd_VSS_Mask = 0;
ULONG Kd_PNPMEM_Mask = 0;
ULONG Kd_PROCESSOR_Mask = 0;
ULONG Kd_DMSERVER_Mask = 0;
ULONG Kd_SR_Mask = 0;
ULONG Kd_INFINIBAND_Mask = 0;
ULONG Kd_IHVDRIVER_Mask = 0;
ULONG Kd_IHVVIDEO_Mask = 0;
ULONG Kd_IHVAUDIO_Mask = 0;
ULONG Kd_IHVNETWORK_Mask = 0;
ULONG Kd_IHVSTREAMING_Mask = 0;
ULONG Kd_IHVBUS_Mask = 0;
ULONG Kd_HPS_Mask = 0;
ULONG Kd_RTLTHREADPOOL_Mask = 0;
ULONG Kd_LDR_Mask = 0;
ULONG Kd_TCPIP6_Mask = 0;
ULONG Kd_ISAPNP_Mask = 0;
ULONG Kd_SHPC_Mask = 0;
ULONG Kd_STORPORT_Mask = 0;
ULONG Kd_STORMINIPORT_Mask = 0;
ULONG Kd_PRINTSPOOLER_Mask = 0;
ULONG Kd_VSSDYNDISK_Mask = 0;
ULONG Kd_VERIFIER_Mask = 0;
ULONG Kd_VDS_Mask = 0;
ULONG Kd_VDSBAS_Mask = 0;
ULONG Kd_VDSDYNDR_Mask = 0;
ULONG Kd_VDSUTIL_Mask = 0;
ULONG Kd_DFRGIFC_Mask = 0;
ULONG Kd_ENDOFTABLE_Mask = 0;

//
// Component debug print filter table.
//

PULONG KdComponentTable[] = {
    &Kd_SYSTEM_Mask,
    &Kd_SMSS_Mask,
    &Kd_SETUP_Mask,
    &Kd_NTFS_Mask,
    &Kd_FSTUB_Mask,
    &Kd_CRASHDUMP_Mask,
    &Kd_CDAUDIO_Mask,
    &Kd_CDROM_Mask,
    &Kd_CLASSPNP_Mask,
    &Kd_DISK_Mask,
    &Kd_REDBOOK_Mask,
    &Kd_STORPROP_Mask,
    &Kd_SCSIPORT_Mask,
    &Kd_SCSIMINIPORT_Mask,
    &Kd_CONFIG_Mask,
    &Kd_I8042PRT_Mask,
    &Kd_SERMOUSE_Mask,
    &Kd_LSERMOUS_Mask,
    &Kd_KBDHID_Mask,
    &Kd_MOUHID_Mask,
    &Kd_KBDCLASS_Mask,
    &Kd_MOUCLASS_Mask,
    &Kd_TWOTRACK_Mask,
    &Kd_WMILIB_Mask,
    &Kd_ACPI_Mask,
    &Kd_AMLI_Mask,
    &Kd_HALIA64_Mask,
    &Kd_VIDEO_Mask,
    &Kd_SVCHOST_Mask,
    &Kd_VIDEOPRT_Mask,
    &Kd_TCPIP_Mask,
    &Kd_DMSYNTH_Mask,
    &Kd_NTOSPNP_Mask,
    &Kd_FASTFAT_Mask,
    &Kd_SAMSS_Mask,
    &Kd_PNPMGR_Mask,
    &Kd_NETAPI_Mask,
    &Kd_SCSERVER_Mask,
    &Kd_SCCLIENT_Mask,
    &Kd_SERIAL_Mask,
    &Kd_SERENUM_Mask,
    &Kd_UHCD_Mask,
    &Kd_RPCPROXY_Mask,
    &Kd_AUTOCHK_Mask,
    &Kd_DCOMSS_Mask,
    &Kd_UNIMODEM_Mask,
    &Kd_SIS_Mask,
    &Kd_FLTMGR_Mask,
    &Kd_WMICORE_Mask,
    &Kd_BURNENG_Mask,
    &Kd_IMAPI_Mask,
    &Kd_SXS_Mask,
    &Kd_FUSION_Mask,
    &Kd_IDLETASK_Mask,
    &Kd_SOFTPCI_Mask,
    &Kd_TAPE_Mask,
    &Kd_MCHGR_Mask,
    &Kd_IDEP_Mask,
    &Kd_PCIIDE_Mask,
    &Kd_FLOPPY_Mask,
    &Kd_FDC_Mask,
    &Kd_TERMSRV_Mask,
    &Kd_W32TIME_Mask,
    &Kd_PREFETCHER_Mask,
    &Kd_RSFILTER_Mask,
    &Kd_FCPORT_Mask,
    &Kd_PCI_Mask,
    &Kd_DMIO_Mask,
    &Kd_DMCONFIG_Mask,
    &Kd_DMADMIN_Mask,
    &Kd_WSOCKTRANSPORT_Mask,
    &Kd_VSS_Mask,
    &Kd_PNPMEM_Mask,
    &Kd_PROCESSOR_Mask,
    &Kd_DMSERVER_Mask,
    &Kd_SR_Mask,
    &Kd_INFINIBAND_Mask,
    &Kd_IHVDRIVER_Mask,
    &Kd_IHVVIDEO_Mask,
    &Kd_IHVAUDIO_Mask,
    &Kd_IHVNETWORK_Mask,
    &Kd_IHVSTREAMING_Mask,
    &Kd_IHVBUS_Mask,
    &Kd_HPS_Mask,
    &Kd_RTLTHREADPOOL_Mask,
    &Kd_LDR_Mask,
    &Kd_TCPIP6_Mask,
    &Kd_ISAPNP_Mask,
    &Kd_SHPC_Mask,
    &Kd_STORPORT_Mask,
    &Kd_STORMINIPORT_Mask,
    &Kd_PRINTSPOOLER_Mask,
    &Kd_VSSDYNDISK_Mask,
    &Kd_VERIFIER_Mask,
    &Kd_VDS_Mask,
    &Kd_VDSBAS_Mask,
    &Kd_VDSDYNDR_Mask,
    &Kd_VDSUTIL_Mask,
    &Kd_DFRGIFC_Mask,
    &Kd_ENDOFTABLE_Mask
};

