#ifndef __CORE2_1E80A70_H__
#define __CORE2_1E80A70_H__
#include "common.h"
#include "core1/1E2C940.h"
#include "core1/1E31B40.h"
#include "core1/1E32FE0.h"
#include "core1/1E2E730.h"

#include "core2/1E831D0.h"
#include "core2/1E99980.h"
#include "core2/1E9A960.h"
#include "core2/1EA0AA0.h"
#include "core2/1EA1DA0.h"
#include "core2/1EA3AA0.h"
#include "core2/1EAAD80.h"
#include "core2/1EB2840.h"
#include "core2/1EBCFC0.h"
#include "core2/1EC1380.h"
#include "core2/1EC3810.h"
#include "core2/1ECE0B0.h"
#include "core2/1ED4E30.h"
#include "core2/1ED8C80.h"
#include "core2/1ED68A0.h"
#include "core2/1E8F430.h"
#include "core2/1E64F00.h"
#include "core2/1EB5E70.h"
#include "core2/1E9E480.h"
#include "core2/1EAED30.h"
#include "core2/1EBE020.h"
#include "core2/1E83B90.h"
#include "core2/1E995C0.h"
#include "core2/1EA5180.h"
#include "core2/1EB2130.h"
#include "core2/1EC1AD0.h"
#include "core2/1EC7E20.h"
#include "core2/1EE7920.h"
#include "core2/1EB52C0.h"
#include "core2/1E8DC70.h"
#include "core2/1EDAEA0.h"
#include "core2/1E82660.h"
#include "core2/1EC2FD0.h"
#include "core2/1EE9AB0.h"
#include "core2/1E7F4D0.h"
#include "core2/1EAF950.h"

#include "core1/defrag.h"
#include "core1/tidy.h"
#include "co/sectionstor.h"
#include "gc/game.h"
#include "gc/level.h"
#include "gl/introsyncDll.h"
#include "gc/sectionDll.h"
#include "gl/cutDll.h"
#include "gfx.h"
#include "overlays.h"


typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    s16 mapValue;
    u8 unk12;
    s8 entranceIndex;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    s8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_80127630_unk;

typedef struct {
    s32 unk0;
    unkStruct800CA334* unk4;
    f32 unk8;
} unk_D_80127688;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} unk_D_80127670;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} unkStructD_8011A420;

typedef struct {
    Gfx* gfx;
    Mtx* mtx;
    Vtx* vtx;
} unkStructD_80127658;

GraphicsBuffers* graphics_getGraphicsBuffer(void);
void func_800A718C();
void func_800A71E0(void);
void func_800A72A4(s32, s32, s32, s32);
void func_800A7380(s32);

void func_800A73F4(s32, s32);
void func_800A7584(s32, s32);
void func_800A759C(s32, s32);
void func_800A76F4(s32);
void func_800A7840(s32);
void func_800A791C(s32, s32, s32);
void func_800A794C(s32, s32, s32);
void func_800A7990(s32, s32, s32);
void func_800A79D4(s32, s32);
void func_800A7A18(s32, s32);
void func_800A7A5C(void);
void func_800A7A6C(s32, s32);
void func_800A7A90(s32);
void func_800A7AD4(s32, s32);
void func_800A7B18(u32);
// func_800A7B24
void func_800A7BB8(s32);
void func_800A7D30();
s32 func_800A7D84(void);
void func_800A7FB4(s32,s32);
void func_800A7FD4(void);
void func_800A8168(void);
s16 func_800A8178(void);
s16 func_800A8184();
u8 func_800A8190(void);
int func_800A819C();
int func_800A81C4();
void func_800A8230(void);
void func_800A8240();
s16 func_800A824C(void);
f32 func_800A8258(void);
int func_800A8264();
void func_800A8278();
s32 func_800A8380(s32);
void func_800A8424(s32, s32*, s32*, s32*, s32*);
void func_800A84EC(s32, s32);
void func_800A85A8(void);
void func_800A861C(void);
void func_800A8670(void);
void func_800A86D8(void);
void func_800A8710(void);
s32 func_800A877C(s32);
s32 func_800A87FC(s32);
unkStruct800CA334* func_800A88C4();
unkStruct800CA334* func_800A8948(s32);
unkStruct800CA334* func_800A8984(s32);
s32 func_800A89A0(s32);
void func_800A89BC(s32);
s32 func_800A89F8();
void func_800A8A04(s32, s32, s32, s32, s32);
void func_800A8A44(s32, s32*, s32*, s32*, s32*);
void func_800A8A88(s32, f32);
f32 func_800A8AD4(s32);
void func_800A8AF0(s32);
void func_800A8B24(Gfx**, s32);
void func_800A8BA8(Gfx**, s32);
s32 func_800A8BD4(Gfx**, s32, s32);
void func_800A8CCC(Gfx**, s32);
void func_800A8D00(s32, s32);

#endif // __CORE2_1E80A70_H__