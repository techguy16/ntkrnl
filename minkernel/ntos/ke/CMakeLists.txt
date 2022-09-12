cmake_minimum_required(VERSION 3.22)

set(KE_HEADERS genxx.h
        ki.h)
set(KE_SOURCES apcobj.c
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
set(KE_amd64_HEADERS amd64/kiamd64.h)
set(KE_amd64_SOURCES amd64/allproc.c
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
      #  amd64/xcpt4.c # test, crashes Clang
        )

add_library(ke STATIC ${KE_HEADERS} ${KE_SOURCES} ${KE_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${KE_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(ke PRIVATE ${NT_DEFS})
target_include_directories(ke PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS})
