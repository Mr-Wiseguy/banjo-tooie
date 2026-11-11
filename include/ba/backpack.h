#ifndef __BA_BACKPACK_H__
#define __BA_BACKPACK_H__

#include "common.h"
#include "player.h"
#include "ba/anim.h"
#include "ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/1E6B900.h"
#include "core2/1EB57A0.h"
#include "core2/1EB5E70.h"

typedef enum ba_backpack_state_e {
    BA_BACKPACK_STATE_0 = 0,
    BA_BACKPACK_STATE_7_FREE = 7
} BaBackpackState;

typedef struct ba_backpack_s {
    s32 unk0;
    UNKfunc_800DBEB0_ARG0* unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    s32 state;
    f32 scale;
    AnimCtrl *anctrl;
} BaBackpack;

s32 _babackpack_get_size(void);
s32 _babackpack_entrypoint_1(PlayerState *self);
void _babackpack_entrypoint_2(PlayerState *self);
void _babackpack_entrypoint_3(PlayerState *self, f32 *position, f32 *arg2, s32 arg3, f32 *arg4);
s32 _babackpack_get_state(PlayerState *self);
void _babackpack_entrypoint_5(PlayerState *self, s32 arg1, s32 arg2);
void _babackpack_entrypoint_6(PlayerState *self, f32* arg1, s32 arg2);
f32 _babackpack_get_scale(PlayerState *self);
void _babackpack_entrypoint_8(PlayerState *self);
void _babackpack_entrypoint_9(PlayerState *self);
void _babackpack_set_state(PlayerState *, BaBackpackState);

s32 babackpack_get_size(void);
void __babackpack_free(PlayerState* self);
void func_8080003C_babackpack(PlayerState* self);
s32 babackpack_entrypoint_1(PlayerState* self);
void func_8080011C_babackpack(PlayerState* self, s32 arg1, f32 scale);
s32 func_8080021C_babackpack(PlayerState* self);
void babackpack_entrypoint_2(PlayerState* self);
void babackpack_entrypoint_3(PlayerState* self, f32* position, f32* arg2, s32 arg3, f32* arg4);
s32 babackpack_get_state(PlayerState* self);
void babackpack_entrypoint_5(PlayerState* self, s32 arg1, s32 arg2);
void babackpack_entrypoint_6(PlayerState* self, s32 arg1, s32 arg2);
f32 babackpack_get_scale(PlayerState* self);
void babackpack_entrypoint_8(PlayerState* self);
void babackpack_entrypoint_9(PlayerState* self);
void babackpack_set_state(PlayerState* self, BaBackpackState state);

#endif // __BA_BACKPACK_H__
