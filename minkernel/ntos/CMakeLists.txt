cmake_minimum_required(VERSION 3.22)

set(ntos ${CMAKE_CURRENT_SOURCE_DIR})
set(NT_DEFS ${MINKERNEL_DEFS} _WINNT_=1 WINNT=1 _WIN32_WINNT=0x1200 _NTSYSTEM_=1)
set(NT_INCDIRS ${MINKERNEL_INCDIRS})

add_subdirectory(rtl)
add_subdirectory(config)
add_subdirectory(kd64)
add_subdirectory(ex)
add_subdirectory(ob)
add_subdirectory(se)
add_subdirectory(mm)
add_subdirectory(ke)
add_subdirectory(po)
add_subdirectory(ps)

add_library(ntoskrnl SHARED init/ntkrnlmp.c init/ntoskrnl.rc)
target_include_directories(ntoskrnl PRIVATE ${ntos}/nls/obj/${CMAKE_SYSTEM_PROCESSOR})
target_link_libraries(ntoskrnl PRIVATE rtl config kd64 ex ob se mm ke po ps libcnt)
target_link_options(ntoskrnl PRIVATE -subsystem:native,6.9 -entry:KiSystemStartup -map -merge:PAGECONST=PAGE
                                     -merge:INITCONST=INIT -merge:INITDATA=INIT -merge:PAGELKCONST=PAGELK
                                     -merge:PAGEVRFY_CONST=PAGEVRFY)
set_target_properties(ntoskrnl PROPERTIES SUFFIX .exe)
add_custom_command(TARGET ntoskrnl POST_BUILD
                   COMMAND ${CMAKE_LINKER} -edit -section:.rsrc,!d $<TARGET_FILE:ntoskrnl>)
set_property(TARGET ntoskrnl PROPERTY FOLDER "Kernel")
