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
    /* 0x00 */ struct ba_alarm_s *alarm;
    /* 0x04 */ struct ba_anim_s *anim;
    /* 0x08 */ struct ba_attach_s *attach;
    /* 0x0C */ struct ba_unknown_c_s *unkC; // baavatar? from BK XBox debug strings?
    /* 0x10 */ struct ba_babykaz_s *babykaz;
    /* 0x14 */ struct ba_backpack_s *backpack;
    u8 pad18[0x4];
    /* 0x1C */ struct ba_bee_s *bee;
    /* 0x20 */ struct ba_unknown_20_s *unk20;
    /* 0x24 */ struct ba_boost_s *boost;
    u8 pad28[0x4];
    /* 0x2C */ struct ba_unknown_2C_s *unk2C; //something with camera
    u8 pad30[0x10];
    /* 0x40 */ struct ba_key_s *key;
    u8 pad44[0x3C];
    /* 0x80 */ struct ba_flag_s *flag;
    u8 pad84[0x20];
    /* 0xA4 */ struct ba_input_s *input;
    u8 padA8[0x4C];
    /* 0xF4 */ struct ba_roll_s *roll;
    /* 0xF8 */ struct ba_yaw_s *yaw;
    u8 padFC[0x2C];
    /* 0x128 */ struct ba_stick_s *stick;
    u8 pad12C[0x10];
    /* 0x13C */ struct ba_timer_s *timer;
    /* 0x140 */ struct ba_translate_s *translate;
    /* 0x144 */ struct ba_van_s *van;
    /* 0x148 */ struct ba_wandglow_s *wandglow;
    /* 0x14C */ struct ba_washer_s *washer;
    u8 pad150[0x4];
    /* 0x154 */ struct ba_wobble_s *wobble;
    u8 pad158[0x4];
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
