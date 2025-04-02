cmake_minimum_required(VERSION 3.29)

set(FSRTL_HEADERS fsrtlp.h)
set(FSRTL_SOURCES DbcsName.c
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

add_library(fsrtl STATIC ${FSRTL_HEADERS} ${FSRTL_SOURCES})
target_compile_definitions(fsrtl PRIVATE ${NT_DEFS})
target_include_directories(fsrtl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET fsrtl PROPERTY FOLDER "Kernel")
