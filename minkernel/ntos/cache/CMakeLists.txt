cmake_minimum_required(VERSION 3.29)

set(TARGET cache)

set(${TARGET}_HEADERS cc.h)
set(${TARGET}_SOURCES cachedat.c
                  cachesub.c
                  ccperf.c
                  copysup.c
                  fssup.c
                  lazyrite.c
                  logsup.c
                  mdlsup.c
                  pinsup.c
                  prefboot.c
                  prefetch.c
                  prefparm.c
                  vacbsup.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke ${ntos}/kd64
        ${HALKIT_INC_PATH} ${minkernel}/fs/fastfat)
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")