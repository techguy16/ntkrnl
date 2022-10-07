cmake_minimum_required(VERSION 3.22)

set(SE_HEADERS adt.h
               adtp.h
               adtutil.h
               pch.h
               rmp.h
               sep.h
               tokenp.h)
set(SE_SOURCES accessck.c
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

add_library(se STATIC ${SE_HEADERS} ${SE_SOURCES})
target_compile_definitions(se PRIVATE ${NT_DEFS})
target_include_directories(se PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NTOSINC} ${DS_INC_PATH} ${NT_INCDIRS})
set_property(TARGET se PROPERTY FOLDER "Kernel")
