cmake_minimum_required(VERSION 3.29)

set(PS_HEADERS psp.h)
set(PS_SOURCES psspnd.c
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
set(PS_AMD64_SOURCES amd64/psctxamd64.c
					 amd64/psldt.c
					 amd64/psvdm.c)

add_library(ps STATIC ${PS_HEADERS} ${PS_SOURCES} ${PS_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(ps PRIVATE ${NT_DEFS})
target_include_directories(ps PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${ntos}/ke
						   ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ps PROPERTY FOLDER "Kernel")
