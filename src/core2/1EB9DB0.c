#include "types.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E04C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E084C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E09B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0CB4.s")

struct unkfunc_800E0E94_inner {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
    u8 unk11;
};

struct unkfunc_800E0E94 {
    struct unkfunc_800E0E94_inner* unk0;
    s16 unk4;
    u8 pad[0x2];
    u8 unk8;
    f32 unkC;
};

void func_800E0E94(struct unkfunc_800E0E94* arg0, u8 arg1, f32* arg2) {
    f32 temp_f0;
    s32 i;
    struct unkfunc_800E0E94_inner* temp_a1;

    for (i = 0; i < arg0->unk4; i++) {
        temp_a1 = arg0->unk0 + i;
        if (temp_a1->unk10 == arg1 && temp_a1->unk11 == 3) {
            temp_f0 = temp_a1->unk0 * arg0->unkC;
            if (temp_f0 < 0.0f) {
                arg2[0] = arg2[0] + ((temp_a1->unk4 - arg2[0]) * -temp_f0);
                arg2[1] = arg2[1] + ((temp_a1->unk8 - arg2[1]) * -temp_f0);
                arg2[2] = arg2[2] + ((temp_a1->unkC - arg2[2]) * -temp_f0);
            } else if (temp_f0 > 0.0f) {
                arg2[0] *= 1.0f + ((temp_a1->unk4 - 1.0f) * temp_f0);
                arg2[1] *= 1.0f + ((temp_a1->unk8 - 1.0f) * temp_f0);
                arg2[2] *= 1.0f + ((temp_a1->unkC - 1.0f) * temp_f0);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB9DB0/func_800E0FE8.s")
