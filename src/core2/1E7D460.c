#include "core2/1E7D460.h"

s32 func_800A3B70() 
{
    return 0x40;
}

void func_800A3B78(PlayerState* arg0, s32 arg1) {
    PlayerState* temp_v0;

    temp_v0 = func_800A4CA8(arg0);
    if (temp_v0 != NULL) {
        func_801106A8(temp_v0, arg1);
    }
}

void func_800A3BA8(PlayerState* arg0, s32 arg1) {
    PlayerState* temp_v0;
    ba_unknown_38_s* temp_v0_2;
    f32 temp_f0;

    temp_v0 = func_800A4CA8(arg0);
    if (temp_v0 != NULL) {
        temp_v0_2 = arg0->unk38;
        switch (temp_v0_2->unk2) {
        case 1:
            temp_f0 = temp_v0_2->unk2C;
            func_80110CC0(temp_v0, (f32) temp_v0_2->unk8 * temp_f0, (f32) temp_v0_2->unkC * temp_f0, (f32) temp_v0_2->unk10 * temp_v0_2->unk30, (f32) temp_v0_2->unk34);
            break;
        case 2:
            temp_f0 = temp_v0_2->unk2C;
            func_80110CC0(temp_v0, (f32) temp_v0_2->unk14 * temp_f0, (f32) temp_v0_2->unk18 * temp_f0, (f32) temp_v0_2->unk1C * temp_v0_2->unk30, (f32) temp_v0_2->unk34);
            break;
        case 3:
            temp_f0 = temp_v0_2->unk2C;
            func_80110CC0(temp_v0, (f32) temp_v0_2->unk20 * temp_f0, (f32) temp_v0_2->unk24 * temp_f0, (f32) temp_v0_2->unk28 * temp_v0_2->unk30, (f32) temp_v0_2->unk34);
            break;
        case 4:
            func_80110CC0(temp_v0, 250.0f, 300.0f, 50.0f, (f32) temp_v0_2->unk34);
            break;
        }
        if (arg1 != 0) {
            func_80115564(temp_v0);
        }
    }
}

void func_800A3D78(PlayerState* arg0, s32 arg1, s32 arg2) {
    ba_unknown_38_s* temp_v0;

    temp_v0 = arg0->unk38;
    if (arg1 != temp_v0->unk2) {
        temp_v0->unk2 = arg1;
        func_800A3BA8(arg0, arg2);
    }
}

u8 func_800A3DAC(PlayerState* arg0) {
    return arg0->unk38->unk2;
}

void func_800A3DB8(PlayerState* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ba_unknown_38_s* temp_v0;

    temp_v0 = arg0->unk38;
    if ((arg1 != temp_v0->unk1) || (arg2 != temp_v0->unk34) || (arg3 != temp_v0->unk39)) {
        temp_v0->unk1 = (u8) arg1;
        temp_v0 = arg0->unk38;
        func_800A59B8(temp_v0->unk1, &temp_v0->unk8, &temp_v0->unkC, &temp_v0->unk10, &temp_v0->unk14, &temp_v0->unk18, &temp_v0->unk1C, &temp_v0->unk20, &temp_v0->unk24, &temp_v0->unk28);
        arg0->unk38->unk34 = (s16) arg2;
        arg0->unk38->unk39 = (u8) arg3;
        if ((func_800A3DAC(arg0) == 3) && ((temp_v0 = arg0->unk38, (temp_v0->unk20 == 0)) || (temp_v0->unk39 != 0))) {
            func_800A3D78(arg0, 2, arg4);
            return;
        }
        func_800A3BA8(arg0, arg4);
    }
}

void func_800A3EC8(PlayerState* arg0, s32 arg1) {
    ba_unknown_38_s* temp_v0;

    temp_v0 = arg0->unk38;
    if (arg1 != temp_v0->unk7) {
        temp_v0->unk7 = arg1;
        func_80110D08(func_800A4CA8(arg0), arg0->unk38->unk7, arg0);
    }
}

void func_800A3F14(PlayerState* arg0, s32 arg1) {
    u8 temp_v1;

    temp_v1 = arg0->unk38->unk6;
    if (arg1 != temp_v1) {
        switch (temp_v1) {
        case 5:
            func_80090C28(arg0, 1);
            break;
        case 7:
            func_800A3D78(arg0, arg0->unk38->unk3A, 1);
            arg0->unk38->unk3A = 0;
            break;
        }
        switch (arg1) {
        case 2:
            func_800A3B78(arg0, 0x13);
            break;
        case 7:
            func_800A3B78(arg0, 0x1A);
            arg0->unk38->unk3A = func_800A3DAC(arg0);
            func_800A3D78(arg0, 4, 1);
            break;
        case 8:
            func_800A3B78(arg0, 0x18);
            break;
        case 6:
            func_800A3B78(arg0, 2);
            break;
        }
        arg0->unk38->unk6 = arg1;
    }
}

void func_800A4030(PlayerState* arg0) {
    if (arg0->unk38->unk6 == 9) {
        func_800A4074(arg0, 9);
        return;
    }
    func_800A4074(arg0, 2);
}

void func_800A4074(PlayerState* arg0, s32 arg1) {
    ba_unknown_38_s* temp_v0;

    func_800A5A4C(arg0);
    func_80090B98(arg0);
    arg0->unk38->unk0 = 0;
    arg0->unk38->unk6 = 0;
    arg0->unk38->unk3 = 0;
    arg0->unk38->unk4 = 0;
    arg0->unk38->unk5 = 0;
    arg0->unk38->unk30 = 1.0f;
    temp_v0 = arg0->unk38;
    temp_v0->unk2C = temp_v0->unk30;
    func_800A3F14(arg0, arg1);
    arg0->unk38->unk2 = 2;
    arg0->unk38->unk1 = 0xFF;
    func_800A3DB8(arg0, 0, 0, 0, 1);
    arg0->unk38->unk7 = 0xFF;
    func_800A3EC8(arg0, 0);
    _batimer_set(arg0, 7, 0.5f);
    arg0->unk38->unk36 = -1;
}

void func_800A4160(PlayerState* arg0)
{

}

void func_800A4168(PlayerState* arg0) {
    arg0->unk38->unk3C = 0;
    func_800A4074(arg0, 2);
}

void func_800A4190(PlayerState* arg0) {
    ba_unknown_38_s* temp_v0;
    u8 temp_v1;

    if ((func_800A4D40(arg0) != 0) && (func_800F65D0(arg0->unk184) != 0) && (func_8009CC68(arg0) == 0) && (func_800F3ED0(arg0) != 4) && (_batimer_get(arg0, 7) == 0.0f) && (bainput_should_exit_first_person(arg0) != 0)) {
        temp_v0 = arg0->unk38;
        if ((temp_v0->unk4 == 0) && (temp_v0->unk3B == 0)) {
            temp_v1 = temp_v0->unk2;
            switch (temp_v1) {
            case 1:
                func_8009DB04(arg0, 0x488, 1.0f, 0x2EE0);
                func_800A3D78(arg0, 2, 1);
                break;
            case 2:
                if ((temp_v0->unk20 != 0) && (temp_v0->unk39 == 0)) {
                    func_8009DB04(arg0, 0x488, 1.2f, 0x2EE0);
                    func_800A3D78(arg0, 3, 1);
                } else {
                    func_8009DB04(arg0, 0x487, 1.0f, 0x2EE0);
                    func_800A3D78(arg0, 1, 1);
                }
                break;
            case 3:
                func_8009DB04(arg0, 0x487, 1.0f, 0x2EE0);
                func_800A3D78(arg0, 1, 1);
                break;
            }
            _batimer_set(arg0, 7, 0.4f);
        }
    }
}

s32 func_800A4338(PlayerState* arg0) {
    s32 sp84;
    s32 stateResult;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    f32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp4C[3];
    s32 sp40[3];

    sp84 = func_80090E24(arg0);
    sp6C = 0;
    sp68 = func_80090E30(arg0);
    sp60 = func_800A5854(sp84);
    switch(sp84)
    {
        default:
            if (func_800A5904(sp84) != 0) 
            {
                if ((arg0->unk38->pad38 == 0) || (sp60 == 4)) 
                {
                    break;
                }
            }
        case -1:
            arg0->unk38->unk4 = func_800A5B9C();
            if (arg0->unk38->unk4 == 5) 
            {
                sp6C = 1;
                arg0->unk38->unk4 = 0;
            }
            func_800A3DB8(arg0, 0, func_800A5B7C(), sp6C, sp68);
            func_800A3EC8(arg0, func_800A5BBC());
            if (arg0->unk38->unk4) 
            {
                func_800A3D78(arg0, arg0->unk38->unk4, sp68);
            } 
            else if (arg0->unk38->pad38 != 0)
            {
                if (arg0->unk38->unk3) 
                {
                    func_800A3D78(arg0, arg0->unk38->unk3, sp68);
                } 
                else 
                {
                    func_80110F44(func_800A4CA8(arg0));
                }
            }
            arg0->unk38->unk5 = func_800A5BAC();
            func_80110D80(func_800A4CA8(arg0), func_800A5BCC());
            func_80110D28(func_800A4CA8(arg0), func_800A5B6C());
            func_80110D58(func_800A4CA8(arg0), func_800A5B8C());
            arg0->unk38->pad38 = 0;
            return 0;
    }

    stateResult = bs_getCurrentState(arg0);
    switch (sp60) 
    {
        case 4:
            func_800A5800(sp84);
            _cadbfunc_entrypoint_26(&sp7C);
            if (sp7C == 0 && (arg0->unk38->pad38 != 0) && (sp84 + 1 != arg0->unk38->pad38) && (arg0->unk38->unk3)) 
            {
                sp7C = arg0->unk38->unk3;
            }
            if (sp84 +1);
            if (sp7C == 5) 
            {
                sp6C = 1;
                sp7C = 0;
            }
            if (sp7C == 0) 
            {
                if (arg0->unk38->unk2 == 4) 
                {
                    sp7C = 1;
                }
            }
            if (arg0->unk38->pad38 == 0) 
            {
                _cadbfunc_entrypoint_29(0x10, &sp78);
                if (sp78 != 0) 
                {
                    arg0->unk38->unk3 = func_800A3DAC(arg0);
                } 
                else 
                {
                    arg0->unk38->unk3 = 0;
                }
            }
            if (sp7C != 0) 
            {
                func_800A3D78(arg0, sp7C, 0);
            }
            arg0->unk38->unk4 = sp7C;
            _cadbfunc_entrypoint_22(&sp74);
            _cadbfunc_entrypoint_24(&sp70);
            func_800A3DB8(arg0, sp70, sp74, sp6C, 0);
            _cadbfunc_entrypoint_29(0x40, &sp78);
            func_800A3EC8(arg0, sp78);
            _cadbfunc_entrypoint_29(0x20, &sp78);
            arg0->unk38->unk5 = sp78;
            _cadbfunc_entrypoint_29(0x80, &sp78);
            func_80110D80(func_800A4CA8(arg0), sp78);
            _cadbfunc_entrypoint_34(&sp74);
            func_80110D28(func_800A4CA8(arg0), sp74);
            _cadbfunc_entrypoint_32(&sp64);
            func_80110D58(func_800A4CA8(arg0), sp64);
            arg0->unk38->pad38 = sp84 + 1;
            return 0;
        case 3:
            if (func_8009CA70(arg0, stateResult, 0x4000) != 0) 
            {
                sp5C = 0;
                func_800A5800(sp84);
                _cadbfunc_entrypoint_29(4, &sp5C);
                if (sp5C == 0) {
                    return 0;
                }
            }
            func_800A3B78(arg0, 0xD);
            _ncbadolly_entrypoint_4(func_800A4CA8(arg0), sp84);
            func_800A3F14(arg0, 4);
            return 1;
        case 1:
            if (func_8009CA70(arg0, stateResult, 0x4000) != 0) 
            {
                sp58 = 0;
                func_800A5800(sp84);
                _cadbfunc_entrypoint_29(4, &sp58);
                if (sp58 == 0) 
                {
                    return 0;
                }
            }
            func_800A3B78(arg0, 6);
            _ncbafixpos_entrypoint_4(func_800A4CA8(arg0), sp84);
            func_800A3F14(arg0, 4);
            return 1;
        case 2:
            if (sp84 && sp84);
            if (sp84 != arg0->unk38->unk36) 
            {
                func_800A5800(sp84);
                _cadbfunc_entrypoint_0(sp4C);
                _cadbfunc_entrypoint_2(sp40);
                func_800CA628(func_800A4C48(arg0), &sp4C, &sp40);
                func_801108A0(func_800A4CA8(arg0));
                arg0->unk38->unk36 = sp84;
            }
            return 0;
        case 7:
            func_800A3B78(arg0, 0x12);
            _ncbaspiral_entrypoint_5(func_800A4CA8(arg0), sp84);
            func_800A3F14(arg0, 4);
            func_800A4190(arg0);
            return 1;
        default:
            return 0;
    }
}


s32 func_800A4878(PlayerState* arg0) {
    PlayerState* sp24;
    PlayerState* temp_v0;

    if (!temp_v0) {
    }
    temp_v0 = func_800A4CA8(arg0);
    sp24 = temp_v0;
    if (arg0->unk38->unk5 != 0) {
        return func_80110EFC(temp_v0, 2, sp24);
    }
    if ((func_800A4D40(arg0) == 0) || (func_8009CC68(arg0) != 0) || (func_800F65D0(arg0->unk184) == 0) || (arg0->unk38->unk3B != 0)) {
        return 0;
    }
    if (bainput_func_80097B4C(arg0) != 0) {
        return func_80110EFC(sp24, 2);
    }
    if (bainput_should_rotate_camera_left(arg0) != 0) {
        return func_80110EFC(sp24, 0);
    }
    if (bainput_should_rotate_camera_right(arg0) != 0) {
        return func_80110EFC(sp24, 1);
    }
    return 0;
}

s32 func_800A4978(PlayerState* arg0) {
    s32 var_a1;

    if (func_800F40EC(arg0) != 2) {
        return 0;
    }

    switch (player_getTransformation(arg0)) {
        case TRANSFORM_B_KAZOOIE:
            var_a1 = 7;
            if (arg0->unk38->unk3 != 0) {
                arg0->unk38->unk3 = 4;
            }
            break;
        case TRANSFORM_C_SUB:
            var_a1 = 8;
            break;
        default:
            var_a1 = 6;
            break;
    }

    func_800A3F14(arg0, var_a1);
    func_800A4878(arg0);
    func_800A4190(arg0);
    return 1;
}


void func_800A4A14(s32 arg0) {
    if (func_800A4338(arg0) == 0) {
        func_800A4190(arg0);
        func_800A4878(arg0);
    }
}

void func_800A4A4C(s32 arg0)
{
    func_800A4190(arg0);
    func_800A4878(arg0);
}

void func_800A4A74(PlayerState* arg0) {
    if ((func_800A4338(arg0) == 0) && (func_800A4978(arg0) == 0)) {
        func_800A4190(arg0);
        if (arg0) {
        }
        func_800A4878(arg0);
        func_800A3F14(arg0, 2);
    }
}

void func_800A4AD0(PlayerState* arg0) {
    if (_ncbaspline_entrypoint_8(func_800A4CA8(arg0)) != 0) {
        func_800A3F14(arg0, 2);
    }
}


void func_800A4B08(PlayerState* arg0) 
{
    _batimer_decrement(arg0, 7);
    if (func_800F65D0(arg0->unk184) != 0) 
    {
        func_80090C34(arg0);
    }
    func_80090C28(arg0, 0);
    switch (arg0->unk38->unk6) 
    {
        case 4:
            if (func_800A4338(arg0) == 0) 
            {
                if (arg0->unk38->unk0 != 0) 
                {
                    func_800A3F14(arg0, 1);
                    func_800A3B78(arg0, arg0->unk38->unk0);
                } 
                else 
                {
                    func_800A3F14(arg0, 2);
                }
                break;
            }
        return;
        case 0:
        case 9:
            break;
            break;
        case 1:
            func_800A4A14(arg0);
        break;
        case 3:
            func_800A4A4C((s32) arg0);
        break;
        case 5:
            func_800A4AD0(arg0);
        break;
        default:
            if (arg0->unk38->unk0 != 0) 
            {
                func_800A3F14(arg0, 1);
                func_800A3B78(arg0, arg0->unk38->unk0);
            } 
            else 
            {
                func_800A4A74(arg0);
            }
        break;
    }
    arg0->unk38->unk3B = 0;
}


f32* func_800A4C48(PlayerState* arg0) {
    return func_800A93F8(arg0->unk184);
}

s32 func_800A4C68(PlayerState* arg0) {
    return func_800A940C(arg0->unk184);
}

s32 func_800A4C88(PlayerState* arg0) {
    return func_800A93E4(arg0->unk184);
}

PlayerState* func_800A4CA8(PlayerState* arg0) {
    PlayerState* var_v1;
    s32 temp_v0;

    temp_v0 = func_800A4C88(arg0);
    if (temp_v0 != 0) {
        var_v1 = func_80110014(temp_v0);
    } else {
        var_v1 = NULL;
    }
    return var_v1;
}

void func_800A4CE8(PlayerState* arg0, f32* arg1) {
    func_800CA7E4(func_800A4C48(arg0), arg1);
}

void func_800A4D14(PlayerState* arg0, s32 arg1) {
    func_800CA9D8(func_800A4C48(arg0), arg1);
}

s32 func_800A4D40(PlayerState* arg0) {
    return func_8010FAE4(func_800A4C88(arg0)) == 2;
}

void func_800A4D6C(PlayerState* arg0, f32 arg1, f32 arg2) {
    arg0->unk38->unk2C = arg1;
    arg0->unk38->unk30 = arg2;
    func_800A3BA8(arg0, 1);
}

void func_800A4DA4(PlayerState* arg0, s32 arg1) {
    u8 temp_v0;

    arg0->unk38->unk0 = (u8) arg1;
    temp_v0 = arg0->unk38->unk6;
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14(arg0, 1);
        func_800A3B78(arg0, arg1);
    }
}

void func_800A4DFC(PlayerState* arg0, s32 arg1) {
    func_800A3F14(arg0, 3);
    func_800A3B78(arg0, arg1);
}

void func_800A4E30(PlayerState* arg0) {
    u8 temp_v0;

    arg0->unk38->unk0 = 0;
    temp_v0 = arg0->unk38->unk6;
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14(arg0, 2);
    }
}

void func_800A4E74(s32 arg0)
{
    func_800A3F14(arg0,0x5);
}

void func_800A4E94(PlayerState* arg0) {
    func_800A3F14(arg0, 9);
    func_80110BF0(func_800A4CA8(arg0));
}

void func_800A4EC8(PlayerState* arg0) {
    func_800A3F14(arg0, 2);
    func_80110C2C(func_800A4CA8(arg0));
}

void func_800A4EFC(PlayerState* arg0, f32 arg1) {
    f32 sp34[3];
    s32 var_a3;
    ba_unknown_38_s* temp_v0;
    f32* var_v1;
    s32 var_v0;

    if (arg0 != NULL) {
        temp_v0 = arg0->unk38;
        if (temp_v0->unk4 == 0) {
            sp34[0] = mlAbsF(arg1 - (f32) temp_v0->unk8);
            sp34[1] = mlAbsF(arg1 - (f32) arg0->unk38->unk14);
            sp34[2] = mlAbsF(arg1 - (f32) arg0->unk38->unk20);
            var_a3 = 0;
            var_v0 = 1;
            var_v1 = &sp34[1];
            do {
                if (*var_v1 < sp34[var_a3]) {
                    var_a3 = var_v0;
                }
                var_v0 += 1;
                var_v1 += 1;
            } while (var_v0 != 3);
            func_800A3D78(arg0, var_a3 + 1, func_80090E30(arg0));
        }
    }
}

void func_800A5004(PlayerState* arg0) {
    if (arg0->unk38->unk3C == 0) {
        arg0->unk38->unk3C = func_800CA334();
        func_800A4E94(arg0);
    }
}

void func_800A5044(PlayerState* arg0) {
    if (arg0->unk38->unk3C != 0) {
        func_800A4EC8(arg0);
        func_800CA364(arg0->unk38->unk3C);
        arg0->unk38->unk3C = 0;
    }
}

s32 func_800A5090(PlayerState* arg0) {
    return arg0->unk38->unk3C;
}

void func_800A509C(PlayerState* arg0) {
    arg0->unk38->unk3B = 1;
}
