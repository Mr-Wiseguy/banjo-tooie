#include "fx/twinkle.h"

extern s32 D_808000F0_fxtwinkle;
extern s32 D_8080010C_fxtwinkle;

void fxtwinkle_entrypoint_0(s32 arg0)
{
    fxtwinkle_entrypoint_1(arg0, ASSET_9E2_GOLD_SPARKLE);
}

void fxtwinkle_entrypoint_1(f32* arg0, AssetId arg1)
{
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    func_800BABB8(temp_v0, arg0, NULL, 1.0f, &D_808000F0_fxtwinkle);
    func_800BA3FC(temp_v0, (s16)arg1);
    func_800BA22C(temp_v0, 1);
}

void fxtwinkle_entrypoint_2(f32* arg0, AssetId arg1)
{
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    func_800BABB8(temp_v0, arg0, NULL, 1.0f, &D_8080010C_fxtwinkle);
    func_800BA3FC(temp_v0, (s16)arg1);
    func_800BA22C(temp_v0, 1);
}