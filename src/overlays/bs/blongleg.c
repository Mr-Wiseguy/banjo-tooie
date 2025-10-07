#include "bs/blongleg.h"

s32 func_80800000_bsblongleg(PlayerState* arg0)
{
    return player_inWater(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800020_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800064_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808000C8_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_8080013C_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800204_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808002D8_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800378_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_5.s")

void bsblongleg_entrypoint_6()
{
    func_80800204_bsblongleg();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_9.s")

void bsblongleg_entrypoint_10()
{
    func_80800204_bsblongleg();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800994_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800A18_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_17.s")

void bsblongleg_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_21.s")

void bsblongleg_entrypoint_22()
{
    func_80800204_bsblongleg();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_23.s")

void bsblongleg_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(arg0);
}
void bsblongleg_entrypoint_25(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_27.s")

void bsblongleg_entrypoint_28(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsdrone_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_29.s")

void bsblongleg_entrypoint_30(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_31.s")
