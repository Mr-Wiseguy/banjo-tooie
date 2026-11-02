#ifndef __CORE2_1EAF950_H__
#define __CORE2_1EAF950_H__

#include <common.h>
#include "ba/playerstate.h"

#include "ba/anim.h"
#include "ba/key.h"
#include "core1/1E29B60.h"
#include "core1/1E2B200.h"
#include "core1/1E32FE0.h"
#include "core2/1E691A0.h"
#include "core2/1E7E9A0.h"
#include "core2/1EA1270.h"
#include "core2/1EAAD80.h"
#include "core2/1EAED30.h"
#include "core2/1EB2840.h"
#include "core2/1EB3750.h"
#include "core2/1EB52C0.h"
#include "core2/1EC8070.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDFED0.h"
#include "freelist.h"
#include "memory.h"
#include "vector.h"


typedef struct {
	u8 pad[0x8];
	s16 unk8;
	s16 unkA;
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

typedef struct {
    u32 unk0_5 : 27; // <<  5
    u32 unk0_1 : 4;  // <<  1
    u32 unk0_0 : 1;  // <<  0
    ModelBin* unk4;
    u32 id : 14;       // << 18
    u32 unk8_17 : 1;   // << 17
    u32 unk8_16 : 1;   // << 16
    u32 unk8_12 : 4;   // << 12
    u32 unk8_8 : 4;    // <<  8
    u32 unk8_0 : 8;    // <<  0
} unkD_8012B800;

extern unkD_8012B800 D_8012B800[136];
extern s16 D_8012BE62;

s32 func_800D6060(s32);
s32 func_800D6254(s32);
void func_800D62E4(s32, s32, PlayerState*);
void func_800D66AC();
//Load Asset
void *asset_load(s32 a0);
s32 func_800D6CEC(s16);
void func_800D70D0(s32);
s32 func_800D70F8(s16, s32);
void func_800D71F4(s32);
s32 func_800D721C(s16, s32);
u8 func_800D731C(u16);
s32 func_800D738C(s32);
void func_800D740C();
void *func_800D7520(s32);

#endif
