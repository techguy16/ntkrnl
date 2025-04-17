cmake_minimum_required(VERSION 3.29)

set(TARGET fstub)

set(${TARGET}_HEADERS drivesup.h
		  efi.h
		  ex.h
		  fstub.h
		  haldisp.h)
set(${TARGET}_SOURCES halfnc.c
		  drivesup.c
		  translate.c
		  ex.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
