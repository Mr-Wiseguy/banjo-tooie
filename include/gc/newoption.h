#ifndef __GC_NEWOPTION_H__
#define __GC_NEWOPTION_H__

#include "common.h"

typedef struct {
	u8 data[0x260];
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
s32 _gcnewoption_entrypoint_19(OptionState*, s32);
void _gcnewoption_entrypoint_23(OptionState*, u32);

void _gcnewoption_entrypoint_31(OptionState*, s32, s16);
void _gcnewoption_entrypoint_32(OptionState*, u32);
void _gcnewoption_entrypoint_34(OptionState*, u32);
void _gcnewoption_entrypoint_36(OptionState*);

//Hide Options
u32 gcnewoption_entrypoint_37(OptionState* a0, u32 a1);
u32 _gcnewoption_entrypoint_37(OptionState* a0, u32 a1);

s32 _gcnewoption_entrypoint_38(OptionState*, u32);
s32 _gcnewoption_entrypoint_39(OptionState*);

void _gcnewoption_entrypoint_40(OptionState*, s32, s32, u8, f32, f32);

void gcnewoption_entrypoint_41(OptionState*, u8);
void _gcnewoption_entrypoint_41(OptionState*, u8);

void _gcnewoption_entrypoint_42(OptionState*, f32);
void _gcnewoption_entrypoint_46(OptionState*, u8);
void _gcnewoption_entrypoint_49(OptionState*, u8);

#endif
