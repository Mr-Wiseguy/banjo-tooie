#ifndef __BS_KAZCROUCH_H__
#define __BS_KAZCROUCH_H__

#include <ultra64.h>
#include "../funcs.h"
#include "../ba/key.h"
#include "../ba/input.h"
#include "../ba/timer.h"
#include "../an/anctrl.h"
#include "../ba/physics.h"
#include "../ba/yaw.h"
#include "../ba/anim.h"

extern f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
extern s32 func_800A2CE8(s32, f32, s32);
extern s32 _bskaz_entrypoint_3(PlayerState* arg0);
extern s32 func_800C6E38(s32);
extern void _bskaz_entrypoint_1(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern void func_8009CFD8(PlayerState *, f32);
extern void func_8009D2D8(PlayerState *, s32);
extern void func_8009D658(PlayerState *);
extern s32 func_8009E710(PlayerState *);
extern s32 func_800F1EA4(f32 *, s32 *);
extern void _bskaz_entrypoint_2();
extern s32 D_808007C0_bskazcrouch[];

#endif // __BS_KAZCROUCH_H__