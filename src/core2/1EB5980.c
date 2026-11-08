#include "core2/1EB5980.h"

extern s32 D_8011B9A0;
extern s32 D_8011B9A4;
extern s32 D_8012C7F0;
extern s32 D_8012C7F4;
extern s32 D_8012C7F8;
extern s32 D_8012C7FC;

s32 rand_i(void)
{
    return D_8012C7F0 = (D_8012C7F0 * 0x19660D) + 0x3C6EF35F;
}

//Produces a random float between 1 and 0
f32 rand_f(void)
{
    s32 sp4;
    f32 returnV0;
    D_8012C7F0 = (D_8012C7F0 * 0x19660D) + 0x3C6EF35F;
    sp4 = ((D_8011B9A4 & D_8012C7F0) | D_8011B9A0);
    returnV0 = *(f32*)&sp4 - 1.0f;
    return returnV0;
}
//Random int within bounds
s32 rand_iBounded(s32 lowerBound, s32 upperBound) {
    return (s32)((rand_f() * (f32)(upperBound - lowerBound)) + (f32)lowerBound);
}

//Random float within bounds
f32 rand_fBounded(f32 lowerBound, f32 upperBound) {
    return (rand_f() * (upperBound - lowerBound)) + lowerBound;
}

f32 rand2_f(void)
{
    s32 sp4;
    f32 returnV0;
    D_8012C7F4 = (D_8012C7F4 * 0x19660D) + 0x3C6EF35F;
    sp4 = ((D_8011B9A4 & D_8012C7F4) | D_8011B9A0);
    returnV0 = *(f32*)&sp4 - 1.0f;
    return returnV0;
}

s32 rand2_iBounded(s32 lowerBound, s32 upperBound)
{
    return (s32)((rand2_f() * (f32)(upperBound - lowerBound)) + (f32)lowerBound);
}

f32 rand2_fBounded(f32 lowerBound, f32 upperBound)
{
    return (rand2_f() * (upperBound - lowerBound)) + lowerBound;
}

int rand_percentChance(f32 arg0)
{
    return rand_f() < arg0 ? 1 : 0;
}

int rand2_percentChance(f32 arg0)
{

    return rand2_f() < arg0 ? 1 : 0;

}

void rand_setInitSeed(void)
{
    D_8012C7F0 = 0xEAA0C7;
}

void rand_setSeed(s32 arg0)
{
    D_8012C7F0 = arg0;
}

void rand_saveCurrentSeed(void) {
    D_8012C7F8 = D_8012C7F0;
    D_8012C7FC = D_8012C7F4;
}

void rand_restoreCurrentSeed(void) {
    D_8012C7F0 = D_8012C7F8;
    D_8012C7F4 = D_8012C7FC;
}