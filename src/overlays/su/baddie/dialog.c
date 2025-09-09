#include "su/baddiedialog.h"

s32 func_80800000_subaddiedialog(f32* a0, s32 a1, s32 arg2)
{
    if (arg2 & 7) 
    {
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
    //If B button is being held
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
    //If B button is being held
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
    //If B button is being held
    if (func_80016B30(0U, 1U) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, arg4);
}

u32 subaddiedialog_entrypoint_7(Actor* arg0, f32* arg1, subaddiedialog_UnkStruct0* arg2)
{
    s32 sp34;
    u32 var_a2_5;
    u32 var_a2_4;
    u32 var_a2;

    sp34 = (s32)arg2->unk16;
    if (((arg2->unk8 != (-1)) && (arg2->unkC != 0)) && (func_800F64A4(func_800F54E4(), arg2->unk8) == 0))
    {
        var_a2 = arg2->unkE;
        if ((var_a2 != 0) && (func_800DA298(arg2->unkE) == 0))
        {
            var_a2 = arg2->unk12;
            if (sp34 & 0x20)
            {
                var_a2 |= 1;
            }
            if (func_80800000_subaddiedialog(arg1, (s32)arg2->unk2, (s32)var_a2) == 0)
            {
                return 0U;
            }
            if ((sp34 & 2) && (func_8080110C_subaddiedialog(arg1, (s32)arg2->unk2, (s32)arg2->unk17) == 0))
            {
                return 0U;
            }
            if ((sp34 & 4) && (func_8080118C_subaddiedialog(arg1, (s32)arg0->rotation[1], (s32)arg2->unk2, (s32)arg2->unk17) == 0))
            {
                return 0U;
            }
            if ((!(sp34 & 1)) && (func_800F4B8C(func_800F54E4(), -1U, (s32)arg2->unk12) == 0))
            {
                return 0U;
            }
            var_a2 = arg2->unk14;
            if (!(sp34 & 0x10))
            {
                var_a2 |= 2;
            }
            if (subaddiedialog_entrypoint_11(arg0->unk0, (u32)arg2->unkC, (u32)var_a2, arg1, (s16)((s32)arg2->unk10)) != 0)
            {
                func_800DA544(arg2->unkE);
                if (arg0)
                {
                }
                var_a2 = arg2->unk18;
                if (var_a2 != 0)
                {
                    func_80102424(arg0, arg2->unk18);
                }
                return arg2->unkC;
            }
        }
        else
            if (func_80801208_subaddiedialog(arg1, arg2->unk2, arg2->unk12, sp34) != 0)
            {
                if ((sp34 & 2) && (func_8080110C_subaddiedialog(arg1, (s32)arg2->unk2, (s32)arg2->unk17) == 0))
                {
                    return func_8080141C_subaddiedialog();
                }
                if ((sp34 & 4) && (func_8080118C_subaddiedialog(arg1, (s32)arg0->rotation[1], (s32)arg2->unk2, (s32)arg2->unk17) == 0))
                {
                    return func_8080141C_subaddiedialog();
                }
                var_a2 = arg2->unk14;
                if (!(sp34 & 8))
                {
                    var_a2 |= 3;
                }
                if (subaddiedialog_entrypoint_11(arg0->unk0, (u32)arg2->unkC, var_a2, arg1, (s16)((s32)arg2->unk10)) != 0)
                {
                    var_a2 = arg2->unk18;
                    if (var_a2 != 0)
                    {
                        func_80102424(arg0, arg2->unk18);
                    }
                    return arg2->unkC;
                }
            }
        return func_8080141C_subaddiedialog();
    }
    if (func_80801394_subaddiedialog(arg0, sp34, arg2->unk0) != 0)
    {
        var_a2 = arg2->unk12;
        if (func_800F64A4(func_800F54E4(), arg2->unk8) == 0)
        {
            return 0U;
        }
        if (sp34 & 0x20)
        {
            var_a2 |= 1;
        }
        if (func_80800000_subaddiedialog(arg1, arg2->unk2, var_a2) == 0)
        {
            return 0U;
        }
        if ((sp34 & 2) && (func_8080110C_subaddiedialog(arg1, (s32)arg2->unk2, (s32)arg2->unk17) == 0))
        {
            return 0U;
        }
        if ((sp34 & 4) && (func_8080118C_subaddiedialog(arg1, arg0->rotation[1], arg2->unk2, arg2->unk17) == 0))
        {
            return 0U;
        }
        if ((!(sp34 & 1)) && (func_800F4B8C(func_800F54E4(), -1U, (s32)arg2->unk12) == 0))
        {
            return 0U;
        }
        var_a2 = arg2->unk14;
        if (!(sp34 & 0x10))
        {
            var_a2 |= 2;
        }
        if (subaddiedialog_entrypoint_11(arg0->unk0, (u32)arg2->unk4, var_a2, arg1, (s16)((s32)arg2->unk10)) != 0)
        {
            func_808013E4_subaddiedialog(arg0, sp34, (u32)arg2->unk0);
            var_a2 = arg2->unk18;
            if (var_a2 != 0)
            {
                func_80102424(arg0, arg2->unk18);
            }
            return arg2->unk4;
        }
        return func_8080141C_subaddiedialog();
    }
    if (func_80801208_subaddiedialog(arg1, arg2->unk2, arg2->unk12, sp34) != 0)
    {
        if (func_800F64A4(func_800F54E4(), arg2->unk8) == 0)
        {
            return func_8080141C_subaddiedialog();
        }
        if ((sp34 & 2) && (func_8080110C_subaddiedialog(arg1, (s32)arg2->unk2, (s32)arg2->unk17) == 0))
        {
            return func_8080141C_subaddiedialog();
        }
        if ((sp34 & 4) && (func_8080118C_subaddiedialog(arg1, (s32)arg0->rotation[1], (s32)arg2->unk2, (s32)arg2->unk17) == 0))
        {
            return func_8080141C_subaddiedialog();
        }
        var_a2 = arg2->unk14;
        if (!(sp34 & 8))
        {
            var_a2 |= 3;
        }
        if (subaddiedialog_entrypoint_11(arg0->unk0, (u32)arg2->unk6, (u32)var_a2, arg1, (s16)((s32)arg2->unk10)) != 0)
        {
            if (arg2->unk18)
            {
                func_80102424(arg0, arg2->unk18);
            }
            return arg2->unk6;
        }
        return func_8080141C_subaddiedialog();
    }
    return 0U;
}

s32 subaddiedialog_entrypoint_8(Actor* arg0, f32* arg1, subaddiedialog_UnkStruct2* arg2, subaddiedialog_UnkStruct1* arg3, s32 arg4)
{
    s32 pad2;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 pad;
    u32 sp34;
    s32 temp_v0;
    s32 var_s1;
    u32 var_v0;
    s32 var_s0;
    sp48 = 0;
    sp44 = 0;
    sp40 = 0;
    sp3C = arg2->unkC;
    sp34 = func_800F54E4();
    var_s1 = 0;
    if (arg4 > 0)
    {
        do
        {

            if (((sp48 == 0) && (func_800F64A4(sp34, arg3[var_s1].TransformationType) != 0)) && (arg3[var_s1].unk6 == 1))
            {
                sp48 = arg3[var_s1].unk4;
            }
            if (((sp44 == 0) && (func_800F64A4(sp34, arg3[var_s1].TransformationType) != 0)) && (arg3[var_s1].unk6 == 2))
            {
                sp44 = arg3[var_s1].unk4;
            }
            if (((sp40 == 0) && (func_800F64A4(sp34, arg3[var_s1].TransformationType) != 0)) && (arg3[var_s1].unk6 == 3))
            {
                sp40 = arg3[var_s1].unk4;
            }
            var_s1 += 1;
        } while (var_s1 != arg4);
    }
    if (sp48 != 0)
    {
        var_s0 = arg2->unk8;
        if (func_80801394_subaddiedialog(arg0, sp3C, arg2->DialogFlag) != 0)
        {
            if (sp3C & 0x20)
            {
                var_s0 |= 1;
            }
            if (func_80800000_subaddiedialog(arg1, arg2->unk4, var_s0) == 0)
            {
                return 0;
            }
            if ((sp3C & 2) && (func_8080110C_subaddiedialog(arg1, arg2->unk4, arg2->unkD) == 0))
            {
                return 0;
            }
            if ((sp3C & 4) && (func_8080118C_subaddiedialog(arg1, arg0->rotation[1], arg2->unk4, arg2->unkD) == 0))
            {
                return 0;
            }
            if ((!(sp3C & 1)) && (func_800F4B8C(sp34, -1U, arg2->unk8) == 0))
            {
                return 0;
            }
            var_s0 = arg2->unkA;
            if (!(sp3C & 0x10))
            {
                var_s0 |= 2;
            }
            temp_v0 = func_808010C8_subaddiedialog(arg0, sp48, 1);
            sp48 = temp_v0;
            if (subaddiedialog_entrypoint_11(arg0->unk0, temp_v0, var_s0, arg1, arg2->unk6) != 0)
            {
                func_808013E4_subaddiedialog(arg0, sp3C, arg2->DialogFlag);
                temp_v0 = arg2->unkE;
                if (arg2->unkE != 0)
                {
                    func_80102424(arg0, temp_v0);
                }
                return sp48;
            }
            return func_8080141C_subaddiedialog();
        }
    }
    if (sp44 != 0)
    {
        if (func_80801208_subaddiedialog(arg1, arg2->unk4, arg2->unk8, sp3C) != 0)
        {
            if ((sp3C & 2) && (func_8080110C_subaddiedialog(arg1, arg2->unk4, arg2->unkD) == 0))
            {
                return func_8080141C_subaddiedialog();
            }
            if ((sp3C & 4) && (func_8080118C_subaddiedialog(arg1, arg0->rotation[1], arg2->unk4, arg2->unkD) == 0))
            {
                return func_8080141C_subaddiedialog();
            }
            var_s0 = arg2->unkA;
            if (!(sp3C & 8))
            {
                var_s0 |= 3;
            }
            sp44 = func_808010C8_subaddiedialog(arg0, sp44, 2);
            if (subaddiedialog_entrypoint_11(arg0->unk0, sp44, var_s0, arg1, (s16)(arg2->unk6)) != 0)
            {
                var_s0 = arg2->unkE;
                if (arg2->unkE != 0)
                {
                    func_80102424(arg0, var_s0);
                }
                return sp44;
            }
            return func_8080141C_subaddiedialog();
        }
        return 0;
    }
    var_v0 = 0;
    if (sp40 != 0)
    {
        if ((arg2->unk2 != 0) && (func_800DA298(arg2->unk2 ^ 0) == 0))
        {
            temp_v0 = arg2->unk8;
            if (sp3C & 0x20)
            {
                temp_v0 |= 1;
            }
            if (func_80800000_subaddiedialog(arg1, arg2->unk4, temp_v0) == 0)
            {
                return 0;
            }
            if ((sp3C & 2) && (func_8080110C_subaddiedialog(arg1, arg2->unk4, arg2->unkD) == 0))
            {
                return 0;
            }
            if ((sp3C & 4) && (func_8080118C_subaddiedialog(arg1, arg0->rotation[1], arg2->unk4, arg2->unkD) == 0))
            {
                return 0;
            }
            if ((!(sp3C & 1)) && (func_800F4B8C(sp34, -1U, arg2->unk8) == 0))
            {
                return 0;
            }
            var_s0 = arg2->unkA;
            if (!(sp3C & 0x10))
            {
                var_s0 |= 2;
            }
            sp40 = func_808010C8_subaddiedialog(arg0, sp40, 3);
            if (subaddiedialog_entrypoint_11(arg0->unk0, sp40, var_s0, arg1, arg2->unk6) != 0)
            {
                func_800DA544(arg2->unk2);
                var_s0 = arg2->unkE;
                if (arg2->unkE)
                {
                    func_80102424(arg0, var_s0);
                }
                return sp40;
            }
        }
        else
            if (func_80801208_subaddiedialog(arg1, arg2->unk4, arg2->unk8, sp3C) != 0)
            {
                if ((sp3C & 2) && (func_8080110C_subaddiedialog(arg1, arg2->unk4, arg2->unkD) == 0))
                {
                    return func_8080141C_subaddiedialog();
                }
                if ((sp3C & 4) && (func_8080118C_subaddiedialog(arg1, arg0->rotation[1], arg2->unk4, arg2->unkD) == 0))
                {
                    return func_8080141C_subaddiedialog();
                }
                var_s0 = arg2->unkA;
                if (!(sp3C & 8))
                {
                    var_s0 |= 3;
                }
                sp40 = func_808010C8_subaddiedialog(arg0, sp40, 3);
                if (subaddiedialog_entrypoint_11(arg0->unk0, sp40, var_s0, arg1, arg2->unk6) != 0)
                {
                    var_s0 = arg2->unkE;
                    if (arg2->unkE != 0)
                    {
                        func_80102424(arg0, var_s0);
                    }
                    return sp40;
                }
            }
        return func_8080141C_subaddiedialog();
    }
    return var_v0;
}


u8 subaddiedialog_entrypoint_9(Actor* arg0, s32 arg1, subaddiedialog_UnkStruct1* arg2, s32 arg3) {
    s32 var_s1;
    u32 temp_s2;
    temp_s2 = func_800F54E4();
    var_s1 = 0;
    if (arg3 > 0)
    {
        do
        {
            if ((func_800F64A4(temp_s2, arg2[var_s1].TransformationType) != 0) && (func_808010C8_subaddiedialog(arg0, arg2[var_s1].unk4, arg2[var_s1].unk6) == arg1))
            {
                return arg2[var_s1].unk6;
            }
            var_s1 += 1;
        } while (var_s1 != arg3);
    }
    return 0U;
}

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

s32 func_808010C8_subaddiedialog(Actor* a0, s32 arg1, s32 arg2)
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
    //If B button is being held
    if (func_80016B30(0U, 1U) != 1)
    {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, arg2);
}

u32 subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4)
{
    return func_800C0534(DialogId, arg2, CameraTarget, arg0, 0, 0, 0, arg4);
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

/// Get the value of dialog flag
s32 func_80801394_subaddiedialog(Actor* arg0, s32 arg1, s32 Flag)
{
    s32 var_v0;

    if (arg1 & 0x40)
    {
        return arg0->unk74_30 == 0;
    }
    if (Flag)
    {
    }
    var_v0 = (Flag != 0) != 0;
    if (var_v0)
    {
        var_v0 = func_800DA298(Flag) == 0;
        return var_v0;
    }
}

/// Set Dialog Flag True
void func_808013E4_subaddiedialog(Actor* actor, s32 arg1, u32 Flag) {
    if (arg1 & 0x40)
    {
        actor->unk74_30 = 1;
        return;
    }
    func_800DA544(Flag);
}

s32 func_8080141C_subaddiedialog(void)
{
    func_800F5FE0(func_800F54E4());
    return 0;
}

s32 subaddiedialog_entrypoint_16(void)
{
    u32 temp_v0;

    if (func_800DB9B0() != 0)
    {
        return 0;
    }
    temp_v0 = func_800F54E4();
    if ((temp_v0 == -1U) || (func_800F6438(temp_v0) == 0))
    {
        return 0;
    }
    if (func_800F6774(temp_v0) == 0)
    {
        return 0;
    }
    if (func_800C0638() != 0)
    {
        return 0;
    }
    return 1;
}
