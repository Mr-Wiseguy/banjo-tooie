#ifndef __CORE2_1E72EA0_H__
#define __CORE2_1E72EA0_H__

#include "common.h"

#include <ultra64.h>

#include "ba/playerstate.h"

typedef struct ba_unknown_C0_s {
    f32 unk0;
    f32 unk4;
    u8 pad8[0xC];
    Unk80132ED0* unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 pad24[0xCC];
} BaUnknownC0;

void func_800995B8(PlayerState *, s32);
void func_80099970(PlayerState*);
f32 func_80099A34(PlayerState *);
f32 func_80099A40(PlayerState *);
Unk80132ED0* func_80099A4C(PlayerState*);
s32 func_80099A58(PlayerState *);
void func_80099A7C(PlayerState *, f32[3]);
void func_80099AA8(PlayerState*);
void func_80099B94(PlayerState *);
void func_8009AB78(PlayerState *);
void func_8009AC6C(PlayerState*);
void func_8009ACF4(PlayerState*, f32);
void func_8009AD04(PlayerState*, f32);
void func_8009AD14(PlayerState*, Unk80132ED0*);
void func_8009AD20(PlayerState*, s32);
void func_8009AD2C(PlayerState*, s32);
void func_8009AD38(PlayerState*, s32);
s32 func_8009AD44(PlayerState*, f32[3]);

#endif // __CORE2_1E72EA0_H__
