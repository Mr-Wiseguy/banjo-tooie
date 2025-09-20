#ifndef __CORE2_1EC8070_H__
#define __CORE2_1EC8070_H__

#include "common.h"

void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]); // ml_vec3f_sum
void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale); // ml_vec3f_scaled_sum
void func_800EE7F8(f32 dst[3], f32 src[3]); // ml_vec3f_copy
void func_800EE814(s16 dst[3], s16 src[3]); // ml_vec3s_copy
void func_800EE830(s32 dst[3], s32 src[3]); // ml_vec3i_copy
void func_800EE84C(f32 dst[3], s32 src[3]); // ml_vec3i_to_vec3f
void func_800EE88C(f32 dst[3], s16 src[3]); // ml_vec3s_to_vec3f
void func_800EE8CC(s32 dst[3], s16 src[3]); // ml_vec3s_to_vec3i
void func_800EE8E8(f32 dst[3], f32 src[2]); // ml_vec2f_to_vec3f
void func_800EE904(s32 dst[3], f32 src[3]); // ml_vec3f_to_vec3i
void func_800EE940(s16 dst[3], f32 src[3]); // ml_vec3f_to_vec3s
void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]); // ml_vec3f_cross_product
void func_800EE9EC(f32 dst[3], s32 a[3], s32 b[3]); // ml_vec3i_cross_product
f32 func_800EEAA4(f32 a[3], f32 b[3]); // ml_vec3f_dot_product
f32 func_800EEAD4(f32 a[3], f32 b[3]); // ml_vec3f_distance
f32 func_800EEB40(f32 a[3], f32 b[3]); // ml_vec3f_distance_sq
void func_800EEBF0(f32*, f32*, f32);
void func_800EF1B8(f32*, f32, f32);
s32 func_800EEF24(f32[3]);
void func_800EF214(f32[3], f32, f32, f32);
void func_800EF334(f32 vec[3], f32 scale); // ml_vec3f_apply_scale
void func_800EF368(f32 vec[3], f32 target_length); // ml_vec3f_set_length
void func_800EF3DC(f32 dst[3], f32 src[3]); // ml_vec3f_subtract
f32 func_800EFB8C(f32*, f32*);
void func_800EFD24(f32 vec[3]); // ml_vec3f_clear
void func_800EFD3C(s32 vec[3]); // ml_vec3i_clear
void func_800EFD4C(s16 vec[3]); // ml_vec3s_clear

void func_800EEB9C(f32[3], f32, f32);
void func_800EEC30(f32[3], f32, f32, f32);
f32 func_800EEFD4(f32[3]);
void func_800EF04C(f32[3], f32[3]);
void func_800EF934(f32[3], f32[3], f32);
void func_800EF2A0(f32[3]);
void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
void func_800EF5A0(f32*, f32*, f32, f32, f32);
void func_800EFA4C(f32[3], f32, f32, f32);
void func_800EFA98(f32[3], f32[3], f32);
void func_800EFCD8(f32[3], f32, f32);
#endif // __CORE2_1EC8070_H__
