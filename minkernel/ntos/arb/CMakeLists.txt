cmake_minimum_required(VERSION 3.22)

set(ARB_HEADERS arbp.h)
set(ARB_SOURCES arbiter.c
		debug.c)

add_library(halarbiter STATIC ${ARB_HEADERS} ${ARB_SOURCES})
target_compile_definitions(halarbiter PRIVATE ${NT_DEFS} _NTHAL_=1)
target_include_directories(halarbiter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})
set_property(TARGET halarbiter PROPERTY FOLDER "Hardware Abstraction Layer")

add_library(arbiter STATIC ${ARB_HEADERS} ${ARB_SOURCES})
target_compile_definitions(arbiter PRIVATE ${NT_DEFS})
target_include_directories(arbiter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})

add_library(arb STATIC ${ARB_HEADERS} ${ARB_SOURCES})
target_compile_definitions(arb PRIVATE ${NT_DEFS})
target_include_directories(arb PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})
set_property(TARGET arb PROPERTY FOLDER "Kernel")

