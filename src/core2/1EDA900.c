#include "core2/1EDA900.h"
extern void* D_80135A80;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_8010105C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101074.s")

void* func_80101080()
{
    return D_80135A80;
}

s32 func_8010108C(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 pad;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    if (arg0->unk74_28)
    {
        sp20 = func_80081D34(arg0->pointerToSyscallEntry);
        if (sp20 != 0)
        {
            sp24 = func_80081D80(sp20);
        }
        else
        {
            sp24 = 0;
        }
        sp28 = (func_80100368(arg0))->unk40(arg0, arg1, arg2);
        if ((sp20 != 0) && (sp24 == 0) && (sp28 <= 0))
        {
            func_800819B4(arg0->pointerToSyscallEntry);
        }
        return sp28;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_8010114C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801012D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801013A8.s")
