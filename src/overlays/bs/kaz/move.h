#ifndef __BS_KAZ_MOVE_H__
#define __BS_KAZ_MOVE_H__

#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/duo.h"
#include "overlays/ba/dust.h"
#include "overlays/ba/input.h"
#include "overlays/ba/key.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/roll.h"
#include "overlays/ba/shoes.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/yaw.h"
#include "overlays/bs/kaz.h"
#include "overlays/bs/splat.h"
#include "core2/1E66990.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1ECA640.h"
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

#endif // __BS_KAZ_MOVE_H__
