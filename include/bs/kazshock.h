#ifndef __BS_KAZSHOCK_H__
#define __BS_KAZSHOCK_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "bs/kazmove.h"
#include "core2/1E66990.h"
#include "funcs.h"
#include "player.h"

extern s32 func_8001211C();
extern void func_8008B1C8(AnimCtrl *, f32);
extern s32 func_8008E260(PlayerState *self);
extern void func_80092BF4(PlayerState *self);
extern void func_80092C24(PlayerState *self, f32[3]);
extern void func_8009BB24(PlayerState *self, f32[3]);
extern void func_8009DBF0(PlayerState *self, s32, f32);
extern void func_8009DF58(PlayerState *self, s32, f32);
extern void func_800BBCB8(f32[3], s32, f32, s32, s32[]);
extern s32 func_800C2E04();
extern void func_800C2E40(s32);
extern void func_800C2FDC(u8);
extern void func_800C301C(s32, s32);
extern void func_800C330C(s32, s32);
extern void func_800C3418(s32, s32);
extern void func_800C3730(s32, f32, f32, f32);
extern void func_800C3BDC(s32);
extern void func_800C6DA0(s32);

#endif // __BS_KAZSHOCK_H__
