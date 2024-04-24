## What this is
This is a project to get the Windows NT version 5.2 kernel included in the 2020 leak with patches and replacements for missing files from [here](https://rentry.co/build-win2k3) (it's made by a 4chan user but quite informative).
This project is probably not worth the time it will take but I think it's cool enough to be worth it. I'm by no means an expert on Windows NT but it fascinates me greatly and I randomly decided I wanted to be able to work with this
cobbled together set of components from the full leak on Linux, and hence I needed to be able to not only use a different compiler but also a build system that works on Linux (build.exe is heavily integrated with Microsoft's tools and
the source for a few of them, such as the compiler, isn't part of the Windows source code. Most of the tools actually are there but make fairly heavy use of the Windows API). I intend to have a somehow usable LLVM-built version of
`ntoskrnl.exe` (technically `ntkrnlmp.exe` but whatever) that just works in a slightly modified install of Windows XP/Server 2003 or at least just as a weird combo of the kernel, NTDLL, and some custom Native API programs that acts
kind of like a minimal Linux system just running BusyBox as the userspace. Please note that this project is entirely based on leaked source code with a tiny little bit of reverse engineered stuff and it is therefore a very bad idea to
make any attempt to commercialize or open source this. Use of this project is at your own risk and only for personal or research purposes, and you take all responsibility for any shitty stuff that you do or is caused by the use of
this project. Also credit to Microsoft (especially Dave Cutler) for building this incredible and historic piece of technology.

## Instructions
You need Clang, LLVM, and CMake.

To compile things, this should work:
```shell
cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE=nt.cmake
cmake --build build -j14
```

The build doesn't work yet because the CRT and some components aren't complete.
