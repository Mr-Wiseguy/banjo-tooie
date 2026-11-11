#include "core2/1EDD9C0.h"

extern unkStruct800DFAD0 D_80135AB0;
extern u8 D_80135AB8[];
extern u8 D_80136BC0[];
extern u8 D_80136D10[];
extern u8 D_80136BE8;
extern u8 D_80124400;
extern u8 D_80136BF8;
extern u8 D_80136D88;

unkStruct800DFAD0* func_801040D0(void) {
    D_80135AB0.unk0 = &D_80135AB8;
    D_80135AB0.unk4 = 0x6D;
    func_800DFAD0(&D_80135AB0);
    return &D_80135AB0;
}

void* func_8010410C(void) {
    return D_80136BC0;
}

void* func_80104118(void) {
    return &D_80136BE8;
}

void* func_80104124(void) {
    return &D_80124400;
}


void* func_80104130(void) {
    return &D_80136BF8;
}

void* func_8010413C(void) {
    return D_80136D10;
}

void* func_80104148(s32 arg0) {
    return (arg0 * 0x14) + &D_80136D88;
}
