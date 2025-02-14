#ifndef __BS_MUMATTACK_H__
#define __BS_MUMATTACK_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "ba/wandglow.h"
#include "bs/mum.h"
#include "bs/state.h"
#include "common.h"
#include <ultra64.h>

extern s32 func_8001210C(s32);
void func_8008B10C(AnimCtrl *, f32);
extern void func_8009DBF0(PlayerState *self, s32, f32);
void func_8009DE38(PlayerState *, s32, f32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
void func_800C2FDC(u8 id);
void func_800C31DC(s32 id, f32, s32);
f32 func_800DC0C0(void);
f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
void func_8008B2E8(AnimCtrl *, s32);
void func_80092C48(PlayerState *self, f32[3]);
s32 func_8009D454(PlayerState *self, s32, s32 *);
s32 func_800C8A98();
void func_800C8B84(s32);
void func_800C8CB8(s32, f32[3]);

void func_800C8D4C(s32, f32 *);
void func_800C8E84(s32, s32 *);

extern s32 D_808006F0_bsmumattack[];
extern s32 D_80800700_bsmumattack[];

#endif // __BS_MUMATTACK_H__