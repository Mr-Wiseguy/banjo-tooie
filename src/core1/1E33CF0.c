#include "core1/1E33CF0.h"

void func_8001D1E0(void);
u32 func_8001D31C(void);
u32 func_8001D32C(void);
s32 func_8001C324(u8*, u8*, void*);
u8* func_8001D30C();

extern s32 D_8007C700;

void func_8001C1C0() {
    func_8001D1E0();
}

s32 func_8001C1E0(u8** arg0, u8** arg1) {
    s32 temp_v0;
    u8* temp_t9;
    u8* v1;

    D_8007C700 = func_8001C324(*arg0, *arg1, &D_8000E800);
    *arg1 += D_8007C700;
    *arg1 = ((uintptr_t)*arg1 & 0xF) ? (u8*)(((uintptr_t)*arg1 & ~0xF) + 0x10) : *arg1;
    *arg0 = func_8001D30C();
    return 1;
}

u32 func_8001C26C() {
    func_8001D31C();
}

u32 func_8001C28C() {
    return func_8001D32C();
}

s32 func_8001C2AC(u8* arg0, u8* arg1) {
    D_8007C700 = func_8001C324(arg0, arg1, D_8000E800);
    return 0;
}

s32 func_8001C2D8() {
    return D_8007C700;
}
