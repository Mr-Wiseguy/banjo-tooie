#ifndef __CORE2_1EB52C0_H__
#define __CORE2_1EB52C0_H__

#include "common.h"

typedef struct {
	s16 unk0;
	s16 unk2;
	f32 unk4;
} unkfunc_800DB9FC_inner;

typedef struct {
	unkfunc_800DB9FC_inner unk0[7];
	f32 unk38[7];
} unkfunc_800DB9FC;

s32 func_800DB9FC(u8, s32, s32*);
u8 func_800DBA84(void);
void func_800DBB24(void);
void func_800DBB5C(void);
void func_800DBB64(void);
void func_800DBB9C(u8);
void func_800DBBF8(u8, unkfunc_800DB9FC*);
void func_800DBC68(void);
s32 func_800DBE28(u8, s32);
void func_800DBE60(u8, s32, s32);

#endif
