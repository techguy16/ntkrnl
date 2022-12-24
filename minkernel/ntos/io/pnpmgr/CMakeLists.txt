cmake_minimum_required(VERSION 3.22)

set(PNPMGR_HEADERS pnpmgrp.h)
set(PNPMGR_SOURCES assign.c
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

add_library(pnpmgr STATIC ${PNPMGR_HEADERS} ${PNPMGR_SOURCES})
target_compile_definitions(pnpmgr PRIVATE ${NT_DEFS})
target_include_directories(pnpmgr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/.. ${NT_INCDIRS} ${WINDOWS_INC_PATH} ${DDK_INC_PATH})
set_property(TARGET pnpmgr PROPERTY FOLDER "Kernel")

