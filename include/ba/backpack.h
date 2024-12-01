#ifndef __BA_BACKPACK_H__
#define __BA_BACKPACK_H__

#include "playerstate.h"
#include "../an/anctrl.h"

typedef enum ba_backpack_state_e {
    BA_BACKPACK_STATE_0 = 0,
    BA_BACKPACK_STATE_7_FREE = 7
} BaBackpackState;

typedef struct ba_backpack_s {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    s32 state;
    f32 scale;
    AnimCtrl *anctrl;
} BaBackpack;

s32 babackpack_get_size(void);
s32 babackpack_entrypoint_1(PlayerState *self);
void babackpack_entrypoint_2(PlayerState *self);
void babackpack_entrypoint_3(PlayerState *self, f32 *position, f32 *arg2, s32 arg3, f32 *arg4);
s32 babackpack_get_state(PlayerState *self);
void babackpack_entrypoint_5(PlayerState *self, s32 arg1, s32 arg2);
void babackpack_entrypoint_6(PlayerState *self, s32 arg1, s32 arg2);
f32 babackpack_get_scale(PlayerState *self);
void babackpack_entrypoint_8(PlayerState *self);
void babackpack_entrypoint_9(PlayerState *self);
void babackpack_set_state(PlayerState *, BaBackpackState);

#endif // __BA_BACKPACK_H__
