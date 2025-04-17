cmake_minimum_required(VERSION 3.29)

set(TARGET ob)

set(${TARGET}_HEADERS obp.h
               obvutil.h)
set(${TARGET}_SOURCES obinit.c
               obcreate.c
               obhandle.c
               obinsert.c
               obperf.c
               obref.c
               obse.c
               obtype.c
               obdir.c
               obdevmap.c
               oblink.c
               obclose.c
               obquery.c
               obsdata.c
               obwait.c
               obvutil.c
               fastref.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
