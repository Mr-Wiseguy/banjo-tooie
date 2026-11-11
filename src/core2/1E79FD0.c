#include "core2/1E79FD0.h"

extern f32 D_80125490;
extern u8 D_80119250[];
extern u8 D_80119254[];

s32 func_800A06E0() 
{
    return 0x18;
}

void func_800A06E8(s32 arg0) {
    func_800A0714(arg0, func_80092B80());
}


void func_800A0714(PlayerState* arg0, s32 arg1) {
    s32 temp_a1;

    func_800DF3E0();
    switch (arg1) {
    case 0x607:
    case 0x608:
    case 0x61F:
    case 0x992:
        if (arg0->unk138->unk17 == 0) {
            func_800DF744(9, arg0->unk138->unk10);
            func_800DF744(0xF, arg0->unk138->unk10);
            func_800DF744(0xA, arg0->unk138->unkE);
            func_800DF744(0x10, arg0->unk138->unkE);
            func_800DF744(0xB, arg0->unk138->unkD);
            func_800DF744(0x11, arg0->unk138->unkD);
            temp_a1 = arg0->unk138->unkF;
            func_800DF744(0x22, temp_a1);
            func_800DF744(0x26, temp_a1);
            func_800DF744(0x23, temp_a1);
            func_800DF744(0x27, temp_a1);
            temp_a1 = arg0->unk138->unk11 + 1;
            func_800DF744(0x2A, temp_a1);
            func_800DF744(0x2E, temp_a1);
            func_800DF744(0x2B, temp_a1);
            func_800DF744(0x2F, temp_a1);
        }
        func_800DF744(3, arg0->unk138->unk12);
        func_800DF744(4, arg0->unk138->unk12);
        func_800DF744(7, arg0->unk138->unk12);
        func_800DF744(0x12, arg0->unk138->unk12);
        temp_a1 = func_800F1214(arg0->unk138->unk0, 1.0f, 8.0f);
        func_800DF744(0x35, temp_a1);
        func_800DF744(0x39, temp_a1);
        temp_a1 = func_800F1214(arg0->unk138->unk4, 1.0f, 8.0f);
        func_800DF744(0x34, temp_a1);
        func_800DF744(0x38, temp_a1);
        break;
    case 0x61C:
    case 0x83A:
    case 0x993:
        if (arg0->unk138->unk15 != 0) {
            func_800DF744(3, 2);
        } else {
            func_800DF744(3, 1);
        }
        temp_a1 = arg0->unk138->unkF;
        func_800DF744(6, temp_a1);
        func_800DF744(7, temp_a1);
        temp_a1 = arg0->unk138->unk11 + 1;
        func_800DF744(4, temp_a1);
        func_800DF744(5, temp_a1);
        func_800DF744(0x33, func_800F1214(arg0->unk138->unk0, 1.0f, 5.0f));
        func_800DF744(0x32, func_800F1214(arg0->unk138->unk4, 1.0f, 5.0f));
        break;
    case 0x665:
        func_800DF744(4, arg0->unk138->unk13);
        func_800DF744(5, arg0->unk138->unk14);
        func_800DF744(1, func_800F1214(arg0->unk138->unk4, 1.0f, 4.0f));
        break;
    case 0x60D:
        func_800DF744(1, func_800F1214(arg0->unk138->unk0, 1.0f, 4.0f));
        func_800DF744(2, func_800F1214(arg0->unk138->unk4, 1.0f, 4.0f));
        break;
    case 0x609:
        func_800DF744(0x33, func_800F1214(arg0->unk138->unk0, 1.0f, 4.0f));
        func_800DF744(0x32, func_800F1214(arg0->unk138->unk4, 1.0f, 4.0f));
        break;
    case 0x60B:
    case 0x60C:
    case 0x623:
    case 0x624:
    case 0x626:
    case 0x998:
        func_800DF744(0x33, func_800F1214(arg0->unk138->unk0, 1.0f, 5.0f));
        func_800DF744(0x32, func_800F1214(arg0->unk138->unk4, 1.0f, 5.0f));
        break;
    case 0x988:
        temp_a1 = D_80119250[func_800A940C(arg0->unk184)];
        func_800DF744(5, temp_a1);
        func_800DF744(4, temp_a1);
        func_800DF744(3, arg0->unk138->unk16);
        break;
    case 0x98D:
        func_800DF744(4, D_80119254[func_800A940C(arg0->unk184)]);
        break;
    case 0x984:
    case 0x986:
        func_800DF744(1, arg0->unk138->unk16);
        break;
    }
}

s32 func_800A0C20(PlayerState* self) {
    return (s32) self->unk138->unk10;
}

f32 func_800A0C2C(PlayerState* arg0) {
    return arg0->unk138->unk0;
}

f32 func_800A0C38(PlayerState* arg0) {
    return arg0->unk138->unk4;
}

void func_800A0C44(PlayerState* arg0) {
    func_800A0CF4(arg0, 0);
    func_800A0CE8(arg0, 0);
    func_800A0CDC(arg0, 0);
    func_800A0D74(arg0, 0);
    func_800A0D84(arg0, 0);
    func_800A0DB8(arg0, 1);
    func_800A0DD0(arg0, 0);
    func_800A0CD0(arg0, 1);
    func_800A0DC4(arg0, 0);
}

void func_800A0CD0(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk12 = arg1;
}

void func_800A0CDC(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unkD = arg1;
}

void func_800A0CE8(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unkE = arg1;
}

void func_800A0CF4(PlayerState* arg0, s32 arg1) 
{
    func_800A0D14(arg0, arg1, 0.0f);
}

void func_800A0D14(PlayerState* arg0, s32 arg1, f32 arg2) {
    arg0->unk138->unk8 = arg2;
    arg0->unk138->unkC = arg1;
    if (arg2 == 0.0f) {
        arg0->unk138->unk10 = arg1;
    }
}

void func_800A0D44(PlayerState* arg0, s32 arg1) {
    func_800A0D14(arg0, arg1, 0.2f);
}

void func_800A0D68(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk17 = arg1;
}

void func_800A0D74(PlayerState* arg0, f32 arg1) {
    arg0->unk138->unk0 = arg1;
}

void func_800A0D84(PlayerState* arg0, f32 arg1) {
    arg0->unk138->unk4 = arg1;
}

void func_800A0D94(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk16 = arg1;
}

void func_800A0DA0(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk14 = arg1;
}

void func_800A0DAC(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk13 = arg1;
}

void func_800A0DB8(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unkF = arg1;
}

void func_800A0DC4(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk15 = arg1;
}

void func_800A0DD0(PlayerState* arg0, s32 arg1) {
    arg0->unk138->unk11 = arg1;
}

void func_800A0DDC(PlayerState* arg0) {
    if (arg0->unk138->unk8 != 0.0f) {
        arg0->unk138->unk8 -= time_getDelta();
        if (arg0->unk138->unk8 <= 0.0f) {
            arg0->unk138->unk10 = arg0->unk138->unkC;
        }
    }
}

s32 func_800A0E50(void) 
{
    return 0x14;
}

f32 func_800A0E58(PlayerState* arg0) {
    return arg0->unk150->unk8;
}

void func_800A0E64(PlayerState* arg0) {
    f32 sp3C[3];
    s32 temp_s0;
    f32 sp34;

    if (func_80096544(arg0) == 0) {
        return;
    }

    func_8009DBF0(arg0, 0x409, rand_fBounded(D_80125490, 0.75f));
    player_getCoords(arg0, sp3C);
    sp3C[1] = sp34 = func_800964DC(arg0);
    temp_s0 = _fxsplash_entrypoint_2(sp3C, 35.0f);
    _fxripple_entrypoint_0(3, sp3C);
    
    func_800BA930(temp_s0, -350, 300, -350, 350, 500, 350);
    func_800BA22C(temp_s0, 0xA);
    func_800BA930(temp_s0, -150, 500, -150, 150, 800, 150);
    func_800BA22C(temp_s0, 0xA);
    
    _fxsplash25d_entrypoint_0(sp3C);
    sp3C[1] -= 30.0f;
    temp_s0 = _fxairbub_entrypoint_1(sp3C, 20.0f, sp34, 1.0f);
    func_800BA930(temp_s0, -60, -250, -60, 60, -150, 60);
    func_800BA22C(temp_s0, 8);
}

s32 func_800A0FCC(PlayerState* arg0) {
    return arg0->unk150->unk2;
}

s32 func_800A0FD8(PlayerState* arg0) {
    return arg0->unk150->unk0;
}

s32 func_800A0FE4(PlayerState* arg0) {
    return arg0->unk150->unk1;
}

void func_800A0FF0(PlayerState* arg0) {
    arg0->unk150->unk2 = 1;
    arg0->unk150->unk0 = 0;
    arg0->unk150->unk1 = 0;
    arg0->unk150->unk4 = 50.0f;
    arg0->unk150->unk8 = 70.0f;
    arg0->unk150->unkC = -1.0f;
}

void func_800A1040(PlayerState* arg0) {
    arg0->unk150->unk4 = arg0->unk150->unkC;
    arg0->unk150->unk8 = arg0->unk150->unk10;
    arg0->unk150->unkC = -1.0f;
}

void func_800A106C(PlayerState* arg0, f32 arg1, f32 arg2) {
    arg0->unk150->unkC = arg0->unk150->unk4;
    arg0->unk150->unk10 = arg0->unk150->unk8;
    arg0->unk150->unk4 = arg1;
    arg0->unk150->unk8 = arg2;
}

void func_800A10A0(PlayerState* arg0) {
    f32 sp2C;
    s32 sp28;
    s32 sp24;

    sp28 = arg0->unk150->unk0;
    sp2C = func_800964DC(arg0) - arg0->unk150->unk4;
    if (sp28 != 0) {
        arg0->unk150->unk0 = (func_80096524(arg0) != 0) && (player_getCoordVertical(arg0) < (sp2C + 2.0f));
    } else {
        arg0->unk150->unk0 = (func_80096524(arg0) != 0) && (player_getCoordVertical(arg0) < (sp2C - 2.0f));
    }
    if ((sp28 == 0) && (arg0->unk150->unk0 != 0) && (baphysics_get_vertical_velocity(arg0) < -40.0f)) {
        func_800A0E64(arg0);
    }
    sp24 = func_800F3ED0(arg0);
    if (func_800A0FD8(arg0) != 0) {
        arg0->unk150->unk1 = 1;
    } else if ((player_isStable(arg0) != 0) || (sp24 == 0xA) || (sp24 == 5)) {
        arg0->unk150->unk1 = 0;
    }
    arg0->unk150->unk2 = func_80096518(arg0);
}
