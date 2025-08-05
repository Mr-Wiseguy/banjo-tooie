#include "ch/handcart.h"

s32 func_80800000_chhandcart(void)
{
    return func_800DA564(0xA4C, 3);
}

void func_80800024_chhandcart(s32 arg0)
{
    func_800DA7A8(0x9DC, arg0, 2);
    func_800FDC28(0U);
    switch (arg0) 
    {
    case 1:
        func_800FC660(0x17U);
        return;
    case 2:
        func_800FC660(0x16U);
        return;
    }
}

s32 func_80800090_chhandcart(void) 
{
    return func_800DA564(0x9DC, 2);
}
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_808000B4_chhandcart.s")
#else
void func_808000B4_chhandcart(Actor* arg0)
{
    u32 var_a0;
    u32 var_a1;
    u32 var_a1_2;
    var_a1_2 = ((CanaryMaryMemory*)func_80100094(arg0, 0U))->unkF;
    switch (var_a1_2)
    {
    case 1:
        if (((*((s32*)(&arg0->unk64))) << 0xC) < 0)
        {
            var_a0 = 0x170;
        }
        else
        {
            var_a0 = 0x16F;
        }
        _gcgoto_entrypoint_1(var_a0, 1);
        return;

    case 0:
    case 2:
        if (func_80800090_chhandcart() == 2)
        {
            if ((*((s32*)(&arg0->unk64))) << 0xC < 0)
            {
                var_a1 = 0x15;
            }
            else
            {
                var_a1 = 0x16;
            }
            _gcgoto_entrypoint_1(0xC7, var_a1);
            return;
        }
        else
        {
            if (((*((s32*)(&arg0->unk64))) << 0xC) < 0)
            {
                var_a1_2 = 0x16;
            }
            else
            {
                var_a1_2 = 0x15;
            }
            _gcgoto_entrypoint_1(0xC7, var_a1_2);
            return;
        }

    }

}

#endif
s32 func_80800194_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* new_var;
    u8 temp_v0;
    new_var = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    temp_v0 = func_800DA564(0xA4C, 3);
    return new_var->unkF = temp_v0;
}

void func_808001D0_chhandcart(Actor* arg0, s32 arg1) 
{
    CanaryMaryMemory* sp1C;

    sp1C = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    func_800DA7A8(0xA4C, arg1, 3);
    sp1C->unkF = (u8)arg1;
}

void func_80800214_chhandcart(Actor* arg0)
{
    switch (((CanaryMaryMemory*)func_80100094(arg0, 0U))->unkF)
    {
    case 0:
        func_808001D0_chhandcart(arg0, 1);
        func_808000B4_chhandcart(arg0);
        return;
    case 1:
        func_808001D0_chhandcart(arg0, 2);
        _gcintrotext_entrypoint_0();
        func_808000B4_chhandcart(arg0);
        return;
    case 2:
        func_808001D0_chhandcart(arg0, 0);
        func_80800024_chhandcart(0);
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_808002B8_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80800528_chhandcart.s")

void func_808007BC_chhandcart(s32* arg0, s32 arg1) 
{
    _capod_entrypoint_2(*arg0, 0x1D, arg1 | 0x800);
}

void func_808007F0_chhandcart(Actor* arg0)
{
    if (((HandcartMemory*)func_80100094(arg0, 0U))->unk8F4 == 3)
    {
        func_80100074(arg0, 1, 0);
    }
}

void func_80800830_chhandcart(s32 arg0) 
{
    func_8008FB58(arg0 + 4, -25.0f, 100.0f);
}

void func_80800858_chhandcart(Actor* arg0, Actor* arg1, s32 arg2, s32 arg3)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    if (arg1 == NULL)
    {
        arg1 = arg0;
    }
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart((s32*)arg0, 0);
    case 1:
    case 3:
    case 4:
        _capod_entrypoint_8(1);
        sp1C->unk8F4 = 2U;
        _gcdialogcamera_entrypoint_6(arg1->unk0);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg2, arg3);
        break;
    }
}

void func_8080090C_chhandcart(Actor* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    HandcartMemory* sp1C;
    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart((s32*)arg0, arg2);
    case 2:
    case 3:
    case 4:
        sp1C->unk8F4 = 1U;
    case 1:
        _capod_entrypoint_6(arg3, arg1, arg2);
        break;
    }
}

void func_80800998_chhandcart(Actor* arg0, u32 arg1, u32 arg2, Unk80132ED0* arg3) {
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*) func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4) 
    {
    case 0:
        func_808007BC_chhandcart((s32*)arg0, (s32)arg2);
    case 1:
    case 2:
    case 3:
        sp1C->unk8F4 = 4U;
    case 4:
        _capod_entrypoint_20(arg3, arg1, arg2);
        break;
    }
}

void func_80800A24_chhandcart(Actor* arg0, s32 arg1, s32 arg2) {
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    switch (sp1C->unk8F4)
    {
    case 0:
        func_808007BC_chhandcart((s32*)arg0, arg2);
    case 1:
    case 2:
    case 4:
        sp1C->unk8F4 = 3U;
    case 3:
        _capod_entrypoint_8(0);
        func_808002B8_chhandcart(arg0, arg1);
        break;
    }
}

void func_80800AB0_chhandcart(Actor* arg0) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_808007F0_chhandcart(arg0);
    if (sp1C->unk8F4 != 0)
    {
        _capod_entrypoint_3(0);
        sp1C->unk8F4 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80800B00_chhandcart.s")

void func_80800CD0_chhandcart(Actor* arg0)
{
    HandcartMemory* temp_v0;


    s32 sp30;

    f32 temp_f0_2;
    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    if (!arg0->unk5F)
    {
    }
    sp30 = func_8010262C(arg0->unk0, 2);
    temp_v0->unk918 = func_800136E4(temp_v0->unk918 + (arg0->unk24 * 0.5f));
    if (sp30 != 0)
    {
        func_800E0AFC(sp30, 0x2B, -1.0f, temp_v0->unk918, 0.0f, 0.0f);
        func_800E0AFC(sp30, 0x2C, -1.0f, temp_v0->unk918, 0.0f, 0.0f);
    }
    if (arg0->unk24 > 10.0f)
    {
        temp_f0_2 = func_800F10B4(1.0f - (arg0->unk24 / 90.0f), 0.0f, 1.f, 0.5f, 3.0f);
        func_80101CDC(arg0, temp_f0_2);
        if (arg0->unk5F == 0)
        {
            arg0->unk5F = func_800C4350(arg0->unk5F, arg0->position, &D_80804DA4_chhandcart);
            return;
        }
        func_800C31DC(arg0->unk5F, func_800F10B4(temp_f0_2, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(arg0->unk5F, arg0->position, 0);
        return;
    }
    func_80101CDC(arg0, 1e7f);
}

void func_80800E58_chhandcart(Actor* arg0, s32 arg1)
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    func_800904C8(0x28);
    if (arg1 != 0)
    {
        func_800903D0((sp1C->unk928));
    }
}

void func_80800EA0_chhandcart(u32* arg0)
{
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 1, &D_80804704_chhandcart);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 1, &D_80804714_chhandcart);
}

void func_80800EE4_chhandcart(Actor* arg0, s32 arg1) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg0, 0U);
    if ((func_8009EA64() == 0x38A) && (sp1C->unk8FA != 0))
    {
        sp1C->unk8FA = 0U;
        func_80800E58_chhandcart(arg0, arg1);
        arg0->unk24 = 0;
        func_80800CD0_chhandcart(arg0);
    }
}

void func_80800F4C_chhandcart(Actor* arg0) 
{
    u32 temp_t6;

    temp_t6 = (u32)arg0->unk72 >> 0xA;
    if ((temp_t6 == 0) || (temp_t6 == 1) || (temp_t6 == 2))
    {
        _subaddieDll_entrypoint_4(arg0, 0);
        return;
    }
    _subaddieDll_entrypoint_4(arg0, 1);
}

void func_80800FA0_chhandcart(Actor* arg0, s32 arg1)
{
    HandcartMemory* sp24;
    u32 temp_t6;

    sp24 = (HandcartMemory*)func_80100094(arg0, 0U);
    temp_t6 = (u32)arg0->unk72 >> 0xA;
    switch (temp_t6)
    {
    case 11:
        break;
    case 4:
        func_800F4CC0(func_800F54E4());
        break;
    case 23:
        func_80103140(arg0, 0x67C, arg0->unk0->unk16);
        break;
    }
    func_80102424(arg0, arg1);
    switch ((u32)arg0->unk72 >> 0xA)
    {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    case 3:
        func_800903D0(arg0->position);
        break;
    case 4:
        sp24->unk8FA = 1;
        func_800904F4(0x27, arg0->unk0);
        func_800F4CEC(func_800F54E4(), 0x3B);
        break;
    case 5:
        sp24->unk8FA = 1;
        func_800904F4(0x27, arg0->unk0);
        break;
    case 7:
        func_80800EE4_chhandcart(arg0, 1);
        break;
    }
    func_80800F4C_chhandcart(arg0);
}

void func_808010D8_chhandcart(Actor* arg0, s32 arg1) {
    Actor* sp1C;

    sp1C = func_80106790(arg0->unk3C);
    func_80800FA0_chhandcart(arg0, arg1);
    func_80802CE8_chhandcart(sp1C, arg1);
}

void func_8080111C_chhandcart(Actor* arg0)
{
    if (func_8009EA64() == 0x38A) 
    {
        //Position
        func_800907C0(arg0->position);
        //Rotation
        func_800906DC(arg0->rotation);
    }
}

f32 func_8080115C_chhandcart(f32* arg0, f32 arg1)
{
    f32 gamespeed;
    f32 temp_f2;
    f32 temp_f12;
    s32 temp_v0;
    gamespeed = func_800D8FF8();
    //Get Button Hold Time
    temp_v0 = func_80016B30(0, 0);
    temp_f12 = *arg0;

    if (temp_f12 < 0.0f)
    {
        if (temp_v0 != 0)
        {
            arg1 += func_800F10B4(temp_f12, -1.0f, -0.01f, 0.0f, 3.0f);
            *arg0 = 0.01f;
            return arg1;
        }
        else
        {
            *arg0 = temp_f12 - gamespeed;
            arg1 *= 0.98f;
        }
    }
    else
    {
        if (temp_v0 == 0)
        {
            arg1 += func_800F10B4(temp_f12, 1.0f, 0.01f, 0.0f, 3.0f);
            *arg0 = -0.01f;
            return arg1;
        }
        else
        {

            *arg0 = temp_f12 + gamespeed;
            arg1 *= 0.98f;
        }
    }
    if (arg1 > 90.0f)
    {
        arg1 = 90.0f;
    }
    return arg1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801290_chhandcart.s")

void func_808014D8_chhandcart(Actor* arg0, u32 arg1)
{
    s32 var_s1;
    s32 var_s2;
    HandcartMemory* temp_v0;
    u8* var_s0;
    temp_v0 = (HandcartMemory*)func_80100094(arg0, 0U);
    var_s1 = 0;
    var_s2 = 0;
    var_s0 = (u8*)temp_v0;
    for (; var_s2 < 0x3C; var_s2++)
    {
        if (var_s0[0x87C] == 0)
        {
            var_s0[0x87C] = 0xFFU;
            var_s0[0x87C + 0x3C] = (s8)arg1;
            func_800EFD24(temp_v0->unkC[var_s2]);
            func_800EFA4C(temp_v0->unkC[var_s2] + 0x168, func_800DC178(-15.0f, 15.0f), func_800DC178(80.0f, 120.0), func_800DC178(-50.0f, -85.0f));
            var_s1 += 1;
            if (var_s1 >= 0x4)
            {
                return;
            }
        }
        var_s0++;
    }

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801638_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_8080169C_chhandcart.s")

void func_8080176C_chhandcart(Actor* arg0) 
{
    HandcartMemory* sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 temp_f0;

    sp44 = (HandcartMemory*)func_80100094(arg0, 0U);
    func_8080169C_chhandcart(arg0, 0, sp2C);
    func_8080169C_chhandcart(arg0, 1, sp38);
    temp_f0 = func_800F1828(sp2C, sp38);
    arg0->position[1] = (sp2C[1] + sp38[1]) * 0.5f;
    arg0->rotation[2] = sp44->unk93C + temp_f0;
    if (arg0->rotation[2] > 0.0f) 
    {
        arg0->position[1] += func_80013970(sp44->unk93C) * 58.0f;
        return;
    }
    arg0->position[1] -= func_80013970(sp44->unk93C) * 58.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801850_chhandcart.s")

void func_80801BA4_chhandcart(Actor* arg0)
{
    HandcartMemory* temp_s1;
    f32 sp28;

    sp28 = 0.1f;
    temp_s1 = (HandcartMemory*)func_80100094(arg0, 0U);
    func_80105A9C(arg0, arg0->unk24 * 10.0f);
    func_80105834(arg0);
    temp_s1->unk920 = func_800F10B4(arg0->unk24, 0.0f, 100.0f, 0.0f, func_800F1DCC(arg0->rotation[1], temp_s1->unk8) * 3.0f);
    temp_s1->unk8 = (f32)arg0->rotation[1];
    if (temp_s1->unk8F7 == 0)
    {
        sp28 = 1.0f;
        temp_s1->unk8F7 = 1U;
    }
    arg0->rotation[0] += func_800F1DCC(arg0->unk50, arg0->rotation[0]) * sp28;
    arg0->rotation[1] += func_800F1DCC(arg0->unk54, arg0->rotation[1]) * sp28;
    func_80801850_chhandcart(arg0);
    func_80800CD0_chhandcart(arg0);
    func_80801290_chhandcart(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801CBC_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801D50_chhandcart.s")

void func_80801FF4_chhandcart(s32 arg0) 
{

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80801FFC_chhandcart.s")

void func_80802068_chhandcart(Actor* arg0, s32 arg1) {
    Prop* var_v0;
    if (func_80800090_chhandcart() == 1)
    {
        arg1 = 1 - arg1;
    }
    if (arg1 != 0)
    {
        var_v0 = _gccubesearch_entrypoint_1(0x314, arg0->position);
    }
    else
    {
        var_v0 = _gccubesearch_entrypoint_1(0x313, arg0->position);
    }
    func_800EE88C(arg0->position, var_v0->position);
    //Controls the rotation of the cart when spawned in normal GGM
    arg0->rotation[1] = var_v0->unkC >> 0x17;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80802120_chhandcart.s")

void func_80802394_chhandcart(Actor* arg0) 
{
    func_801015D0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_808023B4_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80802400_chhandcart.s")

s32 func_80802468_chhandcart(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_a1;
    s32 var_v1;

    switch (arg1)
    {
    case 0x1F:
        func_80802394_chhandcart(arg0);
        break;
    case 0xE:
        func_80802400_chhandcart(func_80106790((s32)arg0->unk3C), arg2);
        return 3;

    case 0xB:
        temp_a1 = func_80106790((s32)arg0->unk3C);
        var_v1 = 0;
        if (arg2 != 0x19)
        {
            if (arg2 == 0x1D)
            {
                var_v1 = 0xF85;
            }
        }
        else
        {
            var_v1 = 0xFAF;
        }
        if (var_v1 != 0)
        {
            func_80800858_chhandcart(arg0, temp_a1, 2, 1);
            func_808023B4_chhandcart(temp_a1, var_v1, 0xB);
        }
        return 4;

    case 0x3D:
        func_80801FFC_chhandcart(arg0);
        break;
    default:
        return 0;
    }
    return 1;

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_8080256C_chhandcart.s")


void* chhandcart_entrypoint_0(void) 
{
    return &D_80804DC4_chhandcart;
}

void func_80802690_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* temp_v0;
    f32* sp24;

    temp_v0 = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    //GameSpeed
    temp_v0->unk0 = temp_v0->unk0 - func_800D8FF8();
    switch (func_801022E4(arg0))
    {
    case 0x7D:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808046C0_chhandcart, 0.1f);
        if (((f32)temp_v0->unk0 <= 0.0f) && (func_800DC298(0.03f) != 0) && (func_800C0638() == 0))
        {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808046D4_chhandcart);
            temp_v0->unk0 = 1.5f;
            return;
        }
    default:
        return;
    case 0x89:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E0C_chhandcart);
        return;
    case 0x8A:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E18_chhandcart);
        return;
    case 0x85:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046E8_chhandcart, &D_80804E2C_chhandcart);
        return;
    case 0x80:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808046C0_chhandcart, &D_80804E38_chhandcart);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808046E8_chhandcart, 0.9f);
        break;
    }
}

void func_8080282C_chhandcart(Actor* arg0, s32 arg1, s32 arg2) 
{
    Prop* var_v0;

    if (func_80800090_chhandcart() == 1)
    {
        arg1 = 1 - arg1;
    }
    if ((arg1 != 0) || (arg2 != 0))
    {
        var_v0 = _gccubesearch_entrypoint_1(0x385, arg0->position);
    }
    else
    {
        var_v0 = _gccubesearch_entrypoint_1(0x384, arg0->position);
    }
    func_800EE88C(arg0->position, var_v0->position);
    //Controls the rotation of canary mary when spawned in normal GGM
    arg0->rotation[1] = var_v0->unkC >> 0x17;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_808028F0_chhandcart.s")

void func_80802B74_chhandcart(Actor* arg0) 
{
    if (((u32)arg0->unk72 >> 0xA) == 0x10) 
    {
        func_800904C8(0x28);
    }
    if (func_80100094(arg0, 1U) != NULL) 
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

void func_80802BC8_chhandcart(Actor* arg0)
{
    CanaryMaryMemory* temp_s1;
    f32 sp20;
    float new_var;
    sp20 = 0.1f;
    temp_s1 = (CanaryMaryMemory*)func_80100094(arg0, 0U);
    func_80105A9C(arg0, arg0->unk24 * 10.0f);
    func_80105834(arg0);
    new_var = (func_800F1DCC(arg0->rotation[1], temp_s1->unk4) * arg0->unk24) * 0.5f;
    temp_s1->unk8 = (f32)((new_var - temp_s1->unk8) * 0.02f);    arg0->rotation[2] = temp_s1->unk8;
    temp_s1->unk4 = (f32)arg0->rotation[1];
    if (temp_s1->unkE == 0)
    {
        sp20 = 1.0f;
        temp_s1->unkE = 1U;
    }
    arg0->rotation[0] += func_800F1DCC(arg0->unk50 * 0.1f, arg0->rotation[0]) * sp20;
    arg0->rotation[1] += func_800F1DCC(arg0->unk54, arg0->rotation[1]) * sp20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80802CE8_chhandcart.s")

void func_808031D0_chhandcart(Actor* arg0, s32 arg1) {
    s32 temp_a0;

    func_80802CE8_chhandcart(arg0, arg1);
    temp_a0 = arg0->unk3C;
    if (temp_a0 != 0) 
    {
        func_80800FA0_chhandcart(func_80106790(temp_a0), arg1);
    }
}

void func_80803218_chhandcart(Actor* arg0, Actor* arg1)
{
    f32 var_f12;
    f32 sp18;
    f32 gamespeed;
    float new_var;
    u32 temp_v0;
    if ((*((u32*)(&arg1->unk7C))) & 0xFFF)
    {
        var_f12 = func_80105AE8(arg1);
    }
    else
    {
        var_f12 = 1.0f;
    }
    sp18 = func_80105AE8(arg0);
    gamespeed = func_800D8FF8();
    temp_v0 = (u32)((*((s32*)(&arg0->unk64))) << 0xC);
    if (gamespeed && gamespeed)
    {
    }
    temp_v0 = temp_v0 >> 0x1F;
    if (var_f12 <= (sp18 - 0.099990845f))
    {
        func_808031D0_chhandcart(arg0, 0x10);
        return;
    }
    if (var_f12 <= (sp18 - ((temp_v0 != 0) ? (0.019989014f) : (0.009994507f))))
    {
        if ((((temp_v0 != 0) ? (80.0f) : (75.0f)) - 10.0f) < arg0->unk24)
        {
            arg0->unk24 = arg0->unk24 - (((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed);
        }
    }
    else
        if ((.019989014f + sp18) <= var_f12)
        {
            new_var = (temp_v0 != 0) ? (80.0f) : (75.0f);
            if (arg0->unk24 < (10.0f + new_var))
            {
                arg0->unk24 += ((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed;
            }
        }
        else
            if (arg0->unk24 < ((temp_v0 != 0) ? (80.0f) : (75.0f)))
            {
                arg0->unk24 += ((temp_v0 != 0) ? (30.0f) : (20.0f)) * gamespeed;
            }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80803448_chhandcart.s")

void func_80803514_chhandcart(Actor* arg0)
{
    f32 temp_f0_2;
    f32 sp20;
    f32 var_f0;
    s32 temp_v0;

    arg0->unk54 = func_8010CD28();
    temp_f0_2 = func_800F1DCC(arg0->rotation[1], arg0->unk54);
    if ((temp_f0_2 < (-10.0f)) || (temp_f0_2 > 10.0f))
    {
        sp20 = func_80101F24(arg0);
        temp_v0 = func_801022E4(arg0);
        switch (temp_v0)
        {
        case 0x80:
            if ((sp20 > 0.75f) && (sp20 < 0.88f))
            {
                func_80102B2C(arg0, 6.0f);
                return;
            }
            break;

        case 0x85:
            if (((sp20 > 0.76f) && (sp20 < 0.99f)) || ((sp20 > 0.25f) && (sp20 < 0.51f)))
            {
                if (temp_f0_2 > 0.0f)
                {
                    var_f0 = -6.0f;
                }
                else
                {
                    var_f0 = 6.0f;
                }
                if (!arg0)
                {
                }
                arg0->rotation[1] = (f32)(arg0->rotation[1] + var_f0);
            }
            break;

        }

    }
}

void func_80803698_chhandcart(s32 arg0) 
{
    _sudeflect_entrypoint_1(arg0 + 4, 180.0f, 0.0f, 65.0f, 0x1E);
}

void func_808036D0_chhandcart(s32 arg0, Actor* arg1) 
{
    HandcartMemory* sp1C;

    sp1C = (HandcartMemory*)func_80100094(arg1, 0U);

    if (0) {}
    if (func_80105998(arg1, 0.9399872f) != 0)
    {
        sp1C->unk8F8 = 0;
        func_80800998_chhandcart(arg1, 1, 5, arg1->unk0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80803730_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80803794_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/func_80803FC4_chhandcart.s")

void func_8080436C_chhandcart(void) 
{
    func_801018A4();
}

void chhandcart_entrypoint_1(Actor* arg0)
{
    func_80101F24(func_80106790(arg0));
}

void* chhandcart_entrypoint_2(void) 
{
    return &D_80804E6C_chhandcart;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043C0_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043C8_chhandcart.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/handcart/R_808043D0_chhandcart.s")
