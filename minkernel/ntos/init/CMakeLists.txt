cmake_minimum_required(VERSION 3.29)

set(INIT_HEADERS anim.h)
set(INIT_SOURCES init.c
                 anim.c
                 port.c
                 bootvid.c
                 ntoskrnl.rc)

add_library(init STATIC ${INIT_HEADERS} ${INIT_SOURCES} ${INIT_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${INIT_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(init PRIVATE ${NT_DEFS})
target_include_directories(init PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET init PROPERTY FOLDER "Kernel")
