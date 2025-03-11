#ifndef __BS_MUMSTILL_H__
#define __BS_MUMSTILL_H__

#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "bs/mum.h"
#include "bs/state.h"
#include "core2/1E6E870.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>


s32 func_8008DD04(PlayerState*);
s32 func_8008E148(PlayerState *self);
extern void func_800909CC(PlayerState *self);
extern void func_80090A2C(PlayerState *self);
void func_8009DF18(PlayerState *, s32, f32, s32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);

extern u8 D_80800400_bsmumstill[];
extern s32 D_80800404_bsmumstill[];
extern s32 D_80800414_bsmumstill[];

#endif // __BS_MUMSTILL_H__
