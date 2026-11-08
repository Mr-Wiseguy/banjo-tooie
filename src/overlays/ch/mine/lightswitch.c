#include "ch/minelightswitch.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/lightswitch/func_80800000_chminelightswitch.s")

void func_80800094_chminelightswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_9E0_UNK);
}

extern ActorData D_808000C0_chminelightswitch;
ActorData* chminelightswitch_entrypoint_0()
{
    return &D_808000C0_chminelightswitch;
}
