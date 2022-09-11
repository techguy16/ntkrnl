cmake_minimum_required(VERSION 3.22)

set(EX_HEADERS exp.h)
set(EX_SOURCES callback.c
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
set(EX_amd64_SOURCES amd64/hifreqlk.asm
                     amd64/intrlock.asm
                     amd64/wowinfo.c)

add_library(ex STATIC ${EX_HEADERS} ${EX_SOURCES} ${EX_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${EX_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(ex PRIVATE ${NT_DEFS})
target_include_directories(ex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke ${ntos}/kd64
                                      ${HALKIT_INC_PATH} ${minkernel}/fs/fastfat)
