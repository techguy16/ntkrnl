cmake_minimum_required(VERSION 3.29)

set(X86NEW_HEADERS emulate.h
		   x86new.h
		   xm86.h)
set(X86NEW_AMD64_SOURCES emulate.c
                         addops.c
                         asciiops.c
                         bitops.c
                         condops.c
                         ctrlops.c
                         data.c
                         debug.c
                         divops.c
                         inoutops.c
                         jmpops.c
                         logops.c
                         miscops.c
                         moveops.c
                         mulops.c
                         operand.c
                         pcibios.c
                         regmode.c
                         setops.c
                         shiftops.c
                         stackops.c
                         stringop.c
                         utility.c
                         x86bios.c)

add_library(x86new STATIC ${X86NEW_HEADERS} ${X86NEW_${CMAKE_SYSTEM_PROCESSOR}_SOURCES})
target_compile_definitions(x86new PRIVATE ${HAL_DEFS})
target_include_directories(x86new PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${HAL_INCDIRS})
target_link_libraries(x86new PRIVATE clang)
set_property(TARGET x86new PROPERTY FOLDER "Hardware Abstraction Layer")

