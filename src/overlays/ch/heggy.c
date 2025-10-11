#include "ch/heggy.h"

extern s32 D_80801E08_chheggy;
extern s32 D_80801E38_chheggy;
extern s32 D_80801E60_chheggy;
extern u32 D_80801E8C_chheggy;
extern s32 D_80801E9C_chheggy;
extern s32 D_80801EE4_chheggy[14];
extern s32 D_80801F1C_chheggy[15];
extern s32 D_80801F58_chheggy;

extern void* func_8010D5DC;

void func_80800ECC_chheggy(Actor*, s32);

void func_80800000_chheggy(Actor* arg0, Unk80100094* arg1, s32 arg2)
{
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F904(&func_8010D5DC, arg0->unk0);
    func_8008F938(1);
    func_8008F990(arg1->unk0[arg2].f, 500.0f);
}

s32 func_8080006C_chheggy(void) 
{
    return
        (func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0 ? 1 : 0) +
        (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0 ? 1 : 0);
}

s32 func_808000C0_chheggy(Actor* arg0)
{
    f32 sp24;

    sp24 = arg0->rotation[1];
    func_80105A9C(arg0, func_800F3780(func_80101F24(arg0), &D_80801E08_chheggy, 6) * 500.0f);
    func_80105834(arg0);
    arg0->unk54 = arg0->rotation[1];
    arg0->rotation[1] = sp24;
    func_80102BAC(arg0, 0.1f, 0.1f, 6.0f);
    return func_80105A5C(arg0);
}

void func_8080015C_chheggy(Actor* arg0)
{
    f32 sp6C[3];
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    f32 sp48[3];
    f32 sp3C[3];

    sp68 = 0;
    sp64 = 0;
    sp60 = 0;
    sp5C = 0;
    switch (func_801022E4(arg0))
    {                              /* irregular */
    case 0x4A5:
        sp5C = func_80101E14(arg0, 0.0f) != 0 || func_80101E14(arg0, 0.8f) != 0;
        sp60 = func_80101E14(arg0, 0.35f);
        sp64 = func_80101E14(arg0, 0.45f) != 0 || func_80101E14(arg0, 0.5f) != 0 || func_80101E14(arg0, 0.56f) != 0;
        break;
    case 0x4A7:
        sp64 = func_80101E14(arg0, 0.4f) != 0 || func_80101E14(arg0, 0.9f) != 0;
        if (func_80101E14(arg0, 0.0f) != 0)
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x2F, sp6C);
            sp68 = 1;
        }
        else if (func_80101E14(arg0, 0.5f) != 0)
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x2C, sp6C);
            sp68 = 1;
        }
        break;
    case 0x4A6:
        sp5C = func_80101E14(arg0, 0.07f);
        sp60 = func_80101E14(arg0, 0.88f);
        sp64 = func_80101E14(arg0, 0.46f) != 0 || func_80101E14(arg0, 0.54f) != 0 || func_80101E14(arg0, 0.6f) != 0;
        if (func_80101E14(arg0, 0.035f) != 0)
        {
            func_800EE7F8(sp6C, arg0->position);
            sp68 = 1;
        }
        else if (func_80101E14(arg0, 0.92f) != 0)
        {
            func_800EE7F8(sp6C, arg0->position);
            sp68 = 1;
        }
        break;
    }
    if (sp68 != 0)
    {
        sp58 = func_800B53A4(2);
        sp54 = func_800B53A4(3);
        func_800EEC30(sp48, 10.0f, arg0->rotation[1] - 180.0f, 50.0f);
        func_800EEC30(sp3C, 25.0f, arg0->rotation[1] - 180.0f, 150.0f);
        func_800BA930(sp58, (s16)sp48[0], (s16)sp48[1], (s16)sp48[2], sp3C[0], sp3C[1], sp3C[2]);
        func_800BA930(sp54, (s16)sp48[0], (s16)sp48[1], (s16)sp48[2], sp3C[0], sp3C[1], sp3C[2]);
        func_800EF334(sp48, -0.5f);
        func_800EF334(sp3C, -0.5f);
        func_800BA450(sp58, (s16)sp48[0], -0xC8, (s16)sp48[2], sp3C[0], -0x190, sp3C[2]);
        func_800BA450(sp54, (s16)sp48[0], -0xC8, (s16)sp48[2], sp3C[0], -0x190, sp3C[2]);
        func_800BABB8(sp58, sp6C, NULL, 1.0f, &D_80801E38_chheggy);
        func_800BA22C(sp58, 2);
        func_800BABB8(sp54, sp6C, NULL, 1.0f, &D_80801E60_chheggy);
        func_800BA22C(sp54, 3);
        func_800C4140(0xA62FA404, arg0->position, 0x0FA00064);
    }
    if (func_800C0638() == 0)
    {
        if (sp64 != 0)
        {
            func_800C4140(((func_800DC0C0() < 0.5f) ? 0x674 : 0x675) + 0x7FEBB800, arg0->position, 0x0FA00064);
        }
        if (sp60 != 0)
        {
            func_800C4140(0x7FEBBE76, arg0->position, 0x0FA00064);
        }
        if (sp5C != 0)
        {
            func_800C4140(0x7FEBBE77, arg0->position, 0x0FA00064);
        }
    }
}

void func_808006C4_chheggy(Actor* arg0, Unk80132ED0* arg1, s32 arg2, s32 arg3)
{

    switch (arg0->actorData[4])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x28U, 0);
    case 1:
        arg0->actorData[4] = 2;
    case 3:
        arg0->actorData[4] = 2;
    case 2:
        _capod_entrypoint_6(arg1, arg2, arg3);
        return;
    }
}

void func_80800750_chheggy(Actor* arg0, Unk80132ED0* arg1, s32 arg2, s32 arg3)
{
    switch (arg0->actorData[4])
    {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x28U, 0);
        case 1:
        case 2:
            arg0->actorData[4] = 3;
        case 3:
            _capod_entrypoint_20(arg1, arg2, arg3);
            return;
    }
}

void func_808007D4_chheggy(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg0->actorData[4])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x28U, 0);
    case 2:
    case 3:
        arg0->actorData[4] = 1;
        _capod_entrypoint_8(1);
        arg1 = 2;
        arg2 = 1;
        _gcdialogcamera_entrypoint_6(arg0->unk0);
        _gcdialogcamera_entrypoint_8();
    case 1:
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}

void func_8080087C_chheggy(Actor* arg0)
{
    if ((arg0->actorData[4] != 0) && (func_800DA298(FLAG2_64B_UNK) != 0))
    {
        _capod_entrypoint_3(0);
        arg0->actorData[4] = 0;
    }
}

void func_808008C4_chheggy(Actor* arg0)
{
    Prop* banjoPathProps[10];
    s32 pad[2];
    s32 var_s0;
    s32 temp_s1_2;
    Unk80100094* temp_s5;
    s32 numFound;
    f32 sp3C;

    temp_s5 = func_80100094(arg0, 0);
    numFound = _gccubesearch_entrypoint_9(0x299, banjoPathProps, 6);
    for (var_s0 = 0; var_s0 < numFound; var_s0++)
    {
        _gspropctrl_entrypoint_11(
            banjoPathProps[var_s0],
            &temp_s5->unk0[_gspropctrl_entrypoint_8(banjoPathProps[var_s0])-50]
        );
    }
    numFound = _gccubesearch_entrypoint_9(0x511, banjoPathProps, 5);
    for (var_s0 = 0; var_s0 < numFound; var_s0++)
    {
        temp_s1_2 = _gspropctrl_entrypoint_8(banjoPathProps[var_s0]) - 0x32;
        _gspropctrl_entrypoint_11(banjoPathProps[var_s0], &sp3C);
        temp_s5->unk48[temp_s1_2] = _glsplinefind_entrypoint_3(&sp3C);
    }
    func_800EE7F8(&temp_s5->unk3C, arg0->position);
}

void func_808009DC_chheggy(Actor* arg0)
{
    void* sp54;
    Unk80100094* sp50;
    Actor* sp4C;
    Unk80100094* sp48;
    f32 sp44;
    Unk80100094* sp40;
    f32 sp3C;
    u32 var_a1;

    switch (arg0->unk70_10)
    {
    case 7:
        if (func_800D90A4(&arg0->unk58) != 0)
        {
            func_80800ECC_chheggy(arg0, 8);
        }
        break;

    case 8:
        sp54 = func_80100094(arg0, 1U);
        sp50 = func_80100094(arg0, 0U);
        sp4C = _subaddiefind_entrypoint_2(arg0->actorData[7], 0);
        if (sp4C != NULL)
        {
            if (arg0->unk3C != NULL)
            {
                func_80106790(arg0->unk3C)->rotation[1] = sp4C->rotation[1];
            }
        }
        if (_subaddieitem_entrypoint_3(arg0, sp50->unk0[arg0->actorData[7] == 0x515 ? 3 : 4].f, sp54) != 0)
        {
            if (arg0->actorData[7] == 0x515)
            {
                func_800DA524(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE);
                arg0->unk64_20 = 1;
                if (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0)
                {
                    func_80800ECC_chheggy(arg0, 6);
                }
                else
                {
                    func_80800ECC_chheggy(arg0, 9);
                }
            }
            else
            {
                func_800DA524(FLAG_3E5_SNS_EGG_ACQUIRED_PINK);
                arg0->unk64_19 = 1;
                func_80800ECC_chheggy(arg0, 9);
            }
        }
        break;
    case 10:
        if (func_800D90A4(&arg0->unk58) != 0)
        {
            func_80800ECC_chheggy(arg0, 0xB);
        }
        break;
    case 12:

        if (func_808000C0_chheggy(arg0) != 0)
        {
            func_80800ECC_chheggy(arg0, 0xD);
        }
        break;
    case 13:
        sp48 = func_80100094(arg0, 0U);
        sp44 = func_80101F24(arg0);
        if (sp44 < 0.035f)
        {
            sp44 = 0.0f;
        }
        else if (sp44 <= 0.16f)
        {
            sp44 = func_800F10B4(func_80101F24(arg0), 0.035f, 0.16f, 0.0f, 1.0f);
        }
        else
        {
            sp44 = 1.0f;
            func_80800ECC_chheggy(arg0, 0xE);
        }
        func_800EFE50(arg0->position, (u8*)sp48 + 0x64, (u8*)sp48 + 0x70, sp44);
        break;
    case 14:
        if (func_80101E14(arg0, 0.84f) != 0)
        {
            func_80800ECC_chheggy(arg0, 0xF);
        }
        break;
    case 15:
        sp40 = func_80100094(arg0, 0U);
        if (func_80101F24(arg0) <= 0.92f)
        {
            sp3C = func_800F10B4(func_80101F24(arg0), 0.84f, 0.92f, 0.0f, 1.0f);
        }
        else
        {
            sp3C = 1.0f;
            func_80800ECC_chheggy(arg0, 0x10);
        }
        func_800EFE50(arg0->position, (u8*)sp40 + 0x64, (u8*)sp40 + 0x70, sp3C);
        func_800D1804(0x52);
        break;
    case 16:
        if (func_800D90A4(&arg0->unk58) != 0)
        {
            func_80800ECC_chheggy(arg0, 0x11);
        }
        func_80102BAC(arg0, 0.2f, 0.1f, 8.0f);
        break;
    case 18:
        if (func_808000C0_chheggy(arg0) != 0)
        {
            func_80800ECC_chheggy(arg0, 0x13);
        }
        break;
    case 19:
        _sudeflect_entrypoint_1(arg0->position, func_80103EF4(arg0), 0.0f, func_80103EAC(arg0) * 0.8f, 0xE);
        if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x258U, 0x3CU, 0) != 0)
        {
            if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) == 0) && (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) == 0))
            {
                var_a1 = 0x1546;
            }
            else if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0) && (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) != 0))
            {

                if (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) != 0)
                {
                    var_a1 = 0x1549;
                }
                else
                {
                    var_a1 = 0x1548;
                }
            }
            else
            {
                var_a1 = 0x1547;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, 0xEU, arg0->position, 0xCBU);
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 11:
    case 17:
    case 20:
        break;
    }
    func_8080015C_chheggy(arg0);
    if (((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) == 0) || (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) == 0)) && (_glcutDll_entrypoint_20() == 0))
    {
        func_800D1824(0x52);
    }
}


void func_80800ECC_chheggy(Actor* arg0, s32 arg1)
{
    Unk80100094* sp34;
    Unk80132ED0** temp_v0;

    s32 sp2C;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;

    sp34 = func_80100094(arg0, 0U);
    if (arg0->unk70_10 == 8)
    {
        temp_v0 = _subaddiefind_entrypoint_2(arg0->actorData[7], 0);
        if (temp_v0 != NULL)
        {
            func_800FFA88(*temp_v0);
        }
        func_80106790(arg0->unk3C)->unk64_16 = 1;
    }
    switch (arg1)
    {
    case 1:
        func_80800000_chheggy(arg0, func_80100094(arg0, 0U), 0);
        func_800DA544(FLAG_3E8_FTT_IoH_HEGGY);
        func_80800750_chheggy(arg0, arg0->unk0, 8, 0x40);
        break;
    case 3:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x153CU, 0xEU, arg0->position, 0xCBU);
        break;
    case 4:
        if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0) || (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) != 0))
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x153EU, 0xEU, arg0->position, 0xCBU);
        }
        else
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x153DU, 0xEU, arg0->position, 0xCBU);
        }
        break;
    case 5:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x153FU, 0xEU, arg0->position, 0xCBU);
        break;
    case 6:
        if (func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0)
        {
            arg0->actorData[7] = 0x515;
        }
        else
        {
            arg0->actorData[7] = 0x516;
        }
        func_80800000_chheggy(arg0, sp34, arg0->actorData[7] == 0x515 ? 1 : 2);
        func_80800750_chheggy(arg0, arg0->unk0, func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0 ? 3 : 1, 0x40);
        break;
    case 7:
        func_80090734(2, sp34->unk0[arg0->actorData[7] == 0x515 ? 3 : 4].f);
        arg0->unk58 = 0.5f;
        break;
    case 8:
        sp2C = func_801000D8(arg0, 1, 0x14);
        func_80090708(0);
        _subaddieitem_entrypoint_0(sp2C, arg0->actorData[7], 0x3E8, 2);
        _subaddieitem_entrypoint_2(sp2C);
        func_80108B04(arg0, 0U);
        break;
    case 9:
        func_80800000_chheggy(arg0, func_80100094(arg0, 0U), 0);
        break;
    case 10:
        func_80090734(2, sp34->unk0[arg0->actorData[7] == 0x515 ? 1 : 2].f);
        arg0->unk58 = 0.5f;
        break;
    case 11:
        func_80090708(0);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1540U, 0xEU, arg0->position, 0xCBU);
        break;
    case 12:
        func_800F82D4(func_800F54E4(), 2);
        if (arg0->unk64_20)
        {
            if (func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0)
            {
                arg0->unk3C = sp34->unk48[6];
                func_801058C4(arg0, sp34->unk48[4], 500.0f, 1U);
                arg0->unk64_20 = 0;
                func_80800750_chheggy(arg0, arg0->unk0, 2, 0x11);
            }
            else
            {
                arg0->unk3C = sp34->unk48[5];
                func_801058C4(arg0, sp34->unk48[0], 500.0f, 1U);
                func_80800750_chheggy(arg0, arg0->unk0, 3, 0x11);
            }
        }
        else if (arg0->unk64_19)
        {
            arg0->unk3C = sp34->unk48[6];
            func_801058C4(arg0, sp34->unk48[2], 500.0f, 1U);
            func_80800750_chheggy(arg0, arg0->unk0, 2, 0x11);
        }
        func_80105BAC(arg0);
        break;
    case 13:
        func_80105634(arg0);
        arg0->unk58 = 1.0f;
        func_800EE7F8(sp34->unk64, arg0->position);
        func_800EE7F8(sp34->unk70, func_80106790(arg0->unk3C)->position);
        if (arg0->unk64_20)
        {
            func_808006C4_chheggy(arg0, arg0->unk0, 4, 0x30);
        }
        else
        {
            func_808006C4_chheggy(arg0, arg0->unk0, 6, 0x30);
        }
        break;
    case 15:
        func_8010114C(arg0->unk3C, 0x18, 0);
        arg0->unk58 = 1.0f;
        func_800EE7F8(sp34->unk64, arg0->position);
        if (arg0->unk64_20)
        {
            func_800C7A68(func_800D7520(sp34->unk48[1]), 0.0f, sp34->unk70);
        }
        else if (arg0->unk64_19)
        {
            func_800C7A68(func_800D7520(sp34->unk48[3]), 0.0f, sp34->unk70);
        }
        break;
    case 16:
        arg0->unk58 = 2.0f;
        arg0->unk54 = func_8010CD50(arg0, func_800F54E4());
        break;
    case 17:
        func_800F82D4(func_800F54E4(), 0);
        if (arg0->unk64_20)
        {
            func_800DA544(FLAG_3E4_SNS_EGG_HATCHED_BLUE);
            func_800D3EF4(0xC);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1541U, 0xEU, arg0->position, 0xCBU);
        }
        else
        {
            func_800DA544(FLAG_3E6_SNS_EGG_HATCHED_PINK);
            func_800C7074(0x32, 1);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1542U, 0xEU, arg0->position, 0xCBU);
        }
        break;
    case 18:
        if (arg0->unk64_20)
        {
            arg0->unk64_20 = 0;
            func_801058C4(arg0, sp34->unk48[1], 500.0f, 1U);
            func_80800750_chheggy(arg0, arg0->unk0, 3, 0x11);
        }
        else if (arg0->unk64_19)
        {
            arg0->unk64_19 = 0;
            func_801058C4(arg0, sp34->unk48[3], 500.0f, 1U);
            func_80800750_chheggy(arg0, arg0->unk0, 1, 0x11);
        }
        func_80105BAC(arg0);
        break;
    case 19:
        func_8080087C_chheggy(arg0);
        break;
    }
    func_80102424(arg0, arg1);
}

s32 func_80801570_chheggy(Actor* arg0, s32 arg1, s32 arg2)
{
    Unk80100094* temp_v1;
    Actor* temp_v0_2;
    s32 temp_a0;
    u32 temp_a1;

    switch (arg1)
    {
    case 0x95:
        if (_glcutDll_entrypoint_20() != 0)
        {
            func_80800ECC_chheggy(arg0, 0x14);
            return 1;
        }
        if (func_800DA298(FLAG_3E8_FTT_IoH_HEGGY) != 0)
        {
            if ((func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0) || (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0))
            {
                func_80800ECC_chheggy(arg0, 1);
                return 1;
            }
            func_80800ECC_chheggy(arg0, 0x13);
            return 1;
        }
        func_80800ECC_chheggy(arg0, 1);
        return 1;
    case 0x32:
        switch (arg0->unk70_10)
        {
        case 1:
            func_808007D4_chheggy(arg0, 2, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, func_800DA298(FLAG_3E8_FTT_IoH_HEGGY) != 0 ? 0x153B : 0x153A, 0xEU, arg0->position, 0xCBU);
            return 1;
        case 6:
            func_80800ECC_chheggy(arg0, 7);
            return 1;
        case 9:
            func_80800ECC_chheggy(arg0, 0xA);
        default:
            return 1;
        }
        break;
    case 0x2E:
        switch (((s16*)&arg2)[0])
        {
        case 0x153A:
        case 0x153B:
            switch (func_8080006C_chheggy())
            {
            case 0:
                func_80800ECC_chheggy(arg0, 3);
                return 1;
            case 1:
                func_80800ECC_chheggy(arg0, 4);
                return 1;
            case 2:
                func_80800ECC_chheggy(arg0, 5);
            default:
                return 1;
            }
            break;
        case 0x153D:
        case 0x153E:
        case 0x153F:
            func_80800ECC_chheggy(arg0, 6);
            return 1;
        case 0x1540:
            func_80800ECC_chheggy(arg0, 0xC);
            return 1;
        case 0x1541:
            func_80800ECC_chheggy(arg0, arg0->unk64_19 ? 0xC : 0x12);
            func_800D3EF4(0xC);
            return 1;
        case 0x1542:
            func_80800ECC_chheggy(arg0, 0x12);
            func_800C7074(0x32, 1);
            return 1;
        case 0x1543:
            func_800DA544(GFLAG_C0B_JINJO_IN_MULTIPLAYER);
            return 1;
        case 0x153C:
            func_80800ECC_chheggy(arg0, 0x13);
        default:
            return 1;
        }
        break;
    case 0x3D:
        temp_v1 = func_80100094(arg0, 0U);
        temp_v0_2 = func_80108528(0x517, &temp_v1->unk0[arg0->actorData[7] == 0x515 ? 3 : 4], 0, &arg0);
        arg0->unk3C = temp_v0_2->unk0;
        temp_v0_2->unk64_16 = 0;
        if (arg0->actorData[7] == 0x515)
        {
            temp_v1->unk48[5] = (Unk80132ED0*)temp_v0_2->unk0;
            func_80103140(temp_v0_2, 0x975, arg0->unk0->unk16);
            func_80102424(temp_v0_2, 1);
            return 1;
        }
        temp_v1->unk48[6] = (Unk80132ED0*)temp_v0_2->unk0;
        func_80103140(temp_v0_2, 0x974, arg0->unk0->unk16);
        func_80102424(temp_v0_2, 1);
        return 1;
    case 0x18:
        if (arg2 != 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1543U, 0xEU, arg0->position, 0xCBU);
        }
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(arg0->position);
        _gcdialogcamera_entrypoint_3(&D_80801E8C_chheggy, arg0->scale);
        return 3;
    case 0x57:
        temp_a0 = arg2 & 0xFFFF;
        temp_a1 = (arg2 & 0xFFFF0000) >> 0x10;
        if (_gcdialogcamera_entrypoint_0(temp_a0, temp_a1) != 0)
        {
            func_808007D4_chheggy(arg0, temp_a0, (s32)temp_a1);
            return 2;
        }
        return 1;
    default:
        return 0;
    }
}

s32* chheggy_entrypoint_0(void) 
{
    return &D_80801E9C_chheggy;
}

void func_808019CC_chheggy(Actor* arg0)
{
    if (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)
    {
        func_80108B04(arg0, 1);
    }
}

s32 func_80801A00_chheggy(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* sp34;

    switch (arg1)
    {                                 /* irregular */
    default:
        if (arg1 == 0x40)
        {
            func_80103110(arg0, 1U);
            _subaddieDll_entrypoint_5(arg0, arg2);
            func_80101FDC(arg0, 2U);
            return 1;
        }
        break;
    case 0x3D:
        func_800DA544(FLAG_581_PHYSICAL_IoH_HeggySplitUpCoverBroken);
        _chskeletonexplode_entrypoint_7(arg0, arg0->position);
        func_8010A570(arg0);
        func_8010A624(arg0);
        return 1;
    case 0xF:
        sp34 = func_80106790(func_80101080());
        func_800C4140(0x59919413, arg0->position, 0x04B000FA);
        func_800BBCB8(arg0->position, arg0->position, 1.0f, 6, &D_80801EE4_chheggy);
        func_800BBCB8(arg0->position, arg0->position, 1.0f, 3, &D_80801F1C_chheggy);
        _chskeletonexplode_entrypoint_3(sp34, 1, 0);
        _chskeletonexplode_entrypoint_3(sp34, 2, 1);
        func_800FFA88(arg0->unk0);
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(1, 1);
        func_800DF744(2, 0);
        return 1;
    }
    return 0;
}

s32* chheggy_entrypoint_1(void) 
{
    return &D_80801F58_chheggy;
}
