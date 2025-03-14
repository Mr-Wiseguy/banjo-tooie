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
#include "core2/1E29B60.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E76CC0.h"
#include "core2/1E93440.h"
#include "core2/1EA0690.h"
#include "funcs.h"
#include "player.h"

extern void func_80092BF4(PlayerState *self);
extern s32 func_800C2E04();
extern void func_800C2E40(s32);
extern void func_800C2FDC(u8);
extern void func_800C301C(s32, s32);
extern void func_800C330C(s32, s32);
extern void func_800C3418(s32, s32);
extern void func_800C3730(s32, f32, f32, f32);
extern void func_800C3BDC(s32);

extern void _bskazshock_entrypoint_0(PlayerState *self);

#endif // __BS_KAZSHOCK_H__
