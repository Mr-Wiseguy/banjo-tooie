#ifndef __BS_KAZFLAMETHROWER_H__
#define __BS_KAZFLAMETHROWER_H__

#include <ultra64.h>

#include "ba/timer.h"
#include "ba/anim.h"
#include "ba/key.h"
#include "ba/yaw.h"
#include "ba/playerstate.h"
#include "bs/kazstill.h"
#include "funcs.h"

// This is probably not the "correct" struct.
// It's taken in by func_8009C128 and func_800EF04C so this might be a position where unk4 could be the y coordinate.
typedef struct bz_kazflamethrower_s {
    s32 pad0;
    f32 unk4;
} BzKazFlamethrowerS;

extern f32 func_8009BFCC(PlayerState *self);
extern void func_8009C128(PlayerState *self, BzKazFlamethrowerS *);
extern void func_8009DF18(PlayerState *self, s32, f32, s32);
extern void func_800EEC30(s32, f32, f32, f32);
extern void func_800EF04C(BzKazFlamethrowerS *, f32 *);
extern void func_800EFA98(f32 *, s32, f32);
extern void func_80800094_bskazflamethrower(PlayerState *self, s32);

void _baflamethrower_entrypoint_5(PlayerState *self);

#endif // __BS_KAZFLAMETHROWER_H__