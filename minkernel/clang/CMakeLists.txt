cmake_minimum_required(VERSION 3.29)

set(CLANG_HEADERS)
set(CLANG_SOURCES dummy.c)
set(CLANG_AMD64_SOURCES amd64/intrin.c)

add_library(clang STATIC ${CLANG_HEADERS} ${CLANG_SOURCES} ${CLANG_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(clang PRIVATE ${NT_DEFS})
target_include_directories(clang PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDK_INC_PATH})
