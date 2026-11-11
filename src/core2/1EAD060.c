#include "common.h"
#include "core2/1EAD060.h"

extern s8 D_8012B3F3;
extern u8 D_8012B3F2;
extern s8 D_8012B3F1;
extern unkStruct8012B3F0 D_8012B3F0;
extern u8 D_8012762C;
extern s16 D_8012B3FC;
extern s8 D_8012B3F4;
extern s8 D_8012B3F5;
extern s16 D_8012B3FC;

s32 func_800D3770() {
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    s32 new_var;

    new_var = 0;
    var_a0 = D_8012762C < 0xF;

    do {} while (0);
    
    var_v1 = var_a0 ^ 1;
    if (var_v1 != new_var) {
        var_v1 = D_8012762C < 0x1C;
    }
    
    var_a0 = var_v1;
    if (D_8012762C == 0x11) {
        var_a0 = new_var;
    }
    
    var_v0 = (D_8012B3F1 + 1) != new_var;
    if (var_v0 != new_var) {
        new_var = var_a0 != new_var;
        return var_v0 = new_var;
    }
}

void func_800D37C0(s32 arg0) {
    D_8012B3F0.unk0 = arg0;
    D_8012B3F0.unk1 = arg0;
}

void func_800D37D4(void) {
    D_8012B3F0.unk1 = -1;
    D_8012B3F0.unk0 = D_8012B3F0.unk1;
}

s8 func_800D37F0(void) {
    return D_8012B3F1;
}

void func_800D37FC(void) {
    if (D_8012B3F0.unk9 == 3) {
        _glgamedata_entrypoint_2(func_8001B798(D_8012B3F0.unk6));
        func_8001B754(D_8012B3F0.unk6);
        D_8012B3F0.unk1 = D_8012B3F0.unk8;
        D_8012B3F0.unk3 = D_8012B3F0.unkB;
        D_8012B3F0.unk2 = D_8012B3F0.unkA;
        D_8012B3F0.unk9 = 0;
        D_8012B3F0.unk8 = -1;
        D_8012B3F0.unk6 = 0;
    }
    if (D_8012B3F0.unk0 != -1) {
        _glsavegame_entrypoint_8(D_8012B3F0.unk0);
        D_8012B3F0.unk0 = -1;
    }
    func_800D3C70();
}

void func_800D389C(void) {
    s8 temp_t7;

    if (func_800D3770() != 0) {
        _glsavegame_entrypoint_7(D_8012B3F0.unk1);
    }
    if (D_8012B3F0.unk9 == 1) {
        D_8012B3F0.unk6 = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798(D_8012B3F0.unk6));
        D_8012B3F0.unk8 = D_8012B3F0.unk1;
        D_8012B3F0.unkB = D_8012B3F0.unk3;
        D_8012B3F0.unkA = D_8012B3F0.unk2;
        D_8012B3F0.unk1 = -1;
        D_8012B3F0.unk9 = 2U;
    }
}

s32 func_800D3934(void) {
    return D_8012B3F2 == 1;
}

s32 func_800D3948(void) {
    return D_8012B3F2 == 3;
}

s32 func_800D395C(void) {
    return D_8012B3F2 == 2;
}

void func_800D3970(void) {
    func_800D37D4();
    func_800D3A14(1);
    func_800D3CF8(0);
    func_800D3D10(1);
}

void func_800D39A8(void) {
    D_8012B3FC = func_800B2DC0(0x14, 1);
}


void func_800D39D0(s32 arg0) {
    D_8012B3F2 = arg0;
}

void func_800D39DC(s32 arg0) {
    if (arg0 >= 0) {
        func_800D3B6C(1, &func_800D39D0, arg0, 0, 0);
    }
}


void func_800D3A14(s32 arg0) {
    D_8012B3F3 = arg0;
}

void func_800D3A20(s32 arg0) {
    func_800D3B6C(1, &flag_setValueTrue, arg0, 0, 0);
}

void func_800D3A54(s32 arg0, s32 arg1) {
    func_800D3B6C(2, &ability_setValue, arg0, arg1, 0);
}

void func_800D3A88(void) {
    func_800D3B6C(0, &func_800C7010, 0, 0, 0);
}

void func_800D3ABC(s32 arg0, s32 arg1) {
    func_800D3B6C(3, &func_800D1864, arg0, arg1, 0);
}

void func_800D3AF0(s32 arg0) {
    func_800D3B6C(3, &func_800D1864, arg0, 0x3E8, 0);
}

void func_800D3B24(void) {
    func_800D3B6C(1, &rand_setSeed, osGetCount(), 0, 0);
}

u8 func_800D3B60(void) {
    return D_8012B3F3;
}

void func_800D3B6C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    unkStruct800D3B6C* temp_v0;

    temp_v0 = func_800B2A58(D_8012B3FC);
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unk8 = arg2;
    temp_v0->unkC = arg3;
    temp_v0->unk10 = arg4;
}

void func_800D3BC8(unkStruct800D3BC8* arg0) {
    switch (arg0->unk0) {
        case 0:
            arg0->unk4();
            return;
        case 1:
            arg0->unk4(arg0->unk8);
            return;
        case 2:
            arg0->unk4(arg0->unk8, arg0->unkC);
            return;
        case 3:
            arg0->unk4(arg0->unk8, arg0->unkC, arg0->unk10);
            return;
    }
}

void func_800D3C70(void) {
    s32 temp_v0;
    u32 temp_v0_2;
    u32 var_s0;

    if (D_8012B3FC != 0) {
        temp_v0 = func_800B2890(D_8012B3FC);
        var_s0 = vector_begin(temp_v0);
        temp_v0_2 = vector_end(temp_v0);
        if (var_s0 < temp_v0_2) {
            do {
                func_800D3BC8(var_s0);
                var_s0 += 0x14;
            } while (var_s0 < temp_v0_2);
        }
        func_800B2D48(D_8012B3FC);
        D_8012B3FC = 0;
    }
}

void func_800D3CF8(s32 arg0) {
    D_8012B3F4 = arg0;
}


u8 func_800D3D04(void) {
    return D_8012B3F4;
}

void func_800D3D10(s32 arg0) {
    D_8012B3F5 = arg0;
}

u8 func_800D3D1C(void) {
    return D_8012B3F5;
}

s32 func_800D3D28(void) {
    if (D_8012B3F0.unk9 != 0) {
        return 0;
    }
    D_8012B3F0.unk9 = 1U;
    return 1;
}


s32 func_800D3D58(void) {
    switch (D_8012B3F0.unk9) {
    case 1:
        D_8012B3F0.unk9 = 0U;
        return 1;
    case 2:
        D_8012B3F0.unk9 = 3U;
        return 1;
    default:
        return 0;
    }
}

s32 func_800D3DA4(void) {
    return character_getControllerIndex();
}
