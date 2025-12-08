#include "ch/warppad.h"

#define WARPPAD_DATA(arg0) ((WarppadActorData*)(arg0->actorData))

extern u8 D_8012762C;

extern ActorData D_808012FC_chwarppad;
extern f32 D_8080134C_chwarppad[3];
extern u8 D_80801080_chwarppad[0x20];
extern D_808010A0 D_808010A0_chwarppad[4];
extern D_808010B0 D_808010B0_chwarppad[31];
extern u32 D_80801344_chwarppad;
extern u32 _gcnewoption_entrypoint_35;

ActorData* chwarppad_entrypoint_0(void) {
    return &D_808012FC_chwarppad;
}

void func_8080000C_chwarppad(Actor* arg0, u32 arg1)
{
    OptionState* temp_v0;

    if (func_800EB854() == 3)
    {
        temp_v0 = (OptionState*)func_80100094(arg0, 0U);
        if (temp_v0 != NULL)
        {
            _gcnewoption_entrypoint_1(temp_v0, arg1);
        }
    }
    else
    {
        func_80101870(arg0, arg1);
    }
}

//Is the warppad at index available
s32 func_80800064_chwarppad(Actor* arg0, s32 warppadIndex)
{
    if ((arg0->unk74_7 == (warppadIndex + 0x32)))
    {
        return 0;
    }
    return func_800DA298((WARPPAD_DATA(arg0)->unk14 * 5) + warppadIndex + 0x3AB);
}
//Get the number of warppads unlocked in the level
s32 func_808000B4_chwarppad(Actor* arg0)
{
    s32 i;
    s32 numPads;

    numPads = 0;
    for (i = 1; i <= WARPPAD_DATA(arg0)->unk4; i++)
    {
        if (func_80800064_chwarppad(arg0, i) != 0)
        {
            numPads += 1;
        }
    }
    return numPads;
}

void func_80800124_chwarppad(Actor* arg0, OptionState* arg1)
{
    s32 i;
    s32 var_s1;

    var_s1 = 0;
    _gcnewoption_entrypoint_32(arg1, 0x6F);

    for (i = 1; i <= WARPPAD_DATA(arg0)->unk4; i++)
    {
        if (func_80800064_chwarppad(arg0, i) != 0)
        {
            _gcnewoption_entrypoint_31(arg1, var_s1, (s16)(&D_808010B0_chwarppad[WARPPAD_DATA(arg0)->unk10])[i].unk5);
            var_s1 += 1;
        }
    }
}

void func_808001F4_chwarppad(Actor* arg0, OptionState* arg1)
{
    s32 var_s0;
    u32 var_s1 = 0;

    for (var_s0 = 1; WARPPAD_DATA(arg0)->unk4 >= var_s0; var_s0++)
    {
        if (func_80800064_chwarppad(arg0, var_s0) != 0)
        {
            _gcnewoption_entrypoint_12(arg1, var_s1, (var_s0 + 9));
            if (func_80090178(D_808010B0_chwarppad[WARPPAD_DATA(arg0)->unk10 + var_s0].unk8) != 0)
            {
                _gcnewoption_entrypoint_23(arg1, var_s1);
                _gcnewoption_entrypoint_13(arg1, var_s1, &D_80801344_chwarppad);
            }
            var_s1++;
        }
    }
}

s32 func_808002F4_chwarppad(Actor* arg0, s32 arg1)
{
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    for (var_s0 = 1; WARPPAD_DATA(arg0)->unk4 >= var_s0; var_s0++)
    {
        if (func_80800064_chwarppad(arg0, var_s0) != 0)
        {
            if (var_s1 == arg1)
            {
                return var_s0;
            }
            var_s1 += 1;
        }
    }
    return -1;
}

//Is this warp pad active
s32 func_80800380_chwarppad(Actor* arg0)
{
    return func_800DA298(WARPPAD_DATA(arg0)->unk14 * 5 + (arg0->unk74_7) + 0x379);
}

//Enable warppad
void func_808003B8_chwarppad(Actor* arg0)
{
    func_800DA544(WARPPAD_DATA(arg0)->unk14 * 5 + (arg0->unk74_7) + 0x379);
    _subaddiefade_entrypoint_4(arg0);
    _chappearfx_entrypoint_1(arg0, 2, 3, 0.8f);
}

void func_80800418_chwarppad(Actor* arg0, u32 arg1)
{
    s32 temp_v0;
    OptionState* sp28;
    //If we want to change the warp pad state
    if (arg1 != arg0->unk70_10)
    {
        switch (arg0->unk70_10) //Check previous state
        {
        case 2: //We Just activated a warp pad
            if (func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0)
            {
                //Enable Movement
                func_80090708(0);
            }
            if (func_808000B4_chwarppad(arg0) > 0)
            {
                func_800DA544(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE);
            }
            break;
        case 3: //Close the option menu
            _gcnewoption_entrypoint_6((OptionState*)arg0, 0U);
            //Enable Movement
            func_80090708(0);
            func_8010A828(arg0, 2);
            break;
        }
        arg0->unk70_10 = arg1;
        switch (arg1)
        {
        case 2: //This warp pad was disabled and someone walked near it
            if (func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0)
            {
                //Disable Movement
                func_80090708(1);
                return;
            }
            func_808003B8_chwarppad(arg0);
            return;
        case 3:
            //Open the options menu
            temp_v0 = func_808000B4_chwarppad(arg0);
            _gcnewoption_entrypoint_4(arg0, 0, &_gcnewoption_entrypoint_35, 0, WARPPAD_DATA(arg0)->unk14 + 0x185A);
            sp28 = func_80100094(arg0, 0U);
            func_800C78CC(1U);
            //If the number of warppads exceeds 4 only show up to 4 at a time
            _gcnewoption_entrypoint_8(sp28, temp_v0 >= 5 ? 4 : temp_v0);
            _gcnewoption_entrypoint_9(sp28, temp_v0);
            _gcnewoption_entrypoint_10(sp28, 0U);
            func_80800124_chwarppad(arg0, sp28);
            _gcnewoption_entrypoint_14(sp28, 0, 0, 0, 0.0f);
            _gcnewoption_entrypoint_40(sp28, 0x41, 0x22, 0x20U, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42(sp28, 0.1f);
            _gcnewoption_entrypoint_11(sp28);
            func_80090708(2);
            func_80800F34_chwarppad(arg0, 5, 1);
            func_8010A828(arg0, 0xA);
            return;
        case 4: //Actually Warp
            func_800DA544(FLAG3_9FE_WARPING_VIA_WARPPAD);
            _gcgoto_entrypoint_1(func_80800E10_chwarppad(D_808010B0_chwarppad[WARPPAD_DATA(arg0)->unk18 + WARPPAD_DATA(arg0)->unk10].unk0), D_808010B0_chwarppad[WARPPAD_DATA(arg0)->unk18 + WARPPAD_DATA(arg0)->unk10].unk4);
            break;
        }
    }
}

s16 func_808006C0_chwarppad(s32 arg0)
{
    TransformationId temp_v0;
    u32 temp_a2;
    s32 var_a1;

    temp_a2 = D_8012762C;
    //Get Transformation
    temp_v0 = func_8008FD48();
    for (var_a1 = 0; D_808010A0_chwarppad[var_a1].unk2 != 0; var_a1++)
    {
        if ((temp_a2 == D_808010A0_chwarppad[var_a1].unk2) && (temp_v0 == D_808010A0_chwarppad[var_a1].unk3))
        {
            return D_808010A0_chwarppad[var_a1].unk0;
        }
    }
    return D_808010A0_chwarppad[var_a1].unk0;
}

void func_80800748_chwarppad(Actor* arg0)
{

    s32 numUnlockedWarppads;
    s32 controlledCharacter;
    s32 sp34;

    func_800DA524(FLAG3_9FE_WARPING_VIA_WARPPAD);
    switch (arg0->unk70_10)
    {
    case 1: //If we are standing near the warppad
        if (func_8010C9FC(arg0->position, 0xFA, 0xC8, -0x32) != 0)
        {
            numUnlockedWarppads = func_808000B4_chwarppad(arg0);
            controlledCharacter = func_800F54E4();
            if (func_80800380_chwarppad(arg0) == 0)
            {
                //Activate Warp Pad
                func_80800418_chwarppad(arg0, 2U);
            }
            else if ((numUnlockedWarppads > 0) && (func_800F64A4(controlledCharacter, *(s32*)&(D_80801080_chwarppad - 0x220)[(WARPPAD_DATA(arg0)->unk10 * 0xC) + ((arg0->unk74_7) * 0xC)]) == 0) && (_subaddiedialog_entrypoint_4(arg0->position, 0x64, 4) != 0))
            {
                //Open the Options Menu
                func_80800418_chwarppad(arg0, 3U);
            }
            //Handles when you press the B button while standing near the warppad
            else if ((func_80016B30(0, 1) == 1) && (func_800F8004(controlledCharacter) == 0) && (func_800F4BB8(controlledCharacter, -1, 4) != 0))
            {
                if (numUnlockedWarppads > 0)
                {
                    if (func_800F64A4(controlledCharacter, *(s32*)&(D_80801080_chwarppad - 0x220)[(WARPPAD_DATA(arg0)->unk10) * 0xC + ((arg0->unk74_7)) * 0xC]) != 0) 
                    {
                        sp34 = func_808006C0_chwarppad((s32)arg0);
                    }
                    else
                    {
                        sp34 = 0xCF0;
                    }
                }
                else
                {
                    sp34 = 0xCEF;
                }
                func_80800F34_chwarppad(arg0, 5, 1);
                _subaddiedialog_entrypoint_11(arg0->unk0, sp34, 0xF, NULL, 0);
            }
        }
        break;
    case 2:
        if ((func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0) && !(arg0->unk74_30))
        {
            if (_subaddiedialog_entrypoint_11(arg0->unk0, func_808000B4_chwarppad(arg0) == 0 ? 0xCED : 0xCEE, 0xA, arg0->position, 0) != 0)
            {
                arg0->unk74_30 = 1;
                func_808003B8_chwarppad(arg0);
                if (func_800F64A4(func_800F54E4(), ALLOW_TREXLARGE | ALLOW_GOLDENGOLIATH) == 0)
                {
                    func_80800F34_chwarppad(arg0, 4, 1);
                }
            }
        }
        if (_subaddiefade_entrypoint_0(arg0) == 0xFF)
        {
            func_80800418_chwarppad(arg0, 1U);
        }
        break;
    case 3:
        _gcnewoption_entrypoint_0(func_80100094(arg0, 0U));
        break;
    }
    if (arg0->unk64_19)
    {
        arg0->unk64_19 = 0;
    }
}

s32 func_80800A1C_chwarppad(Actor* arg0, u32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x91:
        arg0->unk64_19 = 1;
    case 0x95:
        break;
    case 0x2E:
        func_80800AB8_chwarppad(arg0, *(s16*)&arg2, *((s16*)&arg2 + 1));
        break;
    case 0x20:
        func_80800B34_chwarppad(arg0, (OptionState*)func_80101080(), *(s16*)&arg2, *((s16*)&arg2 + 1));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800AB8_chwarppad(Actor* arg0, s32 arg1, s32 arg2)
{
    func_80801018_chwarppad(arg0);
}

u8 func_80800ADC_chwarppad(s32 arg0)
{
    s32 temp_v0;
    u8 var_a0;
    u32 var_v1 = 0;
    //Get Transformation
    temp_v0 = func_8008FD48();
    var_a0 = D_80801080_chwarppad[0];
    for (var_v1 = 0; D_80801080_chwarppad[var_v1] != 0; var_v1 += 2)
    {
        if (temp_v0 == D_80801080_chwarppad[var_v1])
        {
            return D_80801080_chwarppad[var_v1 + 1];
        }
    }
    return 0;
}

void func_80800B34_chwarppad(Actor* arg0, OptionState* arg1, s32 arg2, s32 arg3)
{
    u32 sp24;
    u32 temp_v0;
    switch (arg3)
    {
    case 3:
        sp24 = func_808002F4_chwarppad(arg0, arg2);
        if (_gcnewoption_entrypoint_19(arg1, arg2) != 0)
        {
            temp_v0 = func_80800ADC_chwarppad((s32)arg0);
            if (temp_v0 != 0)
            {
                _gcnewoption_entrypoint_34(arg1, temp_v0);
            }
        }
        else
        {
            WARPPAD_DATA(arg0)->unk18 = sp24;
            func_80800418_chwarppad(arg0, 4);
        }

        break;
    case 0:
        func_808001F4_chwarppad(arg0, arg1);
        break;
    case 2:
        func_800C78CC(0);
        func_80800418_chwarppad(arg0, 1);
        func_80801018_chwarppad(arg0);
        break;
    }
}

void func_80800C00_chwarppad(Actor* arg0)
{
    s32 var_a2;
    u32 levelIndex;
    s32 sp3C;
    f32 sp30[3];

    levelIndex = D_8012762C;
    //Get Character in control
    sp3C = func_800F54E4();
    var_a2 = 0;
    while (D_808010B0_chwarppad[var_a2].unk0 != -2)
    {
        if (D_808010B0_chwarppad[var_a2].unk0 == -1)
        {
            if (levelIndex == D_808010B0_chwarppad[var_a2].unk4)
            {
                break;
            }
            WARPPAD_DATA(arg0)->unk14 += 1;
        }
        var_a2++;
    }
    WARPPAD_DATA(arg0)->unk8 = _subaddiesect_entrypoint_1(arg0);
    WARPPAD_DATA(arg0)->unk10 = var_a2++;
    while (D_808010B0_chwarppad[var_a2].unk0 != -2) 
    {
        if (D_808010B0_chwarppad[var_a2].unk0 == -1)
        {
            break;
        }
        var_a2++;
    }

    WARPPAD_DATA(arg0)->unk4 = ((var_a2 - WARPPAD_DATA(arg0)->unk10) - 1);
    func_80800418_chwarppad(arg0, 1U);
    _subaddiefade_entrypoint_8(arg0, func_80800380_chwarppad(arg0) != 0 ? 0xFF : 0x87);
    if (WARPPAD_DATA(arg0)->unk8 != -1U)
    {
        _subaddiesect_entrypoint_2(arg0, WARPPAD_DATA(arg0)->unk8, 1);
    }
    func_8010A828(arg0, 2);
    if ((func_800DA298(FLAG3_9FE_WARPING_VIA_WARPPAD) != 0) && (func_800EA090() == (D_80801080_chwarppad - 0x224)[(WARPPAD_DATA(arg0)->unk10) * 0xC + arg0->unk74_7 * 0xC]))
    {
        func_800EE7F8(sp30, arg0->position);
        sp30[1] += 15.0f * arg0->scale;
        func_800F608C(sp3C, 1);
        func_800F8294(sp3C, sp30);
        func_800F497C(sp3C);
        func_800C78CC(0U);
        func_800DA524(FLAG3_9FE_WARPING_VIA_WARPPAD);
    }
}

s32 func_80800E10_chwarppad(s32 arg0)
{
    u32 sp2C;
    u32 temp_a2;
    u32 temp_t6;

    temp_a2 = (arg0 & 0xFFFF) + 0xB0000000;
    temp_t6 = ((arg0 & 0xFFFF0000) >> 0x10);
    if (temp_a2 & 2) 
    {
        temp_a2 = (temp_a2 >> 2) << 2;
        rom_read_word(temp_a2, &sp2C);
        arg0 = (sp2C & 0xFFFF0000) >> 0x10;
    }
    else 
    {
        rom_read_word(temp_a2, &sp2C);
        arg0 = sp2C & 0xFFFF;
    }

    if (temp_t6 != 0) 
    {
        temp_t6 += 0xB0000000;
        if (temp_t6 & 2) 
        {
            temp_t6 = (temp_t6 >> 2) << 2;
            rom_read_word(temp_t6, &sp2C);
            arg0 += (sp2C & 0xFFFF0000) >> 0x10;
        }
        else 
        {
            rom_read_word(temp_t6, &sp2C);
            arg0 += sp2C & 0xFFFF;
        }
    }
    return arg0 + 0xA0;
}

void func_80800EF8_chwarppad(Actor* arg0)
{
    if (func_80100094(arg0, 0) != 0)
    {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
    func_80801018_chwarppad(arg0);
}

void func_80800F34_chwarppad(Actor* arg0, s32 arg1, s32 arg2)
{
    f32 sp2C[3];
    f32* var_a1;

    if (!(arg0->unk64_20))
    {
        func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
        _capod_entrypoint_2(arg0->unk0, 0x1AU, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, &D_8080134C_chwarppad);
        _capod_entrypoint_10(0, arg0->position);

        if (arg1 == 4)
        {
            var_a1 = sp2C;
        }
        else
        {
            var_a1 = arg0->rotation;
        }
        _capod_entrypoint_11(0, var_a1);
        _gcdialogcamera_entrypoint_8();
        arg0->unk64_20 = 1;
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    _capod_entrypoint_7(arg1, arg2);
}

void func_80801018_chwarppad(Actor* arg0)
{
    if (arg0->unk64_20)
    {
        _capod_entrypoint_3(0);
        arg0->unk64_20 = 0;
        _subaddieDll_entrypoint_4(arg0, 0U);
    }
}