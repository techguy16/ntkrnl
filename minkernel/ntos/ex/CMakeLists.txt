cmake_minimum_required(VERSION 3.29)

set(TARGET ex)

set(${TARGET}_HEADERS exp.h)
set(${TARGET}_SOURCES callback.c
               callperf.c
               dbgctrl.c
               delay.c
               event.c
               eventpr.c
               exatom.c
               exdata.c
               exinfo.c
               exinit.c
               exdata.c
               exhotp.c
               fmutexc.c
               handle.c
               harderr.c
               hdlsterm.c
               lookasid.c
               luid.c
               mutant.c
               nbqueue.c
               pool.c
               probe.c
               profile.c
               raise.c
               resource.c
               semphore.c
               slist.c
               sysenv.c
               sysinfo.c
               systime.c
               timer.c
               worker.c
               zone.c
               uuid.c
               win32.c
               rundown.c
               pushlock.c
               xipdisp.c
               keyedevent.c)
set(${TARGET}_AMD64_SOURCES amd64/hifreqlk.asm
                     amd64/intrlock.asm
                     amd64/wowinfo.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS} _WIN2K_COMPAT_SLIST_USAGE)
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke ${ntos}/kd64
                                      ${HALKIT_INC_PATH} ${minkernel}/fs/fastfat)
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
