cmake_minimum_required(VERSION 3.22)

set(ntos ${CMAKE_CURRENT_SOURCE_DIR})
set(NT_DEFS ${MINKERNEL_DEFS} _NTSYSTEM_=1)
set(NT_INCDIRS ${SDK_INC_PATH} ${SDK_INC_PATH}/crt ${MINKERNEL_INC_PATH} ${NTOSINC} ${SDKTOOLS_INC_PATH} ${PUBLISHEDDIR}
               ${PUBLISHEDDIR}/${CMAKE_SYSTEM_PROCESSOR})

add_subdirectory(rtl)
add_subdirectory(config)
add_subdirectory(kd64)
add_subdirectory(ex)
add_subdirectory(ob)
add_subdirectory(se)
add_subdirectory(mm)
add_subdirectory(ke)

add_executable(ntoskrnl init/ntkrnlmp.c)
target_link_libraries(ntoskrnl PRIVATE rtl config kd64 ex ob se mm ke)
target_link_options(ntoskrnl PRIVATE -subsystem:native,6.9 -entry:KiSystemStartup -map -merge:PAGECONST=PAGE
                                     -merge:INITCONST=INIT -merge:INITDATA=INIT -merge:PAGELKCONST=PAGELK
                                     -merge:PAGEVRFY_CONST=PAGEVRFY)
add_custom_command(TARGET ntoskrnl POST_BUILD
                   COMMAND ${CMAKE_LINKER} -edit -section:.rsrc,!d $<TARGET_FILE:ntoskrnl>)
