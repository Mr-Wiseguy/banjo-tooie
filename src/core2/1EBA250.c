#include "types.h"
#include "memory.h"

// TODO move these to a math header.
void func_800D9470(f32[4], f32[4], f32[4]);
void func_800D952C(f32[4], f32[4]);
void func_800D9888(f32[4], f32[4], f32[4], f32);
void func_800D9AD4(f32[4], f32[4], f32[4], f32);
void func_800EF334(f32[3], f32);

typedef struct {
    f32 unk0;
    f32 unk4[3];
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
} Unkfunc_800E0960_2;

typedef struct {
    Unkfunc_800E0960_2* unk0;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 padB;
    f32 unkC;
    s32 unk10[4];
} Unkfunc_800E0960_1;

void func_800E0ACC(Unkfunc_800E0960_1*);
s16 func_8001B668(s32, s32);
Unkfunc_800E0960_1* func_800E0A28(s16);
Unkfunc_800E0960_1* func_8001B798(s16);
void func_8001B754(s16);

void* func_800E0960(s32 arg0) {
    void* sp18;
    Unkfunc_800E0960_1* temp_v0;

    temp_v0 = (Unkfunc_800E0960_1*)heap_alloc(arg0 * sizeof(Unkfunc_800E0960_2) + sizeof(Unkfunc_800E0960_1));
    sp18 = temp_v0;
    temp_v0->unk0 = (Unkfunc_800E0960_2* )&temp_v0[1];
    temp_v0->unk6 = (s16) arg0;
    temp_v0->unkC = 0.0f;
    func_800E0ACC(temp_v0);
    return temp_v0;
}

s16 func_800E09B8(s32 arg0) {
    Unkfunc_800E0960_1* temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8001B668(3, arg0 * sizeof(Unkfunc_800E0960_2) + sizeof(Unkfunc_800E0960_1));
    temp_v0_2 = func_800E0A28(temp_v0);
    temp_v0_2->unk0 = (Unkfunc_800E0960_2* )&temp_v0_2[1];
    temp_v0_2->unk6 = (s16) arg0;
    temp_v0_2->unkC = 0.0f;
    func_800E0ACC(temp_v0_2);
    return temp_v0;
}

Unkfunc_800E0960_1* func_800E0A28(s16 arg0) {
    return func_8001B798(arg0);
}

void func_800E0A50(void* arg0) {
    heap_free(arg0);
}

void func_800E0A70(s16 arg0) {
    func_8001B754(arg0);
}

void func_800E0A98(Unkfunc_800E0960_1* arg0) {
    Unkfunc_800E0960_1* temp_v0;

    temp_v0 = (Unkfunc_800E0960_1*)defrag(arg0);
    temp_v0->unk0 = (Unkfunc_800E0960_2* )&temp_v0[1];
}

void func_800E0AC0(Unkfunc_800E0960_1* arg0) {
    arg0->unk0 = (Unkfunc_800E0960_2* )&arg0[1];
}

void func_800E0ACC(Unkfunc_800E0960_1* arg0) {
    arg0->unk10[1] = 0;
    arg0->unk10[2] = 0;
    arg0->unk10[3] = 0;
    arg0->unk10[0] = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk9 = 0;
    arg0->unkA = 0;
}

void func_800E0AF0(Unkfunc_800E0960_1* arg0, f32 arg1) {
    arg0->unkC = arg1;
}

void func_800E0AFC(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    Unkfunc_800E0960_2* temp_v1;

    if (arg0->unk4 < arg0->unk6) {
        temp_v1 = &arg0->unk0[arg0->unk4++];
        temp_v1->unk0 = arg2;
        temp_v1->unk4[0] = arg3;
        temp_v1->unk4[1] = arg4;
        temp_v1->unk4[2] = arg5;
        temp_v1->unk11 = 0;
        temp_v1->unk10 = arg1;
        arg0->unk10[arg1 >> 5] |= 1 << (arg1 & ((1 << 5) - 1));
        arg0->unk8 = 1;
    }
}

void func_800E0B8C(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    Unkfunc_800E0960_2* temp_v1;

    if (arg0->unk4 < arg0->unk6) {
        temp_v1 = &arg0->unk0[arg0->unk4++];
        temp_v1->unk0 = arg2;
        temp_v1->unk4[0] = arg3;
        temp_v1->unk4[1] = arg4;
        temp_v1->unk4[2] = arg5;
        temp_v1->unk11 = 3;
        temp_v1->unk10 = arg1;
        arg0->unk10[arg1 >> 5] |= 1 << (arg1 & ((1 << 5) - 1));
        arg0->unk9 = 1;
    }
}

void func_800E0C20(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    Unkfunc_800E0960_2* temp_v1;

    if (arg0->unk4 < arg0->unk6) {
        temp_v1 = &arg0->unk0[arg0->unk4++];
        temp_v1->unk0 = arg2;
        temp_v1->unk4[0] = arg3;
        temp_v1->unk4[1] = arg4;
        temp_v1->unk4[2] = arg5;
        temp_v1->unk11 = 6;
        temp_v1->unk10 = arg1;
        arg0->unk10[arg1 >> 5] |= 1 << (arg1 & ((1 << 5) - 1));
        arg0->unkA = 1;
    }
}

void func_800E0CB4(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2[4]) {
    f32 temp_f20;
    s32 i;
    f32 sp78[4];
    f32 sp68[4];
    f32 sp5C[3];
    Unkfunc_800E0960_2* temp_v0;

    for (i = 0; i < arg0->unk4; i++) {
        temp_v0 = &arg0->unk0[i];
        if (temp_v0->unk10 == arg1 && temp_v0->unk11 == 0) {
            temp_f20 = temp_v0->unk0 * arg0->unkC;
            sp5C[0] = temp_v0->unk4[0];
            sp5C[1] = temp_v0->unk4[1];
            sp5C[2] = temp_v0->unk4[2];
            if (temp_f20 == -1.0f) {
                func_800D952C(arg2, sp5C);
                return;
            }
            if (temp_f20 < 0.0f) {
                func_800D952C(sp68, sp5C);
                if (temp_f20 == -1.0f) {
                    func_800D9AD4(sp78, arg2, sp68, -temp_f20);
                } else {
                    func_800D9888(sp78, arg2, sp68, -temp_f20);
                }
                arg2[0] = sp78[0];
                arg2[1] = sp78[1];
                arg2[2] = sp78[2];
                arg2[3] = sp78[3];
            } else if (temp_f20 > 0.0f) {
                func_800EF334(sp5C, temp_f20);
                func_800D952C(sp68, sp5C);
                func_800D9470(arg2, arg2, sp68);
            }
        }
    }
}

void func_800E0E94(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2[3]) {
    f32 temp_f0;
    s32 i;
    Unkfunc_800E0960_2* temp_a1;

    for (i = 0; i < arg0->unk4; i++) {
        temp_a1 = arg0->unk0 + i;
        if (temp_a1->unk10 == arg1 && temp_a1->unk11 == 3) {
            temp_f0 = temp_a1->unk0 * arg0->unkC;
            if (temp_f0 < 0.0f) {
                arg2[0] = arg2[0] + ((temp_a1->unk4[0] - arg2[0]) * -temp_f0);
                arg2[1] = arg2[1] + ((temp_a1->unk4[1] - arg2[1]) * -temp_f0);
                arg2[2] = arg2[2] + ((temp_a1->unk4[2] - arg2[2]) * -temp_f0);
            } else if (temp_f0 > 0.0f) {
                arg2[0] *= 1.0f + ((temp_a1->unk4[0] - 1.0f) * temp_f0);
                arg2[1] *= 1.0f + ((temp_a1->unk4[1] - 1.0f) * temp_f0);
                arg2[2] *= 1.0f + ((temp_a1->unk4[2] - 1.0f) * temp_f0);
            }
        }
    }
}

void func_800E0FE8(Unkfunc_800E0960_1* arg0, u8 arg1, f32 arg2[3]) {
    f32 temp_f0;
    s32 i;
    Unkfunc_800E0960_2* temp_a1;

    for (i = 0; i < arg0->unk4; i++) {
        temp_a1 = &arg0->unk0[i];
        if (temp_a1->unk10 == arg1 && temp_a1->unk11 == 6) {
            temp_f0 = temp_a1->unk0 * arg0->unkC;
            if (temp_f0 < 0.0f) {
                arg2[0] = arg2[0] + ((temp_a1->unk4[0] - arg2[0]) * -temp_f0);
                arg2[1] = arg2[1] + ((temp_a1->unk4[1] - arg2[1]) * -temp_f0);
                arg2[2] = arg2[2] + ((temp_a1->unk4[2] - arg2[2]) * -temp_f0);
            } else if (temp_f0 > 0.0f) {
                arg2[0] += temp_a1->unk4[0] * temp_f0;
                arg2[1] += temp_a1->unk4[1] * temp_f0;
                arg2[2] += temp_a1->unk4[2] * temp_f0;
            }
        }
    }
}
