#ifndef __BA_BUZZ_H__
#define __BA_BUZZ_H__

#include "ba/playerstate.h"

typedef struct ba_buzz_s {
    u8 unk0;
    f32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    f32 unk14;
} BaBuzz;

s32 babuzz_entrypoint_0(void);
f32 func_80800008_babuzz(f32);
f32 func_80800074_babuzz(f32, f32, f32);
void _babuzz_entrypoint_1(PlayerState*);
void _babuzz_entrypoint_2(PlayerState*);
void _babuzz_entrypoint_3(PlayerState*);
void _babuzz_entrypoint_4(PlayerState*, f32);
void babuzz_entrypoint_5(PlayerState*, s32);

#endif // __BA_BUZZ_H__
