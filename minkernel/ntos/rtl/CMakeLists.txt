cmake_minimum_required(VERSION 3.29)

set(RTL_HEADERS add2strt.h
                heappagi.h
                heappriv.h
                ntrtlp.h
                range.h
                remlock.h
                stdtimep.h
                str2addt.h
                threads.h
                tracedbp.h
                triangle.h
                xprs.h)
set(RTL_SOURCES acledit.c 
                add2stra.c
                add2strw.c
                assert.c  
                atom.c    
                avltable.c
                bitmap.c  
                bootstatus.c
                checksum.c
                cnvint.c  
                compress.c
                debug.c   
                eballoc.c 
                environ.c 
                error.c   
                excptdbg.c
                generr.c
                gentable.c
                gen8dot3.c
                guid.c    
                heap.c    
                imagedir.c
                rtlimagentheader.c
                intbits.c 
                ldrrsrc.c 
                ldrreloc.c
                lookup.c  
                lznt1.c   
                message.c 
                nls.c     
                nlsxlat.c 
                pctohdr.c 
                peb.c     
                prefix.c  
                prodtype.c
                random.c  
                range.c   
                regutil.c 
                rtlassig.c
                rtldata.c 
                rtlexec.c 
                rtlpatch.c
                rxact.c   
                sertl.c   
                splay.c   
                str2adda.c
                str2addw.c
                string.c  
                stktrace.c
                sysvol.c  
                time.c    
                tracedb.c 
                version.c 
                xencode.c)
set(RTL_AMD64_HEADERS amd64/ntrtlamd64.h)
set(RTL_AMD64_SOURCES amd64/capture.asm
                      amd64/chkstk.asm
                      amd64/context.c
                      amd64/debugstb.asm
                      amd64/exdsptch.c
                      amd64/misalign.c
                      amd64/movemem.asm
                      amd64/raise.c
                      amd64/slist.asm
                      amd64/stkwalk.c
                      amd64/xcptmisc.asm)

add_library(ntosrtl STATIC ${RTL_HEADER} ${RTL_SOURCES} ${RTL_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${RTL_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(ntosrtl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${minkernelinc} ${NT_INCDIRS} ${DS_INC_PATH} ${CMAKE_SYSTEM_PROCESSOR})
target_compile_definitions(ntosrtl PRIVATE ${NT_DEFS})
target_compile_definitions(ntosrtl PRIVATE NTOS_KERNEL_RUNTIME=1)
set_property(TARGET ntosrtl PROPERTY FOLDER "Kernel")

add_library(ntosrtluser STATIC ${RTL_HEADER} ${RTL_SOURCES} ${RTL_${CMAKE_SYSTEM_PROCESSOR}_HEADERS} ${RTL_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_include_directories(ntosrtluser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${minkernelinc} ${NT_INCDIRS} ${DS_INC_PATH} ${DS_INC_PATH}/crypto
                                               ${CMAKE_SYSTEM_PROCESSOR} ${minkernel}/ntdll/wow6432)
target_compile_definitions(ntosrtluser PRIVATE ${NT_DEFS})
target_compile_options(ntosrtluser PRIVATE -U_CRTIMP)
