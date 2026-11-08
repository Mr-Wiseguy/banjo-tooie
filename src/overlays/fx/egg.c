#include "fx/egg.h"

void* func_80800000_fxegg(s32);
s32 func_8080009C_fxegg(s32, s32, f32*, f32);
void func_808000F8_fxegg(s32, f32*, AssetId, f32);
void func_808001CC_fxegg(s32, f32*, f32);
void func_80800410_fxegg(s32, f32*, f32*, AssetId, f32);

extern s32 D_80800574_fxegg;
extern s32 D_808005B0_fxegg;
extern s32 D_808005D8_fxegg;
extern s32 D_80800614_fxegg;
extern s32 D_80800630_fxegg;
extern s32 D_80800658_fxegg;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/func_80800000_fxegg.s")

void fxegg_entrypoint_0(s32 arg0, f32* arg1, f32 arg2)
{
    s32 pad;
    s16* temp_v0;
    temp_v0 = func_80800000_fxegg(arg0);
    temp_v0 = func_8080009C_fxegg(temp_v0[1], temp_v0[2], arg1, arg2);
    func_800BA75C(temp_v0, arg1);
    func_800BA22C(temp_v0, 5);
}

s32 func_8080009C_fxegg(s32 arg0, s32 arg1, f32* arg2, f32 arg3)
{
    s32 temp_v0;
    temp_v0 = func_800B5BE4(arg1);
    func_800BA670(temp_v0, arg0);
    return func_800BABB8(temp_v0, arg2, arg2, arg3, &D_80800574_fxegg);
}

void func_808000F8_fxegg(s32 arg0, f32* arg1, AssetId arg2, f32 arg3)
{
    func_800BA3FC(arg0, arg2);
    func_800BABB8(arg0, arg1, NULL, arg3, &D_808005B0_fxegg);
}

s32 fxegg_entrypoint_1(f32* arg0, f32 arg1)
{
    s32 temp_v0;
    temp_v0 = func_800B5BE4(0xC);
    func_808000F8_fxegg(temp_v0, arg0, ASSET_9E5_LIGHT_BLUE_SPARKLE, arg1);
    return temp_v0;
}

s32 fxegg_entrypoint_2(f32* arg0, f32 arg1)
{
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0xB);
    func_808000F8_fxegg(temp_v0, arg0, ASSET_9E0_BLUE_SPARKLE, arg1);
    return temp_v0;
}

void func_808001CC_fxegg(s32 arg0, f32* arg1, f32 arg2)
{
    func_800BABB8(arg0, arg1, NULL, arg2, &D_808005D8_fxegg);
}

s32 fxegg_entrypoint_3(f32* arg0, f32 arg1)
{
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0x13);
    func_808001CC_fxegg(temp_v0, arg0, arg1);
    return temp_v0;
}

s32 fxegg_entrypoint_4(f32* arg0, f32 arg1)
{
    s32 temp_v0;
    temp_v0 = func_800B5BE4(0x21);
    func_808000F8_fxegg(temp_v0, arg0, ASSET_9E4_RED_SPARKLE, arg1);
    return temp_v0;
}

s32 fxegg_entrypoint_5(f32* arg0, f32* arg1, f32 arg2)
{
    s32 sp34;
    f32 sp28[3];

    sp34 = _fxdlsmoke_entrypoint_0(arg0);
    if (arg1 != NULL)
    {
        ml_getScaledVec3f(sp28, arg1, 0.15f);
        func_800BA930(sp34, sp28[0], (sp28[1] + 60.0f),sp28[2], sp28[0], (sp28[1] + 100.0f), sp28[2]);
    }
    func_800BABB8(sp34, arg0, arg0, arg2, &D_80800614_fxegg);
    return sp34;
}

s32 fxegg_entrypoint_6(f32* arg0, f32 arg1, f32* arg2)
{
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0x17);
    func_800BA930(temp_v0, arg2[0], arg2[1], arg2[2], arg2[0], arg2[1], arg2[2]);
    func_800BA3FC(temp_v0, ASSET_9E2_GOLD_SPARKLE);
    func_800BABB8(temp_v0, arg0, NULL, arg1, &D_80800630_fxegg);
    return temp_v0;
}

void func_80800410_fxegg(s32 arg0, f32* arg1, f32* arg2, AssetId arg3, f32 arg4)
{
    func_800BA930(arg0, arg2[0], arg2[1], arg2[2], arg2[0], arg2[1], arg2[2]);
    func_800BA3FC(arg0, arg3);
    func_800BABB8(arg0, arg1, NULL, arg4, &D_80800658_fxegg);
}

void fxegg_entrypoint_7(f32* arg0, f32* arg1, f32 arg2)
{
    func_80800410_fxegg(func_800B5BE4(0xB), arg0, arg1, ASSET_9E0_BLUE_SPARKLE, arg2);
}

void fxegg_entrypoint_8(f32* arg0, f32* arg1, f32 arg2)
{
    func_80800410_fxegg(func_800B5BE4(0xC), arg0, arg1, ASSET_9E5_LIGHT_BLUE_SPARKLE, arg2);
}
