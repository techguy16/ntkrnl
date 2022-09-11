cmake_minimum_required(VERSION 3.22)

set(OB_HEADERS obp.h
               obvutil.h)
set(OB_SOURCES obinit.c
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

add_library(ob STATIC ${OB_HEADERS} ${OB_SOURCES})
target_compile_definitions(ob PRIVATE ${NT_DEFS})
target_include_directories(ob PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
