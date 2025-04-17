cmake_minimum_required(VERSION 3.29)

set(TARGET ps)

set(${TARGET}_HEADERS psp.h)
set(${TARGET}_SOURCES psspnd.c
	       pscid.c
	       psimpers.c
	       psinit.c
	       psdelete.c
	       psquery.c
	       create.c
	       kulookup.c
	       psquota.c
	       psctx.c
	       psopen.c
	       psjob.c
	       security.c
	       pshelper.c
	       psenum.c)
set(${TARGET}_AMD64_SOURCES amd64/psctxamd64.c
					 amd64/psldt.c
					 amd64/psvdm.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${ntos}/ke
						   ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
