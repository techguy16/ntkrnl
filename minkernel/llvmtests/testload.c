/*++

Copyright (c) 2025 MobSlicer152


Module Name:

	intrin.c

Abstract:

	This file implements a program that checks if the kernel, hal, kdcom, and
	 bootvid can load (only checks imports for now)

	This program isn't great, it should be cleaned up

Author:

	MobSlicer152   18-Apr-25

--*/

#ifdef _M_AMD64
#define _AMD64_ 1
#endif

#include <nt.h>
#include <ntrtl.h>
#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

NTSTATUS LoadImage(PCWSTR path, PCWSTR name, PVOID* base)
{
	if (!path || !name || !base)
	{
		return STATUS_INVALID_PARAMETER;
	}

	*base = NULL;

	wprintf(L"loading file %s\\%s\n", path, name);

	UNICODE_STRING nameStr = {0};
	RtlInitUnicodeString(&nameStr, name);

	// this makes it skip imports
	ULONG characteristics = IMAGE_FILE_EXECUTABLE_IMAGE;
	return LdrLoadDll(path, &characteristics, &nameStr, base);
}

#define LOAD_IMAGE(name)                                                                                                         \
	PVOID name##Base = NULL;                                                                                                     \
	status = LoadImage(system32, L#name, &name##Base);                                                                           \
	if (!NT_SUCCESS(status))                                                                                                     \
	{                                                                                                                            \
		wprintf(L"failed to load " L#name L": NTSTATUS 0x%08X\n", status);                                                       \
		NtTerminateProcess(NtCurrentProcess(), status);                                                                          \
	}

typedef struct _DLLINFO
{
	PCSTR name;
	union {
		PVOID base;
		PIMAGE_DOS_HEADER dosHdr;
	};
	PIMAGE_NT_HEADERS ntHdrs;
	PIMAGE_IMPORT_DESCRIPTOR idt;
	ULONG idtSize;
} DLLINFO, *PDLLINFO;

NTSTATUS ParseHeaders(PDLLINFO dllInfo)
{
	if (!dllInfo || !dllInfo->base)
	{
		return STATUS_INVALID_PARAMETER;
	}

	NTSTATUS status = RtlImageNtHeaderEx(RTL_IMAGE_NT_HEADER_EX_FLAG_NO_RANGE_CHECK, dllInfo->base, 0, &dllInfo->ntHdrs);
	if (!NT_SUCCESS(status))
	{
		wprintf(L"failed to get NT header in %hs 0x%016llX: NTSTATUS 0x%08X\n", dllInfo->name, dllInfo->base, status);
		return status;
	}

	dllInfo->idt = RtlImageDirectoryEntryToData(dllInfo->base, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &dllInfo->idtSize);

	return STATUS_SUCCESS;
}

PVOID RvaToVa(PDLLINFO dll, ULONG rva)
{
	return (PVOID)((ULONG_PTR)dll->base + rva);
}

#ifdef _WIN64
#define IMPORT_LOOKUP_IS_ORDINAL 0x8000000000000000
#else
#define IMPORT_LOOKUP_IS_ORDINAL 0x80000000
#endif

NTSTATUS CheckImport(PCSTR name, UINT16 ordinal, PCSTR dllName, PVOID dll)
{
	printf("Checking if %s/%hu exists in %s\n", name, ordinal, dllName);

    ANSI_STRING procName = {0};
    RtlInitAnsiString(&procName, name);

    PVOID proc = NULL;
    NTSTATUS status = LdrGetProcedureAddress(dll, name ? &procName : NULL, ordinal, &proc);
    if (!NT_SUCCESS(status))
    {
        printf("failed to get procedure address: NTSTATUS 0x%08X\n", status);
        return status;
    }

    printf("%s/%hu found in %s\n", name, ordinal, dllName);

    return STATUS_SUCCESS;
}

NTSTATUS CheckOneDll(PDLLINFO dll, PIMAGE_IMPORT_DESCRIPTOR import, PUINT32 missingCount)
{
	if (!dll || !import || import->Name == 0 || !missingCount)
	{
		return STATUS_INVALID_PARAMETER;
	}

	PCSTR dllName = RvaToVa(dll, import->Name);
	if (_strnicmp(dllName, "ntoskrnl", 8) == 0)
	{
	    // LdrLoadDll only likes things with .dll at the end,
	    // but things import it as ntoskrnl.exe, so fix that
		dllName = "ntoskrnl.dll";
	}

    ANSI_STRING nameStr = {0};
    RtlInitAnsiString(&nameStr, dllName);
    UNICODE_STRING nameUStr = {0};
    RtlAnsiStringToUnicodeString(&nameUStr, &nameStr, TRUE);

    PVOID dllBase = NULL;

    NTSTATUS status = LdrGetDllHandle(NULL, NULL, &nameUStr, &dllBase);
	if (!NT_SUCCESS(status))
	{
		printf("failed to get module handle for %s: NTSTATUS 0x%08X\n", dllName, status);
		return status;
	}

	printf("checking what %s imports from %s\n", dll->name, dllName);

	*missingCount = 0;

	PUINT64 ilt = RvaToVa(dll, import->OriginalFirstThunk);
	for (SIZE_T i = 0; ilt[i] != 0; i++)
	{
        if (ilt[i] & IMPORT_LOOKUP_IS_ORDINAL)
        {
            UINT16 ordinal = ilt[i] & 0xFFFF; // 16 bits
            status = CheckImport(NULL, ordinal, dllName, dllBase);
        }
        else
        {
            UINT32 rva = ilt[i] & 0x7FFFFFFF; // 31 bits
            PIMAGE_IMPORT_BY_NAME name = RvaToVa(dll, rva);
            status = CheckImport((PCSTR)name->Name, 0, dllName, dllBase);
        }

		if (!NT_SUCCESS(status))
		{
			(*missingCount)++;
		}
	}

	printf("%u imports by %s missing from %s\n", *missingCount, dll->name, dllName);

    if (NT_SUCCESS(status))
    {
        RtlFreeUnicodeString(&nameUStr);
    }

	return STATUS_SUCCESS;
}

NTSTATUS CheckImports(PDLLINFO dlls, SIZE_T dllCount)
{
	// parse all the headers
	for (SIZE_T i = 0; i < dllCount; i++)
	{
		ParseHeaders(&dlls[i]);
	}

	UINT32 totalErrors = 0;
	for (SIZE_T i = 0; i < dllCount; i++)
	{
		PCSTR name = dlls[i].name;
		PIMAGE_NT_HEADERS hdr = dlls[i].ntHdrs;
		PIMAGE_IMPORT_DESCRIPTOR idt = dlls[i].idt;

		// ends with a NUL entry
		UINT32 dllsMissing = 0;
		for (SIZE_T j = 0; j < (dlls[i].idtSize / sizeof(IMAGE_IMPORT_DESCRIPTOR)) - 1; j++)
		{
			UINT32 missing = 0;
			NTSTATUS status = CheckOneDll(&dlls[i], &idt[j], &missing);
			if (!NT_SUCCESS(status))
			{
				dllsMissing++;
				return status;
			}

			totalErrors += missing;
		}

		totalErrors += dllsMissing;
	}

	printf("total of %u errors\n", totalErrors);

	return STATUS_SUCCESS;
}

int wmain(int argc, wchar_t* argv[])
{
	if (argc < 2)
	{
		wprintf(L"usage: %s <system32 directory>\n", argv[0]);
		return STATUS_INVALID_PARAMETER;
	}

	PCWSTR system32 = argv[1];

	wchar_t ntoskrnlPath[261] = {0};
	_snwprintf(ntoskrnlPath, ARRAY_SIZE(ntoskrnlPath), L"\\??\\%s\\ntoskrnl.dll", system32);
	wchar_t halPath[261] = {0};
	_snwprintf(halPath, ARRAY_SIZE(halPath), L"\\??\\%s\\hal.dll", system32);
	wchar_t kdcomPath[261] = {0};
	_snwprintf(kdcomPath, ARRAY_SIZE(kdcomPath), L"\\??\\%s\\kdcom.dll", system32);
	wchar_t bootvidPath[261] = {0};
	_snwprintf(bootvidPath, ARRAY_SIZE(bootvidPath), L"\\??\\%s\\bootvid.dll", system32);

	wprintf(L"checking these binaries:\n");
	wprintf(L"\tntoskrnl: %s\n", ntoskrnlPath);
	wprintf(L"\thal: %s\n", halPath);
	wprintf(L"\tkdcom: %s\n", kdcomPath);
	wprintf(L"\tbootvid: %s\n", bootvidPath);
	wprintf(L"\n");

	NTSTATUS status;
	LOAD_IMAGE(ntoskrnl);
	LOAD_IMAGE(hal);
	LOAD_IMAGE(kdcom);
	LOAD_IMAGE(bootvid);

	DLLINFO dlls[] = {
		{"ntoskrnl.dll", {ntoskrnlBase}},
        {     "hal.dll",      {halBase}},
        {   "kdcom.dll",    {kdcomBase}},
        { "bootvid.dll",  {bootvidBase}}
    };

	return CheckImports(dlls, ARRAY_SIZE(dlls));
}
