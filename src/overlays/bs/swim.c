#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800000_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800030_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808000E0_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800178_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808001DC_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800270_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808002E0_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808004C4_bsswim.s")

void func_80800688_bsswim(s32 arg0)
{
    func_80800270_bsswim();
    func_800A4E30(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/bsswim_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808006C4_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808007F8_bsswim.s")

void func_808009F0_bsswim()
{
    func_80800270_bsswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/bsswim_entrypoint_1.s")

void func_80800A24_bsswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800270_bsswim(arg0);
}
void func_80800A4C_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800A74_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/bsswim_entrypoint_2.s")

void func_80800AC8_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsdrone_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800AF0_bsswim.s")

void func_80800B34_bsswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800270_bsswim(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/bsswim_entrypoint_3.s")
