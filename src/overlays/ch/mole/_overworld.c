#include "ch/mole.h"

extern MoveData D_80800190_chmole_overworld;
extern s32 D_808001E0_chmole_overworld[];

s32 func_80800000_chmole_overworld(Actor* arg0, s32 eventId, s32 arg2)
{
    switch (eventId)
    {
    case 0x2F:
    {
        if (((s16*)&arg2)[1] == 3)
        {
            inventory_addValue(D_808001E0_chmole_overworld[(s32)arg0->unk54], func_800D1A6C(D_808001E0_chmole_overworld[(s32)arg0->unk54]) - inventory_getValue(D_808001E0_chmole_overworld[(s32)arg0->unk54]));
            break;
        }
        _sumole_entrypoint_3(arg0, eventId, (s32)arg2, &D_80800190_chmole_overworld);
        return;
    }
    default:
        _sumole_entrypoint_3(arg0, eventId, (s32)arg2, &D_80800190_chmole_overworld);
        return;
    }
    return 1;
}

void func_808000F4_chmole_overworld(Actor* arg0) 
{
    _sumole_entrypoint_0(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->unk54 = arg0->unk74_7;
}

void func_80800160_chmole_overworld(Actor* arg0) {
    _sumole_entrypoint_4(arg0, &D_80800190_chmole_overworld);
}

extern ActorData D_808001F0_chmole_overworld;
ActorData* chmole_overworld_entrypoint_0()
{
    return &D_808001F0_chmole_overworld;
}
