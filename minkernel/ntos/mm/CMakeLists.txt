cmake_minimum_required(VERSION 3.22)

set(MM_HEADERS mi.h)
set(MM_SOURCES acceschk.c
               addrsup.c
               allocpag.c
               allocvm.c
               buildmdl.c
               checkpfn.c
               checkpte.c
               compress.c
               crashdmp.c
               creasect.c
               debugsup.c
               deleteva.c
               dmpaddr.c
               dynmem.c
               extsect.c
               flushbuf.c
               flushsec.c
               forksup.c
               freevm.c
               hypermap.c
               iosup.c
               lockvm.c
               mapcache.c
               mapview.c
               miglobal.c
               mirror.c
               mmfault.c
               mminit.c
               mmsup.c
               mmpatch.c
               mmquota.c
               modwrite.c
               nolowmem.c
               pagfault.c
               pfndec.c
               pfnlist.c
               pfsup.c
               physical.c
               procsup.c
               protect.c
               querysec.c
               queryvm.c
               readwrt.c
               sectsup.c
               session.c
               sessload.c
               shutdown.c
               specpool.c
               sysload.c
               sysptes.c
               triage.c
               umapview.c
               vadtree.c
               verifier.c
               wslist.c
               wsmanage.c
               wstree.c
               wrtfault.c
               wrtwatch.c
               zeropage.c)
set(MM_amd64_HEADERS amd64/miamd.h)
set(MM_amd64_SOURCES amd64/dataamd.c
                     amd64/initamd.c)

add_library(mm STATIC ${MM_HEADERS} ${MM_SOURCES} ${MM_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${MM_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(mm PRIVATE ${NT_DEFS})
target_include_directories(mm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${NT_INCDIRS} ${ntos}/ke ${ntos}/kd64)
set_property(TARGET mm PROPERTY FOLDER "Kernel")
