#include "su/mole.h"

#define MOLE_DATA(arg0) ((MoleActorData*)(arg0->actorData))

extern u32 D_80802510_sumole;
extern u32 D_80802520_sumole;
extern s32 D_80802530_sumole[];
extern s32 D_8080254C_sumole[];
extern s32 D_8080255C_sumole[];
extern s32 D_8080256C_sumole[27];
extern s32 D_808025B4_sumole[];

extern s32 _sumole_entrypoint_21;
s32 sumole_entrypoint_17(Actor* arg0, s16 arg1, s32 arg2, s32 arg3);
Unk80132ED0* func_80802178_sumole(Actor* arg0);

s32 func_80800000_sumole(Actor* arg0, MoveData* arg1)
{
    return arg1[(s32)arg0->unk54].price;
}

void sumole_entrypoint_0(Actor* arg0, s32 arg1)
{
    Prop* temp_v0;

    temp_v0 = _gccubesearch_entrypoint_1(0x387U, arg0->position);
    if (temp_v0 == NULL)
    {
        func_800EE7F8(MOLE_DATA(arg0)->unk0, arg0->position);
        func_800EF1B8(MOLE_DATA(arg0)->unk0, arg0->rotation[1] - 90.0f, 200.0f);
    }
    else
    {
        _gspropctrl_entrypoint_11(temp_v0, MOLE_DATA(arg0)->unk0);
    }
    if ((arg0->unk3C == NULL) && !(arg0->unk64_20))
    {
        _chbaddiesetup_entrypoint_2(&_sumole_entrypoint_21, arg0->unk0, arg1);
        arg0->unk64_20 = 1;
    }
    _subaddieDll_entrypoint_4(arg0, 1U);
}

s32 sumole_entrypoint_1(Actor* arg0, s32 arg1, u32 arg2, s32 arg3)
{
    //Control who can talk to jamjars at all
    if (func_80090178(ALLOW_BK | ALLOW_BANJO | ALLOW_KAZOOIE | ALLOW_MUMBO | ALLOW_FIRSTPERSON) == 0)
    {
        return 0;
    }
    if ((arg2 != 0) && (func_8010CAC0(arg0->position, 0x177U) != 0) && ((arg3 == -1) || (func_800C6E38(arg3) == 0)))
    {
        func_800D2498(0xD0U, func_800D035C(6), 0U);
        func_800D2498(0xEAU, arg2, 0U);
    }
    if (_subaddiedialog_entrypoint_4(arg0->position, 0xFA, 0) != 0)
    {
        if (arg1 != -1)
        {
            arg0->unk70_10 = arg1;
        }
        arg0->unk6C_0 = 0;
        return 1;
    }
    return 0;
}

void func_808001E0_sumole(Actor* arg0, s32 arg1)
{
    f32 sp2C[3];


    func_800EE7F8(sp2C, arg0->position);
    func_800EF1B8(sp2C, arg0->rotation[1] + 15.0f, 150.0f);
    switch (arg1)
    {
    case 1:
        _gcdialogcamera_entrypoint_3(&D_80802510_sumole, arg0->scale);
        break;
    case 2:
    case 3:
        _gcdialogcamera_entrypoint_3(&D_80802520_sumole, arg0->scale);
        break;
    case 0:
        _gcdialogcamera_entrypoint_3((u32*)D_80802530_sumole, arg0->scale);
        break;
    }
    _capod_entrypoint_10(0U, arg0->position);
    _capod_entrypoint_11(0U, arg0->rotation);
    _capod_entrypoint_12(1);
    _gcdialogcamera_entrypoint_8();
    _capod_entrypoint_10(1U, sp2C);
}

void func_808002E0_sumole(Actor* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    switch (arg0->unk7A_11)
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 4U, 0x800);
    case 1:
        _capod_entrypoint_8(1);
        arg0->unk7A_11 = 2;
    case 2:
        func_808001E0_sumole(arg0, arg3);
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}

void func_8080037C_sumole(Actor* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u32 temp_t8;

    switch (arg0->unk7A_11)
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 4, 0x800);
    case 2:
        arg0->unk7A_11 = 1;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        return;
    }
}

void func_80800408_sumole(Actor* arg0)
{
    if (arg0->unk7A_11 != 0)
    {
        _capod_entrypoint_3(0U);
        arg0->unk7A_11 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mole/sumole_entrypoint_2.s")

typedef union {
    s32 i;
    struct { s16 s_0; s16 s_1; };
} Arg2;

s32 sumole_entrypoint_3(Actor* arg0, s32 arg1, Arg2 arg2, MoveData* arg3)
{
    s32 a1;
    Actor* temp_v0;
    Actor* sp24;
    s32 i;

    switch (arg1)
    {
    case 0x95:
        if (_glcutDll_entrypoint_20() != 0)
        {
            sumole_entrypoint_2(arg0, 0xC);
        }
        break;
    case 0x21:
        func_80101074(arg3);
        break;
    case 0x3D:
        switch (arg2.i)
        {
        case 4:
        case 5:
        case 6:
            temp_v0 = func_80108528(0xB7, MOLE_DATA(arg0)->unk0, (s32)arg0->rotation[1], &arg0);
            temp_v0->unk6C_0 = arg2.i - 4;
            func_8080037C_sumole(arg0, D_80802530_sumole[arg2.i], 0x6000, 0);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
            func_8080037C_sumole(arg0, D_8080254C_sumole[arg2.i], 0x6000, 0);
            _chappearfx_entrypoint_2(_chbounce_entrypoint_7(0x1D, MOLE_DATA(arg0)->unk0, D_8080255C_sumole[arg2.i]), 0x2A, 0, 1.0f);
            break;
        }
        break;
    case 0x2E:
        a1 = arg2.s_0;
        if (a1 == 0xD6C)
        {
            sumole_entrypoint_16(arg0, 0xD6C);
            if (arg2.s_1 == 1)
            {
                sumole_entrypoint_2(arg0, 7);
            }
            else
            {
                sumole_entrypoint_2(arg0, 6);
            }
        }
        else
        {
            sumole_entrypoint_16(arg0, a1);
        }
        break;
    case 0x2F:
        sp24 = func_80106790(arg0->unk3C);
        switch (arg2.s_1)
        {
        case 1:
            sp24 = sp24;
            if (_chmolehill_entrypoint_3(sp24) != 0)
            {
                _chmolehill_entrypoint_1(sp24, 5);
            }
            break;
        case 2:
            sp24 = sp24;
            if (_chmolehill_entrypoint_3(sp24) != 0)
            {
                _chmolehill_entrypoint_1(sp24, 6);
            }
            break;
        case 4:
            if (arg3[(s32)arg0->unk54].titleToShow > 0)
            {
                _chintrotext_entrypoint_1(0x18BB, arg3[(s32)arg0->unk54].titleToShow - 1, 0, 1);
            }
            break;
        case 5:
            for (i = 0; i < 27; i += 3) {
                if (D_8080256C_sumole[i + 0] == arg3[(s32)arg0->unk54].MoveTutorialDialog)
                {
                    func_80108B04(arg0, D_8080256C_sumole[i + 1]);
                }
            }
            break;
        }
        break;
    case 0xAC:
        if (arg3[(s32)arg0->unk54].unkF != 0)
        {
            return _ncpoddialog_entrypoint_8(func_80101080(), arg3[(s32)arg0->unk54].unkF);
        }
        return 3;
    case 0xB:
        switch (arg2.i)
        {
        case 30:
        case 37:
        case 0x42:
            func_808002E0_sumole(arg0, 2, 1, 2);
            return 4;
        case 7:
        case 13:
        case 15:
        case 33:
            func_808002E0_sumole(arg0, 2, 1, 2);
            if (func_800C6E38(0x18) != 0)
            {
                sumole_entrypoint_2(arg0, 0x11);
                return 4;
            }
            arg0->unk54 = 4.0f;
            sumole_entrypoint_2(arg0, 7);
        default:
            return 4;
        }
        break;
    case 0x30:
        return func_80800000_sumole(arg0, arg3);
    default:
        return 0;
    }
    return 1;
}

void sumole_entrypoint_4(Actor* arg0, MoveData* arg1)
{
    Actor* temp_v0;
    f32 temp_a1;
    s32 pad;
    s32 pad2;
    s32 var_v1;

    if (arg0->unk3C != NULL)
    {
        if (!(arg0->unk7A_8))
        {
            _subaddieDll_entrypoint_4(arg0, 0U);
            arg0->unk7A_8 = 1;
        }
        if (arg1[(s32)arg0->unk54].AbilityToLearn != -1)
        {
            var_v1 = arg1[(s32)arg0->unk54].AbilityToLearn == 0x18;
            if (var_v1 == 0)
            {
                var_v1 = func_800C6E38(arg1[(s32)arg0->unk54].AbilityToLearn) != 0;
            }
            if (var_v1 != arg0->unk74_29)
            {
                temp_v0 = func_80106790(arg0->unk3C);
                temp_v0->unk74_29 = var_v1;
                arg0->unk74_29 = var_v1;
            }
        }
        switch (arg0->unk70_10)
        {
        case 1:
            if (sumole_entrypoint_1(arg0, -1, func_80800000_sumole(arg0, arg1), (s32)arg1[(s32)arg0->unk54].AbilityToLearn) != 0)
            {
                if (sumole_entrypoint_5(arg0, arg1[(s32)arg0->unk54].charactersAllowed, -1, -1) != 0)
                {
                    if (func_800DA298(FLAG_40C_FTT_JAMJARS) == 0)
                    {
                        sumole_entrypoint_2(arg0, 3);
                        return;
                    }
                    if ((arg1[(s32)arg0->unk54].AbilityToLearn != -1) && (func_800C6E38((s32)arg1[(s32)arg0->unk54].AbilityToLearn) == 0))
                    {
                        var_v1 = func_80800000_sumole(arg0, arg1);
                        if (var_v1 > func_800D035C(6))
                        {
                            sumole_entrypoint_2(arg0, 0xE);
                            arg0->unk6C_0 = 0xF;
                            return;
                        }
                        sumole_entrypoint_7(arg0);
                        sumole_entrypoint_2(arg0, 3);
                        return;
                    }
                    sumole_entrypoint_2(arg0, 0xE);
                    arg0->unk6C_0 = 0xA;
                    return;
                }
                sumole_entrypoint_2(arg0, 0xE);
                if (func_80090178(ALLOW_BK | ALLOW_KAZOOIE | ALLOW_BANJO) != 0)
                {
                    if ((arg1[(s32)arg0->unk54].AbilityToLearn != -1) && (func_800C6E38(arg1[(s32)arg0->unk54].AbilityToLearn) == 0))
                    {
                        arg0->unk6C_0 = 2;
                        return;
                    }
                    arg0->unk6C_0 = 0xA;
                    return;
                }
                arg0->unk6C_0 = 2;
                return;
            }
            break;
        case 2:
            sumole_entrypoint_15(arg0, (s32)arg1[(s32)arg0->unk54].charactersAllowed, -1);
            return;
        case 4:
            sumole_entrypoint_17(arg0, (s16)arg1[(s32)arg0->unk54].CannotAffordDialog, -1, 0);
            return;
        case 7:
            sumole_entrypoint_17(arg0, (s16)arg1[(s32)arg0->unk54].MoveTutorialDialog, -1, 1);
            return;
        case 8:
            if (arg0->unk79_4 != 4)
            {
                sumole_entrypoint_19(arg0, 4);
            }
            sumole_entrypoint_18(arg0, 250.0f);
            if (sumole_entrypoint_20(arg0, (s32)(s8)arg1[(s32)arg0->unk54].unk11, -1) != 0)
            {
                sumole_entrypoint_2(arg0, 0x11);
                return;
            }
            break;
        case 10:
            sumole_entrypoint_17(arg0, (s16)arg1[(s32)arg0->unk54].AlreadyLearnedDialog, -1, 0);
            return;
        case 11:
            if (sumole_entrypoint_14(arg0) != 0)
            {
                sumole_entrypoint_2(arg0, 1);
                return;
            }
            break;
        case 3:
            if (sumole_entrypoint_8(arg0, -1) != 0)
            {
                if (func_800DA9E4(FLAG_40C_FTT_JAMJARS, 1) == 0)
                {
                    sumole_entrypoint_2(arg0, 0x10);
                    return;
                }
                if (func_800DA9E4(FLAG_424_FTT_JAMJARS_FIRST_LESSON_INTRO, 1) == 0)
                {
                    sumole_entrypoint_2(arg0, 0x13);
                    return;
                }
                sumole_entrypoint_2(arg0, 7);
                return;
            }
            break;
        case 16:
            sumole_entrypoint_17(arg0, 0xDB6, -1, 0);
            return;
        case 19:
            sumole_entrypoint_17(arg0, 0xDBE, -1, 0);
            return;
        case 5:
            sumole_entrypoint_17(arg0, 0xD6C, -1, 0);
            return;
        case 6:
            sumole_entrypoint_17(arg0, 0xD6D, -1, 0);
            return;
        case 14:
            if (sumole_entrypoint_10(arg0, -1) != 0) {
                sumole_entrypoint_2(arg0, arg0->unk6C_0);
                return;
            }
            break;
        case 15:
            sumole_entrypoint_17(arg0, arg1[(s32)arg0->unk54].CannotAffordDialog, -1, 0);
            return;
        case 9:
            sumole_entrypoint_17(arg0, 0xD6E, -1, 0);
            return;
        case 18:
            sumole_entrypoint_11(arg0);
            sumole_entrypoint_2(arg0, 0x15);
            return;
        case 21:
            if (sumole_entrypoint_12(arg0) != 0) {
                sumole_entrypoint_2(arg0, 1);
                return;
            }
            break;
        case 17:
            func_8008FBE0(1U);
            sumole_entrypoint_17(arg0, 0xDB7, -1, 0);
            return;
        case 20:
            var_v1 = func_8008FC00();
            if (var_v1 >= func_8008FC28())
            {
                if (_chmolehill_entrypoint_3(func_80106790(arg0->unk3C)) != 0)
                {
                    sumole_entrypoint_2(arg0, 9);
                    return;
                }
                sumole_entrypoint_2(arg0, 0x12);
                return;
            }
            MOLE_DATA(arg0)->unk18 -= func_800D8FF8();
            if (MOLE_DATA(arg0)->unk18 <= 0.0f)
            {
                temp_a1 = func_800F10B4((f32)(func_8008FC00() + 1), 1.0f, 10.0f, 0.8f, 1.5f);
                MOLE_DATA(arg0)->unk18 = 0.2f;
                func_800C3FC0(0x66C, temp_a1, 0x3E80);
                func_8008FC50();
                return;
            }
            break;
        case 12:
            sumole_entrypoint_2(arg0, 0xD);
            break;
        case 22:
            break;
        }
    }
}

s32 sumole_entrypoint_5(Actor* arg0, s32 arg1, AllowedTransformation arg2, s32 arg3)
{
    if (arg2 != -1)
    {
        if (arg1 == -1U)
        {
            arg0->unk70_10 = arg2;
        }
        else if (func_80090178(arg1) != 0)
        {
            arg0->unk70_10 = arg2;
        }
        else
        {
            arg0->unk70_10 = arg3;
        }
        return 0;
    }
    else
    {
        if (arg1 == -1U)
        {
            return 1;
        }
        if (func_80090178(arg1) != 0)
        {
            return 1;
        }
    }
    return 0;
}

s32 sumole_entrypoint_6(Actor* arg0, s32 arg1, f32 arg2)
{
    f32 sp1C[3];
    func_8010D254(sp1C);
    if (_subaddiedialog_entrypoint_0(arg0, (s32)arg2, 0) != 0)
    {
        if (arg1 != -1)
        {
            arg0->unk70_10 = arg1;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_7(Actor* arg0)
{
    _chmolehill_entrypoint_1(func_80106790(arg0->unk3C), 1);
}

s32 sumole_entrypoint_8(Actor* arg0, s32 arg1)
{
    Actor* sp1C;

    sp1C = func_80106790(arg0->unk3C);
    if ((func_800C064C() == -1) && ((sp1C->unk64_19) == 1) && (sp1C->unk3C != NULL))
    {
        if (arg1 != -1)
        {
            arg0->unk70_10 = arg1;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_9(Actor* arg0)
{
    _chmolehill_entrypoint_1(func_80106790(arg0->unk3C), 3);
}

s32 sumole_entrypoint_10(Actor* arg0, s32 arg1)
{
    Actor* sp1C;

    sp1C = func_80106790(arg0->unk3C);
    if ((func_800C064C() == -1) && ((sp1C->unk64_19) == 1) && (sp1C->unk3C != NULL))
    {
        if (arg1 != -1)
        {
            arg0->unk70_10 = arg1;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_11(Actor* arg0)
{
    _chmolehill_entrypoint_1(func_80106790(arg0->unk3C), 4);
}

s32 sumole_entrypoint_12(Actor* arg0)
{
    if ((func_80106790(arg0->unk3C)->unk70_10) == 1)
    {
        return 1;
    }
    return 0;
}

void sumole_entrypoint_13(Actor* arg0)
{
    _chmolehill_entrypoint_1(func_80106790(arg0->unk3C), 2);
}

s32 sumole_entrypoint_14(Actor* arg0)
{
    if ((func_80106790(arg0->unk3C)->unk70_10) == 1)
    {
        return 1;
    }
    return 0;
}

s32 sumole_entrypoint_15(Actor* arg0, s32 arg1, s32 arg2)
{
    s16 var_a1;
    s16 sp1E;

    var_a1 = func_800DC128(0xD7B, 0xD7D);
    switch (arg1)
    {
        case ALLOW_BANJO: //Banjo Moves
            sp1E = var_a1;
            if (func_8010D278() == TRANSFORM_B_KAZOOIE)
            {
                //Randomize kazooie Refusal message to use for Banjo Move
                var_a1 = func_800DC128(0xD71, 0xD73);
            }
            else
            {
                sp1E = var_a1;
                if (func_8010D278() == TRANSFORM_1_BK)
                {
                    //Randomize message saying to get rid of kazooie
                    var_a1 = func_800DC128(0xD6F, 0xD71);
                }
            }
            break;
        case ALLOW_KAZOOIE: //Kazooie Moves
            sp1E = var_a1;
            if (func_8010D278() == TRANSFORM_A_BANJO)
            {
                //Randomize Banjo Refusal message to use for Kazooie Move
                var_a1 = func_800DC128(0xD73, 0xD75);
            }
            else
            {
                sp1E = var_a1;
                if (func_8010D278() == TRANSFORM_1_BK)
                {
                    //Randomize message saying to get rid of Banjo
                    var_a1 = func_800DC128(0xD75, 0xD77);
                }
            }
            break;
        case ALLOW_BK: //BK Moves
            sp1E = var_a1;
            if (func_8010D278() == TRANSFORM_B_KAZOOIE)
            {
                //Randomize Kazooie Refusal message to use for BK Move
                var_a1 = func_800DC128(0xD79, 0xD7B);
            }
            else
            {
                sp1E = var_a1;
                if (func_8010D278() == TRANSFORM_A_BANJO)
                {
                    //Randomize Banjo Refusal message to use for BK Move
                    var_a1 = func_800DC128(0xD77, 0xD79);
                }
            }
            break;
    }
    return sumole_entrypoint_17(arg0, var_a1, arg2, 0);
}

void sumole_entrypoint_16(Actor* arg0, s32 arg1)
{
    MoveData* temp_v0;
    s32 sp28;

    func_8010114C((s32)arg0->unk0, 0x21, 0);
    temp_v0 = (MoveData*)func_80101080();
    arg0->unk58 = 0.0f;
    switch (arg0->unk70_10)
    {
    case 16:
        if (temp_v0[(s32)arg0->unk54].AbilityToLearn != -1)
        {
            if (func_800C6E38(temp_v0[(s32)arg0->unk54].AbilityToLearn) == 0)
            {
                if (func_80800000_sumole(arg0, temp_v0) > func_800D035C(6))
                {
                    sumole_entrypoint_2(arg0, 0xF);
                    return;
                }
                if (func_800DA9E4(FLAG_424_FTT_JAMJARS_FIRST_LESSON_INTRO, 1) == 0)
                {
                    sumole_entrypoint_2(arg0, 0x13);
                    return;
                }
                sumole_entrypoint_2(arg0, 7);
                return;
            }
        }
        sumole_entrypoint_2(arg0, 0xA);
        return;
    case 2:
        if (func_80090178(ALLOW_BK | ALLOW_KAZOOIE | ALLOW_BANJO) != 0)
        {
            sumole_entrypoint_2(arg0, 0x11);
            return;
        }
        sumole_entrypoint_11(arg0);
        sumole_entrypoint_2(arg0, 0x15);
        return;
    case 15:
        sumole_entrypoint_2(arg0, 0x11);
        return;
    case 4:
        sumole_entrypoint_2(arg0, 5);
        return;
    case 6:
        sumole_entrypoint_2(arg0, 0x11);
        return;
    case 19:
        if (func_80800000_sumole(arg0, temp_v0) > func_800D035C(6))
        {
            sumole_entrypoint_2(arg0, 0xF);
            return;
        }
        sumole_entrypoint_2(arg0, 7);
        return;
    case 10:
        if (_chmolehill_entrypoint_3(func_80106790(arg0->unk3C)) == 0)
        {
            func_800C0850();
        }
        sumole_entrypoint_2(arg0, 0x11);
        return;
    case 17:
        if (_chmolehill_entrypoint_3(func_80106790(arg0->unk3C)) == 0)
        {
            func_800C0850();
        }
        sumole_entrypoint_2(arg0, 0x14);
        return;
    case 9:
        sumole_entrypoint_2(arg0, 0xB);
        return;
    case 7:
        func_800FC6B0(0x10U);
        if (temp_v0[(s32)arg0->unk54].AbilityToLearn != -1)
        {
            func_800C7074((s32)temp_v0[(s32)arg0->unk54].AbilityToLearn, func_800DA298(FLAG2_660_UNK));
        }
        for (sp28 = 0; sp28 < 8; sp28++) {
            if (D_808025B4_sumole[sp28 * 2 + 0] == (s16)temp_v0[(s32)arg0->unk54].MoveTutorialDialog)
            {
                func_80108B04(arg0, D_808025B4_sumole[sp28 * 2 + 1]);
                sumole_entrypoint_2(arg0, 0x16);
                break;
            }
        }
        if (sp28 >= 8U)
        {
            sumole_entrypoint_2(arg0, 0x11);
        }
        return;
    default:
        return;
    }
}

s32 sumole_entrypoint_17(Actor* arg0, s16 message, s32 arg2, s32 arg3)
{
    Unk80132ED0* temp_a3;
    Unk80132ED0* temp_v0;
    s32 var_v1;

    temp_v0 = func_80802178_sumole(arg0);
    temp_a3 = temp_v0;
    switch ((s32)arg0->unk58)
    {
    case 0:
        if (temp_v0 != NULL)
        {
            func_800C05B8(message, 7, arg0->position, temp_a3, 0, 0, 0);
        }
        else
        {
            func_800C05B8(message, 7, arg0->position, NULL, 0, 0, func_800DA298(FLAG_578_PROGRESS_BOTTLES_ENERGY_RESTORED) != 0 ? 0xF : 0x84);
        }
        arg0->unk58 = 1.0f;
    default:
        break;
    case 1:
        if (func_800C064C() == message)
        {
            arg0->unk58 = 2.0f;
        }
        break;
    case 2:
        if (func_800C064C() == -1)
        {
            arg0->unk58 = 0.0f;
            if (arg2 != -1)
            {
                arg0->unk70_10 = arg2;
            }
            return 1;
        }
        break;
    }
    return 0;
}

void sumole_entrypoint_18(Actor* arg0, f32 arg1)
{
    f32 sp2C[3];
    f32 temp_f0;

    if ((arg0->unk6C_0 == 2) || (arg0->unk6C_0 == 4))
    {
        func_8010D254(sp2C);
        func_800EF3DC(sp2C, arg0->position);
        temp_f0 = func_800EEF94(sp2C);
        if (temp_f0 != 0.0f)
        {
            temp_f0 = arg1 / temp_f0;
            if (temp_f0 < 1.0f)
            {
                func_800EF334(sp2C, temp_f0);
                func_800EF04C(sp2C, arg0->position);
                func_800907C0(sp2C);
            }
        }
    }
}

void sumole_entrypoint_19(Actor* arg0, s32 arg1)
{
    if (arg1 != arg0->unk79_4)
    {
        switch (arg0->unk79_4)
        {
        case 0:
            switch (arg1)
            {
            case 1:
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            case 2:
                func_8010D254(arg0->position);
                arg0->unk79_4 = arg1;
                return;
            case 3:
                func_80090734(1, arg0->position);
                arg0->unk79_4 = arg1;
                return;
            case 4:
                arg0->unk79_4 = arg1;
                return;
            }
            break;
        case 1:
            switch (arg1)
            {
            case 0:
                func_80090708(0);
                arg0->unk79_4 = arg1;
                break;
            case 2:
                func_8010D254(arg0->position);
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            case 3:
                func_80090708(0);
                func_80090734(1, arg0->position);
                arg0->unk79_4 = arg1;
                return;
            case 4:
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            }
            break;
        case 2:
            switch (arg1)
            {
            case 0:
                arg0->unk79_4 = arg1;
                return;
            case 1:
                func_80090708(1);
                arg0->unk79_4 = arg1;
                break;
            case 3:
                func_80090734(1, arg0->position);
                arg0->unk79_4 = arg1;
                return;
            case 4:
                arg0->unk79_4 = arg1;
                return;
            }
            break;
        case 3:
            switch (arg1)
            {
            case 0:
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            case 1:
                func_80090708(0);
                func_80090708(1);
                return;
            case 2:
                func_8010D254(arg0->position);
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            case 4:
                func_80090708(0);
                arg0->unk79_4 = arg1;
                return;
            }
            break;
        case 4:
            switch (arg1)
            {
            case 0:
                arg0->unk79_4 = arg1;
                return;
            case 1:
                func_80090708(1);
                arg0->unk79_4 = arg1;
                return;
            case 2:
                arg0->unk79_4 = arg1;
                return;
            case 3:
                func_80090734(1, arg0->position);
                arg0->unk79_4 = arg1;
                break;
            }
            break;
        }
    }
}

s32 sumole_entrypoint_20(Actor* arg0, s32 arg1, s32 arg2)
{
    if (func_800C6E18(arg1) != 0)
    {
        if (arg2 != -1)
        {
            arg0->unk70_10 = arg2;
        }
        return 1;
    }
    return 0;
}

Unk80132ED0* func_80802178_sumole(Actor* arg0)
{
    Actor* temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x18F, -1, 0);
    if (temp_v0 != NULL)
    {
        return temp_v0->unk0;
    }
    return 0;
}

void sumole_entrypoint_21(Unk80132ED0* arg0, s32 arg1)
{
    Actor* sp24;
    Actor* sp20;
    Actor* temp_v0;
    if (&arg0) {}

    sp24 = func_80106790(arg0);
    temp_v0 = func_801084B0(0x247, &sp24);
    sp20 = temp_v0;
    sp24->unk3C = temp_v0->unk0;
    _chmolehill_entrypoint_4(temp_v0, sp24->unk0);
    func_80108944(sp20, sp24);
    if (arg1 != 0)
    {
        func_80103140(sp20, 0x629U, sp24->unk0->unk16);
    }
}