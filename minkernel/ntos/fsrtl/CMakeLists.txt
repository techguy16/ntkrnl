cmake_minimum_required(VERSION 3.29)

set(TARGET fsrtl)

set(${TARGET}_HEADERS fsrtlp.h)
set(${TARGET}_SOURCES dbcsname.c
                  fastio.c
                  faulttol.c
                  filelock.c
                  filter.c
                  filtrctx.c
                  fsfilter.c
                  fsrtlpc.c
                  largemcb.c
                  name.c
                  notify.c
                  oplock.c
                  pnp.c
                  unc.c
                  tunnel.c
                  stackovf.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
