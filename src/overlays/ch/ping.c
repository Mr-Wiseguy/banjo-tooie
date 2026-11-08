#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_80800000_chping.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/func_808001B8_chping.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ping/chping_entrypoint_0.s")

extern ActorData D_80800410_chping;
ActorData* chping_entrypoint_1()
{
    return &D_80800410_chping;
}
