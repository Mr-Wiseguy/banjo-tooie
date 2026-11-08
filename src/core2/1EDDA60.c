#include "core2/1EDDA60.h"

extern FreeList* D_80136E70;

void func_80104170(void)
{
	D_80136E70 = freelist_new(func_8008B4F4(), 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_801041A0.s")

void func_801041C8()
{
    if(D_80136E70)
    {
       D_80136E70 = freelist_defrag(D_80136E70);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_80104200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_80104248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_80104268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_801042B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_801042D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDA60/func_80104328.s")
