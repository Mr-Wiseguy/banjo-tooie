#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800000_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_808000D0_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800128_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_808001D4_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800208_bscarry.s")

void func_8080027C_bscarry()
{
    func_808001D4_bscarry();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_8080029C_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800310_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/bscarry_entrypoint_0.s")

void func_808003D8_bscarry()
{
    func_808001D4_bscarry();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_808003F8_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_8080047C_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/bscarry_entrypoint_1.s")

void func_80800500_bscarry()
{
    func_808001D4_bscarry();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800520_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800594_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/bscarry_entrypoint_2.s")

void func_8080065C_bscarry(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808001D4_bscarry(arg0);
}
void func_80800684_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsdrone_entrypoint_0(arg0);
}
void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/bscarry_entrypoint_3.s")

void func_808006E0_bscarry(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808001D4_bscarry(arg0);
}
void func_80800708_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/func_80800730_bscarry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/carry/bscarry_entrypoint_4.s")
