#ifndef __BS_KAZFLY_H__
#define __BS_KAZFLY_H__

#include "common.h"
#include <ultra64.h>

#include "core2/anctrl.h"
#include "core2/1E72EA0.h"
#include "ba/anim.h"
#include "ba/boost.h"
#include "ba/boost.h"
#include "ba/drone.h"
#include "ba/dust.h"
#include "ba/flag.h"
#include "ba/fly.h"
#include "ba/fpctrl.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/roll.h"
#include "ba/statemem.h"
#include "ba/stick.h"
#include "ba/sudie.h"
#include "ba/timer.h"
#include "ba/yaw.h"
#include "bs/drone.h"
#include "bs/splat.h"
#include "ch/usefeather.h"
#include "core2/1E29B60.h"
#include "core2/1E2B200.h"
#include "core2/1E66990.h"
#include "core2/1E67DA0.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E76880.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E7AB30.h"
#include "core2/1E7BFA0.h"
#include "core2/1E7D460.h"
#include "core2/1E93440.h"
#include "core2/1EA0690.h"
#include "core2/1EA3AA0.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECE0B0.h"
#include "overlays/nc/badie.h"
#include "overlays/nc/badive.h"
#include "overlays/nc/bafly.h"
#include "funcs.h"
#include "player.h"

typedef struct bs_kazfly_s {
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    u8 unk1C;
} BsKazFly;

s32 D_80801C10_bskazfly[];
s32 D_80801C38_bskazfly[];
s32 D_80801C48_bskazfly[];
s32 D_80801C58_bskazfly[];
s32 D_80801C68_bskazfly[];
s32 D_80801C78_bskazfly[];
s32 D_80801C88_bskazfly[];
s32 D_80801C98_bskazfly[];
s32 D_80801CA8_bskazfly[];
s32 D_80801CB8_bskazfly[];
s32 D_80801CC8_bskazfly[];

extern s32 _bskazfly_entrypoint_0(s32 idx);
extern s32 _bskazfly_entrypoint_1(s32 idx);
extern s32 _bskazfly_entrypoint_2(s32 idx);
extern s32 _bskazfly_entrypoint_3(s32 idx);
extern s32 _bskazfly_entrypoint_4(s32 idx);
extern s32 _bskazfly_entrypoint_5(s32 idx);
extern s32 _bskazfly_entrypoint_6(s32 idx);
extern s32 _bskazfly_entrypoint_7(s32 idx);
extern s32 _bskazfly_entrypoint_8(s32 idx);
extern s32 _bskazfly_entrypoint_9(s32 idx);

#endif // __BS_KAZFLY_H__
