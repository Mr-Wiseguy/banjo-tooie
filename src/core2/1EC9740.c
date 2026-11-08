#include "core2/1EC9740.h"

extern f32 D_80125EB4;

void func_800EFE50(f32* arg0, f32* arg1, f32* arg2, f32 arg3)
{
    s32 i;

	//Loop through all axis
    for (i = 0; i < 3; i++)
    {
        arg0[i] = arg1[i] + ((arg2[i] - arg1[i]) * arg3);
    }
}

int func_800EFED0(f32* arg0, f32* arg1, f32* arg2)
{
    return arg0[0] < arg2[0]
        && arg2[0] < arg1[0]
        && arg0[1] < arg2[1]
        && arg2[1] < arg1[1]
        && arg0[2] < arg2[2]
        && arg2[2] < arg1[2];
}

int position_isWithinRangeOf(f32* arg0, f32 arg1, f32* arg2)
{
    f32 diff[3];
    //Get Diff
    ml_getdiff_vec3f(diff, arg2, arg0);
    //Compare squared length
    return ml_vec3f_magnitude_sq(diff) <= (arg1 * arg1);
}

int func_800F0008(f32* arg0, f32 arg1, f32* arg2, f32 arg3)
{
    f32 diff[3];
    f32 temp_f2;

    ml_getdiff_vec3f(diff, arg0, arg2);
    temp_f2 = arg1 + arg3;
    return ml_vec3f_magnitude_sq(diff) <= (temp_f2 * temp_f2);
}

int func_800F0064(f32* arg0, f32 arg1, f32* arg2)
{
    s32 var_v0;

    var_v0 = 0;
    return func_800EFC7C(arg0, arg2) < (arg1 * arg1);
}

int func_800F00A4(f32* arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4)
{
    if ((arg4[1] < (arg0[1] + arg3)) || ((arg0[1] + arg2) < arg4[1]))
    {
        return 0;
    }
    return func_800EFC7C(arg0, arg4) < (arg1 * arg1);
}

//ml_vec3w_within_horizontal_distance
int func_800F0130(s32* arg0, s32 arg1, s32* arg2)
{
    s32 diff[3];

    diff[0] = arg2[0] - arg0[0];
    diff[2] = arg2[2] - arg0[2];
    return ((diff[0] * diff[0]) + (diff[2] * diff[2])) < (arg1 * arg1);
}

void func_800F018C(f32* arg0, f32* arg1, f32* arg2, f32* arg3)
{
    f32 sp34[3];
    f32 sp28[3];
    f32 temp_f0;
    f32 temp_f2;

    ml_getdiff_vec3f(sp34, arg2, arg1);
    temp_f0 = ml_vec3f_magnitude_sq(sp34);
    if (temp_f0 < 0.009999999776f)
    {
        ml_vec3f_copy(arg0, arg1);
        return;
    }
    temp_f2 = 1.0f / sqrtf(temp_f0);
    sp34[0] *= temp_f2;
    sp34[1] *= temp_f2;
    sp34[2] *= temp_f2;
    ml_getdiff_vec3f(sp28, arg3, arg1);
    ml_getScaledVec3f(arg0, sp34, ml_vec3f_dot_product(sp28, sp34));
    ml_vec3f_add(arg0, arg1);
}

void func_800F0274(f32* dst, f32* arg1, f32* arg2, f32* arg3)
{
    f32 diff[3];
    f32 diff2[3];
    f32 length;
    f32 dotProduct;

    ml_getdiff_vec3f(diff, arg2, arg1);
    length = ml_vec3f_magnitude_sq(diff);
    if (length < 0.009999999776f)
    {
        //Copy arg1 into dst
        ml_vec3f_copy(dst, arg1);
    }
    else
    {
        length = sqrtf(length);
        diff[0] *= (1.0f / length);
        diff[1] *= (1.0f / length);
        diff[2] *= (1.0f / length);
        ml_getdiff_vec3f(diff2, arg3, arg1);
        dotProduct = ml_vec3f_dot_product(diff2, diff);
        if (dotProduct <= 0.0f)
        {
            //Copy arg1 into dst
            ml_vec3f_copy(dst, arg1);
            return;
        }
        if (length <= dotProduct)
        {
            //Copy arg2 into dst
            ml_vec3f_copy(dst, arg2);
            return;
        }
        //Store Diff*DotProduct in dst
        ml_getScaledVec3f(dst, diff, dotProduct);
        //Add arg1 to dst
        ml_vec3f_add(dst, arg1);
    }
}

void func_800F03AC(f32* arg0, f32* arg1, f32* arg2, f32* arg3)
{
    f32 sp1C[3];

    ml_getdiff_vec3f(sp1C, arg3, arg1);
    ml_getScaledVec3f(sp1C, arg2, ml_vec3f_dot_product(arg2, sp1C));
    ml_getdiff_vec3f(arg0, arg3, sp1C);
}

void func_800F0410(f32* arg0, f32* arg1, f32* arg2)
{
    f32 sp54;
    f32 sp50;
    f32 temp_f0;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_800F0274(sp40, arg1, &arg1[3], arg2);
    func_800F0274(sp34, &arg1[3], &arg1[6], arg2);
    func_800F0274(sp28, &arg1[6], arg1, arg2);
    sp54 = ml_vec3f_distance_sq(sp40, arg2);
    sp50 = ml_vec3f_distance_sq(sp34, arg2);
    temp_f0 = ml_vec3f_distance_sq(sp28, arg2);
    if (sp54 < sp50)
    {
        if (temp_f0 < sp54)
        {
            ml_vec3f_copy(arg0, sp28);
        }
        else
        {
            ml_vec3f_copy(arg0, sp40);
        }
    }
    else if (temp_f0 < sp50)
    {
        ml_vec3f_copy(arg0, sp28);
    }
    else
    {
        ml_vec3f_copy(arg0, sp34);
    }
}

void func_800F0524(f32* arg0, f32* arg1, f32* arg2)
{
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    ml_getdiff_vec3f(sp3C, &arg1[3], arg1);
    ml_getdiff_vec3f(sp30, &arg1[6], arg1);
    ml_vec3f_cross_product(sp24, sp3C, sp30);
    ml_vec3f_normalizeMagnitude(sp24);
    func_800F03AC(arg0, arg1, sp24, arg2);
}

void func_800F059C(f32* arg0, f32* arg1, f32* arg2)
{
    f32 sp1C[3];

    ml_getScaledVec3f(arg0, arg1, -1.0f);
    ml_getScaledVec3f(sp1C, arg2, 2.0f * ml_vec3f_dot_product(arg0, arg2));
    ml_getdiff_vec3f(arg0, sp1C, arg0);
}

s32 func_800F05F8(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32* arg4)
{
    Vec3f sp3C;
    f32 temp_f2; // sp38
    f32 temp_f14; // sp34
    f32 temp_f0;
    f32 var_f18;

    sp3C.f[0] = arg0->f[0] - arg2->f[0];
    sp3C.f[2] = arg0->f[2] - arg2->f[2];
    temp_f2 = SQ(arg1->f[0]) + SQ(arg1->f[2]);
    if (temp_f2 == 0.0f)
    {
        return 0;
    }
    temp_f14 = 2.0f * (arg1->f[0] * sp3C.f[0] + arg1->f[2] * sp3C.f[2]);
    var_f18 = SQ(sp3C.f[0]) + SQ(sp3C.f[2]) - SQ(arg3);

    if (SQ(temp_f14) < 4.0f * temp_f2 * (var_f18))
    {
        return 0;
    }
    temp_f0 = sqrtf(SQ(temp_f14) - 4.0f * temp_f2 * (var_f18));
    temp_f2 = 0.5f / temp_f2;
    arg4[0] = (temp_f0 - temp_f14) * temp_f2;
    if (temp_f0 != 0.0f)
    {
        arg4[1] = -(temp_f14 + temp_f0) * temp_f2;
        return 2;
    }
    else
        return 1;
}

s32 func_800F0734(f32* arg0, f32* arg1, f32* arg2, f32 arg3, f32 arg4, f32* arg5, f32* arg6) {
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    s32 pad;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 temp_f16;
    f32 sp38;
    f32 temp_f2;
    f32 sp30;
    f32 sp2C;
    f32 temp_fv1;

    ml_getdiff_vec3f(sp74, arg0, arg2);
    ml_getdiff_vec3f(sp68, arg1, arg2);
    ml_getdiff_vec3f(sp5C, sp68, sp74);
    sp48 = (sp74[0] * sp5C[0]) + (sp74[2] * sp5C[2]);
    sp44 = (sp5C[0] * sp5C[0]) + (sp5C[2] * sp5C[2]);
    if (sp44 != 0.0f)
    {
        if (-sp48 / sp44 < 0.0f)
        {
            ml_vec3f_copy(sp50, sp74);
        }
        else if (-sp48 / sp44 < 1.0f)
        {
            ml_getScaledVec3f(sp50, sp5C, -sp48 / sp44);
            ml_vec3f_add(sp50, sp74);
        }
        else
        {
            ml_vec3f_copy(sp50, sp68);
        }
        temp_f2 = arg3 * arg3;
        sp40 = (sp50[0] * sp50[0]) + (sp50[2] * sp50[2]);
        if (temp_f2 < sp40)
        {
            return 0;
        }
        temp_f16 = -sp48 / sp44;
        sp38 = sqrtf(sp44);
        temp_f2 = sqrtf(temp_f2 - sp40) / sp38;

        sp30 = temp_f2 < temp_f16 ? temp_f16 - temp_f2 : 0.0f;
        sp2C = temp_f16 + temp_f2 < 1.0f ? temp_f16 + temp_f2 : 1.f;
        func_800EFE50(arg5, arg0, arg1, sp30);
        func_800EFE50(arg6, arg0, arg1, sp2C);
        temp_fv1 = arg2[1] + arg4;
        if ((arg2[1] <= arg5[1]) && (arg5[1] < temp_fv1))
        {
            return 1;
        }
        if ((arg2[1] <= arg6[1]) && (arg6[1] < temp_fv1))
        {
            return 1;
        }
        return 0;
    }
    if (func_800F0064(arg0, arg3, arg2) != 0)
    {
        if ((arg0[1] < arg2[1]) && (arg2[1] < arg1[1]))
        {
            ml_vec3f_copy(arg5, arg2);
            ml_vec3f_assign_value(arg6, arg2[0], arg2[1] + arg4, arg2[2]);
            return 1;
        }

        if ((arg2[1] + arg4 < arg0[1]) && (arg1[1] < arg2[1] + arg4))
        {
            ml_vec3f_assign_value(arg5, arg2[0], arg2[1] + arg4, arg2[2]);
            ml_vec3f_copy(arg6, arg2);
            return 1;
        }
        if (1) {}
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0AA4.s")

s32 func_800F0BD0(f32* arg0, f32* arg1, f32 arg2, f32 arg3)
{
    f32 temp_f0;

    if (ml_vec3f_is_zero(arg0) != 0)
    {
        return 0;
    }
    temp_f0 = ml_vec3f_dot_product(arg1, arg0);
    if (arg2 < temp_f0)
    {
        return 0;
    }
    temp_f0 /= ml_vec3f_magnitude(arg0);
    if (temp_f0 < arg3)
    {
        return 0;
    }
    return 1;
}

f32 func_800F0C68(s32 arg0, f32* arg1, f32 arg2, f32 arg3)
{
    ml_vec3f_normalizeMagnitude(arg1);
    return arg2 / sqrtf((arg2 * arg2) + (arg3 * arg3));
}

s32 func_800F0CB4(f32* arg0, f32* arg1, f32* arg2, f32* arg3)
{
    f32 temp_f0;

    temp_f0 = ml_vec3f_dot_product(arg1, arg3);
    if (temp_f0 == 0.0f)
    {
        return 0;
    }
    ml_vec3f_translate_scale(arg0, arg1, (ml_vec3f_dot_product(arg3, arg2) - ml_vec3f_dot_product(arg0, arg3)) / temp_f0);
    return 1;
}
