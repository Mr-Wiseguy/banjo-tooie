#include "ch/cheato.h"

extern f32 D_80800E50_chcheato[4];
extern ActorData D_80800E98_chcheato;
extern s32 D_80800EE0_chcheato;
extern s16 D_80800EE6_chcheato;
extern s16 D_80800EF4_chcheato;
extern f32 D_80800EFC_chcheato[2];
extern s16 D_80800F04_chcheato[2];
extern s32 D_80800F08_chcheato;
extern s16 D_80800F20_chcheato[3];
extern s16 D_80800F28_chcheato[3];
extern u32 _gcnewoption_entrypoint_16;
void func_808003C4_chcheato(Actor*);
void func_80800434_chcheato(Actor*, s32, s32);
void func_808006B8_chcheato(Actor*);
void func_8080078C_chcheato(Actor*);
s32 func_80800824_chcheato(s32*);
s32 func_80800888_chcheato(void);
void func_808008B8_chcheato(OptionState*, s32);
void func_80800AB4_chcheato(Actor*, OptionState*, s32, s32);
void func_80800B00_chcheato(Actor*);
s32 func_80800BB8_chcheato();
s32 func_80800C0C_chcheato(void);
s32 func_80800C64_chcheato(Actor*, s32, s32);
void func_80800CC0_chcheato(Actor*);
void func_80800D08_chcheato(Actor*,s32,s32);

ActorData* chcheato_entrypoint_0(void) {
    return &D_80800E98_chcheato;
}

void func_8080000C_chcheato(Actor* arg0)
{
    _subaddieitem_entrypoint_0(func_80100094(arg0, 1U), 0x4E3U, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 1U), 5);
    func_8010A828(arg0, 9U);
}

void func_80800068_chcheato(Actor* arg0)
{
    f32 sp34[3];

    _sudeflect_entrypoint_0(arg0->position, 150.0f, 150.0f, 0xA);
    func_808006B8_chcheato(arg0);
    func_8080078C_chcheato(arg0);
    inventory_showValue(0x4A);
    switch (arg0->unk70_10)
    {
    case 1:
        if (!(arg0->unk64_19) && (func_8010D23C() != 0))
        {
            arg0->unk54 = func_8010CD28(arg0);
            func_80102B2C(arg0, 4.0f);
            func_808003C4_chcheato(arg0);
            return;
        }
    default:
        return;
    case 3:
        func_80103DFC(arg0, sp34);
        if (_subaddieitem_entrypoint_3(arg0, sp34, func_80100094(arg0, 1U)) != 0)
        {
            func_80102424(arg0, 2);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x115DU, 0xEU, arg0->position, 0x37U);
            return;
        }
        break;
    case 4:
        if (func_800C0638() == 0)
        {
            func_80800D08_chcheato(arg0, 2, 1);
            func_80800B00_chcheato(arg0);
            return;
        }
        break;
    case 5:
        _gcnewoption_entrypoint_0(func_80100094(arg0, 0U));
        return;
    case 6:
        _gcnewoption_entrypoint_6((OptionState*)arg0, 0U);
        func_80090708(0);
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        break;
    }
}

s32 func_80800204_chcheato(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_80800434_chcheato(arg0, ((s16*)(&arg2))[0], ((s16*)(&arg2))[1]);
        break;
    case 0x49:
        if (arg2 == 1)
        {
            arg0->unk64_19 = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1143U, 4U, arg0->position, 0x37U);
            _capod_entrypoint_13(arg0->unk0, NULL, 1U, 0x830U);
        }
        break;
    case 0x20:
        func_80800AB4_chcheato(arg0, func_80101080(), ((s16*)(&arg2))[0], ((s16*)(&arg2))[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, arg0->scale);
        break;
    case EVENT_95_ACTOR_SPAWNED:
        arg0->unk64_20 = 0;
        break;
    case 0x57:
        return func_80800C64_chcheato(arg0, arg2 & 0xFFFF, (s32)((u32)(arg2 & 0xFFFF0000) >> 0x10));
    default:
        return 0;
    }
    return 1;
}

void func_8080035C_chcheato(Actor* arg0, void* arg1)
{
    if (func_800EB854() == 3)
    {
        if (arg0->unk70_10 == 5)
        {
            _gcnewoption_entrypoint_1(func_80100094(arg0, 0U), arg1);
        }
    }
    else
    {
        func_80101870(arg0, arg1);
    }
}

void func_808003C4_chcheato(Actor* arg0)
{
    s32 sp1C;
    s32 temp_v0;

    sp1C = 0xE;
    D_80800EE6_chcheato = func_80800824_chcheato(&sp1C);
    D_80800EF4_chcheato = (s16)sp1C;
    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0->position, &D_80800EE0_chcheato);
    if ((temp_v0 != 0) && (temp_v0 != 0x1208))
    {
        func_80800D08_chcheato(arg0, 3, 0);
    }
}

void func_80800434_chcheato(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 sp2C;

    switch (arg1)
    {
    case 0x1144:
        _subaddieitem_entrypoint_2(func_80100094(arg0, 1U));
        func_80102424(arg0, 3);
        return;
    case 0x115D:
        _subaddiedialog_entrypoint_11(arg0->unk0, func_80800888_chcheato(), 0xEU, arg0->position, 0x37U);
        return;
    case 0x1142:
        if (inventory_getValue(0x4A) != 0)
        {
            sp2C = 0xE;
            _subaddiedialog_entrypoint_11(arg0->unk0, func_80800824_chcheato(&sp2C), sp2C, arg0->position, 0x37U);
            return;
        }
        func_800C01A8(0x64, 0);
        func_800C0850();
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x1145:
        if (func_80800C0C_chcheato() != 0)
        {
            func_80102424(arg0, 4);
            return;
        }
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x1147:
        func_80102424(arg0, 4);
        return;
    case 0x1148:
        flag_setValueTrue(0x69);
        if (func_80800C0C_chcheato() != 0)
        {
            func_80102424(arg0, 4);
            return;
        }
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x114B:
    case 0x114C:
    case 0x114D:
    case 0x114E:
    case 0x114F:
        if ((inventory_getValue(0x4A) >= 5) && (func_80800BB8_chcheato() != -1))
        {
            _subaddieitem_entrypoint_2(func_80100094(arg0, 1U));
            func_80102424(arg0, 3);
            return;
        }
        if (flag_getValue(0x69) == 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1148U, 0xEU, arg0->position, 0x37U);
            return;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x115EU, 0xEU, arg0->position, 0x37U);
        return;
    case 0x1143:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_17();
        return;
    case 0x115E:
        func_80102424(arg0, 4);
        return;
    default:
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    }
}

void func_808006B8_chcheato(Actor* arg0)
{
    f32 sp44[2] = D_80800EFC_chcheato;
    //f32* var_s1;
    s16 temp[2] = D_80800F04_chcheato;
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 2; var_s0++)
    {
        if (func_80101E14(arg0, sp44[var_s0]) != 0)
        {
            func_800C4B7C(temp[var_s0]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800F08_chcheato);
        }
    }
}

void func_8080078C_chcheato(Actor* arg0)
{
    s32 temp_v0;

    temp_v0 = func_8010CAC0(arg0->position, 0x2EEU);
    if (!(arg0->unk64_20))
    {
        if (temp_v0 != 0)
        {
            func_800FC63C(0x44U, 0U);
            func_800FCAE0(0x44U, -1U, 0x1F4U);
            arg0->unk64_20 = 1;
        }
    }
    else if (temp_v0 == 0)
    {
        func_800FCAE0(0x44U, 0U, 0x1F4U);
        func_800FCA90(0x44U);
        arg0->unk64_20 = 0;
    }
}


s32 func_80800824_chcheato(s32* arg0)
{
    s32 sp1C;
    s32 var_v0;

    sp1C = inventory_getValue(0x4A);
    if (func_80800BB8_chcheato() == -1)
    {
        return 0x1147;
    }

    if (sp1C < 5)
    {
        *arg0 |= 1;
        return 0x1145;

    }
    return 0x1144;
}

s32 func_80800888_chcheato(void)
{
    s32 temp_v0;
    temp_v0 = func_80800BB8_chcheato();
    func_800D3EF4(temp_v0);
    return temp_v0 + 0x114A;
}


void func_808008B8_chcheato(OptionState* arg0, s32 arg1)
{
    s32 temp;
    if (_gcnewoption_entrypoint_17() != 0)
    {
        s16 sp2C[3] = D_80800F20_chcheato;
        _gcnewoption_entrypoint_13(arg0, arg1, sp2C);
        _gcnewoption_entrypoint_12(arg0, arg1, ((arg1 * 2) + 3));
    }
    else if (_gcnewoption_entrypoint_19(arg0, (s32)arg1) != 0)
    {
        s16 sp24[3] = D_80800F28_chcheato;
        _gcnewoption_entrypoint_13(arg0, arg1, sp24);
        _gcnewoption_entrypoint_12(arg0, arg1, ((arg1 * 2) + 4));
    }
}

void func_8080098C_chcheato(s32 arg0, OptionState* arg1)
{
    _gcnewoption_entrypoint_14(arg1, 0U, 1U, 2U, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20U, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0x37U);
}

void func_80800A04_chcheato(OptionState* arg0)
{
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s0;

    temp_v0 = func_80800C0C_chcheato();
    var_s0 = 0;
    for (var_s0 = 0; var_s0 < temp_v0; var_s0++)
    {
        temp_s1 = var_s0 + 1;
        if (func_800D3E14(temp_s1) != 0)
        {
            _gcnewoption_entrypoint_21(arg0, var_s0);
        }
        else
        {
            _gcnewoption_entrypoint_23(arg0, var_s0);
        }
        func_808008B8_chcheato(arg0, var_s0);
        _gcnewoption_entrypoint_31(arg0, (s32)var_s0, func_800D3FC0(temp_s1));
    }

}

void func_80800AB4_chcheato(Actor* arg0, OptionState* arg1, s32 arg2, s32 arg3)
{
    switch (arg3)
    {
    case 0:
        func_80800A04_chcheato(arg1);
        return;
    case 2:
        func_80102424(arg0, 6);
        return;
    }
}

void func_80800B00_chcheato(Actor* arg0)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    OptionState* temp_s0;

    sp2C = func_80800C0C_chcheato();
    _gcnewoption_entrypoint_4(arg0, 0U, &_gcnewoption_entrypoint_16, (u32)&_gcnewoption_entrypoint_35, 0x1849);
    temp_s0 = func_80100094(arg0, 0U);
    _gcnewoption_entrypoint_8(temp_s0, ml_min_i(5, sp2C));
    _gcnewoption_entrypoint_9(temp_s0, (u32)sp2C);
    _gcnewoption_entrypoint_10(temp_s0, 1U);
    func_8080098C_chcheato((s32)arg0, temp_s0);
    _gcnewoption_entrypoint_11(temp_s0);
    func_80102424(arg0, 5);
    func_80090708(2);
}

s32 func_80800BB8_chcheato(void) {
    s32 var_s0;

    for (var_s0 = 1; var_s0 < 6; var_s0++)
    {
        if (func_800D3DD0(var_s0) == 0)
        {
            return var_s0;
        }
    }
    return -1;
}

s32 func_80800C0C_chcheato(void)
{
    s32 var_s0;
    s32 var_s1;
    var_s1 = 0;
    for (var_s0 = 1; var_s0 < 6; var_s0++)
    {
        if (func_800D3DD0(var_s0) != 0)
        {
            var_s1 += 1;
        }
    }
    return var_s1;
}

s32 func_80800C64_chcheato(Actor* arg0, s32 arg1, s32 arg2)
{
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0)
    {
        if ((arg0->unk6C_0) != 2)
        {
            func_80800D08_chcheato(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80800CC0_chcheato(Actor* arg0)
{
    if (arg0->unk6C_0)
    {
        _capod_entrypoint_3(0U);
        arg0->unk6C_0 = 0;
    }
}

void func_80800D08_chcheato(Actor* arg0, s32 arg1, s32 arg2)
{

    switch (arg0->unk6C_0)
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x19U, 0);
    case 1:
        _capod_entrypoint_8(1);
        arg0->unk6C_0 = 2;
        _gcdialogcamera_entrypoint_3(D_80800E50_chcheato, arg0->scale);
        _gcdialogcamera_entrypoint_4(arg0->position);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}
