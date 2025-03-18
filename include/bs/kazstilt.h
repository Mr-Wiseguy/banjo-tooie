#ifndef __BS_KAZSTILT_H__
#define __BS_KAZSTILT_H__

#include <ultra64.h>

#include "ba/playerstate.h"
#include "ba/anim.h"
#include "ba/yaw.h"
#include "ba/roll.h"
#include "ba/stick.h"
#include "ba/statetimer.h"
#include "ba/flag.h"
#include "bs/kaz.h"
#include "ba/alarm.h"
#include "ba/timer.h"
#include "ba/physics.h"
#include "bs/rest.h"
#include "ba/input.h"
#include "core2/1E66990.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E9A960.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "funcs.h"
#include "player.h"

extern void func_8009E474(PlayerState *self);
extern void func_8009E4AC(PlayerState *self);
extern void func_8009E53C(PlayerState *self, s32, f32);
extern void func_8009E55C(PlayerState *self, s32, f32);
extern void func_8009E5A4(PlayerState *self, s32, s32);
extern void func_800A0CE8(PlayerState *self, s32);
extern void func_800A0DD0(PlayerState *self, s32);
extern void func_800C77DC(s32);
extern void func_8008B188(AnimCtrl *, s32);
extern f32 func_80096364(PlayerState *self);
extern f32 func_8009C150(PlayerState *self);
extern f32 func_800A3394(PlayerState *self);

#endif // __BS_KAZSTILT_H__
