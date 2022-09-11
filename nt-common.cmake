cmake_minimum_required(VERSION 3.22)

set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_SYSTEM_VERSION 6.9)

set(CMAKE_C_COMPILER clang-cl)
set(CMAKE_CXX_COMPILER clang-cl)

set(CLANGWARNINGS "-Wno-microsoft-enum-forward-reference -Wno-visibility -Wno-pragma-pack -Wno-gnu-folding-constant -Wno-inconsistent-dllimport -Wno-ignored-pragma-intrinsic -Wno-parentheses -Wno-implicit-int -Wno-pointer-sign -Wno-microsoft-anon-tag -Wno-ignored-pragma-optimize -Wno-shift-count-negative -Wno-shift-count-overflow")
set(CMAKE_C_FLAGS_INIT "-fms-compatibility ${CLANGWARNINGS} --target=${CLANGARCH} ${ARCHDEFS} -Xclang -ffreestanding")
set(CMAKE_CXX_FLAGS_INIT "-fms-compatibility ${CLANGWARNINGS} --target=${CLANGARCH} ${ARCHDEFS} -Xclang -ffreestanding")

set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> -nodefaultlib <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES>")
set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> -nodefaultlib <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES>")
set(CMAKE_C_CREATE_SHARED_LIBRARY "${CMAKE_C_LINK_EXECUTABLE} -dll")
set(CMAKE_CXX_CREATE_SHARED_LIBRARY "${CMAKE_C_LINK_EXECUTABLE} -dll")
set(CMAKE_AR llvm-ar)

if (NOT "${CMAKE_HOST_SYSTEM_NAME}" MATCHES "Windows")
	set(NT_WINE_MASM TRUE)
endif()

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

set(CMAKE_EXECUTABLE_SUFFIX .exe)
set(CMAKE_SHARED_LIBRARY_PREFIX)
set(CMAKE_SHARED_LIBRARY_SUFFIX .dll)

# CMake seems to give zero fucks about this variable when I try to use it
set(CMAKE_STATIC_LIBRARY_PREFIX)
set(CMAKE_STATIC_LIBRARY_SUFFIX .lib)
