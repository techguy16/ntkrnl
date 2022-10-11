cmake_minimum_required(VERSION 3.22)

set(minkernel ${CMAKE_CURRENT_SOURCE_DIR})
set(minkernelinc ${minkernel}/inc)
set(MINKERNEL_DEFS)
set(MINKERNEL_INCDIRS ${SDK_INC_PATH} ${SDK_INC_PATH}/crt ${MINKERNEL_INC_PATH} ${NTOSINC} ${SDKTOOLS_INC_PATH} ${PUBLISHEDDIR}
        ${PUBLISHEDDIR}/${CMAKE_SYSTEM_PROCESSOR} ${minkernelinc})

add_subdirectory(urtl)
add_subdirectory(ntos)
add_subdirectory(kdcom)
add_subdirectory(hals)
add_subdirectory(bootvid)
add_subdirectory(ntdll)
