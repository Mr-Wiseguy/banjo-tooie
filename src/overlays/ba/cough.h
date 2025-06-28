#ifndef __BA_COUGH_H__
#define __BA_COUGH_H__

#include "overlays/ba/playerstate.h"

typedef struct ba_cough_s {
    u8 unk0;
    f32 unk4;
} BaCough;

s32 bacough_entrypoint_0(void);
s32 bacough_entrypoint_1(PlayerState *self);
void bacough_entrypoint_2(PlayerState *self);
void bacough_entrypoint_3(PlayerState *self);
void bacough_entrypoint_4(PlayerState *self, s32 arg1);
void bacough_entrypoint_5(PlayerState *self);

s32 _bacough_entrypoint_0(void);
s32 _bacough_entrypoint_1(PlayerState *self);
void _bacough_entrypoint_2(PlayerState *self);
void _bacough_entrypoint_3(PlayerState *self);
void _bacough_entrypoint_4(PlayerState *self, s32 arg1);
void _bacough_entrypoint_5(PlayerState *self);

#endif // __BA_COUGH_H__
