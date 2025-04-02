cmake_minimum_required(VERSION 3.29)

set(CACHE_HEADERS cc.h)
set(CACHE_SOURCES cachedat.c
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

add_library(cache STATIC ${CACHE_HEADERS} ${CACHE_SOURCES} ${CACHE_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${CACHE_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(cache PRIVATE ${NT_DEFS})
target_include_directories(cache PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke ${ntos}/kd64
        ${HALKIT_INC_PATH} ${minkernel}/fs/fastfat)
set_property(TARGET cache PROPERTY FOLDER "Kernel")