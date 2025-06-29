#ifndef __CORE2_1E965B0_H__
#define __CORE2_1E965B0_H__

#include <ultra64.h>

#include "buttons.h"

typedef struct {
    // Counts up every frame.
    u32 counter;
    u8 unk4;
    u8 unk5;
    u8 controller_index;
    u8 pad7;
    u8 unk8[BUTTON_COUNT];
    u8 unk16[BUTTON_COUNT];
} unkfunc_800BCE84;

u8 func_800BCCF4(unkfunc_800BCE84* arg0);
s32 func_800BCCFC(unkfunc_800BCE84* arg0, ButtonId button, s32 arg2);
u32 func_800BCD78(unkfunc_800BCE84* arg0, ButtonId button, s32 arg2);
s32 func_800BCE84(unkfunc_800BCE84* arg0, ButtonId button);
s32 func_800BCEC0(unkfunc_800BCE84* arg0, ButtonId button);
s32 func_800BCF28(unkfunc_800BCE84* arg0, ButtonId button);
void func_800BCF90(unkfunc_800BCE84* arg0, f32* joystick_values_out);
int func_800BCFC4(unkfunc_800BCE84* arg0, ButtonId button);
int func_800BD030(unkfunc_800BCE84* arg0, ButtonId button);
void func_800BD09C(unkfunc_800BCE84* arg0);
unkfunc_800BCE84* func_800BD0BC(unkfunc_800BCE84* arg0);
unkfunc_800BCE84* func_800BD0DC(s32 arg0);
void func_800BD138(unkfunc_800BCE84* arg0);
void func_800BD268(unkfunc_800BCE84* arg0, s32 arg1);
void func_800BD28C(unkfunc_800BCE84* arg0, s32 arg1);
void func_800BD2D0(unkfunc_800BCE84* arg0);

#endif // __CORE2_1E965B0_H__
