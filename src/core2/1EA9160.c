#include "core2/1EA9160.h"

extern u8 D_8011AB40[];
extern u8 D_8011ABC8[];
extern u8 D_8011AC7C[];
extern u8 D_8011ACB0[];
extern u8 D_8011ACD4[];
extern u8 D_8011AD08[];

extern u8 D_8011AB3D[];
extern u8 D_8011ABC6[];
extern u8 D_8011AC7A[];
extern u8 D_8011ACAE[];
extern u8 D_8011ACD2[];


extern u8 D_8011AB3F[];
extern u8 D_8011ABC7[];
extern u8 D_8011AC7B[];
extern u8 D_8011ACAF[];
extern u8 D_8011ACD3[];
extern u8 D_8011AE3B[];
extern u8 D_8011AE5B[];
extern u32 D_8011AF28[];


//List of the start of different flag regions for different collectible types
extern s32 D_8011AF04[];

//Start of the current level's jiggy flags
extern s32 D_8011AE60;

typedef struct {
    s16 unk0;
    s16 unk2;
} unkD_8011AE64;

extern unkD_8011AE64 D_8011AE64[];

extern unkD_8011AE64 D_8011AE74[];


typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    f32 x;
    f32 y;
    f32 z;
} unkD_D_8012B18C;

extern unkD_D_8012B18C D_8012B18C[];


typedef struct
{
    f32 coords[3];
    Unk80132ED0* unkC;
    s16 spawnMap;
    s16 unk12;
} UnkD_8012B180;
extern UnkD_8012B180 D_8012B180[];

void func_800CF870(s32 arg0)
{
    D_8011AE60 = arg0;
}

s32 func_800CF87C()
{
    return D_8011AE60;
}

s32 func_800CF888(s32 arg0, s32 arg1)
{
    s32 index;
    for (index = 0; index < 2; index++)
    {
        if ((arg0 == D_8011AE64[index].unk0) && (arg1 == D_8011AE64[index].unk2))
        {
            return 1;
        }
    }
    return 0;
}

s32 func_800CF8D0(s32 arg0, s32 arg1)
{
    s32 index;
    for (index = 2; index < 4; index++)
    {
        if ((arg0 == D_8011AE64[index].unk0) && (arg1 == D_8011AE64[index].unk2))
        {
            return 1;
        }
    }
    return 0;
}

s32 func_800CF918(s32 arg0, s32 arg1)
{
    s32 i = 1;

    for (i = 0; i < 9; i++)
    {
        if ((arg0 == D_8011AE74[i * 4].unk0) && (arg1 == D_8011AE74[i * 4].unk2))
        {
            return i;
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF9E4.s")

s32 func_800CFA70(s32 arg0,s32 arg1)
{
    return func_800CF918(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFBC8.s")

//Return the relative jiggy index within the level
s32 func_800CFC5C(s32 jiggyIndex)
{
    jiggyIndex = jiggyIndex - D_8011AE60;
    if ((jiggyIndex >= 0) && (jiggyIndex < 0xA))
    {
        return jiggyIndex;
    }
    return -1;
}

//Get the total number of an item type in a level
s32 func_800CFC8C(s32 itemType, s32 Level)
{
    s32 var_a0;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 0;
    switch (itemType)
    {
    case 0:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011AB40[var_s1 * 3 - 3])
            {
                var_s2 += 1;
            }
            var_s1 += 1;
        }
        return var_s2;
    case 1:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011ABC8[var_s1 * 2 - 2])
            {
                var_s2 += 1;
            }
            var_s1 += 1;
        }
        return var_s2;
    case 2:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011AC7C[var_s1 * 2 - 2])
            {
                var_s2 += 1;
            }
            var_s1 += 1;
        }
        return var_s2;
    case 3:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011ACB0[var_s1 * 2 - 2])
            {
                var_s2 += 1;
            }
            var_s1 += 1;
        }
        return var_s2;
    case 4:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011ACD4[var_s1 * 2 - 2])
            {
                var_s2 += 1;
            }
            var_s1 += 1;
        }
        return var_s2;
    case 5:
        return (func_800D0894(itemType) - func_800D0820(itemType)) + 1;
    case 6:
        var_s1 = func_800D0820(itemType);
        while (func_800D0894(itemType) >= var_s1)
        {
            if (Level == D_8011AD08[var_s1 * 2 - 2])
            {
                if (D_8011AD08[var_s1 * 2 - 1] != 0)
                {
                    var_a0 = 0x1DA;
                }
                else
                {
                    var_a0 = 0x1D9;
                }
                var_s2 += _chnests_entrypoint_13(var_a0);
            }
            var_s1 += 1;
        }
        return var_s2;
    case 7:
        return (func_800D0894(itemType) - func_800D0820(itemType)) + 1;
    case 8:
        return (func_800D0894(itemType) - func_800D0820(itemType)) + 1;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFFBC.s")

s32 func_800D0018(s32 arg0, s32 arg1)
{
    s32 var_a0;
    s32 var_s0;
    s32 var_s2;
    unkD_8011AE64* temp_v0;

    var_s2 = 0;
    switch (arg0)
    {
    case 0:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if ((func_800D0B68(var_s0, arg0) != 0) && (arg1 == D_8011AB3D[var_s0 * 3]))
            {
                var_s2++;
            }
            var_s0++;
        }

        return var_s2;
    case 1:
        var_s0 = func_800D0820(arg0);

        while (func_800D0894(arg0) >= var_s0)
        {
            if ((func_800D0B68(var_s0, arg0) != 0) && (arg1 == (D_8011ABC6)[var_s0 * 2]))
            {
                var_s2++;
            }
            var_s0++;
        }

        return var_s2;
    case 2:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if ((func_800D0B68(var_s0, arg0) != 0) && (arg1 == D_8011AC7A[var_s0 * 2]))
            {
                var_s2++;
            }
            var_s0++;
        }

        return var_s2;
    case 3:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if ((func_800D0B68(var_s0, arg0) != 0) && (arg1 == D_8011ACAE[var_s0 * 2]))
            {
                var_s2++;
            }
            var_s0++;
        }
        return var_s2;
    case 4:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if ((func_800D0B68(var_s0, arg0) != 0) && (arg1 == D_8011ACD2[var_s0 * 2]))
            {
                var_s2++;
            }
            var_s0++;
        }
        return var_s2;
    case 6:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if (func_800D0B68(var_s0, arg0) != 0)
            {
                if (arg1 == D_8011AD08[(var_s0) * 2 - 2])
                {
                    if (D_8011AD08[var_s0 * 2 - 1] != 0)
                    {
                        var_a0 = 0x1DA;
                    }
                    else {
                        var_a0 = 0x1D9;
                    }
                    var_s2 += _chnests_entrypoint_13(var_a0);
                }
            }
            var_s0++;
        }
        return var_s2;
    default:
        var_s0 = func_800D0820(arg0);
        while (func_800D0894(arg0) >= var_s0)
        {
            if (func_800D0B68(var_s0, arg0) != 0)
            {
                var_s2++;
            }
            var_s0++;
        }
        return var_s2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D035C.s")

void func_800D046C(s32 arg0, s32 arg1, s32 arg2)
{
    func_800DAC78(arg0, func_800D0A80(arg1, arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D04A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D053C.s")

void func_800D0594(s32 arg0, s32 arg1, s16 arg2)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = func_800CFC5C(arg0);
        if (temp_v0 != -1)
        {
            D_8012B180[temp_v0].spawnMap = arg2;
        }
    }
}

void func_800D05E4(s32 arg0, s32 arg1, Unk80132ED0* arg2)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = func_800CFC5C(arg0);
        if (temp_v0 != -1)
        {
            D_8012B180[temp_v0].unkC = arg2;
        }
    }
}


s32 func_800D0634(u32 arg0, u32 arg1)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = func_800CFC5C(arg0);
        if (temp_v0 != -1)
        {
            return  D_8012B180[temp_v0].unkC;
        }
    }
    return 0;
}

s16 func_800D0684(s32 arg0, s32 arg1)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = func_800CFC5C(arg0);
        if (temp_v0 != -1)
        {
            return D_8012B180[temp_v0].spawnMap;
        }
    }
    return 0;
}


s32 func_800D06D4(s32 itemIndex, s32 itemType)
{
    switch (itemType)
    {
    case 1:
        return D_8011ABC6[itemIndex * 2];
    case 0:
        return D_8011AB3D[itemIndex * 3];
    case 4:
        return D_8011ACD2[itemIndex * 2];
    case 3:
        return D_8011ACAE[itemIndex * 2];
    case 2:
        return D_8011AC7A[itemIndex * 2];
    case 5:
        return 0x10;
    case 6:
        return -1;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0778.s")

void func_800D07CC(s32 arg0, s32 arg1, f32* arg2)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = func_800CFC5C(arg0);
        if (temp_v0 != -1)
        {
            func_800EE7F8(arg2, D_8012B180[temp_v0].coords);
        }
    }
}

s32 func_800D0820(s32 itemType)
{
    switch (itemType)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return 1;
    case 7:
        return 1;
    case 8:
        return 1;
    default:
        return -1;
    }
}

s32 func_800D0894(s32 itemType)
{
    switch (itemType)
    {
    case 0:
        return 0x2D;
    case 1:
        return 0x5A;
    case 2:
        return 0x19;
    case 3:
        return 0x11;
    case 4:
        return 0x19;
    case 5:
        return 0x19;
    case 6:
        return 0x99;
    case 7:
        return 0x1E;
    case 8:
        return 4;
    default:
        return -1;
    }
}

s32 func_800D0908(s32 arg0, s32 arg1)
{
    switch (arg1)
    {
    case 0:
        if (D_8011AB3F[arg0 * 3] != 0)
        {
            return (D_8011AF28[arg1] + D_8011AB3F[arg0 * 3]) - 1;
        }
    default:
        break;
    case 1:
        if (D_8011ABC7[arg0 * 2] != 0)
        {
            return (D_8011AF28[arg1] + D_8011ABC7[arg0 * 2]) - 1;
        }
        break;
    case 4:
        if (D_8011ACD3[arg0 * 2] != 0)
        {
            return (D_8011AF28[arg1] + D_8011ACD3[arg0 * 2]) - 1;
        }
        break;
    case 2:
        if (D_8011AC7B[arg0 * 2] != 0)
        {
            return (D_8011AF28[arg1] + D_8011AC7B[arg0 * 2]) - 1;
        }
        break;
    case 3:
        if (D_8011ACAF[arg0 * 2] != 0)
        {
            return (D_8011AF28[arg1] + D_8011ACAF[arg0 * 2]) - 1;
        }
        break;
    case 7:
        if (D_8011AE3B[arg0] != 0)
        {
            return (D_8011AF28[arg1] + D_8011AE3B[arg0]) - 1;
        }
        break;
    case 8:
        if (D_8011AE5B[arg0] != 0)
        {
            return D_8011AF28[arg1] + D_8011AE5B[arg0] - 1;
        }
        break;
    }
    return 0;
}
s32 func_800D0A80(s32 arg0, s32 arg1)
{
    return D_8011AF04[arg1] + arg0 - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0A9C.s")

void func_800D0B08(s32 arg0, s32 arg1)
{
    enum flag_e temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
    {
        func_800DA544(temp_v0);
    }
}

void func_800D0B38(s32 arg0, s32 arg1)
{
    enum flag_e temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
    {
        func_800DA524(temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0BD4.s")

void func_800D0C78(u32 arg0, u32 arg1, u32 arg2)
{
    if (arg1 == 1)
    {
        func_800D0B08((s32)arg0, (s32)arg1);
        func_800D0BD4((s32)arg0, arg1);
        if (arg2 == 0)
        {
            func_800FC660(5);
        }
    }
}

s32 func_800D0CC8(s32 arg0)
{
    return D_8011AB40[arg0 * 3 - 2];
}


Actor* func_800D0CE0(PropId arg0, u32 arg1, u32 spawnStyle, s32* arg3)
{
    *arg3 = 0;
    switch (spawnStyle)
    {
    case 0: //Random Low Velocity
        return _chbounce_entrypoint_7(0x1C, arg1, arg0);
    case 1: //Small Bounce
        return _chbounce_entrypoint_7(0x1D, arg1, arg0);
    case 4: //CCW
        return _chbounce_entrypoint_7(0x1E, arg1, arg0);
    case 3:
        *arg3 = 1;
    case 2: //Spin CCW
        return func_80108474(arg0, arg1, 0);
    case 5: //High Velocity
        return _chbounce_entrypoint_7(0x1F, arg1, arg0);
    case 6: //Random High Velocity
        return _chbounce_entrypoint_7(0x20, arg1, arg0);
    default:
        return 0;
    }
}


Unk80132ED0* func_800D0DAC(s32 arg0, f32* arg1, s32 spawnStyle, u16* arg3)
{
    s32 itemType;
    s32 itemFlag;
    Actor* sp2C;
    s32 sp28;

    itemFlag = (arg0 >> 0x10) & 0xFFFF;
    itemType = arg0 & 0xFFFF;
    switch (itemType)
    {
    case 1:
        sp2C = func_800D0CE0(PROP_21F_JIGGY_REAL, arg1, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            func_8010108C(sp2C, 0x14, 1);
        }
        func_800D05E4(itemFlag, itemType, sp2C->unk0);
        break;
    case 0:
        sp2C = func_800D0CE0(PROP_1F4_JINJO_REAL, arg1, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            func_8010108C(sp2C, 0x14, 1);
        }
        break;
    case 4:
        sp2C = func_800D0CE0(PROP_136_CHEATOPAGE_REAL, arg1, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            func_8010108C(sp2C, 0x14, 1);
        }
        break;
    case 2:
        sp2C = func_800D0CE0(PROP_220_HONEYCOMB_REAL, arg1, spawnStyle, &sp28);
        break;
    case 3:
        sp2C = func_800D0CE0(PROP_21B_GLOWBO_REAL, arg1, spawnStyle, &sp28);
        break;
    case 7:
        sp2C = func_800D0CE0(PROP_4E5_DOUBLOON_REAL, arg1, spawnStyle, &sp28);
        break;
    case 8:
        sp2C = func_800D0CE0(PROP_3C6_TICKET_REAL, arg1, spawnStyle, &sp28);
        break;
    default:
        break;
    }
    func_800CFBC8(sp2C, itemFlag, itemType, 0);
    if ((arg3 != NULL) && (arg3[12] & 1))
    {
        func_80101074(sp2C->unk0);
        func_8010114C(arg3, 0xD, arg0);
    }
    return sp2C->unk0;
}

void func_800D0F9C(s32 arg0, s32 x, s32 y, s32 z, s32 spawnStyle, s32 arg5)
{
    f32 temp;
    f32 sp18[3];
    sp18[0] = (f32)x;
    sp18[1] = (f32)y;
    sp18[2] = (f32)z;
    func_800D0DAC(arg0, sp18, spawnStyle, arg5);
}

void func_800D1000(u32 arg0, u32 arg1, f32* spawnCoords, u32 spawnStyle, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((func_800D0A9C(arg0, arg1) == 0) && (func_800D0B68(arg0, arg1) == 0))
    {
        func_800D0B08(arg0, arg1);
        func_800D053C(arg0, arg1);
        if (spawnCoords != NULL)
        {
            func_800EE904(sp44, spawnCoords);
        }
        else
        {
            func_800D07CC(arg0, arg1, sp34);
            func_800EE904(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&func_800D0F9C, (arg0 << 0x10) | (arg1 & 0xFFFF), sp44[0], sp44[1], sp44[2], spawnStyle, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D10D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D119C.s")

void func_800D1218(u32 arg0, u32 arg1, f32* arg2)
{
    s32 temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) 
    {
        func_800EE7F8(arg2, func_80106790((Unk80132ED0*)temp_v0)->position);
    }
}

void func_800D1254(u32 arg0, u32 arg1, f32* arg2)
{
    s32 pad;
    Actor* temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0)
    {
        temp_v0_2 = func_80106790((Unk80132ED0*)temp_v0);
        func_800EE7F8(temp_v0_2->position, arg2);
        func_80103014(temp_v0_2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D129C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D1338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D13E8.s")
