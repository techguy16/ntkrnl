cmake_minimum_required(VERSION 3.22)

set(FSTUB_HEADERS drivesup.h
		  efi.h
		  ex.h
		  fstub.h
		  haldisp.h)
set(FSTUB_SOURCES halfnc.c
		  drivesup.c
		  translate.c
		  ex.c)

add_library(fstub STATIC ${FSTUB_HEADERS} ${FSTUB_SOURCES})

