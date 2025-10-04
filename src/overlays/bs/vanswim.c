#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800000_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808000B0_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800114_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800174_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808001CC_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_80800200_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808002D0_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/bsvanswim_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080042C_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080049C_bsvanswim.s")

void func_808005E8_bsvanswim()
{
    func_80800174_bsvanswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/bsvanswim_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080061C_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_808006D0_bsvanswim.s")

void func_80800808_bsvanswim()
{
    func_80800174_bsvanswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/bsvanswim_entrypoint_2.s")

void func_8080083C_bsvanswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bsvanswim(arg0);
}
void func_80800864_bsvanswim(s32 arg0)
{
    func_80800114_bsvanswim();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/func_8080088C_bsvanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/bsvanswim_entrypoint_3.s")

void func_808008E4_bsvanswim(s32 arg0)
{
    func_80800114_bsvanswim();
    _bsdrone_entrypoint_0(arg0);
}
void func_8080090C_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bsvan_entrypoint_3(arg0);
}
void func_80800934_bsvanswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bsvanswim(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/vanswim/bsvanswim_entrypoint_4.s")
