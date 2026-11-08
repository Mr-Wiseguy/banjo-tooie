#ifndef __CORE2_1EC7E20_H__
#define __CORE2_1EC7E20_H__

#include "common.h"
#include "memory.h"
#include "vector.h"
#include "id/bounce.h"

typedef struct {
    u32 unk0;
    u8 pad4[2];
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 pad9[0x24 - 0x9];
    s32 unk24;
    u8 pad28[0x2C - 0x28];
    s32 unk2C;
    u8 pad30[0xA8 - 0x30];
} unkStruct800EE530;

#endif