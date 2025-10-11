#include "ch/glowbo.h"

#define GLOWBO_DATA(arg0) ((GlowboActorData*)(arg0->actorData))

extern u32 D_808013B0_chglowbo;
extern u32 D_80801420_chglowbo;
extern u32 D_80801430_chglowbo;
extern u32 D_8080143C_chglowbo;
extern u32 D_80801448_chglowbo;
extern u32 D_80801454_chglowbo;
extern s32 D_80801460_chglowbo[3];
extern f32 D_8080146C_chglowbo[18];
extern Vec3s32 D_808014B4_chglowbo;
extern u32 D_808014C0_chglowbo;
extern u32 D_80801508_chglowbo;
extern u32 D_80801540_chglowbo;
extern u32 D_80801588_chglowbo;
extern u32 D_808015D0_chglowbo;
extern f32 D_80801618_chglowbo;
extern u32 _chglowbo_entrypoint_5;

void func_80800000_chglowbo(Actor* arg0) 
{
    glowboStruct* temp_v0 = (glowboStruct*)func_80100094(arg0, 0U);
    s32 sp18[3] = D_80801460_chglowbo;

    if (temp_v0->unk16 == 1)
    {
        temp_v0->unk8 = (f32)(temp_v0->unk8 + 0.02f);
        if (temp_v0->unk8 > 1.0f)
        {
            temp_v0->unk8 = 1.0f;
            temp_v0->unk16 = 0U;
        }
    }
    else {
        temp_v0->unk8 = (f32)(temp_v0->unk8 - 0.02f);
        if (temp_v0->unk8 < 0.6f)
        {
            temp_v0->unk8 = 0.6f;
            temp_v0->unk16 = 1U;
        }
    }
    sp18[0] = (s32)sp18[0] * temp_v0->unk8;
    sp18[1] = (s32)sp18[1] * temp_v0->unk8;
    sp18[2] = (s32)sp18[2] * temp_v0->unk8;
    func_800C8E84(temp_v0->unk4, sp18);
}

void func_8080013C_chglowbo(Actor* arg0)
{
    glowboStruct* sp2C;

    sp2C = (glowboStruct*)func_80100094(arg0, 0U);
    if (arg0->scale == 2.0f)
    {

        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29)
    {

        arg0->unk74_17 = 1;
        arg0->scale = 0.75f;
    }
    else
    {
        arg0->scale = 0.4f;
    }
    if ((arg0->unk74_29) && (func_800DA298(FLAG_056_STATE_MEGA_GLOWBO) != 0))
    {
        func_800FFAB0(arg0);
        return;
    }

    if (_subaddieDll_entrypoint_1(arg0) == 0)
    {
        arg0->unk58 = 0.0f;
        func_80101FDC(arg0, 0xA);
        func_800EE7F8(&GLOWBO_DATA(arg0)->unk10, arg0->position);
    }
    else if (arg0->unk74_29)
    {
        arg0->unk58 = D_8080146C_chglowbo[0];
    }
    else
    {
        arg0->unk58 = D_8080146C_chglowbo[sp2C->unk0];
    }
    GLOWBO_DATA(arg0)->unkC = 100.0f;

    switch (func_800EA05C()) {
    case MAP_1A7_JRL_JOLLY_ROGERS_LAGOON:
    case MAP_1A8_JRL_ATLANTIS:
    case MAP_1A9_JRL_SEA_BOTTOM:

        arg0->unk64_19 = 1;
        sp2C->unk17 = _subaddiesect_entrypoint_1(arg0);
        break;

    }
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 1U), arg0->position);
}

void func_808002F4_chglowbo(Actor* arg0)
{
    glowboStruct* sp74;
    glowboStruct2* sp70;
    f32 gamespeed;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    sp74 = (glowboStruct*)func_80100094(arg0, 0U);
    sp70 = (glowboStruct2*)func_80100094(arg0, 1U);
    if ((!arg0->unk64_19) || (_subaddiesect_entrypoint_0(arg0, sp74->unk17, 0xB) != 0))
    {
        gamespeed = func_800D8FF8();
        if (arg0->unk7C_12 && (func_800DC298(0.05f) != 0))
        {
            func_800EFA4C(sp60, arg0->position[0] + func_800DC178(-30.0f, 30.0f), arg0->position[1] + func_800DC178(25.0f, 55.0f), arg0->position[2] + func_800DC178(-30.0f, 30.0f));
            _fxtwinkle_entrypoint_1(sp60, RED_SPARKLE);
        }
        func_8010D254(GLOWBO_DATA(arg0)->unk0);
        if (arg0->unk70_10 != 1)
        {
            switch (arg0->unk70_10)
            {
            case 2:
                if (_subaddierouteDll_entrypoint_4(arg0) != 0)
                {
                    if ((func_80090128() != 0) && ((func_8010C500(arg0) != 0) || (func_8010C710(arg0) < 0x9C400)))
                    {
                        arg0->unk54 = func_8010CD50(arg0, func_800F54E4()) - 180.0f;
                    }
                    else
                    {
                        _subaddierouteDll_entrypoint_6(arg0, sp70, sp74->unk14, 0x3F, 0.4f, 0x14, 0x28);
                    }
                    _subaddierouteDll_entrypoint_7(arg0, sp70, arg0->rotation[1], arg0->unk54, 75.0f, 0x4803);
                    sp74->unk14 = (u16)sp70->unk6;
                }
                _subaddierouteDll_entrypoint_5(arg0, sp70, sp74->unk14, 0.15f, 8.0f, 200.0f);
                if (func_8010CB84(arg0->position, 0x320) != 0)
                {
                    sp74->unk10 = (f32)arg0->unk58;
                }
                else
                {
                    sp74->unk10 = 100.0f;
                }
                GLOWBO_DATA(arg0)->unkC = func_800F15F8(GLOWBO_DATA(arg0)->unkC, sp74->unk10, gamespeed * 250.0f);
                func_801026CC(arg0, D_808014B4_chglowbo, GLOWBO_DATA(arg0)->unkC);
                func_8010C3A8(arg0, 0x305425, func_800F3780(func_80101F24(arg0), &D_808013B0_chglowbo, 3));
                if (sp74->unk4 != 0)
                {
                    func_800EE7F8(sp54, arg0->position);
                    sp54[1] += 150.0f;
                    func_800C8CB8(sp74->unk4, sp54);
                    func_80800000_chglowbo(arg0);
                }
                if (((sp74->unkC <= 0.0f) && (func_800DC298(0.1f) != 0)) && (func_8010CAC0(arg0->position, 0x5DCU) != 0))
                {
                    sp74->unkC = 4.0f;
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801420_chglowbo);
                }
                else
                {
                    sp74->unkC = (f32)(sp74->unkC - func_800D8FF8());
                }
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801430_chglowbo, 0.3f);
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_8080143C_chglowbo, 0.8f);
                break;

            case 0xa:
                func_800EE7F8(arg0->position, &GLOWBO_DATA(arg0)->unk10);
                func_800EF1B8(arg0->position, arg0->rotation[1] - 90.0f, arg0->unk74_7);
                arg0->rotation[1] += (func_800D8FF8() * 100.0f) * func_800F3780(func_80101F24(arg0), &D_808013B0_chglowbo, 3);
                if (sp74->unk4 != 0)
                {
                    sp48[0] = arg0->position[0];
                    sp48[1] = arg0->position[1] + 150.0f;
                    sp48[2] = arg0->position[2];
                    func_800C8CB8(sp74->unk4, sp48);
                    func_80800000_chglowbo(arg0);
                }
                if (func_80101E14(arg0, 0.3f) != 0)
                {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801430_chglowbo);
                }
                if (func_80101E14(arg0, 0.8f) != 0)
                {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080143C_chglowbo);
                }

            }

        }
        else
        {
            if (sp74->unk4 != 0)
            {
                func_800C8B84(sp74->unk4);
            }
            func_800FFAB0(arg0);
        }
    }
}

s32 func_80800880_chglowbo(Actor* arg0, s32 arg1, s32 arg2)
{
    glowboStruct* sp2C;

    sp2C = (glowboStruct*)func_80100094(arg0, 0U);
    switch (arg1)
    {
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        func_8010A5B0(arg0, func_800DA298(FLAG2_64E_UNK));
        break;
    case 0x3E:
        _fxsparkle_entrypoint_1(arg0->position, 6U);
        if (arg0->unk74_29) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xD03U, 0U, arg0->position, 0U);
            func_800DA544(FLAG_056_STATE_MEGA_GLOWBO);
            func_800D1844(0x54U);
        }
        else {
            _sudialog_entrypoint_0(0x2A, 0);
            func_800D0BD4(sp2C->unk0, 3U);
            func_800D1844(0x48U);
        }
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801454_chglowbo);
        func_80101FDC(arg0, 1U);
        if (sp2C->unk4) {
            func_800C8E54(sp2C->unk4, 0.0f, 0.0f);
            func_800C8FB0(sp2C->unk4, 0U, 0U, 0U);
        }
        break;
    case 0x13:
        sp2C->unk0 = arg2;
        break;
    case 0x55:
        sp2C->unk4 = func_800C8A98();
        func_800C8E54(sp2C->unk4, 100.0f, 750.0f);
        sp2C->unk16 = 1;
        sp2C->unk8 = 0.5f;
        break;
    default:
        return 0;
    }
    return 1;
}

u32* chglowbo_entrypoint_0(void) {
    return &D_808014C0_chglowbo;
}

void func_80800A48_chglowbo(Actor* arg0)
{
    glowboStruct* sp1C;
    s32 temp_v0;

    sp1C = (glowboStruct*)func_80100094(arg0, 0U);
    if (func_800EA05C() == MAP_157_IOH_WUMBA)
    {
        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29) //Set the Scale for Mega Glowbo
    {
        arg0->scale = 0.75f;
    }
    else //Set the Scale for Normal Glowbo
    {
        arg0->scale = 0.25f;
    }
    GLOWBO_DATA(arg0)->unkC = 100.0f;
    temp_v0 = func_800C8A98();
    sp1C->unk4 = temp_v0;
    func_800C8E54(temp_v0, 100.0f, 750.0f);
    sp1C->unk8 = 0.5f;
    sp1C->unk16 = 1;
}

void func_80800B10_chglowbo(Actor* arg0)
{
    glowboStruct* temp_v0 = (glowboStruct*)func_80100094(arg0, 0U);
    func_800BBCB8(arg0->position, 0, 1.0f, 1, &D_80801508_chglowbo);
    switch (arg0->unk70_10)
    {
    case 4:
        if (arg0->unk74_30)
        {
            func_80101FDC(arg0, 3U);
            return;
        }
    default:
        return;
    case 3:
        arg0->unk54 = func_800F1DF4(arg0->position, GLOWBO_DATA(arg0)->unk0);
        GLOWBO_DATA(arg0)->unk14 = func_800EFB8C(arg0->position, GLOWBO_DATA(arg0)->unk0) / 25.0f;
        GLOWBO_DATA(arg0)->unk1C = -80.0f;
        func_80801258_chglowbo(arg0);
        GLOWBO_DATA(arg0)->unk14 = 50.0f;
        arg0->unk6C_0 = 0;
        func_800C9C70(0.25f, 0x4DEU, 1.0f, 0x4650U, arg0->position, 500.0f, 2500.0f);
        func_80101FDC(arg0, 5U);
        return;
    case 5:
        func_80801258_chglowbo(arg0);
        if ((GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1]) || (GLOWBO_DATA(arg0)->unk14 > 0.0f))
        {
            GLOWBO_DATA(arg0)->unk14 += GLOWBO_DATA(arg0)->unk1C * func_800D8FF8();
            func_800EFCD8(&GLOWBO_DATA(arg0)->unk10, arg0->unk54, GLOWBO_DATA(arg0)->unkC);
            func_800EF04C(arg0->position, &GLOWBO_DATA(arg0)->unk10);
            arg0->unk6C_0 += 1;
        }
        else if (arg0->unk64_19)
        {
            func_80101FDC(arg0, 1U);
        }
        else
        {
            GLOWBO_DATA(arg0)->unk0[1] -= 75.0f;
            func_80101FDC(arg0, 6U);
        }
        arg0->rotation[0] += 18.0f;
        func_80800000_chglowbo(arg0);
        return;
    case 6:
        func_800C8FB0(temp_v0->unk4, 0, 0, 0);
        if ((s32)arg0->alpha >= 0xF)
        {
            arg0->alpha -= 0xF;
        }
        if (GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1])
        {
            arg0->position[1] += -6.0f;
            return;
        }
        if (GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1])
        {
            arg0->position[1] += -6.0f;
            return;
        }
        func_80101FDC(arg0, 7U);
        return;
    case 7:
        func_80101FDC(arg0, 1U);
        return;
    case 1:
        func_800C8B84(temp_v0->unk4);
        func_800FFAB0(arg0);
        break;
    }
}

u32* chglowbo_entrypoint_1(void) {
    return &D_80801540_chglowbo;
}

u32* chglowbo_entrypoint_2(void) {
    return &D_80801588_chglowbo;
}

void func_80800E28_chglowbo(Actor* arg0)
{
    f32 sp3C[3];

    if (func_800EA05C() == MAP_157_IOH_WUMBA)
    {
        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29) //Mega Glowbo Scale
    {
        arg0->scale = 0.75f;
    }
    else //Normal Glowbo Scale
    {
        arg0->scale = 0.25f;
    }
    arg0->rotation[1] = (func_80090010() + func_800DC178(-110.0f, 110.0f));
    func_8010D254(sp3C);
    func_800EEB9C(GLOWBO_DATA(arg0)->unk0, arg0->rotation[1], 400.0f);
    func_800EF04C(GLOWBO_DATA(arg0)->unk0, arg0->position);
    GLOWBO_DATA(arg0)->unk0[1] = (f32)(sp3C[1] + 20.0f);
    GLOWBO_DATA(arg0)->unk1C = -80.0f;
    GLOWBO_DATA(arg0)->unk14 = 30.0f;
    func_800C9C70(0.25f, 0x4DE, 0.5f, 0x4650, arg0->position, 500.0f, 2500.0f);
}

void func_80800F64_chglowbo(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 8:
        func_80801258_chglowbo(arg0);
        arg0->rotation[0] = (f32)(arg0->rotation[0] + 18.0f);
        if ((GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1]) || (GLOWBO_DATA(arg0)->unk14 > 0.0f))
        {
            GLOWBO_DATA(arg0)->unk14 += (GLOWBO_DATA(arg0)->unk1C * func_800D8FF8());
            func_800EF1B8(arg0->position, arg0->rotation[1], GLOWBO_DATA(arg0)->unkC);
            arg0->position[1] = (f32)(arg0->position[1] + GLOWBO_DATA(arg0)->unk14);
        }
        if ((arg0->position[1] <= GLOWBO_DATA(arg0)->unk0[1]) && (GLOWBO_DATA(arg0)->unk14 <= 0.0f))
        {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801448_chglowbo);
            arg0->position[1] = (f32)GLOWBO_DATA(arg0)->unk0[1];
            GLOWBO_DATA(arg0)->unk14 = 0.0f;
            GLOWBO_DATA(arg0)->unkC = 100.0f;
            arg0->rotation[0] = func_800136E4(arg0->rotation[0]);
            arg0->unk58 = 6.0f;
            func_80101FDC(arg0, 9);
            return;
        }
        return;
    case 9:
        arg0->rotation[0] += ((360.0f - arg0->rotation[0]) * 0.1f);
        if (func_8010B990(arg0, 0x501105) & 0x24)
        {
            _subaddiefade_entrypoint_3(arg0);
        }
        if (func_8010CAC0(arg0->position, 0x12CU) == 0)
        {
            _subaddiefade_entrypoint_3(arg0);
        }
        break;
    }
}

void func_80801118_chglowbo(Actor* arg0, s32 arg1)
{
    func_800DF5D8(0x80, 0x80, 0x80, _subaddiefade_entrypoint_0(arg0));
    func_80101870(arg0, arg1);
}

s32 func_8080115C_chglowbo(Actor* arg0, s32 arg1, u32 arg2) {
    if (arg1 == 0x4D) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}


u32* chglowbo_entrypoint_3(void) 
{
    return &D_808015D0_chglowbo;
}

void chglowbo_entrypoint_4(void)
{
    func_80108474(0x2A0, &D_80801618_chglowbo, func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_5(void) 
{
    f32 sp1C[3];
    func_8008FE94(1, sp1C);
    func_80108474(0x2A0U, sp1C, (s32)func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_6(void) 
{
    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_5);
}

void func_80801258_chglowbo(Actor* arg0)
{
    f32 sp44[3];
    f32 var_f20 = GLOWBO_DATA(arg0)->unk14;
    s32 var_s1 = 0;

    func_800EE7F8(sp44, arg0->position);

    while ((GLOWBO_DATA(arg0)->unk0[1] < sp44[1]) || (var_f20 > 0.0f))
    {
        var_f20 += GLOWBO_DATA(arg0)->unk1C * func_800D8FF8();
        var_s1++;
        sp44[1] = sp44[1] + var_f20;
    }

    GLOWBO_DATA(arg0)->unkC = func_800EFB8C(arg0->position, GLOWBO_DATA(arg0)->unk0);
    if (var_s1 > 0)
    {
        GLOWBO_DATA(arg0)->unkC = (f32)(GLOWBO_DATA(arg0)->unkC / (f32)var_s1);
        return;
    }
    GLOWBO_DATA(arg0)->unkC = 0.0f;
}