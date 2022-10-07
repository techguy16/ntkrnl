cmake_minimum_required(VERSION 3.22)

set(CONVERT_HEADERS)
set(CONVERT_SOURCES _ctype.c
		    _fptostr.c
		    _mbslen.c
		    _wctype.c
		    atof.c
		    atox.c
		    fcvt.c
		    gcvt.c
		    isctype.c
		    iswctype.c
		    mblen.c
		    mbstowcs.c
		    mbtowc.c
		    strtod.c
		    strtol.c
		    strtoq.c
		    swab.c
		    tolower.c
		    toupper.c
		    towlower.c
		    towupper.c
		    wchtodig.c
		    wcstod.c
		    wcstol.c
		    wcstoq.c
		    wcstombs.c
		    wctomb.c
		    wtof.c
		    wtox.c
		    xtoa.c
		    xtow.c)

add_library(convertnt STATIC ${CONVERT_HEADERS} ${CONVERT_SOURCES})
target_compile_definitions(convertnt PRIVATE ${CRT_NT_DEFS})
target_include_directories(convertnt PRIVATE ${CRT_NT_INCDIRS})
set_property(TARGET convertnt PROPERTY FOLDER "C Runtime (NT)")

