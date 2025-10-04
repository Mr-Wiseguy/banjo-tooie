#include "overlays/ba/physics.h"

s32 func_8009AD70() 
{
    return 0xF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009AD78.s")

void func_8009AD88(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009AD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009ADF0.s")

s32 func_8009AE00() 
{
    return 0xC4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009AE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B27C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B3B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B7C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_type.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_target_horizontal_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_target_yaw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009B9F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_vertical_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_horizontal_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BAE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_get_target_horizontal_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_get_vertical_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BC08.s")

void func_8009BC34(PlayerState* arg0)
{
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_reset_gravity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_reset_terminal_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_gravity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/baphysics_set_terminal_velocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/baphysics/func_8009BD18.s")
