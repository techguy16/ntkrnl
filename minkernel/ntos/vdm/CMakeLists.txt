cmake_minimum_required(VERSION 3.29)

set(TARGET vdm)

set(${TARGET}_HEADERS ntvdmp.h)
set(${TARGET}_SOURCES vdm.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NTOSINC} ${DS_INC_PATH} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
