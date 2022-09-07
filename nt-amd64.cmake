cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_PROCESSOR amd64)
set(CLANGARCH x86_64-msvc-windows)
set(ARCHDEFS "-D_AMD64_ -D_WIN64")

if ("${CMAKE_SOURCE_DIR}" MATCHES "CMakeTmp")
    include(../../../nt-common.cmake)
else()
    include(nt-common.cmake)
endif()
