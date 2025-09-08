#ifndef __BS_MUM_SWIM_H__
#define __BS_MUM_SWIM_H__

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/input.h"
#include "overlays/ba/key.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/yaw.h"
#include "overlays/bs/drone.h"
#include "overlays/bs/mum.h"
#include "overlays/bs/rest.h"
#include "overlays/bs/state.h"
#include "core1/1E29B60.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E93440.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

extern s32 D_80800B30_bsmumswim[];
extern s32 D_80800B40_bsmumswim[];
extern s32 D_80800B50_bsmumswim[];
extern s32 D_80800B60_bsmumswim[];
extern s32 D_80800B70_bsmumswim[];

extern void _bsmumswim_entrypoint_0(PlayerState *self);
extern void _bsmumswim_entrypoint_1(PlayerState *self);
extern void _bsmumswim_entrypoint_2(PlayerState *self);
extern s32 _bsmumswim_entrypoint_3(s32 idx);
extern s32 _bsmumswim_entrypoint_4(s32 idx);
extern s32 _bsmumswim_entrypoint_5(s32 idx);
extern s32 _bsmumswim_entrypoint_6(s32 idx);
extern s32 _bsmumswim_entrypoint_7(s32 idx);

#endif // __BS_MUM_SWIM_H__
