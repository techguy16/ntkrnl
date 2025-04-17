cmake_minimum_required(VERSION 3.29)

set(TARGET verifier)

set(${TARGET}_HEADERS halverifier.h
                     vfbugcheck.h
                     vfddi.h
                     vfdeadlock.h
                     vfdebug.h
                     vfdef.h
                     vfdevobj.h
                     vffilter.h
                     vfgeneric.h
                     vfinit.h
                     vfipacket.h
                     vfirp.h
                     vfirpdb.h
                     vfirplog.h
                     vfmacro.h
                     vfmajor.h
                     vfmessage.h
                     vfpacket.h
                     vfpnp.h
                     vfpower.h
                     vfpragma.h
                     vfprint.h
                     vfrandom.h
                     vfsettings.h
                     vfstack.h
                     vfutil.h
                     vfwmi.h
                     vfzwapi.h
                     vibugcheck.h
                     viddi.h
                     vifilter.h
                     vigeneric.h
                     vihal.h
                     viirp.h
                     viirpdb.h
                     viirplog.h
                     vimajor.h
                     vipnp.h
                     visettings.h)
set(${TARGET}_SOURCES vfbugcheck.c
                     vfddi.c
                     vfdeadlock.c
                     vfdebug.c
                     vfdevobj.c
                     vffileio.c
                     vffilter.c
                     vfhal.c
                     vfinit.c
                     vfirp.c
                     vfirpdb.c
                     vfirplog.c
                     vfgeneric.c
                     vfmajor.c
                     vfmessage.c
                     vfpacket.c
                     vfpnp.c
                     vfpower.c
                     vfprint.c
                     vfrandom.c
                     vfsettings.c
                     vfstack.c
                     vfutil.c
                     vfwmi.c
                     vfzwapi.c)
add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
