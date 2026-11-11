#ifndef __CORE2_1EC2350_H__
#define __CORE2_1EC2350_H__

#include "common.h"
#include "freelist.h"
#include "memory.h"
#include "core2/1EB2840.h"
#include "core2/1EAF950.h"
#include "core2/1ECD170.h"
#include "core1/1E2A0E0.h"
#include "core1/1E29B60.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10[];
} unkStruct800E8B74;

typedef struct {
    u8 pad0[0x18];
    u32 unk18;
    u8 pad1C[0x20 - 0x1C];
    s32 unk20;
    s32 unk24;
    u8 pad28[0xD8 - 0x28];
} unkStruct800E8F8C;

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
    u8 pad10[0x12 - 0x10];
} unkStruct800E93AC;

typedef struct {
    u8 unk0[0x50];
    s32 unk50[0x50];
    s16 unk190[0x50];
    s16 unk230[0x50];
    unkStruct800E8F8C unk2D0;
    unkStruct800E8F8C unk3A8[0x4F];
    s16 unk4650;
    u8 pad4652[0x4658 - 0x4652];
    unkStruct800E93AC unk4658[0x78];
    s32 unk4EC8[2];
} unkStructD_8012D690;

void func_800E8A60(void);
void func_800E8A68(void);
void func_800E8B04(void);
void func_800E8B3C(void);
u8 func_800E8B74(u32);
void func_800E8C08(u8 a0);
s32 func_800E8C58(u8);
unkStruct800E8B74* func_800E8CB0(u8);
void func_800E8CDC(u8);
void func_800E8D28(u8, f32);
void func_800E8D5C(u8, void*, s16);
void func_800E8DB0(u8, s32);
void func_800E8DE4(unkStruct800E8B74*, f32);
void func_800E8E3C(unkStruct800E8B74*);
void func_800E8E70(void*, u32, u32, s32);
s32* func_800E8F68(unkStruct800E8F8C*);
void func_800E8F8C(s32, s32, s32, s32);
s16 func_800E9048(void);
s16 func_800E9054(s32);
void func_800E9070(unkStruct800E8F8C*, s32);
void func_800E90A4(unkStruct800E8F8C*, s32);
unkStruct800E8F8C* func_800E90D8(s32, s32, s32);
void func_800E9300(s32, s32);
void func_800E9320(s32, s32);
void func_800E9340(unkStruct800E93AC*, s32, s32);
unkStruct800E93AC* func_800E93AC(s32);
void func_800E93CC(s32);
void func_800E9438(s32);
void func_800E94E4(void);
void func_800E9574(void);
void func_800E95AC(u32, s32);
void func_800E96B0(s32);

#endif
