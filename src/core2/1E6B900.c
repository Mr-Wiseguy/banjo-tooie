#include "core2/1E6B900.h"

extern u8* D_80117E30[];

extern u8 D_80117E3C[][2];

extern f32 D_80124D40;

s32 func_80092010(void)
{
	return 0x118;
}

void func_80092018(PlayerState* arg0)
{
    f32 sp34[3];
    f32 sp28[3];
    f32 var_f0;

    if (arg0->unk50->unkC4 != 0)
    {
        var_f0 = arg0->unk50->unkC8;
    }
    else
    {
        var_f0 = arg0->unk50->unk28;
    }
    ml_vec3f_assign_value(sp34, arg0->unk50->unk20, var_f0, arg0->unk50->unk24);
    ml_vec3f_sum(sp28, arg0->unk50->unk2C, arg0->unk50->unk44);
    func_80019CD4();
    func_80019750(arg0->unk50->unk44, &sp34, arg0->unk50->unk1C, sp28);
    if (arg0->unk50->unkC4 != 0)
    {
        mlMtxRotPitch(arg0->unk50->unk28);
    }
    mlMtxGet(&arg0->unk50->unkCC);
}

void func_800920C8(PlayerState* arg0)
{
    func_80093504(arg0, arg0->unk50->unk64, arg0->unk50->unk50);
}

void func_800920F0(PlayerState* arg0)
{
    switch (arg0->unk50->unk15)
    {
    case 2:
        arg0->unk50->unk28 = func_800136E4(yaw_get(arg0) + 180.0f);
        return;
    default:
        arg0->unk50->unk28 = yaw_get(arg0);
    case 3:
        return;
    }
}

void func_8009216C(PlayerState* arg0, f32* arg1, f32* arg2)
{
    BaUnknown50* temp_v0;
    func_800920F0(arg0);
    arg0->unk50->unk24 = baroll_get(arg0);
    arg0->unk50->unk20 = func_8009BFCC(arg0);
    temp_v0 = arg0->unk50;
    ml_vec3f_assign_value(arg2, temp_v0->unk20, temp_v0->unk28, temp_v0->unk24);
    player_getCoords(arg0, arg1);
}

void func_800921E0(PlayerState* arg0, s32 arg1, f32* arg2)
{
    func_8009C2A0(arg0->unk50->unk4, arg1,arg2);
    if (ml_vec3f_is_zero(arg2) != 0)
    {
        player_getCoords(arg0, arg2);
    }
}

void func_80092224(PlayerState* arg0)
{
    arg0->unk50->unk1A = 1;
}

void func_80092234(PlayerState* arg0)
{
    arg0->unk50->unk1A = 1;
    arg0->unk50->unk16 = 1;
}

u8 func_8009224C(PlayerState* arg0)
{
    return arg0->unk50->unk1A;
}

s32 func_80092258(PlayerState* arg0)
{
    s32 sp34;
    u8 sp33;
    s32 sp2C;
    f32 var_f20;
    BaUnknown50* temp_v0;

    temp_v0 = arg0->unk50;
    var_f20 = temp_v0->unk88 != 0 ? temp_v0->unk8C : temp_v0->unk14;
    if (func_8009AD78(arg0, 0xC) != 0)
    {
        sp33 = 0;
        if (func_80093DF4(arg0, 2) != 0)
        {
            sp2C = func_800A89F8();
            if (func_800A4C68(arg0) == sp2C)
            {
                sp33 = 1;
            }
        }
        var_f20 *= _bainvisible_entrypoint_2(arg0, sp33);
    }
    return (u32)var_f20 & 0xFF;
}

u8 func_8009239C(PlayerState* arg0)
{
    return arg0->unk50->unk19;
}

void func_800923A8(PlayerState* arg0, s32 arg1)
{
    u8 sp1F;
    BaUnknown50* temp_v0_2;
    s32 temp_v0;

    temp_v0 = func_80092258(arg0);
    sp1F = temp_v0;
    func_800A2540(arg0, temp_v0);
    func_800DF464(2.0f);
    if (arg1 != 0)
    {
        temp_v0_2 = arg0->unk50;
        if (temp_v0_2->unk16 == 0)
        {
            func_800DF738(temp_v0_2->unk4);
        }
    }
    func_800DF830(1);
    temp_v0_2 = arg0->unk50;
    if (temp_v0_2->unk88 != 0)
    {
        func_800DF5D8(temp_v0_2->unk89, temp_v0_2->unk8A, temp_v0_2->unk8B, sp1F);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092444.s")

void func_8009272C(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk11 = arg1;
}

s32 func_80092738(PlayerState* arg0)
{
    return arg0->unk50->unk11;
}

void func_80092744(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk88 = arg1;
}

void func_80092750(PlayerState* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    arg0->unk50->unk89 = arg1;
    arg0->unk50->unk8A = arg2;
    arg0->unk50->unk8B = arg3;
    arg0->unk50->unk8C = arg4;
}

void func_80092778(PlayerState* arg0)
{
    s16 sp1E;
    s16 sp1C;

    _bapreload_entrypoint_0(arg0, player_getTransformation(arg0), &sp1E, &sp1C);
    func_80092EC8(arg0, sp1E);
    func_8009312C(arg0, sp1C);
}

void func_800927C4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
    PlayerState* temp_s0;
    f32 sp28[3];
    f32 temp;

    if (character_existsAtIndex(arg4) != 0)
    {
        temp_s0 = character_getPlayerState(arg4);
        ml_vec3f_assign_value(sp28, arg1, arg2, arg3);
        temp_s0->unk50->unk84 = func_80108474(arg0, sp28, 0)->unk0;
        func_800A70D0(temp_s0->unk50->unk84, temp_s0->unk184);
        func_800A7108(temp_s0->unk50->unk84, temp_s0->unk50->unk78);
    }
}

void func_80092864(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk78 = arg1;
    arg0->unk50->unk7C = 1;
}

void func_80092880(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk80 = arg1;
    arg0->unk50->unk81 = 1;
}

void func_80092898(PlayerState* arg0)
{
    _babackpack_entrypoint_9(arg0);
    arg0->unk50->unk11 = 0;
    arg0->unk50->unk14 = 0xFF;
    arg0->unk50->unk10 = 0;
    arg0->unk50->unk16 = 0;
    arg0->unk50->unk12 = 0;
    arg0->unk50->unk13 = 0;
    arg0->unk50->unkC = 0;
    arg0->unk50->unkA2 = 0;
    arg0->unk50->unk9C = 0;
    func_800936E8(arg0, 0);
    func_80093700(arg0, 1);
    arg0->unk50->unk0 = func_800AE020();
    func_800AE6FC(func_800AE080(arg0->unk50->unk0), func_800E09B8(0xA));
    arg0->unk50->unk88 = 0;
    arg0->unk50->unk4 = func_800DBFF8();
    arg0->unk50->unk84 = 0;
    arg0->unk50->unk7C = 0;
    arg0->unk50->unk81 = 0;
    ml_vec3f_clear(arg0->unk50->unk2C);
    ml_vec3f_clear(&arg0->unk50->unk38);
    ml_vec3f_clear(arg0->unk50->unk44);
    arg0->unk50->unk28 = arg0->unk50->unk24 = arg0->unk50->unk20 = 0.0f;
    func_80093370(arg0, 1);
    func_8009337C(arg0, 1);
    func_80093230(arg0, 1.0f);
    arg0->unk50->unk15 = 0;
    func_800931AC(arg0, 1);
    func_80092778(arg0);
    func_80092864(arg0, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092A1C.s")

void func_80092AA4(PlayerState* arg0)
{
    arg0->unk50->unk84 = 0;
}

void func_80092AB0(PlayerState* arg0)
{
    func_800E0ACC(func_80092AD8(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092AD8.s")

void* func_80092B04(PlayerState* arg0, s32 arg1)
{
    void* temp_v0;

    if (arg0->unk50->unkC == 0x607)
    {
        return func_80093F7C(arg0);
    }
    temp_v0 = asset_load(arg0->unk50->unkC);
    if (arg1 == 0)
    {
        func_800D62E4(arg0->unk50->unkC, arg1, arg0);
    }
    return temp_v0;
}

s32 func_80092B80(PlayerState* arg0)
{
    return arg0->unk50->unkC;
}

f32 func_80092B8C(PlayerState* arg0, f32* arg1)
{
    ml_vec3f_copy(arg1, arg0->unk50->unk64);
    return arg0->unk50->unk70;
}

s32 func_80092BC4(PlayerState* arg0)
{
    return arg0->unk50->unkC4;
}

f32 func_80092BD0(PlayerState* arg0)
{
    return arg0->unk50->unkC8;
}

f32 func_80092BDC(PlayerState* arg0)
{
    return arg0->unk50->unk1C;
}

f32 func_80092BE8(PlayerState* arg0)
{
    return arg0->unk50->unk28;
}

f32 func_80092BF4(PlayerState* arg0)
{
    return arg0->unk50->unk2C[1];
}

void func_80092C00(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0, 0x1, arg1);
}

void func_80092C24(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0,0x2,arg1);
}

void func_80092C48(PlayerState* arg0,f32* arg1)
{
    func_800921E0(arg0,0x7,arg1);
}

void func_80092C6C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x6,arg1);
}

void func_80092C90(PlayerState* arg0, f32* arg1, s32 arg2)
{
    func_800DBEFC(arg0->unk50->unk4, arg2, arg1);
    if (ml_vec3f_is_zero(arg1) != 0)
    {
        player_getCoords(arg0, arg1);
    }
}

s32 func_80092CDC(PlayerState* arg0, f32* arg1, s32 arg2)
{
    func_800DBEFC(arg0->unk50->unk4, arg2, arg1);
    return ml_vec3f_is_not_zero(arg1);
}

void func_80092D18(PlayerState* arg0, f32* arg1)
{
    ml_vec3f_copy(arg1, arg0->unk50->unk44);
}

void func_80092D44(PlayerState* arg0, f32* arg1)
{
    f32 sp24[3];
    f32 sp18[3];

    func_800921E0(arg0, 4, &sp18);
    func_800921E0(arg0, 3, &sp24);
    ml_vec3f_sum(arg1, sp18, sp24);
    ml_vec3f_apply_scale(arg1, 0.5f);
}

void func_80092D9C(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0x3,arg1);
}

void func_80092DC0(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0x4,arg1);
}

void func_80092DE4(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0x8,arg1);
}

void func_80092E08(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0x9,arg1);
}

void func_80092E2C(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0xA,arg1);
}

s32 func_80092E50(PlayerState* arg0)
{
    return arg0->unk50->unk15;
}

void func_80092E5C(PlayerState* arg0,s32 arg1)
{
    func_800921E0(arg0,0x5,arg1);
}

void func_80092E80(PlayerState* arg0)
{
    func_800AE080(arg0->unk50->unk0);
}

s32 func_80092EA4(PlayerState* arg0)
{
    return arg0->unk50->unk17;
}

s32 func_80092EB0(PlayerState* arg0)
{
    return arg0->unk50->unk18;
}

void func_80092EBC(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk14 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80092EC8.s")

void func_80093070(PlayerState* arg0, s32 arg1, s32 arg2, u8* arg3)
{
    ImageStruct* sp34;
    ImageStruct* sp30;
    s32 sp2C;
    s32 sp20;
    u8 temp_v1;
    s32 temp_v0;

    sp34 = asset_load(arg2);
    sp30 = asset_load(arg1);
    temp_v0 = func_800A25D0(arg0);
    temp_v1 = *arg3;
    if (temp_v1 != 0)
    {
        func_80100E18(temp_v1);
    }
    *arg3 = func_80100D24(sp34, arg2, 1, temp_v0, 0, 0);
    sp2C = func_800B2840(sp34);
    func_800B25D8(func_80100A74(*arg3, 0), sp2C, sp30);
}

void func_8009312C(PlayerState* arg0, s32 arg1)
{
    if (arg1 != 0)
    {
        if (arg1 != arg0->unk50->unkE)
        {
            arg0->unk50->unkE = arg1;
            func_80093070(arg0, (s32)arg1, arg0->unk50->unkC, &arg0->unk50->unk12);
        }
    }
}

void func_8009316C(PlayerState* arg0, s32 arg1)
{
    if (arg1 != 0)
    {
        if (arg1 != arg0->unk50->unk9E)
        {
            arg0->unk50->unk9E = arg1;
            func_80093070(arg0, (s32)arg1, (s32)arg0->unk50->unk9C, &arg0->unk50->unkA0);
        }
    }
}

void func_800931AC(PlayerState* arg0, s32 arg1)
{
    if ((arg1 != arg0->unk50->unk15) && ((arg1 == 2) || (arg0->unk50->unk15 == 2)))
    {
        yaw_setIdeal(arg0, func_800136E4(yaw_get(arg0) + 180.0f));
        yaw_applyIdeal(arg0);
    }
    arg0->unk50->unk15 = (u8)arg1;
}

void func_80093230(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk1C = arg1;
    arg0->unk50->unk70 = arg0->unk50->unk5C * arg0->unk50->unk1C;
    arg0->unk50->unk74 = (arg0->unk50->unk60 * arg0->unk50->unk1C);
    ml_vec3f_apply_scale((f32*)arg0->unk50->unk64, arg0->unk50->unk1C);
}

void func_8009328C(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk28 = func_800136E4(arg1);
}

void func_800932BC(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unkC8 = arg1;
}

void func_800932CC(PlayerState* arg0, s32 arg1)
{
    if (arg1 != arg0->unk50->unkC4)
    {
        if (arg1 != 0)
        {
            arg0->unk50->unkC8 = 0.0f;
        }
        arg0->unk50->unkC4 = arg1;
    }
}

void func_80093300(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk2C[1] = arg1;
    func_8009332C(arg0, arg1);
}

void func_8009332C(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk3C = arg1;
}

void func_8009333C(PlayerState* arg0, f32* arg1)
{
    ml_vec3f_copy(arg0->unk50->unk44, arg1);
}

void func_80093360(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk44[1] = arg1;
}

void func_80093370(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk17 = arg1;
}

void func_8009337C(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk18 = arg1;
}

void func_80093388(PlayerState* arg0)
{
    f32 temp_f12;
    f32 temp_f0;

    temp_f12 = arg0->unk50->unk3C - arg0->unk50->unk2C[1];
    temp_f0 = mlAbsF(temp_f12);
    if (temp_f0 < D_80124D40)
    {
        arg0->unk50->unk2C[1] = arg0->unk50->unk3C;
        return;
    }
    else if (temp_f0 > 5.0f)
    {
        temp_f0 = 1.0f;
    }
    if (temp_f12 > 0.0f)
    {
        arg0->unk50->unk2C[1] += temp_f0;
    }
    else
    {
        arg0->unk50->unk2C[1] -= temp_f0;
    }
}

void func_80093448(PlayerState* arg0)
{
    s32 sp2C[3];

    if (arg0->unk50->unk84 == 0)
    {
        player_getCoords(arg0, &sp2C);
        _chbaddiesetup_entrypoint_5((s32)func_800927C4, 0x215, sp2C[0], sp2C[1], sp2C[2], arg0->unk184);
    }
    func_80093388(arg0);
    func_80092018(arg0);
    func_800920C8(arg0);
}

void func_800934C4(PlayerState* arg0)
{
    if (arg0->unk50->unk4 != 0)
    {
        arg0->unk50->unk4 = func_800DC060(arg0->unk50->unk4);
    }
}

void func_80093504(PlayerState* arg0, s32 arg1, s32 arg2)
{
    func_800F23D0(&arg0->unk50->unkCC, arg1, arg2);
}

void func_80093528(PlayerState* arg0)
{
    u8 temp_v1;

    arg0->unk50->unk1A = 0;
    func_800DBEB0(arg0->unk50->unk4);
    arg0->unk50->unk16 = 0;
    arg0->unk50->unkA5 = 0U;
    temp_v1 = arg0->unk50->unkA5;
    arg0->unk50->unkA1 = temp_v1;
    arg0->unk50->unk10 = temp_v1;
}

void func_80093584(PlayerState* arg0)
{
    arg0->unk50->unk94 = 0;
    arg0->unk50->unk8 = arg0->unk50->unk94;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_8009359C.s")

void func_800936CC(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unkA2 = arg1;
}

void func_800936D8(PlayerState* arg0, f32 arg1)
{
    arg0->unk50->unk98 = arg1;
}

void func_800936E8(PlayerState* arg0, s32 arg1) 
{
    arg0->unk50->unkA3 = arg1;
}

s32 func_800936F4(PlayerState* arg0)
{
    return arg0->unk50->unkA3;
}

void func_80093700(PlayerState* arg0, s32 arg1)
{
    arg0->unk50->unk19 = arg1;
}

void func_8009370C(PlayerState* arg0)
{
    func_800AE6BC(func_800AE080(arg0->unk50->unk90));
}

void func_80093738(PlayerState* arg0)
{
    asset_load(arg0->unk50->unk9C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_8009375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093AB8.s")

s32 func_80093DF4(PlayerState* arg0, s32 arg1)
{
    return arg1 == arg0->unk50->unkA2 ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80093FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800941C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_800942D0.s")

s32 func_80094340(void)
{
	return 0x4;
}

s32 func_80094348(PlayerState* arg0, s32 arg1)
{
    return arg0->unk64[2] & arg1 ? 1 : 0;
}
void func_80094370(PlayerState* arg0)
{
    func_800946C4(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094430.s")

s32 func_800944E0(PlayerState* arg0, s32 arg1)
{
    return D_80117E3C[arg1][0];
}

s32 func_800944F8(PlayerState* arg0, s32 arg1)
{
    return D_80117E3C[arg1][1];
}

//Return current egg type
s32 func_80094510(PlayerState* arg0)
{
    //arg0->unk64[0] is the index of the egg cycle pointer to reference. arg0->unk64[1] is the current egg cycle index
    return *(arg0->unk64[1] + D_80117E30[arg0->unk64[0]]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094644.s")

void func_800946C4(PlayerState* arg0, s32 arg1)
{
    switch (arg1)
    {
    case 0:
        func_800947EC(arg0, 1, 0);
        func_800947EC(arg0, 2, 0);
        func_800947EC(arg0, 4, 0);
        func_800947EC(arg0, 8, 0);
        break;
    case 1:
        func_800947EC(arg0, 1, 1);
        func_800947EC(arg0, 2, 1);
        func_800947EC(arg0, 4, 1);
        func_800947EC(arg0, 8, 0);
        break;
    case 2:
        func_800947EC(arg0, 1, 1);
        func_800947EC(arg0, 2, 1);
        func_800947EC(arg0, 4, 1);
        func_800947EC(arg0, 8, 0);
        break;
    }
    arg0->unk64[0] = (u8)arg1;
    arg0->unk64[1] = 0;
}

void func_800947EC(PlayerState* arg0, s32 arg1, s32 arg2)
{
    if (arg2 != 0)
    {
        arg0->unk64[2] |= arg1;
    }
    else
    {
        arg0->unk64[2] &= ~arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094824.s")

void func_80094864(PlayerState* arg0)
{
	s32 sp24;

	if (func_800F6774(arg0->unk184) != 0)
	{
		if (func_80094348(arg0, 0x10) != 0)
		{
			func_80094390(arg0);
		}
		if (func_80094348(arg0, 8) != 0)
		{
			sp24 = _gcegg_entrypoint_5(func_80094510(arg0));
			if (func_80094348(arg0, 4) == 0)
			{
				inventory_showValue(sp24);
			}
		}
		if (func_80094348(arg0, 1) == 0)
		{
			switch (arg0->unk64[3])
			{
			case 0:
				if (bainput_func_80097C7C(arg0) != 0)
				{
					arg0->unk64[3] = 1U;
					func_80094E40(func_80094510(arg0));
					func_80094C88(arg0);
					return;
				}
				break;
			case 1:
				func_80094824(arg0);
				if (func_80094DA8(arg0) != 0)
				{
					arg0->unk64[3] = 2U;
					func_80094C88(arg0);
					return;
				}
				break;
			case 2:
				func_80094824(arg0);
				if (func_80094DA8(arg0) == 0)
				{
					arg0->unk64[3] = 0U;
				}
				break;
			}
		}
	}
}

int func_800949BC(PlayerState* arg0)
{
	return func_8009E674(arg0, 0x80000) || (_bafpctrl_entrypoint_5(arg0) && _baeggfire_entrypoint_8(arg0));
}

s32 func_80094A10(PlayerState* arg0)
{
	s32 nextEggType;
	s32 startEggType;

	startEggType = func_80094510(arg0);
	if (func_800949BC(arg0) != 0)
	{
		return startEggType;
	}
	do
	{
		//arg0->unk64[1] points to the index in the egg cycle
		arg0->unk64[1]++;
		nextEggType = func_80094510(arg0);
		if (nextEggType == 0)
		{
			arg0->unk64[1] = 0U;
			nextEggType = func_80094510(arg0);
		}
	} //Returns true if we have the ability for the associated egg type
	while (_gcegg_entrypoint_6(nextEggType) == 0);

	if (nextEggType != startEggType)
	{
		func_80094E40(nextEggType);
	}
	return nextEggType;
}

void func_80094AB4(PlayerState* arg0)
{
	s32 eggType;
	if (func_80094348(arg0, 2) == 0)
	{
		eggType = func_80094C64(arg0, (s32)arg0->unk64[1]);
		if (eggType != 0)
		{
			//If egg type is unlocked
			if (_gcegg_entrypoint_6(eggType) != 0)
			{
				//Show amount of eggs we have of the given type
				inventory_showValue(_gcegg_entrypoint_5(eggType));
			}
		}
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094C0C.s")

//Get the egg type at the given index
s32 func_80094C64(PlayerState* arg0, s32 eggCycleIndex)
{
    return D_80117E30[arg0->unk64[0]][eggCycleIndex];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6B900/func_80094D04.s")

s32 func_80094DA8(PlayerState* arg0)
{
	s32 eggType;
	s32 eggCycleIndex;

	eggCycleIndex = 0;
	eggType = func_80094C64(arg0, 0);
	while (eggType != 0)
	{
		//If we have the egg type unlocked and the ui is being shown
		if ((_gcegg_entrypoint_6(eggType) != 0) && (func_800D27F4(func_800D1C5C(_gcegg_entrypoint_5(eggType))) == 0))
		{
			return 0;
		}
		eggCycleIndex += 1;
		eggType = func_80094C64(arg0, eggCycleIndex);
	}
	return 1;
}

void func_80094E40(s32 arg0)
{
    func_800FC660(_gcegg_entrypoint_2(arg0));
}
