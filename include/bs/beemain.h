#ifndef __BS_BEEMAIN_H__
#define __BS_BEEMAIN_H__

#include <ultra64.h>

#include "common.h"
#include "player.h"

#include "bee.h"

#include "bs/state.h"
#include "ba/playerstate.h"
#include "ba/flag.h"
#include "ba/physics.h"
#include "ba/bounce.h"
#include "ba/timer.h"
#include "ba/stick.h"
#include "ba/bee.h"
#include "ba/drone.h"
#include "ba/input.h"
#include "ba/sudie.h"

#include "nc/ba/die.h"

#include "core1/1E2B200.h"

#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E6B900.h"
#include "core2/1E6E870.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75710.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1EC3810.h"
#include "core2/1ECA640.h"
#include "core2/1ED4E30.h"

// Entrypoints
extern void _bsbee_entrypoint_1(PlayerState*);
extern void _bsbee_entrypoint_2(PlayerState*);

// Code
void func_80800000_bsbeemain(PlayerState*);
void func_8080002C_bsbeemain(PlayerState*);
void func_80800058_bsbeemain(PlayerState*);
void func_808000C0_bsbeemain(PlayerState*);
void func_80800128_bsbeemain(PlayerState*);
void func_808001FC_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_0(s32);
void func_80800238_bsbeemain(PlayerState*);
void func_808002C0_bsbeemain(PlayerState*);
void func_808003B4_bsbeemain(PlayerState*);
void func_808003F0_bsbeemain(PlayerState*);
void func_80800548_bsbeemain(PlayerState*);
void func_80800788_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_2(s32);
void func_808007C4_bsbeemain(PlayerState*);
void func_80800874_bsbeemain(PlayerState*);
void func_80800A74_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_3(s32);
void bsbeemain_entrypoint_4(PlayerState*);
void bsbeemain_entrypoint_5(PlayerState*);
void bsbeemain_entrypoint_6(PlayerState*);
s32 bsbeemain_entrypoint_7(s32);
void func_80800B68_bsbeemain(PlayerState*);
void func_80800B90_bsbeemain(PlayerState*);
void func_80800BD0_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_8(s32);
void func_80800C28_bsbeemain(PlayerState*);
void func_80800E0C_bsbeemain(PlayerState*);
void func_80800FB8_bsbeemain(PlayerState*);
void func_80800FF0_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_9(s32);
void func_80801080_bsbeemain(PlayerState*);
void func_808010A8_bsbeemain(PlayerState*);
void func_808010F4_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_10(s32);
void func_80801130_bsbeemain(PlayerState*);
void func_8080118C_bsbeemain(PlayerState*);
void func_808011E8_bsbeemain(PlayerState*);
s32 bsbeemain_entrypoint_11(s32);

#endif // __BS_BEEMAIN_H__
