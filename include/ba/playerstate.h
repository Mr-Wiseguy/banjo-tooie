#ifndef __BANJOSTATE_H__
#define __BANJOSTATE_H__

#include <ultra64.h>

#include "buttons.h"

// TODO validate that the rest of these state
typedef enum bs_e {
    BS_1_IDLE = 0x1,
    BS_2_SLOW_WALK = 0x2,

    BS_CROUCH = 0x7,
    
    BS_F_BBUSTER = 0xF,

    BS_20_LANDING = 0x20,

    BS_2F_FALL = 0x2F,

    BS_3D_FALL_TUMBLING = 0x3D,

    BS_4C_LANDING_IN_WATER = 0x4C,

    BS_B6_BILL_DRILL = 0xB6
} BanjoStateId;

typedef struct player_state_s {
    u8 pad0[0x40];
    struct ba_key_s *key; // 0x40
    u8 pad44[0x3C];
    struct ba_flag_s *flag; //0x80
    u8 pad84[0x20];
    struct ba_input_s *input; //0xA4
    u8 padA8[0x4C];
    struct ba_roll_s *roll;   // 0xF4
    struct ba_yaw_s *yaw; // 0xF8
    u8 padFC[0x2C];
    struct ba_stick_s *stick; // 0x128
    u8 pad12C[0x30];
    union {
        s32 word;
        u8 bytes[4];
    } unk15C;
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    s32 unk164;
    u8 pad168[4];
    f32 unk16C;
    f32 unk170;
    u8 pad174[0x10];
    s32 unk184;
} PlayerState;

s32 func_80094510(PlayerState* thisx);

#endif
