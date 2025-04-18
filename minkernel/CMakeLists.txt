cmake_minimum_required(VERSION 3.29)

set(minkernel ${CMAKE_CURRENT_SOURCE_DIR})
set(minkernelinc ${minkernel}/inc)
set(MINKERNEL_DEFS _WIN32_WINNT=0x502)
set(MINKERNEL_INCDIRS ${SDK_INC_PATH} ${SDK_INC_PATH}/crt ${MINKERNEL_INC_PATH} ${NTOSINC} ${SDKTOOLS_INC_PATH} ${PUBLISHEDDIR}
	${PUBLISHEDDIR}/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}> ${minkernelinc})

if (NOT DEFINED NT_MSVC)
	add_subdirectory(clang)
endif()
add_subdirectory(urtl)
add_subdirectory(ntos)
add_subdirectory(boot)
add_subdirectory(hals)
add_subdirectory(ntdll)
