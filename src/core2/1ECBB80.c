#include "core2/1ECBB80.h"

f32 func_800F2290(f32* arg0, f32* arg1)
{
    return (arg0[0] * arg1[1]) - (arg0[1] * arg1[0]);
}

void func_800F22B4(f32* arg0, f32 arg1)
{
    arg0[0] = ml_sin2f(arg1);
    arg0[1] = ml_cos2f();
}

void func_800F22EC(f32* arg0)
{
    sqrtf((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]));
}

f32 func_800F2320(f32* arg0)
{
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = mlAbsF(arg0[0]);
    temp_f0 = mlAbsF(arg0[1]);
    if (sp1C < temp_f0)
    {
        var_f12 = sp1C;
    }
    else
    {
        var_f12 = temp_f0;
    }
    return (sp1C + temp_f0) - (var_f12 * 0.414213568f);
}

void func_800F2388(f32* arg0, f32* arg1, f32* arg2)
{
    arg0[0] = (f32)(arg1[0] - arg2[0]);
    arg0[1] = (f32)(arg1[1] - arg2[1]);
}

void func_800F23AC(f32* arg0, f32* arg1)
{
    arg0[0] = arg1[1];
    arg0[1] = -arg1[0];
}
