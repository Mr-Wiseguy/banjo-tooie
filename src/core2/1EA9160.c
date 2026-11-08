#include "core2/1EA9160.h"

typedef struct {
    u8 unk0;
    u8 color;
    u8 unk2;
} JinjoData;

extern JinjoData D_8011AB40[];

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
    s16 itemFlag;
    s16 itemType;
} unkD_8011AE64;

extern unkD_8011AE64 D_8011AE64[];

typedef struct {
    s16 itemFlag; //ItemFlag
    s16 itemType; //ItemType
    s32 r;
    s32 g;
    s32 b;
} glowingItems;
extern glowingItems D_8011AE74[];


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

//Is this Mr Patch or SSLUMBER Jiggy
s32 collectable_isMrPatchOrSSLUMBERJiggy(s32 arg0, CollectableId arg1)
{
    s32 index;
    for (index = 0; index < 2; index++)
    {
        if ((arg0 == D_8011AE64[index].itemFlag) && (arg1 == D_8011AE64[index].itemType))
        {
            return 1;
        }
    }
    return 0;
}

//Is this King Coal or Mingy Jongo Reward
s32 collectable_isKingCoalOrMingyJongoReward(s32 arg0, CollectableId arg1)
{
    s32 index;
    for (index = 2; index < 4; index++)
    {
        if ((arg0 == D_8011AE64[index].itemFlag) && (arg1 == D_8011AE64[index].itemType))
        {
            return 1;
        }
    }
    return 0;
}

//Is this a glowing Jiggy retrieve the index if so
s32 collectable_getSpecialColorIdx(s32 arg0, CollectableId arg1)
{
    s32 i = 0;
    for (i = 0; i < 9; i++)
    {
        if ((arg0 == D_8011AE74[i].itemFlag) && (arg1 == D_8011AE74[i].itemType))
        {
            return i;
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF9E4.s")

s32 collectable_getSpecialColorIdx_DUPE(s32 arg0, CollectableId arg1)
{
    return collectable_getSpecialColorIdx(arg0,arg1);
}

//Set jinjo pattern
s32 collectable_setJinjoPattern()
{
	s32 var_v0[0x9];
	s32 var_a0;

	s32* var_v1;


	s32 var_s0;

	s32 var_v0_2;


	s32 index;
	if (func_800DA9E4(FLAG2_6A0_JINJO_PATTERN_ALREADY_APPLIED_TO_GAME, 1) != 0)
	{
		return 0;
	}
	if (flag_getValue(FLAG_379_RANDOMISER_JINJO_SET) == 0)
	{
		//Get Random int between 0 and 0x21
		var_s0 = rand_iBounded(0, 0x21);
		flag_setMultipleValue(FLAG_37A_RANDOMISER_JINJO_1, (u32)var_s0, 5);
		flag_setValueTrue(FLAG_379_RANDOMISER_JINJO_SET);
	}
	else
	{
		var_s0 = flag_getMultipleValue(FLAG_37A_RANDOMISER_JINJO_1, 5);
	}
	rand_saveCurrentSeed();
	rand_setSeed((s32)var_s0);
	//Zero out 0x24 from sp
	for (index = 0; index < 0x9; index++)
	{
		var_v0[index] = 0;
	}
	for (index = 0; index < 0x2D; index++)
	{
		//Get Random int between 0 and 9
		var_v0_2 = rand_iBounded(0, 9);
		var_v1 = &(&var_v0[0])[var_v0_2];
		var_a0 = *var_v1;
		while ((s32)var_v0_2 < var_a0)
		{
			var_v0_2 = rand_iBounded(0, 9);
			var_v1 = &(&var_v0[0])[var_v0_2];
			var_a0 = *var_v1;
		}
		*var_v1 = var_a0 + 1;
		D_8011AB40[index].color = var_v0_2;
	}
	rand_restoreCurrentSeed(var_a0);
	return 1;
}

void func_800CFBC8(Actor* arg0, s32 itemFlag, CollectableId itemType, s32 arg3)
{
	event_sendToActor(arg0, 0x13, itemFlag);
	if (collectable_isMrPatchOrSSLUMBERJiggy(itemFlag, itemType) != 0)
	{
		_subaddieDll_entrypoint_4(arg0, 1);
	}
	if (collectable_isKingCoalOrMingyJongoReward(itemFlag, itemType) != 0)
	{
		event_sendToActor(arg0, 0x12, 1);
	}
	if (collectable_getSpecialColorIdx(itemFlag, itemType) != -1)
	{
		event_sendToActor(arg0, 0x55, 1);
	}
}

//Return the relative jiggy index within the level
s32 collectable_getJiggyLevelIdx(s32 jiggyIndex)
{
    jiggyIndex = jiggyIndex - D_8011AE60;
    if ((jiggyIndex >= 0) && (jiggyIndex < 0xA))
    {
        return jiggyIndex;
    }
    return -1;
}

//Get the total number of an item type in a level
s32 collectable_getTotalInLevel(CollectableId itemType, s32 Level)
{
    s32 var_a0;
    s32 var_s1;
    s32 foundInLevel;

    foundInLevel = 0;
    switch (itemType)
    {
    case TYPE_0_JINJO:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
        {
            if (Level == D_8011AB40[var_s1 - 1].unk0)
            {
                foundInLevel += 1;
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_1_JIGGY:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
        {
            if (Level == D_8011ABC8[var_s1 * 2 - 2])
            {
                foundInLevel += 1;
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_2_EMPTY_HONEYCOMB:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
        {
            if (Level == D_8011AC7C[var_s1 * 2 - 2])
            {
                foundInLevel += 1;
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_3_GLOWBO:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
        {
            if (Level == D_8011ACB0[var_s1 * 2 - 2])
            {
                foundInLevel += 1;
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_4_CHEATO:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
        {
            if (Level == D_8011ACD4[var_s1 * 2 - 2])
            {
                foundInLevel += 1;
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_5_JADE_TOTEM:
        return (collectable_getTotalCount(itemType) - collectable_getStartIdx(itemType)) + 1;
    case TYPE_6_NOTE:
        var_s1 = collectable_getStartIdx(itemType);
        while (collectable_getTotalCount(itemType) >= var_s1)
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
                foundInLevel += _chnests_entrypoint_13(var_a0);
            }
            var_s1 += 1;
        }
        return foundInLevel;
    case TYPE_7_DOUBLOON:
        return (collectable_getTotalCount(itemType) - collectable_getStartIdx(itemType)) + 1;
    case TYPE_8_TICKET:
        return (collectable_getTotalCount(itemType) - collectable_getStartIdx(itemType)) + 1;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFFBC.s")

s32 collectable_getCollectedInLevel(CollectableId arg0, s32 arg1)
{
    s32 var_a0;
    s32 idx;
    s32 foundCollected;
    unkD_8011AE64* temp_v0;

    foundCollected = 0;
    switch (arg0)
    {
        case TYPE_0_JINJO:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if ((collectable_isCollected(idx, arg0) != 0) && (arg1 == D_8011AB3D[idx * 3]))
                {
                    foundCollected++;
                }
                idx++;
            }

            return foundCollected;
        case TYPE_1_JIGGY:
            idx = collectable_getStartIdx(arg0);

            while (collectable_getTotalCount(arg0) >= idx)
            {
                if ((collectable_isCollected(idx, arg0) != 0) && (arg1 == (D_8011ABC6)[idx * 2]))
                {
                    foundCollected++;
                }
                idx++;
            }

            return foundCollected;
        case TYPE_2_EMPTY_HONEYCOMB:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if ((collectable_isCollected(idx, arg0) != 0) && (arg1 == D_8011AC7A[idx * 2]))
                {
                    foundCollected++;
                }
                idx++;
            }

            return foundCollected;
        case TYPE_3_GLOWBO:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if ((collectable_isCollected(idx, arg0) != 0) && (arg1 == D_8011ACAE[idx * 2]))
                {
                    foundCollected++;
                }
                idx++;
            }
            return foundCollected;
        case TYPE_4_CHEATO:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if ((collectable_isCollected(idx, arg0) != 0) && (arg1 == D_8011ACD2[idx * 2]))
                {
                    foundCollected++;
                }
                idx++;
            }
            return foundCollected;
        case TYPE_6_NOTE:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if (collectable_isCollected(idx, arg0) != 0)
                {
                    if (arg1 == D_8011AD08[(idx) * 2 - 2])
                    {
                        if (D_8011AD08[idx * 2 - 1] != 0)
                        {
                            var_a0 = 0x1DA;
                        }
                        else {
                            var_a0 = 0x1D9;
                        }
                        foundCollected += _chnests_entrypoint_13(var_a0);
                    }
                }
                idx++;
            }
            return foundCollected;
        default:
            idx = collectable_getStartIdx(arg0);
            while (collectable_getTotalCount(arg0) >= idx)
            {
                if (collectable_isCollected(idx, arg0) != 0)
                {
                    foundCollected++;
                }
                idx++;
            }
            return foundCollected;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D035C.s")

void func_800D046C(s32 arg0, s32 arg1, CollectableId arg2)
{
    func_800DAC78(arg0, collectable_getCollectedFlag(arg1, arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D04A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D053C.s")

void func_800D0594(s32 arg0, CollectableId arg1, s16 arg2)
{
    s32 temp_v0;

    if (arg1 == TYPE_1_JIGGY)
    {
        temp_v0 = collectable_getJiggyLevelIdx(arg0);
        if (temp_v0 != -1)
        {
            D_8012B180[temp_v0].spawnMap = arg2;
        }
    }
}

void func_800D05E4(s32 arg0, CollectableId arg1, Unk80132ED0* arg2)
{
    s32 temp_v0;

    if (arg1 == TYPE_1_JIGGY)
    {
        temp_v0 = collectable_getJiggyLevelIdx(arg0);
        if (temp_v0 != -1)
        {
            D_8012B180[temp_v0].unkC = arg2;
        }
    }
}


s32 func_800D0634(s32 arg0, CollectableId arg1)
{
    s32 temp_v0;

    if (arg1 == 1)
    {
        temp_v0 = collectable_getJiggyLevelIdx(arg0);
        if (temp_v0 != -1)
        {
            return  D_8012B180[temp_v0].unkC;
        }
    }
    return 0;
}

s16 func_800D0684(s32 arg0, CollectableId arg1)
{
    s32 temp_v0;

    if (arg1 == TYPE_1_JIGGY)
    {
        temp_v0 = collectable_getJiggyLevelIdx(arg0);
        if (temp_v0 != -1)
        {
            return D_8012B180[temp_v0].spawnMap;
        }
    }
    return 0;
}


s32 func_800D06D4(s32 itemIndex, CollectableId itemType)
{
    switch (itemType)
    {
    case TYPE_1_JIGGY:
        return D_8011ABC6[itemIndex * 2];
    case TYPE_0_JINJO:
        return D_8011AB3D[itemIndex * 3];
    case TYPE_4_CHEATO:
        return D_8011ACD2[itemIndex * 2];
    case TYPE_3_GLOWBO:
        return D_8011ACAE[itemIndex * 2];
    case TYPE_2_EMPTY_HONEYCOMB:
        return D_8011AC7A[itemIndex * 2];
    case TYPE_5_JADE_TOTEM:
        return 0x10;
    case TYPE_6_NOTE:
        return -1;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0778.s")

void collectable_getJiggyCoords(s32 itemIndex, CollectableId arg1, f32* arg2)
{
    s32 temp_v0;

    if (arg1 == TYPE_1_JIGGY)
    {
        temp_v0 = collectable_getJiggyLevelIdx(itemIndex);
        if (temp_v0 != -1)
        {
            ml_vec3f_copy(arg2, D_8012B180[temp_v0].coords);
        }
    }
}

s32 collectable_getStartIdx(CollectableId itemType)
{
    switch (itemType)
    {
        case TYPE_0_JINJO:
            return 1;
        case TYPE_1_JIGGY:
            return 1;
        case TYPE_2_EMPTY_HONEYCOMB:
            return 1;
        case TYPE_3_GLOWBO:
            return 1;
        case TYPE_4_CHEATO:
            return 1;
        case TYPE_5_JADE_TOTEM:
            return 1;
        case TYPE_6_NOTE:
            return 1;
        case TYPE_7_DOUBLOON:
            return 1;
        case TYPE_8_TICKET:
            return 1;
        default:
            return -1;
    }
}

s32 collectable_getTotalCount(CollectableId itemType)
{
    switch (itemType)
    {
        case TYPE_0_JINJO:
            return 45;
        case TYPE_1_JIGGY:
            return 90;
        case TYPE_2_EMPTY_HONEYCOMB:
            return 25;
        case TYPE_3_GLOWBO:
            return 17;
        case TYPE_4_CHEATO:
            return 25;
        case TYPE_5_JADE_TOTEM:
            return 25;
        case TYPE_6_NOTE:
            return 153;
        case TYPE_7_DOUBLOON:
            return 30;
        case TYPE_8_TICKET:
            return 4;
        default:
            return -1;
    }
}

s32 collectable_getSpawnFlag(s32 arg0, CollectableId itemType)
{
    switch (itemType)
    {
    case TYPE_0_JINJO:
        if (D_8011AB3F[arg0 * 3] != 0)
        {
            return (D_8011AF28[itemType] + D_8011AB3F[arg0 * 3]) - 1;
        }
    default:
        break;
    case TYPE_1_JIGGY:
        if (D_8011ABC7[arg0 * 2] != 0)
        {
            return (D_8011AF28[itemType] + D_8011ABC7[arg0 * 2]) - 1;
        }
        break;
    case TYPE_4_CHEATO:
        if (D_8011ACD3[arg0 * 2] != 0)
        {
            return (D_8011AF28[itemType] + D_8011ACD3[arg0 * 2]) - 1;
        }
        break;
    case TYPE_2_EMPTY_HONEYCOMB:
        if (D_8011AC7B[arg0 * 2] != 0)
        {
            return (D_8011AF28[itemType] + D_8011AC7B[arg0 * 2]) - 1;
        }
        break;
    case TYPE_3_GLOWBO:
        if (D_8011ACAF[arg0 * 2] != 0)
        {
            return (D_8011AF28[itemType] + D_8011ACAF[arg0 * 2]) - 1;
        }
        break;
    case TYPE_7_DOUBLOON:
        if (D_8011AE3B[arg0] != 0)
        {
            return (D_8011AF28[itemType] + D_8011AE3B[arg0]) - 1;
        }
        break;
    case TYPE_8_TICKET:
        if (D_8011AE5B[arg0] != 0)
        {
            return D_8011AF28[itemType] + D_8011AE5B[arg0] - 1;
        }
        break;
    }
    return 0;
}
s32 collectable_getCollectedFlag(s32 arg0, CollectableId itemType)
{
    return D_8011AF04[itemType] + arg0 - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/collectable_isSpawned.s")

void collectable_setSpawnedTrue(s32 arg0, CollectableId itemType)
{
    enum flag_e temp_v0;

    temp_v0 = collectable_getSpawnFlag(arg0, itemType);
    if (temp_v0 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
    {
        flag_setValueTrue(temp_v0);
    }
}

void collectable_setSpawnedFalse(s32 arg0, CollectableId itemType)
{
    enum flag_e temp_v0;

    temp_v0 = collectable_getSpawnFlag(arg0, itemType);
    if (temp_v0 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
    {
        flag_setValueFalse(temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/collectable_isCollected.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/collectable_collectItem.s")

void func_800D0C78(s32 arg0, CollectableId itemType, u32 arg2)
{
    if (itemType == TYPE_1_JIGGY)
    {
        collectable_setSpawnedTrue(arg0, itemType);
        collectable_collectItem(arg0, itemType);
        if (arg2 == 0)
        {
            func_800FC660(5);
        }
    }
}

s32 func_800D0CC8(s32 arg0)
{
    return D_8011AB40[arg0 - 1].color;
}


Actor* collectable_itemSpawnMovement(PropId arg0, f32* coords, u32 spawnStyle, s32* arg3)
{
    *arg3 = 0;
    switch (spawnStyle)
    {
    case 0: //Random Low Velocity
        return _chbounce_entrypoint_7(0x1C, coords, arg0);
    case 1: //Small Bounce
        return _chbounce_entrypoint_7(0x1D, coords, arg0);
    case 4: //CCW
        return _chbounce_entrypoint_7(0x1E, coords, arg0);
    case 3:
        *arg3 = 1;
    case 2: //Spin CCW
        return func_80108474(arg0, coords, 0);
    case 5: //High Velocity
        return _chbounce_entrypoint_7(0x1F, coords, arg0);
    case 6: //Random High Velocity
        return _chbounce_entrypoint_7(0x20, coords, arg0);
    default:
        return 0;
    }
}


Unk80132ED0* collectable_itemSetup(s32 arg0, f32* coords, s32 spawnStyle, Unk80132ED0* arg3)
{
    CollectableId itemType;
    s32 itemFlag;
    Actor* sp2C;
    s32 sp28;

    itemFlag = (arg0 >> 0x10) & 0xFFFF;
    itemType = arg0 & 0xFFFF;
    switch (itemType)
    {
    case TYPE_1_JIGGY:
        sp2C = collectable_itemSpawnMovement(PROP_21F_JIGGY_REAL, coords, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            event_sendToActor(sp2C, 0x14, 1);
        }
        func_800D05E4(itemFlag, itemType, sp2C->unk0);
        break;
    case TYPE_0_JINJO:
        sp2C = collectable_itemSpawnMovement(PROP_1F4_JINJO_REAL, coords, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            event_sendToActor(sp2C, 0x14, 1);
        }
        break;
    case TYPE_4_CHEATO:
        sp2C = collectable_itemSpawnMovement(PROP_136_CHEATOPAGE_REAL, coords, spawnStyle, &sp28);
        if (sp28 == 0)
        {
            event_sendToActor(sp2C, 0x14, 1);
        }
        break;
    case TYPE_2_EMPTY_HONEYCOMB:
        sp2C = collectable_itemSpawnMovement(PROP_220_HONEYCOMB_REAL, coords, spawnStyle, &sp28);
        break;
    case TYPE_3_GLOWBO:
        sp2C = collectable_itemSpawnMovement(PROP_21B_GLOWBO_REAL, coords, spawnStyle, &sp28);
        break;
    case TYPE_7_DOUBLOON:
        sp2C = collectable_itemSpawnMovement(PROP_4E5_DOUBLOON_REAL, coords, spawnStyle, &sp28);
        break;
    case TYPE_8_TICKET:
        sp2C = collectable_itemSpawnMovement(PROP_3C6_TICKET_REAL, coords, spawnStyle, &sp28);
        break;
    default:
        break;
    }
    func_800CFBC8(sp2C, itemFlag, itemType, 0);
    if ((arg3 != NULL) && (arg3->unk18_16))
    {
        func_80101074(sp2C->unk0);
        func_8010114C(arg3, 0xD, arg0);
    }
    return sp2C->unk0;
}

void collectable_itemInit(s32 arg0, s32 x, s32 y, s32 z, s32 spawnStyle, Unk80132ED0* arg5)
{
    f32 temp;
    f32 coords[3];
    coords[0] = (f32)x;
    coords[1] = (f32)y;
    coords[2] = (f32)z;
    collectable_itemSetup(arg0, coords, spawnStyle, arg5);
}

void collectable_spawnItem(u32 itemIndex, CollectableId itemType, f32* spawnCoords, u32 spawnStyle, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((collectable_isSpawned(itemIndex, itemType) == 0) && (collectable_isCollected(itemIndex, itemType) == 0))
    {
        collectable_setSpawnedTrue(itemIndex, itemType);
        func_800D053C(itemIndex, itemType);
        if (spawnCoords != NULL)
        {
            ml_vec3f_to_vec3i(sp44, spawnCoords);
        }
        else
        {
            collectable_getJiggyCoords(itemIndex, itemType, sp34);
            ml_vec3f_to_vec3i(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&collectable_itemInit, (itemIndex << 0x10) | (itemType & 0xFFFF), sp44[0], sp44[1], sp44[2], spawnStyle, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D10D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D119C.s")

void func_800D1218(s32 arg0, CollectableId arg1, f32* arg2)
{
    s32 temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) 
    {
        ml_vec3f_copy(arg2, func_80106790((Unk80132ED0*)temp_v0)->position);
    }
}

void func_800D1254(s32 arg0, CollectableId arg1, f32* arg2)
{
    s32 pad;
    Actor* temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0)
    {
        temp_v0_2 = func_80106790((Unk80132ED0*)temp_v0);
        ml_vec3f_copy(temp_v0_2->position, arg2);
        func_80103014(temp_v0_2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D129C.s")

s32 collectable_getNumJinjoCollectedColor(s32 JinjoColor)
{
    s32 var_s0;
    u32 var_s2;

    var_s2 = 0;
    var_s0 = collectable_getStartIdx(TYPE_0_JINJO);

    while (collectable_getTotalCount(TYPE_0_JINJO) >= var_s0)
    {
        if ((JinjoColor == D_8011AB40[var_s0 - 1].color) && (collectable_isCollected((u32)var_s0, TYPE_0_JINJO) != 0))
        {
            var_s2 += 1;
        }
        var_s0 += 1;
    }

    return var_s2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D13E8.s")
