#ifndef __BS_KAZFLY_H__
#define __BS_KAZFLY_H__

#include <ultra64.h>

#include "an/anctrl.h"
#include "ba/anim.h"
#include "ba/boost.h"
#include "ba/boost.h"
#include "ba/drone.h"
#include "ba/dust.h"
#include "ba/flag.h"
#include "ba/fly.h"
#include "ba/fpctrl.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/statemem.h"
#include "ba/stick.h"
#include "ba/sudie.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/splat.h"
#include "ch/usefeather.h"
#include "core2/1E2B200.h"
#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7D460.h"
#include "core2/1EA0690.h"
#include "core2/1ECA640.h"
#include "nc/badie.h"
#include "nc/badive.h"
#include "nc/bafly.h"
#include "funcs.h"
#include "player.h"

typedef struct bs_kazfly_s {
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    u8 unk1C;
} BsKazFly;

extern s32 func_8001211C();
extern f32 func_8009BFD8(PlayerState *self);
extern void func_8009DFD4(PlayerState *self, s32, f32, f32, s32, s32);
extern s32 func_8008D0E0(PlayerState *self);
extern void func_8009DF94(PlayerState *self, s32, f32, s32);
extern void func_8009E0DC(PlayerState *self);
extern void func_800A4DA4(PlayerState *self, s32);
extern void func_8009DF58(PlayerState *self, s32, f32);
extern void func_800A34AC(PlayerState *self, f32[3]);
extern void func_800EF04C(f32[3], f32 *);
extern s32 func_8009E704(PlayerState *self);
extern void func_80095A40(PlayerState *self);
extern void func_800961AC(PlayerState *self, s32);
extern s32 func_8009E74C(PlayerState *self, s32);
extern s32 func_8009E77C(PlayerState *self, s32);
extern void func_800A042C(PlayerState *self);
extern void func_800A0CF4(PlayerState *self, s32);
extern void func_808000AC_bskazfly(PlayerState *self);
extern void func_8009BA9C(PlayerState *self, f32 *);
extern void func_8009D874(PlayerState *self);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void func_800BBCB8(f32[3], s32, f32, s32, s32[]);
extern f32 func_800DC178(f32, f32);
extern void func_80093360(PlayerState *self, f32);
extern void func_800959C8(PlayerState *self, f32, f32);
extern void func_800CA9D8(s32, s32 *);
extern void func_800EE7F8(f32 dst[3], f32 src[3]);
extern void func_800EF934(f32 *, f32 *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800963C0(PlayerState *self, f32 *);
extern s32 func_80096434(PlayerState *self);
extern void func_80096440(PlayerState *self, f32 *);
extern s32 func_8009650C(PlayerState *self);
extern s32 func_80096628(PlayerState *self);
extern s32 func_800A1718(PlayerState *self);
extern void func_800A17A8(PlayerState *self, s32);
extern f32 func_800EEAA4(f32 *, f32[3]);
extern void func_800EF2A0(f32[3]);
extern void func_8009DDDC(PlayerState *);
extern f32 func_800EEFD4(f32[3]);
extern void func_800EF3DC(f32[3], s32);
extern void func_8008B1C8(AnimCtrl *, f32);
extern void func_8009DB04(PlayerState *self, s32, f32, s32);
extern void func_8009BB24(PlayerState *self, f32[3]);
extern void func_8009FE58(PlayerState *self);
extern f32 func_800D8FF8();
extern void func_8009DBF0(PlayerState *self, s32, f32);
extern void func_8009E100(PlayerState *self);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern s32 func_800F8B64();
extern void func_8008E95C(PlayerState *self);
extern s32 func_8008E124(PlayerState *self);
extern void func_80099B94(PlayerState *self);
extern void func_8009DEC0(PlayerState *self, s32, f32, f32, s32, s32);
extern s32 func_8009E6EC(PlayerState *self);
extern void func_8009E830(PlayerState *self, s32);
extern void func_800A046C(PlayerState *self);

#endif // __BS_KAZFLY_H__
