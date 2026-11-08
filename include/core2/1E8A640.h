#ifndef __CORE2_1E8A640_H__
#define __CORE2_1E8A640_H__

#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x8 - 0x4];
    s32 unk8;
    u8 unkC[];
} unkStruct800B0D58;

s16 func_800B0D50(unkStruct800B0D58*);
s16 func_800B0D58(unkStruct800B0D58*);
u8* func_800B0D60(unkStruct800B0D58*);
s32 func_800B0D6C(unkStruct800B0D58*, s32);

#endif