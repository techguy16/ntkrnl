cmake_minimum_required(VERSION 3.29)

set(TARGET config)

set(${TARGET}_HEADERS cmp.h
                   cmpbug.h
                   cmplock.h
                   hive.h)
set(${TARGET}_SOURCES cmapi.c
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
set(${TARGET}_AMD64_HEADERS i386/geninst.h
                         i386/parseini.h
                         i386/rules.h)
set(${TARGET}_AMD64_SOURCES i386/geninst.c
                         i386/init386.c
                         i386/initdat.c
                         i386/parseini.c
                         i386/rules.c)

add_library(${TARGET} STATIC ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${${TARGET}_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(${TARGET} PRIVATE ${NTOSINC} ${ntos}/ke ${PUBLISHEDDIR} ${PUBLISHEDDIR}/${CMAKE_SYSTEM_PROCESSOR} ${HALKIT_INC_PATH} ${SDK_INC_PATH}
                                          ${SDK_INC_PATH}/crt ${MINKERNEL_INC_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(${TARGET} PRIVATE ${NT_DEFS})
target_compile_options(${TARGET} PRIVATE ${NT_C_FLAGS})
set_property(TARGET ${TARGET} PROPERTY FOLDER "Kernel")
