cmake_minimum_required(VERSION 3.29)

set(FSTUB_HEADERS drivesup.h
		  efi.h
		  ex.h
		  fstub.h
		  haldisp.h)
set(FSTUB_SOURCES halfnc.c
		  drivesup.c
		  translate.c
		  ex.c)

add_library(fstub STATIC ${FSTUB_HEADERS} ${FSTUB_SOURCES})
target_compile_definitions(fstub PRIVATE ${NT_DEFS})
target_include_directories(fstub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET fstub PROPERTY FOLDER "Kernel")
