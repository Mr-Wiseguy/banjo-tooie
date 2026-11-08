#include "core2/1EC8070.h"

// TODO rename operations based on whether they output to a new vector or output to an input vector.
// add vs sum/subtract vs difference? What to do for scalar multiplication? apply_scale vs scale?

// ml_vec3f_sum
void ml_vec3f_sum(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// ml_vec3f_scaled_sum
void ml_vec3f_scaled_sum(f32 dst[3], f32 a[3], f32 b[3], f32 scale) {
    dst[0] = a[0] + b[0] * scale;
    dst[1] = a[1] + b[1] * scale;
    dst[2] = a[2] + b[2] * scale;
}

// ml_vec3f_copy
void ml_vec3f_copy(f32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_copy
void ml_vec3s_copy(s16 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_copy
void ml_vec3i_copy(s32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_to_vec3f
void ml_vec3i_to_vec3f(f32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3f
void ml_vec3s_to_vec3f(f32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3i
void ml_vec3s_to_vec3i(s32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec2f_to_vec3f
void ml_vec2f_to_vec3f(f32 dst[3], f32 src[2]) {
    dst[0] = src[0];
    dst[1] = 0;
    dst[2] = src[1];
}

// ml_vec3f_to_vec3i
void ml_vec3f_to_vec3i(s32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_to_vec3s
void ml_vec3f_to_vec3s(s16 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_cross_product
void ml_vec3f_cross_product(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3i_cross_product
void ml_vec3i_cross_product(f32 dst[3], s32 a[3], s32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3f_dot_product
f32 ml_vec3f_dot_product(f32 a[3], f32 b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ml_vec3f_distance
f32 ml_vec3f_distance(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return sqrtf(SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]));
}

// ml_vec3f_distance_sq
f32 ml_vec3f_distance_sq(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]);
}

//ml_vec3f_getVecFromYaw
void ml_vec3f_getVecFromYaw(f32* dst, f32 yaw, f32 dist)
{
    f32 temp_f6;

    temp_f6 = ml_sin2f(yaw) * dist;
    dst[0] = temp_f6;
    dst[1] = 0.0f;
    dst[2] = ml_cos2f() * dist;
}

void func_800EEBF0(f32* dst, f32* arg1, f32 dist)
{
    ml_vec3f_clear(dst);
    ml_translateAngleDist_3D(dst, arg1[0], arg1[1], dist);
}

void func_800EEC30(f32* dst, f32 pitch, f32 yaw, f32 dist)
{
    ml_vec3f_clear(dst);
    ml_translateAngleDist_3D(dst, pitch, yaw, dist);
}

void func_800EEC70(f32* arg0, f32 arg1, f32 arg2, f32 arg3)
{
    f32 sp1C;

    sp1C = func_800138D0(arg1) * arg3;
    arg0[1] = 0.0f;
    arg0[0] = (f32)(ml_sin2f(arg2) * sp1C);
    arg0[2] = (f32)(ml_cos2f() * sp1C);
}
// ml_vec3f_is_equal
int ml_vec3f_is_equal(f32* a, f32* b)
{
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}
// ml_vec3i_is_equal
int ml_vec3i_is_equal(s32* a, s32* b)
{
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

// ml_vec3s_is_equal
int ml_vec3s_is_equal(s16* a, s16* b)
{
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);

}

// ml_vec3f_is_within_range
int ml_vec3f_is_within_range(f32* arg0, f32* arg1, f32 arg2)
{
    return (mlAbsF(arg0[0] - arg1[0]) < arg2 && mlAbsF(arg0[1] - arg1[1]) < arg2 && mlAbsF(arg0[2] - arg1[2]) < arg2);
}

// ml_vec3f_is_zero
int ml_vec3f_is_zero(f32* arg0)
{
    return !(arg0[0] != 0.0f || arg0[1] != 0.0f || arg0[2] != 0.0f);
}

// ml_vec3f_is_not_zero
int ml_vec3f_is_not_zero(f32* arg0)
{
    return (arg0[0] != 0.0f || arg0[1] != 0.0f || arg0[2] != 0.0f);
}

f32 ml_vec3f_magnitude(f32* arg0)
{
    return sqrtf(SQ(arg0[0]) + SQ(arg0[1]) + SQ(arg0[2]));
}

//ml_distanceSquared_vec3f
f32 ml_vec3f_magnitude_sq(f32* arg0)
{
	return (SQ(arg0[0]) + SQ(arg0[1]) + SQ(arg0[2]));
}

f32 ml_vec2f_magnitude(f32* arg0)
{
    return sqrtf(SQ(arg0[0]) + SQ(arg0[2]));
}

f32 ml_vec2f_magnitude_sq(f32* arg0)
{
    return (SQ(arg0[0])) + (SQ(arg0[2]));
}

void ml_vec3f_add(f32* target, f32* modifier)
{
	target[0] += modifier[0];
	target[1] += modifier[1];
	target[2] += modifier[2];
}

void ml_vec3s_add(s16* target, s16* modifier)
{
	target[0] += modifier[0];
	target[1] += modifier[1];
	target[2] += modifier[2];
}

void ml_vec3s_add_3f(s16* target, f32* modifier)
{
	target[0] += modifier[0];
	target[1] += modifier[1];
	target[2] += modifier[2];
}

void ml_vec3f_add_3s(f32* target, s16* modifier)
{
	target[0] += modifier[0];
	target[1] += modifier[1];
	target[2] += modifier[2];
}

//ml_vec3f_translate_scale
void ml_vec3f_translate_scale(f32* arg0, f32* arg1, f32 arg2)
{
    arg0[0] += arg1[0] * arg2;
    arg0[1] += arg1[1] * arg2;
    arg0[2] += arg1[2] * arg2;
}

//ml_translateAngleDist
void ml_translateAngleDist(f32* arg0, f32 angle, f32 dist)
{
    arg0[0] += dist * ml_sin2f(angle);
    arg0[2] += dist * ml_cos2f();
}

//ml_translateAngleDist_3D
void ml_translateAngleDist_3D(f32* arg0, f32 pitchAngle, f32 yawAngle, f32 dist)
{
    f32 temp_f6;
    temp_f6 = ml_cosf(pitchAngle) * dist;
    arg0[1] += dist * ml_sinf(); //y
    arg0[0] += temp_f6 * ml_sin2f(yawAngle); //x
    arg0[2] += temp_f6 * ml_cos2f(); //z
}

void ml_vec3f_normalizeMagnitude(f32* vec)
{
    f32 temp_f14;
    f32 temp_f2_2;
    temp_f14 = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (temp_f14 != 0.0f)
    {
        temp_f2_2 = 1.0f / sqrtf(temp_f14);
        vec[0] *= temp_f2_2;
        vec[1] *= temp_f2_2;
        vec[2] *= temp_f2_2;
    }
}

// ml_vec3f_apply_scale
void ml_vec3f_apply_scale(f32 vec[3], f32 scale) {
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

// ml_vec3f_set_length
void ml_vec3f_set_length(f32 vec[3], f32 target_length) {
    f32 length_sq;

    length_sq = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (length_sq != 0.0f) {
        ml_vec3f_apply_scale(vec, target_length / sqrtf(length_sq));
    }
}

// ml_vec3f_subtract
void ml_vec3f_subtract(f32 dst[3], f32 src[3]) {
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

void ml_vec3f_getNormalized(f32* dst, f32* src)
{
    f32 temp_f14;

    temp_f14 = SQ(src[0]) + SQ(src[1]) + SQ(src[2]);
    if (temp_f14 != 0.0f)
    {
        ml_getScaledVec3f(dst, src, 1.0f / sqrtf(temp_f14));
        return;
    }
    ml_vec3f_copy(dst, src);
}

void ml_vec3f_normalizeAngles_f(f32* arg0)
{
    arg0[0] = ml_normalizeAngle_f(arg0[0]);
    arg0[1] = ml_normalizeAngle_f(arg0[1]);
    arg0[2] = ml_normalizeAngle_f(arg0[2]);
}


void func_800EF4E4(f32* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    f32 cosf;
    f32 sinf;
    f32 sp24;

    sinf = ml_sin2f(arg1);
    cosf = ml_cos2f();
    sp24 = arg4 * sinf + arg5 * cosf;
    arg0[1] = (arg4 * cosf) - (arg5 * sinf);
    sinf = ml_sin2f(arg2);
    cosf = ml_cos2f();
    arg0[0] = (sp24 * sinf) + (arg3 * cosf);
    arg0[2] = (sp24 * cosf) - (arg3 * sinf);
}

void func_800EF5A0(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 cosf;
    f32 pad;
    f32 temp_f14;
    f32 sinf;
    f32 temp_f2;

    sinf = ml_sin2f(arg1[0]);
    cosf = ml_cos2f();
    temp_f14 = (arg3 * sinf) + (arg4 * cosf);
    arg0[1] = (arg3 * cosf) - (arg4 * sinf);
    sinf = ml_sin2f(arg1[1]);
    cosf = ml_cos2f();
    arg0[0] = (temp_f14 * sinf) + (arg2 * cosf);
    arg0[2] = (temp_f14 * cosf) - (arg2 * sinf);
    sinf = ml_sin2f(arg1[2]);
    cosf = ml_cos2f();
    temp_f2 = arg0[0];
    temp_f14 = (arg0[0] * cosf) - (arg0[1] * sinf);
    arg0[1] = (arg0[0] * sinf) + (arg0[1] * cosf);
    arg0[0] = temp_f14;
}

void func_800EF6A8(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 cosf;
    f32 sinf;
    f32 sp2C;
    f32 temp_f2;
    f32 temp_f2_2;

    sinf = ml_sin2f(arg1[2]);
    cosf = ml_cos2f();
    arg0[1] = (f32)((arg2 * sinf) + (arg3 * cosf));
    arg0[0] = (f32)((arg2 * cosf) - (arg3 * sinf));
    sinf = ml_sin2f(arg1[0]);
    cosf = ml_cos2f();
    temp_f2 = arg0[1];
    sp2C = (temp_f2 * sinf) + (arg4 * cosf);
    arg0[1] = (f32)((temp_f2 * cosf) - (arg4 * sinf));
    sinf = ml_sin2f(arg1[1]);
    cosf = ml_cos2f();
    temp_f2_2 = arg0[0];
    arg0[2] = (f32)((sp2C * cosf) - (temp_f2_2 * sinf));
    arg0[0] = (f32)((temp_f2_2 * cosf) + (sp2C * sinf));
}

void func_800EF7B0(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 sinf;
    f32 cosf;
    f32 temp_fv1;


	cosf = ml_cosf(arg1[1]);
	sinf = ml_sinf();
    arg0[1] = arg3;
    arg0[2] = arg4 * cosf - arg2 * sinf;
    arg0[0] = arg4 * sinf + arg2 * cosf;
	cosf = ml_cosf(arg1[0]);
	sinf = ml_sinf();
    temp_fv1 = arg0[1] * cosf - arg0[2] * sinf;
    arg0[2] = arg0[1] * sinf + arg0[2] * cosf;
    arg0[1] = temp_fv1;
	cosf = ml_cosf(arg1[2]);
	sinf = ml_sinf();
    temp_fv1 = ((arg0[0] * cosf) - (arg0[1] * sinf));
    arg0[1] = ((arg0[0] * sinf) + (arg0[1] * cosf));
    arg0[0] = temp_fv1;
}

void func_800EF8BC(f32* arg0, f32* arg1, f32 arg2)
{
    f32 cosf;
    f32 sinf;
    f32 temp_fa1;

    cosf = ml_cosf(arg2);
	sinf = ml_sinf();
    arg0[0] = arg1[0];

    temp_fa1 = arg1[1] * cosf - arg1[2] * sinf;
    arg0[2] = arg1[1] * sinf + arg1[2] * cosf;
    arg0[1] = temp_fa1;
}

void func_800EF934(f32* arg0, f32* arg1, f32 arg2)
{
    f32 cosf;
    f32 sinf;
    f32 val;
	cosf = ml_cosf(arg2);
	sinf = ml_sinf();
    val = (arg1[2] * sinf) + (arg1[0] * cosf);
    arg0[1] = arg1[1];
    arg0[2] = (arg1[2] * cosf) - (arg1[0] * sinf);
    arg0[0] = val;
}

void func_800EF9A8(f32* arg0, f32* arg1, f32 arg2)
{
    f32 cosf;
    f32 sinf;
    f32 temp_fa1;

	cosf = ml_cosf(arg2);
	sinf = ml_sinf();
    temp_fa1 = arg1[0] * cosf - arg1[1] * sinf;
    arg0[1] = arg1[0] * sinf + arg1[1] * cosf;
    arg0[2] = arg1[2];
    arg0[0] = temp_fa1;
}


//ml_getScaledVec3f
void ml_getScaledVec3f(f32* dst, f32* src, f32 arg2)
{
    dst[0] = src[0] * arg2;
	dst[1] = src[1] * arg2;
	dst[2] = src[2] * arg2;
}

//ml_vec3f_assign_value
void ml_vec3f_assign_value(f32* dst, f32 arg1, f32 arg2, f32 arg3)
{
	dst[0] = arg1;
	dst[1] = arg2;
	dst[2] = arg3;
}
//ml_vec3s_assign_value
void ml_vec3s_assign_value(s16* dst, s16 arg1, s16 arg2, s16 arg3)
{
	dst[0] = arg1;
	dst[1] = arg2;
	dst[2] = arg3;
}
//ml_vec3i_assign_value
void ml_vec3i_assign_value(s32* dst, s32 arg1, s32 arg2, s32 arg3)
{
	dst[0] = arg1;
	dst[1] = arg2;
	dst[2] = arg3;
}

void func_800EFA98(f32* arg0, f32* arg1, f32 arg2)
{
    f32 temp_f14;

    temp_f14 = arg1[0] * arg1[0] + arg1[1] * arg1[1] + arg1[2] * arg1[2];
    if (temp_f14 != 0.0f)
    {
        ml_getScaledVec3f(arg0, arg1, arg2 / sqrtf(temp_f14));
        return;
    }
    ml_vec3f_copy(arg0, arg1);
}

//ml_getdiff_vec3f
void ml_getdiff_vec3f(f32* arg0, f32* arg1, f32* arg2)
{
    arg0[0] = arg1[0] - arg2[0];
    arg0[1] = arg1[1] - arg2[1];
    arg0[2] = arg1[2] - arg2[2];
}

//ml_getdiff_vec3i
void ml_getdiff_vec3i(s32* arg0, s32* arg1, s32* arg2)
{
    arg0[0] = (arg1[0] - arg2[0]);
    arg0[1] = (arg1[1] - arg2[1]);
    arg0[2] = (arg1[2] - arg2[2]);
}

f32 func_800EFB8C(f32* arg0, f32* arg1)
{
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = arg0[0] - arg1[0];
    temp_f2 = arg0[2] - arg1[2];
    if ((temp_f0 != 0.0f) || (temp_f2 != 0.0f))
    {
        return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
    }
    return 0.0f;
}

f32 func_800EFBFC(f32* arg0, f32* arg1) {
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = mlAbsF(arg1[0] - arg0[0]);
    temp_f0 = mlAbsF(arg1[2] - arg0[2]);
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

f32 func_800EFC7C(f32* arg0, f32* arg1)
{
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = arg0[0] - arg1[0];
    temp_f12 = arg0[2] - arg1[2];
    if ((temp_f2 != 0.0f) || (temp_f12 != 0.0f))
    {
        return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
    }
    return 0;
}

void func_800EFCD8(f32* arg0, f32 arg1, f32 arg2)
{
    arg0[0] = ml_sin2f(arg1) * arg2;
    arg0[2] = ml_cos2f() * arg2;
}

// ml_vec3f_clear
void ml_vec3f_clear(f32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3i_clear
void ml_vec3i_clear(s32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3s_clear
void ml_vec3s_clear(s16 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

void func_800EFD60(f32* arg0, f32* arg1, f32 arg2)
{
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;

    sp1C = mlAbsF(ml_cosf(arg2));
    temp_f0 = mlAbsF(ml_sinf());
    temp_f2 = arg1[0];
    temp_f12 = arg1[2];
    arg0[0] = (f32)((temp_f2 * sp1C) + (temp_f12 * temp_f0));
    arg0[1] = (f32)arg1[1];
    arg0[2] = (f32)((temp_f12 * sp1C) + (temp_f2 * temp_f0));
}

void func_800EFDE8(f32* arg0, f32* arg1, f32* arg2)
{
    f32 sp1C[3];

    ml_getScaledVec3f(sp1C, arg1, -1.0f);
    ml_getScaledVec3f(arg0, arg2, 2.0f * ml_vec3f_dot_product(sp1C, arg2));
    ml_vec3f_subtract(arg0, sp1C);
}
