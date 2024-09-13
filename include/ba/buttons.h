#ifndef __BUTTONS_H__
#define __BUTTONS_H__

// These button IDs are an enum, rather than a bitmask like the libultra ones.
typedef enum button_e {
    BUTTON_START = 0x0,
    BUTTON_Z = 0x1,
    BUTTON_L = 0x2,
    BUTTON_R = 0x3,
    BUTTON_D_UP = 0x4, 
    BUTTON_D_DOWN = 0x5, 
    BUTTON_D_LEFT = 0x6,
    BUTTON_D_RIGHT = 0x7,
    BUTTON_A = 0x8,
    BUTTON_B = 0x9,
    BUTTON_C_LEFT = 0xA,
    BUTTON_C_DOWN = 0xB,
    BUTTON_C_UP = 0xC,
    BUTTON_C_RIGHT = 0xD
} ButtonId;

s32 button_held(PlayerState*, ButtonId);

#endif
