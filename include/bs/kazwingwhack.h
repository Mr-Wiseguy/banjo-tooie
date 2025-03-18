#ifndef __BS_KAZWINGWHACK__
#define __BS_KAZWINGWHACK__

#include <ultra64.h>

#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/input.h"
#include "ba/physics.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "core2/1E2B200.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78170.h"
#include "core2/1E93440.h"
#include "core2/1E8F430.h"
#include "core2/1ECA640.h"
#include "funcs.h"
#include "player.h"

extern f32 func_8009E138(PlayerState *self, s32);
extern void func_8009328C(PlayerState *self, f32);
extern void func_8009B9F0(PlayerState *self, f32);
extern void func_800BA670(s32, s32);
extern void func_800BA77C(s32, s32, s16, s16);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F1DF4(f32[3], f32[3]);
extern f32 func_800F3780(f32, s32[], s32);
extern void func_800F3BD0(PlayerState *self, s32, f32[3]);

#endif // __BS_KAZWINGWHACK__
