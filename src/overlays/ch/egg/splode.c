#include "ch/egg/splode.h"


typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    f32 unkC;
    s32 unk10;
} EggSplodeData;

f32 func_80800548_cheggsplode(s32);
extern u32 D_808009DC_cheggsplode[3];

extern ActorData D_80800994_cheggsplode;
ActorData* cheggsplode_entrypoint_0()
{
    return &D_80800994_cheggsplode;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080000C_cheggsplode.s")

s32 func_808002A8_cheggsplode(Actor* arg0, s32 arg1, s32 arg2)
{
    EggSplodeData* sp1C;
    s32 temp_v0;

    sp1C = (EggSplodeData*)actor_getAdditionalMem(arg0, 0);
    switch (arg1)
    {
    case 0x9F:
    {
        if (func_800D3948() == 0)
        {
            sp1C->unk6 = 1;
        }
        return 1;
    }
    case EVENT_95_ACTOR_SPAWNED:
    {
        if (func_800BF8E4() > 0)
        {
            temp_v0 = func_800C8A98();
            sp1C->unk10 = temp_v0;
            func_800C8E84(temp_v0, &D_808009DC_cheggsplode);
            func_800C8CB8(sp1C->unk10, arg0->position);
        }
        return 1;
    }
    }
    return 0;

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080035C_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080041C_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_80800548_cheggsplode.s")

void cheggsplode_entrypoint_1(s32 arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;
    EggSplodeData* temp_v0_2;

    temp_v0 = func_801084B0(0x2B2, arg0);
    temp_v0_2 = (EggSplodeData*)actor_getAdditionalMem(temp_v0, 0);
    temp_v0_2->unk6 = 0;
    temp_v0_2->unk4 = arg2;
    temp_v0_2->unk0 = arg1;
    if (arg2 != 4)
    {
        if (arg2 == 6)
        {
            temp_v0->unk70_10 = 3;
            temp_v0_2->unkC = 350.0f;
        }
    }
    else
    {
        temp_v0->unk70_10 = 2;
        temp_v0_2->unkC = func_80800548_cheggsplode(arg1);
    }
}

void cheggsplode_entrypoint_2(f32 arg0[3], f32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Actor* sp1C;
    EggSplodeData* temp_v0_2;

    sp1C = func_80108474(0x2B2, arg0, arg1);
    temp_v0_2 = (EggSplodeData*)actor_getAdditionalMem(sp1C, 0);
    temp_v0_2->unk0 = arg2;
    temp_v0_2->unk4 = arg3;
    temp_v0_2->unk6 = (arg4 == 0);
    if (arg3 == 5)
    {
        sp1C->unk70_10 = 4;
        temp_v0_2->unkC = func_80800548_cheggsplode(arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_808006F0_cheggsplode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_80800778_cheggsplode.s")

s32 func_808007D4_cheggsplode(s32 arg0, s32 arg1)
{
    if (func_800F6478(arg1) == 0)
    {
        return 0;
    }
    return 1;
}
