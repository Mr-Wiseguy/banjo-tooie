#ifndef __CORE2_1E6A190_H__
#define __CORE2_1E6A190_H__

#include "ba/playerstate.h"
#include "core2/1EB2840.h"

typedef struct ba_unknown_20_s {
    u8 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
} BaUnknown20;

s32 func_800908A0(void);
f32* func_800908A8(s32);
void func_800908F0(PlayerState*, s32);
void func_80090938(PlayerState*);
void func_8009097C(PlayerState*, s32 );
void func_800909CC(PlayerState* );
void func_800909EC(PlayerState* );
void func_80090A0C(PlayerState* );
void func_80090A2C(PlayerState* );
void func_80090A4C(PlayerState*);

#endif // __CORE2_1E6A190_H__
