#ifndef __BS_MUMSWIM_H__
#define __BS_MUMSWIM_H__

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/mum.h"
#include "bs/rest.h"
#include "bs/state.h"
#include "core2/1E29B60.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E93440.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "funcs.h"
#include "player.h"
#include <ultra64.h>

void func_8008C9F0(PlayerState *self, f32, f32, f32, f32);
void func_8008CA4C(PlayerState *self, BaAnimUpdateType arg1);
extern void func_8009DE74(PlayerState *self, s32, f32, f32);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
s32 func_80096544(PlayerState *self);
void func_8009FD24(PlayerState *self, s32);

extern s32 D_80800B30_bsmumswim[];
extern s32 D_80800B40_bsmumswim[];
extern s32 D_80800B50_bsmumswim[];
extern s32 D_80800B60_bsmumswim[];
extern s32 D_80800B70_bsmumswim[];

#endif // __BS_MUMSWIM_H__
