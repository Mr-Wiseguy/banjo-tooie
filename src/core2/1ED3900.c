#include "core2/1ED3900.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    s16 unk8;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    u8 unk12;
    s8 unk13;
    f32 unk14;
    s32 unk18;
}UNKD_80123880;

extern UNKD_80123880 D_80123880[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA6B8.s")

s32 func_800FA708(u32 amount, s32 positionSlot, s32 icon, u32 style)
{
    if ((icon != D_80123880[positionSlot].unkE) || (style != D_80123880[positionSlot].unk12))
    {
        if ((D_80123880[positionSlot].unk18 != 0) && (_scinfobar_entrypoint_23(D_80123880[positionSlot].unk18) != 0))
        {
            return 0;
        }
        if ((D_80123880[positionSlot].unk18 != 0) && (_scinfobar_entrypoint_7(D_80123880[positionSlot].unk18, icon) == 0))
        {
            return 0;
        }
    }

    D_80123880[positionSlot].unk11 = 0;
    D_80123880[positionSlot].unkE = icon;
    D_80123880[positionSlot].unk12 = style;

    func_800FA240(positionSlot, 1);
    D_80123880[positionSlot].unk14 = 2.0f;
    if ((_scinfobar_entrypoint_16(D_80123880[positionSlot].unk18) != icon) && (_scinfobar_entrypoint_22(D_80123880[positionSlot].unk18) != 0))
    {
        _scinfobar_entrypoint_6(D_80123880[positionSlot].unk18, 0);
    }
    func_800FA6B8(positionSlot, style, amount);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA8E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FAA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FAA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FAAB4.s")
