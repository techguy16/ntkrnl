cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_policy(SET CMP0091 NEW) # MSVC_RUNTIME_LIBRARY

project(ntkrnl VERSION 5.2 LANGUAGES C ASM_MASM)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 03)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
set(CMAKE_EXECUTABLE_SUFFIX .exe)
set(CMAKE_SHARED_LIBRARY_PREFIX)
set(CMAKE_SHARED_LIBRARY_SUFFIX .dll)
set(CMAKE_STATIC_LIBRARY_PREFIX)
set(CMAKE_STATIC_LIBRARY_SUFFIX .lib)

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
set(DDK_LIB_PATH ${CMAKE_SOURCE_DIR}/public/ddk/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set(HALKIT_INC_PATH ${CMAKE_SOURCE_DIR}/public/halkit/inc)
set(HALKIT_LIB_PATH ${CMAKE_SOURCE_DIR}/public/halkit/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set(SDK_INC_PATH ${CMAKE_SOURCE_DIR}/public/sdk/inc)
set(SDK_LIB_PATH ${CMAKE_SOURCE_DIR}/public/sdk/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set(DS_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/ds/inc)
set(DS_LIB_PATH ${CMAKE_SOURCE_DIR}/public/internal/ds/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set(SDKTOOLS_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/sdktools/inc)
set(MINKERNEL_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/minkernel/inc)
set(MINKERNEL_LIB_PATH ${CMAKE_SOURCE_DIR}/public/internal/minkernel/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set(NET_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/net/inc)
set(WINDOWS_INC_PATH ${CMAKE_SOURCE_DIR}/public/internal/windows/inc)
set(WINDOWS_LIB_PATH ${CMAKE_SOURCE_DIR}/public/internal/windows/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)

add_compile_definitions(_NO_CRT_STDIO_INLINE _CRT_SECURE_NO_WARNINGS _WIN2K_COMPAT_SLIST_USAGE)
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_compile_definitions(DEVL=1 DBG=1)
else()
	add_compile_definitions(DBG=0)
endif()

set_property(GLOBAL PROPERTY MSVC_RUNTIME_LIBRARY "")

add_subdirectory(windows)
add_subdirectory(minkernel)
