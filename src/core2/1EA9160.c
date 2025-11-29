#include "core2/1EA9160.h"

extern s32 D_8011AE60;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF870.s")

s32 func_800CF87C()
{
    return D_8011AE60;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF9E4.s")

void func_800CFA70()
{
    func_800CF918();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D035C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D046C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D04A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D053C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D05E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D06D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D07CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0B38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0DAC.s")

void func_800D0F9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    f32 temp;
    f32 sp18[3];
    sp18[0] = (f32)arg1;
    sp18[1] = (f32)arg2;
    sp18[2] = (f32)arg3;
    func_800D0DAC(arg0, sp18, arg4, arg5);
}

void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((func_800D0A9C(arg0, arg1) == 0) && (func_800D0B68(arg0, arg1) == 0))
    {
        func_800D0B08(arg0, arg1);
        func_800D053C(arg0, arg1);
        if (arg2 != NULL)
        {
            func_800EE904(sp44, arg2);
        }
        else
        {
            func_800D07CC(arg0, arg1, sp34);
            func_800EE904(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&func_800D0F9C, (arg0 << 0x10) | (arg1 & 0xFFFF), sp44[0], sp44[1], sp44[2], arg3, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D10D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D1218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D1254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D129C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D1338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D13E8.s")
