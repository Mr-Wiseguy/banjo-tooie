#include "su/baddiedialog.h"

s32 func_80800000_subaddiedialog(f32* a0, s32 a1, s32 arg2)
{
    if (arg2 & 7) {
        return func_8010CAC0(a0, a1);
    }
    return func_8010CB0C(a0, a1, 0x96, -0x96);
}

s32 subaddiedialog_entrypoint_0(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg0->unk74_30)
    {
        arg0->unk74_30 = func_80800000_subaddiedialog(arg0->position, arg1, arg2);
        return 0;
    }
    if (subaddiedialog_entrypoint_1(arg0->position, (u32)arg1, arg2) != 0)
    {
        arg0->unk74_30 = 1;
        return 1;
    }
    return 0;
}

s32 subaddiedialog_entrypoint_1(f32* a0, u32 a1, s32 arg2)
{
    if (func_80800000_subaddiedialog(a0, a1, arg2) == 0)
    {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1, arg2) == 0)
    {
        return 0;
    }
    return 1;
}

s32 subaddiedialog_entrypoint_2(f32* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (func_80800000_subaddiedialog(arg0, arg1, arg3) == 0)
    {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1U, arg3) == 0)
    {
        return 0;
    }
    if (func_8080110C_subaddiedialog(arg0, arg1, arg2) == 0)
    {
        return func_8080141C_subaddiedialog();
    }
    return 1;
}

s32 subaddiedialog_entrypoint_3(f32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (func_80800000_subaddiedialog(arg0, arg2, arg4) == 0)
    {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1U, arg4) == 0)
    {
        return 0;
    }
    if ((func_8080110C_subaddiedialog(arg0, arg2, arg3) == 0) || (func_8080118C_subaddiedialog(arg0, arg1, arg2, arg3) == 0))
    {
        return func_8080141C_subaddiedialog();
    }
    return 1;
}

s32 subaddiedialog_entrypoint_4(f32* arg0, s32 arg1, s32 arg2)
{
    if ((arg0 != NULL) && (func_80800000_subaddiedialog(arg0, arg1, arg2) == 0))
    {
        return 0;
    }
    if (func_80016B30(0, 1) != 1)
    {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1, arg2);
}

s32 subaddiedialog_entrypoint_5(f32* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (func_80800000_subaddiedialog(arg0, arg1, arg3) == 0)
    {
        return 0;
    }
    if (func_8080110C_subaddiedialog(arg0, arg1, arg2) == 0)
    {
        return 0;
    }
    if (func_80016B30(0U, 1U) != 1)
    {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, arg3);
}

s32 subaddiedialog_entrypoint_6(f32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (func_80800000_subaddiedialog(arg0, arg2, arg4) == 0)
    {
        return 0;
    }
    if ((func_8080110C_subaddiedialog(arg0, arg2, arg3) == 0) || (func_8080118C_subaddiedialog(arg0, arg1, arg2, arg3) == 0)) {
        return 0;
    }
    if (func_80016B30(0U, 1U) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/dialog/subaddiedialog_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/dialog/subaddiedialog_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/dialog/subaddiedialog_entrypoint_9.s")

s32 subaddiedialog_entrypoint_10(s32 arg0)
{
    s32 var_v0;
    var_v0 = arg0 != 0;
    if (arg0)
    {
    }
    if (var_v0)
    {
        var_v0 = arg0 != 3;
        return var_v0;
    }
}

s32 func_808010C8_subaddiedialog(s32 a0, s32 arg1, s32 arg2)
{
    if (arg1 < 0)
    {
        arg1 = func_8010108C(a0, 0xB8, (arg2 << 0x10) | (-arg1 & 0xFFFF), arg1);
    }
    return arg1;
}

s32 func_8080110C_subaddiedialog(f32* arg0, s32 arg1, s32 arg2)
{
    f32 sp2C[3];
    u32 pad;
    f32 sp24;
    func_8010D254(sp2C);
    sp24 = func_800F1DF4(sp2C, arg0);
    return mlAbsF(func_800F1DCC(func_800F5F24(func_800F54E4()), sp24)) < (f32)arg2;
}

s32 func_8080118C_subaddiedialog(f32* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    f32 sp24[3];
    u32 var_v0;

    func_8010D254(sp24);
    var_v0 = 0;
    return mlAbsF(func_800F1DCC((f32)arg1, func_800F1DF4(arg0, sp24))) < (f32)arg3;
}

s32 func_80801208_subaddiedialog(f32* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 sp1C;

    sp1C = arg2;
    if (arg3 & 0x20)
    {
        sp1C = arg2 | 1;
    }
    if (func_80800000_subaddiedialog(arg0, arg1, sp1C) == 0)
    {
        return 0;
    }
    if (func_80016B30(0U, 1U) != 1)
    {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, arg2);
}

u32 subaddiedialog_entrypoint_11(s32 arg0, u32 arg1, u32 arg2, s32 arg3, s16 arg4)
{
    return func_800C0534(arg1, arg2, arg3, arg0, 0, 0, 0, arg4);
}

void subaddiedialog_entrypoint_12(s32 arg1, s32 arg2, s32 arg3)
{
    s16 combined[2];
    combined[0] = arg2;
    combined[1] = arg3;
    func_8010114C(arg1, 0x2E, ((s32*)combined)[0]);
}

void subaddiedialog_entrypoint_13(s32 arg1, s32 arg2, s32 arg3)
{
    s16 combined[2];
    combined[0] = arg2;
    combined[1] = arg3;
    func_8010114C(arg1, 0x2F, ((s32*)combined)[0]);
}

void subaddiedialog_entrypoint_14(s32 arg1, s32 arg2, s32 arg3)
{
    s16 combined[2];
    combined[0] = arg2;
    combined[1] = arg3;
    func_8010114C(arg1, 0x30, ((s32*)combined)[0]);
}

void subaddiedialog_entrypoint_15(s32 arg1, s32 arg2, s32 arg3)
{
    s16 combined[2];
    combined[0] = arg2;
    combined[1] = arg3;
    func_8010114C(arg1, 0x3a, ((s32*)combined)[0]);
}

s32 func_80801394_subaddiedialog(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 var_v0;

    if (arg1 & 0x40)
    {
        return arg0->unk74_30 == 0;
    }
    if (arg2)
    {
    }
    var_v0 = (arg2 != 0) != 0;
    if (var_v0)
    {
        var_v0 = func_800DA298(arg2) == 0;
        return var_v0;
    }
}

void func_808013E4_subaddiedialog(Actor* arg0, s32 arg1, u32 arg2) {
    if (arg1 & 0x40)
    {
        arg0->unk74_30 = 1;
        return;
    }
    func_800DA544(arg2);
}

s32 func_8080141C_subaddiedialog(void)
{
    func_800F5FE0(func_800F54E4());
    return 0;
}

s32 subaddiedialog_entrypoint_16(void)
{
    u32 temp_v0;
    u32 sp1C;

    if (func_800DB9B0() != 0)
    {
        return 0;
    }
    temp_v0 = func_800F54E4();
    if ((temp_v0 == -1U) || (sp1C = temp_v0, (func_800F6438(temp_v0) == 0)))
    {
        return 0;
    }
    if (func_800F6774(sp1C) == 0)
    {
        return 0;
    }
    if (func_800C0638() != 0)
    {
        return 0;
    }
    return 1;
}
