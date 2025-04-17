cmake_minimum_required(VERSION 3.29)

set(TARGET io)

set(${TARGET}_HEADERS iop.h
	       iopcmn.h
	       ioverifier.h
	       iovputil.h
	       sessnirp.h
	       trackirp.h)
set(${TARGET}_SOURCES ioguid.c
	       iovutil.c
	       netboot.c
	       sessnirp.c
	       trackirp.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/iomgr
									  ${CMAKE_CURRENT_SOURCE_DIR}/pnpmgr ${NT_INCDIRS} ${DDK_INC_PATH}
									  ${NET_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")

add_subdirectory(iomgr)
add_subdirectory(pnpmgr)

