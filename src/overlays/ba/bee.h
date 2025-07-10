#ifndef __BA_BEE_H__
#define __BA_BEE_H__

#include "common.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E93440.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECD170.h"
#include "core2/1ECE0B0.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
#include "overlays/ch/stinger.h"
typedef struct {
    f32 unk0;
    f32 cooldown_time;
    f32 unk8;
} BaBeeSub0;


typedef struct ba_bee_s {
    BaBeeSub0 unk0[2];
    f32 cooldown;
    u8 index;
    //u8 pad1D[0x3];
} BaBee;

s32 _babee_entrypoint_0(void);
void _babee_entrypoint_1(s32 arg0);
void _babee_entrypoint_2(PlayerState *self);
void _babee_entrypoint_3(PlayerState *self);
void _babee_entrypoint_4(PlayerState *self);
void _babee_entrypoint_5(PlayerState *self);
void _babee_entrypoint_6(PlayerState *self);
void _babee_entrypoint_7(PlayerState *self, f32 arg1, f32 arg2, f32 arg3);
void _babee_entrypoint_8(PlayerState *self);

s32 babee_entrypoint_0(void);
void babee_entrypoint_1(s32 arg0);
void babee_entrypoint_2(PlayerState *self);
void babee_entrypoint_3(PlayerState *self);
void babee_entrypoint_4(PlayerState *self);
void babee_entrypoint_5(PlayerState *self);
void babee_entrypoint_6(PlayerState *self);
void babee_entrypoint_7(PlayerState *self, f32 arg1, f32 arg2, f32 arg3);
void babee_entrypoint_8(PlayerState *self);

#endif // __BA_BEE_H__
