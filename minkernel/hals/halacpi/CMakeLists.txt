cmake_minimum_required(VERSION 3.22)

set(HAL_HEADERS halnls.h
		             halp.h
		             ixisa.h
		             ixsleep.h
		             mmtimer.h
		             pcip.h
		             xxacpi.h
		             xxtimer.h)
set(HAL_SOURCES mpapic/hal.rc
		            
                     acpidtct.c
                     chiphacks.c
                     cmosopregion.c
                     drivesup.c
                     dynsysres.c
                     ixenvirv.c
                     ixfirm.c
                     ixhalt.c
                     ixhwsup.c
                     ixinfo.c
                     ixisabus.c
                     ixisasup.c
                     ixnmi.c
                     ixpcibus.c
                     ixpciint.c
                     ixphwsup.c
                     ixpnpdrv.c
                     ixreboot.c
                     ixslpsup.c
                     ixthunk.c
                     ixusage.c
                     mpipic.c
                     mpprocst.c
		             mpclockc.c
                     mpdat.c
                     mpdebug.c
                     mphal.c
                     mpinfo.c
                     mpsproc.c
                     mpsys.c
                     mpsysbus.c
                     mpsyssup.c
                     pmapic.c
                     pmbus.c
                     pmdata.c
                     pmisabus.c
                     pmpcisup.c
                     pmsleep.c
                     sratnuma.c
                     xxacpi.c
                     xxdisp.c
                     xxmemory.c
                     xxstubs.c
                     xxtime.c)

set(HAL_amd64_HEADERS amd64/8259.h
			               amd64/amd64.h
			               amd64/halcmn.h
			               amd64/io_cmos.h)
set(HAL_amd64_SOURCES amd64/amd64s.asm
			               amd64/interrupt.c
                           amd64/ixbeep.c
                           amd64/ixcmos.c
                           amd64/ixsstate.c
                           amd64/picinit.c
                           amd64/pmrtc.c
                           amd64/x86bios.c
                           amd64/mcheck.c
                           amd64/mpipi.c
                           amd64/mpirql.c
                           amd64/mpprofil.c
                           amd64/amd64.c
                           amd64/mpspin.c
                           amd64/mpsproca.c
                           amd64/mpswint.c
                           amd64/mpsysint.c
                           amd64/pmstall.c
                           amd64/pmtimer.c)

add_library(hal SHARED ${hal_HEADERS} ${HAL_SOURCES} ${HAL_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(hal PRIVATE ${HAL_DEFS} APIC_HAL=1 ACPI_HAL=1 _HALPAE_=1 SPEEDY_BOOT=1 NO_PM_KEQPC=1)
target_include_directories(hal PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/i386 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_SYSTEM_PROCESSOR} ${HAL_INCDIRS}
                                            ${HALKIT_INC_PATH}/i386 ${WDM_INC_PATH} ${hals}/x86new)
target_link_options(hal PRIVATE -merge:PAGECONST=PAGE -merge:INITCONST=INIT /LARGEADDRESSAWARE -noentry)
target_link_libraries(hal PRIVATE ${HALKIT_LIB_PATH}/kdcom.lib x86new ${DDK_LIB_PATH}/ntoskrnl.lib)
set_property(TARGET hal PROPERTY FOLDER "Hardware Abstraction Layer")
