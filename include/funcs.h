#ifndef __FUNCS_H__
#define __FUNCS_H__

// This file is for functions that haven't been sorted into more specific headers.
// Functions should only be added here if it's unclear what system they belong to.
// The end goal is to delete this file after moving all the functions out.

#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/bs/state.h"

BanjoStateId _bscrouch_entrypoint_4(PlayerState*, BanjoStateId);
void func_8008B064(AnimCtrl*);
void func_8008B24C(AnimCtrl*, f32);
f32 func_8008B2B4(AnimCtrl*);
void func_8009E5C8(PlayerState*, s32);
f32 mlAbsF(f32);

#endif
