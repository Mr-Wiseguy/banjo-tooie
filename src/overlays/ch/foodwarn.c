#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_80800000_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_8080003C_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_80800074_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808000D4_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808001F4_chfoodwarn.s")

extern ActorData D_808002A8_chfoodwarn;
ActorData* chfoodwarn_entrypoint_0()
{
    return &D_808002A8_chfoodwarn;
}
