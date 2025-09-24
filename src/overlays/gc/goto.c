#include "gc/goto.h"

typedef struct
{
    u8 unk0[0x42C];
    u8 unk42C;
} UNKD_80127194;

/* extern */
extern UNKD_80127194 D_80127194;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/func_80800000_gcgoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_0.s")

void func_8080011C_gcgoto(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (D_80127194.unk42C == 0)
    {
        if ((arg0 == 0xCE) && (arg1 == 4))
        {
            func_800DA544(FLAG_503_UNK);
        }
        gcgoto_entrypoint_0(&arg0, &arg1);
        func_800A7990(arg0, arg1, arg3);
        func_800EA334(arg2);
        gcgoto_entrypoint_14(1);
    }
}

void gcgoto_entrypoint_1(u32 a0, u32 a1)
{
    func_8080011C_gcgoto(a0, a1, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/func_808001E0_gcgoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/func_808003D0_gcgoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_6.s")

void gcgoto_entrypoint_7(s32 arg0, s32 arg1) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_10.s")

void gcgoto_entrypoint_11(s32 arg0, u32 arg1)
{
    s32 sp1C;
    s32 sp18;

    _sutempleboss_entrypoint_0(arg0, &sp1C, &sp18);
    if (sp1C != 0)
    {
        func_808003D0_gcgoto(arg0, (sp1C << 8) + sp18);
    }
}

void gcgoto_entrypoint_12(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/goto/gcgoto_entrypoint_15.s")
