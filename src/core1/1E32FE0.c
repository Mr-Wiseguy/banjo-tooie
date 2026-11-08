#include "core1/1E32FE0.h"

typedef struct
{
    void* unk0;
    s32 unk4;
} UNKD_8007BF10;

extern UNKD_8007BF10 D_8007BF10[];
extern s32 D_8007C6E0;

void func_8001B4B0(void)
{
    s32 index;

    for (index = 1; index < 0xFA; index++)
    {
        D_8007BF10[index].unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E32FE0/func_8001B4E8.s")

void func_8001B50C(void)
{
    D_8007C6E0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E32FE0/func_8001B518.s")

s16 func_8001B668(s32 arg0, s32 arg1)
{
    s32 index = 1;
    while (D_8007BF10[index].unk0 != 0)
    {
        index++;
    }
    if (index < 0xFA)
    {
        D_8007BF10[index].unk0 = heap_alloc_sided(arg1, 2);
        D_8007BF10[index].unk4 = arg0;
        func_8001B3A0(D_8007BF10[index].unk0);
        return index;
    }
    return 0;
}

void func_8001B710(s16 arg0, s32 arg1)
{
    D_8007BF10[arg0].unk0 = heap_realloc(D_8007BF10[arg0].unk0, arg1);
}

void func_8001B754(s16 arg0)
{
    heap_free(D_8007BF10[arg0].unk0);
    D_8007BF10[arg0].unk0 = NULL;
}

void* func_8001B798(s16 arg0)
{
    return D_8007BF10[arg0].unk0;
}

void func_8001B7B8(s16 arg0) 
{
    heap_get_allocation_size(D_8007BF10[arg0].unk0);
}

void func_8001B7F0(s16 arg0, u8 arg1, s32 arg2)
{
    rare_memset(D_8007BF10[arg0].unk0, arg1, arg2);
}