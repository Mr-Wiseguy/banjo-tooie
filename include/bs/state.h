#ifndef __BS_STATE_H__
#define __BS_STATE_H__

#include "ba/playerstate.h"

// TODO validate that the rest of these state
typedef enum bs_state_e {
    BS_0_INVALID = 0x0,
    BS_STATE_1_IDLE,
    BS_STATE_1_SLOW_WALK,

    BS_STATE_7_CROUCH = 0x7,
    
    BS_STATE_F_BBUSTER = 0xF,

    BS_STATE_20_LANDING = 0x20,

    BS_STATE_2F_FALL = 0x2F,

    BS_STATE_3D_FALL_TUMBLING = 0x3D,

    BS_STATE_4C_LANDING_IN_WATER = 0x4C,

    BS_STATE_B6_BILL_DRILL = 0xB6
} BanjoStateId;

typedef struct bs_state_s {
    s32 previous;
    s32 current;
    s32 next;
} BanjoState;

#endif // __BS_STATE_H__