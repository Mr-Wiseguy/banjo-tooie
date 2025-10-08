#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800000_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800074_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800100_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800164_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080021C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808002AC_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080030C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_8080037C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_0.s")

void func_80800430_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800450_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808004AC_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808005DC_bsbanshack.s")

void func_80800744_bsbanshack(s32 arg0)
{
    func_808005DC_bsbanshack(arg0,0);
    func_80800164_bsbanshack(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800770_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808007A0_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_2.s")

void func_80800928_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800948_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_808009E4_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_3.s")

void func_80800AD0_bsbanshack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800164_bsbanshack(arg0);
}
void func_80800AF8_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800B20_bsbanshack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_4.s")

void func_80800B54_bsbanshack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800164_bsbanshack(arg0);
}
void func_80800B7C_bsbanshack(s32 arg0)
{
    func_8080021C_bsbanshack();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800BA4_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_5.s")

void func_80800BF0_bsbanshack()
{
    func_80800164_bsbanshack();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800C10_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/func_80800C6C_bsbanshack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/shack/bsbanshack_entrypoint_6.s")
