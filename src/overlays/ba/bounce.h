#ifndef __BA_BOUNCE_H__
#define __BA_BOUNCE_H__

#include "overlays/ba/assets.h"
#include "overlays/ba/playerstate.h"

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
