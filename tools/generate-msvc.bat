@echo off

:: nt.cmake decides to use Clang if NT_MSVC isn't defined and the generator isn't Visual Studio
set "clangflags=-G^"Ninja^""
set "msvcflags=-DNT_MSVC=ON -G^"Visual Studio 17 2022^""

set "flags=-DCMAKE_TOOLCHAIN_FILE=%~dp0..\nt.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE -DCMAKE_BUILD_TYPE=Debug"
if "%~nx0" == "generate-msvc.bat" (
	set "flags=%flags% %msvcflags%"
) else (
	set "flags=%flags% %clangflags%"
)

cmake -S%~dp0.. -B%~dp0..\cmake-build-debug %flags% %*
