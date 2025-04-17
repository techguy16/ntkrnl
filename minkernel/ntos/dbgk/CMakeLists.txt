cmake_minimum_required(VERSION 3.29)

set(TARGET dbgk)

set(${TARGET}_HEADERS dbgkp.h)
set(${TARGET}_SOURCES dbgkobj.c
                 dbgkport.c
                 dbgkproc.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
