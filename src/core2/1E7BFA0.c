#include "core2/1E7BFA0.h"

extern f32 D_80119340[][3];
extern f32 D_80119430[][2];
extern f32 D_801194D0[];
extern f32 D_80125560;
extern f32 D_80125564;
extern f32 D_80125568;

s32 func_800A26B0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A26B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A275C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A300C.s")

s32 func_800A3040() 
{
    return sizeof(ba_unkA0_s);
}

f32 player_getSpeedModifier(PlayerState* self)
{
    if (!cheat_isActive(CHEAT_7_SUPERBANJO))
    {
        return 1.0f;
    }
    if (player_wearingClawClambers(self) != 0)
    {
        return D_80125560;
    }
    return D_801194D0[self->unkA0->transformation];
}

void func_800A30B4(PlayerState* self, f32* arg1, f32* arg2)
{
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 temp_f0;

    func_800A3148(self, &sp24, &sp20, &sp1C);
    temp_f0 = sp1C * 0.5f;
    ml_vec3f_assign_value(arg1, -sp24, sp20 - temp_f0, -sp24);
    ml_vec3f_assign_value(arg2, sp24, sp20 + temp_f0, sp24);
}

void func_800A3148(PlayerState* self, f32* arg1, f32* arg2, f32* arg3)
{
    f32 temp_f0;
    u8 temp_v1;

    temp_v1 = self->unkA0->transformation;
    *arg1 = D_80119340[temp_v1][0];
    *arg2 = D_80119340[temp_v1][1];
    *arg3 = D_80119340[temp_v1][2];
    switch (temp_v1)
    {
    case 2:
        temp_f0 = _basnowball_entrypoint_4(self);
        *arg1 *= temp_f0;
        *arg2 *= temp_f0;
        *arg3 *= temp_f0;
        return;
    case 9:
        _bsfirstp_entrypoint_6();
        return;
    }
}

void func_800A3200(PlayerState* self, f32* arg1, f32* arg2)
{
    f32 temp_f0;
    u8 temp_v0;

    temp_v0 = self->unkA0->transformation;
    *arg1 = D_80119430[temp_v0][0];
    *arg2 = D_80119430[temp_v0][1];
    if (temp_v0 == 2)
    {
        temp_f0 = _basnowball_entrypoint_4(self);
        *arg1 *= temp_f0;
        *arg2 *= temp_f0;
    }
}

TransformationId player_getTransformation(PlayerState* self)
{
    return (TransformationId)self->unkA0->transformation;
}

s32 func_800A3280(PlayerState* self)
{
    return (s32)self->unkA0->unk2A;
}

f32 func_800A328C(PlayerState* self)
{
    return self->unkA0->unk48;
}

f32 func_800A3298(PlayerState* self)
{
    return self->unkA0->unk48 - player_getWaterHeight(self);
}

void func_800A32C4(PlayerState* self, f32* arg1) { ml_vec3f_copy(arg1, self->unkA0->unk0); }

u8 func_800A32EC(PlayerState* self)
{
    return self->unkA0->unk2B;
}

Unk80132ED0* func_800A32F8(PlayerState* self)
{
    return self->unkA0->unk44;
}

s32 bs_isBKTogether(PlayerState* self)
{
    return bs_getSplitStatus() == SPLIT_STATE_NOTSPLIT;
}

void func_800A3328(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(arg1, self->unkA0->unk2C);
}

u8 func_800A3354(PlayerState* self)
{
    return self->unkA0->unk54;
}

u8 func_800A3360(PlayerState* self)
{
    return self->unkA0->unk55;
}

u8 func_800A336C(PlayerState* self)
{
    return self->unkA0->unk3C;
}

f32 func_800A3378(PlayerState* self)
{
    return self->unkA0->unk38 * 1;
}

f32 func_800A3394(PlayerState* self)
{
    return self->unkA0->unk24;
}

void func_800A33A0(PlayerState* self, f32* arg1) { ml_vec3f_copy(arg1, self->unkA0->unkC); }

void func_800A33CC(PlayerState* self, f32* arg1) { ml_vec3f_copy(arg1, self->unkA0->unk18); }

u8 func_800A33F8(PlayerState* self)
{
    return self->unkA0->unk28;
}

u8 func_800A3404(PlayerState* self)
{
    return self->unkA0->unk3F;
}

void player_setTransformation(PlayerState* self, TransformationId nextTransform)
{
    ba_unkA0_s* var_v0;

    var_v0 = self->unkA0;
    if (var_v0->transformation == TRANSFORM_A_BANJO)
    {
        func_800947EC(self, 1, 0);
        func_800A0D68(self, 0);
        var_v0 = self->unkA0;
    }
    var_v0->transformation = nextTransform;
    if (self->unkA0->transformation == TRANSFORM_A_BANJO)
    {
        func_800947EC(self, 1, 1);
        func_800A0D68(self, 1);
    }
}

void func_800A34A0(PlayerState* self, s32 arg1)
{
    self->unkA0->unk2A = arg1;
}

void func_800A34AC(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(self->unkA0->unk0, arg1);
}

void func_800A34CC(PlayerState* self, s32 arg1)
{
    self->unkA0->unk2B = arg1;
}

void func_800A34D8(PlayerState* self, s32 arg1)
{
    self->unkA0->unk44 = arg1;
}

void func_800A34E4(PlayerState* self, s32 arg1)
{
    self->unkA0->unk3C = arg1;
}

void func_800A34F0(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(self->unkA0->unkC, arg1);
}

void func_800A3514(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(self->unkA0->unk18, arg1);
}

void func_800A3538(PlayerState* self, s32 arg1)
{
    self->unkA0->unk28 = arg1;
}

void func_800A3544(PlayerState* self, s32 arg1)
{
    self->unkA0->unk3F = arg1;
}

void func_800A3550(PlayerState* self, s32 arg1)
{
    self->unkA0->unk50 = arg1;
}

void func_800A355C(PlayerState* self)
{
    f32 sp24;
    s32 sp20;
    ba_unkA0_s* temp_v0;

    sp24 = player_getCoordVertical(self);
    sp20 = func_800F3ED0(self);
    if ((player_isStable(self) != 0) || (player_inWater(self) != 0) || ((sp20 == 0xA) && (func_8008EF3C(self, 0) != 3)) || (sp20 == 5))
    {
        func_800A3550(self, 1);
    }
    else
    {
        func_800A3550(self, 2);
    }
    temp_v0 = self->unkA0;
    if ((temp_v0->unk50 != 2) || !(sp24 <= temp_v0->unk4C))
    {
        temp_v0->unk48 = temp_v0->unk4C;
        self->unkA0->unk4C = sp24;
    }
}

void func_800A3644(PlayerState* self)
{
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = time_getDelta();
    sp38 = func_800963E4(self);
    sp30 = func_80096628(self);
    if (self->unkA0->unk3D != 0)
    {
        self->unkA0->unk38 = sp38 > 35.0f ? 1.0f : 0.0f;
    }
    else
    {
        sp3C = ml_map_f(sp38, 20.0f, 60.0f, 0.6f, D_80125564);
        if ((func_80096518(self) == 0) && !(sp30 & 0x50))
        {
            sp2C = func_80096434(self);
            if ((func_8009650C(self) != 0) && (sp2C & 0x50))
            {
                sp30 = sp2C;
            }
        }
        if ((sp30 & 0x50) && (player_inWater(self) == 0))
        {
            self->unkA0->unk38 = ml_min_f(self->unkA0->unk38 + (sp34 * sp3C), 1.0f);
        }
        else
        {
            self->unkA0->unk38 = 0.0f;
        }
        if (self->unkA0->unk38 == 1.0f)
        {
            if (sp30 & 0x10)
            {
                bastatetimer_set(self, BA_STATE_TIMER_ID_5_UNKNOWN, 0.18f);
            }
            else if (sp30 & 0x40)
            {
                bastatetimer_set(self, BA_STATE_TIMER_ID_6_UNKNOWN, 0.18f);
            }
        }
    }
    self->unkA0->unk3D = 0;
}

void func_800A380C(PlayerState* self)
{
    self->unkA0->unk38 = D_80125568;
}

void func_800A3820(PlayerState* self)
{
    f32 temp_f0;

    ml_vec3f_clear(self->unkA0->unk0);
    ml_vec3f_clear(self->unkA0->unkC);
    player_getCoords(self, self->unkA0->unk2C);
    self->unkA0->unk3D = 0;
    self->unkA0->unk38 = 0.0f;
    func_800A380C(self);
    self->unkA0->unk3C = 1;
    self->unkA0->unk40 = 0.0f;
    self->unkA0->unk50 = 0;
    temp_f0 = player_getCoordVertical(self);
    self->unkA0->unk48 = temp_f0;
    self->unkA0->unk4C = temp_f0;
    self->unkA0->transformation = 0;
    player_setTransformation(self, func_8009E958());
    self->unkA0->unk54 = 1;
    self->unkA0->unk55 = 1;
    self->unkA0->unk3E = 1;
}

void func_800A38F0(PlayerState* self, s32 arg1, s32 arg2)
{
    self->unkA0->unk54 = (u8)arg1;
    self->unkA0->unk55 = (u8)arg2;
}

void func_800A3904(PlayerState* self, s32 arg1)
{
    self->unkA0->unk3E = (u8)arg1;
}

void func_800A3910(PlayerState* self, s32 arg1)
{
    self->unkA0->unk3D = arg1;
}

void func_800A391C(PlayerState* self, f32 arg1)
{
    self->unkA0->unk24 = arg1;
}

s32 func_800A392C(PlayerState* self, s32 arg1)
{
    f32 sp2C[3];

    player_getCoords(self, sp2C);
    return func_800C05B8(arg1, 2, sp2C, NULL, 0, 0, 0);
}

s32 func_800A3970(PlayerState* self, s32 arg1)
{
    if (self->unkA0->unk40 != 0.0f)
    {
        return 0;
    }
    self->unkA0->unk40 = 10.0f;
    if (player_getTransformation(self) == TRANSFORM_11_CLOCKWORK)
    {
        func_8009E7C8(self, 0x1F);
    }
    if (arg1 != 0)
    {
        return func_800A392C(self, arg1);
    }
    switch (player_getTransformation(self))
    {
    case TRANSFORM_A_BANJO:
        return func_800A392C(self, 0x1212);
    case TRANSFORM_B_KAZOOIE:
        return func_800A392C(self, 0x1213);
    case TRANSFORM_D_MUMBO:
        return func_800A392C(self, 0x1214);
    case TRANSFORM_11_CLOCKWORK:
        return func_800A392C(self, 0x1216);
    default:
        return func_800A392C(self, 0x1217);
    }
}

void func_800A3A80(PlayerState* self)
{
    ba_unkA0_s* temp_v0;

    temp_v0 = self->unkA0;
    if (temp_v0->unk40 != 0.0f)
    {
        timer_reachedZero(&temp_v0->unk40);
    }
    if (player_isStable(self) != 0)
    {
        player_getCoords(self, self->unkA0->unk2C);
    }
    if ((player_isStable(self) != 0) || (func_8009E71C(self, 0xA) != 0))
    {
        baflag_clear(self, BA_FLAG_5_HAS_PECKED);
        baflag_clear(self, BA_FLAG_12_HAS_FLAPPED);
    }
    if (player_inWater(self) != 0)
    {
        baflag_clear(self, BA_FLAG_5_HAS_PECKED);
        baflag_clear(self, BA_FLAG_12_HAS_FLAPPED);
    }
    func_800A3644(self);
    func_800A355C(self);
    if (func_80096568(self, 0x600) != 0)
    {
        func_8009BD18(self, 0.75f);
    }
}