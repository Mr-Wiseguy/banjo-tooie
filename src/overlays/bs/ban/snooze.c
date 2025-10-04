#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800000_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800098_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800128_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_8080019C_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808001FC_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800278_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_0.s")

void func_8080037C_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_8080039C_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800414_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_1.s")

void func_808004C0_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808004E0_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800588_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_2.s")

void func_8080064C_bsbansnooze(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800000_bsbansnooze(arg0);
}
void func_80800674_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
    _bsdrone_entrypoint_0(arg0);
}
void func_8080069C_bsbansnooze(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_3.s")

void func_808006D0_bsbansnooze(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsbansnooze(arg0);
}
void func_808006F8_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800720_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_4.s")

void func_8080076C_bsbansnooze(s32 arg0)
{
    func_800951B4();
    func_80800000_bsbansnooze(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_80800794_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/func_808008A4_bsbansnooze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/snooze/bsbansnooze_entrypoint_5.s")
