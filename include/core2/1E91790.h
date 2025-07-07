#ifndef __CORE2_1E91790_H__
#define __CORE2_1E91790_H__
#include "common.h"
#include "gc/newoption.h"

void func_800B8C50(void);
void func_800B8C8C(s32 Transparency);
void func_800B8C98(s32 Font);
void func_800B8CA4(s32 shakiness);

void func_800B8CE0(s32 color);
void func_800B8CF0(f32 size);
extern struct {
	u8 data[0x14];  // D_801282C0
	f32 value;
} D_801282C0;
extern s8 D_801282C1; 
extern s8 D_801282C2; 
extern s8 D_801282C3; //Transparency
extern s8 D_801282C4; //Shakiness
extern s8 D_801282C6; //Font
extern s8 D_801282C7;

extern s8 D_801282C9; //Pattern

extern f32 D_801282D4; //Size

#endif
