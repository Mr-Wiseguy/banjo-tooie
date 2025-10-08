#ifndef __BS_KAZ_DIE_H__
#define __BS_KAZ_DIE_H__

#include "common.h"
#include <ultra64.h>

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/dust.h"
#include "overlays/ba/timer.h"
#include "overlays/ba/motor.h"
#include "overlays/ba/sudie.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/roll.h"
#include "overlays/ba/yaw.h"
#include "overlays/bs/kaz.h"
#include "nc/ba/die.h"
#include "core2/1E2B200.h"
#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E6E870.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E76880.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"

extern void _bskazdie_entrypoint_0(PlayerState *self);
extern void _bskazdie_entrypoint_1(PlayerState *self);
extern void _bskazdie_entrypoint_2(PlayerState *self);
extern s32 _bskazdie_entrypoint_3(s32 idx);

#endif // __BS_KAZ_DIE_H__
