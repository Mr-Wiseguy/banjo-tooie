#include "ch/nests.h"

typedef struct {
    s16 unk0;
    s16 abilityId;
    s16 unk4;
    s16 unk6;
    s16 firstTimeFlag;
    u8 inventoryId;
    u8 itemAmount;
    u8 unkC;
}D_80801118_chnestsUnk;

typedef struct
{
    s32 unk0[6];
    u8 unk18;
    u8 unk19;
    u16 unk1A_5 : 11;
    u16 unk1A_0 : 5;
}UnkArg2ChNest;

s32 D_808010F0_chnests[] = { 0,0,0x40000000,0x01140401,0x3f1c28f6,0x01cb0d01,0x3f800000,0x01cc0c01,0x0,0x0 };

void func_80800000_chnests(Actor*);
void func_80800098_chnests(Actor*);
void func_808002E0_chnests(Actor*);
void func_808003AC_chnests(Actor*);
s32 func_808003F4_chnests(Actor*, s32, s32);
void func_80800670_chnests(Actor* arg0, UnkArg2ChNest* arg1);
void func_808006C4_chnests(Actor*);
void func_808007C8_chnests(Actor*);
void func_8080082C_chnests(Actor*, s32);
s32 func_80800898_chnests(Actor*, s32, f32);
void func_8080093C_chnests(Actor*, s32);
void func_80800960_chnests(s32);
void func_80800968_chnests(Actor*, s32);
void func_808009D4_chnests(s32, s32);
void func_808009F8_chnests(s32);
void func_80800A00_chnests(Actor*, s32);
void func_80800A6C_chnests(s32);
void func_80800B80_chnests(Actor*);
void func_80800BD8_chnests(Actor*, s32, f32, f32);
void func_80800C3C_chnests(Actor*);
void func_80800D8C_chnests(Actor*, s32);
void func_80800ED8_chnests(Actor*);
void func_80800F08_chnests(Actor*);

D_80801118_chnestsUnk D_80801118_chnests[]={ 
    {0x01CE,ABILITY_31_EGGS_BLUE,0x0003,0x0004,FLAG_02B_FTT_ITEM_EGG,0x40,20,0x02},
    {0x01CF,ABILITY_2C_EGGS_FIRE,0x0004,0x006A,0x0000,0x41,10,0x01},
    {0x01D1,ABILITY_2D_EGGS_GRENADE,0x000C,0x006C,0x0000,0x43,10,0x05},
    {0x01D0,ABILITY_2F_EGGS_ICE,0x0003,0x006B,0x0000,0x42,10,0x03},
    {0x01D2,ABILITY_2E_EGGS_CLOCKWORK,0x0004,0x0069,0x0000,0x44,1,0x07},
    {0xFFFF,0x0000,0x0000,0x0000,0x0000,0x0,0x0,0x0},
    {0x01D5,0x0000,0x0004,0x0003,FLAG_02C_FTT_ITEM_FEATHER_RED,0x46,20,0x02},
    {0x01D6,0x0000,0x0005,0x0006,FLAG_02D_FTT_ITEM_FEATHER_GOLD,0x47,2,0x01},
    {0xFFFF,0x0000,0x0000,0x0000,0x0000,0x0,0x0,0x0},
    {0xFFFE,0x0000,0x0000,0x0000,0x0000,0x0,0x0,0x0},
    {0x01D4,0x0000,0x0005,0x0004,0x0000,0x0,0x0,0x04},
    {0x01D3,0x0000,0x0003,0x0078,0x0000,0x45,0x05,0x08},
    {0x01D9,0x0000,0x0005,0x0001,FLAG_029_FTT_ITEM_NOTE,0x00,5,0x00},
    {0x01DA,0x0000,0x0005,0x0014,FLAG_02E_FTT_ITEM_TREBLE_CLEF,0x00,20,0x00}
};
s16 D_808011DC_chnests[][2] = { {0xA,0xF},{0x14,0x1E},{0x2D,0x3C} };

ActorData D_808011E8_chnests =
{
    /*0x0*/ 0x1CE,
    /*0x2*/ PROP_1C8_NEST_BLUE_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0
};

ActorData D_80801230_chnests =
{
    /*0x0*/ 0x1CF,
    /*0x2*/ PROP_1C9_NEST_FIRE_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801278_chnests =
{
    /*0x0*/ 0x1D0,
    /*0x2*/ PROP_1CA_NEST_ICE_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_808012C0_chnests =
{
    /*0x0*/ 0x1D1,
    /*0x2*/ PROP_1CB_NEST_GRENADE_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801308_chnests =
{
    /*0x0*/ 0x1D2,
    /*0x2*/ PROP_1CC_NEST_CLOCKWORK_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801350_chnests =
{
    /*0x0*/ 0x1D4,
    /*0x2*/ PROP_1CD_NEST_GOLD_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800098_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801398_chnests =
{
    /*0x0*/ 0x1D3,
    /*0x2*/ PROP_2B8_NEST_PROXIMITY_EGGS,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800968_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800960_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_808013E0_chnests =
{
    /*0x0*/ 0x1D5,
    /*0x2*/ PROP_1CE_NEST_RED_FEATHERS,
    /*0x4*/ 0x6EF,
    /*0x6*/ 0x3,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800A00_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_808009F8_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801428_chnests =
{
    /*0x0*/ 0x1D6,
    /*0x2*/ PROP_1CF_NEST_GOLD_FEATHERS,
    /*0x4*/ 0x6EF,
    /*0x6*/ 0x3,
    /*0x8*/ 0,
    /*0xC*/ func_808003AC_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800A00_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0000,
    /*0x28*/ func_808009F8_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800000_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3410,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_80801470_chnests =
{
    /*0x0*/ 0x1D9,
    /*0x2*/ PROP_1D7_NOTE,
    /*0x4*/ 0x6EC,
    /*0x6*/ 0x2,
    /*0x8*/ 0,
    /*0xC*/ func_808007C8_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_8080082C_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0000,
    /*0x28*/ 0x0,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_808006C4_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3450,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

ActorData D_808014B8_chnests =
{
    /*0x0*/ 0x1DA,
    /*0x2*/ PROP_1D8_TREBLE_CLEF,
    /*0x4*/ 0x6ED,
    /*0x6*/ 0x2,
    /*0x8*/ 0,
    /*0xC*/ func_808007C8_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_8080082C_chnests,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0000,
    /*0x28*/ 0x0,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_808006C4_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8400,
    /*0x3E*/ 0x3450,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};
ActorData D_80801500_chnests =
{
    /*0x0*/ 0x1C5,
    /*0x2*/ PROP_1E9_EGGNEST,
    /*0x4*/ 0x6EA,
    /*0x6*/ 0x1,
    /*0x8*/ 0,
    /*0xC*/ func_80800C3C_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800D8C_chnests,
    /*0x18*/ 0x01F4,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800A6C_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800ED8_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x7010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};
ActorData D_80801548_chnests =
{
    /*0x0*/ 0x1C6,
    /*0x2*/ PROP_4A6_FEATHERNEST,
    /*0x4*/ 0x6EF,
    /*0x6*/ 0x3,
    /*0x8*/ 0,
    /*0xC*/ func_80800C3C_chnests,
    /*0x10*/ func_80102EC0,
    /*0x14*/ func_80800D8C_chnests,
    /*0x18*/ 0x01F4,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 0x00000000,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x4000,
    /*0x26*/ 0x0080,
    /*0x28*/ func_80800A6C_chnests,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0,
    /*0x32*/ 0,
    /*0x34*/ func_80800F08_chnests,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x7010,
    /*0x40*/ func_808003F4_chnests,
    /*0x44*/ 0,
    /*0x46*/ 0,
};

extern u8 D_8012762C;



void func_80800000_chnests(Actor* arg0)
{
    s32 var_v1;
    s32 temp_v0;

    temp_v0 = 0xe;

    for (var_v1 = 0; var_v1 < temp_v0; var_v1++)
    {
        if (arg0->unk0->unk24_22 == D_80801118_chnests[var_v1].unk0)
        {
            break;
        }
    }

    if (var_v1 == 0xE)
    {
        actor_mark_delete(arg0);
        return;
    }
    arg0->actorData[1] = (u32)var_v1;
    arg0->actorData[3] = _subaddiesect_entrypoint_1(arg0);
    if (arg0->actorData[3] != -1U)
    {
        _subaddiesect_entrypoint_2(arg0, (s32)arg0->actorData[3], 0);
    }
}

void func_80800098_chnests(Actor* arg0)
{
    func_80800000_chnests(arg0);
    if ((func_800D3948() == 0) && (func_800F7150(character_getActiveIndex()) != 0))
    {
        func_808002E0_chnests(arg0);
    }
}

void func_808000E8_chnests(Actor* arg0)
{
    D_80801118_chnestsUnk* sp1C;
    sp1C = &D_80801118_chnests[arg0->actorData[1]];
    if (sp1C->firstTimeFlag != 0)
    {
        if (flag_getValue((enum flag_e)sp1C->firstTimeFlag) == 0)
        {
            _sudialog_entrypoint_0(sp1C->firstTimeFlag, 0);
        }
    }
}

void func_80800144_chnests(Actor* arg0, UnkArg2ChNest* arg1) // some struct that has a unk1A...
{
    D_80801118_chnestsUnk* var_v1;
    s32 temp;
    var_v1 = &D_80801118_chnests[arg0->actorData[1]];
    temp = var_v1->unk4;
    if (temp != 0)
    {
        _fxsparkle_entrypoint_1(arg0->position, var_v1->unk4);
    }
    if (var_v1->unk6 != 0)
    {
        func_800FC660(var_v1->unk6);
    }
    if (var_v1->inventoryId != 0)
    {
        if ((_gleeprom_entrypoint_0() >> 0x18) == 0x10)
        {
            func_800F7664((u32)arg1->unk1A_5, var_v1->inventoryId, var_v1->itemAmount);
        }
    }
}

void func_808001F0_chnests(Actor* arg0, UnkArg2ChNest* arg1)
{
    Unk80132ED0* sp24;
    s32 temp_v1;
    s16* temp_v0;

    sp24 = arg0->unk0;
    temp_v1 = (arg0->unk74_7) - 0x32;
    func_80800144_chnests(arg0,arg1);
    func_808000E8_chnests(arg0);
    switch (temp_v1)
    {
    case 1:
    case 2:
    case 3:
        temp_v0 = D_808011DC_chnests[temp_v1 - 1];
        arg0->unk58 = rand_fBounded((f32)temp_v0[0], (f32)temp_v0[1]);
        arg0->unk64_16 = 0;
        actor_disableCollision(arg0);
        func_80103110(arg0, 1U);
        _subaddieDll_entrypoint_4(arg0, 1U);
        arg0->actorData[0] = arg0->unk70_10;
        func_80101FDC(arg0, 4U);
        func_80800B80_chnests(arg0);
        break;
    default:
        func_800FFA88(sp24);
        return;
    }

}

void func_808002E0_chnests(Actor* arg0)
{
    arg0->unk64_16 = 0;
    actor_disableCollision(arg0);
    arg0->actorData[0] = arg0->unk70_10;
    func_80101FDC(arg0, 4U);
}

void func_80800324_chnests(Actor* arg0, UnkArg2ChNest* arg1)
{
    func_80800144_chnests(arg0,arg1);
    func_808002E0_chnests(arg0);
}
void func_8080034C_chnests(Actor* arg0)
{
    _subaddiefade_entrypoint_2(arg0);
    func_80103110(arg0, 0U);
    _subaddieDll_entrypoint_4(arg0, 0U);
    actor_enableCollision(arg0);
    arg0->unk64_16 = 1;
    func_80101FDC(arg0, arg0->actorData[0]);
}

//Update for single type egg/feather nests
void func_808003AC_chnests(Actor* arg0)
{
    if (((arg0->unk70_10) == 4) && (timer_reachedZero(&arg0->unk58) != 0))
    {
        func_8080034C_chnests(arg0);
    }
}

//Event Handler
s32 func_808003F4_chnests(Actor* arg0, s32 eventType, s32 arg2)
{
    switch (eventType)
    {
        case EVENT_3E_ACTOR_TOUCHED:
        {
            UnkArg2ChNest* temp2 = arg2;    // = arg2;
            // FAKE to force saving arg2 / temp2 on stack
            if (&arg2);

            if (func_800F4B4C(temp2->unk1A_5) == 0)
            {
                return 0;
            }
            switch (arg0->unk0->unk24_22)
            {
            case 0x1D9:
            case 0x1DA:
                func_80800670_chnests(arg0, temp2);
                break;
            case 0x1D4:
                func_800F7C0C(temp2->unk1A_5, 0x5F, arg0->rotation[1]);
                if (arg0->unk74_7 == 0x32)
                {
                    func_808001F0_chnests(arg0, temp2);
                }
                else
                {
                    func_80800324_chnests(arg0, temp2);
                }
                break;

            default:
                func_808001F0_chnests(arg0, temp2);
                break;
            }
            return 1;
        }
        case EVENT_1F_ACTOR_ONSCREEN:
            if (func_80801014_chnests(arg0) != 0)
            {
                func_8080093C_chnests(arg0, arg2);
            }
            else if (func_808010A0_chnests(arg0) != 0)
            {
                func_808009D4_chnests(arg0, arg2);
            }
            break;
        case EVENT_95_ACTOR_SPAWNED:
		    if ((arg0->unk6C_9 != PROP_1E9_EGGNEST) && (arg0->unk6C_9 != PROP_4A6_FEATHERNEST))
		    {
                func_80103110(arg0, 0U);
            }
            func_80109EEC(arg0, 0x44);
            break;
        case 0x29:
            if (func_80801014_chnests(arg0) != 0)
            {
                func_8010DC50(0);
            }
            else if (func_808010A0_chnests(arg0) != 0)
            {
                func_8010DC50(1);
            }
            break;
        case 0x2A:
            if (func_80801014_chnests(arg0) != 0)
            {
                func_8010DCB4(0);
            }
            else if (func_808010A0_chnests(arg0) != 0)
            {
                func_8010DCB4(1);
            }
            break;
        case 0x76:
            func_8080034C_chnests(arg0);
            func_80101FDC(arg0, 1U);
            break;
        default:
            return 0;
    }

    return 1;
}

void func_80800670_chnests(Actor* arg0, UnkArg2ChNest* arg1)
{
    func_80800144_chnests(arg0,arg1);
    func_808000E8_chnests(arg0);
    if ((_gleeprom_entrypoint_0() >> 0x18) == 0x10)
    {
        collectable_collectItem((s32)arg0->actorData[2], 6U);
    }
    actor_mark_delete(arg0);
}

void func_808006C4_chnests(Actor* arg0)
{
    f32 sp20;
    f32 var_f2;
    s32 temp_v0;
    u32 temp_a0;

    temp_v0 = (arg0->unk74_7) - 0x32;
    if ((temp_v0 <= 0) || (temp_v0 >= 0x12))
    {
        actor_mark_delete(arg0);
        return;
    }
    temp_a0 = (func_800D13E8(6, D_8012762C) + (arg0->unk74_7)) - 0x32;
    arg0->actorData[2] = temp_a0;
    if (collectable_isCollected(temp_a0, 6U) != 0)
    {
        actor_mark_delete(arg0);
        return;
    }
    func_80800000_chnests(arg0);
    ((f32*)arg0->actorData)[4] = arg0->rotation[1];
    if (rand_percentChance(0.5f) != 0)
    {
        var_f2 = -1.0f;
    }
    else
    {
        var_f2 = 1.0f;
    }
    sp20 = var_f2;
    ((f32*)arg0->actorData)[5] = (rand_fBounded(540.0f, 630.0f) * var_f2);
    arg0->rotation[1] = rand_fBounded(0.0f, 360.0f);
}

//Update Note Nests
void func_808007C8_chnests(Actor* arg0)
{
    if ((arg0->unk70_10 == 2) && (arg0->unk74_27))
    {
        arg0->rotation[1] += ((f32*)arg0->actorData)[5] * time_getDelta();
        func_80103110(arg0, 0U);
    }
}

void func_8080082C_chnests(Actor* arg0, s32 arg1)
{
    if (func_80800898_chnests(arg0, arg1, ((f32*)arg0->actorData)[4]) != 0)
    {
        func_80101870(arg0, arg1);
        if ((arg0->unk7C_12) && ((arg0->unk70_10) == 2))
        {
            func_80103110(arg0, 1U);
        }
    }
}

s32 func_80800898_chnests(Actor* arg0, s32 arg1, f32 arg2)
{
    f32 sp34[3];
    ImageStruct* sp30;

    sp30 = asset_load(ASSET_85C_MODEL_ITEM_NEST);
    func_80101970(arg0);
    func_80106A98(arg0, sp30);
    func_800DF830(1);
    func_800DF410(_subaddiefade_entrypoint_0(arg0));
    ml_vec3f_assign_value(sp34, 0.0f, arg2, 0.0f);
    return func_800DE448(arg0->position, sp34, arg0->scale, func_801018D8(arg0), (s32)sp30);
}

void func_8080093C_chnests(Actor* arg0, s32 arg1)
{
    func_8010DD20(arg0, 0, arg1);
}

void func_80800960_chnests(s32 arg0) 
{
}

void func_80800968_chnests(Actor* arg0, s32 arg1)
{
    if (func_80800898_chnests(arg0, arg1, arg0->rotation[1]) != 0)
    {
        func_800DF3E0();
        func_800DF744(D_80801118_chnests[arg0->actorData[1]].unkC, 1);
        func_801018A4(arg0, arg1);
    }
}

void func_808009D4_chnests(s32 arg0,s32 arg1)
{
    func_8010DD20(arg0,0x1,arg1);
}

void func_808009F8_chnests(s32 arg0) 
{
}

void func_80800A00_chnests(Actor* arg0, s32 arg1)
{
    if (func_80800898_chnests(arg0, arg1, arg0->rotation[1]) != 0)
    {
        func_800DF3E0();
        func_800DF744(D_80801118_chnests[arg0->actorData[1]].unkC, 1);
        func_801018A4(arg0, arg1);
    }
}
void func_80800A6C_chnests(s32 arg0) 
{
}

s32 func_80800A74_chnests(s32 nestIndex)
{
    s16 associatedAbility;
    s32 temp_s3;
    //Increment the nestIndex from the current nest being displayed

    temp_s3 = D_80801118_chnests[nestIndex++].unk0;
    while (temp_s3 != D_80801118_chnests[nestIndex].unk0)
    {
        //Check if the cycle should loop back to the beginning
        if (D_80801118_chnests[nestIndex].unk0 == -1)
        {
            //Traverse the cycle backwards until we hit 0 or another -1
            while (nestIndex > 0 && D_80801118_chnests[nestIndex - 1].unk0 != -1)
            {
                nestIndex--;
            }
        }
        associatedAbility = D_80801118_chnests[nestIndex].abilityId;
        //Check if we can cycle to the next nest type
        if (associatedAbility == 0 || ability_getValue(associatedAbility) != 0)
        {
            //We have found a valid next nest type to go to stop here
            break;
        }
        //Go to the next nest type and see if we can use that
        nestIndex++;
    }
    //Return the next valid nest type
    return nestIndex;
}

void func_80800B4C_chnests(Actor* arg0)
{
    arg0->unk58 = rand_fBounded(((f32*)&arg0->actorData)[4], ((f32*)&arg0->actorData)[5]);
    arg0->actorData[6] = 0;
}

void func_80800B80_chnests(Actor* arg0)
{
    if (arg0->unk64_20)
    {
        arg0->actorData[6] = 2;
    }
}

void func_80800BA0_chnests(Actor* arg0, s32 arg1)
{
    arg0->actorData[1] = arg1;
    arg0->unk0->unk24_22 = (D_80801118_chnests[arg1].unk0);
}

void func_80800BD8_chnests(Actor* arg0, s32 arg1, f32 arg2, f32 arg3)
{
    Unk80132ED0* temp_v0;

    temp_v0 = arg0->unk0;
    temp_v0->unk24_22 = arg1;
    func_80800000_chnests(arg0);
    arg0->unk64_20 = 1;
    ((f32*)arg0->actorData)[4] = arg2;
    ((f32*)arg0->actorData)[5] = arg3;
    func_80800B4C_chnests(arg0);
}

//Update Cycling Egg/Feather Nests
void func_80800C3C_chnests(Actor* arg0)
{
    switch (arg0->actorData[6])
    {
    case 0:
        if (!(arg0->unk79_0) && (timer_reachedZero(&arg0->unk58) != 0))
        {
            arg0->unk6C_0 = (func_80800A74_chnests(arg0->actorData[1]));
            if ((arg0->unk6C_0) == arg0->actorData[1])
            {
                func_80800B4C_chnests(arg0);
                return;
            }
            arg0->unk58 = 0.25f;
            arg0->actorData[6] = 1;
            return;
        }
        return;
    case 1:
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            func_80800BA0_chnests(arg0, arg0->unk6C_0);
            func_80800B4C_chnests(arg0);
            func_8010A828(arg0, 1U);
            return;
        }
        break;
    case 2:
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            _subaddiefade_entrypoint_2(arg0);
            actor_enableCollision(arg0);
            _subaddieDll_entrypoint_4(arg0, 0U);
            arg0->unk64_16 = 1;
            func_80101FDC(arg0, arg0->actorData[0]);
            func_80800B4C_chnests(arg0);
        }
        break;
    }
}

void func_80800D8C_chnests(Actor* arg0, s32 arg1)
{
    s32 temp_f18;
    if (func_80800898_chnests(arg0, arg1, arg0->rotation[1]) != 0)
    {
        func_800DF3E0();
        func_800DF744(D_80801118_chnests[arg0->actorData[1]].unkC, 1);
        if (arg0->actorData[6] == 1)
        {
            temp_f18 = (s32)((arg0->unk58 / 0.25f) * 255.0f);
            arg0->unk7A_14 = 2;
            _subaddiefade_entrypoint_1(arg0, temp_f18);
            func_801018A4(arg0, arg1);
            func_800DF3E0();
            func_800DF744(D_80801118_chnests[arg0->unk6C_0].unkC, 1);
            arg0->unk7A_14 = 1;
            _subaddiefade_entrypoint_1(arg0, 0xFF - temp_f18);
            func_801018A4(arg0, arg1);
            arg0->unk7A_14 = 1;
            _subaddiefade_entrypoint_1(arg0, 0xFF);
            return;
        }
        func_801018A4(arg0, arg1);
    }
}

void func_80800ED8_chnests(Actor* arg0)
{
    func_80800BD8_chnests(arg0, 0x1CE, 1.0f, 1.0f);
}

void func_80800F08_chnests(Actor* arg0)
{
    func_80800BD8_chnests(arg0, 0x1D5, 1.0f, 1.0f);
}
//Blue Eggs
ActorData* chnests_entrypoint_0(void)
{
    return &D_808011E8_chnests;
}
//Fire Egg Nest
ActorData* chnests_entrypoint_1(void)
{
    return &D_80801230_chnests;
}
//Ice Eggs
ActorData* chnests_entrypoint_2(void)
{
    return &D_80801278_chnests;
}
//Grenade Eggs
ActorData* chnests_entrypoint_3(void)
{
    return &D_808012C0_chnests;
}
//Clockwork Eggs
ActorData* chnests_entrypoint_4(void)
{
    return &D_80801308_chnests;
}
//Gold Eggs
ActorData* chnests_entrypoint_5(void)
{
    return &D_80801350_chnests;
}
//Proximity Eggs
ActorData* chnests_entrypoint_6(void)
{
    return &D_80801398_chnests;
}
//Red Feathers
ActorData* chnests_entrypoint_7(void)
{
    return &D_808013E0_chnests;
}
//Gold Feathers
ActorData* chnests_entrypoint_8(void)
{
    return &D_80801428_chnests;
}
//Note Nest
ActorData* chnests_entrypoint_9(void)
{
    return &D_80801470_chnests;
}
//Treble Nest
ActorData* chnests_entrypoint_10(void)
{
    return &D_808014B8_chnests;
}
//Egg Nest
ActorData* chnests_entrypoint_11(void)
{
    return &D_80801500_chnests;
}
//Feather Nest
ActorData* chnests_entrypoint_12(void)
{
    return &D_80801548_chnests;
}

u8 chnests_entrypoint_13(s32 arg0)
{
    s32 index = 1;
    s32 size = 0xE;
    for (index = 0; index < size; index++)
    {
        if (arg0 == D_80801118_chnests[index].unk0)
        {
            return D_80801118_chnests[index].itemAmount;
        }
    }
    return 0U;
}

//Is Egg Nest
int func_80801014_chnests(Actor* arg0)
{
	return arg0->unk6C_9 == PROP_1C8_NEST_BLUE_EGGS || arg0->unk6C_9 == PROP_1C9_NEST_FIRE_EGGS || arg0->unk6C_9 == PROP_1CA_NEST_ICE_EGGS || arg0->unk6C_9 == PROP_1CB_NEST_GRENADE_EGGS || arg0->unk6C_9 == PROP_1CC_NEST_CLOCKWORK_EGGS || arg0->unk6C_9 == PROP_1CD_NEST_GOLD_EGGS || arg0->unk6C_9 == PROP_2B8_NEST_PROXIMITY_EGGS || arg0->unk6C_9 == PROP_1E9_EGGNEST;
}
//Is Feather Nest
int func_808010A0_chnests(Actor* arg0)
{
	return (arg0->unk6C_9 == PROP_1CE_NEST_RED_FEATHERS || arg0->unk6C_9 == PROP_1CF_NEST_GOLD_FEATHERS || arg0->unk6C_9 == PROP_4A6_FEATHERNEST);
}
