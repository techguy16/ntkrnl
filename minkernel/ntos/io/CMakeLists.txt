cmake_minimum_required(VERSION 3.22)

set(IO_HEADERS iop.h
	       iopcmn.h
	       ioverifier.h
	       iovputil.h
	       sessnirp.h
	       trackirp.h)
set(IO_SOURCES ioguid.c
	       iovutil.c
	       netboot.c
	       sessnirp.c
	       trackirp.c)

add_library(io STATIC ${IO_HEADERS} ${IO_SOURCES})
target_compile_definitions(io PRIVATE ${NT_DEFS})
target_include_directories(io PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/iomgr
									  ${CMAKE_CURRENT_SOURCE_DIR}/pnpmgr ${NT_INCDIRS} ${DDK_INC_PATH}
									  ${NET_INC_PATH})
set_property(TARGET io PROPERTY FOLDER "Kernel")

add_subdirectory(iomgr)
add_subdirectory(pnpmgr)

