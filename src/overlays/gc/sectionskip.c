#include "gc/sectionskip.h"

s32 func_80800000_gcsectionskip(Vec3f*, Vec3f*, f32, s32);
void func_808002A0_gcsectionskip(s32, Prop*);
s32 func_80800D3C_gcsectionskip(MapId*, s32*);
void func_80800EF8_gcsectionskip(s32, s32);
extern u8 D_8012762C;
extern u8 D_80801040_gcsectionskip[];

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    u16 unk1A_5 : 11;
    u16 unk1A_0 : 5;
} UNKgcsectionskip_entrypoint_1arg4;

s32 func_80800000_gcsectionskip(Vec3f* arg0, Vec3f* arg1, f32 arg2, s32 arg3)
{
    f32 sp54[3];
    f32 temp_f2;
    f32 var_f20;
    f32 var_f22;
    s32 pad[2];
    f32 sp3C;
    f32 sp38;

    ml_vec3f_copy(sp54, arg0);
    if (arg3 == 0)
    {
        var_f20 = (arg1->f[0] + arg2) - arg0->f[0];
        if (arg2 < var_f20)
        {
            var_f20 -= 2.0f * arg2;
        }
        var_f22 = (arg1->f[2] + arg2) - arg0->f[2];
        if (arg2 < var_f22)
        {
            var_f22 -= 2.0f * arg2;
        }
        if (mlAbsF(var_f20) < mlAbsF(var_f22))
        {
            arg0->f[0] += var_f20;
        }
        else
        {
            arg0->f[2] += var_f22;
        }
    }
    else
    {
        var_f20 = (2.0f * arg2) / sqrtf(2.0f);
        sp3C = arg0->f[0] - arg1->f[0];
        sp38 = arg0->f[2] - arg1->f[2];

        temp_f2 = mlAbsF(sp3C) + mlAbsF(sp38);
        sp3C = (sp3C * var_f20) / temp_f2;
        sp38 = (sp38 * var_f20) / temp_f2;
        arg0->f[0] = arg1->f[0] + sp3C;
        arg0->f[2] = arg1->f[2] + sp38;
    }
    if (ml_vec3f_is_equal(sp54, arg0->f) != 0)
    {
        return 0;
    }
    return 1;
}

void func_8080019C_gcsectionskip(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32 arg4) {
    Vec3f sp64;
    Vec3f sp58;
    f32 temp;
    s32 i;
    ml_vec3f_copy(&sp64, arg1);
    for (i = 0; i < 4; i++) {
        temp = (f32)i / 4;
        // @fake
        if (i) {}
        func_800EFE50(&sp58, arg1, arg0, temp);
        if (func_80800000_gcsectionskip(&sp58, arg2, arg3, arg4) == 0) {
            break;
        }
        ml_vec3f_copy(&sp64, &sp58);
    }
    ml_vec3f_copy(arg1, &sp64);
}

void func_808002A0_gcsectionskip(s32 arg0, Prop* arg1)
{
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    Vec3f sp30;
    s32 sp2C;
    f32 temp_t9;



    if (arg1 != NULL)
    {
        sp2C = arg1->unk12_7;
        temp_t9 = arg1->unk6_7;
        func_800F5D9C(arg0, &sp30);
        func_800F5D70(arg0, &sp3C);
        ml_vec3f_apply_scale(&sp3C, time_getDelta());
        ml_getdiff_vec3f(&sp48, &sp30, &sp3C);
        ml_vec3s_to_vec3f(&sp54, arg1);
        func_8080019C_gcsectionskip(&sp48, &sp30, &sp54, temp_t9, sp2C);
        func_800F8418(arg0, &sp30);
    }
}

void func_80800374_gcsectionskip(s32 arg0, Prop* arg1) {
    func_800F7E3C(arg0, 0);
    func_808002A0_gcsectionskip(arg0, arg1);
}

void gcsectionskip_entrypoint_0(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0xDAA)
    {
        flag_setValueFalse(FLAG2_6C9_UNK);
    }
}


s32 gcsectionskip_entrypoint_1(Prop* arg0, MapId mapToEnter, s32 mapEntranceToUse, u32 arg3, UNKgcsectionskip_entrypoint_1arg4* arg4)
{
    s32 sp2C;
    s32 temp_v0;
    TransformationId sp24;
    u32 temp_a0;
    u32 sp1C;
    s32 currentSection;
    s32 nextSection;
    s32 Same;
    sp2C = 1;
    if (_gcgoto_entrypoint_15() != 0) {
        return 0;
    }
    temp_v0 = character_getActiveIndex();
    if ((arg4 != NULL) && (temp_v0 != (arg4->unk1A_5)))
    {
        return 0;
    }
    sp24 = character_getTransform(temp_v0);
    _gcgoto_entrypoint_0(&mapToEnter, &mapEntranceToUse);
    if ((func_800F6D24(temp_v0) != 0) || (func_800F8004((s32)temp_v0) != 0) || (func_800F6CC8(temp_v0) != 0) || (func_800F66F0(temp_v0) != 0) || (func_800F70BC(character_getActiveIndex()) != 0))
    {
        func_808002A0_gcsectionskip(temp_v0, arg0);
        return 0;
    }
    if (bs_getSplitStatus() == SPLIT_STATE_TALON_TORPEDO && sp24 == TRANSFORM_B_KAZOOIE)
    {

        func_800F7B9C(temp_v0, 0x88U);
        return 0;

    }
    else
    {
        switch (arg3)
        {
        case 0:
            if (func_800F4BE4(temp_v0) == 0)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 1:
            if (_chchuffycont_entrypoint_0(&mapToEnter, &mapEntranceToUse) == 0)
            {
                return 0;
            }
            break;
        case 2:
            if (_chchuffycont_entrypoint_1(&mapToEnter, &mapEntranceToUse) == 0)
            {
                return 0;
            }
            sp2C = 0;
            break;
        case 3:
            if (flag_getValue(FLAG_0B2_UNK) == 0)
            {
                return 0;
            }
            break;
        case 4:
            if (sp24 != TRANSFORM_1_BK)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 29:
            if (sp24 != TRANSFORM_1_BK)
            {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                func_800F7E3C(temp_v0, 0x1228);
                return 0;
            }
            break;
        case 5:
            if (sp24 != TRANSFORM_B_KAZOOIE)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 6:
            if (sp24 != TRANSFORM_A_BANJO)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            sp2C = 0;
            break;
        case 7:
            if (flag_getValue(FLAG_0B6_PROGRESS_JRL_UFO_LEFT_JRL) != 0)
            {
                return 0;
            }
            break;
        case 8:
            if (flag_getMultipleValue(FLAG3_A34_UNK, 3) != 0)
            {
                return 0;
            }
            break;
        case 14:
            mapEntranceToUse = D_80801040_gcsectionskip[flag_getMultipleValue(FLAG_3A4_RANDOMISER_JRL_DAVY_LOCKER_1, 4)];
            break;
        case 11:
            if (flag_getValue(FLAG_327_UNK) != 0)
            {
                mapEntranceToUse += 1;
            }
            break;
        case 12:
            if (func_800DA9E4(FLAG_409_RANDOMISER_CCL_SKULL_SET, 1) == 0)
            {
                flag_setValue(FLAG_40A_RANDOMISER_CCL_SKULL_1, rand_percentChance(0.5f) != 0 ? 0 : 1);
            }
            switch (map_getCurrent())
            {
            case MAP_136_CCL_CLOUD_CUCKOOLAND:
                switch (mapToEnter)
                {
                case MAP_13E_CCL_MUMBO:
                    if (flag_getValue(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                    {
                        mapToEnter = MAP_13F_CCL_MINGY_JONGO;
                    }
                    break;
                case MAP_13F_CCL_MINGY_JONGO:
                    if (flag_getValue(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                    {
                        mapToEnter = MAP_13E_CCL_MUMBO;
                    }
                    break;
                default:
                    return 0;
                }
                break;
            case MAP_13E_CCL_MUMBO:
                if (flag_getValue(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                {
                    mapEntranceToUse = 9;
                }
                break;
            case MAP_13F_CCL_MINGY_JONGO:
                if (flag_getValue(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0)
                {
                    mapEntranceToUse = 0x16;
                }
                break;
            }
            break;
        case 13:
            if (func_80800D3C_gcsectionskip(&mapToEnter, &mapEntranceToUse) == 0)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 9:
            if (sp24 != TRANSFORM_1_BK)
            {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            if (ability_getValue(ABILITY_1B_AIRBORNE_EGG_AIM) == 0)
            {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                func_80800EF8_gcsectionskip(0x10FB, 0x22);
                return 0;
            }
            break;
        case 16:
            if ((sp24 != TRANSFORM_1_BK) && (sp24 != TRANSFORM_8_STONY))
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            sp2C = 0;
            break;
        case 17:
            if (sp24 != TRANSFORM_C_SUB)
            {
                func_80800EF8_gcsectionskip(0x1219, 0x22);
                return 0;
            }
            break;
        case 18:
            if (sp24 == TRANSFORM_A_BANJO)
            {
                func_80800EF8_gcsectionskip(0x1545, 0xCB);
                return 0;
            }
            if (sp24 == TRANSFORM_B_KAZOOIE)
            {
                func_80800EF8_gcsectionskip(0x1544, 0xCB);
                return 0;
            }
            break;
        case 19:
            if (sp24 != TRANSFORM_8_STONY)
            {
                func_80800EF8_gcsectionskip(0xF56, 0xCB);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 20:
            if (sp24 != TRANSFORM_1_BK)
            {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                func_80800EF8_gcsectionskip(0x1221, 0x22);
                return 0;
            }
            if (ability_getValue(ABILITY_15_BREEGULL_BLASTER) == 0) {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                func_80800EF8_gcsectionskip(0x1227, 0x22);
                return 0;
            }
            if (ability_getValue(ABILITY_2E_EGGS_CLOCKWORK) == 0)
            {
                func_808002A0_gcsectionskip(temp_v0, arg0);
                func_80800EF8_gcsectionskip(0x122A, 0x22);
                return 0;
            }
            if ((flag_getValue(FLAG_044_RETRY_BOSS_HAG_1) != 0) && (flag_getValue(FLAG_043_PROGRESS_DEFEATED_HAG_1) == 0))
            {
                mapToEnter = 0x19A;
                mapEntranceToUse = 1;
            }
            break;
        case 21:
            if (flag_getValue(FLAG_360_PROGRESS_JINGALING_LIFE_SAPPED) != 0) {
                mapToEnter = 0x19B;
            }
            break;
        case 22:
            if (character_includedInTransformMask((s32)temp_v0, ALLOW_BANJO | ALLOW_KAZOOIE | ALLOW_BK) == 0)
            {
                func_80800EF8_gcsectionskip(0x1211, 0x6F);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 23:
            if (character_includedInTransformMask((s32)temp_v0, ALLOW_SUB | ALLOW_BK) == 0)
            {
                func_80800EF8_gcsectionskip(0x1223, 0x6F);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            if (((ability_getValue(ABILITY_1F_SUB_AQUA_EGG_AIM) == 0) || (ability_getValue(ABILITY_2D_EGGS_GRENADE) == 0)))
            {
                func_80800EF8_gcsectionskip(0x1226, 0x6F);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 24:
            if (sp24 == TRANSFORM_11_CLOCKWORK)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 25:
            temp_a0 = character_getActiveIndex();
            if (sp24 == TRANSFORM_11_CLOCKWORK)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            func_800F7C9C(temp_a0, 0x95, map_getCurrent(), 2);
            break;
        case 26:
            sp1C = character_getActiveIndex();
            if (sp24 == TRANSFORM_11_CLOCKWORK)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            func_800F7C9C(sp1C, 0x95, map_getCurrent(), 2);
            func_800F7B9C(sp1C, 0x96U);
            break;
        case 27:
            if (sp24 == TRANSFORM_11_CLOCKWORK)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            if (sp24 != TRANSFORM_1_BK)
            {
                if (func_800F7E3C(temp_v0, 0x1224) != 0)
                {
                    _chmrtannoy_entrypoint_0();
                }
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            if (ability_getValue(ABILITY_2D_EGGS_GRENADE) == 0)
            {
                if (func_800F7E3C(temp_v0, 0x122B) != 0)
                {
                    _chmrtannoy_entrypoint_0();
                }
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 28:
            if (sp24 == TRANSFORM_8_STONY)
            {
                func_80800374_gcsectionskip(temp_v0, arg0);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 30:
            if (sp24 == TRANSFORM_D_MUMBO)
            {
                func_800F7E3C(temp_v0, 0x1215);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 31:
            if ((flag_getValue(FLAG_360_PROGRESS_JINGALING_LIFE_SAPPED) == 0) && (flag_getValue(FLAG_03B_PROGRESS_FINISHED_TOWER_OF_TRAGEDY) == 0)) {
                func_800F7E3C(temp_v0, 0x1566);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        case 32:
            if (ability_getValue(ABILITY_2F_EGGS_ICE) == 0)
            {
                func_800F7E3C(temp_v0, 0x122C);
                func_808002A0_gcsectionskip(temp_v0, arg0);
                return 0;
            }
            break;
        default:
            break;
        }
    }
    if ((func_800D395C() != 0) || (func_800D3948() != 0))
    {
        func_808002A0_gcsectionskip(temp_v0, arg0);
        return 0;
    }
    if ((sp2C != 0) && (sp24 != TRANSFORM_1_BK))
    {
        currentSection = D_8012762C;
        nextSection = _gcsectionDll_entrypoint_4(mapToEnter);

        Same = (nextSection == currentSection) && (sp24 == TRANSFORM_D_MUMBO);

        if ((currentSection != nextSection) || ((currentSection == 0x1A) && (Same == 0)))
        {
            func_80800374_gcsectionskip(temp_v0, arg0);
            return 0;
        }

    }
    if (func_800A8264() != 0)
    {
        return 0;
    }
    _gcgoto_entrypoint_3(arg0, mapToEnter, mapEntranceToUse);
    return 1;
}

s32 func_80800D3C_gcsectionskip(MapId* arg0, s32* arg1)
{

    if (character_getTransform(character_getActiveIndex()) != 1)
    {
        return 0;
    }
    switch (map_getCurrent())
    {
    case MAP_AF_SM_SPIRAL_MOUNTAIN:
        if (flag_getValue(FLAG_318_PROGRESS_DEFEATED_KLUNGO_1) != 0)
        {
            *arg0 = MAP_142_JV_JINJO_VILLAGE;
            *arg1 = 3;
        }
        break;
    case MAP_142_JV_JINJO_VILLAGE:
        if (flag_getValue(FLAG_318_PROGRESS_DEFEATED_KLUNGO_1) != 0) {
            *arg0 = MAP_AF_SM_SPIRAL_MOUNTAIN;
            *arg1 = 3;
        }
        else {
            *arg1 = 1;
        }
        break;
    case MAP_15A_IOH_WASTELAND:
        if (flag_getValue(FLAG_319_PROGRESS_DEFEATED_KLUNGO_2) != 0) {
            *arg0 = MAP_154_IOH_PINE_GROVE;
            *arg1 = 3;
        }
        else {
            *arg1 = 1;
        }
        break;
    case MAP_154_IOH_PINE_GROVE:
        if (flag_getValue(FLAG_319_PROGRESS_DEFEATED_KLUNGO_2) != 0) {
            *arg0 = MAP_15A_IOH_WASTELAND;
            *arg1 = 1;
        }
        break;
    case MAP_15D_CK_CAULDRON_KEEP:
        if (flag_getValue(FLAG_31A_PROGRESS_DEFEATED_KLUNGO_3) != 0) {
            *arg0 = MAP_15F_CK_QUIZ;
            if (flag_getValue(FLAG_441_UNK) != 0) {
                *arg1 = 3;
            }
            else {
                *arg1 = 1;
            }
        }
        break;
    case MAP_15F_CK_QUIZ:
        if (flag_getValue(FLAG_31A_PROGRESS_DEFEATED_KLUNGO_3) != 0) {
            *arg0 = MAP_15D_CK_CAULDRON_KEEP;
            *arg1 = 2;
        }
        else {
            *arg1 = 1;
        }
        break;

    }
    return 1;
}

void func_80800EF8_gcsectionskip(s32 arg0, s32 arg1)
{
    func_800C05B8(arg0, 0, NULL, NULL, 0, 0, arg1);
}
