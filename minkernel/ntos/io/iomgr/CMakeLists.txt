cmake_minimum_required(VERSION 3.29)

set(IOMGR_HEADERS dumpctl.h
		  iomgr.h)
set(IOMGR_SOURCES arcsec.c
                  cancelapi.c
                  complete.c
                  create.c
                  devctrl.c
                  dev2dos.c
                  dumpctl.c
                  dir.c
		  errorlog.c
                  fsctrl.c
                  internal.c
                  iodata.c
                  ioinit.c
                  iosubs.c
                  ioverifier.c
                  ioPerf.c
                  loadunld.c
                  lock.c
                  misc.c
                  objsup.c
                  open.c
                  parse.c
                  qsea.c
                  qsfs.c
                  qsinfo.c
                  qsquota.c
                  query.c
                  read.c
		  triage.c
                  write.c)

add_library(iomgr STATIC ${IOMGR_HEADERS} ${IOMGR_SOURCES})
target_compile_definitions(iomgr PRIVATE ${NT_DEFS})
target_include_directories(iomgr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/.. ${NT_INCDIRS} ${DDK_INC_PATH})
set_property(TARGET iomgr PROPERTY FOLDER "Kernel")

