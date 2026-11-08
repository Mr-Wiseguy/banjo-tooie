#include "ch/lavaslabswitch.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/slabswitch/func_80800000_chlavaslabswitch.s")

void func_8080005C_chlavaslabswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_38F_UNK);
    _chswitch_entrypoint_9(arg0);
}

extern ActorData D_808000A0_chlavaslabswitch;
ActorData* chlavaslabswitch_entrypoint_0()
{
    return &D_808000A0_chlavaslabswitch;
}
