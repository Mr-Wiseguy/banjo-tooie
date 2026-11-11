#include "gc/collectDLL.h"

s16 D_80800BE0_gccollectDll[0x16] = { 0x31,0x1,0x26,0x1,0xB,0x4,0xA,0x1,0x16,0x2,0x3D,0x1,0x4C,0x01,0xA,0x2,0x14,0x0,0x36,0x1,0x6,0x2 };
f32 D_80800C0C_gccollectDll[3] = { 0,0,0};
PropId D_80800C18_gccollectDll[0x9] = { PROP_1F4_JINJO_REAL,PROP_21F_JIGGY_REAL,PROP_220_HONEYCOMB_REAL,PROP_21B_GLOWBO_REAL,PROP_136_CHEATOPAGE_REAL,0x0,0x0,PROP_4E5_DOUBLOON_REAL,PROP_3C6_TICKET_REAL };
extern u8 D_8012762C;

s32 func_80800000_gccollectDll(void)
{
    s32 var_s0;
    u32 temp_s1;

    //Seems to be some indicator for which level you are in
    temp_s1 = D_8012762C;
    if (temp_s1 == 0x13) //If we are in SM
    {
        return 0x5B;
    }
    var_s0 = collectable_getStartIdx(TYPE_1_JIGGY); //This will always return 1 since 1(Jiggy) is a valid item
    //If the number of Jiggies is greater than or equal to 1 (Always true)
    if (collectable_getTotalCount(TYPE_1_JIGGY) >= var_s0)
    {
        //Loop through all Jiggies
        do
        {
            if (func_800D06D4(var_s0, TYPE_1_JIGGY) == temp_s1) //Return the index of the first jiggy found associated with the level
            {
                return var_s0;
            }
            var_s0 += 1;
        } while (collectable_getTotalCount(TYPE_1_JIGGY) >= var_s0);
    }
    return -1;
}

void gccollectDll_entrypoint_0(CollectableId arg0) 
{
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s0 = collectable_getStartIdx(arg0);
    if (var_s0 < collectable_getTotalCount(arg0)) 
    {
        do {
            temp_v0 = collectable_getCollectedFlag(var_s0, arg0);
            if (temp_v0 != 0) 
            {
                flag_setValueFalse(temp_v0);
            }
            temp_v0_2 = collectable_getSpawnFlag(var_s0, arg0);
            if (temp_v0_2 != 0) 
            {
                flag_setValueFalse(temp_v0_2);
            }
            var_s0 += 1;
        } while (var_s0 < collectable_getTotalCount(arg0));
    }
}

void gccollectDll_entrypoint_1(void)
{
    s32 var_s0;

    var_s0 = 0;
    do {
        gccollectDll_entrypoint_0(var_s0);
        var_s0 += 1;
    } while (var_s0 != 9);
}

void gccollectDll_entrypoint_2(void)
{
    gccollectDll_entrypoint_1();
}

void gccollectDll_entrypoint_3(void) {
}

void gccollectDll_entrypoint_4(void)
{
    s32 pad1;
    s32 pad2;
    s32 sp2C;
    s32 var_s0;
    //Get First Jiggy Index for current level
    s32 temp_v0 = func_80800000_gccollectDll();
    s32 iterator;

    //Store Jiggy Index in 8011AE60
    func_800CF870(temp_v0);
    if (temp_v0 != -1) //If we found a jiggy
    {
        sp2C = collectable_setJinjoPattern();
        for (iterator = temp_v0; iterator < temp_v0 + 0xA; iterator++)
        {
            func_800D0778(iterator, 1, D_80800C0C_gccollectDll);
            func_800D05E4(iterator, 1, NULL);
            func_800D0594(iterator, 1, 0);
        }
        //If we are not in a cutscene
        if (func_800DB9B0() == 0)
        {
            _gcgamefix_entrypoint_1(sp2C);
        }
    }
}

void gccollectDll_entrypoint_5(void)
{
    u32 var_s0 = 0;

    if (func_800CF87C() != -1)
    {
        //Iterate through the list of collectables that are virtual objects e.g. they do not exist in the map file
        for (var_s0 = 0; var_s0 < 0x16; var_s0 += 2)
        {
            //If the item hasn't been collected but has been spawned
            if ((collectable_isCollected((u32)D_80800BE0_gccollectDll[var_s0], (u32)D_80800BE0_gccollectDll[var_s0 + 1]) == 0) && (collectable_isSpawned((u32)D_80800BE0_gccollectDll[var_s0], (u32)D_80800BE0_gccollectDll[var_s0 + 1]) != 0))
            {
                //Set Spawned Flag False
                collectable_setSpawnedFalse(D_80800BE0_gccollectDll[var_s0], D_80800BE0_gccollectDll[var_s0 + 1]);
            }
        }
    }
}

//Is the given item a virtual object (it is only spawned through code and does not exist in the map file)
s32 func_808002C4_gccollectDll(s32 arg0, s32 arg1)
{
    u32 var_s0;
    for (var_s0 = 0; var_s0 < 0x16; var_s0 += 2)
    {
        if ((arg0 == D_80800BE0_gccollectDll[var_s0]) && (arg1 == D_80800BE0_gccollectDll[var_s0 + 1]))
        {
            return 1;
        }
    }
    return 0;
}

s32 func_808003E0_gccollectDll(s32* arg0, s32* arg1)
{
    s32 foundSpawnFlag2;
    u32 size;
    s16* sp64;
    enum flag_e foundSpawnFlag;
    s32 jiggyMap;
    s32 activeJiggiesInCurrentMap;
    s16* var_s2;
    s32 levelIndexStart;
    f32 sp44[3];
    s32 itemIndex;

    activeJiggiesInCurrentMap = 0;
    //Gets the starting index for whatever the current level's jiggy index is so 0x1 for MT and 0xB for GGM
    levelIndexStart = func_800CF87C();
    itemIndex = levelIndexStart;
    for (itemIndex = levelIndexStart; itemIndex < (levelIndexStart + 0xA); itemIndex++)
    {
        //Have we collected this jiggy
        if (collectable_isCollected(itemIndex, TYPE_1_JIGGY) == 0)
        {
            //Get the spawn flag for the given item
            foundSpawnFlag = collectable_getSpawnFlag(itemIndex, TYPE_1_JIGGY);
            if (foundSpawnFlag != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
            {
                //Check if the current item index fits within the range allocated for the current level
                jiggyMap = func_800D0684(itemIndex, TYPE_1_JIGGY);
                //If we have a matching map, the item isn't a virtual object, and it has been spawned
                if ((map_getCurrent() == jiggyMap) && (func_808002C4_gccollectDll(itemIndex, TYPE_1_JIGGY) == 0) && (flag_getValue(foundSpawnFlag) != 0))
                {
                    activeJiggiesInCurrentMap += 1;
                }
            }
        }
    }
    size = activeJiggiesInCurrentMap * 8 + 2;

    sp64 = heap_realloc(arg0, *arg1 + size);
    if (size & 0xFFFFFFFFu)
    {
    }
    var_s2 = (s16*)((s32*)sp64 + *arg1);
    *var_s2 = activeJiggiesInCurrentMap;
    var_s2 += 2;

    activeJiggiesInCurrentMap = 0;

    for (itemIndex = levelIndexStart; itemIndex < (levelIndexStart + 0xA); itemIndex++, activeJiggiesInCurrentMap++)
    {
        //Item not collected
        if (collectable_isCollected(itemIndex, TYPE_1_JIGGY) == 0)
        {
            foundSpawnFlag2 = collectable_getSpawnFlag(itemIndex, TYPE_1_JIGGY);
            if (foundSpawnFlag2 != FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)
            {
                //Get the map at current item index fits within the range allocated for the current level
                jiggyMap = func_800D0684(itemIndex, TYPE_1_JIGGY);
                //If we have a matching map, the item isn't a virtual object, and it has been spawned
                if ((map_getCurrent() == jiggyMap) && (func_808002C4_gccollectDll(itemIndex, TYPE_1_JIGGY) == 0) && (flag_getValue(foundSpawnFlag2) != 0))
                {
                    var_s2[0] = activeJiggiesInCurrentMap;
                    var_s2++;

                    //Get the coords of the jiggy
                    collectable_getJiggyCoords(itemIndex, TYPE_1_JIGGY, sp44);
                    //Convert Float Coords
                    ml_vec3f_to_vec3s(var_s2, sp44);
                    var_s2 += 3;
                }
            }
        }
    }

    *arg1 = (s32*)var_s2 - (s32*)sp64;
    return sp64;
}

void func_808005BC_gccollectDll(u32 arg0, Prop* arg1)
{
    Actor* sp24;
    s32 sp18[3];

    sp18[0] = (s32)arg1->position[0];
    sp18[1] = (s32)arg1->position[1];
    sp18[2] = (s32)arg1->position[2];
    sp24 = func_80108C90(PROP_21F_JIGGY_REAL, sp18, 0U, NULL);
    func_800D053C(arg0, 1);
    func_800D05E4((s32)arg0, 1, sp24->unk0);
    func_800CFBC8(sp24, arg0, TYPE_1_JIGGY, 0);
    if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) 
    {
        actor_disableCollision(sp24);
    }
}

s32 func_80800660_gccollectDll(s16* arg0, s32* arg1)
{
    Prop* temp_s0_2;
    s16 temp_s2;
    s16 temp_s4;
    s16* temp_s0;
    s16* var_s0;
    s32 var_s3;
    u32 temp_a0;

    var_s3 = 0;
    temp_s0 = (s16*)&((s32*)arg0)[*arg1];
    temp_s4 = temp_s0[0];
    temp_s0 = temp_s0 + 2;
    for (var_s3 = 0; var_s3 < temp_s4; var_s3++)
    {
        temp_s2 = *temp_s0;
        temp_s0++;
        //Gets the starting index for the current level's jiggy index flag block
        temp_a0 = func_800CF87C() + temp_s2;
        //If Item is spawned but not collected
        if ((collectable_isSpawned(temp_a0, 1U) != 0) && (collectable_isCollected(temp_a0, 1U) == 0))
        {
            func_808005BC_gccollectDll(temp_a0, temp_s0);
        }
        temp_s0 = temp_s0 + 3;
    }
    *arg1 = (s32*)temp_s0 - (s32*)arg0;
    return arg0;
}

s32 gccollectDll_entrypoint_6(void* arg0, void* arg1)
{
    if (func_800CF87C() == -1)
    {
        return arg0;
    }
    if (func_800CF87C() == 0x5B)
    {
        return arg0;
    }
    return func_808003E0_gccollectDll(arg0, arg1);
}

s32 gccollectDll_entrypoint_7(s16* arg0, s32* arg1) {
    if (func_800CF87C() == -1) 
    {
        return arg0;
    }
    if (func_800CF87C() == 0x5B) 
    {
        return arg0;
    }
    return func_80800660_gccollectDll(arg0, arg1);
}

void func_808007D8_gccollectDll(Prop* arg0) 
{
    f32 sp24[3];

    if ((collectable_isSpawned((u32)arg0->FlagOrRotation, 1U) != 0) && (collectable_isCollected((u32)arg0->FlagOrRotation, 1U) == 0) && (func_800D0634((u32)arg0->FlagOrRotation, 1) == 0))
    {
        func_808005BC_gccollectDll((u32)arg0->FlagOrRotation, arg0);
        return;
    }
    ml_vec3s_to_vec3f(sp24, arg0->position);
    func_800D0778(arg0->FlagOrRotation, 1, &sp24);
}

Actor* func_80800890_gccollectDll(Prop* arg0, CollectableId arg1)
{
    s32 sp1C[3];
    s32 sp18;
    //If Item is spawned but not collected
    if ((collectable_isSpawned(arg0->FlagOrRotation, arg1) != 0) && (collectable_isCollected(arg0->FlagOrRotation, arg1) == 0))
    {
        sp1C[0] = (s32)arg0->position[0];
        sp1C[1] = (s32)arg0->position[1];
        sp1C[2] = (s32)arg0->position[2];
        sp18 = func_80108C90(D_80800C18_gccollectDll[arg1], sp1C, arg0->FlagOrRotation, arg0);
        if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) 
        {
            actor_disableCollision(sp18);
        }
        return sp18;
    }
    return 0;
}

void gccollectDll_entrypoint_8(s16* arg0)
{
    u32 sp34 = D_8012762C;
    Prop* var_s1;
    Prop* temp_v0;
    CollectableId var_s0;
    u32 temp_v0_2;
    Actor* var_s2;

    if ((func_800CF87C() != -1) && (arg0 != 0) && (func_800E9DC4(arg0) != 0))
    {
        var_s1 = func_800E9D68(arg0);
        temp_v0 = func_800E9D90(arg0);
        for (var_s1; var_s1 < temp_v0; var_s1++)
        {
            if (var_s1->unk6_1 == 6)
            {
                temp_v0_2 = var_s1->PropID;
                var_s2 = NULL;
                switch (temp_v0_2)
                {
                case PROP_1F5_JINJO_SPAWN:
                    var_s0 = TYPE_0_JINJO;
                    break;
                case PROP_1F6_JIGGY_SPAWN:
                    var_s0 = TYPE_1_JIGGY;
                    break;
                case PROP_1F7_HONEYCOMB_SPAWN:
                    var_s0 = TYPE_2_EMPTY_HONEYCOMB;
                    break;
                case PROP_1F8_GLOWBO_SPAWN:
                    var_s0 = TYPE_3_GLOWBO;
                    break;
                case PROP_201_CHEATOPAGE_SPAWN:
                    var_s0 = TYPE_4_CHEATO;
                    break;
                case PROP_29D_DOUBLOON_SPAWN:
                    var_s0 = TYPE_7_DOUBLOON;
                    break;
                case PROP_4E6_TICKET_SPAWN:
                    var_s0 = TYPE_8_TICKET;
                    break;
                default:
                    continue;
                }

                if (func_800CFFBC(var_s1->FlagOrRotation, var_s0) != 0)
                {
                    temp_v0_2 = func_800D06D4(var_s1->FlagOrRotation, var_s0);
                    if (temp_v0_2 == sp34 || temp_v0_2 == -1)
                    {
                        switch (var_s0)
                        {
                        case TYPE_1_JIGGY:
                            func_808007D8_gccollectDll(var_s1);
                            break;
                        case TYPE_3_GLOWBO:
                            var_s2 = func_80800890_gccollectDll(var_s1, var_s0);
                            if (var_s2 != NULL)
                            {
                                var_s2->unk74_7 = var_s1->unk6_7;
                            }
                            break;
                        case TYPE_0_JINJO:
                        case TYPE_2_EMPTY_HONEYCOMB:
                        case TYPE_4_CHEATO:
                        case TYPE_7_DOUBLOON:
                        case TYPE_8_TICKET:
                            var_s2 = func_80800890_gccollectDll(var_s1, var_s0);
                            break;
                        }
                        if (var_s2 != NULL)
                        {
                            func_800CFBC8(var_s2, var_s1->FlagOrRotation, var_s0, 0);
                        }
                    }
                }
            }
        }
    }
}
