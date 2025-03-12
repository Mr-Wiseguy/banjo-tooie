#ifndef __BS_KAZGLIDE_H__
#define __BS_KAZGLIDE_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/fly.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"
#include "core2/1E2B200.h"
#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "funcs.h"
#include "player.h"

extern s32 func_8008E124();
extern void func_8008E95C(PlayerState *self);
extern void func_80093360(PlayerState *self, f32);
extern void func_800959C8(PlayerState *self, f32, f32);
extern void func_80095A40(PlayerState *self);
extern void func_800961AC(PlayerState *self, s32);
extern f32 func_8009630C(PlayerState *self);
extern void func_800995B8(PlayerState *self, s32);
extern void func_80099B94(PlayerState *self);
extern void func_8009BC34();
extern void func_8009BD88(PlayerState *self);
extern void func_8009DF94(PlayerState *self, s32, f32, s32);
extern s32 func_8009E69C(PlayerState *self, s32);
extern s32 func_8009E6C4(PlayerState *self, s32);
extern s32 func_8009E6EC(PlayerState *self);
extern void func_8009E830(PlayerState *self, s32);
extern void func_800A042C(PlayerState *self);
extern void func_800A4DA4(PlayerState *self, s32);
extern f32 func_800DC178(f32, f32);

#endif // __BS_KAZGLIDE_H__
