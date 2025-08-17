#ifndef __BS_KAZ_CROUCH_H__
#define __BS_KAZ_CROUCH_H__

#include "common.h"

#include "bs.h"
#include "core2/anctrl.h"
#include "overlays/ba/key.h"
#include "overlays/ba/input.h"
#include "overlays/ba/timer.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/anim.h"
#include "overlays/bs/kaz.h"
#include "core2/1E6B900.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E7BFA0.h"
#include "core2/1EA0690.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1E72EA0.h"

extern BanjoStateId _bskazcrouch_entrypoint_0(PlayerState* self, BanjoStateId arg1);
extern void _bskazcrouch_entrypoint_1(PlayerState *self);
// This might be inaccurate
// extern void _bskazcrouch_entrypoint_2(PlayerState *self);
extern void _bskazcrouch_entrypoint_3(PlayerState *self);
extern s32 _bskazcrouch_entrypoint_4(s32 idx);

#endif // __BS_KAZ_CROUCH_H__
