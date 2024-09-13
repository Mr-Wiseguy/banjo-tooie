#ifndef __FUNCS_H__
#define __FUNCS_H__

// This file is for functions that haven't been sorted into more specific headers.
// Functions should only be added here if it's unclear what system they belong to.
// The end goal is to delete this file after moving all the functions out.

#include "ba/playerstate.h"
#include "ba/animctrl.h"

// TODO rename these symbols
#define bs_setState func_8009E5C8

void func_800A0CDC(PlayerState* thisx, s32 arg1);
void func_800A0CDC(PlayerState* thisx, s32 arg1);
void func_8009AB78();
void bs_setState(PlayerState*, s32);
s32 func_80097BFC(PlayerState*);
s32 _bscrouch_entrypoint_4(PlayerState*, s32);
void func_800C6DA0(s32);
s32 func_8008B324(AnimCtrl*);
s32 func_8008DD04(PlayerState*);
s32 func_800944E0(PlayerState*, s32);
s32 func_80094B14(PlayerState*);
s32 func_80094BC0(PlayerState*);
s32 func_800F1418(s32, s32);
void func_8008B064(AnimCtrl*);
void func_8008B24C(AnimCtrl*, f32);
f32 func_8008B2B4(AnimCtrl*);
s32 func_80097C3C(PlayerState*);
void func_8009E5C8(PlayerState*, s32);
void func_800A0CF4(PlayerState* player, s32);

#endif
