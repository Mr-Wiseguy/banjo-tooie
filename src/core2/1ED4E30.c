#include "core2/1ED4E30.h"
#include "core2/1EB3750.h"

extern s32 D_80135960;
extern s16 D_80123DE0[];

void func_800FB540(unkStruct800FB540* arg0) {
    s16* var_v1;
    s32 var_v0;

    if (arg0->unk33 == 0) {
        func_800FED70(arg0->unk28, arg0);
        arg0->unk33 = 1U;
        var_v1 = &D_80123DE0;
        for (var_v0 = 0;var_v0 != 0x30;var_v0++)
        {
        if (arg0->unk28 == D_80123DE0[var_v0]) 
        {
            flag_setValueTrue(var_v0 + 0x53E);
            return;
        }
        var_v1 ++;
        }
    }
}

void func_800FB5BC(unkStruct800FB540* arg0) {
    if (arg0->unk33 != 0) {
        func_800FED90(arg0->unk28, arg0);
        arg0->unk33 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB650.s")

void func_800FB6C0(s32 arg0, s32 arg1) {
    func_800FB650(arg0, arg1, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FBEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FBF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC124.s")

void func_800FC1A8()
{
    func_800FB774(&D_80135960);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCF50.s")
