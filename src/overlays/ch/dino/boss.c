#include "ch/dino/boss.h"

extern u32 D_80802A48_chdinoboss;
extern ActorData D_80802B40_chdinoboss;
extern ActorData D_80802B88_chdinoboss;
extern u32 D_80802C40_chdinoboss;
extern u32 D_80802C98_chdinoboss;

ActorData* chdinoboss_entrypoint_0(void)
{
    return &D_80802B40_chdinoboss;
}


ActorData*chdinoboss_entrypoint_1(void) {
    return &D_80802B88_chdinoboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800018_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800220_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800C50_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800E2C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800E88_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800F28_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800F70_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801408_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808015AC_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801660_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808016C0_chdinoboss.s")

void func_808017A0_chdinoboss(Actor* arg0) {
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802A48_chdinoboss, &D_80802C40_chdinoboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808017D0_chdinoboss.s")

void func_80801800_chdinoboss(Actor* arg0) {
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A48_chdinoboss, 0.23f);
}

void func_80801830_chdinoboss(Actor* arg0) 
{
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A48_chdinoboss, 0.28f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801860_chdinoboss.s")


void func_808018D0_chdinoboss(Actor* arg0) {
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802C98_chdinoboss, 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801900_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801A44_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801AE4_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801C28_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801C84_chdinoboss.s")

void func_80801CDC_chdinoboss(Actor* arg0) 
{
    func_800D2498(0xC8U, arg0->unk5C[2], 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801D08_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801DC8_chdinoboss.s")

void func_80801E90_chdinoboss(s32 arg0, s32 arg1)
{
    func_8010FFB0(func_800F5EF8(character_getActiveIndex()), arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801ECC_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801F44_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801FAC_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_8080232C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_8080248C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802500_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802540_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808025E8_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802684_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808026D0_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802864_chdinoboss.s")
