/*++

Copyright (c) 1991  Microsoft Corporation

Module Name:

    msgs.h

Abstract:

    This file contains the message definitions for setupldr

Author:

    John Vert (jvert) 12-Nov-1993

Revision History:

Notes:

    This file is generated from msgs.mc

--*/

#ifndef _SETUPLDR_MSG_
#define _SETUPLDR_MSG_


//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: SL_MSG_FIRST
//
// MessageText:
//
//  SL_MSG_FIRST
//
#define SL_MSG_FIRST                     0x00002328L

//
// MessageId: SL_SCRN_WELCOME
//
// MessageText:
//
//  Welcome to Windows Setup
//  
//    Press ENTER to continue
//  
//       Press F3 to Exit
//
#define SL_SCRN_WELCOME                  0x00002329L

//
// MessageId: SL_WELCOME_HEADER
//
// MessageText:
//
//  
//  Windows Setup
//  ���������������
//
#define SL_WELCOME_HEADER                0x0000232AL

//
// MessageId: SL_TOTAL_SETUP_DEATH
//
// MessageText:
//
//  Setup failed. Press any key to restart your computer.
//
#define SL_TOTAL_SETUP_DEATH             0x0000232BL

//
// MessageId: SL_FILE_LOAD_MESSAGE
//
// MessageText:
//
//  Setup is loading files (%s)...
//
#define SL_FILE_LOAD_MESSAGE             0x0000232CL

//
// MessageId: SL_OTHER_SELECTION
//
// MessageText:
//
//  Other (requires an OEM driver diskette)
//
#define SL_OTHER_SELECTION               0x0000232DL

//
// MessageId: SL_SELECT_DRIVER_PROMPT
//
// MessageText:
//
//  ENTER=Select  F3=Exit
//
#define SL_SELECT_DRIVER_PROMPT          0x0000232EL

//
// MessageId: SL_NEXT_DISK_PROMPT_CANCELLABLE
//
// MessageText:
//
//  ENTER=Continue  ESC=Cancel  F3=Exit
//
#define SL_NEXT_DISK_PROMPT_CANCELLABLE  0x0000232FL

//
// MessageId: SL_OEM_DISK_PROMPT
//
// MessageText:
//
//  Manufacturer-supplied hardware support disk
//
#define SL_OEM_DISK_PROMPT               0x00002330L

//
// MessageId: SL_MSG_INSERT_DISK
//
// MessageText:
//
//  Please insert the disk labeled
//  
//  
//  
//           into Drive A:
//  
//   *  Press ENTER when ready.
//
#define SL_MSG_INSERT_DISK               0x00002331L

//
// MessageId: SL_MSG_EXIT_DIALOG
//
// MessageText:
//
//  ������������������������������������������������������
//  �  Windows is not completely set up on your          �
//  �  system. If you quit Setup now, you will need      �
//  �  to run Setup again to set up Windows.             �
//  �                                                    �
//  �     * Press ENTER to continue Setup.               �
//  �     * Press F3 to quit Setup.                      �
//  ������������������������������������������������������
//  �  F3=Exit  ENTER=Continue                           �
//  ������������������������������������������������������
//
#define SL_MSG_EXIT_DIALOG               0x00002332L

//
// MessageId: SL_NEXT_DISK_PROMPT
//
// MessageText:
//
//  ENTER=Continue  F3=Exit
//
#define SL_NEXT_DISK_PROMPT              0x00002333L

//
// MessageId: SL_NTDETECT_PROMPT
//
// MessageText:
//
//  
//  Setup is inspecting your computer's hardware configuration...
//  
//
#define SL_NTDETECT_PROMPT               0x00002334L

//
// MessageId: SL_KERNEL_NAME
//
// MessageText:
//
//  Windows Executive
//
#define SL_KERNEL_NAME                   0x00002335L

//
// MessageId: SL_HAL_NAME
//
// MessageText:
//
//  Hardware Abstraction Layer
//
#define SL_HAL_NAME                      0x00002336L

//
// MessageId: SL_PAL_NAME
//
// MessageText:
//
//  Windows Processor Extensions
//
#define SL_PAL_NAME                      0x00002337L

//
// MessageId: SL_HIVE_NAME
//
// MessageText:
//
//  Windows Configuration Data
//
#define SL_HIVE_NAME                     0x00002338L

//
// MessageId: SL_NLS_NAME
//
// MessageText:
//
//  Locale-Specific Data
//
#define SL_NLS_NAME                      0x00002339L

//
// MessageId: SL_OEM_FONT_NAME
//
// MessageText:
//
//  Setup Font
//
#define SL_OEM_FONT_NAME                 0x0000233AL

//
// MessageId: SL_SETUP_NAME
//
// MessageText:
//
//  Windows Setup
//
#define SL_SETUP_NAME                    0x0000233BL

//
// MessageId: SL_FLOPPY_NAME
//
// MessageText:
//
//  Floppy Disk Driver
//
#define SL_FLOPPY_NAME                   0x0000233CL

//
// MessageId: SL_KBD_NAME
//
// MessageText:
//
//  Keyboard Driver
//
#define SL_KBD_NAME                      0x0000233DL

//
// MessageId: SL_FAT_NAME
//
// MessageText:
//
//  FAT File System
//
#define SL_FAT_NAME                      0x000023A1L

//
// MessageId: SL_SCSIPORT_NAME
//
// MessageText:
//
//  SCSI Port Driver
//
#define SL_SCSIPORT_NAME                 0x0000233EL

//
// MessageId: SL_VIDEO_NAME
//
// MessageText:
//
//  Video Driver
//
#define SL_VIDEO_NAME                    0x0000233FL

//
// MessageId: SL_STATUS_REBOOT
//
// MessageText:
//
//  Press any key to restart your computer.
//
#define SL_STATUS_REBOOT                 0x00002340L

//
// MessageId: SL_WARNING_ERROR
//
// MessageText:
//
//  An unexpected error (%d) occurred at
//  line %d in %s.
//  
//  Press any key to continue.
//
#define SL_WARNING_ERROR                 0x00002341L

//
// MessageId: SL_FLOPPY_NOT_FOUND
//
// MessageText:
//
//  Only %d floppy drives were found,
//  the system was trying to find drive %d.
//
#define SL_FLOPPY_NOT_FOUND              0x00002342L

//
// MessageId: SL_NO_MEMORY
//
// MessageText:
//
//  The system has run out of memory at
//  line %d in file %s
//
#define SL_NO_MEMORY                     0x00002343L

//
// MessageId: SL_IO_ERROR
//
// MessageText:
//
//  The system encountered an I/O error
//  accessing %s.
//
#define SL_IO_ERROR                      0x00002344L

//
// MessageId: SL_BAD_INF_SECTION
//
// MessageText:
//
//  Section %s of the INF file is invalid
//
#define SL_BAD_INF_SECTION               0x00002345L

//
// MessageId: SL_BAD_INF_LINE
//
// MessageText:
//
//  Line %d of the INF file %s is invalid
//
#define SL_BAD_INF_LINE                  0x00002346L

//
// MessageId: SL_BAD_INF_FILE
//
// MessageText:
//
//  INF file %s is corrupt or missing, status %d.
//
#define SL_BAD_INF_FILE                  0x00002347L

//
// MessageId: SL_FILE_LOAD_FAILED
//
// MessageText:
//
//  File %s could not be loaded.
//  The error code is %d
//
#define SL_FILE_LOAD_FAILED              0x00002348L

//
// MessageId: SL_INF_ENTRY_MISSING
//
// MessageText:
//
//  The entry "%s" in the [%s] section
//  of the INF file is corrupt or missing.
//
#define SL_INF_ENTRY_MISSING             0x00002349L

//
// MessageId: SL_PLEASE_WAIT
//
// MessageText:
//
//  Please wait...
//
#define SL_PLEASE_WAIT                   0x0000234AL

//
// MessageId: SL_CANT_CONTINUE
//
// MessageText:
//
//  Setup cannot continue. Press any key to exit.
//
#define SL_CANT_CONTINUE                 0x0000234BL

//
// MessageId: SL_PROMPT_SCSI
//
// MessageText:
//
//  Select the SCSI Adapter you want from the following list, or select "Other"
//  if you have a device support disk provided by an adapter manufacturer.
//  
//
#define SL_PROMPT_SCSI                   0x0000234CL

//
// MessageId: SL_PROMPT_OEM_SCSI
//
// MessageText:
//
//  You have chosen to configure a SCSI Adapter for use with Windows,
//  using a device support disk provided by an adapter manufacturer.
//  
//  Select the SCSI Adapter you want from the following list, or press ESC
//  to return to the previous screen.
//  
//
#define SL_PROMPT_OEM_SCSI               0x0000234DL

//
// MessageId: SL_PROMPT_HAL
//
// MessageText:
//
//  Setup could not determine the type of computer you have, or you have
//  chosen to manually specify the computer type.
//  
//  Select the computer type from the following list, or select "Other"
//  if you have a device support disk provided by your computer manufacturer.
//  
//  To scroll through the menu items press up arrow or down arrow.
//  
//
#define SL_PROMPT_HAL                    0x0000234EL

//
// MessageId: SL_PROMPT_OEM_HAL
//
// MessageText:
//
//  You have chosen to configure a computer for use with Windows,
//  using a device support disk provided by the computer's manufacturer.
//  
//  Select the computer type from the following list, or press ESC
//  to return to the previous screen.
//  
//  To scroll through the menu items press up arrow or down arrow.
//  
//
#define SL_PROMPT_OEM_HAL                0x0000234FL

//
// MessageId: SL_PROMPT_VIDEO
//
// MessageText:
//
//  Setup could not determine the type of video adapter installed in the system.
//  
//  Select the video Adapter you want from the following list, or select "Other"
//  if you have a device support disk provided by an adapter manufacturer.
//  
//
#define SL_PROMPT_VIDEO                  0x00002350L

//
// MessageId: SL_PROMPT_OEM_VIDEO
//
// MessageText:
//
//  You have chosen to configure a video Adapter for use with Windows,
//  using a device support disk provided by an adapter manufacturer.
//  
//  Select the video Adapter you want from the following list, or press ESC
//  to return to the previous screen.
//  
//
#define SL_PROMPT_OEM_VIDEO              0x00002351L

//
// MessageId: SL_WARNING_ERROR_WFILE
//
// MessageText:
//
//  File %s caused an unexpected error (%d) at
//  line %d in %s.
//  
//  Press any key to continue.
//
#define SL_WARNING_ERROR_WFILE           0x00002352L

//
// MessageId: SL_WARNING_IMG_CORRUPT
//
// MessageText:
//
//  The file %s is corrupted.
//  
//  Press any key to continue.
//
#define SL_WARNING_IMG_CORRUPT           0x00002353L

//
// MessageId: SL_WARNING_IOERR
//
// MessageText:
//
//  An I/O error occurred on file %s.
//  
//  Press any key to continue.
//
#define SL_WARNING_IOERR                 0x00002354L

//
// MessageId: SL_WARNING_NOFILE
//
// MessageText:
//
//  The file %s could not be found.
//  
//  Press any key to continue.
//
#define SL_WARNING_NOFILE                0x00002355L

//
// MessageId: SL_WARNING_NOMEM
//
// MessageText:
//
//  Insufficient memory for %s.
//  
//  Press any key to continue.
//
#define SL_WARNING_NOMEM                 0x00002356L

//
// MessageId: SL_DRIVE_ERROR
//
// MessageText:
//
//  SETUPLDR: Couldn't open drive %s
//
#define SL_DRIVE_ERROR                   0x00002357L

//
// MessageId: SL_NTDETECT_MSG
//
// MessageText:
//
//  
//  Setup is inspecting your computer's hardware configuration...
//  
//
#define SL_NTDETECT_MSG                  0x00002358L

//
// MessageId: SL_NTDETECT_FAILURE
//
// MessageText:
//
//  NTDETECT failed
//
#define SL_NTDETECT_FAILURE              0x00002359L

//
// MessageId: SL_SCRN_TEXTSETUP_EXITED
//
// MessageText:
//
//  Windows has not been installed.
//  
//  If there is a floppy disk inserted in drive A:, remove it.
//  
//  Press ENTER to restart your computer.
//
#define SL_SCRN_TEXTSETUP_EXITED         0x0000235AL

//
// MessageId: SL_SCRN_TEXTSETUP_EXITED_ARC
//
// MessageText:
//
//  Windows has not been installed.
//  
//  Press ENTER to restart your computer.
//
#define SL_SCRN_TEXTSETUP_EXITED_ARC     0x0000235BL

//
// MessageId: SL_REBOOT_PROMPT
//
// MessageText:
//
//  ENTER=Restart Computer
//
#define SL_REBOOT_PROMPT                 0x0000235CL

//
// MessageId: SL_WARNING_SIF_NO_DRIVERS
//
// MessageText:
//
//  Setup could not find any drivers associated with your selection.
//  
//  Press any key to continue.
//
#define SL_WARNING_SIF_NO_DRIVERS        0x0000235DL

//
// MessageId: SL_WARNING_SIF_NO_COMPONENT
//
// MessageText:
//
//  The disk you have supplied does not provide any relevant support files.
//  
//  Press any key to continue.
//
#define SL_WARNING_SIF_NO_COMPONENT      0x0000235EL

//
// MessageId: SL_WARNING_BAD_FILESYS
//
// MessageText:
//
//  This disk cannot be read because it contains an unrecognized file system.
//  
//  Press any key to continue.
//
#define SL_WARNING_BAD_FILESYS           0x0000235FL

//
// MessageId: SL_BAD_UNATTENDED_SCRIPT_FILE
//
// MessageText:
//
//  The entry
//  
//  "%s"
//  
//  in the unattended script file doesn't exist
//  in the [%s] section of the INF file %s.
//
#define SL_BAD_UNATTENDED_SCRIPT_FILE    0x00002360L

//
// MessageId: SL_MSG_PRESS_F5_OR_F6
//
// MessageText:
//
//  Press F6 if you need to install a third party SCSI or RAID driver...
//
#define SL_MSG_PRESS_F5_OR_F6            0x00002361L

//
// The following three messages are used to provide the same mnemonic
// keypress as is used in the Additional SCSI screen in setupdd.sys
// (see setup\textmode\user\msg.mc--SP_MNEMONICS and SP_MNEMONICS_INFO)
// The single character specified in SL_SCSI_SELECT_MNEMONIC must be
// the same as that listed in the status text of SL_SCSI_SELECT_PROMPT
// (and also referenced in the SL_SCSI_SELECT_MESSAGE_2).
//
//
// MessageId: SL_SCSI_SELECT_MNEMONIC
//
// MessageText:
//
//  S
//
#define SL_SCSI_SELECT_MNEMONIC          0x00002364L

//
// MessageId: SL_SCSI_SELECT_PROMPT
//
// MessageText:
//
//  S=Specify Additional Device   ENTER=Continue   F3=Exit
//
#define SL_SCSI_SELECT_PROMPT            0x00002365L

//
// MessageId: SL_SCSI_SELECT_MESSAGE_2
//
// MessageText:
//
//    * To specify additional SCSI adapters, CD-ROM drives, or special
//      disk controllers for use with Windows, including those for
//      which you have a device support disk from a mass storage device
//      manufacturer, press S.
//  
//    * If you do not have any device support disks from a mass storage
//      device manufacturer, or do not want to specify additional
//      mass storage devices for use with Windows, press ENTER.
//
#define SL_SCSI_SELECT_MESSAGE_2         0x00002366L

//
// MessageId: SL_SCSI_SELECT_MESSAGE_1
//
// MessageText:
//
//  Setup could not determine the type of one or more mass storage devices
//  installed in your system, or you have chosen to manually specify an adapter.
//  Currently, Setup will load support for the following mass storage devices(s):
//
#define SL_SCSI_SELECT_MESSAGE_1         0x00002367L

//
// MessageId: SL_SCSI_SELECT_MESSAGE_3
//
// MessageText:
//
//  Setup will load support for the following mass storage device(s):
//
#define SL_SCSI_SELECT_MESSAGE_3         0x00002368L

//
// MessageId: SL_SCSI_SELECT_ERROR
//
// MessageText:
//
//  Setup was unable to load support for the mass storage device you specified.
//  Currently, Setup will load support for the following mass storage devices(s):
//
#define SL_SCSI_SELECT_ERROR             0x00002369L

//
// MessageId: SL_TEXT_ANGLED_NONE
//
// MessageText:
//
//  <none>
//
#define SL_TEXT_ANGLED_NONE              0x0000236AL

//
// MessageId: SL_TEXT_SCSI_UNNAMED
//
// MessageText:
//
//  <unnamed adapter>
//
#define SL_TEXT_SCSI_UNNAMED             0x0000236BL

//
// MessageId: SL_TEXT_OTHER_DRIVER
//
// MessageText:
//
//  Other
//
#define SL_TEXT_OTHER_DRIVER             0x0000236CL

//
// MessageId: SL_TEXT_REQUIRES_486
//
// MessageText:
//
//  Windows requires an 80486 or later processor.
//
#define SL_TEXT_REQUIRES_486             0x0000236DL

//
// MessageId: SL_NTPNP_NAME
//
// MessageText:
//
//  Plug & Play Export Driver
//
#define SL_NTPNP_NAME                    0x0000236EL

//
// MessageId: SL_PCI_IDE_EXTENSIONS_NAME
//
// MessageText:
//
//  PCI IDE Extensions Driver
//
#define SL_PCI_IDE_EXTENSIONS_NAME       0x0000236FL

//
// MessageId: SL_HW_FW_CFG_CLASS
//
// MessageText:
//
//  Windows could not start because of the following ARC
//  firmware boot configuration problem :
//
#define SL_HW_FW_CFG_CLASS               0x00002370L

//
// MessageId: DIAG_SL_FW_GET_BOOT_DEVICE
//
// MessageText:
//
//  The 'osloadpartition' parameter setting is invalid.
//
#define DIAG_SL_FW_GET_BOOT_DEVICE       0x00002371L

//
// MessageId: LOAD_HW_FW_CFG_ACT
//
// MessageText:
//
//  Please check the Windows documentation about ARC configuration
//  options and your hardware reference manuals for additional
//  information.
//
#define LOAD_HW_FW_CFG_ACT               0x00002372L

//
// MessageId: SL_NETADAPTER_NAME
//
// MessageText:
//
//  Network Adapter Driver
//
#define SL_NETADAPTER_NAME               0x00002373L

//
// MessageId: SL_TCPIP_NAME
//
// MessageText:
//
//  TCP/IP Service
//
#define SL_TCPIP_NAME                    0x00002374L

//
// MessageId: SL_NETBT_NAME
//
// MessageText:
//
//  WINS Client(TCP/IP) Service
//
#define SL_NETBT_NAME                    0x00002375L

//
// MessageId: SL_MRXSMB_NAME
//
// MessageText:
//
//  MRXSMB mini-redirector
//
#define SL_MRXSMB_NAME                   0x00002376L

//
// MessageId: SL_MUP_NAME
//
// MessageText:
//
//  UNC Filesystem
//
#define SL_MUP_NAME                      0x00002377L

//
// MessageId: SL_NDIS_NAME
//
// MessageText:
//
//  NDIS Driver
//
#define SL_NDIS_NAME                     0x00002378L

//
// MessageId: SL_RDBSS_NAME
//
// MessageText:
//
//  SMB Redirector Filesystem
//
#define SL_RDBSS_NAME                    0x00002379L

//
// MessageId: SL_NETBOOT_CARD_ERROR
//
// MessageText:
//
//  The network boot card in your computer has an older version
//  of ROM and cannot be used to remotely install Windows.
//  Contact your system administrator or computer manufacturer
//  for information about upgrading the ROM.
//
#define SL_NETBOOT_CARD_ERROR            0x0000237AL

//
// MessageId: SL_NETBOOT_SERVER_ERROR
//
// MessageText:
//
//  The operating system image you selected does not contain the
//  necessary drivers for your network adapter. Try selecting a
//  different operating system image. If the problem persists,
//  contact your system administrator.
//
#define SL_NETBOOT_SERVER_ERROR          0x0000237BL

//
// MessageId: SL_IPSEC_NAME
//
// MessageText:
//
//  IP Security Service
//
#define SL_IPSEC_NAME                    0x0000237CL

//
// MessageId: SL_CMDCONS_MSG
//
// MessageText:
//
//  Windows Recovery Console
//
#define SL_CMDCONS_MSG                   0x0000237DL

//
// MessageId: SL_KERNEL_TRANSITION
//
// MessageText:
//
//  Setup is starting Windows
//
#define SL_KERNEL_TRANSITION             0x0000237EL

#ifdef _WANT_MACHINE_IDENTIFICATION
//
// MessageId: SL_BIOSINFO_NAME
//
// MessageText:
//
//  Machine Identification Data
//
#define SL_BIOSINFO_NAME                 0x0000237FL

#endif
//
// MessageId: SL_KSECDD_NAME
//
// MessageText:
//
//  Kernel Security Service
//
#define SL_KSECDD_NAME                   0x00002380L

//
// MessageId: SL_WRONG_PROM_VERSION
//
// MessageText:
//
//  Your system's PROM (firmware) is below the required revision level.
//  Please contact SGI customer support or visit the SGI web site to obtain
//  the PROM update and upgrade instructions.
//  
//  Note: you can boot previous installations of Microsoft(R) Windows(R) 
//  by selecting the appropriate boot entry in the startup menu rather 
//  than the current default "Windows Setup" boot entry.
//
#define SL_WRONG_PROM_VERSION            0x00002381L

//
// MessageId: SIGNATURE_CHANGED
//
// MessageText:
//
//  Setup either detected multiple disks in your machine that are
//  indistinguishable or detected raw disk(s). Setup has corrected the problem,
//  but a reboot is required.
//
#define SIGNATURE_CHANGED                0x00002382L

//
// MessageId: SL_KDDLL_NAME
//
// MessageText:
//
//  Kernel Debugger DLL
//
#define SL_KDDLL_NAME                    0x00002383L

//
// MessageId: SL_OEM_DRIVERINFO
//
// MessageText:
//
//  %s
//  
//  Windows already has a driver that you can use for
//  "%s".
//  
//  Unless the device manufacturer prefers that you use the driver on the
//  floppy disk, you should use the driver in Windows.
//
#define SL_OEM_DRIVERINFO                0x00002384L

//
// MessageId: SL_CONFIRM_OEMDRIVER
//
// MessageText:
//
//  S=Use the driver on floppy ENTER=Use the default Windows driver
//
#define SL_CONFIRM_OEMDRIVER             0x00002385L

//
// MessageId: SL_OEMDRIVER_NEW
//
// MessageText:
//
//  The driver you provided seems to be newer than the Windows
//  default driver.
//
#define SL_OEMDRIVER_NEW                 0x00002386L

//
// MessageId: SL_INBOXDRIVER_NEW
//
// MessageText:
//
//  The driver you provided seems to be older than the Windows
//  default driver.
//
#define SL_INBOXDRIVER_NEW               0x00002387L

//
// MessageId: SL_CMDCONS_STARTING
//
// MessageText:
//
//  Starting Windows Recovery Console...
//
#define SL_CMDCONS_STARTING              0x00002388L

//
// MessageId: SL_NTDETECT_CMDCONS
//
// MessageText:
//
//  NTDETECT Checking Hardware ...
//
#define SL_NTDETECT_CMDCONS              0x00002389L

//
// MessageId: SL_MSG_PRESS_ASR
//
// MessageText:
//
//  Press F2 to run Automated System Recovery (ASR)...
//
#define SL_MSG_PRESS_ASR                 0x0000238AL

//
// MessageId: SL_MSG_WARNING_ASR
//
// MessageText:
//
//          Please insert the disk labeled:
//  
//  
//      Windows Automated System Recovery Disk
//  
//  
//              into the floppy drive.
//  
//  
//  
//            Press any key when ready.
//
#define SL_MSG_WARNING_ASR               0x0000238BL

//
// MessageId: SL_TEXT_REQUIRED_FEATURES_MISSING
//
// MessageText:
//
//  Windows requires certain processor features that are not available
//  on the processor in this computer.   Specifically, Windows requires
//  the following instructions.
//  
//      CPUID
//      CMPXCHG8B
//
#define SL_TEXT_REQUIRED_FEATURES_MISSING 0x0000238CL

//
// MessageId: SL_MSG_PREPARING_ASR
//
// MessageText:
//
//  Preparing for Automated System Recovery, press ESC to cancel...
//
#define SL_MSG_PREPARING_ASR             0x0000238DL

//
// MessageId: SL_MSG_ENTERING_ASR
//
// MessageText:
//
//  Starting Windows Automated System Recovery...
//
#define SL_MSG_ENTERING_ASR              0x0000238EL

//
// MessageId: SL_MOUSE_NAME
//
// MessageText:
//
//  Mouse Driver
//
#define SL_MOUSE_NAME                    0x0000238FL

//
// MessageId: SL_SETUP_STARTING
//
// MessageText:
//
//  Starting Windows Setup...
//
#define SL_SETUP_STARTING                0x00002390L

//
// MessageId: SL_MSG_INVALID_ASRPNP_FILE
//
// MessageText:
//
//  The file ASRPNP.SIF on the Automated System Recovery disk is invalid
//
#define SL_MSG_INVALID_ASRPNP_FILE       0x00002391L

//
// MessageId: SL_SETUP_STARTING_WINPE
//
// MessageText:
//
//  Starting Windows Preinstall Environment...
//
#define SL_SETUP_STARTING_WINPE          0x00002392L

//
// MessageId: SL_NTDETECT_ROLLBACK
//
// MessageText:
//
//  
//  Uninstall is checking hardware...
//  
//
#define SL_NTDETECT_ROLLBACK             0x00002393L

//
// MessageId: SL_ROLLBACK_STARTING
//
// MessageText:
//
//  Starting Windows Uninstallation...
//
#define SL_ROLLBACK_STARTING             0x00002394L

//
// MessageId: SL_NO_FLOPPY_DRIVE
//
// MessageText:
//
//  Setup could not find a floppy drive on your machine to load
//  OEM drivers from floppy disk.
//  
//      * Press ESC to cancel loading OEM drivers
//      
//      * Press F3 to quit setup.
//
#define SL_NO_FLOPPY_DRIVE               0x00002395L

//
// MessageId: SL_UPGRADE_IN_PROGRESS
//
// MessageText:
//
//  This computer is already in the process of being upgraded to Microsoft 
//  Windows. What do you want to do ?
//  
//      * To continue the current upgrade, press ENTER.
//  
//      * To cancel the current upgrade and install new version of
//        Microsoft Windows, press F10.
//  
//      * To exit Setup without installing Microsoft Windows, 
//        press F3.
//
#define SL_UPGRADE_IN_PROGRESS           0x00002396L

//
// MessageId: SL_DRVMAINSDB_NAME
//
// MessageText:
//
//  Driver Identification Data
//
#define SL_DRVMAINSDB_NAME               0x00002397L

//
// MessageId: SL_OEM_FILE_LOAD_FAILED
//
// MessageText:
//
//  Setup failed to load the OEM drivers.
//  
//  Press any key to continue.
//
#define SL_OEM_FILE_LOAD_FAILED          0x00002398L

//
// MessageId: SL_SACDRV_NAME
//
// MessageText:
//
//  EMS Support
//
#define SL_SACDRV_NAME                   0x00002399L

 //
 // NOTE : donot change the Message ID values for SL_CMDCONS_PROGBAR_FRONT
 // and SL_CMDCONS_PROGBAR_BACK from 11513 & 11514
 //

 // The character used to draw the foregound in percent-complete bar


//
// MessageId: SL_CMDCONS_PROGBAR_FRONT
//
// MessageText:
//
//  �
//
#define SL_CMDCONS_PROGBAR_FRONT         0x00002CF9L


 // The character used to draw the background in percent-complete bar


//
// MessageId: SL_CMDCONS_PROGBAR_BACK
//
// MessageText:
//
//  �
//
#define SL_CMDCONS_PROGBAR_BACK          0x00002CFAL


 //
 // Ramdisk related messages. DO NOT CHANGE the message numbers
 // as they are kept in sync with \base\boot\inc\ramdisk.h.
 //

//
// MessageId: BL_RAMDISK_GENERAL_FAILURE
//
// MessageText:
//
//  Windows could not start due to an error while booting from a RAMDISK.
//
#define BL_RAMDISK_GENERAL_FAILURE       0x00003A98L

//
// MessageId: BL_RAMDISK_INVALID_OPTIONS
//
// MessageText:
//
//  The RAMDISK options specified in boot.ini are invalid.
//
#define BL_RAMDISK_INVALID_OPTIONS       0x00003A99L

//
// MessageId: BL_RAMDISK_BUILD_FAILURE
//
// MessageText:
//
//  Windows failed to build a bootable RAMDISK image.
//
#define BL_RAMDISK_BUILD_FAILURE         0x00003A9AL

//
// MessageId: BL_RAMDISK_BOOT_FAILURE
//
// MessageText:
//
//  Windows failed to open the RAMDISK image.
//
#define BL_RAMDISK_BOOT_FAILURE          0x00003A9BL

//
// MessageId: BL_RAMDISK_BUILD_DISCOVER
//
// MessageText:
//
//  Searching for a build server...
//
#define BL_RAMDISK_BUILD_DISCOVER        0x00003A9CL

//
// MessageId: BL_RAMDISK_BUILD_REQUEST
//
// MessageText:
//
//  Requesting a bootable image from build server...
//
#define BL_RAMDISK_BUILD_REQUEST         0x00003A9DL

//
// MessageId: BL_RAMDISK_BUILD_PROGRESS_TIMEOUT
//
// MessageText:
//
//  Build Server IP = %d.%d.%d.%d. Last request timed out.  
//
#define BL_RAMDISK_BUILD_PROGRESS_TIMEOUT 0x00003A9EL

//
// MessageId: BL_RAMDISK_BUILD_PROGRESS_PENDING
//
// MessageText:
//
//  Build Server IP = %d.%d.%d.%d. Last request is pending.  
//
#define BL_RAMDISK_BUILD_PROGRESS_PENDING 0x00003A9FL

//
// MessageId: BL_RAMDISK_BUILD_PROGRESS_ERROR
//
// MessageText:
//
//  Build Server IP = %d.%d.%d.%d. Last request failed.     
//
#define BL_RAMDISK_BUILD_PROGRESS_ERROR  0x00003AA0L

//
// MessageId: BL_RAMDISK_BUILD_PROGRESS
//
// MessageText:
//
//  Build Server IP = %d.%d.%d.%d.
//
#define BL_RAMDISK_BUILD_PROGRESS        0x00003AA1L

//
// MessageId: BL_RAMDISK_DOWNLOAD
//
// MessageText:
//
//  Loading RAMDISK image...
//
#define BL_RAMDISK_DOWNLOAD              0x00003AA2L

//
// MessageId: BL_RAMDISK_DOWNLOAD_NETWORK
//
// MessageText:
//
//  TFTP download from %d.%d.%d.%d
//
#define BL_RAMDISK_DOWNLOAD_NETWORK      0x00003AA3L

//
// MessageId: BL_RAMDISK_DOWNLOAD_NETWORK_MCAST
//
// MessageText:
//
//  Multicast TFTP download from %d.%d.%d.%d:%d.
//
#define BL_RAMDISK_DOWNLOAD_NETWORK_MCAST 0x00003AA4L

#endif // _SETUPLDR_MSG_
