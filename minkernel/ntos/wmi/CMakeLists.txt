cmake_minimum_required(VERSION 3.29)

set(WMI_HEADERS tracep.h
                wmikmp.h
                wmiumds.h)
set(WMI_SOURCES wmi.c
                register.c
                api.c
                notify.c
                callouts.c
                tracelog.c
                traceapi.c
                tracesup.c
                secure.c
                globalog.c
                wmidata.c
                dataprov.c
                alloc.c
                chunk.c
                ds.c
                consumer.c
                enabdisa.c
                smbios.c
                mca.c)

add_library(wmi STATIC ${WMI_HEADERS} ${WMI_SOURCES})
target_compile_definitions(wmi PRIVATE ${NT_DEFS})
target_include_directories(wmi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${minkernel}/win32/inc ${SDKTOOLS_INC_PATH})
set_property(TARGET wmi PROPERTY FOLDER "Kernel")
