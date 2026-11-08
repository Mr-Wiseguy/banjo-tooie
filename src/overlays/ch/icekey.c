#include "ch/icekey.h"

extern s32 D_808000A0_chicekey;
extern ActorData D_808000EC_chicekey;

s32 func_80800000_chicekey(Actor* arg0, s32 arg1, s32 arg2)
{

    if (arg1 == 0x3E)
    {
        func_800BBCB8(arg0->position, arg0->position, 1.0f, 0x14, &D_808000A0_chicekey);
        inventory_incrementValue(0x53);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1550U, 4U, arg0->position, 0x6FU);
        func_800FC660(0xE);
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

ActorData* chicekey_entrypoint_0()
{
    return &D_808000EC_chicekey;
}
