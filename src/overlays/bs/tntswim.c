#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800000_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808000B0_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800114_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800174_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808001CC_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800200_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808002D0_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/bstntswim_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_8080042C_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_8080049C_bstntswim.s")

void func_808005FC_bstntswim()
{
    func_80800174_bstntswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/bstntswim_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_80800630_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808006E4_bstntswim.s")

void func_80800830_bstntswim()
{
    func_80800174_bstntswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/bstntswim_entrypoint_2.s")

void func_80800864_bstntswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bstntswim(arg0);
}
void func_8080088C_bstntswim(s32 arg0)
{
    func_80800114_bstntswim();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/func_808008B4_bstntswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/bstntswim_entrypoint_3.s")

void func_8080090C_bstntswim(s32 arg0)
{
    func_80800114_bstntswim();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800934_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bstnt_entrypoint_4(arg0);
}
void func_8080095C_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bstntswim(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tntswim/bstntswim_entrypoint_4.s")
