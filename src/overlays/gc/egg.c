#include "gc/egg.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 inventoryId;
    u8 abilityId;
    u8 unkB;
    u8 unkC;
    u8 unkD;
} eggStruct;

eggStruct D_80800200_gcegg[] = {
    {0x0158,0x0071,0x0000,0x0004,0x0,0x40,0x3C,0x01,0x03,0x00},
    {0x026C,0x0071,0x015A,0x0004,0x01,0x40,ABILITY_31_EGGS_BLUE,0x01,0x03,0x00},
    {0x026D,0x006E,0x015B,0x006A,0x02,0x41,ABILITY_2C_EGGS_FIRE,0x02,0x04,0x00},
    {0x026E,0x006F,0x015C,0x006B,0x03,0x42,ABILITY_2F_EGGS_ICE,0x00,0x03,0x00},
    {0x026F,0x0070,0x015D,0x006C,0x04,0x43,ABILITY_2D_EGGS_GRENADE,0x04,0x0C,0x00},
    {0x0270,0x006D,0x015E,0x0069,0x05,0x44,ABILITY_2E_EGGS_CLOCKWORK,0x04,0x04,0x00},
    {0x016D,0x0079,0x0160,0x0078,0x06,0x45,0x3C,0x04,0x03,0x00},
    {0x0271,0x0071,0x015F,0x0004,0x07,0x40,0x3C,0x01,0x05,0x00}
};

s32 gcegg_entrypoint_0(s32 arg0)
{
    s32 eggType;
    for (eggType = 0; eggType < 8; eggType++)
    {
        if (arg0 == D_80800200_gcegg[eggType].unk0)
        {
            return D_80800200_gcegg[eggType].unk8;
        }
    }
    return 0;
}

s32 gcegg_entrypoint_1(s32 arg0)
{
    s32 eggType;
    for (eggType = 0; eggType < 8; eggType++)
    {
        if (arg0 == D_80800200_gcegg[eggType].unk4)
        {
            return D_80800200_gcegg[eggType].unk8;
        }
    }
    return 0;
}

s32 gcegg_entrypoint_2(s32 eggType)
{
    return D_80800200_gcegg[eggType].unk2;
}

s32 gcegg_entrypoint_3(s32 eggType)
{
    return D_80800200_gcegg[eggType].unk6;
}

s32 gcegg_entrypoint_4(s32 eggType)
{
    return D_80800200_gcegg[eggType].unkC;
}

s32 gcegg_entrypoint_5(s32 eggType)
{
    return D_80800200_gcegg[eggType].inventoryId;
}

int gcegg_entrypoint_6(s32 eggType)
{
    s32 returnValue;
    returnValue = D_80800200_gcegg[eggType].abilityId;
    return  returnValue == 0x3C || ability_getValue(returnValue);
}

int gcegg_entrypoint_7(s32 arg0)
{
    s32 returnValue;
    if (!func_800D3948())
    {
        return 1;
    }
    else
    {
        returnValue = D_80800200_gcegg[arg0].unkB;
    }
    return returnValue;
}
