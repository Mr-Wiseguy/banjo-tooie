#include "su/jiggy.h"

extern JiggyData D_808008E0_sujiggy[8];

s32 func_80800000_sujiggy(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/func_80800000_sujiggy.s")

s32 sujiggy_entrypoint_0()
{
    return func_800DA564(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
}

s32 sujiggy_entrypoint_1() 
{
    return 0xB;
}

u8 sujiggy_entrypoint_2(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].WorldCost;
}

f32 sujiggy_entrypoint_3(s32 arg0)
{
    return (f32)(_glreflight_entrypoint_0() & D_808008E0_sujiggy[arg0].unk9 & 0x7F);
}

s32 sujiggy_entrypoint_4(s32 arg0)
{
    return func_80800000_sujiggy(D_808008E0_sujiggy[arg0].unk4);
}

s32 sujiggy_entrypoint_5(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk8;
}

u8 sujiggy_entrypoint_6(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk11;
}

u8 sujiggy_entrypoint_7(s32 arg0)
{
    return D_808008E0_sujiggy[arg0].unk12;
}

void sujiggy_entrypoint_8(void)
{
    s32 sp24;
    s32 s20;
    s32 sp1C;

    sp24 = sujiggy_entrypoint_0();
    if (func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen) == 0)
    {
        func_800DA7A8(GFLAG_C0D_UNK, 0, 8);
        func_800DA7A8(FLAG5_D57_UNK, 0, 4);
    }
    func_800DA524(FLAG5_D4D_UNK);
    func_800DA544(FLAG5_D4E_UNK);
    if (sp24 >= 0xA)
    {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE, func_800DA298(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE));
    }
    else
    {
        func_800DA3B8(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE, func_800DA298(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen));
    }
    func_800DA3B8(FLAG5_D74_UNK, func_800DA298(FLAG_57B_UNK));
    func_800DA7A8(FLAG5_D50_UNK, sp24, 4);
    func_800DA524(FLAG5_D73_UNK);
    func_800FE844(2);
    func_800FE734(1);
    func_800FC6B0(0x2E);
    func_800A9B84();
    func_800A9B8C(0x151, 3);
    sp1C = sujiggy_entrypoint_4(sp24);
    func_800A9BA0(1, sp1C, sujiggy_entrypoint_5(sp24));
}

void sujiggy_entrypoint_9()
{
    func_800DA544(FLAG5_D4D_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_11.s")

s32 sujiggy_entrypoint_12(void)
{
    return func_800DA564(FLAG5_D50_UNK, 4);
}

s32 sujiggy_entrypoint_13()
{
    return func_800DA298(FLAG5_D4F_UNK);
}

s32 sujiggy_entrypoint_14(void)
{
    s32 sp1C;

    if (sujiggy_entrypoint_21() != 0)
    {
        if (func_800DA298(FLAG5_D4D_UNK) != 0)
        {
            sp1C = 2;
        }
        else
        {
            sp1C = 3;
        }
    }
    else if (func_800DA298(FLAG5_D4D_UNK) != 0)
    {
        sp1C = 1;
    }
    else
    {
        sp1C = 0;
    }
    func_800DA7A8(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, func_800DA564(FLAG5_D50_UNK, 4), 4);
    if (sujiggy_entrypoint_21() != 0)
    {
        func_800DA3B8(FLAG_589_ATTEMPTED_JIGGYWIGGY_SPECIAL_PUZZLE, func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    }
    else
    {
        func_800DA3B8(FLAG_3E9_PHYSICAL_IoH_PineGroveDoorOpen, func_800DA298(FLAG5_D49_TEMPCOPY_ATTEMPTED_JIGGYWIGGY_PUZZLE));
    }
    func_800DA3B8(FLAG_57B_UNK, func_800DA298(FLAG5_D74_UNK));
    if (sp1C == 1)
    {
        func_800DA944(FLAG_35C_JIGGYWIGGY_CHALLENGE_COMPLETION_1, 4);
    }
    func_800DA524(FLAG5_D4F_UNK);
    func_800DA524(FLAG5_D4E_UNK);
    if (func_800DA298(FLAG5_D73_UNK) != 0)
    {
        func_800D2054(1, 0x96, sujiggy_entrypoint_24());
        func_800DA524(FLAG5_D73_UNK);
    }
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_17.s")

s32 sujiggy_entrypoint_18(void) 
{
    return (sujiggy_entrypoint_19() < 3) ^ 1;
}

s32 sujiggy_entrypoint_19(void)
{
    return func_800DA564(FLAG5_D57_UNK, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_22.s")

u16 sujiggy_entrypoint_23(s32 arg0) 
{
    return D_808008E0_sujiggy[arg0].unk14;
}

s32 sujiggy_entrypoint_24(void)
{
    return func_800DA564(GFLAG_C0D_UNK, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/jiggy/sujiggy_entrypoint_25.s")
