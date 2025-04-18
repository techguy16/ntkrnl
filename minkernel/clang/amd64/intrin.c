/*++

Copyright (c) 2025 MobSlicer152


Module Name:

    intrin.c

Abstract:

    This file implements some intrinsics missing in Clang

Author:

    MobSlicer152   18-Apr-25

--*/

#include <nt.h>
#include <ntclang.h>

#if __x86_64__
#define __LPTRINT_TYPE__ __int64
#else
#define __LPTRINT_TYPE__ long
#endif

#define MAKE_CR_RDWR(n)                                                                                                          \
	unsigned __LPTRINT_TYPE__ __readcr##n(void)                                                                                  \
	{                                                                                                                            \
		unsigned __LPTRINT_TYPE__ __cr##n##_val;                                                                                 \
		__asm__ __volatile__("mov {%%cr" #n ", %0|%0, cr" #n "}" : "=r"(__cr##n##_val) : : "memory");                            \
		return __cr##n##_val;                                                                                                    \
	}                                                                                                                            \
                                                                                                                                 \
	void __writecr##n(unsigned __INTPTR_TYPE__ __cr##n##_val)                                                                    \
	{                                                                                                                            \
		__asm__ volatile("mov {%0, %%cr" #n "|cr" #n ", %0}" : : "r"(__cr##n##_val) : "memory");                                 \
	}

MAKE_CR_RDWR(0)
MAKE_CR_RDWR(4)
MAKE_CR_RDWR(8)

void __writegsbyte(unsigned long offset, unsigned char data)
{
	__asm__ volatile("movb %[data], %%al\n"
					 "movl %[offset], %%edx\n"
					 "movb %%gs:(%%rdx), %%al\n"
					 :
					 : [data] "r"(data), [offset] "r"(offset)
					 : "%al", "%edx");
}

void __writegsword(unsigned long offset, unsigned short data)
{
	__asm__ volatile("movw %[data], %%ax\n"
					 "movl %[offset], %%edx\n"
					 "movw %%gs:(%%rdx), %%ax\n"
					 :
					 : [data] "r"(data), [offset] "r"(offset)
					 : "%ax", "%edx");
}

void __writegsdword(unsigned long offset, unsigned long data)
{
	__asm__ volatile("movl %[data], %%eax\n"
					 "movl %[offset], %%edx\n"
					 "movl %%gs:(%%rdx), %%eax\n"
					 :
					 : [data] "r"(data), [offset] "r"(offset)
					 : "%eax", "%edx");
}

void __writegsqword(unsigned long offset, unsigned __int64 data)
{
	__asm__ volatile("movq %[data], %%rax\n"
					 "movl %[offset], %%edx\n"
					 "movq %%gs:(%%rdx), %%rax\n"
					 :
					 : [data] "r"(data), [offset] "r"(offset)
					 : "%rax", "%edx");
}

void _enable(void)
{
	__asm__ volatile("sti");
}

void _disable(void)
{
	__asm__ volatile("cli");
}

void _assume(BOOLEAN x)
{
	__builtin_assume(x);
}

void __writemsr(ULONG Register, UINT64 Value)
{
	__asm__ volatile("wrmsr" : : "c"(Register), "A"(Value));
}

void __wbinvd()
{
	__asm__ volatile("wbinvd");
}

unsigned short _byteswap_ushort(unsigned short value)
{
	return __builtin_bswap16(value);
}

unsigned long _byteswap_ulong(unsigned long value)
{
	return __builtin_bswap32(value);
}

unsigned int __getcallerseflags(void)
{
	unsigned __int64 eflags;
	__asm__ volatile("pushf\npop %0" : "=r"(eflags) : : "memory");
	return eflags;
}

void __invlpg(void* addr)
{
	__asm__ volatile("invlpg %0" : : "m"(addr) : "memory");
}

void __inbytestring(unsigned short Port, unsigned char* Buffer, unsigned long Count)
{
	__asm__ volatile("rep insb" : : "d"(Port), "D"(Buffer), "c"(Count) : "memory");
}

void __inwordstring(unsigned short Port, unsigned short* Buffer, unsigned long Count)
{
	__asm__ volatile("rep insw" : : "d"(Port), "D"(Buffer), "c"(Count) : "memory");
}

void __indwordstring(unsigned short Port, unsigned long* Buffer, unsigned long Count)
{
	__asm__ volatile("rep insl" : : "d"(Port), "D"(Buffer), "c"(Count) : "memory");
}

void __outbytestring(unsigned short Port, unsigned char* Buffer, unsigned long Count)
{
	__asm__ volatile("rep outsb" : : "d"(Port), "S"(Buffer), "c"(Count) : "memory");
}

void __outwordstring(unsigned short Port, unsigned short* Buffer, unsigned long Count)
{
	__asm__ volatile("rep outsw" : : "d"(Port), "S"(Buffer), "c"(Count) : "memory");
}

void __outdwordstring(unsigned short Port, unsigned long* Buffer, unsigned long Count)
{
	__asm__ volatile("rep outsl" : : "d"(Port), "S"(Buffer), "c"(Count) : "memory");
}

#ifdef CLANG_MISSING_INBYTE
unsigned char __inbyte(unsigned short Port)
{
	unsigned char value;
	__asm__ volatile("inb %1, %0" : "=r"(value) : "d"(Port) : "memory");
	return value;
}

void __outbyte(unsigned short Port, unsigned char Value)
{
	__asm__ volatile("outb %0, %1" : : "a"(Value), "d"(Port));
}

unsigned short __inword(unsigned short Port)
{
	unsigned short value;
	__asm__ volatile("inw %1, %0" : "=r"(value) : "d"(Port) : "memory");
	return value;
}

void __outword(unsigned short Port, unsigned short Value)
{
	__asm__ volatile("outw %0, %1" : : "a"(Value), "d"(Port));
}

unsigned long __indword(unsigned short Port)
{
	unsigned long value;
	__asm__ volatile("inl %1, %0" : "=r"(value) : "d"(Port) : "memory");
	return value;
}

void __outdword(unsigned short Port, unsigned long Value)
{
	__asm__ volatile("outl %0, %1" : : "a"(Value), "d"(Port));
}
#endif
