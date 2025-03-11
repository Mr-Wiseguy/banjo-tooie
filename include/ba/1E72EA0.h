#ifndef __BA_1E72EA0_H__
#define __BA_1E72EA0_H__

#include "ba/playerstate.h"

typedef struct ba_unknown_C0_s {
    f32 unk0;
    f32 unk4;
    u8 pad8[0xC];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 pad24[0xCC];
} BaUnknownC0;

f32 func_80099A34(PlayerState *self);
void func_80099B94(PlayerState *);
f32 func_80099A40(PlayerState *self);
void func_8009AB78(PlayerState *);

#endif // __BA_1E72EA0_H__
