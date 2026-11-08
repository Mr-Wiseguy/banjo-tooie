#include "ch/flysaucerdoor.h"

extern ActorData D_80800160_chflysaucerdoor;
ActorData* chflysaucerdoor_entrypoint_0()
{
    return &D_80800160_chflysaucerdoor;
}
extern ActorData D_808001A8_chflysaucerdoor;
ActorData* chflysaucerdoor_entrypoint_1()
{
    return &D_808001A8_chflysaucerdoor;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucerdoor/func_80800018_chflysaucerdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucerdoor/func_8080006C_chflysaucerdoor.s")

void func_80800140_chflysaucerdoor(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG0_008_UNK);
}

