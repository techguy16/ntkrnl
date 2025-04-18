cmake_minimum_required(VERSION 3.29)

set(TARGET perf)

set(${TARGET}_HEADERS perfinfokrn.h
                 perfp.h)
set(${TARGET}_SOURCES hooks.c
                 logging.c
                 perfdata.c
                 perfsup.c

		 $<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>/setlog.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
