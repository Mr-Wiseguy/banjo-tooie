#include "core2/1EE06E0.h"

extern FreeList* D_80136F00;

void func_80106DF0(void) {
	D_80136F00 = freelist_new(0x18, 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106E18.s")

void func_80106E50()
{
    if(D_80136F00)
    {
       D_80136F00 = freelist_defrag(D_80136F00);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801072A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801072E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801073AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801073F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_8010754C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801075E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801078AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801078DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107C00.s")
