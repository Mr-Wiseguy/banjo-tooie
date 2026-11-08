#ifndef __CORE2_1EAD060_H__
#define __CORE2_1EAD060_H__

#include "common.h"
#include "vector.h"

#include "core2/1EA0690.h"
#include "core2/1ECE0B0.h"
#include "core2/1EAAD80.h"
#include "core2/1EA9160.h"
#include "gl/savegame.h"

typedef struct {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} unkStruct800D3B6C;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    void (*unk4)();
    s32 unk8;
    s32 unkC;
    s32 unk10;
} unkStruct800D3BC8;

typedef struct {
    s8  unk0;
    s8  unk1;
    u8  unk2;
    u8  unk3;
    u8  pad4[2];
    s16 unk6;
    s8  unk8;
    u8  unk9;
    u8  unkA;
    u8  unkB;
} unkStruct8012B3F0;

void func_800D37FC();
void func_800D389C();
s32 func_800D3948();
s32 func_800D395C();
void func_800D39D0(s32);
void func_800D3A14(s32);
u8 func_800D3B60();
void func_800D3B6C(s32, s32, s32, s32, s32);
void func_800D3BC8(unkStruct800D3BC8*);
void func_800D3C70();
void func_800D3CF8(s32);
void func_800D3D10(s32);
void func_800C7010();

#endif // __CORE2_1EAD060_H__
