#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_80800000_chscreenadjust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_8080016C_chscreenadjust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_808001E0_chscreenadjust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/screenadjust/func_8080037C_chscreenadjust.s")

extern ActorData D_80800430_chscreenadjust;
ActorData* chscreenadjust_entrypoint_0()
{
    return &D_80800430_chscreenadjust;
}
