cmake_minimum_required(VERSION 3.29)

set(TARGET se)

set(${TARGET}_HEADERS adt.h
               adtp.h
               adtutil.h
               pch.h
               rmp.h
               sep.h
               tokenp.h)
set(${TARGET}_SOURCES accessck.c
               capture.c
               privileg.c
               rmlogon.c
               rmmain.c
               rmvars.c
               seassign.c
               seaudit.c
               sepaudit.c
               seclient.c
               seglobal.c
               seinit.c
               semethod.c
               sep.c
               subject.c
               seastate.c
               token.c
               tokenadj.c
               tokendup.c
               tokenopn.c
               tokenqry.c
               tokenset.c
               adtlog.c
               adtinit.c
               adtvars.c
               adtutil.c
               rmaudit.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NTOSINC} ${DS_INC_PATH} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
