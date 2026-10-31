#ifndef __CORE2_1E6F080_H__
#define __CORE2_1E6F080_H__

#include "common.h"

#include <ultra64.h>

#include "ba/playerstate.h"
#include "ba/hitspline.h"
#include "ba/statetimer.h"
#include "ba/yaw.h"

#include "core2/1ECB9F0.h"
#include "core2/1E75920.h"
#include "core2/1EA0210.h"
#include "core2/1E9F060.h"
#include "core2/1EC3810.h"
#include "core2/1EA1DA0.h"
#include "core2/1EC8070.h"
#include "core2/1ECB0F0.h"
#include "core2/1EADCF0.h"
#include "core2/1EC9740.h"
#include "core2/1E97EF0.h"
#include "core1/1E2B200.h"

typedef struct {
    s32 unk0;
    f32 unk4;
    Vec3f unk8;
    Vec3f unk14;
    Vec3f unk20;
    f32 unk2C[2]; // ?? should be Vec3f, too
} Unk80126E30;

void func_80095870(PlayerState*, f32*, f32*);
s32 func_8009588C(PlayerState*);
s32 func_800958A4(PlayerState* arg0, f32 arg1, f32 arg2);
void func_8009590C(PlayerState*, f32);
void func_80095964(PlayerState*, s32);
void func_800959C8(PlayerState *, f32, f32);
void func_80095A08(PlayerState*, s32, s32);
void func_80095A40(PlayerState *);
void func_80095AD0(PlayerState*);
void func_80095C10(PlayerState*);
f32 func_80095C34(f32, f32, f32);
void func_80095C94(PlayerState*);
void func_800961A0(PlayerState*, s32);
void func_800961AC(PlayerState *, s32);
void func_80096254(PlayerState*, s32);
void func_80096260(PlayerState*);
void func_800962B0(PlayerState *, s32);
f32 func_800962D4(PlayerState*);
f32 func_8009630C(PlayerState *);
f32 player_getGroundHeight(PlayerState *);
s32 func_80096388(PlayerState *);
void func_80096394(PlayerState*, f32*);
void func_800963C0(PlayerState *, f32[3]);
f32 func_800963E4(PlayerState*);
s32 func_8009640C(PlayerState*);
s32 func_80096434(PlayerState *);
void func_80096440(PlayerState *, f32 *);
void func_8009646C(PlayerState*, f32[3][3]);
f32 player_getWaterHeight(PlayerState *);
s32 player_atWaterSurface(PlayerState *);
s32 func_8009650C(PlayerState *);
s32 func_80096518(PlayerState*);
s32 player_touchingWater(PlayerState*);
s32 func_80096530(PlayerState*);
s32 func_80096544(PlayerState *);
s32 func_80096568(PlayerState*, s32);
s32 func_8009659C(PlayerState*, s32);
Unk80132ED0* func_800965D4(PlayerState*);
void func_800965E0(PlayerState*, void*);
void func_80096604(PlayerState*, f32[3][3]);
s32 func_80096628(PlayerState *);
s32 func_8009664C(PlayerState*);
s32 func_80096670(PlayerState*);
s32 func_80096694(PlayerState*);
s32 func_800966BC(PlayerState*);
void func_80096704(PlayerState*);
void func_80096728(PlayerState*);
void func_80096768(PlayerState*);
void func_8009679C(PlayerState*);
s32 func_80096ACC(f32*, f32*, s32, s32);
s32 func_80096DD4(s32, s32, f32*, f32*);
s32 func_80096E30(ba_unknown_98_s*, f32*, f32*, f32, f32, f32);
s32 func_8009700C(PlayerState*, f32*, f32*, f32, f32);
s32 func_800970A4(f32*, f32*, f32);
s32 func_80097104(PlayerState*, f32*, f32);
s32 func_800972BC(PlayerState*, f32*);
f32 func_800974FC(PlayerState*);
u8 func_80097524(PlayerState *);
s32 func_80097530(PlayerState *);
s32 func_800976DC(PlayerState*);
void func_80097858(PlayerState*);
void func_8009788C(PlayerState*);
void func_800978A4(PlayerState*);

#endif // __CORE2_1E6F080_H__
