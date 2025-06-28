#ifndef __BS_KAZMOVE_H__
#define __BS_KAZMOVE_H__

#include "common.h"
#include <ultra64.h>

#include "core2/anctrl.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/dust.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/shoes.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/kaz.h"
#include "bs/splat.h"
#include "core2/1E66990.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1ECA640.h"
#include "funcs.h"
#include "player.h"

extern s32 D_80800C70_bskazmove[];
extern s32 D_80800C80_bskazmove[];

extern void _bskazmove_entrypoint_0(PlayerState *self);
extern void _bskazmove_entrypoint_1(PlayerState *self);
extern void _bskazmove_entrypoint_2(PlayerState *self);
extern void _bskazmove_entrypoint_3(PlayerState *self);
extern s32 _bskazmove_entrypoint_4(s32 idx);
extern void _bskazmove_entrypoint_5(PlayerState *self, s32 arg1);
extern void _bskazmove_entrypoint_6(PlayerState *self);
extern void _bskazmove_entrypoint_7(PlayerState *self);
extern void _bskazmove_entrypoint_8(PlayerState *self);
extern void _bskazmove_entrypoint_9(PlayerState *self);
extern s32 _bskazmove_entrypoint_10(s32 idx);
extern void _bskazmove_entrypoint_11(PlayerState *self, s32 arg1);

#endif // __BS_KAZMOVE_H__
