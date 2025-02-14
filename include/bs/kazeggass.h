#ifndef __BS_KAZEGGASS_H__
#define __BS_KAZEGGASS_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/playerstate.h"
#include "ba/yaw.h"
#include "ba/eggs.h"
#include "ba/anim.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "bs/kaz.h"
#include "bs/kazcrouch.h"
#include "funcs.h"

extern s32 func_800944E0(PlayerState *self, s32);
extern s32 func_80094510(PlayerState *self);
extern s32 func_80094B14(PlayerState *self);
extern s32 func_80094BC0(PlayerState *self);
extern void func_800A0CDC(PlayerState *self, s32);
extern void func_800C6DA0(s32);
extern s32 func_800F1418(s32, s32);

#endif // __BS_KAZEGGASS_H__
