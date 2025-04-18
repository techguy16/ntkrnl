@echo off
if [%CC%] == [] set "CC=cl.exe"
set "CFLAGS=%CFLAGS% -nologo -Zi -I%~dp0..\..\public\sdk\inc"
set "COMMONFILES=%~dp0util.c"
set "LIBS=%LIBS% ntdll.lib"

for %%x in (testload.c) do (
    echo compiling %%x...
    %CC% %FLAGS% %%x %COMMONFILES% /link %LIBS% > %%x.log
)

echo done
