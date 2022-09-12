cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_PROCESSOR amd64)
set(CLANGARCH x86_64-msvc-windows)
set(ARCHDEFS "-D_AMD64_ -D_WIN64")

if ("${CMAKE_SOURCE_DIR}" MATCHES "CMakeTmp")
    set(root ${CMAKE_SOURCE_DIR}/../../..)
else()
    set(root ${CMAKE_SOURCE_DIR})
endif()
include(${root}/nt-common.cmake)

if (DEFINED NT_WINE_MASM)
	set(CMAKE_ASM_MASM_COMPILER ${root}/tools/masm64.sh)
else()
    set(CMAKE_ASM_MASM_COMPILER ${root}/tools/ml64.exe)
endif()

