## What this is
I'm trying to get `ntoskrnl.exe`, `hal.dll`, `bootvid.dll`, `ntdll.dll`, and `kdcom.dll` to build with Clang,
in the hope of seeing it work with the MSVC binaries in a normal build.

A secondary goal is the mere act of building NT with CMake (or anything other than `build.exe`, really).

## Instructions
You need Clang, LLVM, and CMake.

To compile things, this should work:
```shell
cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE=nt.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE -GNinja
cmake --build build
```

There are still some binary libraries that I haven't made compile with Clang yet, but it does all link.
