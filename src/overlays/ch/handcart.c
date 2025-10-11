#include "ch/handcart.h"

#define HANDCART_DATA(arg0) ((HandcartActorData*)(arg0->actorData))

extern f32 func_80013970(f32);

extern u32 D_808046C0_chhandcart;
extern u32 D_808046D4_chhandcart;
extern u32 D_808046E8_chhandcart;
extern unk80804B84* D_80804B84_chhandcart[4];
extern s32 D_80804B94_chhandcart[4];
extern unk80804D84* (D_80804D84_chhandcart[4]);
extern s32 D_80804D94_chhandcart[4];
extern s32 D_80804DA4_chhandcart;
extern f32 D_80804DB8_chhandcart[3];
extern void* D_80804DC4_chhandcart;
extern void* D_80804E6C_chhandcart;
extern u32 D_80804E0C_chhandcart;
extern u32 D_80804E18_chhandcart;
extern u32 D_80804E2C_chhandcart;
extern u32 D_80804E38_chhandcart;
extern u32 D_80804E4C_chhandcart;
extern u32 D_80804E5C_chhandcart;
extern f32 D_808046F4_chhandcart;
extern u32 D_80804704_chhandcart;
extern u32 D_80804714_chhandcart;

s32 func_80800000_chhandcart(void)
{
    return func_800DA564(FLAG3_A4C_UNK, 3);
}

//Start/End
void func_80800024_chhandcart(s32 arg0)
{
    func_800DA7A8(FLAG3_9DC_UNK, arg0, 2);
    func_800FDC28(0U);
    switch (arg0) 
    {
    case 1: //Lose
        func_800FC660(0x17U);
        return;
    case 2: //Win
        func_800FC660(0x16U);
        return;
    }
}

//Get Cart Progress
s32 func_80800090_chhandcart(void) 
{
    return func_800DA564(FLAG3_9DC_UNK, 2);
}

//Goto Map
void func_808000B4_chhandcart(Actor* arg0)
{
    switch (((CanaryMaryMemory*)func_80100094(arg0, 0U))->RaceState)
    {
    case 1:
        //Control which race to go to
        _gcgoto_entrypoint_1(arg0->unk64_19>0 ? MAP_170_GGM_RACE_2 : MAP_16F_GGM_RACE_1, 1);
        return;
    case 0:
    case 2:
        if (func_80800090_chhandcart() == 2)
        {
            //Success Teleport
            _gcgoto_entrypoint_1(MAP_C7_GGM_GLITTER_GULCH_MINE, arg0->unk64_19>0 ? 0x15 : 0x16);
            return;
        }
        else
        {
            //Failure Teleport
            _gcgoto_entrypoint_1(MAP_C7_GGM_GLITTER_GULCH_MINE, arg0->unk64_19>0 ? 0x16 : 0x15);
            return;
        }

    }

}

//Get the Race State
s32 func_80800194_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* new_var;
    u8 tempRaceState;
    new_var = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    //Load the Race State into the actor's memory
    tempRaceState = func_800DA564(FLAG3_A4C_UNK, 3);
    return new_var->RaceState = tempRaceState;
}

//Set Cart Progress State
void func_808001D0_chhandcart(Actor* arg0, s32 arg1) 
{
    CanaryMaryMemory* sp1C;

    sp1C = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    func_800DA7A8(FLAG3_A4C_UNK, arg1, 3);
    sp1C->RaceState = (u8)arg1;
}

//Progress the Race
void func_80800214_chhandcart(Actor* arg0)
{
    switch (((CanaryMaryMemory*)func_80100094(arg0, 0U))->RaceState)
    {
    case 0: //If we are in the default state enter the race state
        //Mid Race
        func_808001D0_chhandcart(arg0, 1);
        func_808000B4_chhandcart(arg0);
        return;
    case 1: //If we are in the race state enter the win state
        //Won Race
        func_808001D0_chhandcart(arg0, 2);
        _gcintrotext_entrypoint_0();
        func_808000B4_chhandcart(arg0);
        return;
    case 2: //If we are in the win state reset to default
        func_808001D0_chhandcart(arg0, 0);
        func_80800024_chhandcart(0);
        return;
    }
}

void func_808002B8_chhandcart(Actor* arg0, s32 arg1)
{
    Vec3f* sp6C[1];
    f32* sp68[1];
    s16* var_s3;
    s16* var_s4;
    s32 var_s0;
    SplineMemory* splineMemory;
    u32 tempA1;
    s32 pad;
    HandcartMemory* sp4C;

    tempA1 = arg1 - 1;
    sp4C = (HandcartMemory*)func_80100094(arg0, 0U);
    splineMemory = (SplineMemory*)func_80100074(arg0, 1U, _susplinet_entrypoint_18(D_80804B94_chhandcart[tempA1], 1, 1));
    _susplinet_entrypoint_19(splineMemory, D_80804B94_chhandcart[tempA1], 1, 1);
    for (var_s0 = 0; var_s0 <= 0; var_s0++)
    {
        sp6C[var_s0] = _susplinet_entrypoint_14(splineMemory, var_s0);
    }

    for (var_s0 = 0; var_s0 <= 0; var_s0++)
    {
        sp68[var_s0] = _susplinet_entrypoint_15(splineMemory, var_s0);
    }

    var_s3 = _susplinet_entrypoint_12(splineMemory);
    var_s4 = _susplinet_entrypoint_13(splineMemory);
    for (var_s0 = 0; var_s0 < D_80804B94_chhandcart[tempA1]; var_s0++)
    {
        func_800EE7F8(sp68[1], D_80804B84_chhandcart[tempA1][var_s0].unk0);
        var_s3[0] = D_80804B84_chhandcart[tempA1][var_s0].unk10;
        var_s4[0] = -1;
        *sp68[0] = D_80804B84_chhandcart[tempA1][var_s0].unk0[3];
        _susplinet_entrypoint_0(splineMemory, var_s0, 2, ((D_80804B84_chhandcart[tempA1][var_s0].unk12 & 1) != 0) ? (1) : (0));
        _susplinet_entrypoint_0(splineMemory, var_s0, 4, ((D_80804B84_chhandcart[tempA1][var_s0].unk12 & 2) != 0) ? (1) : (0));
        var_s3++;
        var_s4++;
        sp68[0]++;
        sp6C[0]++;
    }

    for (var_s0 = 0; var_s0 <= 0; var_s0++)
    {
        sp6C[var_s0] = _susplinet_entrypoint_14(splineMemory, var_s0);
    }

    for (var_s0 = 0; var_s0 <= 0; var_s0++)
    {
        sp68[var_s0] = _susplinet_entrypoint_15(splineMemory, var_s0);
    }

    func_800F0EF0(D_80804B94_chhandcart[tempA1], sp6C[0]->f);
    sp4C->unk8F5 = arg1;
    sp4C->unk8F6 = 0;
}

void func_80800528_chhandcart(Actor* arg0)
{
    SplineMemory* splineMemory;
    HandcartMemory* handcartMemory;
    f32 gamespeed;
    Actor* sp78;
    f32 sp74;
    f32 new_var;
    f32 sp6C;
    f32 sp60[3];
    f32 sp5c;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s32 sp40;
    f32 sp34[3];
    splineMemory = (SplineMemory*)func_80100094(arg0, 1U);
    handcartMemory = (HandcartMemory*)func_80100094(arg0, 0U);
    gamespeed = func_800D8FF8();
    sp78 = NULL;
    if (handcartMemory->unk8F4 == 3)
    {
        switch (handcartMemory->unk8F5)
        {
        case 1:

        case 3:
            sp40 = 0;
            sp78 = arg0;
            break;

        case 2:

        case 4:
            sp78 = func_80106790(arg0->unk3C);
            sp40 = 1;
            break;

        }

        _susplinet_entrypoint_11(splineMemory, _susplinet_entrypoint_9(splineMemory));
        _susplinet_entrypoint_10(splineMemory, func_80105AE8(sp78) * 1000.0f);
        _susplinet_entrypoint_17(splineMemory);
        _susplinet_entrypoint_7(splineMemory, 0, &sp6C);
        func_800EF5A0(sp60, &sp6C, 0.0f, 0.0f, -_susplinet_entrypoint_8(splineMemory, 0.0f));
        if (sp40 == 1)
        {
            func_800EFA4C(sp34, 0.0f, 75.0f, 150.0f);
        }
        else
        {
            func_800EFA4C(sp34, 0.0f, 75.0f, 0.0f);
        }
        if (_susplinet_entrypoint_6(splineMemory) != 0)
        {
            handcartMemory->unk8F6 = 0U;
        }
        if (handcartMemory->unk8F6 != 0)
        {
            new_var = 3.0f * gamespeed;
            handcartMemory->unk904 += (func_800F1DCC(sp78->rotation[0], handcartMemory->unk904) * new_var);
            handcartMemory->unk908 += (func_800F1DCC(sp78->rotation[1], handcartMemory->unk908) * new_var);
        }
        else
        {
            handcartMemory->unk904 = sp78->rotation[0];
            handcartMemory->unk908 = sp78->rotation[1];
            handcartMemory->unk8F6 = 1U;
        }
        func_800EF4E4(sp60, handcartMemory->unk904, handcartMemory->unk908, sp60[0], sp60[1], sp60[2]);
        func_800EF4E4(&sp48, handcartMemory->unk904, handcartMemory->unk908, sp34[0], sp34[1], sp34[2] * 1.0f);
        func_800EF04C(sp60, sp78->position);
        func_800EF04C(&sp48, sp78->position);
        func_800A516C(&sp54, &sp48, sp60);
        _capod_entrypoint_1(sp60, &sp54);
    }
}

void func_808007BC_chhandcart(Actor* arg0, s32 arg1) 
{
    _capod_entrypoint_2(arg0->unk0, 0x1D, arg1 | 0x800);
}

void func_808007F0_chhandcart(Actor* arg0)
{
    if (((HandcartMemory*)func_80100094(arg0, 0U))->unk8F4 == 3)
    {
        func_80100074(arg0, 1, 0);
    }
}

void func_80800830_chhandcart(Actor *arg0) 
{
    func_8008FB58(arg0->position, -25.0f, 100.0f);
}

void func_80800858_chhandcart(Actor* arg0, Actor* arg1, s32 arg2, s32 arg3)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    if (arg1 == NULL)
    {
        arg1 = arg0;
    }
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart(arg0, 0);
    case 1:
    case 3:
    case 4:
        _capod_entrypoint_8(1);
        sp1C->unk8F4 = 2U;
        _gcdialogcamera_entrypoint_6(arg1->unk0);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg2, arg3);
        break;
    }
}

void func_8080090C_chhandcart(Actor* arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart(arg0, arg2);
    case 2:
    case 3:
    case 4:
        sp1C->unk8F4 = 1U;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        break;
    }
}

void func_80800998_chhandcart(Actor* arg0, u32 arg1, u32 arg2, Unk80132ED0* arg3) {
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*) func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4) 
    {
    case 0:
        func_808007BC_chhandcart(arg0, (s32)arg2);
    case 1:
    case 2:
    case 3:
        sp1C->unk8F4 = 4U;
    case 4:
        _capod_entrypoint_20(arg3, arg1, arg2);
        break;
    }
}

void func_80800A24_chhandcart(Actor* arg0, s32 arg1, s32 arg2) {
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart(arg0, arg2);
    case 1:
    case 2:
    case 4:
        sp1C->unk8F4 = 3U;
    case 3:
        _capod_entrypoint_8(0);
        func_808002B8_chhandcart(arg0, arg1);
        break;
    }
}

void func_80800AB0_chhandcart(Actor* arg0) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    if (sp1C->unk8F4 != 0)
    {
        _capod_entrypoint_3(0);
        sp1C->unk8F4 = 0U;
    }
}

void func_80800B00_chhandcart(Actor* arg0) 
{
    s32 temp_v1;
    s32 var_s4;
    HandcartMemory* temp_v0;

    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    temp_v1 = temp_v0->unk8F5 - 1;
    if (D_80804D84_chhandcart[temp_v1] != 0) 
    {
        if (arg0->unk7C_0)
        {
            for (var_s4 = 0; var_s4 < D_80804D94_chhandcart[temp_v1]; var_s4++) 
            {
                if (func_80105998(arg0, D_80804D84_chhandcart[temp_v1][var_s4].unk0) != 0) 
                {
                    switch (D_80804D84_chhandcart[temp_v1][var_s4].unkC) 
                    {
                    case 1:
                        if (temp_v0->unk8F8 != 0)
                        {
                            func_80800A24_chhandcart(arg0, temp_v0->unk8F5, 4);
                        }
                        break;
                    case 2:
                        if (temp_v0->unk8F8 != 0)
                        {
                            func_80800998_chhandcart(arg0, D_80804D84_chhandcart[temp_v1][var_s4].unkE, 5U, arg0->unk0);
                        }
                        break;
                    case 3:
                        if (temp_v0->unk8F8 != 0) {
                            temp_v0->unk8FC = D_80804D84_chhandcart[temp_v1][var_s4].unk4;
                            temp_v0->unk900 = D_80804D84_chhandcart[temp_v1][var_s4].unk8;
                            func_8080090C_chhandcart(arg0, D_80804D84_chhandcart[temp_v1][var_s4].unkE, 4, arg0->unk0);
                        }
                        break;
                    }
                    temp_v0->unk8F9 = D_80804D84_chhandcart[temp_v1][var_s4].unkC;
                }
            }
        }
    }
}

void func_80800CD0_chhandcart(Actor* arg0)
{
    HandcartMemory* temp_v0;


    Unkfunc_800E0960_1 *sp30;

    f32 temp_f0_2;
    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    if (!arg0->unk5F)
    {
    }
    sp30 = (Unkfunc_800E0960_1 *)func_8010262C(arg0->unk0, 2);
    temp_v0->unk918 = func_800136E4(temp_v0->unk918 + (HANDCART_DATA(arg0)->unkC * 0.5f));
    if (sp30 != 0)
    {
        func_800E0AFC(sp30, 0x2B, -1.0f, temp_v0->unk918, 0.0f, 0.0f);
        func_800E0AFC(sp30, 0x2C, -1.0f, temp_v0->unk918, 0.0f, 0.0f);
    }
    if (HANDCART_DATA(arg0)->unkC > 10.0f)
    {
        temp_f0_2 = func_800F10B4(1.0f - (HANDCART_DATA(arg0)->unkC / 90.0f), 0.0f, 1.f, 0.5f, 3.0f);
        func_80101CDC(arg0, temp_f0_2);
        if (arg0->unk5F == 0)
        {
            arg0->unk5F = func_800C4350(arg0->unk5F, arg0->position, &D_80804DA4_chhandcart);
            return;
        }
        func_800C31DC(arg0->unk5F, func_800F10B4(temp_f0_2, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(arg0->unk5F, arg0->position, 0);
        return;
    }
    func_80101CDC(arg0, 1e7f);
}

void func_80800E58_chhandcart(Actor* arg0, s32 arg1)
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_800904C8(0x28);
    if (arg1 != 0)
    {
        func_800903D0((sp1C->unk928));
    }
}

void func_80800EA0_chhandcart(Actor *arg0)
{
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804704_chhandcart);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80804714_chhandcart);
}

void func_80800EE4_chhandcart(Actor* arg0, s32 arg1) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    if ((func_8009EA64() == 0x38A) && (sp1C->unk8FA != 0))
    {
        sp1C->unk8FA = 0U;
        func_80800E58_chhandcart(arg0, arg1);
        HANDCART_DATA(arg0)->unkC = 0;
        func_80800CD0_chhandcart(arg0);
    }
}

void func_80800F4C_chhandcart(Actor* arg0) 
{
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 == 0) || (temp_t6 == 1) || (temp_t6 == 2))
    {
        _subaddieDll_entrypoint_4(arg0, 0);
        return;
    }
    _subaddieDll_entrypoint_4(arg0, 1);
}

void func_80800FA0_chhandcart(Actor* arg0, s32 arg1)
{
    HandcartMemory* sp24;
    u32 temp_t6;

    sp24 = (HandcartMemory*)func_80100094(arg0, 0U);
    temp_t6 = arg0->unk70_10;
    switch (temp_t6)
    {
    case 11:
        break;
    case 4:
        func_800F4CC0(func_800F54E4());
        break;
    case 23:
        func_80103140(arg0, 0x67C, arg0->unk0->unk16);
        break;
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10)
    {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    case 3:
        func_800903D0(arg0->position);
        break;
    case 4:
        sp24->unk8FA = 1;
        func_800904F4(0x27, arg0->unk0);
        func_800F4CEC(func_800F54E4(), 0x3B);
        break;
    case 5:
        sp24->unk8FA = 1;
        func_800904F4(0x27, arg0->unk0);
        break;
    case 7:
        func_80800EE4_chhandcart(arg0, 1);
        break;
    }
    func_80800F4C_chhandcart(arg0);
}

void func_808010D8_chhandcart(Actor* arg0, s32 arg1) {
    Actor* sp1C;

    sp1C = func_80106790(arg0->unk3C);
    func_80800FA0_chhandcart(arg0, arg1);
    func_80802CE8_chhandcart(sp1C, arg1);
}

void func_8080111C_chhandcart(Actor* arg0)
{
    if (func_8009EA64() == 0x38A) 
    {
        //Position
        func_800907C0(arg0->position);
        //Rotation
        func_800906DC(arg0->rotation);
    }
}

f32 func_8080115C_chhandcart(f32* arg0, f32 arg1)
{
    f32 gamespeed;
    f32 temp_f2;
    f32 temp_f12;
    s32 temp_v0;
    gamespeed = func_800D8FF8();

    //Get Button Hold Time
    temp_v0 = func_80016B30(0, 0);
    temp_f12 = *arg0;
    //If the button has not been pressed in a bit
    if (temp_f12 < 0.0f)
    {
        //If we're holding the button
        if (temp_v0 != 0)
        {
            arg1 += func_800F10B4(temp_f12, -1.0f, -0.01f, 0.0f, 3.0f);
            *arg0 = 0.01f;
            return arg1;
        }
        else //Slow the player
        {
            *arg0 = temp_f12 - gamespeed;
            arg1 *= 0.98f;
        }
    }
    //If the button has just been pressed
    else
    {
        //If we're not holding the button
        if (temp_v0 == 0)
        {
            arg1 += func_800F10B4(temp_f12, 1.0f, 0.01f, 0.0f, 3.0f);
            *arg0 = -0.01f;
            return arg1;
        }
        else//Slow the player
        {

            *arg0 = temp_f12 + gamespeed;
            arg1 *= 0.98f;
        }
    }
    //Cap the player speed at 90
    if (arg1 > 90.0f)
    {
        arg1 = 90.0f;
    }
    return arg1;
}


void func_80801290_chhandcart(Actor* arg0)
{
    HandcartMemory* spBC;
    f32 gamespeed;
    s32 temp_v0;
    s32 i;
    f32 spAC;
    f32 sp7C[4][3];
    spBC = (HandcartMemory*)func_80100094(arg0, 0);
    gamespeed = func_800D8FF8();
    func_800EF5A0(sp7C[0], arg0->rotation, -52.0f, 0, -49.0f);
    func_800EF5A0(sp7C[1], arg0->rotation, -52.0f, 0, 30.0f);
    func_800EF5A0(sp7C[2], arg0->rotation, 52.0f, 0, -49.0f);
    func_800EF5A0(sp7C[3], arg0->rotation, 52.0f, 0, 30.0f);
    for (i = 0; i < 4; i++) {
        func_800EF04C(sp7C[i], arg0->position);
    }
    for (i = 0; i < 0x3C; i++) {

        if (spBC->unk87C[i] != 0)
        {
            func_800EE7B4(spBC->unkC[i], spBC->unkC[i], spBC->unkC[i + 0x78], gamespeed);
            if (spBC->unkC[i][1] < (0.0f * 1.0f))
            {
                spBC->unk87C[i] = 0U;
            }
            else
            {
                temp_v0 = func_800DC128(8, 0xF);
                if (temp_v0 < spBC->unk87C[i])
                {
                    spBC->unk87C[i] -= temp_v0;
                }
                spBC->unkC[i + 0x78][1] += -300.0f * gamespeed;
                func_800EE7F8(spBC->unkC[i + 0x3C], sp7C[spBC->unk87C[i + 0x3C]]);
                func_800EF4E4(&spAC, arg0->rotation[0], arg0->rotation[1], spBC->unkC[i][0], spBC->unkC[i][1], spBC->unkC[i][2]);
                func_800EF04C(spBC->unkC[i + 0x3C], &spAC);
            }
        }
    }
}

void func_808014D8_chhandcart(Actor* arg0, u32 arg1)
{
    s32 var_s1;
    s32 var_s2;
    HandcartMemory* temp_v0;
    u8* var_s0;
    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    var_s1 = 0;
    var_s2 = 0;
    var_s0 = (u8*)temp_v0;
    for (; var_s2 < 0x3C; var_s2++)
    {
        if (var_s0[0x87C] == 0)
        {
            var_s0[0x87C] = 0xFFU;
            var_s0[0x87C + 0x3C] = (s8)arg1;
            func_800EFD24(temp_v0->unkC[var_s2]);
            func_800EFA4C(temp_v0->unkC[var_s2] + 0x168, func_800DC178(-15.0f, 15.0f), func_800DC178(80.0f, 120.0), func_800DC178(-50.0f, -85.0f));
            var_s1 += 1;
            if (var_s1 >= 0x4)
            {
                return;
            }
        }
        var_s0++;
    }

}

void func_80801638_chhandcart(Actor* arg0, s32 arg1)
{
    if (arg0->unk7C_12)
    {
        if (arg1 != 0)
        {
            func_808014D8_chhandcart(arg0, 0);
            func_808014D8_chhandcart(arg0, 1);
            return;
        }
        func_808014D8_chhandcart(arg0, 2);
        func_808014D8_chhandcart(arg0, 3);
    }
}

f32 func_8080169C_chhandcart(Actor* arg0, u32 arg1, f32* arg2)
{
    f32 var_f0;

    f32 sp38[3];
    f32 sp2C[3];

    if (arg1 != 0)
    {
        var_f0 = 58.0f;
    }
    else
    {
        var_f0 = -58.0f;
    }
    func_800EF4E4(arg2, arg0->rotation[0], arg0->rotation[1], var_f0, 0.0f, 0.0f);
    func_800EF04C(arg2, arg0->position);
    func_800EE7F8(sp38, arg2);
    sp38[1] += 150.0f;
    arg2[1] -= 150.0f;
    if (func_800BEF00(sp38, arg2, sp2C, 0x20020U) == 0)
    {
        arg2[1] = arg0->position[1];
    }
    return arg2[1];
}

void func_8080176C_chhandcart(Actor* arg0) 
{
    HandcartMemory* sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 temp_f0;

    sp44 = (HandcartMemory*)func_80100094(arg0, 0U);
    func_8080169C_chhandcart(arg0, 0, sp2C);
    func_8080169C_chhandcart(arg0, 1, sp38);
    temp_f0 = func_800F1828(sp2C, sp38);
    arg0->position[1] = (sp2C[1] + sp38[1]) * 0.5f;
    arg0->rotation[2] = sp44->unk934[2] + temp_f0;
    if (arg0->rotation[2] > 0.0f) 
    {
        arg0->position[1] += func_80013970(sp44->unk934[2]) * 58.0f;
        return;
    }
    arg0->position[1] -= func_80013970(sp44->unk934[2]) * 58.0f;
}

void func_80801850_chhandcart(Actor* arg0)
{
    HandcartMemory* temp_v0;
    f32 a0;
    f32 sp2C;

    s32 var_s0;
    f32* f0;

    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    temp_v0->unk91C = temp_v0->unk934[2];
    if (HANDCART_DATA(arg0)->unkC > 12.0f)
    {
        if (temp_v0->unk934[2] < temp_v0->unk920)
        {
            temp_v0->unk934[2] = (f32)(temp_v0->unk934[2] + 1.0f);
        }
        else if (temp_v0->unk920 < temp_v0->unk934[2])
        {
            temp_v0->unk934[2] = (f32)(temp_v0->unk934[2] - 1.0f);
        }
        if (temp_v0->unk920 > 0.0f)
        {
            if (temp_v0->unk920 < temp_v0->unk934[2])
            {
                temp_v0->unk934[2] = temp_v0->unk920;
            }
        }
        else if (temp_v0->unk934[2] < temp_v0->unk920)
        {
            temp_v0->unk934[2] = temp_v0->unk920;
        }
    }
    else
    {
        temp_v0->unk934[2] = (f32)(temp_v0->unk934[2] * 0.65f);
    }
    if (((temp_v0->unk934[2] < -5.0f) || (temp_v0->unk934[2] > 5.0f)) && (temp_v0->unk924 != 0))
    {
        func_800C4350(temp_v0->unk924, arg0->position, 0);
    }
    if ((temp_v0->unk91C >= 2.0f) && (temp_v0->unk934[2] < 2.0f))
    {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808046F4_chhandcart);
        temp_v0->unk934[0] = 0.1f;
        if (func_800DC0C0() < 0.5f)
        {
            temp_v0->unk934[2] = -3.0f;
        }
    }
    if ((temp_v0->unk91C <= -2.0f) && (temp_v0->unk934[2] > -2.0f))
    {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808046F4_chhandcart);
        temp_v0->unk934[1] = 0.1f;
        if (func_800DC0C0() < 0.5f)
        {
            temp_v0->unk934[2] = 3.0f;
        }
    }
    if ((func_800DC0C0() < 0.1f) && (HANDCART_DATA(arg0)->unkC > 5.0f))
    {
        if (temp_v0->unk934[2] < 0.0f)
        {
            temp_v0->unk934[0] = 0.1f;
        }
        if (temp_v0->unk934[2] > 0.0f)
        {
            temp_v0->unk934[1] = 0.1f;
        }
    }
    sp2C = func_800D8FF8();
    var_s0 = 0;
    f0 = (f32*)temp_v0;
    do {
        if (f0[0x24D] >= 0.0f)
        {
            f0[0x24D] = (f0[0x24D] - sp2C);
            func_80801638_chhandcart(arg0, var_s0);
        }
        var_s0 += 1;
        f0 += 1;
    } while (var_s0 != 2);
    func_8080176C_chhandcart(arg0);
}

void func_80801BA4_chhandcart(Actor* arg0)
{
    HandcartMemory* temp_s1;
    f32 sp28;

    sp28 = 0.1f;
    temp_s1 = (HandcartMemory*)func_80100094(arg0, 0U);
    func_80105A9C(arg0, HANDCART_DATA(arg0)->unkC * 10.0f);
    func_80105834(arg0);
    temp_s1->unk920 = func_800F10B4(HANDCART_DATA(arg0)->unkC, 0.0f, 100.0f, 0.0f, func_800F1DCC(arg0->rotation[1], temp_s1->unk8) * 3.0f);
    temp_s1->unk8 = (f32)arg0->rotation[1];
    if (temp_s1->unk8F7 == 0)
    {
        sp28 = 1.0f;
        temp_s1->unk8F7 = 1U;
    }
    arg0->rotation[0] += func_800F1DCC(arg0->unk50, arg0->rotation[0]) * sp28;
    arg0->rotation[1] += func_800F1DCC(arg0->unk54, arg0->rotation[1]) * sp28;
    func_80801850_chhandcart(arg0);
    func_80800CD0_chhandcart(arg0);
    func_80801290_chhandcart(arg0);
}

void func_80801CBC_chhandcart(Actor* arg0)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    HANDCART_DATA(arg0)->unkC *= 0.95f;
    arg0->rotation[0] += func_800F1DCC(0.0f, arg0->rotation[0]) * 0.05f;
    sp1C->unk934[2] += (func_800F1DCC(0, sp1C->unk934[2]) * 0.05f);
}

void func_80801D50_chhandcart(Actor* arg0)
{
    Actor* sp3C;
    f32 gameSpeed;
    HandcartMemory* sp34;

    if (arg0->unk3C == 0)
    {
        func_80800830_chhandcart(arg0);
        return;
    }
    gameSpeed = func_800D8FF8();
    sp3C = func_80106790(arg0->unk3C);
    sp34 = (HandcartMemory*)func_80100094(arg0, 0U);
    switch (arg0->unk70_10)
    {
    case 2:
        func_80800830_chhandcart(arg0);
        //Check if the player is Banjo and Kazooie
        if ((func_80090178(1) != 0) && (func_8010C9B0(arg0->position, 0x64) != 0))
        {
            //Set Flag True Canary Mary Race Intro
            func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
            func_80800214_chhandcart(sp3C);
        }
        break;
    case 3:
        if (func_8010CB0C(arg0->position, 0x32, 0x32, 0) != 0)
        {
            //Set Flag True Canary Mary Race Intro
            func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
            func_808010D8_chhandcart(arg0, 4);
        }
        break;
    case 4:
    {
        f32 sp28[3] = D_80804DB8_chhandcart;
        f32 temp_f0;
        func_800907C0(arg0->position);
        sp28[1] = func_80090010();
        temp_f0 = func_800F1DCC(arg0->rotation[1], sp28[1]);
        if ((temp_f0 < -35.0f) || (temp_f0 > 35.0f))
        {
            sp28[1] += temp_f0 * gameSpeed * 5.0f;
            func_800906DC(sp28);
        }
        else
        {
            func_80800214_chhandcart(sp3C);
        }
        break;
    }
    case 5:
        func_8080111C_chhandcart(arg0);
        break;
    case 6:
        HANDCART_DATA(arg0)->unkC = func_8080115C_chhandcart(&(sp34->unk4), HANDCART_DATA(arg0)->unkC);
        func_80801BA4_chhandcart(arg0);
        func_8080111C_chhandcart(arg0);
        if (func_80105A5C(arg0) != 0)
        {
            func_80800EA0_chhandcart(arg0);
            func_808010D8_chhandcart(arg0, 7);
        }
        break;
    case 9:
    case 10:
    case 11:
        HANDCART_DATA(arg0)->unkC = func_8080115C_chhandcart(&(sp34->unk4), HANDCART_DATA(arg0)->unkC);
        func_80801BA4_chhandcart(arg0);
        func_8080111C_chhandcart(arg0);
        break;
    case 7:
    case 8:
    case 12:
    case 13:
        func_80801CBC_chhandcart(arg0);
        func_80801290_chhandcart(arg0);
        break;
    case 14:
    case 15:
        func_80800830_chhandcart(arg0);
        func_80801CBC_chhandcart(arg0);
        break;
    }
    if ((sp34->unk8F5 == 1) || (sp34->unk8F5 == 3))
    {
        func_80800B00_chhandcart(arg0);
        func_80800528_chhandcart(arg0);
    }
}

void func_80801FF4_chhandcart(s32 arg0) 
{

}

void func_80801FFC_chhandcart(Actor* arg0)
{
    Actor* temp_v0;
    f32 sp28;
    f32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x226, arg0->position), sp1C);
    temp_v0 = func_80108528(0x51E, sp1C, 0, &arg0);
    arg0->unk3C = temp_v0->unk0;
    temp_v0->unk3C = arg0->unk0;
    func_80100120(temp_v0);
}

void func_80802068_chhandcart(Actor* arg0, s32 arg1) {
    Prop* var_v0;
    if (func_80800090_chhandcart() == 1)
    {
        arg1 = 1 - arg1;
    }
    if (arg1 != 0)
    {
        var_v0 = _gccubesearch_entrypoint_1(0x314, arg0->position);
    }
    else
    {
        var_v0 = _gccubesearch_entrypoint_1(0x313, arg0->position);
    }
    func_800EE88C(arg0->position, var_v0->position);
    //Controls the rotation of the cart when spawned in normal GGM
    arg0->rotation[1] = var_v0->FlagOrRotation;
}

void func_80802120_chhandcart(Actor* arg0)
{
    HandcartMemory* sp34;
    Prop* var_v0;
    Prop* var_v0_2;
    sp34 = (HandcartMemory*)func_80100094(arg0, 0U);
    arg0->scale = 0.425f;
    //Based on if we've spawned the first Item set which location canary mary should think we're at
    arg0->unk64_19 = func_800D0A9C(0xC, 1);
    sp34->unk8F4 = 0;
    sp34->unk4 = 0.0f;
    if (_glcutDll_entrypoint_20() != 0)
    {
        if (func_800EA05C() == MAP_C7_GGM_GLITTER_GULCH_MINE)
        {
            func_80108B04(arg0, 0);
        }
    }
    else
    {
        if ((func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) == 0) || (func_800D0A9C(4, 4) != 0))
        {
            func_80103140(arg0, 0x68BU, arg0->unk0->unk16);
            return;
        }
        switch (func_80800000_chhandcart())
        {
        case 0:
            if (func_800DA298(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE) == 0)
            {
                func_80103140(arg0, 0x68BU, arg0->unk0->unk16);
            }
            func_80802068_chhandcart(arg0, 1 - arg0->unk64_19);
            break;

        case 1:
            if (arg0->unk64_19)
            {
                sp34->unk0 = _glsplinefind_entrypoint_0(0x314, arg0->position);
                var_v0 = _gccubesearch_entrypoint_1(0x15U, arg0->position);
            }
            else
            {
                sp34->unk0 = _glsplinefind_entrypoint_0(0x313, arg0->position);
                var_v0 = _gccubesearch_entrypoint_1(0x16U, arg0->position);
            }
            // @fake
            if (sp34->unk928[0]) {}
            func_800EE88C(sp34->unk928, var_v0->position);
            func_801058C4(arg0, (s16)sp34->unk0, HANDCART_DATA(arg0)->unkC, 0);
            func_80801BA4_chhandcart(arg0);
            break;

        case 2:
            if (arg0->unk64_19)
            {
                var_v0_2 = _gccubesearch_entrypoint_0(0x201, arg0);
            }
            else
            {
                var_v0_2 = _gccubesearch_entrypoint_0(0x1F6, arg0);
            }
            func_800EE88C(sp34->rewardSpawn, var_v0_2->position);
            func_80802068_chhandcart(arg0, arg0->unk64_19);
            if (arg0->unk64_19 && (func_80800090_chhandcart() == 2))
            {
                func_80103140(arg0, 0x68BU, arg0->unk0->unk16);
            }
            break;

        }

        func_80108B04(arg0, 0);
    }
}

void func_80802394_chhandcart(Actor* arg0) 
{
    func_801015D0(arg0);
}

//Play Canary Mary Dialog
void func_808023B4_chhandcart(Actor* arg0, u32 arg1, u32 arg2)
{
    arg2 = arg2 | 0x4;
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x36);
    arg0->unk74_30 = 1;
}

void func_80802400_chhandcart(Actor* arg0, s32 arg1) 
{
    f32 sp1C[3];

    func_800EE7F8(sp1C, arg0->position);
    sp1C[1] += 75.0f;
    if ((arg1 == 0) || (arg1 == 0x1B) || (arg1 == 0x1F)) 
    {
        _capod_entrypoint_19(sp1C);
    }
}

s32 func_80802468_chhandcart(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_a1;
    s32 var_v1;

    switch (arg1)
    {
    case 0x1F:
        func_80802394_chhandcart(arg0);
        break;
    case 0xE:
        func_80802400_chhandcart(func_80106790(arg0->unk3C), arg2);
        return 3;

    case 0xB:
        temp_a1 = func_80106790(arg0->unk3C);
        var_v1 = 0;
        if (arg2 != 0x19)
        {
            if (arg2 == 0x1D)
            {
                var_v1 = 0xF85;
            }
        }
        else
        {
            var_v1 = 0xFAF;
        }
        if (var_v1 != 0)
        {
            func_80800858_chhandcart(arg0, temp_a1, 2, 1);
            func_808023B4_chhandcart(temp_a1, var_v1, 0xB);
        }
        return 4;

    case 0x3D:
        func_80801FFC_chhandcart(arg0);
        break;
    default:
        return 0;
    }
    return 1;

}

void func_8080256C_chhandcart(Actor* arg0, u32 arg1)
{
    ImageStruct *imageStruct;
    s32 var_s0;
    f32 filler;
    f32 sp50[3];
    HandcartMemory* temp_s5;
    temp_s5 = (HandcartMemory*)func_80100094(arg0, 0U);
    func_801018A4(arg0, arg1);
    if (arg0->unk7C_12)
    {
        imageStruct = func_800D674C(0x9E2);
        func_800E2588(2);
        func_800E2594(arg1, imageStruct);
        func_800EFA4C(sp50, 0.06f, 0.03f, 0.06f);
        var_s0 = 0;
        for (var_s0 = 0; var_s0 != 0x3C; var_s0++)
        {
            if (temp_s5->unk87C[var_s0] != 0)
            {
                func_800E2720(arg1, 0, 0, temp_s5->unkC[var_s0 + 0x3C], sp50, temp_s5->unk87C[var_s0]);
            }
        }

        func_800E2A14(arg1);
    }
}

void* chhandcart_entrypoint_0(void) 
{
    return &D_80804DC4_chhandcart;
}

void func_80802690_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* temp_v0;
    f32* sp24;

    temp_v0 = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    //GameSpeed
    temp_v0->unk0 = temp_v0->unk0 - func_800D8FF8();
    switch (func_801022E4(arg0))
    {
    case 0x7D:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808046C0_chhandcart, 0.1f);
        if (((f32)temp_v0->unk0 <= 0.0f) && (func_800DC298(0.03f) != 0) && (func_800C0638() == 0))
        {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808046D4_chhandcart);
            temp_v0->unk0 = 1.5f;
            return;
        }
    default:
        return;
    case 0x89:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E0C_chhandcart);
        return;
    case 0x8A:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E18_chhandcart);
        return;
    case 0x85:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046E8_chhandcart, &D_80804E2C_chhandcart);
        return;
    case 0x80:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E38_chhandcart);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808046E8_chhandcart, 0.9f);
        break;
    }
}

void func_8080282C_chhandcart(Actor* arg0, s32 arg1, s32 arg2) 
{
    Prop* var_v0;

    if (func_80800090_chhandcart() == 1)
    {
        arg1 = 1 - arg1;
    }
    if ((arg1 != 0) || (arg2 != 0))
    {
        var_v0 = _gccubesearch_entrypoint_1(0x385, arg0->position);
    }
    else
    {
        var_v0 = _gccubesearch_entrypoint_1(0x384, arg0->position);
    }
    func_800EE88C(arg0->position, var_v0->position);
    //Controls the rotation of canary mary when spawned in normal GGM
    arg0->rotation[1] = var_v0->FlagOrRotation;
}

void func_808028F0_chhandcart(Actor* arg0)
{
    f32 sp2C[3];
    CanaryMaryMemory* maryMemory;
    maryMemory = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    arg0->unk64_19 = func_800D0A9C(0xC, 1);
    if (_glcutDll_entrypoint_20() != 0)
    {
        //Are we in GGM
        if (func_800EA05C() == MAP_C7_GGM_GLITTER_GULCH_MINE)
        {
            func_8080282C_chhandcart(arg0, 0, 1);
            func_808031D0_chhandcart(arg0, 0x11);
        }
        else //If we're not in GGM
        {
            func_800FFAB0(arg0);
            return;
        }
    }
    else if (func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) != 0) //Canary Mary has been freed from Cage
    {
        //Are we in Canary Cave
        if (func_800EA05C() == MAP_DB_GGM_CANARY_CAVE)
        {
            func_800FFAB0(arg0);
            return;
        }
        switch (func_80800194_chhandcart(arg0))
        {
            case 0: //Default State
                func_8080282C_chhandcart(arg0, 1 - arg0->unk64_19, 0);
                break;

            case 1: //In Race
                //Race Starting (in the Race Map)
                if (arg0->unk64_19)
                {
                    maryMemory->unkC = _glsplinefind_entrypoint_0(0x385, sp2C);
                }
                else
                {
                    maryMemory->unkC = _glsplinefind_entrypoint_0(0x384, sp2C);
                }
                func_80800024_chhandcart(0);
                func_808031D0_chhandcart(arg0, 5);
                break;

            case 2: //Won Race
                func_8080282C_chhandcart(arg0, arg0->unk64_19, 0);
                func_808031D0_chhandcart(arg0, 0xF);
                if (arg0->unk64_19)
                {
                    maryMemory->unkC = _glsplinefind_entrypoint_0(0x389, sp2C);
                }
                func_80800214_chhandcart(arg0);
                break;
        }

        if (func_800DA298(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE) == 0) //If Canary Mary isn't ready yet
        {
            maryMemory->unkC = _glsplinefind_entrypoint_0(0x388, arg0->position);
            func_801058C4(arg0, (s16)maryMemory->unkC, HANDCART_DATA(arg0)->unkC, 0);
            func_808031D0_chhandcart(arg0, 0x14);
        }
    }
    else if (func_800EA05C() != MAP_DB_GGM_CANARY_CAVE) //If we aren't in Canary Cave
    {
        func_800FFAB0(arg0);
        return;
    }
    else
    {
        maryMemory->unkC = _glsplinefind_entrypoint_0(0x384, sp2C);
        func_80802CE8_chhandcart(arg0, 0x18);
    }
    _suexpression_entrypoint_7(arg0, 1, 0x36);
    _suexpression_entrypoint_12(func_80100094(arg0, 1U), 45.0f, 15.0f);
}

void func_80802B74_chhandcart(Actor* arg0) 
{
    if (arg0->unk70_10 == 0x10) 
    {
        func_800904C8(0x28);
    }
    if (func_80100094(arg0, 1U) != NULL) 
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

void func_80802BC8_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* canaryMary;
    f32 sp20;
    float new_var;
    sp20 = 0.1f;
    canaryMary = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    func_80105A9C(arg0, HANDCART_DATA(arg0)->unkC * 10.0f);
    func_80105834(arg0);
    new_var = (func_800F1DCC(arg0->rotation[1], canaryMary->unk4) * HANDCART_DATA(arg0)->unkC) * 0.5f;
    canaryMary->unk8 = (f32)((new_var - canaryMary->unk8) * 0.02f);    arg0->rotation[2] = canaryMary->unk8;
    canaryMary->unk4 = (f32)arg0->rotation[1];
    if (canaryMary->unkE == 0)
    {
        sp20 = 1.0f;
        canaryMary->unkE = 1U;
    }
    arg0->rotation[0] += func_800F1DCC(arg0->unk50 * 0.1f, arg0->rotation[0]) * sp20;
    arg0->rotation[1] += func_800F1DCC(arg0->unk54, arg0->rotation[1]) * sp20;
}

void func_80802CE8_chhandcart(Actor* arg0, s32 arg1)
{
    Actor* sp2C;
    CanaryMaryMemory* canaryMary;
    s32 sp24;
    s32 sp20;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_t1;
    u32 temp_t6;
    canaryMary = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    if (arg0->unk3C != 0)
    {
        sp2C = func_80106790(arg0->unk3C);
    }
    else
    {
        sp2C = NULL;
    }
    switch (arg0->unk70_10)
    {
    case 19:
        arg0->unk64_16 = 1;
        break;

    case 23:
        func_80800AB0_chhandcart(sp2C);
        break;

    case 15:
        func_80090708(0);
        break;

    }

    func_80102424(arg0, arg1);
    switch (arg0->unk70_10)
    {
        case 24:
            _subaddieDll_entrypoint_0(arg0);
            break;

        case 25:
            temp_v0 = func_8008FD70();
            if (temp_v0 != 1)
            {
                if (temp_v0 == 0x4000)
                {
                    func_808023B4_chhandcart(arg0, 0xFA9, 0xB);
                    break;
                }
            }
            else //Play Open
            {
                func_808023B4_chhandcart(arg0, 0xF7F, 0xB);
                break;
            }
            func_80802CE8_chhandcart(arg0, 0x1A);
            break;

    case 26:
        HANDCART_DATA(arg0)->unkC = 40.0f;
        func_801058C4(arg0, *((s16*)(&canaryMary->unkC)), 40.0f, 0);
        func_80802BC8_chhandcart(arg0);
        func_800C01A8(0x6B, 0);
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0, 0x28B0);
        break;

        case 19:
            arg0->unk64_16 = 0;
            break;

        case 20:
            //Loading into GGM from canary cave for cutscene
            //Canary Mary Freed and ready to race
            func_800DA544(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE);
            HANDCART_DATA(arg0)->unkC = 40.0f;
            func_8080090C_chhandcart(sp2C, 0x1F, 0x28B0, arg0->unk0);
            break;

        case 23:
            arg0->unk58 = 1.0f;
            break;

        case 5:
            func_80800998_chhandcart(sp2C, 0U, 5U, sp2C->unk0);
            func_808023B4_chhandcart(arg0, 0xCEC, 3);
            func_801058C4(arg0, *((s16*)(&canaryMary->unkC)), HANDCART_DATA(arg0)->unkC, 0);
            break;

        case 6:
            func_800FDC28(0x15U);
            if (arg0->unk64_19)
            {
                HANDCART_DATA(arg0)->unkC = 25.0f;
            }
            else
            {
                HANDCART_DATA(arg0)->unkC = 15.0f;
            }
            break;

        case 7:
            //Win the Race
            func_80800024_chhandcart(2);
            func_80090658(1);
            break;

        case 8:
            if (func_80105AE8(arg0) < 0.93f)
            {
                func_80800A24_chhandcart(sp2C, arg0->unk64_19 ? (4) : (2), 4);
            }
            else
            {
                func_80800998_chhandcart(sp2C, 1U, 5U, arg0->unk0);
            }
            break;

        case 9:
            //Start the Race (Touching the Cart)
            func_80800024_chhandcart(1);
            func_800FDC28(0U);
            func_80800EE4_chhandcart(sp2C, 0);
            func_80800214_chhandcart(arg0);
            break;

        case 10:
            if (func_80105AE8(sp2C) < 0.93f)
            {
                func_80800A24_chhandcart(sp2C, arg0->unk64_19 ? (3) : (1), 4);
            }
            else
            {
                func_80800998_chhandcart(sp2C, 1U, 5U, sp2C->unk0);
            }
            break;

        case 14:
            arg0->unk58 = 0.5f;
            break;

        case 16:
            if (func_800D0A9C(0xC, 1) != 0) //If we've spawned the first object
            {
                sp24 = 0xF88;
            }
            else
            {
                sp24 = 0xF83;
            }
            func_80800858_chhandcart(sp2C, arg0, 3, 1);
            func_808023B4_chhandcart(arg0, sp24, 3);
            func_800FDC28(0U);
            func_800FC660(0x17U);
            break;

        case 15:
            sp20 = 0;
            func_80090658(0);
            func_80090734(1, arg0->position);
            func_80800858_chhandcart(sp2C, arg0, 2, 1);
            temp_v0_2 = func_80800090_chhandcart();
            switch (temp_v0_2)
            {
            case 1:
                if (func_800D0A9C(0xC, 1) != 0)
                {
                    sp20 = 0xF87;
                }
                else
                {
                    sp20 = 0xF82;
                }
                break;

            case 2:
                if (func_800D0A9C(0xC, 1) != 0)
                {
                    sp20 = 0xF89;
                }
                else
                {
                    sp20 = 0xF84;
                }
                break;

            }

            func_808023B4_chhandcart(arg0, sp20, 0xB);
            break;

        case 18:
            HANDCART_DATA(arg0)->unkC = 40.0f;
            func_801058C4(arg0, *((s16*)(&canaryMary->unkC)), 40.0f, 0);
            func_80802BC8_chhandcart(arg0);
            func_8080090C_chhandcart(sp2C, 0x1B, 0x20B0, arg0->unk0);
            break;

    }

    func_80800F4C_chhandcart(arg0);
}

void func_808031D0_chhandcart(Actor* arg0, s32 arg1) {
    func_80802CE8_chhandcart(arg0, arg1);
    if (arg0->unk3C != 0) 
    {
        func_80800FA0_chhandcart(func_80106790(arg0->unk3C), arg1);
    }
}

void func_80803218_chhandcart(Actor* arg0, Actor* arg1)
{
    f32 var_f12;
    f32 sp18;
    f32 gamespeed;
    float new_var;
    u32 temp_v0;
    if (arg1->unk7C_0)
    {
        var_f12 = func_80105AE8(arg1);
    }
    else
    {
        var_f12 = 1.0f;
    }
    sp18 = func_80105AE8(arg0);
    gamespeed = func_800D8FF8();
    if (gamespeed && gamespeed)
    {
    }
    temp_v0 = arg0->unk64_19;
    if (var_f12 <= (sp18 - 6553 / 65536.0f))
    {
        func_808031D0_chhandcart(arg0, 0x10);
        return;
    }
    if (var_f12 <= (sp18 - ((temp_v0 != 0) ? (1310 / 65536.0f) : (655 / 65536.0f))))
    {
        if ((((temp_v0 != 0) ? (80.0f) : (75.0f)) - 10.0f) < HANDCART_DATA(arg0)->unkC)
        {
            HANDCART_DATA(arg0)->unkC = HANDCART_DATA(arg0)->unkC - (((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed);
        }
    }
    else if ((1310 / 65536.0f + sp18) <= var_f12)
    {
        new_var = (temp_v0 != 0) ? (80.0f) : (75.0f);
        if (HANDCART_DATA(arg0)->unkC < (10.0f + new_var))
        {
            HANDCART_DATA(arg0)->unkC += ((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed;
        }
    }
    else if (HANDCART_DATA(arg0)->unkC < ((temp_v0 != 0) ? (80.0f) : (75.0f)))
    {
        HANDCART_DATA(arg0)->unkC += ((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed;
    }
}



s32 func_80803448_chhandcart(Actor* arg0)
{
    u32 sp48;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 gamespeed;
    gamespeed = func_800D8FF8();
    func_800EE7F8(sp38, arg0->position);
    sp38[1] = sp38[1] + 50.0f;
    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] -= 50.0f;
    if ((func_800BEF00(sp38, sp2C, sp20, 0x20020U) == 0) || sp2C[1] < arg0->position[1])
    {
        arg0->position[1] = (arg0->position[1] - (250.0f * gamespeed));
        return 0;
    }
    return 1;
}

void func_80803514_chhandcart(Actor* arg0)
{
    f32 temp_f0_2;
    f32 sp20;
    f32 var_f0;
    s32 temp_v0;

    arg0->unk54 = func_8010CD28(arg0);
    temp_f0_2 = func_800F1DCC(arg0->rotation[1], arg0->unk54);
    if ((temp_f0_2 < (-10.0f)) || (temp_f0_2 > 10.0f))
    {
        sp20 = func_80101F24(arg0);
        temp_v0 = func_801022E4(arg0);
        switch (temp_v0)
        {
        case 0x80:
            if ((sp20 > 0.75f) && (sp20 < 0.88f))
            {
                func_80102B2C(arg0, 6.0f);
                return;
            }
            break;

        case 0x85:
            if (((sp20 > 0.76f) && (sp20 < 0.99f)) || ((sp20 > 0.25f) && (sp20 < 0.51f)))
            {
                if (temp_f0_2 > 0.0f)
                {
                    var_f0 = -6.0f;
                }
                else
                {
                    var_f0 = 6.0f;
                }
                if (!arg0)
                {
                }
                arg0->rotation[1] = (f32)(arg0->rotation[1] + var_f0);
            }
            break;

        }

    }
}

void func_80803698_chhandcart(Actor *arg0) 
{
    _sudeflect_entrypoint_1(arg0->position, 180.0f, 0.0f, 65.0f, 0x1E);
}

void func_808036D0_chhandcart(s32 arg0, Actor* arg1) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg1, 0U);

    if (0) {}
    if (func_80105998(arg1, 0.9399872f) != 0)
    {
        sp1C->unk8F8 = 0;
        func_80800998_chhandcart(arg1, 1, 5, arg1->unk0);
    }
}

void func_80803730_chhandcart(Actor* arg0, Actor* arg1)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg1, 0U);
    if (arg0->unk0)
    {
    }
    if (func_80105998(arg0, 0.9399872f) != 0)
    {
        sp1C->unk8F8 = 0;
        func_80800998_chhandcart(arg1, 1, 5, arg0->unk0);
    }
}

void func_80803794_chhandcart(Actor* arg0)
{
    f32 sp44;
    Actor* sp40;
    HandcartMemory* sp3C;
    s32 pad[2];

    sp44 = func_800D8FF8();
    if (arg0->unk3C != 0)
    {
        sp40 = func_80106790(arg0->unk3C);
        sp3C = (HandcartMemory*)func_80100094(sp40, 0U);
    }
    else
    {
        sp40 = NULL;
        sp3C = NULL;
    }
    _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0);
    switch (arg0->unk70_10)
    {
    case 24:
        if (func_800DA298(FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG) != 0) //If we have spoken to canary mary in the cage
        {
            if (func_80090270() == 0)
            {
                func_80802CE8_chhandcart(arg0, 0x19);
            }
        }
        else if (func_800DA298(FLAG0_001_STATE_CANARY_MARY_CAGE_BROKEN) == 0) //If we haven't spoken to canary mary in the cage
        {
            if ((_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 0x1F4, 0x46, 6) != 0) && (func_80090178(0x4001) != 0))
            {
                if (func_800DA9E4(FLAG_42A_FTT_CANARY_MARY_CANARY_CAVE, 1) == 0) //If we havent spoken to canary mary set flag to true
                {
                    func_808023B4_chhandcart(arg0, 0xF7E, 0xB);
                }
                else if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0x1F4, 0x46, 6) != 0)
                {
                    func_808023B4_chhandcart(arg0, 0xFA7, 0xB);
                }
            }
        }
        break;
    case 26:
        func_80802BC8_chhandcart(arg0);
        if (func_80105A5C(arg0) != 0)
        {
            //Set Canary Mary Freed (Cutscene leaving Canary Cave inside)
            func_800DA544(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1);
            _glcutDll_entrypoint_6(MAP_C7_GGM_GLITTER_GULCH_MINE, 0x1A);
        }
        break;
    case 20:
        func_80802BC8_chhandcart(arg0);
        if (func_80105A5C(arg0) != 0)
        {
            func_80105634(arg0);
            func_808031D0_chhandcart(arg0, 0x15);
        }
        break;
    case 21:
        if ((func_80803448_chhandcart(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0))
        {
            func_808031D0_chhandcart(arg0, 0x16);
        }
        break;
    case 22:
        if (func_80101DDC(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 0x17);
        }
        break;
    case 23:
        if (arg0->unk58 > 0.0f)
        {
            arg0->unk58 = (f32)(arg0->unk58 - sp44);
        }
        else
        {
            _glcutDll_entrypoint_17();
            func_808031D0_chhandcart(arg0, 2);
        }
        break;
    case 2:
        func_80803698_chhandcart(arg0);
        func_80803514_chhandcart(arg0);
        if (!arg0->unk74_30)
        {
            if (func_80090178(1) != 0)
            {
                if (func_800DA298(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO) != 0)
                {
                    if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0xC8, 0x46, 6) != 0)
                    {
                        //Play the dialog for interacting with Canary Mary while she's next to the cart
                        func_808023B4_chhandcart(arg0, arg0->unk64_19 ? 0xFAE : 0xFAD, 0xB);
                    }
                }
                else if (_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 0xC8, 0x46, 6) != 0)
                {
                    func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
                    func_80800858_chhandcart(sp40, arg0, 2, 0);
                    if (func_800DA298(FLAG_57A_PROGRESS_GGM_CANARY_MARY_FREED_3) != 0) //If canary Mary has been freed get the race rules talk
                    {
                        func_808023B4_chhandcart(arg0, 0xF80, 0xB);
                    }
                    else //Alternate canary Mary introduces herself them gives the race rules talk
                    {
                        func_808023B4_chhandcart(arg0, 0xFB7, 0xB);
                    }
                }
            }
            else if (func_800DA298(FLAG_054_FTT_GGM_DetonatorTalkToCanaryMary) != 0) //if the Detonator has talked to canary mary
            {
                if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 0xC8, 0x46, 6) != 0)
                {
                    func_808023B4_chhandcart(arg0, arg0->unk64_19 ? 0xFB2 : 0xFB1, 0xB);
                }
            }
            else if (_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 0xC8, 0x46, 6) != 0)
            {
                //Set Detonator talks to canary mary flag
                func_800DA544(FLAG_054_FTT_GGM_DetonatorTalkToCanaryMary);
                func_808023B4_chhandcart(arg0, 0xFB0, 0xB);
            }
        }
        break;
    case 5:
        func_80803514_chhandcart(arg0);
        func_80803698_chhandcart(arg0);
        func_80802BC8_chhandcart(arg0);
        break;
    case 6:
        func_80803218_chhandcart(arg0, sp40);
        func_80802BC8_chhandcart(arg0);
        if (func_80105998(sp40, 0.05f) != 0)
        {
            sp3C->unk8F8 = 1;
            func_80800A24_chhandcart(sp40, sp40->unk64_19 ? 3 : 1, 4);
        }
        func_808036D0_chhandcart((s32)arg0, sp40);
        if (func_80105A5C(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 9);
        }
        break;
    case 7:
        func_80803218_chhandcart(arg0, sp40);
        func_80802BC8_chhandcart(arg0);
        func_80803730_chhandcart(arg0, sp40);
        if (func_80090248() != 0)
        {
            func_808031D0_chhandcart(arg0, 8);
        }
        if (func_80105A5C(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 0xC);
        }
        break;
    case 8:
        func_80803218_chhandcart(arg0, sp40);
        func_80802BC8_chhandcart(arg0);
        func_80803730_chhandcart(arg0, sp40);
        if (func_80105A5C(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 0xC);
        }
        break;
    case 9:
        func_808036D0_chhandcart((s32)arg0, sp40);
        if (func_80105A5C(sp40) != 0)
        {
            func_80800EA0_chhandcart(sp40);
            func_80800EE4_chhandcart(sp40, 0);
        }
        if ((func_80803448_chhandcart(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0))
        {
            func_808031D0_chhandcart(arg0, 0xA);
        }
        break;
    case 10:
        func_808036D0_chhandcart((s32)arg0, sp40);
        func_80803698_chhandcart(arg0);
        if (func_80105A5C(sp40) != 0)
        {
            func_80800EA0_chhandcart(sp40);
            func_80800EE4_chhandcart(sp40, 0);
        }
        if (func_80101DDC(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 0xB);
        }
        break;
    case 11:
        func_808036D0_chhandcart((s32)arg0, sp40);
        func_80803698_chhandcart(arg0);
        func_80803514_chhandcart(arg0);
        if (func_80105A5C(sp40) != 0)
        {
            func_80800EE4_chhandcart(sp40, 0);
            func_808031D0_chhandcart(arg0, 0xE);
        }
        break;
    case 12:
        if ((func_80803448_chhandcart(arg0) != 0) && (func_80101E14(arg0, 0.999f) != 0))
        {
            func_808031D0_chhandcart(arg0, 0xD);
        }
        break;
    case 13:
        func_80803698_chhandcart(arg0);
        if (func_80101DDC(arg0) != 0)
        {
            func_808031D0_chhandcart(arg0, 0xE);
        }
        break;
    case 14:
        if (arg0->unk58 > 0.0f)
        {
            arg0->unk58 = (f32)(arg0->unk58 - sp44);
        }
        else
        {
            func_80800214_chhandcart(arg0);
        }
        break;
    case 15:
        func_80803514_chhandcart(arg0);
        func_80803698_chhandcart(arg0);
        break;
    case 18:
        if (HANDCART_DATA(arg0)->unkC < 150.0f)
        {
            HANDCART_DATA(arg0)->unkC = HANDCART_DATA(arg0)->unkC + (50.0f * sp44);
        }
        func_80802BC8_chhandcart(arg0);
        if (func_80105A5C(arg0) != 0)
        {
            func_80105634(arg0);
            if (_gclevel_entrypoint_3(0x18) != 0)
            {
                _glcutDll_entrypoint_6(0x136, 0x55);
            }
            else
            {
                func_80800AB0_chhandcart(sp40);
                sp40->unk3C = 0;
                func_800FFAB0(arg0);
            }
        }
        break;
    }
    func_80802690_chhandcart(arg0);
    if ((sp3C != NULL))
    {
        switch (sp3C->unk8F5)
        {
        case 2:
        case 4:
            func_80800B00_chhandcart(sp40);
            func_80800528_chhandcart(sp40);
            break;
        }
    }
}

//Update Function
s32 func_80803FC4_chhandcart(Actor* arg0, s32 arg1, u32 arg2)
{
    HandcartMemory* temp_t0;
    u32 temp_a0;
    Actor* temp_s0;
    Actor* var_a2;

    if (arg1 >= 0x30)
    {
        if (arg1 == 0x52)
        {
            goto case52;
        }
        return 0;
    }
    switch (arg1)
    {
    case 14:
        func_80802400_chhandcart(arg0, arg2);
        return 3;
    case 47: //Callback from dialog ending
        temp_t0 = (HandcartMemory*)func_80100094(func_80106790(arg0->unk3C), 0U);
        switch (*(s16*)&arg2)
        {
        case 0xF84:
            //Won Race 1
            //Spawn jiggy of flag C
            func_800D1000(0xC, 0x1, temp_t0->rewardSpawn, 1, arg0->unk0);
            break;
        case 0xF89:
            //Won Race 2
            //Spawn Cheato page of flag 4
            func_800D1000(0x4, 0x4, temp_t0->rewardSpawn, 1, arg0->unk0);
            break;
        }
        break;
    case 13:
        temp_s0 = func_80106790(arg0->unk3C);
        switch (arg2 & 0xFFFF)
        {
        case 1:
            func_8080090C_chhandcart(temp_s0, 0x1D, 0x2000, func_80101080());
            break;
        case 4:
            func_8080090C_chhandcart(temp_s0, 0x19, 0x2000, func_80101080());
            break;
        }
        break;
    case 46: //Callback from dialog ending
        if (arg0->unk3C != 0)
        {
            var_a2 = func_80106790(arg0->unk3C);
        }
        else
        {
            var_a2 = NULL;
        }
        switch (*(s16*)&arg2)
        {
            case 0xF7F:
            case 0xFA9:
                //Set Canary Mary Cage Opened
                func_800DA544(FLAG_57A_PROGRESS_GGM_CANARY_MARY_FREED_3);
                func_80802CE8_chhandcart(arg0, 0x1A);
                break;
            case 0xF80:
            case 0xFB7:
                //Canary Mary talk before race 1
                func_80800AB0_chhandcart(var_a2);
                func_808031D0_chhandcart(arg0, 2);
                break;
            case 0xCEC:
                //3..2..1..Go
                func_808031D0_chhandcart(arg0, 6);
                break;
            case 0xF83:
            case 0xF88:
                //Just too slow Reset the race state
                func_808001D0_chhandcart(arg0, 0);
                func_808000B4_chhandcart(arg0);
                func_800904C8(0x28U);
                break;
            case 0xF82:
                //Mary Wins
                func_80800AB0_chhandcart(var_a2);
                func_808031D0_chhandcart(arg0, 2);
                break;
            case 0xF87:
                //Mary Wins
                func_80800AB0_chhandcart(var_a2);
                func_808031D0_chhandcart(arg0, 2);
                break;
            case 0xF85:
                //Canary Mary Wants another Race
                func_80800AB0_chhandcart(var_a2);
                func_808031D0_chhandcart(arg0, 2);
                arg0->unk64_19 = 1;
                var_a2->unk64_19 = 1;
                break;
            case 0xFAF:
                //Canary Mary Leaves CCL
                func_80800AB0_chhandcart(var_a2);
                func_808031D0_chhandcart(arg0, 0x12);
                break;
        }
        arg0->unk74_30 = 0;
        break;
    case52://Such a weird thing to do
        if (func_801022E4(arg0) == 0x7D)
        {
            _gcdialogcamera_entrypoint_3(&D_80804E4C_chhandcart, arg0->scale);
        }
        else
        {
            _gcdialogcamera_entrypoint_3(&D_80804E5C_chhandcart, arg0->scale);
        }
        break;
    case 31:
        func_801015D0(arg0);
        if ((arg0->unk70_10 == 0x18) || (arg0->unk70_10 == 0x19))
        {
            func_800DF744(3, 1);
        }
        else
        {
            func_800DF744(3, 0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080436C_chhandcart(void) 
{
    func_801018A4();
}

void chhandcart_entrypoint_1(Actor* arg0)
{
    func_80101F24(func_80106790((Unk80132ED0*)arg0));
}

void* chhandcart_entrypoint_2(void) 
{
    return &D_80804E6C_chhandcart;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043C0_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043C8_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043D0_chhandcart.s")
