cmake_minimum_required(VERSION 3.29)

set(TARGET po)

set(${TARGET}_HEADERS pop.h)
set(${TARGET}_SOURCES attrib.c
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
set(${TARGET}_AMD64_SOURCES amd64/xsum.asm)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
