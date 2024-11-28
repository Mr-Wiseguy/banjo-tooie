#include "common.h"

#include "ba/1E67DA0.h"

extern f32 func_8009E138(PlayerState *, s32);

s32 func_8008E4B0(void) {
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        self->unkC->unkC[i] = (s32)func_8009E138(self, i);
    }
    return self->unkC->unkC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008ED70.s")
