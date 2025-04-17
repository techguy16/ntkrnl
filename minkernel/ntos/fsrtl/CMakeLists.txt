cmake_minimum_required(VERSION 3.29)

set(TARGET fsrtl)

set(${TARGET}_HEADERS fsrtlp.h)
set(${TARGET}_SOURCES DbcsName.c
                  FastIo.c
                  FaultTol.c
                  FileLock.c
                  Filter.c
                  FiltrCtx.c
                  FsFilter.c
                  FsRtlPc.c
                  LargeMcb.c
                  Name.c
                  Notify.c
                  Oplock.c
                  PnP.c
                  Unc.c
                  Tunnel.c
                  StackOvf.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
