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
set(KE_amd64_HEADERS keamd64.h
                     kiamd64.h)
