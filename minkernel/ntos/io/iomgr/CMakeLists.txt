cmake_minimum_required(VERSION 3.29)

set(TARGET iomgr)

set(${TARGET}_HEADERS dumpctl.h
		  iomgr.h)
set(${TARGET}_SOURCES arcsec.c
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
                  ioperf.c
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

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/.. ${NT_INCDIRS} ${DDK_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")

