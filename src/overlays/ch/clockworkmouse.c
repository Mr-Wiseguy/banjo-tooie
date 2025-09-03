#include "ch/clockworkmouse.h"

extern void* D_80803E48_chclockworkmouse;
extern void* D_80803EF0_chclockworkmouse;

void func_80800000_chclockworkmouse(void)
{
    func_800DA564(0xA37, 3);
}

void func_80800024_chclockworkmouse(s32 arg0)
{
    func_800DA7A8(0x9DA, arg0, 2);
    func_800FDC28(0);
    switch (arg0) 
    {                                 /* irregular */
    case 1:
        func_800FC660(0x17);
        return;
    case 2:
        func_800FC660(0x16);
        return;
    }
}

void func_80800090_chclockworkmouse(void)
{
    func_800DA564(0x9DA, 2);
}

void func_808000B4_chclockworkmouse(u32 a0)
{
    u8 temp_v1;

    temp_v1 = ((objectMemory*)func_80100094(a0, 0))->unkF;
    switch (temp_v1) {                              /* irregular */
    case 1:
        _gcgoto_entrypoint_1(0x161, 1);
        return;
    case 0:
    case 2:
        _gcgoto_entrypoint_1(0x136, 0x1F);
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080011C_chclockworkmouse.s")

void func_80800158_chclockworkmouse(u32 arg0, s32 arg1) 
{
    objectMemory* sp1C;

    sp1C = (objectMemory*)func_80100094(arg0, 0U);
    func_800DA7A8(0xA37, arg1, 3);
    sp1C->unkF = (u8)arg1;
}

void func_8080019C_chclockworkmouse(u32 arg0) 
{
    u8 temp_v1;

    temp_v1 = ((objectMemory*)func_80100094(arg0, 0U))->unkF;
    switch (temp_v1) 
    {                              /* irregular */
    case 0:
        func_80800158_chclockworkmouse(arg0, 1);
        func_808000B4_chclockworkmouse(arg0);
        return;
    case 1:
        func_80800158_chclockworkmouse(arg0, 2);
        _gcintrotext_entrypoint_0();
        func_808000B4_chclockworkmouse(arg0);
        return;
    case 2:
        func_80800158_chclockworkmouse(arg0, 0);
        func_80800024_chclockworkmouse(0);
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800240_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808004B0_chclockworkmouse.s")

void func_80800700_chclockworkmouse(s32* arg0, s32 arg1) 
{
    _capod_entrypoint_2(*arg0, 0x1C, arg1 | 0x800);
}

void func_80800734_chclockworkmouse(Actor* arg0)
{
    if (((objectMemory*)func_80100094(arg0, 0U))->unkFA == 3)
    {
        func_80100074(arg0, 1, 0);
    }
}

void func_80800774_chclockworkmouse(s32* arg0) 
{
    func_8008FB58(arg0 + 1, 0.0f, 70.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080079C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800850_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808008DC_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800968_chclockworkmouse.s")

void func_808009F4_chclockworkmouse(Actor* arg0)
{
    objectMemory* sp1C;

    sp1C = (objectMemory*)func_80100094(arg0, 0U);
    func_80800734_chclockworkmouse(arg0);
    if (sp1C->unkFA != 0) 
    {
        _capod_entrypoint_3(0);
        sp1C->unkFA = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800A44_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800C14_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800C64_chclockworkmouse.s")

void func_80800CC0_chclockworkmouse(Actor* arg0) {
    u32 temp_t6;

    temp_t6 = arg0->unk72_10;
    if ((temp_t6 == 0) || (temp_t6 == 1) || (temp_t6 == 2))
    {
        _subaddieDll_entrypoint_4(arg0, 0);
        return;
    }
    else
    {
        _subaddieDll_entrypoint_4(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800D14_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800E8C_chclockworkmouse.s")

void func_80800ED0_chclockworkmouse(Actor* arg0)
{
    if (func_8009EA64() == 0x171)
    {
        //Position
        func_800907C0(arg0->position);
        //Rotation
        func_800906DC(arg0->rotation);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80800F10_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801044_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080111C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801240_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801508_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801588_chclockworkmouse.s")

void func_80801848_chclockworkmouse(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801850_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808018BC_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801A94_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801B44_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801B90_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801BF0_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801CFC_chclockworkmouse.s")

void* chclockworkmouse_entrypoint_0(void)
{
    return &D_80803E48_chclockworkmouse;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801E2C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80801FC8_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802170_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808021C4_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808022E4_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808026E0_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802724_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_8080297C_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802A48_chclockworkmouse.s")

void func_80802BCC_chclockworkmouse(s32 arg0) 
{
    _sudeflect_entrypoint_1(arg0 + 4, 180.0f, 0.0f, 65.0f, 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802C04_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802C64_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_80802CC8_chclockworkmouse.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clockworkmouse/func_808032F8_chclockworkmouse.s")

void func_8080364C_chclockworkmouse(void) {
    func_801018A4();
}

void* chclockworkmouse_entrypoint_1(void) 
{
    return &D_80803EF0_chclockworkmouse;
}