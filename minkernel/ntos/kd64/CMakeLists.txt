cmake_minimum_required(VERSION 3.22)

set(KD64_HEADERS kdp.h)
set(KD64_SOURCES file.c
                 kdinit.c
                 kdbreak.c
                 kdlock.c
                 kdmove.c
                 kddbgio.c
                 kdapi.c
                 kddata.c
                 print.c
                 query.c)
set(KD64_amd64_SOURCES amd64/kdtrap.c
                       amd64/kdcmsup.c
                       amd64/kdcpuapi.c)

add_library(kd64 STATIC ${KD64_HEADERS} ${KD64_SOURCES} ${KD64_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(kd64 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDK_INC_PATH} ${NTOSINC} ${MINKERNEL_INC_PATH} ${ntos}/ke ${SDKTOOLS_INC_PATH} ${PUBLISHEDDIR} ${PUBLISHEDDIR}/${CMAKE_SYSTEM_PROCESSOR})
target_compile_definitions(kd64 PRIVATE ${NT_DEFS})
