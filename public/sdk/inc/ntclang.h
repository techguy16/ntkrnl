/*

Module Name:

	ntclang.h

Abstract:

	This file is force-included when compiling with Clang, and has things that
	don't fit in anywhere else to make the build work.

Author:

	Elliot McNeil  23-May-2024

*/

#pragma once

#ifdef __clang__

#define __readcr0 __readcr0_extern
#define __writecr0 __writecr0_extern
#define __readcr4 __readcr4_extern
#define __writecr4 __writecr4_extern
#define __readcr8 __readcr8_extern
#define __writecr8 __writecr8_extern
#include <intrin.h>
#undef __readcr0
#undef __writecr0
#undef __readcr4
#undef __writecr4
#undef __readcr8
#undef __writecr8

//
// The MSVC build is free from warnings
//

#pragma clang diagnostic ignored "-Wmicrosoft-enum-forward-reference"
#pragma clang diagnostic ignored "-Wincompatible-pointer-types"
#pragma clang diagnostic ignored "-Wvisibility"
#pragma clang diagnostic ignored "-Wpragma-pack"
#pragma clang diagnostic ignored "-Wgnu-folding-constant"
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#pragma clang diagnostic ignored "-Wignored-pragma-intrinsic"
#pragma clang diagnostic ignored "-Wparentheses"
#pragma clang diagnostic ignored "-Wimplicit-int"
#pragma clang diagnostic ignored "-Wpointer-sign"
#pragma clang diagnostic ignored "-Wmicrosoft-anon-tag"
#pragma clang diagnostic ignored "-Wignored-pragma-optimize"
#pragma clang diagnostic ignored "-Wshift-count-negative"
#pragma clang diagnostic ignored "-Wshift-count-overflow"
#pragma clang diagnostic ignored "-Wignored-pragmas"
#pragma clang diagnostic ignored "-Wmicrosoft-include"
#pragma clang diagnostic ignored "-Wenum-conversion"
#pragma clang diagnostic ignored "-Wcomment"
#pragma clang diagnostic ignored "-Wextern-initializer"
#pragma clang diagnostic ignored "-Wunsequenced"
#pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
#pragma clang diagnostic ignored "-Wenum-compare"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wswitch"
#pragma clang diagnostic ignored "-Wunused-value"
#pragma clang diagnostic ignored "-Wcompare-distinct-pointer-types"
#pragma clang diagnostic ignored "-Wmissing-declarations"
#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
#pragma clang diagnostic ignored "-Wextra-tokens"
#pragma clang diagnostic ignored "-Wvisibility"
#pragma clang diagnostic ignored "-Wignored-pragma-intrinsic"
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#pragma clang diagnostic ignored "-Wextra-tokens"
#pragma clang diagnostic ignored "-Warray-bounds"
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#pragma clang diagnostic ignored "-Wmacro-redefined"
#pragma clang diagnostic ignored "-Wbitfield-constant-conversion"
#pragma clang diagnostic ignored "-Wmultichar"
#pragma clang diagnostic ignored "-Winvalid-noreturn"
#pragma clang diagnostic ignored "-Winteger-overflow"
#pragma clang diagnostic ignored "-Wtentative-definition-array"
#pragma clang diagnostic ignored "-W#pragma-messages"
#pragma clang diagnostic ignored "-Wvarargs"
#pragma clang diagnostic ignored "-Wpointer-type-mismatch"
#pragma clang diagnostic ignored "-Wsizeof-array-div"

#define __forceinline __attribute__((always_inline))

extern void __writecr0(unsigned __int64 Value);
extern unsigned __int64 __readcr0(void);
extern void __writecr4(unsigned __int64 Value);
extern unsigned __int64 __readcr4(void);
extern void __writecr8(unsigned __int64 Value);
extern unsigned __int64 __readcr8(void);

#endif
