#include "ch/doubloon.h"

void func_80800000_chdoubloon(Actor*);
void func_8080000C_chdoubloon(Actor*);
void chdoubloon_entrypoint_0(Actor*, void*);
void chdoubloon_entrypoint_1(Actor*);
s32 func_808001D4_chdoubloon(Actor*, s32, s32);

s32 D_80800290_chdoubloon[] = {0x001B0013 ,0x06340002,0x00140016,0x6D600000};
ActorData D_808002A0_chdoubloon =
{
    /*0x0*/ 0x0134,
    /*0x2*/ PROP_4E5_DOUBLOON_REAL,
    /*0x4*/ 0x07C0,
    /*0x6*/ 0x0001,
    /*0x8*/ 0x00000000,
    /*0xC*/ func_8080000C_chdoubloon,
    /*0x10*/ func_80105834,
    /*0x14*/ _chdoubloon_entrypoint_0,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0BB8,
    /*0x1C*/ 0.0f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0000,
    /*0x26*/ 0x0004,
    /*0x28*/ 0x00000000,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0x0000,
    /*0x32*/ 0x0000,
    /*0x34*/ func_80800000_chdoubloon,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x2000,
    /*0x40*/ func_808001D4_chdoubloon,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
};

void func_80800000_chdoubloon(Actor* arg0)
{
    arg0->rotation[0] = 0.0f;
}

void func_8080000C_chdoubloon(Actor* arg0)
{
    chdoubloon_entrypoint_1(arg0);
    func_80103110(arg0, 0U);
}

void chdoubloon_entrypoint_0(Actor* arg0, void* arg1)
{
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12)
    {
        func_80103110(arg0, 1U);
    }
}

void chdoubloon_entrypoint_1(Actor* arg0)
{

    f32 sp74[3];
    s32 var_s1;
    f32 sp68[2];
    f32 sp5C[3];

    arg0->rotation[1] += ((time_getDelta() * 300.0f));
    if (arg0->unk7C_12)
    {
        func_800E3980(sp5C);
        func_800F18FC(arg0->position, sp5C, sp68);
        for (var_s1 = 0; var_s1 < 4; var_s1++)
        {
            if (rand_f() < 0.015f)
            {
                func_800EEC30(sp74, sp68[0] + rand_fBounded(-90.0f, 90.0f), sp68[1] + rand_fBounded(-90.0f, 90.0f), 30.0f);
                ml_vec3f_add(sp74, arg0->position);
                sp74[1] += 30.0f;
                _fxtwinkle_entrypoint_1(sp74, ASSET_9E2_GOLD_SPARKLE);
            }
        }
    }
}

s32 func_808001D4_chdoubloon(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {

        case EVENT_3E_ACTOR_TOUCHED:
            _sudialog_entrypoint_0(0x165, 4);
            collectable_collectItem(arg0->unk54s, 7U);
            inventory_incrementValue(0x4E);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800290_chdoubloon);
            _fxsparkle_entrypoint_1(arg0->position, 0x13U);
            actor_mark_delete(arg0);
            break;
        case 0x13:
            arg0->unk54s = arg2;
            break;
        default:
            return 0;
    }

    return 1;
}

ActorData* chdoubloon_entrypoint_2()
{
    return &D_808002A0_chdoubloon;
}
