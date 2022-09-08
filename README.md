## What this is
This is a project to get the Windows NT version 5.2 kernel included in the 2020 leak with patches and replacements for missing files from [here](https://rentry.co/build-win2k3) (it's made by a 4chan user but quite informative).
This project is probably not worth the time it will take but I think it's cool enough to be worth it. I'm by no means an expert on Windows NT but it fascinates me greatly and I randomly decided I wanted to be able to work with this
cobbled together set of components from the full leak on Linux, and hence I needed to be able to not only use a different compiler but also a build system that works on Linux (build.exe is heavily integrated with Microsoft's tools and
the source for a few of them, such as the compiler, isn't part of the Windows source code. Most of the tools actually are there but make fairly heavy use of the Windows API). I intend to have a somehow usable LLVM-built version of
`ntoskrnl.exe` (technically `ntkrnlmp.exe` but whatever) that just works in a slightly modified install of Windows XP/Server 2003 or at least just as a weird combo of the kernel, NTDLL, and some custom Native API programs that acts
kind of like a minimal Linux system just running BusyBox as the userspace. Please note that this project is entirely based on leaked source code with a tiny little bit of reverse engineered stuff and it is therefore a very bad idea to
make any attempt to commercialize or open source this. Use of this project is at your own risk and only for personal or research purposes, and you take all responsibility for any shitty stuff that you do or is caused by the use of
this project. Also credit to Microsoft (especially Dave Cutler) for building this incredible and historic piece of technology.

## Main challenges in this foolhardy endeavour
OBVIOUSLY there are gonna be quite a few issues with this, namely:
- ~~Clang is LP64 but Windows is LLP64, so that sucks~~ Nope, turns out it was just some fuckery with some headers declaring intrinsic functions in a way Clang doesn't like
- The code relies heavily on MSVC-only features. Clang is a lot better at MSVC compatibility than GCC could be and in my opinion is much better in tons of other ways too, and the Windows headers do define macros (I don't know for but I'm pretty sure they're slightly designed to be portable between compilers) so this is less of an issue than it could be
- There are likely to be issues related to the binary being unsigned (probably fixable) and LLVM generating the binary differently that will cause issues with the bootloader and stuff, but if that's the case in theory if I replace those other components too (more work, but there aren't many of them) then they'll work fine and the rest of the system won't know the difference through the power of dynamic linking.
