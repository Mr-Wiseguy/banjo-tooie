#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include <ultra64.h>

#include "buttons.h"

// TODO validate that the rest of these state
typedef enum bs_e {
    BS_1_IDLE = 0x1,
    BS_CROUCH = 0x7,
    BS_2F_FALL = 0x2F
} BanjoStateId;

typedef struct player_state_s {
    u8 pad0[0x15C];
    s32 unk15C;
    s32 unk160;
    s32 unk164;
} PlayerState;

void func_80098140(PlayerState* thisx, s32, s32);
s32 func_80094510(PlayerState* thisx);
s32 button_held(PlayerState*, ButtonId);

#endif
