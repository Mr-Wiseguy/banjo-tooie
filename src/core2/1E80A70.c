#include "core2/1E80A70.h"

extern s32 D_8011A3F0;
extern s32 D_8011A3F4;
extern f32 D_801255F8;
extern D_80127630_unk D_80127630;
extern s16 D_80127632;
extern GraphicsBuffers D_80127658;
extern s32 D_80127674;
extern unkStruct800CA334* D_801276BC;
extern f32 D_80127638;
extern s32 D_80127650;
extern u8 D_8012762C;
extern f32 D_801255F0;
extern f32 D_8012763C;
extern u8 D_80127647;
extern s32 D_80127678;
extern s16 D_80127634;
extern f32 D_801255F4;
extern s32 D_8011A3F8[];
extern s32 D_8011A418;

extern unkStructD_8011A420 D_8011A420[];

extern unk_D_80127688 D_80127688[];
extern unk_D_80127670 D_80127670;

GraphicsBuffers* func_800A7180(void)
{
    return &D_80127658;
}

void func_800A718C(void)
{
    func_800E3BFC(0, 0, 0);
    func_800E3C58(-30.0f, 30.0f, 0);
    func_800E3900(D_801255F0);
    func_800E3CE8();
}

void func_800A71E0(void) {
    s32 i;

    func_800D58CC();
    func_8001A570();
    func_8001B840();
    for (i = 0; i < 15; i++) {
        func_8001B518(1);
        func_800DF874();
        _cosectionstor_entrypoint_2();
        func_800C9484();
        func_800B5E3C();
        func_800D58AC();
        func_800E4C7C();
        func_800CA174();
        func_800FCD5C();
        func_800A9D00();
        func_800C9484();
        func_800B4380();
        func_8008BA5C();
        func_800DA1E0();
        inventory_defrag();
    }
}

void func_800A72A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) D_8012762C;
    sp18 = _gcsectionDll_entrypoint_4(arg0);
    func_800E96E0();
    _gcsectionDll_entrypoint_1(1);
    if ((arg3 != 0) || (arg2 != 0) || (sp18 != sp1C)) {
        _gclevel_entrypoint_1();
        if (arg3 != 0) {
            _gcgame_entrypoint_1();
            _gcgame_entrypoint_0(1);
        }
        _gclevel_entrypoint_0(arg0, arg1);
    }
    _gcsectionDll_entrypoint_0(arg0, arg1);
    func_801101C0();
    func_800A8D70(arg0, arg1);
    func_80081724();
    func_800EA0CC(arg0, arg1, 0);
    func_800A718C();
}

void func_800A7380(s32 arg0) {
    func_800EA0A8();
    func_800A8F68();
    func_800C2AB8();
    func_800FB968();
    func_8001A2B0();
    func_800D6C64();
    func_800D58CC();
    func_8008B768();
    func_80081724();
    if (arg0 != 0) {
        func_800A71E0();
    }
}

void func_800A73F4(s32 arg0, s32 arg1) {
    Mtx* sp24;
    Vtx* sp20;

    sp24 = D_80127658.mtx;
    sp20 = D_80127658.vtx;
    do {} while (0);
    func_800A8670();
    func_800A9378();
    func_800F5184();
    func_800A8BA8(&D_80127658.gfx, arg1);
    while (func_800A8BD4(&D_80127658.gfx, -1, arg1) != 0) {
        func_800E9F20(func_800A89F8(), arg1);
    }
    func_800A8CCC(&D_80127658.gfx, arg1);
    if (D_80127632 == 5) {
        func_800A9AA4(&D_80127658.gfx);
    }
    if (func_800EA358() != 0) {
        func_800EB51C(3, &D_80127658.gfx);
    }
    func_800C0984(&D_80127658.gfx);
    func_800C9358(&D_80127658.gfx, arg1);
    func_800C0130(&D_80127658.gfx);
    if (func_800EA358() != 0) {
        func_800EB51C(4, &D_80127658.gfx);
    }
    func_800FA508(&D_80127658.gfx);
    func_800B7448(&D_80127658.gfx);
    func_800C940C(&D_80127658.gfx, arg1);
    func_800E7EF4(&D_80127658.gfx);
    osWritebackDCache(sp24, (D_80127658.mtx - sp24) * sizeof(Mtx));
    osWritebackDCache(sp20, (D_80127658.vtx - sp20) * sizeof(Vtx));
    func_800F51A8();
    func_800D36A8();
    func_800FFC90();
    func_800A89BC(0);
}

void func_800A7584(s32 arg0, s32 arg1)
{
    D_80127630.unk1A = arg0 + 1;
    D_80127630.unk1B = arg1;
}

void func_800A759C(s32 arg0, s32 arg1) {
    s32 sp1C;

    sp1C = D_80127632;
    if (((D_80127632 == 3) && (arg0 != 4)) || ((D_80127632 == 4) && (arg0 != 3))) {
        func_800C9B84();
    }
    if ((D_80127632 == 4) && (arg0 != 4)) {
        func_800C0920();
    }
    if (D_80127632 == 5) {
        func_800A9AF8();
    }
    D_80127632 = arg0;
    switch (D_80127632) {
    case 2:
        func_800EA148(3);
        break;
    case 5:
        func_800A9998();
    case 3:
        if (sp1C != 4) {
            func_800EA148(2);
        }
        if ((arg1 != 0) && (D_80127647 == 0)) {
            func_800C9598();
        }
        D_8012763C = 0.0f;
        break;
    case 4:
        func_800EA334(0);
        func_8001608C();
        func_800C08F8();
        break;
    }
}

void func_800A76F4(s32 arg0) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    func_800FB968();
    _glintrosyncDll_entrypoint_0(D_80127630.mapValue);
    func_8001A2B0();
    sp34 = D_80127630.unk16;
    sp30 = D_80127630.unk15;
    sp2C = D_80127630.unk14;
    sp28 = D_80127630.mapValue;
    sp24 = (u8)D_80127630.entranceIndex;
    sp20 = D_80127630.unk0;
    D_80127630.unk16 = 0;
    D_80127630.unk15 = 0;
    D_80127630.unk14 = 0;
    D_80127630.mapValue = 0;
    D_80127630.entranceIndex = 0;
    func_800A759C(2, 0);
    D_80127630.unk1C = arg0;
    func_800A5CF0(0);
    if ((func_800DA9E4(0x647, 0) == 0) || (_gcsectionDll_entrypoint_4(D_80127630.mapValue) == D_8012762C)) {
        if (flag_getValue(0x650) == 0) {
            _cosectionstor_entrypoint_3(func_800EA05C());
        }
    }
    func_800A7380(1);
    func_800A72A4(sp28, sp24, sp30, sp34);
    func_800A5CF0(1);
    func_800A5C94();
    func_80081724();
    _glintrosyncDll_entrypoint_1();
    D_80127630.unk0 = sp20;
    D_80127630.unk1C = 2;
    func_800A759C(arg0, sp2C);
    func_80015768();
}

void func_800A7840(s32 arg0) {
    Gfx* sp1C;
    Gfx* sp18;

    func_8001A4B8(&D_80127658);
    if (D_80127634 != 0) {
        func_8001A4B8(&D_80127658);
    }
    sp1C = D_80127658.gfx;
    func_800A73F4(func_80014F58(), arg0);
    if (D_80127634 == 0) {
        sp18 = D_80127658.gfx;
        func_80015410();
        if (D_80127650 == 0) {
            if (func_8001BD50(D_801255F4) != 0) {
                func_800A7FD4();
            }
        }
        func_800E82EC();
        func_8001A270(sp1C, sp18);
    }
    func_80015878();
    func_800E4628();
    D_80127634 = 0;
    D_80127650 = 0;
}

void func_800A791C(s32 arg0, s32 arg1, s32 arg2)
{
    func_800A79D4(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

void func_800A794C(s32 arg0, s32 arg1, s32 arg2) {
    func_800FE8EC();
    func_800A7A18(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

void func_800A7990(s32 arg0, s32 arg1, s32 arg2) {
    func_800FE8EC();
    func_800A7A6C(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

void func_800A79D4(s32 arg0, s32 arg1) {
    func_800FE4E4();
    D_80127630.unk16 = 1;
    D_80127630.unk15 = 0;
    D_80127630.mapValue = (s16) arg0;
    D_80127630.entranceIndex = (s8) arg1;
}

void func_800A7A18(s32 arg0, s32 arg1) {
    func_800FE8EC();
    D_80127630.unk16 = 0;
    D_80127630.unk15 = 1;
    D_80127630.mapValue = (s16) arg0;
    D_80127630.entranceIndex = (s8) arg1;
}

void func_800A7A5C(void) 
{
    D_80127630.unk18 = 1;
}

void func_800A7A6C(s32 arg0, s32 arg1) {
    D_80127630.unk16 = 0;
    D_80127630.mapValue = arg0;
    D_80127630.entranceIndex = arg1;
    D_80127630.unk15 = D_80127630.unk18;
    D_80127630.unk18 = 0;
}

void func_800A7A90(s32 arg0) {
    D_80127630.unk14 = (u8) arg0;
    D_80127630.unk17 = 0;
    if ((arg0 != 0) && (func_800C9510() == 0)) {
        func_800C9610();
    }
}

void func_800A7AD4(s32 arg0, s32 arg1) {
    D_80127630.unk14 = arg0;
    D_80127630.unk17 = arg1;
    if ((arg0 != 0) && (func_800C9510() == 0)) {
        func_800C964C(arg1);
    }
}

//Set Warp Bit To On
void func_800A7B18(u32 warpVal)
{
    D_80127630.unk12 = warpVal;
}

void func_800A7B24(void) {
    func_800A759C(2, 0);
    func_80013430();
    func_800B5DF4();
    func_800CA060();
    func_800DF35C();
    func_800A7380(0);
    _gcsectionDll_entrypoint_1(0);
    _gclevel_entrypoint_1();
    _gcgame_entrypoint_1();
    func_8008B64C();
    func_800FB908();
    func_800C2A90();
    func_800A8710();
    func_800E4290();
    _glcutDll_entrypoint_2();
}

void func_800A7BB8(s32 arg0) {
    func_800A5CF0(1);
    D_80127630.unk12 = 0;
    D_80127630.mapValue = D_80127630.unk12 & 0xFF & 0xFF & 0xFF & 0xFF;
    D_80127630.unk16 = 0;
    D_80127630.unk15 = 0;
    D_80127630.unk17 = 0;
    D_80127630.unk14 = 0;
    D_80127630.entranceIndex = 0;
    D_80127630.unk1A = 0;
    D_80127630.unk1B = 0;
    D_80127630.unk4 = 0;
    func_800A8240();
    func_800DA238();
    func_800DA268();
    _glglobaldata_entrypoint_0();
    _glglobalsettings_entrypoint_1();
    _glgamedata_entrypoint_0();
    func_800D3970();
    func_800E4278();
    func_800A861C();
    func_800C2A08();
    func_800FB808();
    _glcutDll_entrypoint_3();
    func_800CA098();
    func_800D34A0();
    func_800B5DD4();
    func_800133A0();
    func_800DF38C();
    func_8008B610();
    func_800DC310();
    func_8001A290();
    func_800D8F84();
    _gsattract_entrypoint_4();
    func_800EBB5C();
    _gcgame_entrypoint_0(0);
    D_80127630.unk2 = 2;
    D_80127630.unk8 = 0.0f;
    func_800D8FA0(0);
    _gclevel_entrypoint_0(arg0, 0);
    _gcsectionDll_entrypoint_0(arg0, 0);
    func_800A71E0();
    func_800A72A4(arg0, 0, 0, 0);
    D_80127630.unk0 = 0;
    func_800A759C(3, 1);
}


void func_800A7D30(void) {
    if (D_80127638 == 0.0f) {
        func_800D8FA0(0);
        return;
    }
    func_800D8FA0(func_80014F4C());
}

s32 func_800A7D84(void)
{
    s32 sp1C;
    s32 temp_v0;

    D_80127630.unk8 += time_getDelta();


    if (func_800C9510() == 0)
    {

        temp_v0 = D_80127630.unk12;
        D_80127630.unk12 = 0U;
        if (temp_v0 != 0)
        {
            switch (temp_v0)
            {
            case 1:
                func_800A76F4(3);
                return 0;
            case 2:
                func_800A76F4(D_80127630.unk2);
                return 0;
            case 3:
                func_800A9924(D_80127630.mapValue, D_80127630.entranceIndex);
                func_800A76F4(5);
                return 0;
            }
        }
        temp_v0 = D_80127630.unk1A;
    }

    if (D_80127630.unk1A != 0)
    {
        func_800A759C(D_80127630.unk1A - 1, D_80127630.unk1B);
        D_80127630.unk1A = 0U;
    }
    sp1C = func_800EA170();

    if ((D_8011A3F4 != 0) && (D_8011A3F0 == 0))
    {
        func_800A8278();
    }
    func_800C7900();
    func_800C427C();
    func_800FB968();
    switch (D_80127630.unk2)
    {
        case 5:
            func_800A9A14();
            break;
        case 3:
            D_80127630.unkC += time_getDelta();
            if ((D_801255F8 < D_80127630.unkC) && (func_800C0A34() != 0))
            {
                func_800A759C(4, 0U);
            }
            else if (sp1C == 0)
            {
                func_800A759C(3, 1U);
            }
            break;
        case 4:
            if (func_800C0948() != 0)
            {
                func_800EA334(1);
                func_800EA34C(1);
                func_800A759C(3, 0U);
                func_800FFC14();
                func_800F8850();
            }
    }
    if (func_800A819C() != 0)
    {
        func_800CA0A8();
    }
    func_800C92A8();
    return 1;

}

void func_800A7FB4(s32 arg0, s32 arg1)
{
    func_800A7584(arg0,arg1);
}



// do_tidy
void func_800A7FD4(void) {
    D_80127650 = 1;
    func_8001B84C();
    func_8001B840();
    defragment_overlays();
    func_8001B518(0);
    func_801015C8();
    func_80017840();
    func_800D8674();
    func_8008BA5C();
    func_800B5A6C();
    func_800A5654();
    func_800DF874();
    func_800A95C4();
    func_800F86D8();
    func_800F91EC();
    func_800B562C();
    func_800BF58C();
    func_800BD600();
    func_800CCFEC();
    func_800A5D6C();
    func_800B5E3C();
    func_800DA1E0();
    inventory_defrag();
    func_8010E030();
    func_800C075C();
    if (D_80127630.unk2 == 4) {
        func_800C08C0();
    }
    func_801005B8();
    func_800D6D68();
    func_80100E54();
    func_800BFFF4();
    func_800C9074();
    func_800DBB64();
    func_800E8B3C();
    func_800A86D8();
    func_800EE670();
    func_800ABA20();
    func_800FA608();
    func_800E8A20();
    func_800A9D00();
    func_800C9484();
    func_800B4380();
    func_800EB7A8();
    func_800D88C0();
    func_800FFE08();
    func_8001B858();
}

void func_800A8168(void) {
    D_80127630.unk4 = 1;
}

s16 func_800A8178(void) {
    return D_80127630.unk4;
}

s16 func_800A8184(void) {
    return D_80127630.unk2;
}

u8 func_800A8190(void) {
    return D_80127630.unk1C;
}

int func_800A819C(void) {
    return D_80127630.unk2 == 3 || D_80127630.unk2 == 5;
}

int func_800A81C4(void) {
    s32 a, b;
    if (D_80127630.mapValue == 0) {
        return 0;
    }
    a = _gcsectionDll_entrypoint_4(D_80127630.mapValue);
    b = _gcsectionDll_entrypoint_4(func_800EA05C());
    return b != a && D_80127630.unk6 == 0;
}

void func_800A8230(void) {
    D_80127630.unk6 = 1;
}

void func_800A8240(void) {
    D_80127630.unk6 = 0;
}

s16 func_800A824C(void) {
    return D_80127630.unk6;
}

f32 func_800A8258(void) {
    return D_80127630.unk8;
}

int func_800A8264(void) {
    return D_80127630.unk12 != 0;
}

void func_800A8278(void) {
    s32 i;
    s32 temp_a0;
    s32 sp28[14];

    D_8011A3F4--;
    func_80015E80(0, sp28);
    func_80015F28(0, &sp28[6]);
    func_80015FFC(0, &sp28[9]);
    sp28[13] = func_80015F84(0);
    temp_a0 = D_8011A3F8[D_8011A418];
    if (sp28[temp_a0] == 1) {
        D_8011A418++;
    }
    for (i = 0; i != 14; i++) {
        if ((i != temp_a0) && (sp28[i] == 1)) {
            D_8011A418 = 0;
            break;
        }
    }
    if (D_8011A3F8[D_8011A418] == -1) {
        D_8011A3F0 = 1;
    }
}


s32 func_800A8380(s32 arg0) {
    s32 var_v1;
    s32 var_a0;
    s32* new_var;

    if (D_80127670.unk8 == 0) {
        var_v1 = 1;
    } else {
        var_v1 = 7;
    }
    var_a0 = D_80127670.unk0;
    new_var = &var_a0;
    switch (var_a0) {
    case 2:
        return var_v1 + arg0;
    case 3:
        if (var_v1 == 1) {
            var_a0 = var_v1;
            if (arg0 != 0) {
                return arg0 + 4;
            }
            return *new_var;
        }
        var_a0 = var_v1;
        if (arg0 != 0) {
            var_a0 = arg0 << 1;
            return (*new_var) + 2;
        }
        return *new_var;
    case 4:
        return arg0 + 3;
    }
    return 0;
}

void func_800A8424(s32 arg0, s32* arg1, s32* arg2, s32* arg3, s32* arg4) {
    *arg1 = D_8011A420[arg0].unk0 * D_80127670.unkC;
    if (D_8011A420[arg0].unk0 == 1) {
        *arg1 = *arg1 + 1;
    }
    *arg2 = D_8011A420[arg0].unk2 * D_80127670.unk10;
    if (D_8011A420[arg0].unk2 != 0) {
        *arg2 = *arg2 + 1;
    }
    *arg3 = D_8011A420[arg0].unk4 * D_80127670.unkC;
    if (D_8011A420[arg0].unk4 == 1) {
        *arg3 = *arg3 - 1;
    }
    *arg4 = D_8011A420[arg0].unk6 * D_80127670.unk10;
    if (D_8011A420[arg0].unk6 == 1) {
        *arg4 = *arg4 - 1;
    }
}

void func_800A84EC(s32 arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (D_80127688[arg0].unk0 != 0) {
        func_800158E4(D_80127688[arg0].unk0);
    }
    func_800A8424(arg1, &sp34, &sp30, &sp2C, &sp28);
    D_80127688[arg0].unk0 = func_8001592C(sp34, sp30, sp2C, sp28);
    D_80127688[arg0].unk8 = 40.0f;
    if (D_80127688[arg0].unk4 != 0) {
        func_80015CE8(D_80127688[arg0].unk0, D_80127688[arg0].unk4);
    }
    func_800C54CC(arg0, 40.0f, 1.0f);
}

void func_800A85A8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_80127688[i].unk0 != 0) {
            func_800A84EC(i, func_800A8380(i));
        }
    }
    func_800A84EC(4, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A861C.s")

void func_800A8670(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if ((D_80127688[i].unk0 != 0) && (D_80127688[i].unk4 != 0)) {
            func_800C54F0(i);
        }
    }
}

void func_800A86D8(void)
{
    if (D_801276BC != 0)
    {
        D_801276BC = func_800CA384(D_801276BC);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8710.s")

s32 func_800A877C(s32 arg0) {
    if (D_80127688[arg0].unk0 != 0) {
        return 1;
    }
    if (arg0 >= D_80127670.unk0) {
        D_80127670.unk0 = arg0 + 1;
        func_800A85A8();
    }
    func_800A84EC(arg0, func_800A8380(arg0));
    return 1;
}

s32 func_800A87FC(s32 arg0) {
    s32 i;

    if (D_80127688[arg0].unk0 == 0) {
        return 0;
    }
    func_800158E4(D_80127688[arg0].unk0);
    D_80127688[arg0].unk0 = 0;
    D_80127688[arg0].unk4 = 0;
    if ((arg0 + 1) == D_80127670.unk0) {
        D_80127670.unk0 = 0;
        for (i = 0; i < 4; i++) {
            if (D_80127688[arg0].unk0 != 0) {
                D_80127670.unk0++;
            }
        }
        func_800A85A8();
    }
    if (D_80127670.unk0 == 0) {
        func_800E42B4(D_801276BC);
    }
    return 1;
}

unkStruct800CA334* func_800A88C4(s32 arg0, unkStruct800CA334* arg1) {
    unkStruct800CA334* sp1C;

    if (D_80127688[arg0].unk0 == 0) {
        return 0;
    }
    sp1C = D_80127688[arg0].unk4;
    D_80127688[arg0].unk4 = arg1;
    func_80015CE8(D_80127688[arg0].unk0, arg1);
    if (arg0 == D_80127674) {
        func_800E42B4(D_80127688[arg0].unk4);
    }
    return sp1C;
}

unkStruct800CA334* func_800A8948(s32 arg0)
{
    unkStruct800CA334* temp_v0;

    if (D_80127688[arg0].unk0 == 0)
    {
        return 0;
    }
    temp_v0 = D_80127688[arg0].unk4;
    D_80127688[arg0].unk4 = 0;
    return temp_v0;
}

unkStruct800CA334* func_800A8984(s32 arg0) 
{
    return D_80127688[arg0].unk4;
}

s32 func_800A89A0(s32 arg0) 
{
    return D_80127688[arg0].unk0;
}

void func_800A89BC(s32 arg0)
{
    D_80127674 = arg0;
    func_800E42B4(D_80127688[arg0].unk4);
}

s32 func_800A89F8()
{
    return D_80127674;
}

void func_800A8A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_80015CC0(D_80127688[arg0].unk0, arg1, arg2, arg3, arg4);
}


void func_800A8A44(s32 arg0, s32* arg1, s32* arg2, s32* arg3, s32* arg4) {
    func_800A8424(func_800A8380(arg0), arg1, arg2, arg3, arg4);
}

void func_800A8A88(s32 arg0, f32 arg1) {
    D_80127688[arg0].unk8 = arg1;
    if (D_80127688[arg0].unk4 != 0) {
        func_800CA558(D_80127688[arg0].unk4, arg1);
    }
}

f32 func_800A8AD4(s32 arg0) 
{
    return D_80127688[arg0].unk8;
}

void func_800A8AF0(s32 arg0)
{
    func_80015D14(D_80127688[arg0].unk0);
}

void func_800A8B24(Gfx** arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp24 = D_80127688[D_80127674].unk0;
    func_80015CC0(sp24, &sp34, &sp30, &sp2C, &sp28);
    func_800E7FB0(sp34, sp30, sp2C, sp28);
    func_800E7EC0(arg0);
    func_800157EC(sp24, arg0);
}

void func_800A8BA8(Gfx** arg0, s32 arg1)
{
    D_80127674 = -1;
    func_800E7E70(arg0);
}

s32 func_800A8BD4(Gfx** arg0, s32 arg1, s32 arg2) {
    if (arg1 >= 0) {
        D_80127670.unk4 = arg1 - 1;
    }
    if ((D_80127670.unk4 >= 0) && (D_80127688[D_80127670.unk4].unk4 != 0)) {
        func_800C5668(D_80127670.unk4, arg0);
    }
    D_80127670.unk4++;
    for (; D_80127670.unk4 < 4; D_80127670.unk4++) {
        if (D_80127688[D_80127670.unk4].unk0 != 0) {
            break;
        }
    }
    if (D_80127670.unk4 >= 4) {
        return 0;
    }
    func_800A89BC(D_80127670.unk4);
    func_800A8B24(arg0, arg2);
    return 1;
}

void func_800A8CCC(Gfx** arg0, s32 arg1)
{
    func_800A89BC(4);
    func_800A8B24(arg0, arg1);
}

void func_800A8D00(s32 arg0, s32 arg1) {
    if ((arg0 != D_80127670.unkC * 2) || (arg1 != D_80127670.unk10 * 2)) {
        D_80127670.unkC = arg0 / 2;
        D_80127670.unk10 = arg1 / 2;
        func_800A85A8();
    }
}
