#ifndef __CORE2_1E91790_H__
#define __CORE2_1E91790_H__

#include "common.h"
#include "gc/newoption.h"
#include "core1/1E29B60.h"
#include "core1/heap.h"
#include "core1/mlmtx.h"
#include "core2/1E691A0.h"
#include "core2/1E80A70.h"
#include "core2/1E88E90.h"
#include "core2/1E8A640.h"
#include "core2/1E9A960.h"
#include "core2/1EAC810.h"
#include "core2/1EAF950.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EBCFC0.h"
#include "core2/1EC0300.h"
#include "core2/1EC8070.h"
#include "memory.h"

void func_800B7F14(GraphicsBuffers*);
void func_800B811C(GraphicsBuffers*);
void func_800B81CC(GraphicsBuffers*, s32, s32, char);
void graphics_resetTextParams(void);
void graphics_setTextAlpha(s32 Transparency);
void graphics_setTextFont(s32 Font);
void graphics_setTextShaky(s32 shakiness);
void func_800B8CB0(s32);
void graphics_setTextColors(s8, s8, s8);
void graphics_setTextPattern(s32 pattern);
void graphics_setTextScale(f32 size);
void graphics_drawChar(GraphicsBuffers*, s32, s32, char);
void func_800B8FE0();
void func_800B8FEC();
void func_800B90C8();
void func_800B90E8();
void func_800B9170();
void func_800B956C();

extern struct {
	u8 red;
	u8 green;
	u8 blue;
	u8 alpha; //Transparency
	u8 shaky; //Shakiness
	u8 unk5; //
	u8 font; //Font
	u8 unk7;
	u8 unk8;
	u8 pattern; //Pattern
	u8 unkA;
	u8 unkB;
	u8 unkC;
	u8 unkD;
	u8 unkE;
	u8 unkF;
	u8 unk10;
	u8 unk11;
	u8 unk12;
	u8 unk13;
	f32 size; //Size
} D_801282C0;

#endif
