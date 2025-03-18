#ifndef __BA_WANDGLOW_H__
#define __BA_WANDGLOW_H__

#include <ultra64.h>

#include "playerstate.h"
#include "core2/1ECE0B0.h"

typedef struct ba_wandglow_s {
    f32 unk0[3];
    s32 unkC;
    u8 unk10;
} BaWandGlow;

void _bawandglow_entrypoint_1(s32 arg0, s32 arg1);
void _bawandglow_entrypoint_2(s32 arg0);
void _bawandglow_entrypoint_3(PlayerState *self, f32);
void _bawandglow_entrypoint_4(PlayerState *self, s32);
void _bawandglow_entrypoint_5(PlayerState *self);
void _bawandglow_entrypoint_6(PlayerState *self);
void _bawandglow_entrypoint_7(PlayerState *self);

#endif 
