cmake_minimum_required(VERSION 3.29)

set(TARGET pnpmgr)

set(${TARGET}_HEADERS pnpmgrp.h)
set(${TARGET}_SOURCES assign.c
                   devices.c
                   devnode.c
                   devintrf.c
                   dockhwp.c
                   iofileutil.c
                   mapper.c
                   notify.c
                   pnpbusno.c
                   pnpcvrt.c
                   pnpdata.c
                   pnpdd.c
                   pnpdel.c
                   pnpdma.c
                   pnpeisa.c
                   pnpenum.c
                   pnpevent.c
                   pnpinit.c
                   pnpioapi.c
                   pnpirp.c
                   pnpirq.c
                   pnpmap.c
                   pnpmemio.c
                   pnppower.c
                   pnpres.c
                   pnprlist.c
                   pnpstart.c
                   pnpsubs.c
                   ppcddb.c
                   ppcontrol.c
                   pphandle.c
                   pphotswap.c
                   pplastgood.c
                   pppagepath.c
                   ppdrvdb.c
                   ppprofile.c
                   ppvutil.c
                   remlock.c
                   report.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/.. ${NT_INCDIRS} ${WINDOWS_INC_PATH} ${DDK_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")

