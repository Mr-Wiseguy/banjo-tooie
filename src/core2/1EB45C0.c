#include <ultra64.h>
#include "types.h"

s16 func_800A8184(void);
f32 func_800D9004(void);

extern u8 D_8012762C;
extern f32 D_8012C768[];

f32 D_8012C7A0[14];

void func_800DACD0(void) {
    s32 i;
    for (i = 0; i < 14; i++) {
        D_8012C7A0[i] = 0;
    }
}

s32 func_800DAD10(void) {
    s32 ret = 0;
    s32 i;
    for (i = 0; i < 14; i++) {
        ret += D_8012C7A0[i];
    }
    return ret;
}

u16 func_800DADEC(s32 arg0) {
    return D_8012C768[arg0];
}

void func_800DAE9C(void) {
    s32 sp24 = D_8012762C;
    f32 var_f2_0;
    f32 var_f2;

    if ((func_800A8184() != 4) && (func_80090128() != 0) && (sp24 >= 0xF) && (sp24 < 0x1C) && (sp24 != 0x11)) {
        // These MINs expand into multiple calls to func_800D9004 each.
        var_f2_0 = MIN(65535.0f, D_8012C7A0[sp24 - 14] + func_800D9004());
        if (var_f2_0 < 1.0f) {
            D_8012C7A0[sp24 - 14] = 1.0f;
            return;
        }

        var_f2 = MIN(65535.0f, D_8012C7A0[sp24 - 14] + func_800D9004());
        D_8012C7A0[sp24 - 14] = var_f2;
    }
}

s32 func_800DAFC4(void) {
    return 0x1C;
}

void func_800DAFCC(u8 arg0[2 * ARRLEN(D_8012C7A0)]) {
    s32 i;
    for (i = 0; i < ARRLEN(D_8012C7A0); i++) {
        arg0[i * 2 + 0] = ((s16)(u32)D_8012C7A0[i]) >> 8; arg0[i * 2 + 1] = ((s16)(u32)D_8012C7A0[i]);
    }
}

void func_800DB67C(u8* arg0, u32 arg1) {
    s32 count;
    s32 i;

    func_800DACD0();
    count = arg1 / 2;
    count = MIN(ARRLEN(D_8012C7A0), count);
    for (i = 0; i < count; i++) {
        D_8012C7A0[i] = (arg0[2 * i + 0] << 8) | arg0[2 * i + 1];
    }
}

s32 func_800DB7C0(u8* arg0) {
    s32 offset;
    u32 length;
    s32 i;
    s32 sum;
    s32 count;

    if (_glgamedata_entrypoint_3(arg0, 3, &offset, &length)) {
        sum = 0;
        count = length / 2;
        for (i = 0; i < count; i++) {
            // Using `offset` directly in the array index doesn't match, but this pointer arithmetic does.
            s32 val = ((arg0 + offset)[2 * i + 0] << 8) | (arg0 + offset)[2 * i + 1];
            sum += val;
        }
        return sum;
    }
    return -1;
}

s32 func_800DB83C(u8* arg0, s32 arg1) {
    s32 offset;
    u32 length;
    s32 count;
    s32 val;

    if (_glgamedata_entrypoint_3(arg0, 3, &offset, &length)) {
        arg1 -= 0xE;
        count = length / 2;
        if (count < arg1) {
            return -1;
        }
        // Using `offset` directly in the array index doesn't match, but this pointer arithmetic does.
        val = ((arg0 + offset)[arg1 * 2 + 0] << 8) | (arg0 + offset)[arg1 * 2 + 1];
        return val;
    }
    return -1;
}

// strcat
void func_800E6A10(char*, const char*);
// int to string
void func_800E6DB4(char*, s32);

// time_to_string
void func_800DB8BC(char* arg0, s32 time) {
    s32 hours = time / 3600;
    s32 minutes = (time / 60) % 60;
    s32 seconds = time % 60;

    func_800E6DB4(arg0, hours);
    func_800E6A10(arg0, ":");

    if (minutes < 10) {
        func_800E6A10(arg0, "0");
    }
    func_800E6DB4(arg0, minutes);
    func_800E6A10(arg0, ":");
    
    if (seconds < 10) {
        func_800E6A10(arg0, "0");
    }
    func_800E6DB4(arg0, seconds);
    func_800E6A10(arg0, "");
}

//Is in a cutscene
int func_800DB9B0(void) {
    return func_800DA298(1601);
}
