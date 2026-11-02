#include "ba/duo.h"

void baduo_entrypoint_7(PlayerState*, s32);
void baduo_entrypoint_10(PlayerState*, s32);
void baduo_entrypoint_11(PlayerState*, s32);
void func_80800C78_baduo(PlayerState*, s32);
void func_80800CA8_baduo(PlayerState*, PlayerState*);

s32 baduo_entrypoint_0() 
{
    return sizeof(BaDuo);
}

void func_80800008_baduo(PlayerState* self, PlayerState* arg1)
{
    func_801100E4(func_800A4C88(arg1), func_800A4C88(self));
}
s32 baduo_entrypoint_1(PlayerState* self) {
    return self->duo->unk0;
}

s32 duo_getOtherCharacter(PlayerState* self)
{
    switch (player_getTransformation(self))
    {
        case TRANSFORM_A_BANJO:
            return _character_findCharOfTransform(TRANSFORM_B_KAZOOIE);
        case TRANSFORM_B_KAZOOIE:
            return _character_findCharOfTransform(TRANSFORM_A_BANJO);
        default:
            return 0;
    }
}

s32 baduo_entrypoint_3(PlayerState* self)
{
    return self->duo->unk1;
}

s32 baduo_entrypoint_4(PlayerState* arg0) {
    return arg0->duo->unk2;
}

void baduo_entrypoint_5(PlayerState* self)
{
}

void baduo_entrypoint_6(PlayerState* self)
{
    TransformationId temp_v0;

    self->duo->unk1 = 0;
    baduo_entrypoint_11(self, 0);
    self->duo->unk4 = 0;
    ml_vec3f_clear(self->duo->unk8);
    self->duo->unk0 = 0;
    temp_v0 = player_getTransformation(self);
    if ((temp_v0 == TRANSFORM_A_BANJO) || (temp_v0 == TRANSFORM_B_KAZOOIE))
    {
        if (bs_getSplitStatus() == SPLIT_STATE_SPLIT)
        {
            baduo_entrypoint_7(self, 3);
            return;
        }
        baduo_entrypoint_7(self, 1);
        return;
    }
    baduo_entrypoint_7(self, 1);
}

void baduo_entrypoint_7(PlayerState* self, s32 arg1)
{
    self->duo->unk0 = (u8)arg1;
    switch (self->duo->unk0)
    {
    case 1:
        baduo_entrypoint_11(self, 0);
        func_8009ADF0(self, 2, 0);
        return;
    case 2:
        baduo_entrypoint_10(self, 0);
        baduo_entrypoint_11(self, 1);
        return;
    case 3:
        if (func_8008DAA8(self) != 0)
        {
            func_800A38F0(self, 1, 1);
        }
        else
        {
            func_800A38F0(self, 0, 1);
        }
        func_8009ADF0(self, 2, 1);
        return;
    case 4:
        _bashoes_entrypoint_6(self, 1);
        func_800F82D4(character_getActiveIndex(), 2);
        return;
    }
}

void baduo_entrypoint_8(PlayerState* self, f32* arg1)
{
    ml_vec3f_copy(self->duo->unk8, arg1);
}

void baduo_entrypoint_9(PlayerState* self, f32 arg1)
{
    self->duo->unk4 = arg1;
}

void baduo_entrypoint_10(PlayerState* self, s32 arg1) {
    self->duo->unk1 = arg1;
}

void baduo_entrypoint_11(PlayerState* self, s32 arg1)
{
    self->duo->unk2 = arg1;
}

void baduo_entrypoint_12(PlayerState* self)
{
    if (func_8008E39C(self))
    {
        _bashoes_entrypoint_6(self, 2);
    }
    func_800F9A6C();
}

void baduo_entrypoint_13(PlayerState* self)
{
    u32 activeIndex;
    s32 pad;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30;
    activeIndex = character_getActiveIndex();
    switch (self->duo->unk0)
    {
    case 3:
        if ((player_getTransformation(self) == TRANSFORM_A_BANJO) && (player_shouldRejoin(self) != 0))
        {
            baduo_entrypoint_7(self, 4);
            return;
        }
        return;
    case 4:
        if (func_800F5B0C(activeIndex) == 2)
        {
            sp30 = duo_getOtherCharacter(self);
            if (activeIndex == self->unk184)
            {
                func_800F8EBC(_character_findCharOfTransform(TRANSFORM_B_KAZOOIE));
            }
            else
            {
                func_800F8EBC(self->unk184);
            }
            if (activeIndex == self->unk184)
            {
                func_800F82D4((s32)activeIndex, 0);
            }
            else
            {
                func_800F82D4((s32)activeIndex, 0);
                func_800F82D4(self->unk184, 0);
            }
            _bapackctrl_entrypoint_5(self, 1);
            func_800F911C(1);
            func_800F80D8((u32)self->unk184);
            func_800D5034(player_getTransformation(self), TRANSFORM_1_BK);
            player_setTransformation(self, TRANSFORM_1_BK);
            func_800F8268(self->unk184, 0, 1);
            if (activeIndex != self->unk184)
            {
                func_80800008_baduo(character_getPlayerState(sp30), character_getPlayerState(self->unk184));
            }
            sp4C = yaw_get(self);
            character_getCoords(sp30, sp34);
            player_getCoords(self, sp40);
            func_800F759C(sp30);
            func_800A38F0(self, 1, 1);
            func_800A91A8(self->unk184);
            baduo_entrypoint_7(self, 1);
            if (mlAbsF(func_800F1F0C(sp40, sp34, sp4C)) > 90.0f)
            {
                bs_setState(self, 0x69);
            }
            else
            {
                bs_setState(self, 0x6A);
            }
            event_sendToActorsOfType(PROP_158_SWAP_CLOUD, 0x17, 0);
        }
        break;
    }
}

void baduo_entrypoint_14(PlayerState* self, f32* arg1)
{
    s32 sp24;
    PlayerState* temp_v0_2;

    sp24 = character_createNew(self->unk184);
    temp_v0_2 = character_getPlayerState(sp24);
    func_800F452C(temp_v0_2, arg1);
    player_setTransformation(temp_v0_2, TRANSFORM_11_CLOCKWORK);
    func_80092778(temp_v0_2);
    func_80800008_baduo(self, temp_v0_2);
    _bababykaz_entrypoint_8(temp_v0_2);
    bs_setState(temp_v0_2, 0x139);
    yaw_set(temp_v0_2, yaw_get(self));
    yaw_setIdeal(temp_v0_2, yaw_getIdeal(self));
    _bababykaz_entrypoint_10(temp_v0_2, self->unk184);
    _bsfirstp_entrypoint_28(self, temp_v0_2);
    func_800A91A8(sp24);
    func_800A38F0(self, 0, 1);
}

void baduo_entrypoint_15(PlayerState* self, f32* arg1)
{
    s32 sp4C;
    PlayerState* temp_s2;
    PlayerState* temp_v0_2;
    s32 var_s0;
    f32 sp34[3];


    sp4C = character_createNew(self->unk184);
    temp_v0_2 = character_getPlayerState(sp4C);
    func_800F452C(temp_v0_2, arg1);
    player_setTransformation(temp_v0_2, TRANSFORM_11_CLOCKWORK);
    func_80092778(temp_v0_2);
    _bababykaz_entrypoint_8(temp_v0_2);
    func_80800008_baduo(self, temp_v0_2);
    temp_s2 = func_800A4CA8(temp_v0_2);
    player_getCoords_Dupe(self, sp34);
    if (ml_vec3f_distance_sq(arg1, sp34) > 1000000.0f)
    {
        for (var_s0 = 0; var_s0 < 0x3C; var_s0++)
        {
            func_80110588(temp_s2);
        }
    }
    bs_setState(temp_v0_2, 0x136);
    func_800F8128(sp4C);
    func_800A38F0(self, 0, 1);
    func_800F8EE4(self->unk184);
    bs_setState(self, _badrone_entrypoint_29(self));
    _sudialog_entrypoint_0(0xE8, 0xC);
    func_80800C78_baduo(temp_v0_2, 0x11);
    func_80800CA8_baduo(self, temp_v0_2);
    func_800F86C4(temp_v0_2->unk184, 0x11);
}

void baduo_entrypoint_16(PlayerState* self)
{
    s32 sp24;
    PlayerState* temp_s0;

    sp24 = character_createNew(self->unk184);
    temp_s0 = character_getPlayerState(sp24);
    yaw_setIdeal(self, yaw_get(self));
    yaw_setIdeal(temp_s0, yaw_get(self));
    yaw_applyIdeal(temp_s0);
    bs_setState(temp_s0, 0xBA);
    func_80800008_baduo(self, temp_s0);
    baduo_entrypoint_7(temp_s0, 2);
    baduo_entrypoint_7(self, 2);
    func_800F911C(2);
    func_800F9098(0xA, self->duo->unk8);
    func_800F90EC(self->duo->unk4);
    func_800D5034(TRANSFORM_1_BK, TRANSFORM_A_BANJO);
    func_800D5034(TRANSFORM_1_BK, TRANSFORM_B_KAZOOIE);
    func_800F8EE4(sp24);
    func_800F8128(self->unk184);
    event_sendToActorsOfType(PROP_158_SWAP_CLOUD, 0x16, 0);
}

void baduo_entrypoint_17(PlayerState* self, f32* arg1)
{
    s32 pad;
    PlayerState* sp28;
    f32 sp1C[3];

    player_getCoords(self, sp1C);
    sp28 = character_getPlayerState(character_createNew(self->unk184));
    func_800F452C(sp28, arg1);
    bs_setState(sp28, BS_STATE_1_IDLE);
    func_800F45B0(sp28, 2, sp1C);
}

void baduo_entrypoint_18(PlayerState* self, f32* arg1)
{
    s32 sp24;
    PlayerState* temp_v0_2;

    sp24 = character_createNew(self->unk184);
    temp_v0_2 = character_getPlayerState(sp24);
    func_800F452C(temp_v0_2, arg1);
    player_setTransformation(temp_v0_2, TRANSFORM_D_MUMBO);
    func_80092778(temp_v0_2);
    bs_setState(temp_v0_2, BS_STATE_E5);
    func_80800008_baduo(self, temp_v0_2);
    func_800A38F0(self, 0, 1);
    func_800F8128(sp24);
    func_800F8EE4(self->unk184);
    func_800F45B0(self, 2, arg1);
    yaw_setIdeal(temp_v0_2, 0.0f);
    yaw_applyIdeal(temp_v0_2);
    func_80800C78_baduo(temp_v0_2, 0xD);
    func_80800CA8_baduo(self, temp_v0_2);
    func_8009DB04(self, 0x5A2, 0.9f, 0x6D60);
}

void baduo_entrypoint_19(PlayerState* self)
{
    s32 sp24;

    sp24 = _character_findCharOfTransform(TRANSFORM_D_MUMBO);
    func_800F457C(self, 0);
    func_800A38F0(self, 1, 1);
    func_800F8EBC(self->unk184);
    func_80800008_baduo(character_getPlayerState(sp24), self);
    func_800F8128(self->unk184);
    func_80800CA8_baduo(character_getPlayerState(sp24), self);
    func_800F759C(sp24);
    func_80800C78_baduo(self, 1);
    func_8009DB04(self, 0x5A4, 0.9f, 0x6D60);
}

void baduo_entrypoint_20(PlayerState* self, f32* arg1, f32 arg2)
{
    s32 temp_v0;
    PlayerState* temp_v0_2;

    temp_v0 = character_createNew(self->unk184);
    temp_v0_2 = character_getPlayerState(temp_v0);
    func_800F452C(temp_v0_2, arg1);
    func_80800008_baduo(self, temp_v0_2);
    player_setTransformation(temp_v0_2, TRANSFORM_E_GOLDENGOLIATH);
    func_80092778(temp_v0_2);
    yaw_setIdeal(temp_v0_2, arg2);
    yaw_applyIdeal(temp_v0_2);
    _bsstatue_entrypoint_1(self);
    bs_setState(temp_v0_2, 0xF9);
    func_800F8128(temp_v0);
    func_800F8EE4(self->unk184);
    func_800F45B0(self, 2, arg1);
    func_800A38F0(self, 0, 1);
    _sudialog_entrypoint_0(0x50, 0xE);
    func_80800C78_baduo(temp_v0_2, 0xE);
    func_80800CA8_baduo(self, temp_v0_2);
}

void baduo_entrypoint_21(PlayerState* self)
{
    s32 sp34;
    PlayerState* currentState;
    f32 sp24[3];

    func_800F911C(3);
    sp34 = character_createNew(self->unk184);
    currentState = character_getPlayerState(sp34);
    player_getCoords(self, sp24);
    func_800F452C(currentState, sp24);
    player_setTransformation(self, TRANSFORM_A_BANJO);
    player_setTransformation(currentState, TRANSFORM_B_KAZOOIE);
    func_80092778(currentState);
    yaw_setIdeal(self, yaw_get(self));
    yaw_setIdeal(currentState, yaw_get(self));
    yaw_applyIdeal(currentState);
    func_800F80D8((u32)sp34);
    bs_setState(currentState, 0x153);
    func_800A91A8(sp34);
    func_80800008_baduo(self, currentState);
    func_800F8EE4(self->unk184);
    func_800A38F0(self, 0, 1);
    func_800D5234(1);
    func_800A16BC(1);
    func_800A1694();
    _bakaztorpedo_entrypoint_3(currentState);
}

void func_80800C78_baduo(PlayerState* self, s32 arg1)
{
    _surestart_entrypoint_0(arg1);
    func_800A1658(arg1);
}

void func_80800CA8_baduo(PlayerState* self, PlayerState* arg1)
{
    func_800D5034(player_getTransformation(self), player_getTransformation(arg1));
}
