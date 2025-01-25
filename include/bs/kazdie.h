#ifndef __BS_KAZDIE_H__
#define __BS_KAZDIE_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/dust.h"
#include "ba/timer.h"
#include "ba/motor.h"
#include "ba/sudie.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "nc/badie.h"
#include "funcs.h"

extern s32 func_8008DF8C(PlayerState *self, s32);
extern void func_8009D3A8(PlayerState *self, s32);
extern void func_8009D9D4(PlayerState *self);
extern void func_8009E058(PlayerState *self);
extern f32 func_800F0E00(f32, f32);
extern void func_80800000_bskazdie(PlayerState *self);
extern void func_800951B4(PlayerState *self);
extern void func_8009BF5C(PlayerState *self, f32);
extern void func_800A4E30(PlayerState *self);
extern f32 func_800136E4(f32 maybe_yaw);
extern void func_8008E944(PlayerState *self);
extern void func_8009514C(PlayerState *self);
extern void func_8009BFE4(PlayerState *self, f32, f32);
extern void func_8009C128(PlayerState *self, s32);
extern void func_8009D2D8(PlayerState *self, s32);
extern void func_8009D820(PlayerState *self, f32);
extern void func_800A0180(PlayerState *self);
extern void func_800A32C4(PlayerState *self, s32);
extern s32 func_800A4CA8(PlayerState *self);
extern void func_800A4DFC(PlayerState *self, s32);
extern void func_800F1E6C(s32 *, s32 *, f32 *target_yaw);

#endif // __BS_KAZDIE_H__