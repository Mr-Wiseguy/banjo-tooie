#include "core2/1EE4270.h"

extern f32 D_80136F20[3];
extern f32 D_80136F30[3];
extern f32 D_80136F40[3];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010A980.s")

void func_8010AA54(f32* arg0) {
    ml_vec3f_copy(arg0, D_80136F30);
}

void func_8010AA78(f32* arg0) {
    ml_vec3f_copy(arg0, D_80136F20);
}

void func_8010AA9C(f32* arg0) {
    ml_vec3f_copy(arg0, D_80136F40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010ACE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AE9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AF8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010AFF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B13C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B8A4.s")

s32 func_8010B910(Actor* arg0, s32 arg1, s32 arg2, s32 arg3) {
	ml_vec3f_add(arg0->position, &((f32*)arg0->actorData)[4]);
	return 0;
}
s32 func_8010B94C(Actor* arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800EF174(arg0->position, &((f32*)arg0->actorData)[4], time_getDelta());
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010B990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010BFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C2D8.s")

void func_8010C3A8(Actor* arg0, u32 arg1, f32 arg2)
{
    s32 pad;
    f32 temp_f0;

    temp_f0 = ((f32*)arg0->actorData)[3];
    ((f32*)arg0->actorData)[3] *= arg2;
    func_8010B990(arg0, arg1);
    ((f32*)arg0->actorData)[3] = temp_f0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4270/func_8010C4AC.s")
