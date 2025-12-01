#ifndef __CORE2_1E7F4D0_H__
#define __CORE2_1E7F4D0_H__

#include "common.h"


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

D_80127110_Data* func_800A5D60();

#endif
