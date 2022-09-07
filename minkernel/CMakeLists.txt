cmake_minimum_required(VERSION 3.22)

set(minkernelinc ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(MINKERNEL_DEFS _WINNT_=1 WINNT=1 _WIN32_WINNT=0x0609)

add_subdirectory(ntos)
add_subdirectory(hals)
add_subdirectory(bootvid)
add_subdirectory(ntdll)
