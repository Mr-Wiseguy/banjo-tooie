#include "core2/1EBE020.h"

extern s32 D_8012D560[];
extern void* D_8012D570;
extern u8 D_801275E0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E47CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E488C.s")

s32 func_800E4AF0(void)
{
    if (func_800E4730() < 0)
    {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4B1C.s")

s32 func_800E4BB8(void)
{
    s32 temp_v0;

    temp_v0 = func_800E4730();
    if (temp_v0 < 0)
    {
        return 0;
    }
    func_800E4B1C(temp_v0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4BF4.s")

void func_800E4C7C(void)
{
    s32 index;
    s32 var_s0;

    var_s0 = &D_8012D560;
    for (index = 0; index < 4; index++)
    {
        var_s0 = D_8012D560[index];
        if (var_s0 != NULL)
        {
            D_8012D560[index] = defrag(var_s0);
        }
    }
    D_8012D570 = defrag(D_8012D570);
}

void func_800E4CE8(void)
{
    s32 var_s0;
    for (var_s0 = 0; var_s0 < 4; var_s0++)
    {
        func_800E4B1C(var_s0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E4E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E5EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E659C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6728.s")

void func_800E692C(void) {
    D_8012D570 = heap_alloc(0x40);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBE020/func_800E6950.s")

s32 func_800E6A00(void) {
    return D_801275E0;
}