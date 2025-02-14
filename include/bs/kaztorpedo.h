#ifndef __BS_KAZTORPEDO_H__
#define __BS_KAZTORPEDO_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/duo.h"
#include "ba/flag.h"
#include "ba/fpctrl.h"
#include "ba/key.h"
#include "ba/movegoto.h"
#include "ba/movethrust.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/react.h"
#include "ba/roll.h"
#include "ba/spin.h"
#include "ba/stick.h"
#include "ba/translate.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/rest.h"
#include "core2/1EBA250.h"
#include "funcs.h"
#include "player.h"

extern s32 _plsu_entrypoint_1(s32);
extern f32 func_80013728(f32);
extern s32 func_8008E124(PlayerState *self);
extern void func_8008E944(PlayerState *self);
extern void func_8008E95C(PlayerState *self);
extern void func_800909CC(PlayerState *self);
extern void func_80090A2C(PlayerState *self);
extern void func_800910BC(PlayerState *self, s32);
extern void func_80091290(PlayerState *self, f32, s32,s32);
extern s32 func_80092AD8(PlayerState *self);
extern f32 func_80092BE8(PlayerState *self);
extern void func_800931AC(PlayerState *self, s32);
extern void func_80093360(PlayerState *self, f32);
extern void func_800947EC(PlayerState *self, s32, s32);
extern void func_8009514C(PlayerState *self);
extern void func_800951B4(PlayerState *self);
extern void func_800959C8(PlayerState *self, f32, f32);
extern void func_80095A40(PlayerState *self);
extern void func_800961AC(PlayerState *self, s32);
extern s32 func_8009650C(PlayerState *self);
extern void func_800995B8();
extern s32 func_80099A58(PlayerState *self);
extern void func_8009B94C(PlayerState *self, s32);
extern void func_8009BA9C(PlayerState *self, s32);
extern f32 func_8009BB94(PlayerState *self);
extern void func_8009BC34(PlayerState *self);
extern void func_8009BC5C(PlayerState *self, f32);
extern void func_8009BD88();
extern void func_8009BF5C(PlayerState *self, f32);
extern f32 func_8009BFCC(PlayerState *self);
extern f32 func_8009BFD8(PlayerState *self);
extern void func_8009BFE4(PlayerState *self, f32, f32);
extern void func_8009C000(PlayerState *self);
extern void func_8009C128(PlayerState *self, f32[3]);
extern void func_8009DA40(PlayerState *self);
extern void func_8009DB04(PlayerState *self, s32, f32, s32);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern void func_8009E154(PlayerState *self, s32, f32 *);
extern void func_8009E474(PlayerState *self);
extern void func_8009E4AC(PlayerState *self);
extern void func_8009E55C(PlayerState *self, s32, f32);
extern s32 func_8009E69C(PlayerState *self, s32);
extern s32 func_8009E6C4(PlayerState *self, s32);
extern s32 func_8009E6F8(PlayerState *self);
extern void func_8009E830(PlayerState *self, s32);
extern s32 func_8009FBB0(PlayerState *self, f32[3], f32);
extern void func_800A0DC4(PlayerState *self, s32);
extern void func_800A16BC(s32);
extern void func_800A32C4(PlayerState *self, f32 *);
extern void func_800A3410(PlayerState *self, s32);
extern void func_800A38F0(PlayerState *self, s32, s32);
extern void func_800A3904(PlayerState *self, s32);
extern s32 func_800B5BE4(s32);
extern s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
extern void func_800D5234(s32);
extern f32 func_800D8FF8();
extern f32 func_800DC178(f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EFA4C(f32[3], f32, f32, f32);
extern f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern PlayerState *func_800F53D0(s32);
extern void func_800F5A00(s32, f32 *);
extern void func_800F82C0(s32);
extern void func_800F911C(s32);
extern void func_800F9BC4();

f32 _bakaztorpedo_entrypoint_1(PlayerState *self);
void _bakaztorpedo_entrypoint_2(PlayerState *self);
void _bakaztorpedo_entrypoint_4(PlayerState *self);
void _bakaztorpedo_entrypoint_5(PlayerState *self, f32, f32);
void _bakaztorpedo_entrypoint_6(PlayerState *self, s32);
void _bakaztorpedo_entrypoint_7(PlayerState *self, f32);
void _bakaztorpedo_entrypoint_8(PlayerState *self);

#endif // __BS_KAZTORPEDO_H__
