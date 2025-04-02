cmake_minimum_required(VERSION 3.29)

set(DBGK_HEADERS dbgkp.h)
set(DBGK_SOURCES dbgkobj.c
                 dbgkport.c
                 dbgkproc.c)

add_library(dbgk STATIC ${DBGK_HEADERS} ${DBGK_SOURCES} ${DBGK_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${DBGK_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(dbgk PRIVATE ${NT_DEFS})
target_include_directories(dbgk PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET dbgk PROPERTY FOLDER "Kernel")
