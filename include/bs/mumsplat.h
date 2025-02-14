#ifndef __BS_MUMSPLAT_H__
#define __BS_MUMSPLAT_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/dust.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "bs/mum.h"
#include "bs/splat.h"
#include "bs/state.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

s32 func_8008DD04(PlayerState*);
extern void func_8008E944(PlayerState *self);
extern void func_8008E95C(PlayerState *self);
extern void func_8009BA9C(PlayerState *self, f32 *);
extern void func_8009BD88();
void func_8009DB04(PlayerState *, s32, f32, s32);
void func_8009DF18(PlayerState *, s32, f32, s32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
extern s32 func_800A1718(PlayerState *self);

extern s32 D_808001E0_bsmumsplat[];

#endif // __BS_MUMSPLAT_H__
