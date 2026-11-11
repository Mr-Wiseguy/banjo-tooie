#include "common.h"
#include "core2/1EAD6C0.h"

extern unkStructD_8011B5B8 D_8011B5B8[];
extern unkStructD_8011B5B8 D_8011B5C0[];
extern unkStructD_8011B5B8 D_8011B608;
extern unkStructD_8011B620 D_8011B620[];

s32 func_800D3DD0(s32 arg0) {
    u16 temp_v0;

    temp_v0 = D_8011B5B8[arg0].unk0;
    if (temp_v0 != 0) {
        return flag_getValue(temp_v0);
    }
    return 0;
}

s32 func_800D3E14(s32 arg0) {
    return flag_getValue(D_8011B5B8[arg0].unk2);
}

s32 cheat_isActive(u32 arg0) {
    return flag_getValue(D_8011B5B8[arg0].unk4);
}

s32 func_800D3E6C(s32 arg0) {
    u16 temp_v0;

    if (func_800D3E14(arg0) != 0) {
        return 0;
    }
    temp_v0 = D_8011B5B8[arg0].unk0;
    if (temp_v0) {
        return flag_getValue(temp_v0);
    }
    return 1;
}

s32 func_800D3EC8(s32 arg0) {
    if (func_800D3E14(arg0) != 0) {
        return 0;
    }
    return 1;
}

void func_800D3EF4(s32 arg0) {
    u16 temp_v0;

    temp_v0 = D_8011B5B8[arg0].unk0;
    if (temp_v0 != 0) {
        flag_setValueTrue((enum flag_e) temp_v0);
    }
}

void func_800D3F2C(s32 arg0) {
    flag_setValueTrue(D_8011B5B8[arg0].unk2);
}

void func_800D3F58(s32 arg0, s32 arg1) {
    flag_setValue(D_8011B5C0[arg0 - 1].unk4, arg1);
    if (&D_8011B608 == &D_8011B5C0[arg0]) {
        if (arg1 != 0) {
            func_800F4924(character_getActiveIndex(), 0x3E7);
        }
    }
}

u16 func_800D3FC0(s32 arg0) {
    return D_8011B5B8[arg0].unk6;
}

void func_800D3FD4(u32 arg0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = 0;
    sp28 = 0;
    sp24 = 0;
    if (cheat_isActive(CHEAT_A_NESTKING) != 0) {
        func_800D42E8(0x40, arg0);
        func_800D42E8(0x41, arg0);
        func_800D42E8(0x42, arg0);
        func_800D42E8(0x43, arg0);
        func_800D42E8(0x44, arg0);
        func_800D42E8(0x46, arg0);
        func_800D42E8(0x47, arg0);
        sp2C = sp28 = sp24 = 1;
    } else {
        if (cheat_isActive(CHEAT_2_EGGS) != 0) {
            func_800D4398(0x40, arg0);
            func_800D4398(0x41, arg0);
            func_800D4398(0x42, arg0);
            func_800D4398(0x43, arg0);
            func_800D4398(0x44, arg0);
            sp2C = sp28 = 1;
        }
        if (cheat_isActive(CHEAT_1_FEATHERS) != 0) {
            func_800D4398(0x46, arg0);
            sp2C = 1;
            func_800D4398(0x47, arg0);
            sp24 = 1;
        }
    }
    if (sp2C == 0) {
        func_800D433C(0x40, arg0);
        sp24 = 1;
        sp28 = 1;
        func_800D433C(0x41, arg0);
        func_800D433C(0x42, arg0);
        func_800D433C(0x43, arg0);
        func_800D433C(0x44, arg0);
        func_800D433C(0x46, arg0);
        func_800D433C(0x47, arg0);
    }
    if (arg0 == 0) {
        sp24 = 0;
        sp28 = 0;
    }
    func_800D4298(0x40, sp28);
    func_800D4298(0x41, sp28);
    func_800D4298(0x42, sp28);
    func_800D4298(0x43, sp28);
    func_800D4298(0x44, sp28);
    func_800D4298(0x46, sp24);
    func_800D4298(0x47, 0);
}

s32 func_800D41D8(s32 arg0) {
    s32 i;

    for (i = 0; i < 7; i++) {
        if (arg0 == D_8011B620[i].unk0) {
            return D_8011B620[i].unk2;
        }
    }
    return 0x3C;
}

void func_800D4298(s32 arg0, s32 arg1) {
    enum ability_e temp_v0;

    temp_v0 = func_800D41D8(arg0);
    if ((temp_v0 != 0x3C) && (ability_getValue(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D192C(arg0, (u32) arg1);
}


void func_800D42E8(s32 arg0, s32 arg1) {
    enum ability_e temp_v0;

    temp_v0 = func_800D41D8(arg0);
    if ((temp_v0 != 0x3C) && (ability_getValue(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, -2, arg1);
}


void func_800D433C(s32 arg0, s32 arg1) {
    enum ability_e temp_v0;

    temp_v0 = func_800D41D8(arg0);
    if ((temp_v0 != 0x3C) && (ability_getValue(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, func_800D1ACC(arg0), arg1);
}


void func_800D4398(s32 arg0, s32 arg1) {
    enum ability_e temp_v0;

    temp_v0 = func_800D41D8(arg0);
    if ((temp_v0 != 0x3C) && (ability_getValue(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, func_800D1ACC(arg0) * 2, arg1);
}
