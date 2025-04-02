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
