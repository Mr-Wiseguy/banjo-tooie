#include "core2/1E66990.h"

extern f32 D_80124AD0;
extern f32 D_80124AD4;
extern f32 D_80124AE4;

//Can Beak Barge
int player_canBeakBarge(PlayerState* arg0)
{
	return ability_getValue(ABILITY_00_BK_BEAK_BARGE) && (bs_isBKTogether(arg0) != 0);
}

//Can Beak Bomb
int player_canBeakBomb(PlayerState* arg0)
{
	return ability_getValue(ABILITY_01_BK_BEAK_BOMB) && baflag_isFalse(arg0, 0x39) && (bs_isBKTogether(arg0) || player_getTransformation(arg0) == TRANSFORM_B_KAZOOIE);
}

//Can Beak Bust
int player_canBeakBust(PlayerState* arg0) {
	return ability_getValue(ABILITY_02_BK_BEAK_BUSTER) && (bs_isBKTogether(arg0) != 0);
}


int func_8008D18C(PlayerState* arg0)
{
	return ability_getValue(ABILITY_03_UNK);
}

//Can Peck
int player_canPeck(PlayerState* arg0) {
	return ability_getValue(ABILITY_04_BK_STANDING_PECK) && (bs_isBKTogether(arg0) != 0);
}

//Can Climb
int player_canClimb(PlayerState* arg0)
{
	return ability_getValue(ABILITY_05_BK_CLIMB_TREES);
}

//Can Dive
int player_canDive(PlayerState* arg0) {

	return ability_getValue(ABILITY_0F_BK_DIVING) && player_getWaterHeight(arg0) - player_getGroundHeight(arg0) > 100.0f;
}

//Can Use Eggs
s32 player_canEggShoot(PlayerState* arg0)
{
    enum transform_e temp_v0;

	if (ability_getValue(ABILITY_06_BK_USE_EGGS) == 0)
	{
        return 0;
    }
    if (flag_getValue(FLAG2_6B6_UNK) != 0)
    {
        return 0;
    }
    temp_v0 = player_getTransformation(arg0);
    if (((temp_v0 == TRANSFORM_1_BK) || (temp_v0 == TRANSFORM_A_BANJO)) && (bs_isBKTogether(arg0) == 0)) {
        return 0;
    }
    return 1;
}

//Can use feathery flap
int player_canFeatheryFlap(PlayerState* arg0) {
    return baflag_isFalse(arg0, BA_FLAG_12_HAS_FLAPPED)
        && baflag_isFalse(arg0, BA_FLAG_5_HAS_PECKED)
		&& ability_getValue(ABILITY_07_BK_FEATHERY_FLAP)
		&& bs_isBKTogether(arg0);
}

//Can use flap flip
int player_canFlapFlip(s32 arg0) {
	return ability_getValue(ABILITY_08_BK_FLAP_FLIP) && bs_isBKTogether(arg0);
}

//Can Fly
int player_canFly(PlayerState* arg0) {
	return baflag_isTrue(arg0, BA_FLAG_1_ON_FLIGHT_PAD) && ability_getValue(ABILITY_09_BK_FLYING) && character_includedInTransformMask(arg0->unk184, ALLOW_KAZOOIE | ALLOW_BK);
}

int player_shouldRejoin(PlayerState* self)
{
    f32 sp34[3];
    s32 sp30;
    f32 sp24[3];
    s32 pad;
    if ((bs_getSplitStatus() == SPLIT_STATE_SPLIT) && (_character_soloCharactersExist()))
    {
        if (func_8008E0C8(self))
        {
            return 0;
        }
        if (func_800F99E8())
        {
            return 0;
        }
        switch (bs_getCurrentState(self))
        {
        case 0xB9:
        case 0xBA:
            return 0;
        }
        sp30 = _duo_getOtherCharacter(self);
        if (!player_isStable(self) || !character_isStable(sp30))
        {
            return 0;
        }
        if (!func_800F6774(character_getActiveIndex()))
        {
            return 0;
        }
        player_getCoords(self, sp24);
        character_getCoords(_duo_getOtherCharacter(self), sp34);
        return ml_vec3f_distance_sq(sp24, sp34) < D_80124AD0;
    }
    return 0;
}

//Can Full Jump Height
s32 player_canFullJump(PlayerState* arg0)
{
	return ability_getValue(ABILITY_0A_BK_FULL_JUMP_HEIGHT);
}

//Can Pack Whack
int player_canPackWhack(PlayerState* arg0) {
	return ability_getValue(ABILITY_29_PACK_WHACK) != 0 && baflag_isFalse(arg0, BA_FLAG_5_HAS_PECKED) != 0 && baflag_isFalse(arg0, BA_FLAG_12_HAS_FLAPPED) != 0;
}

//Can Rat a Tat Rap
int player_canRataTatRap(PlayerState* arg0) {
    return baflag_isFalse(arg0, BA_FLAG_5_HAS_PECKED)
        && baflag_isFalse(arg0, BA_FLAG_12_HAS_FLAPPED)
		&& ability_getValue(ABILITY_0B_BK_RAT_A_TAT_RAP)
		&& bs_isBKTogether(arg0);
}

s32 func_8008D630(PlayerState* arg0) {
    if ((baflag_isTrue(arg0, BA_FLAG_14_LOSE_BOGGY_RACE) != 0) || (baflag_isTrue(arg0, BA_FLAG_19) != 0))
    {
        return 0;
    }
    if (bs_getCurrentState(arg0) == 0x56)
    {
        return 0;
    }
    return 1;
}

//Can Roll
int player_canRoll(s32 arg0)
{
	return ability_getValue(ABILITY_0C_BK_ROLL) && bs_isBKTogether(arg0);
}

//Can Shock Spring Jump
int player_canShockSpring(PlayerState* arg0) {
	return ability_getValue(ABILITY_0D_BK_SHOCK_SPRING_JUMP) && bs_isBKTogether(arg0);
}


int player_canSplitUp(PlayerState* arg0)
{
    return _baduo_entrypoint_3(arg0) && bs_isBKTogether(arg0);
}

//Can Wading Boots
int player_canWadingBoots(PlayerState* arg0) {
	return ability_getValue(ABILITY_0E_BK_WADING_BOOTS) && bs_isBKTogether(arg0);
}

int player_canSwap(PlayerState* arg0) {
    return _baduo_entrypoint_4(arg0)
        && func_8008E39C(arg0) == 0
        && player_isStable(arg0) != 0
        && func_800C954C() == 0
        && func_800DB9B0() == 0
        && func_800F8004(arg0->unk184) == 0
        && func_800F6D24(arg0->unk184) == 0
        && baflag_isFalse(arg0, 0x34) != 0;
}

//Can Talon Torpedo
s32 player_canTalonTorpedo(PlayerState* arg0)
{
    f32 sp1C[3];

	if ((ability_getValue(ABILITY_1E_TALON_TORPEDO) != 0) && (bs_isBKTogether(arg0) != 0) && (_bafpctrl_entrypoint_5(arg0) == 0))
	{
        player_getCoords(arg0, sp1C);
        //Restrict Talon Torpedo when in the waterfall
        if ((map_getCurrent() == MAP_117_TDL_RIVER_PASSAGE) && (sp1C[2] < D_80124AD4))
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

//Can Talon Trot
int player_canTalonTrot(PlayerState* arg0) {
	return ability_getValue(ABILITY_10_BK_TALON_TROT) && bs_isBKTogether(arg0);
}

//Can Talon Trot Duplicate?
int player_canTalonTrot_dupe(PlayerState* arg0) {
	return ability_getValue(ABILITY_10_BK_TALON_TROT) && bs_isBKTogether(arg0);
}

//Can Wonderwing
int player_canWonderwing(PlayerState* arg0) {
	return ability_getValue(ABILITY_12_BK_WONDERWING) && bs_isBKTogether(arg0);
}

s32 func_8008D9A4(PlayerState* arg0) {
    if (_ncba1p_entrypoint_10(func_800A4CA8(arg0)) == 3) {
        return 0;
    }
    if (func_800A4D40(arg0) == 0) {
        return 0;
    }
    if ((player_isStable(arg0) == 0) && (player_inWater(arg0) == 0)) {
        return 0;
    }
    return 1;
}

//Can Grip Grab
int player_canGripGrab(PlayerState* arg0) {
	return ability_getValue(ABILITY_14_GRIP_GRAB)
		&& baphysics_get_vertical_velocity(arg0) < 100.0f
        && player_isGrounded(arg0) == 0
        && func_800976DC(arg0) != 0;
}

s32 func_8008DAA8(PlayerState* arg0) {
    return func_800F65D0(arg0->unk184);
}

s32 func_8008DAC8(s32 arg0) {
    return func_800DB9B0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008DAE8.s")

int func_8008DC90(PlayerState* self, f32* arg1, f32 arg2)
{
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp18[2];

    player_getCoords(self, sp20);
    func_8008FF40(sp2C);
    func_800F18FC(sp20, arg1, sp18);
    return func_800F20BC(sp2C[0], sp18[0], arg2) && func_800F20BC(sp2C[1], sp18[1], arg2);
}

int func_8008DD04(PlayerState* self)
{
    return (player_getCoordVertical(self) - player_getGroundHeight(self)) > 60.0f
        && player_isStable(self) == 0;
}

s32 func_8008DD70(PlayerState* self)
{
    return func_8009E71C(self,0x5);
}

s32 func_8008DD90(PlayerState* self) {
    if (func_8009E674(self, 0x10) != 0)
    {
        return 1;
    }
    if (func_8009E674(self, 8) != 0) {
        return _badrone_entrypoint_1(self) == 0;
    }
    return 0;
}

s32 func_8008DDEC(PlayerState* arg0, f32* arg1, f32 arg2)
{
    f32 sp1C[3];

    player_getCoords(arg0, sp1C);
    return func_800F0064(arg1, arg2, sp1C);
}

s32 func_8008DE24(PlayerState* arg0)
{
    return func_80096568(arg0,0xE00);
}

s32 func_8008DE44(s32 arg0) {
    return 0;
}

s32 func_8008DE50(PlayerState* arg0) {
    return func_80096694(arg0) == 3;
}

s32 func_8008DE74(PlayerState* arg0) {
    return func_8009CA70(arg0, bs_getCurrentState(arg0), 0x4000);
}

int func_8008DEA4(PlayerState* arg0, f32* arg1, f32 arg2)
{
    f32 sp1C[3];

    player_getCoords(arg0, sp1C);
    return ((arg1[1] - arg2) <= sp1C[1]) && (sp1C[1] <= (arg1[1] + arg2));

}

int func_8008DF18(PlayerState* self)
{
	return bastatetimer_isActive(self, BA_STATE_TIMER_ID_6_UNKNOWN) || func_800A3378(self) == 1.0f && func_8009659C(self, 0x40);
}

int func_8008DF8C(PlayerState* arg0, s32 arg1)
{
	f32 sp24[3];

	if (player_isStable(arg0))
	{
		return 1;
	}
	func_800963C0(arg0, sp24);
	if ((sp24[1] < D_80124AE4) && (sp24[1] >= 0.0f))
	{
		return 0;
	}
	return baphysics_get_vertical_velocity(arg0) < 0.0f && (player_getCoordVertical(arg0) - player_getGroundHeight(arg0)) < (f32)arg1;
}

int player_isStable(PlayerState* self)
{
	return player_isGrounded(self) && (baphysics_get_vertical_velocity(self) < 0.0f);
}

s32 func_8008E0C8(PlayerState* self)
{
    return _bapackctrl_entrypoint_1(self);
}

int func_8008E0E8(PlayerState* self)
{
	return (player_isSplitUp(self) && !func_8008E0C8(self));
}

s32 func_8008E124(PlayerState* self) {
	return func_8009CC68(self) != 0;
}

int func_8008E148(PlayerState* self)
{
	return bastatetimer_isActive(self, BA_STATE_TIMER_ID_5_UNKNOWN) != 0 || func_800A3378(self) == 1.0f;
}

s32 func_8008E1A0(PlayerState* self) {
	return func_80096694(self) == 0x18;
}

int func_8008E1C4(PlayerState* self)
{
	s32 var_a2;
	s32 var_v0;
	s32 var_v0_2;

	var_a2 = func_8009659C(self, 0x10) && baflag_isFalse(self, BA_FLAG_3);
	var_v0_2 = func_8009659C(self, 0x40) && baflag_isFalse(self, BA_FLAG_4);
	if ((var_a2) || (var_v0_2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

s32 player_isSplitUp(PlayerState* self)
{
	return bs_getSplitStatus() == SPLIT_STATE_SPLIT;
}

s32 func_8008E260(PlayerState* self)
{
	s32 sp1C;

	if (player_isStable(self) != 0)
	{
		return 0;
	}
	if (func_800954E8(self, &sp1C) == 0)
	{
		return 0;
	}
	return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E66990/func_8008E2AC.s")

int func_8008E300(PlayerState* self) {
	return (mlAbsF(func_800F1DCC(yaw_getIdeal(self), yaw_get(self))) > 135.0f);
}

int player_inWater(PlayerState* self)
{
    return func_800A0FD8(self);
}

s32 func_8008E37C(PlayerState* self)
{
    return func_800A0FE4(self);
}

int func_8008E39C(PlayerState* self)
{
	s32 temp_v0;
	temp_v0 = _bashoes_entrypoint_1(self);
	return !(temp_v0 == 1) && !(temp_v0 == 0) && !(temp_v0 == SHOETYPE_NO_SHOES);
}

s32 player_wearingTurboTrainers(PlayerState* self) {
	return _bashoes_entrypoint_1(self) == SHOETYPE_TURBO_TRAINER;
}

s32 player_wearingClawClambers(PlayerState* self) {
	return _bashoes_entrypoint_1(self) == SHOETYPE_CLAW_CLAMBER;
}

s32 player_wearingSpringyStep(PlayerState* self) {
	return _bashoes_entrypoint_1(self) == SHOETYPE_SPRINGY_STEP;
}

s32 func_8008E454(PlayerState* self)
{
	f32 sp1C[3];

	if ((func_800DB9B0() != 0) && (func_800BFAA4() != 0))
	{
		player_getCoords(self, sp1C);
		return (_gcmapsects_entrypoint_4(sp1C) + 1) != 0;
	}
	return 1;
}