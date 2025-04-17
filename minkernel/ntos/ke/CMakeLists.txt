cmake_minimum_required(VERSION 3.29)

set(TARGET ke)

set(${TARGET}_HEADERS genxx.h
        ki.h)
set(${TARGET}_SOURCES apcobj.c
        apcsup.c
        balmgr.c
        bugcheck.c
        config.c
        debug.c
        devquobj.c
        dpclock.c
        dpcobj.c
        dpcsup.c
        eventobj.c
        idsched.c
        interobj.c
        kernldat.c
        kevutil.c
        kiinit.c
        miscc.c
        mutntobj.c
        procobj.c
        profobj.c
        queueobj.c
        raisexcp.c
        semphobj.c
        thredobj.c
        thredsup.c
        timerobj.c
        timersup.c
        wait.c
        waitsup.c
        xipi.c
        yield.c)
set(${TARGET}_AMD64_HEADERS amd64/kiamd64.h)
set(${TARGET}_AMD64_SOURCES amd64/allproc.c
        amd64/apcuser.c
        amd64/callback.c
        amd64/exceptn.c
        amd64/flush.c
        amd64/flushtb.c
        amd64/initkr.c
        amd64/intobj.c
        amd64/ipi.c
        amd64/misc.c
        amd64/pat.c
        amd64/queuelock.c
        amd64/spinlock.c
        amd64/thredini.c
        amd64/apcint.asm
        amd64/callout.asm
        amd64/clockint.asm
        amd64/cpuid.asm
        amd64/ctxswap.asm
        amd64/dpcint.asm
        amd64/idle.asm
        amd64/intipi.asm
        amd64/intsup.asm
        amd64/miscs.asm
        amd64/procstat.asm
        amd64/profint.asm
        amd64/start.asm # entry point

        amd64/sysstubs.asm # need to figure out how to generate these
        amd64/systable.asm

        amd64/threadbg.asm
        amd64/trap.asm
        amd64/zero.asm
        # amd64/xcpt4.c # this file is a test, and it actually crashes Clang
        )

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
