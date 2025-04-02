cmake_minimum_required(VERSION 3.29)

set(RAW_HEADERS nodetype.h
                rawprocs.h
                rawstruc.h)
set(RAW_SOURCES cleanup.c
                close.c
                create.c
                fileinfo.c
                fsctrl.c
                strucsup.c
                rawdisp.c
                rawinit.c
                readwrit.c
                volinfo.c)

add_library(raw STATIC ${RAW_HEADERS} ${RAW_SOURCES})
target_compile_definitions(raw PRIVATE ${NT_DEFS})
target_include_directories(raw PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${SDKTOOLS_INC_PATH})
set_property(TARGET raw PROPERTY FOLDER "Kernel")
