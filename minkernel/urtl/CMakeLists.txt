cmake_minimum_required(VERSION 3.29)

set(URTL_SOURCES startup.c)

add_library(nt STATIC ${URTL_SOURCES})
target_compile_definitions(nt PRIVATE ${MINKERNEL_DEFS})
target_include_directories(nt PRIVATE ${MINKERNEL_INCDIRS})
