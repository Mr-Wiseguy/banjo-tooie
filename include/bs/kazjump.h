#ifndef __BS_KAZJUMP_H__
#define __BS_KAZJUMP_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"
#include "funcs.h"

extern void _bskazshock_entrypoint_0(PlayerState *self);
extern void func_8008B1C8(AnimCtrl *, f32);
extern s32 func_8008D544(PlayerState *self);
extern s32 func_8008DF8C(PlayerState *self, s32);
extern s32 func_8008E260(PlayerState *self);
extern s32 func_8008E39C(PlayerState *self);
extern void func_8008E944(PlayerState *self);
extern void func_8008E95C(PlayerState *self);
extern void func_80093360(PlayerState *self, f32);
extern s32 func_8009557C(PlayerState *self);
extern void func_8009B7C0(PlayerState *self);
extern void func_8009BA9C(PlayerState *self, s32);
extern void func_8009BB24(PlayerState *self, f32[3]);
extern void func_8009BF5C(PlayerState *self, f32);
extern f32 func_8009BFD8(PlayerState *self);
extern void func_8009D2D8(PlayerState *self, s32);
extern void func_8009DE38(PlayerState *self, s32, f32);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern void func_8009E0DC(PlayerState *self);
extern s32 func_8009E710(PlayerState *self);
extern f32 func_8009F308(PlayerState *self);
extern void func_8009FE58(PlayerState *self);
extern void func_800A042C(PlayerState *self);
extern void func_800A046C(PlayerState *self);
extern void func_800C6DA0(s32);
extern s32 func_800C6E38(s32);

#endif // __BS_KAZJUMP_H__