#include "ch/humba.h"

extern s32 D_80802590_chhumba;
extern s32 D_80802648_chhumba[];
extern s16 D_8080266E_chhumba[];
extern u32 D_80802684_chhumba;
extern f32 D_80802694_chhumba;
extern f32 D_808026F0_chhumba[3];
extern Vec3f D_808026FC_chhumba[];
extern s32 D_808026A0_chhumba;
extern f32 D_8080272C_chhumba;
extern ActorData D_80802738_chhumba;
extern ActorData D_80802780_chhumba;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
}HumbaActorData;
#define HUMBA_DATA(arg0) ((HumbaActorData*)(arg0->actorData))

void func_80800E44_chhumba(Actor*, u32);
void func_80801DB0_chhumba(Actor*, s32, s32);
void func_80801F74_chhumba(Actor*);

void func_80800000_chhumba(Actor* arg0, s32 arg1)
{
    _capod_entrypoint_2(arg0->unk0, 9U, arg1);
}

void func_80800028_chhumba(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg0->unk74_7) {
    case 0:
        func_80800000_chhumba(arg0, 0);
    case 1:
    case 3:
        _capod_entrypoint_8(1);
        arg0->unk74_7 = 2;
        _gcdialogcamera_entrypoint_6(arg0->unk0);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_12(0);
    case 2:
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}

void func_808000D4_chhumba(Actor* arg0, s32 arg1, s32 arg2, Unk80132ED0* arg3)
{
    switch (arg0->unk74_7)
    {
    case 0:
        func_80800000_chhumba(arg0, arg2);
    case 1:
    case 2:
        arg0->unk74_7 = 3;
    case 3:
        _capod_entrypoint_20(arg3, arg1, arg2);
        return;
    }
}

void func_8080015C_chhumba(Actor* arg0, s32 arg1, s32 arg2, Unk80132ED0* arg3)
{
    switch (arg0->unk74_7)
    {
    case 0:
        func_80800000_chhumba(arg0, arg2);
    case 2:
    case 3:
        arg0->unk74_7 = 1;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        return;
    }
}

void func_808001E4_chhumba(Actor* arg0)
{
    if ((flag_getValue(FLAG3_9C7_UNK) != 0) && (arg0->unk74_7 != 0))
    {
        _capod_entrypoint_3(0U);
        arg0->unk74_7 = 0;
    }
}

void func_80800238_chhumba(Actor* arg0, f32* arg1)
{
    ml_vec3f_assign_value(arg1, 0.0f, arg0->scale * 5.0f * -50.0f, 0.0f);
}

void func_80800294_chhumba(Actor* arg0, s32 arg1)
{
    if ((arg1 != 0) && (flag_getValue(FLAG3_9C8_UNK) != 0))
    {
        func_800904C8(0x8D);
    }
    if (map_getCurrent() != MAP_122_TDL_BIG_WUMBA)
    {
        if (arg1 != 0)
        {
            func_80090734(1, arg0->position);
            return;
        }
        if (flag_getValue(FLAG3_9C8_UNK) != 0)
        {
            func_80090708(0);
        }
    }
    else if (flag_getValue(FLAG3_9C8_UNK) != 0)
    {
        func_80090658(arg1);
    }
}

void func_80800338_chhumba(Actor* arg0, u32 arg1, u32 arg2)
{
    arg2 |= 4;
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x40U);
    arg0->unk74_30 = 1;
}

TransformationId func_80800384_chhumba(Actor* arg0)
{
    if (map_getCurrent() == MAP_122_TDL_BIG_WUMBA)
    {
        return TRANSFORM_13_TREXLARGE;
    }
    return D_80802648_chhumba[arg0->unk6C_0];
}

s16 func_808003CC_chhumba(Actor* arg0)
{
    if (map_getCurrent() == MAP_122_TDL_BIG_WUMBA)
    {
        return 0x11AA;
    }
    return D_8080266E_chhumba[arg0->unk6C_0];
}

s32 func_80800414_chhumba(Actor* arg0)
{
    if (map_getCurrent() == MAP_122_TDL_BIG_WUMBA)
    {
        return 0x346;
    }
    return (arg0->unk6C_0) + 0x346;
}

s32 func_80800450_chhumba(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;
    unkStruct80103CB8* temp_v0_2;
    u32 temp2;
    f32 sp20;
    u32 temp;
    switch (arg1)
    {
    case 0x49:
        func_80801F74_chhumba(arg0);
        break;
    case 0xA1:
        switch (arg0->unk70_10)
        {
        default:
            break;
        case 10:
            func_80800E44_chhumba(arg0, 0xB);
            break;
        case 15:
            func_80800E44_chhumba(arg0, 0x10);
            break;
        }
        return 1;
    case 0x3D:
        func_80800238_chhumba(arg0, &sp20);
        temp_v0 = func_801084B0(0x29F, &arg0);
        ml_vec3f_copy(temp_v0->actorData, &sp20);
        func_8010D254(temp_v0->position);
        temp_v0->unk74_30 = 1;
        arg0->unk3C = temp_v0->unk0;
        func_80800E44_chhumba(arg0, 6);
        break;
    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_80801DB0_chhumba(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
        break;
    case 0x2F:
        if (((s16*)&arg2)[1] == 1) {
            func_80090708(0);
            func_80090708(1);
        }
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80802684_chhumba, arg0->scale);
        return 1;
    case 0x57:
        if (_gcdialogcamera_entrypoint_0(arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 0x10) != 0)
        {
            if (arg0->unk74_7 != 2)
            {
                func_80800028_chhumba(arg0, 2, 1);
            }
            return 2;
        }
        return 1;
    case 0x32:
        switch (arg0->unk70_10)
        {
        case 17:
            func_80800338_chhumba(arg0, 0x11AF, 0xF);
            break;
        case 18:
            func_80800E44_chhumba(arg0, 0x12);
            break;
        default:
            func_800904C8(0x8D);
            if (arg0->unk74_29)
            {
                func_80800338_chhumba(arg0, 0x11BD, 0xF);
            }
            else
            {
                func_80800338_chhumba(arg0, 0x11A4, 0xF);
            }
            break;
        }
        break;
    case EVENT_1F_ACTOR_ONSCREEN:
        func_801015D0(arg0);
        temp_v0_2 = func_80103CB8(arg0, func_801039E4(arg0->unk0));
        temp_v0_2->unk0 = 1;
        func_800DF744(3, 0);
        func_800DF744(5, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_8080071C_chhumba(s32 arg0)
{
    switch (map_getCurrent())
    {
        case MAP_B6_MT_WUMBAS:
            return 1;
        case MAP_D5_WW_WUMBA:
            return 3;
        case MAP_E9_GGM_WUMBA:
            return 2;
        case MAP_11E_TDL_SMALL_WUMBA:
        case MAP_122_TDL_BIG_WUMBA:
            return 5;
        case MAP_120_JRL_WUMBA:
            return 4;
        case MAP_11F_GI_WUMBA:
            return 6;
        case MAP_135_HP_WUMBA:
            return 7;
        case MAP_140_CCL_WUMBA:
            return 8;
        case MAP_157_IOH_WUMBA:
            return 9;
        default:
            return 0;
    }
}

s32 func_808007EC_chhumba(s32 arg0)
{
    return 1;
}

void func_808007F8_chhumba(Actor* arg0)
{
    flag_setValueTrue((arg0->unk6C_0) + 0xD5);
    if (arg0->unk74_29)
    {
        inventory_addValue(0x54, -func_808007EC_chhumba((s32)arg0));
    }
    else
    {
        inventory_addValue(0x48, -func_808007EC_chhumba((s32)arg0));
    }
    arg0->unk64_20 = 1;
}

s32 func_80800878_chhumba(Actor* arg0)
{
    return flag_getValue((arg0->unk6C_0) + 0xD5);
}

s32 func_808008A0_chhumba(Actor* arg0)
{
    f32 sp24[3];
    Actor* sp20;
    sp20 = func_80106790(arg0->unk3C);
    func_80800238_chhumba(arg0, sp24);
    if ((sp20->position[1] < (-202.5f * arg0->scale)) && (func_800F0064(sp20->position, (arg0->scale * 1550.0f), sp24) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_80800934_chhumba(Actor* arg0, s32 arg1)
{
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];

    sp3C = arg0->scale * 500.0f;
    sp38 = arg0->scale * -500.0f;
    sp34 = arg0->scale * 1900.0f;
    sp30 = arg0->scale * 2950.0f;
    func_8010D254(sp24);
    if ((sp24[0] < sp38) || (sp3C < sp24[0]))
    {
        return 0;
    }
    if ((sp24[2] < sp34) || (sp30 < sp24[2]))
    {
        return 0;
    }
    if (func_8008FA60(arg1, 6) == 0)
    {
        return 0;
    }
    if (func_80090080() != 0) {
        if (func_80016B30(0U, 1U) != 0)
        {
            return 1;
        }
        func_800F5FE0(character_getActiveIndex());
    }

    return 0;
}

s32 func_80800A50_chhumba(Actor* arg0)
{
    f32 sp2C[3];
    f32 sp20[3];
    f32 temp_f0;

    func_80800238_chhumba(arg0, sp2C);
    sp2C[1] = 0.0f;
    func_8010D254(sp20);
    temp_f0 = arg0->scale;
    if (func_8010C9FC(sp2C, (s32)(temp_f0 * 1550.0f), (s32)(temp_f0 * -202.5f), (s32)(temp_f0 * -1237.5f)) == 0)
    {
        return 0;
    }
    if (func_800F71D4(character_getActiveIndex()) == 0) {
        return 0;
    }
    if ((map_getCurrent() == MAP_120_JRL_WUMBA) && (sp20[1] > -100.0f)) {
        return 0;
    }
    return 1;
}

void func_80800B40_chhumba(Actor* arg0)
{
    func_8080015C_chhumba(arg0, 0, 0x60, 0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(func_8010D5DC, arg0->unk0);
    func_8008F9F8(&arg0->actorData[4], 200.0f);
}

void func_80800BA8_chhumba(Actor* arg0, f32* arg1)
{
    f32 sp2C;
    f32 sp20[3];

    func_8010D254(sp20);
    func_800F1EA4(sp20, &sp2C);
    func_800EFCD8(arg1, func_800F1F38(sp2C, 0, 10.0f), arg0->scale * 2000.0f);
    arg1[1] = sp20[1];
}

s32 func_80800C20_chhumba(s32 arg0)
{
    f32 sp24;
    f32 sp18[3];

    func_8010D254(sp18);
    func_800F1EA4(sp18, &sp24);
    if (func_800F20BC(0.0f, sp24, 5.0f) == 0) 
    {
        return 1;
    }
    return 0;
}

void func_80800C6C_chhumba(Actor* arg0) 
{
    s32 sp1C[3];
    func_80800BA8_chhumba(arg0, sp1C);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(func_8010D5DC, arg0->unk0);
    func_8008F990((s32)&sp1C, 300.0f);
}

void func_80800CC8_chhumba(Actor* arg0)
{
    func_8008FB10(&D_80802694_chhumba, arg0->scale * 1600.0f, arg0->scale * 72.0f, arg0->scale * 350.0f);
}

s32 func_80800D2C_chhumba(Actor* arg0)
{
    if (func_800DA9E4(FLAG_0E2_UNK, 1) == 0)
    {
        func_80800338_chhumba(arg0, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

void func_80800D74_chhumba(Actor* arg0) 
{
    u32 temp_v0;
    s32 sp38;
    f32 sp2C[3];

    if (rand_f() < 0.1f)
    {
        temp_v0 = rand_iBounded(1, 3);
        sp38 = func_800B53A4(temp_v0);
        func_800EEB9C(sp2C, rand_fBounded(0.0f, 360.0f), rand_fBounded(0.0f, 1000.0f) * arg0->scale);
        sp2C[1] = -50.0f;
        func_800BABB8(sp38, sp2C, NULL, 1.0f, &D_808026A0_chhumba);
        func_800BA22C(sp38, temp_v0);
    }
}

void func_80800E44_chhumba(Actor* arg0, u32 arg1)
{
    f32 sp34[3];
    s32 temp;
    f32 sp24[3];

    switch (arg0->unk70_10)
    {
    case 2:
        break;
    case 3:
        func_80800294_chhumba(arg0, 0);
        break;
    case 5:
    case 6:
        func_80800238_chhumba(arg0, sp34);
        func_80090658(0);
        _fxsplash_entrypoint_1(sp34);
        _fxsplash25d_entrypoint_0(sp34);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802590_chhumba);
        func_808007F8_chhumba(arg0);
        func_800FC660(0xE);
        func_80800338_chhumba(arg0, 0x11B4, 0xF);
        break;
    }
    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10)
    {
    case 2:
        func_80800B40_chhumba(arg0);
        return;
    case 3:
        func_80800028_chhumba(arg0, 3, 1);
        func_80800294_chhumba(arg0, 1);
        return;
    case 18:
        if (func_80800C20_chhumba((s32)arg0) != 0)
        {
            func_80800C6C_chhumba(arg0);
            return;
        }
        func_80800E44_chhumba(arg0, 4U);
        return;
    case 4:
        func_80090658(1);
        return;
    case 5:
        func_80800238_chhumba(arg0, sp24);
        func_80090768(sp24);
        arg0->unk3C = func_8008FDEC();
        temp = func_80106790(arg0->unk3C);
        ml_vec3f_copy((f32*)((Actor*)temp)->actorData, sp24);
        ((Actor*)temp)->unk74_30 = 1;
        func_808000D4_chhumba(arg0, 0xE, 9, arg0->unk3C);
        return;
    case 6:
        func_808000D4_chhumba(arg0, 0xE, 9, arg0->unk3C);
        return;
    case 8:
        func_80090658(1);
        func_8080015C_chhumba(arg0, 2, 0x60, NULL);
        return;
    case 9:
        arg0->unk58 = 4.0f;
        func_800FC6B0(0xC);
        if ((arg0->unk74_29) && (bs_getDragonKazooieState() == 0))
        {
            bs_setDragonKazooieState(1);
            func_800907EC(activePlayer_getTransformation());
            return;
        }
        func_800907EC(func_80800384_chhumba(arg0));
        return;
    case 11:
        func_80090658(0);
        if (func_800DA9E4(func_80800414_chhumba(arg0), 1) == 0)
        {
            if (arg0->unk74_29) {
                func_80090708(2);
                temp = func_808003CC_chhumba(arg0);
                func_80800338_chhumba(arg0, temp, 3);
                return;
            }
            temp = func_808003CC_chhumba(arg0);
            func_80800338_chhumba(arg0, temp, 0xB);
            return;
        }
        if (func_80800D2C_chhumba(arg0) == 0)
        {
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 0xCU);
            return;
        }
    default:
        return;
    case 13:
        func_80090658(1);
        func_8080015C_chhumba(arg0, 5, 0x60, NULL);
        return;
    case 14:
        arg0->unk58 = 4.0f;
        func_800FC6B0(0xC);
        if ((arg0->unk74_29) && (bs_getDragonKazooieState() != 0))
        {
            bs_setDragonKazooieState(0);
            func_800907EC(activePlayer_getTransformation());
            return;
        }
        func_800907EC(TRANSFORM_1_BK);
        return;
    case 16:
        func_80090658(0);
        if (func_800DA9E4(FLAG_1D1_UNK, 1) == 0)
        {
            func_80800338_chhumba(arg0, 0x11B6, 0xF);
            return;
        }
        func_808001E4_chhumba(arg0);
        func_80800E44_chhumba(arg0, 7U);
        return;
    case 17:
        if (func_800DA9E4(FLAG_505_UNK, 1) == 0)
        {
            func_80800B40_chhumba(arg0);
        }
        break;
    }
}
void func_80801260_chhumba(Actor* arg0) 
{
    f32 sp44[3] = D_808026F0_chhumba;
    s32 index;

    f32 sp34[3];
    ml_vec3f_apply_scale(sp44, arg0->scale);
    activePlayer_getCoords(sp34);
    index = 0;
    for (index = 0; index < 3; index++)
    {
        sp34[index] = ((sp44[index] - sp34[index]) * 0.05f) + sp34[index];
    }
    func_800907C0(sp34);
    func_8008FF40(sp34);
    sp34[1] += func_800F1DCC(180.0f, sp34[1]) * 0.05f;
    sp34[0] += func_800F1DCC(0.0f, sp34[0]) * 0.05f;
    sp34[2] += func_800F1DCC(0.0f, sp34[2]) * 0.05f;
    func_800906DC(sp34);
}

void func_8080138C_chhumba(Actor* arg0)
{
    TransformationId currentTransformation;
    if (0) {}
    if (func_80800A50_chhumba(arg0) != 0 && (func_80090270() == 0)) {
        currentTransformation = activePlayer_getTransformation();
        if ((currentTransformation == TRANSFORM_1_BK) && ((bs_getDragonKazooieState() == 0) || !(arg0->unk74_29)))
        {
            func_80800E44_chhumba(arg0, 8);
            return;
        }
        if ((func_80800384_chhumba(arg0) == currentTransformation) || ((bs_getDragonKazooieState() != 0) && (arg0->unk74_29)))
        {
            func_80800E44_chhumba(arg0, 0xD);
        }
    }
}


void func_8080144C_chhumba(f32 arg0)
{
    s32 index;
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    f32 var_f20;
    f32 sp70[3];


    func_8010D254(sp8C);
    if (arg0 <= 1.0f)
    {
        var_f20 = 60.0f;
    }
    else
    {
        var_f20 = 100.0f;
    }
    for (index = 0; index < 4; index++)
    {
        func_800EFA20(sp98, D_808026FC_chhumba[index].f, arg0);
        ml_vec3f_copy(sp80, sp98);
        sp80[1] = 610.0f * arg0;
        ml_getdiff_vec3f(sp70, sp98, sp8C);
        if ((((sp70[0] * sp70[0]) + (sp70[2] * sp70[2])) < ((var_f20 + 25.0f) * (var_f20 + 25.0f))) && (sp98[1] < sp8C[1]) && (sp8C[1] <= sp80[1]))
        {
            func_800F7F50(character_getActiveIndex(), sp98, sp80, var_f20, 2, 1);
        }
    }
}

void func_808015DC_chhumba(Actor* arg0)
{
    f32 sp44[3];
    f32 sp38[3];
    s32 var_a2;
    s32 var_a1;

    _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0U);
    func_8080144C_chhumba(arg0->scale * 5.0f);
    if (func_800C0638() != 0)
    {
        HUMBA_DATA(arg0)->unkC = 1.5f;
    }
    else if (HUMBA_DATA(arg0)->unkC > 0.0f)
    {
        HUMBA_DATA(arg0)->unkC = (HUMBA_DATA(arg0)->unkC - time_getDelta());
    }
    if (func_80800878_chhumba(arg0) != 0)
    {
        func_80800D74_chhumba(arg0);
    }
    else if (HUMBA_DATA(arg0)->unkC <= 0.0f)
    {
        if (arg0->unk74_29)
        {
            inventory_showValue(0x54);
        }
        else
        {
            inventory_showValue(0x48);
        }
    }
    func_8008FB10(arg0->position, arg0->scale * 1350.0f, arg0->scale * 72.0f, arg0->scale * 350.0f);
    if (activePlayer_includedInTransformMask(ALLOW_CLOCKWORK) == 0)
    {
        switch (arg0->unk70_10)
        {
        case 1:
            if (map_getCurrent() == MAP_120_JRL_WUMBA) {
                func_8010D254(sp44);
                if ((sp44[1] > -30.0f) && (activePlayer_includedInTransformMask(ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 6) != 0)) {
                    func_80800E44_chhumba(arg0, 3);
                }
                if (func_80800934_chhumba(arg0, ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) {
                    func_80800E44_chhumba(arg0, 3);
                    return;
                }
            }
            else {
                if ((activePlayer_includedInTransformMask(ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 0) != 0)) {
                    func_80800E44_chhumba(arg0, 3);
                }
                if (func_80800934_chhumba(arg0, ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) {
                    func_80800E44_chhumba(arg0, 3);
                    return;
                }
            }
            break;
        case 3:
            if (!arg0->unk74_30)
            {
                if (arg0->unk74_29)
                {
                    if (inventory_getValue(0x54) >= func_808007EC_chhumba(arg0))
                    {
                        func_80800338_chhumba(arg0, 0x11BE, 0x4E);
                        return;
                    }
                    func_80800338_chhumba(arg0, 0x11BF, 0xF);
                    return;
                }
                if (inventory_getValue(0x48) >= func_808007EC_chhumba(arg0))
                {
                    func_80800338_chhumba(arg0, 0x11B0, 0x4E);
                    return;
                }
                func_80800338_chhumba(arg0, 0x11B3, 0xF);
                return;
            }
            break;
        case 18:
            func_80800BA8_chhumba(arg0, sp38);
            func_8008F964(sp38);
            func_80800CC8_chhumba(arg0);
            return;
        case 4:
            if (map_getCurrent() == MAP_120_JRL_WUMBA) {
                func_80108B04(arg0, 0U);
                return;
            }
            if (arg0->unk74_29)
            {
                var_a2 = 0x523;
            }
            else
            {
                var_a2 = 0x29F;
            }
            if (func_800902E4(arg0->position, 2500.0f, var_a2, &arg0) != 0)
            {
                if ((func_8008FE14() == var_a2) && (func_80090818() != 0)) {
                    func_80800E44_chhumba(arg0, 5);
                    return;
                }
            }
            break;
        case 5:
        case 6:
            if (func_808008A0_chhumba(arg0) != 0) {
                func_80800E44_chhumba(arg0, 7);
                return;
            }
            break;
        case 7:
            if (((activePlayer_includedInTransformMask(ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 6) != 0)) || (func_80800934_chhumba(arg0, 0x6C8E3) != 0)) {
                func_80800338_chhumba(arg0, 0x11B8, 0xF);
                return;
            }
            func_8080138C_chhumba(arg0);
            return;
        case 8:
            func_80800E44_chhumba(arg0, 9);
            return;
        case 9:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= time_getDelta();
                if ((arg0->unk64_20) && (arg0->unk58 < 1.5f)) {
                    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_4);
                    arg0->unk64_20 = 0;
                }
            }
            else if (func_800903D0(&HUMBA_DATA(arg0)->unk10) != 0)
            {
                func_800904F4(0x89, arg0->unk0);
                func_80800E44_chhumba(arg0, 0xA);
            }
            func_80801260_chhumba(arg0);
            return;
        case 12:
            if (((activePlayer_includedInTransformMask(ALLOW_TREXLARGE | ALLOW_TREXSMALL | ALLOW_VAN | ALLOW_SUB | ALLOW_DETONATOR | ALLOW_STONY | ALLOW_WASHINGMACHINE | ALLOW_BEE | ALLOW_SNOWBALL | ALLOW_BK) != 0) && (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 0) != 0)) || (func_80800934_chhumba(arg0, 0x6C8E3) != 0)) {
                func_80800338_chhumba(arg0, 0x11B9, 0xF);
                return;
            }
            func_8080138C_chhumba(arg0);
            return;
        case 13:
            func_80800E44_chhumba(arg0, 0xE);
            return;
        case 14:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= time_getDelta();
            }
            else if (func_800903D0(&HUMBA_DATA(arg0)->unk10) != 0)
            {
                func_800904F4(0x89, arg0->unk0);
                func_80800E44_chhumba(arg0, 0xF);
            }
            func_80801260_chhumba(arg0);
            return;
        case 17:
            if ((_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 0) != 0) || (func_80800934_chhumba(arg0, ALLOW_BANJO | ALLOW_KAZOOIE) != 0)) {
                func_80800338_chhumba(arg0, 0x11BC, 0xF);
                return;
            }
            if (!(arg0->unk64_19) && (func_80800A50_chhumba(arg0) != 0)) {
                arg0->unk64_19 = 1;
                func_80800338_chhumba(arg0, 0x11BA, 0xF);
                return;
            }
            break;
        case 19:
            if ((_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x15EU, 0x32U, 0) != 0) || (func_80800934_chhumba(arg0, ALLOW_BANJO | ALLOW_KAZOOIE) != 0)) {
                if (activePlayer_includedInTransformMask(ALLOW_BANJO) != 0)
                {
                    var_a1 = 0x121C;
                }
                else
                {
                    var_a1 = 0x121D;
                }
                func_80800338_chhumba(arg0, var_a1, 0xF);
                return;
            }
            if (!(arg0->unk64_19) && (func_80800A50_chhumba(arg0) != 0)) {
                arg0->unk64_19 = 1;
                func_80800338_chhumba(arg0, 0x11BB, 0xF);
            }
            break;
        }
    }
}

void func_80801DB0_chhumba(Actor* arg0, s32 arg1, s32 arg2)
{
    arg0->unk74_30 = 0;
    switch (arg1)
    {
        case 0x11AF:
            func_808001E4_chhumba(arg0);
            return;
        case 0x11A4:
        case 0x11BD:
            func_80800E44_chhumba(arg0, 3);
            return;
        case 0x11A5:
        case 0x11A6:
        case 0x11A7:
        case 0x11A8:
        case 0x11A9:
        case 0x11AA:
        case 0x11AB:
        case 0x11AC:
        case 0x11AD:
        case 0x11AE:
        case 0x11B7:
            if (func_80800D2C_chhumba(arg0) == 0)
            {
                func_800C0850();
                func_808001E4_chhumba(arg0);
                func_80800E44_chhumba(arg0, 0xC);
            }
            if (arg1 == 0x11B7) {
                func_80090708(0);
                return;
            }
        default:
            return;
        case 0x11B0:
        case 0x11BE:
            if (arg2 != 0) {
                func_80800338_chhumba(arg0, 0x11B1, 0xF);
                return;
            }
            func_80800338_chhumba(arg0, 0x11B2, 0xF);
            return;
        case 0x11B2:
            func_808001E4_chhumba(arg0);
            ml_vec3f_copy((f32*)arg0->actorData, arg0->position);
            func_80800E44_chhumba(arg0, 1);
            return;
        case 0x11B1:
            if (func_80800C20_chhumba((s32)arg0) != 0) {
                func_808001E4_chhumba(arg0);
            }
            func_808000D4_chhumba(arg0, 0xE, 0x40, NULL);
            func_80800E44_chhumba(arg0, 0x12);
            return;
        case 0x11B3:
        case 0x11BF:
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 1);
            return;
        case 0x11B5:
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 0xC);
            return;
        case 0x11B4:
            func_808001E4_chhumba(arg0);
            return;
        case 0x11B6:
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 7);
            break;
    }
}

void func_80801F74_chhumba(Actor* arg0)
{
    Prop* sp24;
    enum map_e currentMap;

    sp24 = _gccubesearch_entrypoint_1(0x226, arg0->position);
    currentMap = map_getCurrent();
    arg0->unk74_7 = 0;
    if (sp24 == NULL)
    {
        actor_mark_delete(arg0);
        return;
    }
    _gspropctrl_entrypoint_11(sp24, (f32*)&arg0->actorData[4]);
    arg0->unk6C_0 = func_8080071C_chhumba(arg0);
    _suexpression_entrypoint_7(arg0, 1U, 0x40U);
    _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0.0f, 0.0f);
    switch (currentMap)
    {
    case MAP_135_HP_WUMBA:
        func_800BF744(1, 1);
        break;
    case MAP_120_JRL_WUMBA:
        func_800BF744(2, 1);
        break;
    case MAP_157_IOH_WUMBA:
        arg0->unk74_29 = 1;
        break;
    }
    if (currentMap != MAP_135_HP_WUMBA) {
        func_80108474(0x381U, &D_8080272C_chhumba, 0);
    }
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80800E44_chhumba(arg0, 0x14);
        return;
    }
    switch (activePlayer_getTransformationBit())
    {
    case ALLOW_MUMBO:
        func_80800E44_chhumba(arg0, 0x11);
        return;
    case ALLOW_BANJO:
    case ALLOW_KAZOOIE:
        func_80800E44_chhumba(arg0, 0x13);
        return;
    default:
        if ((arg0->unk74_29) && (func_800DA9E4(FLAG_055_FTT_IoH_WumbasWigwam, 1) == 0))
        {
            func_80800E44_chhumba(arg0, 2);
            return;
        }
        if (!(arg0->unk74_29) && (func_800DA9E4(FLAG_08F_FTT_WUMBA, 1) == 0))
        {
            func_80800E44_chhumba(arg0, 2);
            return;
        }
        if (func_80800878_chhumba(arg0) != 0) {
            if ((activePlayer_getTransformation() == TRANSFORM_1_BK) && ((bs_getDragonKazooieState() == 0) || !(arg0->unk74_29)))
            {
                func_80800E44_chhumba(arg0, 7);
                return;
            }
            func_80800E44_chhumba(arg0, 0xC);
            return;
        }
        func_80800E44_chhumba(arg0, 1);
    case ALLOW_CLOCKWORK:
        return;
    }
}

void func_808021F4_chhumba(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
ActorData* chhumba_entrypoint_0(void) 
{
    return &D_80802738_chhumba;
}

void func_80802234_chhumba(Actor* arg0) 
{
    if (map_getCurrent() == MAP_122_TDL_BIG_WUMBA) 
    {
        arg0->scale = 2.0f;
        return;
    }
    arg0->scale = 1.0f;
}

ActorData* chhumba_entrypoint_1(void) 
{
    return &D_80802780_chhumba;
}
