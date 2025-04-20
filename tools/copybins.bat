@echo off

if [%1] == [] (
	echo need install drive root
	goto :eof
)

set "root=%1\windows\system32"

if not exist %root%\ntoskrnl.exe.orig copy /b %root%\ntoskrnl.exe %root%\ntoskrnl.exe.orig
copy /b %~dp0..\cmake-build-debug\minkernel\ntos\ntoskrnl.exe %root%\ntoskrnl.exe
copy /b %~dp0..\cmake-build-debug\minkernel\ntos\ntoskrnl.exe %root%\ntoskrnl.dll
if not exist %root%\hal.dll.orig copy /b %root%\hal.dll %root%\hal.dll.orig
copy /b %~dp0..\cmake-build-debug\minkernel\hals\halacpi\hal.dll %root%\hal.dll
if not exist %root%\kdcom.dll.orig copy /b %root%\kdcom.dll %root%\kdcom.dll.orig
copy /b %~dp0..\cmake-build-debug\minkernel\boot\kdcom\kdcom.dll %root%\kdcom.dll
if not exist %root%\bootvid.dll.orig copy /b %root%\bootvid.dll %root%\bootvid.dll.orig
copy /b %~dp0..\cmake-build-debug\minkernel\boot\bootvid\bootvid.dll %root%\bootvid.dll

