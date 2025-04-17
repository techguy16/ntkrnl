cmake_minimum_required(VERSION 3.29)

set(TARGET kd64)

set(${TARGET}_HEADERS kdp.h)
set(${TARGET}_SOURCES file.c
                 kdinit.c
                 kdbreak.c
                 kdlock.c
                 kdmove.c
                 kddbgio.c
                 kdapi.c
                 kddata.c
                 print.c
                 query.c)
set(${TARGET}_AMD64_SOURCES amd64/kdtrap.c
                       amd64/kdcmsup.c
                       amd64/kdcpuapi.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke)
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
