cmake_minimum_required(VERSION 3.29)

set(TARGET wmi)

set(${TARGET}_HEADERS tracep.h
                wmikmp.h
                wmiumds.h)
set(${TARGET}_SOURCES wmi.c
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

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${minkernel}/win32/inc ${SDKTOOLS_INC_PATH})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
