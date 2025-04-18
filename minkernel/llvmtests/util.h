/*++

Copyright (c) 2025 MobSlicer152


Module Name:

	util.h

Abstract:

	This file declares some stuff for the tests in this folder

Author:

	MobSlicer152   19-Apr-25

--*/

#pragma once

#ifdef _M_AMD64
#define _AMD64_ 1
#endif

#include <nt.h>
#include <ntrtl.h>
#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

extern NTSTATUS LoadImage(PCWSTR path, PCWSTR name, PVOID* base);

#define LOAD_IMAGE(name, ext)                                                                                                    \
	PVOID name##Base = NULL;                                                                                                     \
	status = LoadImage(system32, L#name ext, &name##Base);                                                                       \
	if (!NT_SUCCESS(status))                                                                                                     \
	{                                                                                                                            \
		wprintf(L"failed to load " L#name L": NTSTATUS 0x%08X\n", status);                                                       \
		NtTerminateProcess(NtCurrentProcess(), status);                                                                          \
	}

#define LOAD_DRIVER(name)                                                                                                        \
	PVOID name##Base = NULL;                                                                                                     \
	status = LoadImage(drivers, L#name L".sys", &name##Base);                                                                    \
	if (!NT_SUCCESS(status))                                                                                                     \
	{                                                                                                                            \
		wprintf(L"failed to load " L#name L": NTSTATUS 0x%08X\n", status);                                                       \
		NtTerminateProcess(NtCurrentProcess(), status);                                                                          \
	}
