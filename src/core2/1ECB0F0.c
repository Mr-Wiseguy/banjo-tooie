#include "core2/1ECB0F0.h"

f32 func_800F1800(f32 a0)
{
    return mlAbsF(func_80013AAC(a0));
}

f32 func_800F1828(f32* arg0, f32* arg1) {
    f32 temp_f0;
    f32 sp18;
    f32 temp_f2;

    temp_f0 = arg1[0] - arg0[0];
    sp18 = arg1[1] - arg0[1];
    temp_f2 = arg1[2] - arg0[2];
    return func_80013B7C(sp18, sqrtf(SQ(temp_f0) + SQ(temp_f2)));
}

s32 func_800F1884(f32* arg0, f32* arg1)
{
    f32 temp_f0_2;

    temp_f0_2 = sqrtf(SQ(arg0[0]) + SQ(arg0[2]));
    if (temp_f0_2 == 0.0f)
    {
        arg1[0] = 0.0f;
        return 0;
    }
    arg1[0] = func_80013B7C(arg0[1], temp_f0_2);
    return 1;
}

void func_800F18FC(f32* arg0, f32* arg1, f32* arg2) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = arg1[0] - arg0[0];
    sp20 = arg1[1] - arg0[1];
    sp1C = arg1[2] - arg0[2];
    sp18 = sqrtf(SQ(sp24) + SQ(sp1C));
    arg2[1] = func_80013B70(sp24, sp1C, sp18);
    arg2[0] = func_80013B7C(sp20, sp18);
}

s32 func_800F1988(f32* arg0, f32* arg1, f32* arg2)
{
    f32 sp1C;

    arg1[0] = 0.0f;
    arg2[0] = 0.0f;
    sp1C = sqrtf(SQ(arg0[2]) + SQ(arg0[0]));
    if (sp1C < 0.01f)
    {
        return 0;
    }
    arg2[0] = func_800F1800(arg0[0] / sp1C);
    if (arg0[2] < 0)
    {
        arg2[0] = 180.0f - arg2[0];
    }
    if (arg0[0] < 0.0f)
    {
        arg2[0] = 360.0f - arg2[0];
    }
    arg1[0] = func_800F1800(sp1C);
    return 1;
}

void func_800F1A88(f32* arg0, f32* arg1)
{
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0[2];
    temp_f2 = arg0[0];
    sp1C = sqrtf((SQ(temp_f0)) + (SQ(temp_f2)));
    arg1[1] = func_80013B70(arg0[0], arg0[2], sp1C);
    arg1[0] = func_80013B7C(arg0[1], sp1C);
}

void func_800F1AFC(f32* arg0, f32* arg1) {
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    temp_f0 = arg0[2];
    temp_f2 = arg0[0];
    temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    sp1C = temp_f0_2;
    arg1[1] = func_80013B70(arg0[0], arg0[2], temp_f0_2);
    arg1[0] = func_80013B7C(arg0[1], sp1C);
    arg1[2] = 0.0f;
}

s32 func_800F1B78(f32* arg0, f32* arg1, f32 arg2, f32 arg3) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    s32 sp2C;

    ml_vec3f_clear(arg0);
    sp2C = func_800F1988(arg1, &sp3C, &sp38);
    sp3C *= arg3;
    if (sp2C != 0)
    {

        sp30 = func_800F1DCC(arg2, sp38);
        sp34 = mlAbsF(sp30);
        arg0[0] = ml_map_f(sp34, 0.0f, 180.0f, sp3C, -sp3C);
        if (sp34 < 90.0f)
        {
            arg0[2] = ml_map_f(sp34, 0.0f, 90.0f, 0.0f, sp3C);
        }
        else
        {
            arg0[2] = ml_map_f(sp34, 90.0f, 180.0f, sp3C, 0.0f);
        }
        if (sp30 < 0.0f)
        {
            arg0[2] = -arg0[2];
        }
    }
    return sp2C;
}

f32 func_800F1C98(f32* arg0, f32* arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp1C[3];

    sp2C = ml_vec3f_magnitude(arg0);
    sp28 = ml_vec3f_magnitude(arg1);
    ml_vec3f_cross_product(sp1C, arg0, arg1);
    return ml_vec3f_magnitude(sp1C) / (sp2C * sp28);
}

f32 func_800F1CF0(f32* arg0, f32* arg1) {
    f32 sp24;
    f32 sp20;
    f32 temp_f0_2;
    f32 sp18;

    sp18 = sqrtf(SQ(arg0[2]) + SQ(arg0[0]));
    sp24 = sqrtf(SQ(arg1[0]) + SQ(arg1[2])) * sp18;
    if (sp24 > 0.000001f)
    {
        sp20 = (arg0[2] * arg1[0]) - (arg0[0] * arg1[2]);
        temp_f0_2 = mlAbsF(sp20);
        if (sp24 < temp_f0_2)
        {
            sp24 = temp_f0_2;
        }
        return sp20 / sp24;
    }
    return 0.0f;
}

f32 func_800F1DCC(f32 arg0, f32 arg1)
{
    return ml_absNormalizeAngle_f(arg0 - arg1);
}

f32 func_800F1DF4(f32* arg0, f32* arg1)
{
    return func_80013B7C(arg1[0] - arg0[0], arg1[2] - arg0[2]);
}

void func_800F1E28(s16* arg0, s16* arg1)
{
    func_80013B7C((arg1[0] - arg0[0]), (arg1[2] - arg0[2]));
}

s32 func_800F1E6C(f32* arg0, f32* arg1, f32* target_yaw)
{
    f32 sp1C[3];

    ml_getdiff_vec3f(sp1C, arg1, arg0);
    return func_800F1EA4(sp1C, target_yaw);
}

s32 func_800F1EA4(f32* arg0, f32* arg1)
{
    if ((arg0[0] != 0.0f) || ((arg0[2] != 0.0f)))
    {
        arg1[0] = func_80013B7C(arg0[0], arg0[2]);
        return 1;
    }
    else
    {
        arg1[0] = 0.0f;
        return 0;
    }
}

f32 func_800F1F0C(f32* arg0, f32* arg1, f32 arg2)
{
    return func_800F1DCC(func_800F1DF4(arg0, arg1), arg2);
}

f32 func_800F1F38(f32 arg0, f32 arg1, f32 arg2)
{
    f32 var_f0;
    f32 var_f2;
    f32 var_f12;

    if (arg1 == arg0)
    {
        return arg1;
    }
    var_f0 = func_800F1DCC(arg1, arg0);
    if (var_f0 > 0.0f)
    {
        var_f2 = MIN(var_f0, arg2);
        var_f0 = var_f2;
    }
    else
    {
        var_f12 = MAX(var_f0, -arg2);
        var_f0 = var_f12;
    }
    return ml_normalizeAngle_f(arg0 + var_f0);
}

f32 func_800F1FF0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 sp1C;
    f32 temp_f0;

    sp1C = func_800F1DCC(arg1, arg0) * arg2;
    temp_f0 = mlAbsF(sp1C);
    if (temp_f0 < arg3)
    {
        return arg1;
    }
    if (arg4 < temp_f0)
    {
        if (sp1C < 0.0f)
        {
            sp1C = -arg4;
        }
        else
        {
            sp1C = arg4;
        }
    }
    return ml_normalizeAngle_f(arg0 + sp1C);
}

f32 func_800F2094(f32 arg0, f32 arg1)
{
    return mlAbsF(func_800F1DCC(arg0, arg1));
}

s32 func_800F20BC(f32 arg0, f32 arg1, f32 arg2)
{
    return func_800F2094(arg0, arg1) < arg2;
}
