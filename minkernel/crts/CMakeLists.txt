cmake_minimum_required(VERSION 3.22)

set(crts ${CMAKE_CURRENT_SOURCE_DIR})
set(CRT_INCDIRS ${MINKERNEL_INCDIRS})

add_subdirectory(crtw32)

