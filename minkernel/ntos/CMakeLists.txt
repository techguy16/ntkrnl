cmake_minimum_required(VERSION 3.22)

set(ntos ${CMAKE_CURRENT_SOURCE_DIR})
set(NT_DEFS ${MINKERNEL_DEFS} _NTSYSTEM_=1)

add_subdirectory(rtl)
add_subdirectory(config)
add_subdirectory(kd64)
add_subdirectory(ex)

add_executable(ntoskrnl init/ntkrnlmp.c)
target_link_libraries(ntoskrnl PRIVATE rtl config kd64 ex)
target_link_options(ntoskrnl PRIVATE -subsystem:native,6.9 -entry:KiSystemStartup -map -merge:PAGECONST=PAGE -merge:INITCONST=INIT -merge:INITDATA=INIT -merge:PAGELKCONST=PAGELK -merge:PAGEVRFY_CONST=PAGEVRFY)
add_custom_command(TARGET ntoskrnl POST_BUILD
                            COMMAND ${CMAKE_LINKER} -edit -section:.rsrc,!d $<TARGET_FILE:ntoskrnl>)
