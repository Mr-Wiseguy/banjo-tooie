#ifndef __BS_STATE_H__
#define __BS_STATE_H__

#include "ba/playerstate.h"

// TODO validate that the rest of these state
typedef enum bs_state_e {
    BS_STATE_0_INVALID = 0x0,
    BS_STATE_1_IDLE,
    BS_STATE_1_SLOW_WALK,

    BS_STATE_7_CROUCH = 0x7,

    BS_STATE_F_BBUSTER = 0xF,

    BS_STATE_20_LANDING = 0x20,

    BS_STATE_2F_FALL = 0x2F,

    BS_STATE_3D_FALL_TUMBLING = 0x3D,

    BS_STATE_48 = 0x48,
    BS_STATE_49,
    BS_STATE_4A,
    BS_STATE_4B,
    BS_STATE_4C_LANDING_IN_WATER,
    BS_STATE_4D,

    BS_STATE_67 = 0x67,
    BS_STATE_68,

    BS_STATE_72 = 0x72,

    BS_STATE_84 = 0x84,

    BS_STATE_A6 = 0xA6,
    
    BS_STATE_A8 = 0xA8,

    BS_STATE_B6_BILL_DRILL = 0xB6,

    BS_STATE_BB = 0xBB,
    BS_STATE_BC,
    BS_STATE_BD,
    BS_STATE_BE,
    
    BS_STATE_C1 = 0xC1,

    BS_STATE_C3 = 0xC3,
    BS_STATE_C4,
    BS_STATE_C5,
    BS_STATE_C6,
    BS_STATE_C7,

    BS_STATE_DD = 0xDD,
    BS_STATE_DE,
    BS_STATE_DF,
    BS_STATE_E0,

    BS_STATE_101 = 0x101,

    BS_STATE_154 = 0x154,
    BS_STATE_155,

    BS_STATE_159 = 0x159,
    BS_STATE_15A,
    BS_STATE_15B,
    BS_STATE_15C,
    BS_STATE_15D,
    BS_STATE_15E,
    BS_STATE_15F,
    BS_STATE_160,
    BS_STATE_161,
    BS_STATE_162,

    BS_STATE_173 = 0x173,
    BS_STATE_174,
    BS_STATE_175,
    BS_STATE_176,
    BS_STATE_177,

    BS_STATE_186 = 0x186,
    BS_STATE_187,
    BS_STATE_188
} BanjoStateId;

typedef struct bs_state_s {
    s32 previous;
    s32 current;
    s32 next;
} BanjoState;

BanjoStateId bs_getTypeOfJump(PlayerState *self);
void bs_setState(PlayerState *self, BanjoStateId nextState);

#endif // __BS_STATE_H__