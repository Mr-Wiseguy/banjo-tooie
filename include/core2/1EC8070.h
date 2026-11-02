#ifndef __CORE2_1EC8070_H__
#define __CORE2_1EC8070_H__

#include "common.h"
#include "core1/1E2B200.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"

void ml_vec3f_sum(f32 dst[3], f32 a[3], f32 b[3]); // ml_vec3f_sum
void ml_vec3f_scaled_sum(f32 dst[3], f32 a[3], f32 b[3], f32 scale); // ml_vec3f_scaled_sum
void ml_vec3f_copy(f32 dst[3], f32 src[3]); // ml_vec3f_copy
void ml_vec3s_copy(s16 dst[3], s16 src[3]); // ml_vec3s_copy
void ml_vec3i_copy(s32 dst[3], s32 src[3]); // ml_vec3i_copy
void ml_vec3i_to_vec3f(f32 dst[3], s32 src[3]); // ml_vec3i_to_vec3f
void ml_vec3s_to_vec3f(f32 dst[3], s16 src[3]); // ml_vec3s_to_vec3f
void ml_vec3s_to_vec3i(s32 dst[3], s16 src[3]); // ml_vec3s_to_vec3i
void ml_vec2f_to_vec3f(f32 dst[3], f32 src[2]); // ml_vec2f_to_vec3f
void ml_vec3f_to_vec3i(s32 dst[3], f32 src[3]); // ml_vec3f_to_vec3i
void ml_vec3f_to_vec3s(s16 dst[3], f32 src[3]); // ml_vec3f_to_vec3s
void ml_vec3f_cross_product(f32 dst[3], f32 a[3], f32 b[3]); // ml_vec3f_cross_product
void ml_vec3i_cross_product(f32 dst[3], s32 a[3], s32 b[3]); // ml_vec3i_cross_product
f32 ml_vec3f_dot_product(f32 a[3], f32 b[3]); // ml_vec3f_dot_product
f32 ml_vec3f_distance(f32 a[3], f32 b[3]); // ml_vec3f_distance
f32 ml_vec3f_distance_sq(f32 a[3], f32 b[3]); // ml_vec3f_distance_sq
void func_800EEB9C(f32[3], f32, f32);
void func_800EEBF0(f32*, f32*, f32);
void func_800EEC30(f32[3], f32, f32, f32);
void func_800EEC70(f32*, f32, f32, f32);
int ml_vec3f_is_equal(f32*, f32*);
int ml_vec3f_is_zero(f32*);
int ml_vec3f_is_not_zero(f32[3]);
f32 ml_vec3f_magnitude(f32*);
f32 ml_vec3f_magnitude_sq(f32[3]);
f32 ml_vec2f_magnitude(f32*);
void ml_vec3f_add(f32[3], f32[3]); //ml_vec3f_add
void func_800EF174(f32*, f32*, f32);
void func_800EF1B8(f32*, f32, f32);
void func_800EF214(f32[3], f32, f32, f32);
void func_800EF2A0(f32[3]);
void ml_vec3f_apply_scale(f32 vec[3], f32 scale); // ml_vec3f_apply_scale
void ml_vec3f_set_length(f32 vec[3], f32 target_length); // ml_vec3f_set_length
void ml_vec3f_subtract(f32 dst[3], f32 src[3]); // ml_vec3f_subtract
void func_800EF410(f32*, f32*);
void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
void func_800EF5A0(f32*, f32*, f32, f32, f32);
void func_800EF8BC(f32*, f32*, f32);
void func_800EF934(f32[3], f32[3], f32);
void func_800EFA20(f32*, f32*, f32);
void ml_vec3f_assign_value(f32[3], f32, f32, f32);
void ml_vec3i_assign_value(s32*, s32, s32, s32);
void func_800EFA98(f32[3], f32[3], f32);
void ml_getdiff_vec3f(f32*, f32*, f32*);
void func_800EFB58(s32*, s32*, s32*);
f32 func_800EFB8C(f32*, f32*);
f32 func_800EFC7C(f32*, f32*);
void func_800EFCD8(f32[3], f32, f32);
void ml_vec3f_clear(f32 vec[3]); // ml_vec3f_clear
void ml_vec3i_clear(s32 vec[3]); // ml_vec3i_clear
void ml_vec3s_clear(s16 vec[3]); // ml_vec3s_clear
#endif // __CORE2_1EC8070_H__
