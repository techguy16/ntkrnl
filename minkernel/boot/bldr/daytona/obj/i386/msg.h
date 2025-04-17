/*++

Copyright (c) 1991  Microsoft Corporation

Module Name:

    msg.h

Abstract:

    This file contains the message definitions for osloader

Author:

    John Vert (jvert) 12-Nov-1993

Revision History:

Notes:

    This file is generated from msg.mc

--*/

#ifndef _BLDR_MSG_
#define _BLDR_MSG_


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
// MessageId: BL_MSG_FIRST
//
// MessageText:
//
//  BL_MSG_FIRST
//
#define BL_MSG_FIRST                     0x00002328L

//
// MessageId: LOAD_SW_INT_ERR_CLASS
//
// MessageText:
//
//  Windows could not start because of an error in the software.
//  Please report this problem as :
//
#define LOAD_SW_INT_ERR_CLASS            0x00002329L

//
// MessageId: LOAD_SW_MISRQD_FILE_CLASS
//
// MessageText:
//
//  Windows could not start because the following file was not found
//  and is required :
//
#define LOAD_SW_MISRQD_FILE_CLASS        0x0000232AL

//
// MessageId: LOAD_SW_BAD_FILE_CLASS
//
// MessageText:
//
//  Windows could not start because of a bad copy of the 
//  following file :
//
#define LOAD_SW_BAD_FILE_CLASS           0x0000232BL

//
// MessageId: LOAD_SW_MIS_FILE_CLASS
//
// MessageText:
//
//  Windows could not start because the following file is missing 
//  or corrupt:
//
#define LOAD_SW_MIS_FILE_CLASS           0x0000232CL

//
// MessageId: LOAD_HW_MEM_CLASS
//
// MessageText:
//
//  Windows could not start because of a hardware memory 
//  configuration problem.
//
#define LOAD_HW_MEM_CLASS                0x0000232DL

//
// MessageId: LOAD_HW_DISK_CLASS
//
// MessageText:
//
//  Windows could not start because of a computer disk hardware
//  configuration problem.
//
#define LOAD_HW_DISK_CLASS               0x0000232EL

//
// MessageId: LOAD_HW_GEN_ERR_CLASS
//
// MessageText:
//
//  Windows could not start because of a general computer hardware
//  configuration problem.
//
#define LOAD_HW_GEN_ERR_CLASS            0x0000232FL

//
// MessageId: LOAD_HW_FW_CFG_CLASS
//
// MessageText:
//
//  Windows could not start because of the following ARC firmware
//  boot configuration problem :
//
#define LOAD_HW_FW_CFG_CLASS             0x00002330L

//
// MessageId: DIAG_BL_MEMORY_INIT
//
// MessageText:
//
//  Check hardware memory configuration and amount of RAM.
//
#define DIAG_BL_MEMORY_INIT              0x00002331L

//
// MessageId: DIAG_BL_CONFIG_INIT
//
// MessageText:
//
//  Too many configuration entries.
//
#define DIAG_BL_CONFIG_INIT              0x00002332L

//
// MessageId: DIAG_BL_IO_INIT
//
// MessageText:
//
//  Could not access disk partition tables
//
#define DIAG_BL_IO_INIT                  0x00002333L

//
// MessageId: DIAG_BL_FW_GET_BOOT_DEVICE
//
// MessageText:
//
//  The 'osloadpartition' parameter setting is invalid.
//
#define DIAG_BL_FW_GET_BOOT_DEVICE       0x00002334L

//
// MessageId: DIAG_BL_OPEN_BOOT_DEVICE
//
// MessageText:
//
//  Could not read from the selected boot disk.  Check boot path
//  and disk hardware.
//
#define DIAG_BL_OPEN_BOOT_DEVICE         0x00002335L

//
// MessageId: DIAG_BL_FW_GET_SYSTEM_DEVICE
//
// MessageText:
//
//  The 'systempartition' parameter setting is invalid.
//
#define DIAG_BL_FW_GET_SYSTEM_DEVICE     0x00002336L

//
// MessageId: DIAG_BL_FW_OPEN_SYSTEM_DEVICE
//
// MessageText:
//
//  Could not read from the selected system boot disk.
//  Check 'systempartition' path.
//
#define DIAG_BL_FW_OPEN_SYSTEM_DEVICE    0x00002337L

//
// MessageId: DIAG_BL_GET_SYSTEM_PATH
//
// MessageText:
//
//  The 'osloadfilename' parameter does not point to a valid file.
//
#define DIAG_BL_GET_SYSTEM_PATH          0x00002338L

//
// MessageId: DIAG_BL_LOAD_SYSTEM_IMAGE
//
// MessageText:
//
//  <Windows root>\system32\ntoskrnl.exe.
//
#define DIAG_BL_LOAD_SYSTEM_IMAGE        0x00002339L

//
// MessageId: DIAG_BL_FIND_HAL_IMAGE
//
// MessageText:
//
//  The 'osloader' parameter does not point to a valid file.
//
#define DIAG_BL_FIND_HAL_IMAGE           0x0000233AL

//
// MessageId: DIAG_BL_LOAD_HAL_IMAGE_X86
//
// MessageText:
//
//  <Windows root>\system32\hal.dll.
//
#define DIAG_BL_LOAD_HAL_IMAGE_X86       0x0000233BL

//
// MessageId: DIAG_BL_LOAD_HAL_IMAGE_ARC
//
// MessageText:
//
//  'osloader'\hal.dll
//
#define DIAG_BL_LOAD_HAL_IMAGE_ARC       0x0000233CL

#ifdef _X86_
#define DIAG_BL_LOAD_HAL_IMAGE DIAG_BL_LOAD_HAL_IMAGE_X86
#else
#define DIAG_BL_LOAD_HAL_IMAGE DIAG_BL_LOAD_HAL_IMAGE_ARC
#endif
//
// MessageId: DIAG_BL_LOAD_SYSTEM_IMAGE_DATA
//
// MessageText:
//
//  Loader error 1.
//
#define DIAG_BL_LOAD_SYSTEM_IMAGE_DATA   0x0000233DL

//
// MessageId: DIAG_BL_LOAD_HAL_IMAGE_DATA
//
// MessageText:
//
//  Loader error 2.
//
#define DIAG_BL_LOAD_HAL_IMAGE_DATA      0x0000233EL

//
// MessageId: DIAG_BL_LOAD_SYSTEM_DLLS
//
// MessageText:
//
//  load needed DLLs for kernel.
//
#define DIAG_BL_LOAD_SYSTEM_DLLS         0x0000233FL

//
// MessageId: DIAG_BL_LOAD_HAL_DLLS
//
// MessageText:
//
//  load needed DLLs for HAL.
//
#define DIAG_BL_LOAD_HAL_DLLS            0x00002340L

//
// MessageId: DIAG_BL_FIND_SYSTEM_DRIVERS
//
// MessageText:
//
//  find system drivers.
//
#define DIAG_BL_FIND_SYSTEM_DRIVERS      0x00002342L

//
// MessageId: DIAG_BL_READ_SYSTEM_DRIVERS
//
// MessageText:
//
//  read system drivers.
//
#define DIAG_BL_READ_SYSTEM_DRIVERS      0x00002343L

//
// MessageId: DIAG_BL_LOAD_DEVICE_DRIVER
//
// MessageText:
//
//  did not load system boot device driver.
//
#define DIAG_BL_LOAD_DEVICE_DRIVER       0x00002344L

//
// MessageId: DIAG_BL_LOAD_SYSTEM_HIVE
//
// MessageText:
//
//  load system hardware configuration file.
//
#define DIAG_BL_LOAD_SYSTEM_HIVE         0x00002345L

//
// MessageId: DIAG_BL_SYSTEM_PART_DEV_NAME
//
// MessageText:
//
//  find system partition name device name.
//
#define DIAG_BL_SYSTEM_PART_DEV_NAME     0x00002346L

//
// MessageId: DIAG_BL_BOOT_PART_DEV_NAME
//
// MessageText:
//
//  find boot partition name.
//
#define DIAG_BL_BOOT_PART_DEV_NAME       0x00002347L

//
// MessageId: DIAG_BL_ARC_BOOT_DEV_NAME
//
// MessageText:
//
//  did not properly generate ARC name for HAL and system paths.
//
#define DIAG_BL_ARC_BOOT_DEV_NAME        0x00002348L

//
// MessageId: DIAG_BL_SETUP_FOR_NT
//
// MessageText:
//
//  Loader error 3.
//
#define DIAG_BL_SETUP_FOR_NT             0x0000234AL

//
// MessageId: DIAG_BL_KERNEL_INIT_XFER
//
// MessageText:
//
//  <Windows root>\system32\ntoskrnl.exe
//
#define DIAG_BL_KERNEL_INIT_XFER         0x0000234BL

//
// MessageId: LOAD_SW_INT_ERR_ACT
//
// MessageText:
//
//  Please contact your support person to report this problem.
//
#define LOAD_SW_INT_ERR_ACT              0x0000234CL

//
// MessageId: LOAD_SW_FILE_REST_ACT
//
// MessageText:
//
//  You can attempt to repair this file by starting Windows Setup
//  using the original Setup CD-ROM.
//  Select 'r' at the first screen to start repair.
//
#define LOAD_SW_FILE_REST_ACT            0x0000234DL

//
// MessageId: LOAD_SW_FILE_REINST_ACT
//
// MessageText:
//
//  Please re-install a copy of the above file.
//
#define LOAD_SW_FILE_REINST_ACT          0x0000234EL

//
// MessageId: LOAD_HW_MEM_ACT
//
// MessageText:
//
//  Please check the Windows documentation about hardware memory
//  requirements and your hardware reference manuals for
//  additional information.
//
#define LOAD_HW_MEM_ACT                  0x0000234FL

//
// MessageId: LOAD_HW_DISK_ACT
//
// MessageText:
//
//  Please check the Windows documentation about hardware disk
//  configuration and your hardware reference manuals for
//  additional information.
//
#define LOAD_HW_DISK_ACT                 0x00002350L

//
// MessageId: LOAD_HW_GEN_ACT
//
// MessageText:
//
//  Please check the Windows documentation about hardware
//  configuration and your hardware reference manuals for additional
//  information.
//
#define LOAD_HW_GEN_ACT                  0x00002351L

//
// MessageId: LOAD_HW_FW_CFG_ACT
//
// MessageText:
//
//  Please check the Windows documentation about ARC configuration
//  options and your hardware reference manuals for additional
//  information.
//
#define LOAD_HW_FW_CFG_ACT               0x00002352L

//
// MessageId: BL_LKG_MENU_HEADER
//
// MessageText:
//
//       Hardware Profile/Configuration Recovery Menu
//  
//  This menu allows you to select a hardware profile
//  to be used when Windows is started.
//  
//  If your system is not starting correctly, then you may switch to a 
//  previous system configuration, which may overcome startup problems.
//  IMPORTANT: System configuration changes made since the last successful
//  startup will be discarded.
//
#define BL_LKG_MENU_HEADER               0x00002353L

//
// MessageId: BL_LKG_MENU_TRAILER
//
// MessageText:
//
//  Use the up and down arrow keys to move the highlight
//  to the selection you want. Then press ENTER.
//
#define BL_LKG_MENU_TRAILER              0x00002354L

//
// MessageId: BL_LKG_MENU_TRAILER_NO_PROFILES
//
// MessageText:
//
//  No hardware profiles are currently defined. Hardware profiles
//  can be created from the System applet of the control panel.
//
#define BL_LKG_MENU_TRAILER_NO_PROFILES  0x00002355L

//
// MessageId: BL_SWITCH_LKG_TRAILER
//
// MessageText:
//
//  To switch to the Last Known Good configuration, press 'L'.
//  To Exit this menu and restart your computer, press F3.
//
#define BL_SWITCH_LKG_TRAILER            0x00002356L

//
// MessageId: BL_SWITCH_DEFAULT_TRAILER
//
// MessageText:
//
//  To switch to the default configuration, press 'D'.
//  To Exit this menu and restart your computer, press F3.
//
#define BL_SWITCH_DEFAULT_TRAILER        0x00002357L

//
// The following two messages are used to provide the mnemonic keypress
// that toggles between the Last Known Good control set and the default
// control set. (see BL_SWITCH_LKG_TRAILER and BL_SWITCH_DEFAULT_TRAILER)
//
//
// MessageId: BL_LKG_SELECT_MNEMONIC
//
// MessageText:
//
//  L
//
#define BL_LKG_SELECT_MNEMONIC           0x00002358L

//
// MessageId: BL_DEFAULT_SELECT_MNEMONIC
//
// MessageText:
//
//  D
//
#define BL_DEFAULT_SELECT_MNEMONIC       0x00002359L

//
// MessageId: BL_LKG_TIMEOUT
//
// MessageText:
//
//  Seconds until highlighted choice will be started automatically: %d
//
#define BL_LKG_TIMEOUT                   0x0000235AL

//
// MessageId: BL_LKG_MENU_PROMPT
//
// MessageText:
//
//  
//  Press spacebar NOW to invoke Hardware Profile/Last Known Good menu
//
#define BL_LKG_MENU_PROMPT               0x0000235BL

//
// MessageId: BL_BOOT_DEFAULT_PROMPT
//
// MessageText:
//
//  Boot default hardware configuration
//
#define BL_BOOT_DEFAULT_PROMPT           0x0000235CL

//
// The following messages are used during hibernation restoration
//
//
// MessageId: HIBER_BEING_RESTARTED
//
// MessageText:
//
//  The system is being restarted from its previous location.
//  Press the spacebar to interrupt.
//
#define HIBER_BEING_RESTARTED            0x0000235DL

//
// MessageId: HIBER_ERROR
//
// MessageText:
//
//  The system could not be restarted from its previous location
//
#define HIBER_ERROR                      0x0000235EL

//
// MessageId: HIBER_ERROR_NO_MEMORY
//
// MessageText:
//
//  due to no memory.
//
#define HIBER_ERROR_NO_MEMORY            0x0000235FL

//
// MessageId: HIBER_ERROR_BAD_IMAGE
//
// MessageText:
//
//  because the restoration image is corrupt.
//
#define HIBER_ERROR_BAD_IMAGE            0x00002360L

//
// MessageId: HIBER_IMAGE_INCOMPATIBLE
//
// MessageText:
//
//  because the restoration image is not compatible with the current
//  configuration.
//
#define HIBER_IMAGE_INCOMPATIBLE         0x00002361L

//
// MessageId: HIBER_ERROR_OUT_OF_REMAP
//
// MessageText:
//
//  due to an internal error.
//
#define HIBER_ERROR_OUT_OF_REMAP         0x00002362L

//
// MessageId: HIBER_INTERNAL_ERROR
//
// MessageText:
//
//  due to an internal error.
//
#define HIBER_INTERNAL_ERROR             0x00002363L

//
// MessageId: HIBER_READ_ERROR
//
// MessageText:
//
//  due to a read failure.
//
#define HIBER_READ_ERROR                 0x00002364L

//
// MessageId: HIBER_PAUSE
//
// MessageText:
//
//  System restart has been paused:
//
#define HIBER_PAUSE                      0x00002365L

//
// MessageId: HIBER_CANCEL
//
// MessageText:
//
//  Delete restoration data and proceed to system boot menu
//
#define HIBER_CANCEL                     0x00002366L

//
// MessageId: HIBER_CONTINUE
//
// MessageText:
//
//  Continue with system restart
//
#define HIBER_CONTINUE                   0x00002367L

//
// MessageId: HIBER_RESTART_AGAIN
//
// MessageText:
//
//  The last attempt to restart the system from its previous location
//  failed.  Attempt to restart again?
//
#define HIBER_RESTART_AGAIN              0x00002368L

//
// MessageId: HIBER_DEBUG_BREAK_ON_WAKE
//
// MessageText:
//
//  Continue with debug breakpoint on system wake
//
#define HIBER_DEBUG_BREAK_ON_WAKE        0x00002369L

//
// MessageId: LOAD_SW_MISMATCHED_KERNEL
//
// MessageText:
//
//  Windows could not start because the specified kernel does 
//  not exist or is not compatible with this processor.
//
#define LOAD_SW_MISMATCHED_KERNEL        0x0000236AL

//
// MessageId: BL_MSG_STARTING_WINDOWS
//
// MessageText:
//
//  Starting Windows...
//
#define BL_MSG_STARTING_WINDOWS          0x0000236BL

//
// MessageId: BL_MSG_RESUMING_WINDOWS
//
// MessageText:
//
//  Resuming Windows...
//
#define BL_MSG_RESUMING_WINDOWS          0x0000236CL

//
// MessageId: BL_EFI_OPTION_FAILURE
//
// MessageText:
//
//  Windows could not start because there was an error reading
//  the boot settings from NVRAM.
//  
//  Please check your firmware settings.  You may need to restore your
//  NVRAM settings from a backup.
//
#define BL_EFI_OPTION_FAILURE            0x0000236DL

//
// MessageId: HIBER_MEMORY_INCOMPATIBLE
//
// MessageText:
//
//  because the memory configuration has changed.  If you proceed,
//  your hibernated context may be lost.  To properly resume, you
//  should turn your machine off now, restore the original memory
//  configuration, then reboot the system.
//  
//
#define HIBER_MEMORY_INCOMPATIBLE        0x0000236EL


 //
 // Following messages are for the x86-specific
 // boot menu.
 //

//
// MessageId: BL_ENABLED_KD_TITLE
//
// MessageText:
//
//   [debugger enabled]
//
#define BL_ENABLED_KD_TITLE              0x00002711L

//
// MessageId: BL_DEFAULT_TITLE
//
// MessageText:
//
//  Windows (default)
//
#define BL_DEFAULT_TITLE                 0x00002712L

//
// MessageId: BL_MISSING_BOOT_INI
//
// MessageText:
//
//  NTLDR: BOOT.INI file not found.
//
#define BL_MISSING_BOOT_INI              0x00002713L

//
// MessageId: BL_MISSING_OS_SECTION
//
// MessageText:
//
//  NTLDR: no [operating systems] section in boot.txt.
//
#define BL_MISSING_OS_SECTION            0x00002714L

//
// MessageId: BL_BOOTING_DEFAULT
//
// MessageText:
//
//  Booting default kernel from %s.
//
#define BL_BOOTING_DEFAULT               0x00002715L

//
// MessageId: BL_SELECT_OS
//
// MessageText:
//
//  Please select the operating system to start:
//
#define BL_SELECT_OS                     0x00002716L

//
// MessageId: BL_MOVE_HIGHLIGHT
//
// MessageText:
//
//  
//  
//  Use the up and down arrow keys to move the highlight to your choice.
//  Press ENTER to choose.
//
#define BL_MOVE_HIGHLIGHT                0x00002717L

//
// MessageId: BL_TIMEOUT_COUNTDOWN
//
// MessageText:
//
//  Seconds until highlighted choice will be started automatically:
//
#define BL_TIMEOUT_COUNTDOWN             0x00002718L

//
// MessageId: BL_INVALID_BOOT_INI
//
// MessageText:
//
//  Invalid BOOT.INI file
//  Booting from %s
//
#define BL_INVALID_BOOT_INI              0x00002719L

//
// MessageId: BL_REBOOT_IO_ERROR
//
// MessageText:
//
//  I/O Error accessing boot sector file
//  %s\BOOTSECT.DOS
//
#define BL_REBOOT_IO_ERROR               0x0000271AL

//
// MessageId: BL_DRIVE_ERROR
//
// MessageText:
//
//  NTLDR: Couldn't open drive %s
//
#define BL_DRIVE_ERROR                   0x0000271BL

//
// MessageId: BL_READ_ERROR
//
// MessageText:
//
//  NTLDR: Fatal Error %d reading BOOT.INI
//
#define BL_READ_ERROR                    0x0000271CL

//
// MessageId: BL_NTDETECT_MSG
//
// MessageText:
//
//  
//  NTDETECT V5.2 Checking Hardware ...
//  
//
#define BL_NTDETECT_MSG                  0x0000271DL

//
// MessageId: BL_NTDETECT_FAILURE
//
// MessageText:
//
//  NTDETECT failed
//
#define BL_NTDETECT_FAILURE              0x0000271EL

//
// MessageId: BL_DEBUG_SELECT_OS
//
// MessageText:
//
//  Current Selection:
//    Title..: %s
//    Path...: %s
//    Options: %s
//
#define BL_DEBUG_SELECT_OS               0x0000271FL

//
// MessageId: BL_DEBUG_NEW_OPTIONS
//
// MessageText:
//
//  Enter new load options:
//
#define BL_DEBUG_NEW_OPTIONS             0x00002720L

//
// MessageId: BL_HEADLESS_REDIRECT_TITLE
//
// MessageText:
//
//   [EMS enabled]
//
#define BL_HEADLESS_REDIRECT_TITLE       0x00002721L

//
// MessageId: BL_INVALID_BOOT_INI_FATAL
//
// MessageText:
//
//  Invalid BOOT.INI file
//
#define BL_INVALID_BOOT_INI_FATAL        0x00002722L


 //
 // Following messages are for the advanced boot menu
 //

//
// MessageId: BL_ADVANCEDBOOT_TITLE
//
// MessageText:
//
//  Windows Advanced Options Menu
//  Please select an option:
//
#define BL_ADVANCEDBOOT_TITLE            0x00002AF9L

//
// MessageId: BL_SAFEBOOT_OPTION1
//
// MessageText:
//
//  Safe Mode
//
#define BL_SAFEBOOT_OPTION1              0x00002AFAL

//
// MessageId: BL_SAFEBOOT_OPTION2
//
// MessageText:
//
//  Safe Mode with Networking
//
#define BL_SAFEBOOT_OPTION2              0x00002AFBL

//
// MessageId: BL_SAFEBOOT_OPTION3
//
// MessageText:
//
//  Step-by-Step Confirmation Mode
//
#define BL_SAFEBOOT_OPTION3              0x00002AFCL

//
// MessageId: BL_SAFEBOOT_OPTION4
//
// MessageText:
//
//  Safe Mode with Command Prompt
//
#define BL_SAFEBOOT_OPTION4              0x00002AFDL

//
// MessageId: BL_SAFEBOOT_OPTION5
//
// MessageText:
//
//  VGA Mode
//
#define BL_SAFEBOOT_OPTION5              0x00002AFEL

//
// MessageId: BL_SAFEBOOT_OPTION6
//
// MessageText:
//
//  Directory Services Restore Mode (Windows domain controllers only)
//
#define BL_SAFEBOOT_OPTION6              0x00002AFFL

//
// MessageId: BL_LASTKNOWNGOOD_OPTION
//
// MessageText:
//
//  Last Known Good Configuration (your most recent settings that worked)
//
#define BL_LASTKNOWNGOOD_OPTION          0x00002B00L

//
// MessageId: BL_DEBUG_OPTION
//
// MessageText:
//
//  Debugging Mode
//
#define BL_DEBUG_OPTION                  0x00002B01L

#if defined(REMOTE_BOOT)
MessageID=11010 SymbolicName=BL_REMOTEBOOT_OPTION1
Language=English
Remote Boot Maintenance and Troubleshooting
.

MessageID=11011 SymbolicName=BL_REMOTEBOOT_OPTION2
Language=English
Clear Offline Cache
.

MessageID=11012 SymbolicName=BL_REMOTEBOOT_OPTION3
Language=English
Load using files from server only
.
#endif // defined(REMOTE_BOOT)
//
// MessageId: BL_BOOTLOG
//
// MessageText:
//
//  Enable Boot Logging
//
#define BL_BOOTLOG                       0x00002B05L

//
// MessageId: BL_ADVANCED_BOOT_MESSAGE
//
// MessageText:
//
//  For troubleshooting and advanced startup options for Windows, press F8.
//
#define BL_ADVANCED_BOOT_MESSAGE         0x00002B06L

//
// MessageId: BL_BASEVIDEO
//
// MessageText:
//
//  Enable VGA Mode
//
#define BL_BASEVIDEO                     0x00002B07L

//
// MessageId: BL_DISABLE_SAFEBOOT
//
// MessageText:
//
//  
//  Press ESCAPE to disable safeboot and boot normally.
//
#define BL_DISABLE_SAFEBOOT              0x00002B08L

//
// MessageId: BL_MSG_BOOT_NORMALLY
//
// MessageText:
//
//  Start Windows Normally
//
#define BL_MSG_BOOT_NORMALLY             0x00002B09L

//
// MessageId: BL_MSG_OSCHOICES_MENU
//
// MessageText:
//
//  Return to OS Choices Menu
//
#define BL_MSG_OSCHOICES_MENU            0x00002B0AL

//
// MessageId: BL_MSG_REBOOT
//
// MessageText:
//
//  Reboot
//
#define BL_MSG_REBOOT                    0x00002B0BL

//
// MessageId: BL_ADVANCEDBOOT_AUTOLKG_TITLE
//
// MessageText:
//
//  We apologize for the inconvenience, but Windows did not start successfully.  A 
//  recent hardware or software change might have caused this.
//  
//  If your computer stopped responding, restarted unexpectedly, or was 
//  automatically shut down to protect your files and folders, choose Last Known 
//  Good Configuration to revert to the most recent settings that worked.
//  
//  If a previous startup attempt was interrupted due to a power failure or because 
//  the Power or Reset button was pressed, or if you aren't sure what caused the 
//  problem, choose Start Windows Normally.
//
#define BL_ADVANCEDBOOT_AUTOLKG_TITLE    0x00002B0CL

//
// MessageId: BL_ADVANCEDBOOT_AUTOSAFE_TITLE
//
// MessageText:
//
//  Windows was not shutdown successfully.  If this was due to the system not 
//  responding, or if the system shutdown to protect data, you might be able to 
//  recover by choosing one of the Safe Mode configurations from the menu below:
//
#define BL_ADVANCEDBOOT_AUTOSAFE_TITLE   0x00002B0DL

//
// MessageId: BL_ADVANCEDBOOT_TIMEOUT
//
// MessageText:
//
//  Seconds until Windows starts:
//
#define BL_ADVANCEDBOOT_TIMEOUT          0x00002B0EL


//
// Following messages are the symbols used
// in the Hibernation Restore percent completed UI. 
//
// These symbols are here because they employ high-ASCII
// line drawing characters, which need to be localized
// for fonts that may not have such characters (or have
// them in a different ASCII location). 
//  
// This primarily affects FE character sets. 
//
// Note that only the FIRST character of any of these
// messages is ever looked at by the code.  
//

 // Just a base message, contains nothing.


 //
 // NOTE : donot change the Message ID values for HIBER_UI_BAR_ELEMENT
 // and BLDR_UI_BAR_BACKGROUND from 11513 & 11514


 // The character used to draw the percent-complete bar


//
// MessageId: HIBER_UI_BAR_ELEMENT
//
// MessageText:
//
//  �
//
#define HIBER_UI_BAR_ELEMENT             0x00002CF9L


 // The character used to draw the percent-complete bar


//
// MessageId: BLDR_UI_BAR_BACKGROUND
//
// MessageText:
//
//  �
//
#define BLDR_UI_BAR_BACKGROUND           0x00002CFAL

#if defined(REMOTE_BOOT)
;
; //
; // Following messages are for warning the user about
; // an impending autoformat of the hard disk.
; //
;

MessageID=12002 SymbolicName=BL_WARNFORMAT_TRAILER
Language=English
Press ENTER to continue booting Windows, otherwise turn off
your remote boot machine.
.

MessageID=12003 SymbolicName=BL_WARNFORMAT_CONTINUE
Language=English
Continue
.
MessageID=12004 SymbolicName=BL_FORCELOGON_HEADER
Language=English
          Auto-Format

Windows has detected a new hard disk in your remote boot
machine.  Before Windows can use this disk, you must logon and
validate that you have access to this disk.

WARNING:  Windows will automatically repartition and format
this disk to accept the new operating system.  All data on the
hard disk will be lost if you choose to continue.  If you do
not want to continue, power off the computer now and contact
your administrator.
.
#endif // defined(REMOTE_BOOT)

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

#endif // _BLDR_MSG_
