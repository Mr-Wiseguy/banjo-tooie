#ifndef __BS_MUMCAST_H__
#define __BS_MUMCAST_H__

#include <ultra64.h>
#include "ba/playerstate.h"
#include "bs/mum.h"
#include "core2/1E67DA0.h"
#include "core2/1E72EA0.h"
#include "core2/1E79FD0.h"
#include "common.h"

void func_800A0DAC(PlayerState *self, s32);
u8 func_8009EA20();
s32 func_800A00CC(PlayerState *self, f32[3]);
s32 func_800A0DA0(PlayerState *self, s32);

extern s32 D_808004A0_bsmumcast[];


#endif // __BS_MUMCAST_H__
