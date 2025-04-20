@rem @echo off

setlocal enabledelayedexpansion

if [%CC%] == [] set "CC=cl.exe"

set CFLAGS=%CFLAGS% -nologo -Zi -I%~dp0..\..\public\sdk\inc
set COMMONFILES=%~dp0util.c
set LIBS=%LIBS% ntdll.lib

for %%x in (testload.c) do (
    set COMPILE=%CC% %CFLAGS% %%x %COMMONFILES% /link %LIBS%
	echo !COMPILE!
	!COMPILE!
)

echo done
