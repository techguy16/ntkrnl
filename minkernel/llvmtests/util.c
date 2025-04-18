/*++

Copyright (c) 2025 MobSlicer152


Module Name:

	util.c

Abstract:

	This file implements things for the tests in this folder

Author:

	MobSlicer152   19-Apr-25

--*/

#include "util.h"

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