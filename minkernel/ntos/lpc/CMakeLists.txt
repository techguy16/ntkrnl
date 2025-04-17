cmake_minimum_required(VERSION 3.29)

set(TARGET lpc)

set(${TARGET}_HEADERS lpcp.h
                ulpc.h)
set(${TARGET}_SOURCES lpcinit.c
                lpccreat.c
                lpclistn.c
                lpcconn.c
                lpccompl.c
                lpcsend.c
                lpcrecv.c
                lpcreply.c
                lpcquery.c
                lpcqueue.c
                lpcclose.c
                lpcpriv.c
                lpclog.c)
set(${TARGET}_AMD64_SOURCES amd64/lpcmove.asm)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
