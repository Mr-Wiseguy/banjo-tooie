#ifndef __BS_KAZCROUCH_H__
#define __BS_KAZCROUCH_H__

#include <ultra64.h>
#include "an/anctrl.h"
#include "ba/key.h"
#include "ba/input.h"
#include "ba/timer.h"
#include "ba/physics.h"
#include "ba/yaw.h"
#include "ba/anim.h"
#include "bs/kaz.h"
#include "funcs.h"

extern f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
extern void func_800A2CE8(PlayerState *self, f32, s32);
extern s32 func_800C6E38(s32);
extern void func_8009BB24(PlayerState *self, f32[3]);
extern void func_8009CFD8(PlayerState *, f32);
extern void func_8009D2D8(PlayerState *, s32);
extern void func_8009D658(PlayerState *);
extern s32 func_8009E710(PlayerState *);
extern s32 func_800F1EA4(f32 *, f32 *);

BanjoStateId bskazcrouch_entrypoint_0(PlayerState* self, BanjoStateId arg1);

#endif // __BS_KAZCROUCH_H__