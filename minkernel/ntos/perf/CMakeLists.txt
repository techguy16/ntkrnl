cmake_minimum_required(VERSION 3.29)

set(PERF_HEADERS perfinfokrn.h
                 perfp.h)
set(PERF_SOURCES hooks.c
                 logging.c
                 perfdata.c
                 perfsup.c

                 ${CMAKE_SYSTEM_PROCESSOR}/setlog.c)

add_library(perf STATIC ${PERF_HEADERS} ${PERF_SOURCES})
target_compile_definitions(perf PRIVATE ${NT_DEFS})
target_include_directories(perf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET perf PROPERTY FOLDER "Kernel")
