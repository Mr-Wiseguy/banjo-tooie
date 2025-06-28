#ifndef __BS_MUM_H__
#define __BS_MUM_H__

#include "core2/anctrl.h"
#include "core2/1E72EA0.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/bounce.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/key.h"
#include "overlays/ba/mum.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/sudie.h"
#include "overlays/bs/drone.h"
#include "overlays/bs/mummove.h"
#include "overlays/bs/rest.h"
#include "overlays/bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6E870.h"
#include "core2/1E75710.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1EB5980.h"
#include "core2/1ECA640.h"
#include "common.h"
#include "player.h"
#include <ultra64.h>

extern s32 D_80801140_bsmum[];
extern s32 D_80801150_bsmum[];
extern s32 D_80801160_bsmum[];
extern s32 D_80801170_bsmum[];
extern s32 D_80801180_bsmum[];
extern s32 D_80801190_bsmum[];
extern s32 D_808011A0_bsmum[];
extern s32 D_808011B0_bsmum[];

extern void _bsmum_entrypoint_0(PlayerState *self);
extern void _bsmum_entrypoint_1(PlayerState *self);
extern void _bsmum_entrypoint_2(PlayerState *self);
extern s32 _bsmum_entrypoint_3(s32 idx);
extern s32 _bsmum_entrypoint_4(s32 idx);
extern s32 _bsmum_entrypoint_5(s32 idx);
extern s32 _bsmum_entrypoint_6(s32 idx);
extern s32 _bsmum_entrypoint_7(s32 idx);
extern void _bsmum_entrypoint_8(PlayerState *self);
extern void _bsmum_entrypoint_9(PlayerState *self);
extern void _bsmum_entrypoint_10(PlayerState *self);
extern s32 _bsmum_entrypoint_11(s32 idx);
extern s32 _bsmum_entrypoint_12(s32 idx);
extern void _bsmum_entrypoint_13(PlayerState *self);
extern s32 _bsmum_entrypoint_14(s32 idx);
#endif // __BS_MUM_H__
