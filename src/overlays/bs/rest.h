#ifndef __BS_REST_H__
#define __BS_REST_H__

#include <ultra64.h>
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/data.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/fpctrl.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/roll.h"
#include "overlays/ba/yaw.h"
#include "overlays/bs/state.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76500.h"
#include "core2/1E76880.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E7D460.h"
#include "core2/1E7E9A0.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECD170.h"
#include "core2/1EE9AB0.h"
#include "core2/1EEF790.h"
#include "overlays/nc/ba/1p.h"
#include "common.h"
#include "player.h"

extern s32 D_80800910_bsrest[];
extern s32 D_80800920_bsrest[];
extern s32 D_80800930_bsrest[];

extern void _bsrest_entrypoint_0(PlayerState *self);
extern void _bsrest_entrypoint_1(PlayerState *self);
extern void _bsrest_entrypoint_2(PlayerState *self);
extern void _bsrest_entrypoint_3(PlayerState *self);
extern s32 _bsrest_entrypoint_4(s32 idx);
extern void _bsrest_entrypoint_5(PlayerState *self);
extern void _bsrest_entrypoint_6(PlayerState *self);
extern void _bsrest_entrypoint_7(PlayerState *self);
extern s32 _bsrest_entrypoint_8(s32 idx);
extern void _bsrest_entrypoint_9(PlayerState *self);
extern void _bsrest_entrypoint_10(PlayerState *self);
extern void _bsrest_entrypoint_11(PlayerState *self);
extern s32 _bsrest_entrypoint_12(s32 idx);
extern AssetId _bsrest_entrypoint_13(PlayerState *self);
extern void _bsrest_entrypoint_14(PlayerState *self);
extern void _bsrest_entrypoint_15(PlayerState *self, s32 arg1);
extern void _bsrest_entrypoint_16(PlayerState *self);
extern void _bsrest_entrypoint_17(PlayerState *self, s32 arg1);
extern void _bsrest_entrypoint_18(PlayerState *self);
extern s32 _bsrest_entrypoint_19(PlayerState *self, s32 arg1);
extern s32 _bsrest_entrypoint_20(PlayerState *self);

#endif // __BS_REST_H__
