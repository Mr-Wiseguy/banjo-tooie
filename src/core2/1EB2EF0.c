#include "core2/1EB2EF0.h"
#define LENGTH_SQ_VEC4F(v) (v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3])

//vec4f_copy
void func_800D9600(f32 dst[4], f32 src[4]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D965C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D97E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9888.s")

void func_800D9AD4(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3) {
    f32 var_f0;
    f32 var_f2;
    f32 sp20[4];

    sp20[0] = arg1[0] - arg2[0];
    sp20[1] = arg1[1] - arg2[1];
    sp20[2] = arg1[2] - arg2[2];
    sp20[3] = arg1[3] - arg2[3];
    var_f0 = LENGTH_SQ_VEC4F(sp20);

    sp20[0] = arg1[0] + arg2[0];
    sp20[1] = arg1[1] + arg2[1];
    sp20[2] = arg1[2] + arg2[2];
    sp20[3] = arg1[3] + arg2[3];
    var_f2 = LENGTH_SQ_VEC4F(sp20);

    if (var_f0 <= var_f2) {
        func_800D9888(arg0, arg1, arg2, arg3);
        return;
    }
    sp20[0] = -arg2[0];
    sp20[1] = -arg2[1];
    sp20[2] = -arg2[2];
    sp20[3] = -arg2[3];
    func_800D9888(arg0, arg1, sp20, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9C34.s")

int func_800D9C4C(f32 arg0[4]) {
    return ((arg0[0] == 0.0f)
        && (arg0[1] == 0.0f)
        && (arg0[2] == 0.0f)
        && (arg0[3] == 1.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9CE8.s")
