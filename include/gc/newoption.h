#ifndef __GC_NEWOPTION_H__
#define __GC_NEWOPTION_H__

#include "common.h"
#include "core1/1E2D890.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1ECB9F0.h"
#include "core2/1ED4E30.h"
#include "core2/1ED8C80.h"
#include "core2/1EDA900.h"
#include "gc/zoombox.h"
#include "gl/dbstring.h"
#include "gl/dialog.h"

typedef struct {
	s16 unk0;
	s16 unk2;
	s16 unk4;
	s16 unk6;
	s16 unk8;
	s16 unkB;
	s16 unkC;
	s16 unkE;
	s32 unk10;
	f32 unk14;
	f32 unk18;
	u8 unk1C_5 : 3;
	u8 unk1C_4 : 1;
	u8 unk1C_3 : 1;
	u8 unk1C_0 : 3;
	u8 unk1D_5 : 3;
	u8 unk1D_4 : 1;
	u8 unk1D_3 : 1;
	u8 unk1D_2 : 1;
	u8 unk1D_1 : 1;
	u8 unk1D_0 : 1;
	u8 unk1E;
	u8 unk1F;
	f32 unk20;
	u8 unk24;
	u8 unk25;
	s16 unk26;
	s16 unk28;
	s16 unk2A;
	f32 unk2C;
	f32 unk30;
	u8 unk34[0xB0-0x34];
	s16 unkB0;
	s16 unkB2;
	u8 unkB4[0x250-0xB4];
	s8 unk250;
	s8 unk251;
	s8 unk252;
	s8 unk253;
	s16 unk254;
	s16 unk256;
	f32 unk258;
	f32 unk25C;
} OptionState;

void _gcnewoption_entrypoint_0(OptionState*);
void _gcnewoption_entrypoint_1(OptionState*, u32);

//Get Memory Size of option menu
int gcnewoption_entrypoint_2(void);
int _gcnewoption_entrypoint_2(void);

void _gcnewoption_entrypoint_4(Actor*, u32, u32*, u32, s32);
void _gcnewoption_entrypoint_5(OptionState*, void*, u8, s16, s32);
void _gcnewoption_entrypoint_6(OptionState*, u32);
void gcnewoption_entrypoint_7(OptionState* a0);
void _gcnewoption_entrypoint_7(OptionState* a0);
//Setup number of visible options
void _gcnewoption_entrypoint_8(OptionState*, u32);

//Setup number of usable options
void _gcnewoption_entrypoint_9(OptionState*, u32);


void _gcnewoption_entrypoint_10(OptionState*, u8);
void _gcnewoption_entrypoint_11(OptionState*);


//Setup Option Text
void gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);
void _gcnewoption_entrypoint_12(OptionState* a0, u32 optionIndex, s16 textIndex);
void _gcnewoption_entrypoint_13(OptionState*, u32, u32*);
void _gcnewoption_entrypoint_14(OptionState*, u32, u32, u32, f32);

s32 _gcnewoption_entrypoint_17();

s32 _gcnewoption_entrypoint_19(OptionState*, s32);
void _gcnewoption_entrypoint_21(OptionState*, u32);
void _gcnewoption_entrypoint_23(OptionState*, u32);

void _gcnewoption_entrypoint_31(OptionState*, s32, s16);
void _gcnewoption_entrypoint_32(OptionState*, u32);
void _gcnewoption_entrypoint_34(OptionState*, u32); 
u32 _gcnewoption_entrypoint_35();
void _gcnewoption_entrypoint_36(OptionState*);

//Hide Options
u32 gcnewoption_entrypoint_37(OptionState* a0, u32 a1);
u32 _gcnewoption_entrypoint_37(OptionState* a0, u32 a1);

s32 _gcnewoption_entrypoint_38(OptionState*, u32);
s32 _gcnewoption_entrypoint_39(OptionState*);

void _gcnewoption_entrypoint_40(OptionState*, s32, s32, s32, f32, f32);

void gcnewoption_entrypoint_41(OptionState*, u8);
void _gcnewoption_entrypoint_41(OptionState*, u8);

void _gcnewoption_entrypoint_42(OptionState*, f32);
void _gcnewoption_entrypoint_46(OptionState*, u8);
void _gcnewoption_entrypoint_49(OptionState*, u8);

#endif
