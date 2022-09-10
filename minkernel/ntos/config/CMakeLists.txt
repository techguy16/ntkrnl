cmake_minimum_required(VERSION 3.22)

set(CONFIG_HEADERS )
set(CONFIG_SOURCES cmapi.c     
                   cmapi2.c
                   cmboot.c
                   cmchek.c
                   cmchek2.c
                   cmclose.c
                   cmconfig.c
                   cmcontrl.c
                   cmdat.c
                   cmdat2.c
                   cmdat3.c
                   cmdatini.c
                   cmdelete.c
                   cmgquota.c
                   cmhvlist.c
                   cmindex.c
                   cminit.c
                   cmname.c
                   cmnotify.c
                   cmparse.c
                   cmparse2.c
                   cmquery.c
                   cmsavres.c
                   cmsubs.c
                   cmsubs2.c
                   cmsubs3.c
                   cmse.c
                   cmsysini.c
                   cmtrecpy.c
                   cmtredel.c
                   cmtree.c
                   cmworker.c
                   cmwrapr.c
                   cmwrapr2.c
                   cmwmi.c
                   cmmapvw.c
                   cmdelay.c
                   cmvalue.c
                   cmsecache.c
                   cmdown.c
                   cmalloc.c
                   cmhook.c
                   hivebin.c
                   hivecell.c
                   hivechek.c
                   hivefree.c
                   hiveinit.c
                   hiveload.c
                   hivemap.c
                   hivesum.c
                   hivesync.c
                   hivehint.c
                   ntapi.c
                   hwprofil.c)
set(CONFIG_amd64_HEADERS i386/geninst.h
                         i386/parseini.h
                         i386/rules.h)
set(CONFIG_amd64_SOURCES i386/geninst.c
                         i386/init386.c
                         i386/initdat.c
                         i386/parseini.c
                         i386/rules.c)

add_library(config STATIC ${CONFIG_HEADERS} ${CONFIG_SOURCES} ${CONFIG_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${CONFIG_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(config PRIVATE ${NTOSINC} ${ntos}/ke ${PUBLISHEDDIR} ${PUBLISHEDDIR}/${CMAKE_SYSTEM_PROCESSOR} ${HALKIT_INC_PATH} ${SDK_INC_PATH} ${MINKERNEL_INC_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(config PRIVATE ${NT_DEFS})
