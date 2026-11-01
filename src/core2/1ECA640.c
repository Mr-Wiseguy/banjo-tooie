#include "core2/1ECA640.h"

extern f32 func_80013970(f32);

//ml_clamp_f
f32 ml_clamp_f(f32 val, f32 min, f32 max)
{
    if (val < min)
        return min;

    if (val > max)
        return max;

    return val;
}

//ml_clamp_w
s32 ml_clamp_i(s32 val, s32 min, s32 max)
{
    if (val < min)
        return min;

    if (val > max)
        return max;

    return val;
}

f32 func_800F0DC0(f32 arg0, f32 arg1)
{
    if (arg0 > arg1)
        return arg1;

    if (arg0 < -arg1)
        return -arg1;

    return arg0;
}

//ml_max_f
f32 ml_max_f(f32 arg0, f32 arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

//ml_max_w
s32 ml_max_i(s32 arg0, s32 arg1)
{
    return arg0 > arg1 ? arg0 : arg1;
}

s32 ml_normalizeAngle_i(s32 arg0)
{
    while (arg0 < 0)
    {
        arg0 += 360;
    }
    while (arg0 >= 360)
    {
        arg0 -= 360;
    }
    return arg0;
}

f32 func_800F0E7C(f32 arg0, f32 arg1)
{
    while (arg1 + 180.0f < arg0)
    {
        arg0 -= 360.0f;
    }
    while (arg0 < arg1 - 180.0f)
    {
        arg0 += 360.0f;
    }
    return arg0;
}

void func_800F0EF0(s32 arg0, f32* arg1)
{
    s32 var_v0;
    for (var_v0 = 0; var_v0 < (arg0 * 3) - 3; var_v0++)
    {
        while ((arg1[var_v0 + 3] + 180.0f) <= arg1[var_v0 + 0])
        {
            arg1[var_v0 + 3] += 360.0f;
        }
        while (arg1[var_v0 + 0] <= (arg1[var_v0 + 3] - 180.0f))
        {
            arg1[var_v0 + 3] -= 360.0f;
        }
    }
}

f32 func_800F0F9C(f32 val1, f32 val2)
{
    return ml_remainder_f(val1, val2) / val2;
}

f32 func_800F0FC4(f32 arg0, f32 arg1) {
    return (func_80013970((ml_remainder_f(arg0, arg1) / arg1) * 360.0f) + 1.0f) * 0.5f;
}

f32 func_800F101C(f32 arg0, f32 arg1) {
    return (func_800138D0((ml_remainder_f(arg0, arg1) / arg1) * 360.0f) + 1.0f) * 0.5f;
}

f32 func_800F1074(f32 arg0, f32 arg1)
{
    return func_80013970((ml_remainder_f(arg0, arg1) / arg1) * 360.0f);
}

//ml_map_f
f32 ml_map_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    f32 result;

    if (in_max != in_min)
    {
        if (out_min < out_max)
        {
            result = (((val - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;

            if (result > out_max)
                return out_max;

            if (result < out_min)
                return out_min;
        }
        else
        {
            result = (((val - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;

            if (result < out_max)
                return out_max;

            if (result > out_min)
                return out_min;
        }

        return result;
    }

    return out_max;
}

//ml_mapRange_f
f32 ml_mapRange_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (in_max != in_min)
        return ((val - in_min) / (in_max - in_min)) * (out_max - out_min) + out_min;

    return out_max;
}

//No divide by 0 protection
f32 ml_mapRangeUnsafe_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    return (((val - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;
}

f32 ml_mapNormal_f(f32 value, f32 min, f32 max) {
    return ((max - min) * value) + min;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F122C.s")

//ml_mapFunction_f
f32 func_800F1274(f32 a, f32 b, f32 c, f32 d, f32 e, f32(*func)(f32))
{
    f32 val = func(ml_map_f(a, b, c, 0.f, 1.f));

    return ml_map_f(val, 0, 1, d, e);
}

f32 func_800F12D4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return func_800F1274(arg0, arg1, arg2, arg3, arg4, func_800F1434);
}

void func_800F130C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) 
{
    func_800F1274(arg0, arg1, arg2, arg3, arg4, func_800F14AC);
}

//ml_mapAbsRange_f
f32 func_800F1344(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (val < 0)
        return ml_map_f(val, -in_min, -in_max, -out_min, -out_max);
    else
        return ml_map_f(val, in_min, in_max, out_min, out_max);
}

//ml_remainder_f
f32 ml_remainder_f(f32 arg0, f32 arg1)
{
    f32 val = arg0 / arg1;

    return (val - (s32)val) * arg1;
}

//ml_min_f
f32 ml_min_f(f32 arg0, f32 arg1)
{
    return arg1 > arg0 ? arg0 : arg1;
}

//ml_min_w
s32 ml_min_i(s32 arg0, s32 arg1)
{
    return arg1 > arg0 ? arg0 : arg1;
}

f32 func_800F1434(f32 arg0) {
    return (func_8001395C((arg0 * 3.141592741f) + -1.570796371f) + 1.0f) * 0.5f;
}

void func_800F1480(f32 arg0) {
    func_80013970(arg0 * 90.0f);
}

f32 func_800F14AC(f32 val)
{
    return func_800F1434(func_800F1434(val));
}

f32 func_800F14D4(f32 arg0, f32 arg1)
{
    return arg0 <= arg1 ? arg0 : arg1;
}

f32 func_800F14FC(f32 arg0, f32 arg1, f32 arg2)
{
    f32 temp_f2;

    if (arg2 < arg0) {
        return 0.0f;
    }
    if (arg1 <= arg2) {
        return 1.0f;
    }
    temp_f2 = (arg2 - arg0) / (arg1 - arg0);
    return temp_f2 * temp_f2 * (3.0f - (2.0f * temp_f2));
}

//ml_timer_update
int ml_timer_update(f32* timer, f32 delta) {
    if (*timer > 0) 
    {
        *timer -= delta;

        if (*timer <= 0) 
        {
            *timer = 0;
            return TRUE;
        }
    }

    return FALSE;
}

f32 func_800F15C4(f32 arg0, s32 arg1)
{
    f32 var_f2;

    var_f2 = 1.0f;

    while (arg1 != 0)
    {

        if (arg1 & 1)
        {
            var_f2 *= arg0;
        }
        arg1 = arg1 >> 1;
        arg0 *= arg0;
    }

    return var_f2;
}

f32 func_800F15F8(f32 arg0, f32 arg1, f32 arg2) {
    if (arg0 < arg1) {
        return ml_min_f(arg0 + arg2, arg1);
    }
    if (arg1 < arg0) {
        return ml_max_f(arg0 - arg2, arg1);
    }
    return arg0;
}

s32 func_800F1660(f32 arg0, f32 arg1)
{
    if (arg0 < 0.0f)
    {
        arg0 = -arg0;
    }
    if (arg1 < 0.0f)
    {
        arg1 = -arg1;
    }
    return arg1 < arg0;
}

void func_800F16AC(f32* arg0, f32* arg1, f32* arg2, f32 arg3)
{
    s32 var_s1;
    for (var_s1 = 0; var_s1 < 3; var_s1++)
    {
        arg0[var_s1] = arg1[var_s1] - func_800F1DCC(arg1[var_s1], arg2[var_s1]) * arg3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1738.s")
