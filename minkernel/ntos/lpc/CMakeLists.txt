cmake_minimum_required(VERSION 3.29)

set(LPC_HEADERS lpcp.h
                ulpc.h)
set(LPC_SOURCES lpcinit.c
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
set(LPC_AMD64_SOURCES amd64/lpcmove.asm)

add_library(lpc STATIC ${LPC_HEADERS} ${LPC_SOURCES} ${LPC_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${LPC_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(lpc PRIVATE ${NT_DEFS})
target_include_directories(lpc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET lpc PROPERTY FOLDER "Kernel")
