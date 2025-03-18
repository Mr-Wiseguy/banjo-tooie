#ifndef __BS_MUM_H__
#define __BS_MUM_H__

#include "an/anctrl.h"
#include "core2/1E72EA0.h"
#include "ba/anim.h"
#include "ba/bounce.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/mum.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/sudie.h"
#include "bs/drone.h"
#include "bs/mummove.h"
#include "bs/rest.h"
#include "bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6E870.h"
#include "core2/1E75710.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

void func_8009FFD8(PlayerState* thisx, BaAnimUpdateType anim_update_type, YawType yaw_state, s32 arg2, BaPhysicsType arg3);
s32 func_8008DE24(PlayerState *self);
void func_80093230(PlayerState *self, f32);
void func_800A0DAC(PlayerState *self, s32);

extern s32 D_80801140_bsmum[];
extern s32 D_80801150_bsmum[];
extern s32 D_80801160_bsmum[];
extern s32 D_80801170_bsmum[];
extern s32 D_80801180_bsmum[];
extern s32 D_80801190_bsmum[];
extern s32 D_808011A0_bsmum[];
extern s32 D_808011B0_bsmum[];

void bsmum_entrypoint_13(PlayerState *self);
void _bsmum_entrypoint_13(PlayerState *self);
void _bsmum_entrypoint_1(PlayerState *self);
void _bsmum_entrypoint_2(PlayerState *self);
void _bamum_entrypoint_5(PlayerState *self, f32);

#endif // __BS_MUM_H__
