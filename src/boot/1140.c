#include "types.h"
#include "buffers.h"

// Copy of core1's 1E33CF0.c

void func_80001590(void);
void func_800016CC(void);
void func_800016DC(void);
s32 func_800006D4(u8*, u8*, void*);
u8* func_800016BC();

extern s32 D_800064F0;

void func_80000540() {
    func_80001590();
}

s32 func_80000560(u8** arg0, u8** arg1) {
    s32 temp_v0;
    u8* temp_t9;
    u8* v1;

    D_800064F0 = func_800006D4(*arg0, *arg1, &D_8000E800);
    *arg1 += D_800064F0;
    *arg1 = ((uintptr_t)*arg1 & 0xF) ? (u8*)(((uintptr_t)*arg1 & ~0xF) + 0x10) : *arg1;
    *arg0 = func_800016BC();
    return 1;
}

void func_800005EC() {
    func_800016CC();
}

void func_8000060C() {
    func_800016DC();
}

s32 func_8000062C(u8* arg0, u8* arg1) {
    D_800064F0 = func_800006D4(arg0, arg1, D_8000E800);
    return 0;
}

s32 func_80000658() {
    return D_800064F0;
}
