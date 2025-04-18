cmake_minimum_required(VERSION 3.29)

set(TARGET init)

set(${TARGET}_HEADERS anim.h)
set(${TARGET}_SOURCES init.c
                 anim.c
                 port.c
                 bootvid.c
                 ntoskrnl.rc)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/nls/obj/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>)
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
