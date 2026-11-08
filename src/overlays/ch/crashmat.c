#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crashmat/func_80800000_chcrashmat.s")

extern ActorData D_808000A0_chcrashmat;
ActorData* chcrashmat_entrypoint_0()
{
    return &D_808000A0_chcrashmat;
}
