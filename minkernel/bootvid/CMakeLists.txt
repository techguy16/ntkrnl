cmake_minimum_required(VERSION 3.29)

set(BOOTVID_HEADERS cmdcnst.h
                    vga.h)
set(BOOTVID_SOURCES bootdata.c
                    bootvid.c
                    bootvid.rc
                    vga.c)

add_library(bootvid SHARED ${BOOTVID_HEADERS} ${BOOTVID_SOURCES})
target_compile_definitions(bootvid PRIVATE ${MINKERNEL_DEFS})
target_include_directories(bootvid PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${DDK_INC_PATH} ${HALKIT_INC_PATH} ${MINKERNEL_INCDIRS})
target_link_options(bootvid PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/bootvid.def)
target_link_libraries(bootvid PRIVATE ntoskrnl)
