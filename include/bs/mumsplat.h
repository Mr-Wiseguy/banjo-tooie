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
#include "core2/1E67DA0.h"
#include "core2/1E75620.h"
#include "core2/1E76CC0.h"
#include "core2/1E7AB30.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

s32 func_8008DD04(PlayerState*);
void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);

extern s32 D_808001E0_bsmumsplat[];

#endif // __BS_MUMSPLAT_H__
