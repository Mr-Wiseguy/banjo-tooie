#include "ch/lavatraindoorswitch.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/traindoorswitch/func_80800000_chlavatraindoorswitch.s")

void func_8080003C_chlavatraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D0_STATION_UNLOCKED_HFPL);
    _chswitch_entrypoint_9(arg0);
}

extern ActorData D_80800080_chlavatraindoorswitch;
ActorData* chlavatraindoorswitch_entrypoint_0()
{
    return &D_80800080_chlavatraindoorswitch;
}
