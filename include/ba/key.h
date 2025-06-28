#ifndef __BA_KEY_H__
#define __BA_KEY_H__

#include <ultra64.h>

#include "buttons.h"     // ButtonId
#include "ba/playerstate.h" // PlayerState
#include "core2/1E965B0.h"  // unkfunc_800BCE84


typedef struct ba_key_s {
    unkfunc_800BCE84 *unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 state[0xE];
    u8 prev_state[0xE];
} BaKey;

// Definitions
s32 bakey_getStructSize(void);
s32 bakey_getControllerIndex(PlayerState *self);
void bakey_func_8009191C(PlayerState *self, ButtonId id, s32 arg2);
void bakey_func_80091940(PlayerState *self, ButtonId id, s32 arg2);
s32 bakey_func_80091964(PlayerState *self);
s32 bakey_heldCount(PlayerState *self, ButtonId id);
s32 bakey_releaseCount(PlayerState *self, ButtonId id);
void bakey_getStick(PlayerState *self, f32 pStickValues[2]);
int bakey_held(PlayerState *self, ButtonId id);
int bakey_released(PlayerState *self, ButtonId id);
int bakey_pressed(PlayerState *self, ButtonId id);
int bakey_newlyReleased(PlayerState *self, ButtonId id);
void bakey_free(PlayerState *self);
void bakey_defrag(PlayerState *self);
void bakey_init(PlayerState *self);
void bakey_setControllerIndex(PlayerState *self, s32 controller_index);
void bakey_func_80091C14(PlayerState *self, s32 value);
void bakey_func_80091C74(PlayerState *self, s32 arg1);
s32 bakey_setState(PlayerState *self, ButtonId id, int arg2);
int bakey_getBitfield(PlayerState *self);
void bakey_update(PlayerState *self);


#endif // __BA_KEY_H__
