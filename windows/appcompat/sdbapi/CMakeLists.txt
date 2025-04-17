cmake_minimum_required(VERSION 3.29)

set(SDBAPI_HEADERS sdbp.h)
set(SDBAPI_SOURCES sdbapi.c
                   read.c
                   findtag.c
                   hash.c
                   dbaccess.c
                   attributes.c
                   index.c
                   guid.c)
set(SDBAPI_KMODE_SOURCES ntbase.c
                         ntver.c
                         kmode/ntkmode.c
                         kmode/ahcache.c)

add_library(sdbapint STATIC ${SDBAPI_HEADERS} ${SDBAPI_SOURCES} ${SDBAPI_KMODE_SOURCES})
target_compile_definitions(sdbapint PRIVATE KERNEL_MODE=1 NT_SYSTEM=1 _NTSYSTEM_=1)
target_compile_options(sdbapint PRIVATE -Os)
target_include_directories(sdbapint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${DDK_INC_PATH} ${MINKERNEL_INC_PATH} ${SDK_INC_PATH} ${SDK_INC_PATH}/crt ${WINDOWS_INC_PATH})
set_property(TARGET sdbapint PROPERTY FOLDER "Windows/AppCompat")
