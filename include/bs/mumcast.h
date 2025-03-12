#ifndef __BS_MUMCAST_H__
#define __BS_MUMCAST_H__

#include "ba/playerstate.h"
#include "bs/mum.h"
#include "core2/1E67DA0.h"
#include "common.h"
#include <ultra64.h>

extern void func_80099A7C(PlayerState *self, f32[3]);
void func_800A0DAC(PlayerState *self, s32);
u8 func_8009EA20();
s32 func_800A00CC(PlayerState *self, f32[3]);
s32 func_800A0DA0(PlayerState *self, s32);

extern s32 D_808004A0_bsmumcast[];


#endif // __BS_MUMCAST_H__
