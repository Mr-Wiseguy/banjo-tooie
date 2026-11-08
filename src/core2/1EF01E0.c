#include "core2/1EF01E0.h"

extern s32 D_8000E800;
extern s32 D_80011000;
extern s32* D_80124A80;
extern s32* D_80124A8C;

void func_801168F0(void)
{
    D_80124A8C = &D_80011000;
    D_80124A80 = &D_8000E800;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EF01E0/func_80116914.s")
