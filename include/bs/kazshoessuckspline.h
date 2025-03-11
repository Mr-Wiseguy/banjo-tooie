#ifndef __BS_KAZSHOESSUCKSPLINE_H__
#define __BS_KAZSHOESSUCKSPLINE_H__

#include <ultra64.h>

#include "ba/drone.h"
#include "ba/movespline.h"
#include "ba/shoes.h"
#include "ba/shoessuck.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "core2/1E77A20.h"
#include "funcs.h"

extern s32 func_8008DD04(PlayerState *self);
extern void func_80092880(PlayerState *self, s32);
extern void func_800956B8();
extern void func_80099A7C(PlayerState *self, f32[3]);
extern void func_80099B94(PlayerState *self);
extern s32 func_8009BCD4(PlayerState *self, f32);
extern s32 func_8009CA70(PlayerState *self, s32, s32);
extern s32 func_8009E6EC(PlayerState *self);
extern s32 func_8009E704();
extern void func_8009E830(PlayerState *self, s32);
extern void func_800A2018(PlayerState *self, s32);
extern void func_800A4DA4(PlayerState *self, s32);
extern void func_800A4E30(PlayerState *self);

#endif // __BS_KAZSHOESSUCKSPLINE_H__
