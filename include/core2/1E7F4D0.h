#ifndef __CORE2_1E7F4D0_H__
#define __CORE2_1E7F4D0_H__

#include "common.h"
#include "core2/1ED8C80.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
}UNK_Data;

typedef struct {
    UNK_Data* unk0;
    u8 unk4;
}D_80127110_Data;

void func_800A5BE0();
void func_800A5CFC();
void func_800A5D1C();
D_80127110_Data* func_800A5D60();

#endif
