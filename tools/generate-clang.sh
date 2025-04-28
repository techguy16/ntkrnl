#!/bin/sh

# nt.cmake decides to use Clang if NT_MSVC isn't defined and the generator isn't Visual Studio
clangflags='-G Ninja'
msvcflags='-DNT_MSVC=ON -G"Visual Studio 17 2022"'

flags="-DCMAKE_TOOLCHAIN_FILE=$(dirname "$0")/../nt.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE -DCMAKE_BUILD_TYPE=Debug"

script_name=$(basename "$0")
if [ "$script_name" = "generate-msvc.sh" ]; then
    flags="$flags $msvcflags"
else
    flags="$flags $clangflags"
fi

cmake -S"$(dirname "$0")/.." -B"$(dirname "$0")/../cmake-build-debug" $flags "$@"
