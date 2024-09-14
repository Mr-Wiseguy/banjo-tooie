#include <ultra64.h>
#include "macros.h"

// TODO rename operations based on whether they output to a new vector or output to an input vector.
// add vs sum/subtract vs difference? What to do for scalar multiplication? apply_scale vs scale?

// ml_vec3f_sum
void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// ml_vec3f_scaled_sum
void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale) {
    dst[0] = a[0] + b[0] * scale;
    dst[1] = a[1] + b[1] * scale;
    dst[2] = a[2] + b[2] * scale;
}

// ml_vec3f_copy
void func_800EE7F8(f32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_copy
void func_800EE814(s16 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_copy
void func_800EE830(s32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_to_vec3f
void func_800EE84C(f32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3f
void func_800EE88C(f32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3i
void func_800EE8CC(s32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec2f_to_vec3f
void func_800EE8E8(f32 dst[3], f32 src[2]) {
    dst[0] = src[0];
    dst[1] = 0;
    dst[2] = src[1];
}

// ml_vec3f_to_vec3i
void func_800EE904(s32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_to_vec3s
void func_800EE940(s16 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_cross_product
void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3i_cross_product
void func_800EE9EC(f32 dst[3], s32 a[3], s32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3f_dot_product
f32 func_800EEAA4(f32 a[3], f32 b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ml_vec3f_distance
f32 func_800EEAD4(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return sqrtf(SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]));
}

// ml_vec3f_distance_sq
f32 func_800EEB40(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EECE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EED58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEDE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEEA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEF94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EEFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF1B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF2A0.s")

// ml_vec3f_apply_scale
void func_800EF334(f32 vec[3], f32 scale) {
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

// ml_vec3f_set_length
void func_800EF368(f32 vec[3], f32 target_length) {
    f32 length_sq;

    length_sq = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (length_sq != 0.0f) {
        func_800EF334(vec, target_length / sqrtf(length_sq));
    }
}

// ml_vec3f_subtract
void func_800EF3DC(f32 dst[3], f32 src[3]) {
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EF9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFB8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFBFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFCD8.s")

// ml_vec3f_clear
void func_800EFD24(f32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3i_clear
void func_800EFD3C(s32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3s_clear
void func_800EFD4C(s16 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC8070/func_800EFDE8.s")
