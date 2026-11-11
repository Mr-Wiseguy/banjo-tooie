#ifndef __CORE2_1EB5980_H__
#define __CORE2_1EB5980_H__

#include "common.h"

s32 rand_i(void);
f32 rand_f(void);
s32 rand_iBounded(s32, s32);
//Randomize Float
f32 rand_fBounded(f32, f32);
f32 rand2_f(void);
s32 rand2_iBounded(s32, s32);
f32 rand2_fBounded(f32, f32);
int rand_percentChance(f32);
int rand2_percentChance(f32);
void rand_setInitSeed();
void rand_setSeed(s32);
void rand_saveCurrentSeed();
void rand_restoreCurrentSeed();
#endif // __CORE2_1EB5980_H__
