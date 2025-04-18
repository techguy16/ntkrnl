#include "exp.h"

USHORT
ExQueryDepthSList (
    IN PSLIST_HEADER SListHead
    )
{

    return (USHORT)(SListHead->Alignment & 0xffff);
}