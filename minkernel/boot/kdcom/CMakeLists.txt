cmake_minimum_required(VERSION 3.29)

set(KDCOM_HEADERS kdcomp.h)
set(KDCOM_SOURCES ixkdcom.c
		  kdcom.c
		  kdcom.rc
		  kdcomio.c
		  xxkdsup.c)

add_library(kdcom SHARED ${KDCOM_HEADERS} ${KDCOM_SOURCES})
add_library(kdcom_static STATIC ${KDCOM_HEADERS} ${KDCOM_SOURCES})
target_compile_definitions(kdcom PRIVATE ${MINKERNEL_DEFS} ACPI_HAL=1)
target_include_directories(kdcom PRIVATE ${MINKERNEL_INCDIRS} ${HALKIT_INC_PATH})
target_compile_definitions(kdcom_static PRIVATE ${MINKERNEL_DEFS})
target_include_directories(kdcom_static PRIVATE ${MINKERNEL_INCDIRS} ${HALKIT_INC_PATH})
target_link_libraries(kdcom PRIVATE ${DDK_LIB_PATH}/hal.lib ${MINKERNEL_LIB_PATH}/ntoskrnl.lib clang)
target_link_options(kdcom PRIVATE -def:${CMAKE_CURRENT_SOURCE_DIR}/dll/kdcom.def -noentry -base:0x10000 -debug -release -subsystem:native)
set_property(TARGET kdcom PROPERTY FOLDER "Kernel Debugger")
set_property(TARGET kdcom_static PROPERTY FOLDER "Kernel Debugger")

