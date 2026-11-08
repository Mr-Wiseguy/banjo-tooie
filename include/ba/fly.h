#ifndef __BY_FLY_H__
#define __BY_FLY_H__

#include <ultra64.h>

#include "common.h"
#include "player.h"

#include "ba/anim.h"
#include "ba/flag.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/playerstate.h"
#include "ba/physics.h"
#include "ba/roll.h"
#include "ba/stick.h"
#include "ba/yaw.h"

#include "bs/state.h"

#include "ba/fpctrl.h"
#include "ba/egg/fire.h"

#include "nc/ba/fly.h"

#include "gc/statusDll.h"

#include "su/inv.h"

#include "core1/1E2B200.h"

#include "core2/anctrl.h"

#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E6F080.h"
#include "core2/1E75620.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E9A960.h"
#include "core2/1EA3AA0.h"
#include "core2/1EBAA10.h"
#include "core2/1EC3810.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECB9F0.h"
#include "core2/1EE9AB0.h"

// Code
void _bafly_entrypoint_1(PlayerState*, f32 *, f32 *, f32);
s32 _bafly_entrypoint_2(PlayerState*);
u8 bafly_entrypoint_3(PlayerState*);
void _bafly_entrypoint_4(PlayerState*);
void _bafly_entrypoint_5(PlayerState*);
void _bafly_entrypoint_6(PlayerState*, f32);
void _bafly_entrypoint_7(PlayerState*, s32);
void _bafly_entrypoint_8(PlayerState*, f32, f32, f32, f32, f32, f32, f32);
void _bafly_entrypoint_9(PlayerState*);
void _bafly_entrypoint_10(PlayerState*, f32, f32);
void _bafly_entrypoint_11(PlayerState*);
s32 _bafly_entrypoint_12(PlayerState*);
void _bafly_entrypoint_13(PlayerState*, s32, enum asset_e, f32);
void bafly_entrypoint_14(PlayerState* arg0, BanjoStateId, BanjoStateId);
void _bafly_entrypoint_15(PlayerState*);
void _bafly_entrypoint_16(PlayerState*, s32, f32);
void _bafly_entrypoint_17(PlayerState*, s32, s32, u8 *);
void _bafly_entrypoint_18(PlayerState*);
void _bafly_entrypoint_19(PlayerState*);
void _bafly_entrypoint_20(PlayerState*);
void _bafly_entrypoint_21(PlayerState*);

#endif // __BY_FLY_H__
