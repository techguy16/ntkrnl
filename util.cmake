if (DEFINED __UTIL_CMAKE)
    return()
endif()

function(add_c_flags)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${ARGV}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ARGV}")
endfunction()

function(add_asm_flags)
    set(CMAKE_ASM_MASM_FLAGS "${CMAKE_ASM_MASM_FLAGS} ${ARGV}")
endfunction()
