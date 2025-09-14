#include "ch/glowbo.h"

extern s32 D_80801460_chglowbo[3];
extern u32 D_808014C0_chglowbo;
extern u32 D_80801540_chglowbo;
extern u32 D_80801588_chglowbo;
extern u32 D_808015D0_chglowbo;
extern f32 D_80801618_chglowbo;
extern u32 _chglowbo_entrypoint_5;

void func_80800000_chglowbo(Actor* arg0) 
{
    glowboStruct* temp_v0 = (glowboStruct*)func_80100094(arg0, 0U);
    s32 sp18[3] = D_80801460_chglowbo;

    if (temp_v0->unk16 == 1)
    {
        temp_v0->unk8 = (f32)(temp_v0->unk8 + 0.02f);
        if (temp_v0->unk8 > 1.0f)
        {
            temp_v0->unk8 = 1.0f;
            temp_v0->unk16 = 0U;
        }
    }
    else {
        temp_v0->unk8 = (f32)(temp_v0->unk8 - 0.02f);
        if (temp_v0->unk8 < 0.6f)
        {
            temp_v0->unk8 = 0.6f;
            temp_v0->unk16 = 1U;
        }
    }
    sp18[0] = (s32)sp18[0] * temp_v0->unk8;
    sp18[1] = (s32)sp18[1] * temp_v0->unk8;
    sp18[2] = (s32)sp18[2] * temp_v0->unk8;
    func_800C8E84(temp_v0->unk4, sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_8080013C_chglowbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_808002F4_chglowbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_80800880_chglowbo.s")


u32* chglowbo_entrypoint_0(void) {
    return &D_808014C0_chglowbo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_80800A48_chglowbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_80800B10_chglowbo.s")

u32* chglowbo_entrypoint_1(void) {
    return &D_80801540_chglowbo;
}

u32* chglowbo_entrypoint_2(void) {
    return &D_80801588_chglowbo;
}

void func_80800E28_chglowbo(Actor* arg0)
{
    f32 sp3C[3];

    if (func_800EA05C() == 0x157)
    {
        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29)
    {
        arg0->scale = 0.75f;
    }
    else
    {
        arg0->scale = 0.25f;
    }
    arg0->rotation[1] = (func_80090010() + func_800DC178(-110.0f, 110.0f));
    func_8010D254(sp3C);
    func_800EEB9C(arg0->unk18, arg0->rotation[1], 400.0f);
    func_800EF04C(arg0->unk18, arg0->position);
    arg0->unk18[1] = (f32)(sp3C[1] + 20.0f);
    arg0->unk34 = -80.0f;
    arg0->unk2C = 30.0f;
    func_800C9C70(0.25f, 0x4DE, 0.5f, 0x4650, arg0->position, 500.0f, 2500.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_80800F64_chglowbo.s")

void func_80801118_chglowbo(Actor* arg0, s32 arg1)
{
    func_800DF5D8(0x80, 0x80, 0x80, _subaddiefade_entrypoint_0(arg0));
    func_80101870(arg0, arg1);
}

s32 func_8080115C_chglowbo(Actor* arg0, s32 arg1, u32 arg2) {
    if (arg1 == 0x4D) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}


u32* chglowbo_entrypoint_3(void) 
{
    return &D_808015D0_chglowbo;
}

void chglowbo_entrypoint_4(void)
{
    func_80108474(0x2A0, &D_80801618_chglowbo, func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_5(void) 
{
    f32 sp1C[3];
    func_8008FE94(1, sp1C);
    func_80108474(0x2A0U, sp1C, (s32)func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_6(void) 
{
    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/glowbo/func_80801258_chglowbo.s")
