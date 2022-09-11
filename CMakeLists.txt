cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ntkrnl VERSION 6.9 LANGUAGES C ASM_MASM)

if (NOT "${CMAKE_TOOLCHAIN_FILE}" MATCHES "nt-amd64.cmake")
	message(FATAL_ERROR "Use the toolchain file (set CMAKE_TOOLCHAIN_FILE)")
endif()

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 03)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

function(wrap_linkopts out)
	foreach (arg ${ARGN})
    	list(APPEND _out -Wl,${arg})
	endforeach()
	set(${out} ${_out} PARENT_SCOPE)
endfunction()

set(NT TRUE)
set(toolsdir ${CMAKE_SOURCE_DIR}/tools)
set(NTOSINC ${CMAKE_SOURCE_DIR}/minkernel/ntos/inc)
set(PUBLISHEDDIR ${CMAKE_SOURCE_DIR}/minkernel/published)
set(DDK_INC_PATH ${CMAKE_SOURCE_DIR}/public/ddk/inc)
set(HALKIT_INC_PATH ${CMAKE_SOURCE_DIR}/public/halkit/inc)
set(SDK_INC_PATH ${CMAKE_SOURCE_DIR}/public/sdk/inc)
set(DS_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/ds/inc)
set(SDKTOOLS_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/sdktools/inc)
set(MINKERNEL_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/minkernel/inc)

add_compile_definitions(DEVL=1 DBG=1)

add_subdirectory(minkernel)
