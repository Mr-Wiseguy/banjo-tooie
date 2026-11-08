#ifndef __CORE2_ANCTRL_H__
#define __CORE2_ANCTRL_H__

#include <ultra64.h>

#include "ba/assets.h"

typedef struct anctrl_s {
	s32 unk0;
	s32 unk4;
	s32 unk8;
	s32 unkC;
	s32 unk10;
	s32 unk14;
	u32 unk18_31 : 1;
	u32 unk18_30 : 1;
	u32 unk18_24 : 6;
	u32 unk18_16 : 8;
	u32 unk18_8 : 8;
	u32 unk18_3 : 5;
	u32 unk18_2 : 1;
	u32 unk18_1 : 1;
	u32 unk18_0 : 1;
	f32 unk1C[3];
} AnimCtrl;

void anctrl_setIndex(AnimCtrl *, AssetId);
void anctrl_reset(AnimCtrl *);
void anctrl_setSmoothTransition(AnimCtrl *, s32);
void anctrl_setDuration(AnimCtrl *, f32);
void anctrl_setSubrange(AnimCtrl *, f32, f32);
void anctrl_setPlaybackType(AnimCtrl *, s32);
s32 func_8008AEDC(AnimCtrl*);
void func_8008B10C(AnimCtrl *, f32);
int anctrl_isAt(AnimCtrl *, f32);
void anctrl_setStart(AnimCtrl *, f32);
f32 anctrl_getAnimTimer(AnimCtrl *);
void anctrl_start(AnimCtrl *);
s32 anctrl_getPlaybackType(AnimCtrl*);
s32 anctrl_isStopped(AnimCtrl *);
AssetId anctrl_getIndex(AnimCtrl *);

AnimCtrl *func_8008AD80(s32);
//Update Anim
void func_8008ADE4(AnimCtrl*);
AnimCtrl *func_8008AEB4(AnimCtrl *);
void func_8008B1C8(AnimCtrl *, f32);
void func_8008B188(AnimCtrl *, s32);
s32 func_8008B28C(AnimCtrl *);
void func_8008B2E8(AnimCtrl *, s32);
void func_8008B304(AnimCtrl*);
s32 func_8008B4D4(AnimCtrl *);

#endif
