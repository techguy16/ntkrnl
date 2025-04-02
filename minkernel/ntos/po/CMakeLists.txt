cmake_minimum_required(VERSION 3.29)

set(PO_HEADERS pop.h)
set(PO_SOURCES attrib.c
               paction.c
               pbatt.c
               pidle.c
               pinfo.c
               poinit.c
               podata.c
               postate.c
               pocall.c
               poshtdwn.c
               pwork.c
               switch.c
               notify.c
               hiber.c
               idle.c
               misc.c
               ntapi.c
               sidle.c
               suspend.c
               sys.c
               sysdev.c
               thermal.c
               throttle.c
               volume.c)
set(PO_AMD64_SOURCES amd64/xsum.asm)

add_library(po STATIC ${PO_HEADERS} ${PO_SOURCES} ${PO_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(po PRIVATE ${NT_DEFS})
target_include_directories(po PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET po PROPERTY FOLDER "Kernel")
