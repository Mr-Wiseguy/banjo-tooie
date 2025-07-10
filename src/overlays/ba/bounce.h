#ifndef __BA_BOUNCE_H__
#define __BA_BOUNCE_H__

#include "assets.h"
#include "common.h"
#include "core2/1E2B200.h"
#include "core2/1E67DA0.h"
#include "core2/1E6E870.h"
#include "core2/1E72EA0.h"
#include "core2/1E75620.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1E78BF0.h"
#include "core2/1E7BFA0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EDA900.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/react.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/timer.h"

typedef struct ba_bounce_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 padE[0x2];
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} BaBounce;

s32 babounce_entrypoint_0(void);
s32 babounce_entrypoint_1(PlayerState *self);
int babounce_entrypoint_2(PlayerState *self);
void babounce_entrypoint_3(PlayerState *self);
void babounce_entrypoint_4(PlayerState *self, s32 arg1);
void babounce_entrypoint_5(PlayerState *self, AssetId asset_id, f32 arg2);
void babounce_entrypoint_6(PlayerState *self, AssetId asset_id, f32 arg2, f32 arg3, f32 arg4);
void babounce_entrypoint_7(PlayerState *self, s32 arg1);
s32 babounce_entrypoint_8(PlayerState *self);
s32 babounce_entrypoint_9(PlayerState *self);
s32 babounce_entrypoint_10(PlayerState *self);


s32 _babounce_entrypoint_0(void);
s32 _babounce_entrypoint_1(PlayerState *self);
int _babounce_entrypoint_2(PlayerState *self);
void _babounce_entrypoint_3(PlayerState *self);
void _babounce_entrypoint_4(PlayerState *self, s32 arg1);
void _babounce_entrypoint_5(PlayerState *self, AssetId asset_id, f32 arg2);
void _babounce_entrypoint_6(PlayerState *self, AssetId asset_id, f32 arg2, f32 arg3, f32 arg4);
void _babounce_entrypoint_7(PlayerState *self, s32 arg1);
s32 _babounce_entrypoint_8(PlayerState *self);
s32 _babounce_entrypoint_9(PlayerState *self);
s32 _babounce_entrypoint_10(PlayerState *self);

#endif // __BA_BOUNCE_H__
