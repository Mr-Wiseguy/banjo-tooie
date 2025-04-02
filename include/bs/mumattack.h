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
#include "core2/1E29B60.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E9A960.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "common.h"
#include <ultra64.h>

void func_8008B10C(AnimCtrl *, f32);
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
