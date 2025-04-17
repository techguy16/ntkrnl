cmake_minimum_required(VERSION 3.29)

set(TARGET arb)

set(${TARGET}_HEADERS arbp.h)
set(${TARGET}_SOURCES arbiter.c
		debug.c)

add_library(halarbiter STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(halarbiter PRIVATE ${NT_DEFS} _NTHAL_=1)
target_include_directories(halarbiter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})
set_property(TARGET halarbiter PROPERTY FOLDER "Hardware Abstraction Layer")

add_library(arbiter STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(arbiter PRIVATE ${NT_DEFS})
target_include_directories(arbiter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})
set_property(TARGET halarbiter PROPERTY FOLDER "Hardware Abstraction Layer")

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS} NTOS_KERNEL)
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${DDK_INC_PATH} ${SDK_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")

