cmake_minimum_required(VERSION 3.22)

set(crtw32 ${CMAKE_CURRENT_SOURCE_DIR})
set(CRT_NT_DEFS ${MINKERNEL_DEFS} _NT=1 _NTSUBSET_=1 _NTSYSTEM_=1 _CRTBLD=1)
set(CRT_NT_INCDIRS ${CRT_INCDIRS} ${crtw32}/h ${MINKERNEL}/ntos/inc)

add_subdirectory(convert)

add_library(libcnt STATIC dummy.c)
target_link_libraries(libcnt PRIVATE convert)
set_property(TARGET libcnt PROPERTY FOLDER "C Runtime (NT)")
