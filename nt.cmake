cmake_minimum_required(VERSION 3.29)

# the Windows module drags in a ton of flags and other stuff
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 5.2)

set(CMAKE_SYSTEM_PROCESSOR AMD64)
set(CLANG_ARCH x86_64-msvc-windows)
set(ARCH_DEFS "-D_AMD64_ -D_WIN64")
if (NOT "${CMAKE_HOST_SYSTEM_NAME}" MATCHES "Windows")
    set(NT_WINE_MASM TRUE)
    set(CMAKE_ASM_MASM_COMPILER ${CMAKE_SOURCE_DIR}/tools/masm.sh)
else()
    set(CMAKE_ASM_MASM_COMPILER ${CMAKE_SOURCE_DIR}/tools/ml64.exe)
endif()

if (DEFINED NT_MSVC OR "${CMAKE_GENERATOR}" MATCHES "Visual Studio")
    set(CMAKE_C_COMPILER cl)
    set(CMAKE_CXX_COMPILER cl)
	set(NT_COMPILER_LIBS "")
else()
    set(CMAKE_C_COMPILER clang-cl)
    set(CMAKE_CXX_COMPILER clang-cl)
	set(NT_COMPILER_LIBS clang ${CMAKE_SOURCE_DIR}/public/sdk/lib/$<LOWER_CASE:${CMAKE_SYSTEM_PROCESSOR}>/clang_rt.builtins.lib)
endif()

set(COMMON_FLAGS "${ARCH_DEFS} -Zl -GS- -Os -GR-")
set(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS}")

if (NOT DEFINED NT_MSVC)
    set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -fms-compatibility -fms-extensions --target=${CLANG_ARCH} ${ARCH_DEFS} -Xclang -ffreestanding")
    set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -fms-compatibility -fms-extensions --target=${CLANG_ARCH} ${ARCH_DEFS} -Xclang -ffreestanding")
	set(CMAKE_LINKER lld-link)
	set(CMAKE_AR llvm-ar)
	set(CMAKE_RC_COMPILER llvm-rc)
else()
    set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT}")
    set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CX_FLAGS_INIT}")
	set(CMAKE_LINKER link)
	set(CMAKE_AR lib)
	set(CMAKE_RC_COMPILER rc)

	# LLVM is compatible with CMake's assumptions, but these have to be overridden like this
	foreach (lang C CXX)
		set(CMAKE_${lang}_COMPILE_OBJECT
				"<CMAKE_${lang}_COMPILER> ${CMAKE_START_TEMP_FILE} /nologo ${_COMPILE_${lang}} <DEFINES> <INCLUDES> <FLAGS> /Fo<OBJECT> /Fd<TARGET_COMPILE_PDB>${_FS_${lang}} -c <SOURCE>${CMAKE_END_TEMP_FILE}")
		set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE
			"<CMAKE_${lang}_COMPILER> > ${CMAKE_START_TEMP_FILE} <PREPROCESSED_SOURCE> /nologo ${_COMPILE_${lang}} <DEFINES> <INCLUDES> <FLAGS> -E <SOURCE>${CMAKE_END_TEMP_FILE}")
		set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE
			"<CMAKE_${lang}_COMPILER> ${CMAKE_START_TEMP_FILE} /nologo ${_COMPILE_${lang}} <DEFINES> <INCLUDES> <FLAGS> /FoNUL /FAs /Fa<ASSEMBLY_SOURCE> /c <SOURCE>${CMAKE_END_TEMP_FILE}")
		set(CMAKE_${lang}_CREATE_STATIC_LIBRARY  "<CMAKE_AR> ${CMAKE_CL_NOLOGO} <LINK_FLAGS> /out:<TARGET> <OBJECTS> ")
	endforeach()
endif()

set(_CMAKE_VS_LINK_DLL "<CMAKE_COMMAND> -E vs_link_dll --msvc-ver=${MSVC_VERSION} --intdir=<OBJECT_DIR> --rc=<CMAKE_RC_COMPILER> --mt=<CMAKE_MT> --manifests <MANIFESTS> -- ")
set(_CMAKE_VS_LINK_EXE "<CMAKE_COMMAND> -E vs_link_exe --msvc-ver=${MSVC_VERSION} --intdir=<OBJECT_DIR> --rc=<CMAKE_RC_COMPILER> --mt=<CMAKE_MT> --manifests <MANIFESTS> -- ")

set(LINK_FLAGS "-nodefaultlib -errorlimit:0 -force:multiple")
set(CMAKE_C_LINK_EXECUTABLE "${_CMAKE_VS_LINK_EXE}<CMAKE_LINKER> ${LINK_FLAGS} <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -out:<TARGET>")
set(CMAKE_CXX_LINK_EXECUTABLE "${_CMAKE_VS_LINK_EXE}<CMAKE_LINKER> ${LINK_FLAGS} <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -out:<TARGET>")
set(CMAKE_C_CREATE_SHARED_LIBRARY "${_CMAKE_VS_LINK_DLL}<CMAKE_LINKER> ${LINK_FLAGS} <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -dll -out:<TARGET>")
set(CMAKE_CXX_CREATE_SHARED_LIBRARY "${_CMAKE_VS_LINK_DLL}<CMAKE_LINKER> ${LINK_FLAGS} <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -dll -out:<TARGET>")

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_C_STANDARD_LIBRARIES_INIT "")
set(CMAKE_CXX_STANDARD_LIBRARIES_INIT "")
