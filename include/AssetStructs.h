#ifndef __ASSET_STRUCT_H__
#define __ASSET_STRUCT_H__
#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C[3][6];
} ImageStruct;

typedef struct {
    /* 0x00 */ u32 magic; // 0x0000000B
    /* 0x04 */ u32 unk4; // geometry layout offset
    /* 0x08 */ s16 unk8; // texture setup offset
    /* 0x0A */ s16 unkA; // geo type
    /* 0x0C */ s32 unkC; // displaylist setup offset
    /* 0x10 */ s32 unk10; // vertex store setup offset
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x2C */ u8 pad30[0x38 - 0x30];
    /* 0x38 */ s32 unk38;
} ModelBin; /* Size: 0x50 */

#endif
