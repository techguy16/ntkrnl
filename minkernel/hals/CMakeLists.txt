cmake_minimum_required(VERSION 3.29)

set(hals ${CMAKE_CURRENT_SOURCE_DIR})
set(HAL_DEFS ${MINKERNEL_DEFS} IS_HAL=1)
set(HAL_INCDIRS ${MINKERNEL_INCDIRS} ${HALKIT_INC_PATH} ${SDK_INC_PATH} ${hals}/inc ${minkernel}/ntos/inc ${minkernel}/ntos/ke ${minkernel}/ntos/io)

add_subdirectory(x86new)
add_subdirectory(halacpi)

