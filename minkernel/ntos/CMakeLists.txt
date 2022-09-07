cmake_minimum_required(VERSION 3.22)

set(ntos ${CMAKE_CURRENT_SOURCE_DIR})
set(NT_DEFS ${MINKERNEL_DEFS} _NTSYSTEM_=1)

add_subdirectory(rtl)

add_executable(ntoskrnl init/ntkrnlmp.c)
target_link_libraries(ntoskrnl PRIVATE rtl)
