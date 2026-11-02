#include "bs/ban/sack.h"
extern s32 D_80801E10_bsbansack[];
extern s32 D_80801E20_bsbansack[];
extern s32 D_80801E30_bsbansack[];
extern s32 D_80801E40_bsbansack[];
extern s32 D_80801E50_bsbansack[];
extern s32 D_80801E60_bsbansack[];
extern s32 D_80801E70_bsbansack[];
extern s32 D_80801E80_bsbansack[];
extern s32 D_80801E90_bsbansack[];
extern s32 D_80801EA0_bsbansack[];

s32 func_80800000_bsbansack(PlayerState* self, BanjoStateId arg1, s32 arg2)
{
    if (arg2 != 0)
    {
        if (bakey_pressed(self, BUTTON_A) != 0)
        {
            arg1 = BS_STATE_169_SACK_JUMP;
        }
    }
    if (func_8008E148(self) != 0)
    {
        arg1 = BS_STATE_1_IDLE;
    }
    if (self->unk15C.bytes[3] == 0)
    {
        if (bakey_released(self, BUTTON_Z) != 0)
        {
            arg1 = BS_STATE_164_SACK_EXIT;
        }
    }
    return arg1;
}

BanjoStateId func_80800084_bsbansack(PlayerState* self, BanjoStateId arg1)
{
    if (bakey_pressed(self, BUTTON_A) != 0)
    {
        arg1 = BS_STATE_169_SACK_JUMP;
    }
    if (func_8008E148(self) != 0)
    {
        arg1 = BS_STATE_1_IDLE;
    }
    if (self->unk15C.bytes[3] == 0)
    {
        arg1 = arg1;
        arg1 = arg1;
        if (bakey_released(self, BUTTON_Z) != 0)
        {
            arg1 = BS_STATE_164_SACK_EXIT;
        }
    }
    return arg1;
}

void func_80800100_bsbansack(PlayerState* self, void (*arg1)(PlayerState*))
{
    switch (func_8009E6EC(self))
    {
    case 0x7F:
        self->unk15C.bytes[3] = 1;
        return;
    case 0x80:
        self->unk15C.bytes[3] = 0;
        return;
    default:
        arg1(self);
    case 0xC:
        return;
    }
}

void func_80800168_bsbansack(PlayerState* self)
{
    func_80800100_bsbansack(self, func_80099B94);
}

void func_8080018C_bsbansack(PlayerState* arg0)
{
    func_80800100_bsbansack(arg0, _bsdrone_entrypoint_3);
}

void func_808001B0_bsbansack(PlayerState* self, void)
{
    func_80800100_bsbansack(self, func_80099AA8);
}

void func_808001D4_bsbansack(PlayerState* arg0)
{
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == BS_STICK_ZONE_ID_0)
    {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, ml_mapNormal_f(sp1C, 100.0f, 500.0f));
}

void func_80800238_bsbansack(PlayerState* self)
{
    if (func_8009E74C(self, 0x12) != 0)
    {
        if (_babackpack_get_state(self) != 4)
        {
            func_800A0CD0(self, 0);
            _babackpack_set_state(self, 4);
        }
    }
    else
    {
        if (_babackpack_get_state(self) != 1)
        {
            _babackpack_set_state(self, 1);
        }
        func_800A0CD0(self, 1);
        bastick_popZone(self);
        func_800A1040(self);
    }
}

void func_808002D4_bsbansack(PlayerState* self)
{
    if (func_8009E77C(self, 0x12) == 0)
    {
        func_800A0CD0(self, 0);
        _babackpack_set_state(self, 4);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.12f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_800A106C(self, -10.0f, 10.0f);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        self->unk15C.bytes[3] = 0;
    }
}

void func_80800368_bsbansack(PlayerState* self)
{
    if (func_8008DF8C(self, 0x1E) != 0)
    {
        func_8009D2F0(self, 0, 0.5f);
        return;
    }
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

void func_808003C0_bsbansack(PlayerState* self)
{
    baphysics_set_gravity(self, 100.0f);
    baphysics_set_terminal_velocity(self, 133.33f);
    func_800961AC(self, 3);
}

void func_80800400_bsbansack(PlayerState* self)
{
    baphysics_reset_terminal_velocity(self);
    baphysics_reset_gravity(self);
    func_800961AC(self, 1);
}

void func_80800434_bsbansack(PlayerState* self)
{
    func_80800400_bsbansack(self);
    func_80800238_bsbansack(self);
}

void func_8080045C_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    baanim_playForDuration_loopSmooth(self, 0x28B, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
    func_808003C0_bsbansack(self);
}

void func_808004B0_bsbansack(PlayerState* self)
{
    BanjoStateId sp1C;

    sp1C = BS_STATE_0_INVALID;
    if (bastick_getZone(self) > 0)
    {
        sp1C = BS_STATE_166_SACK_WALK;
    }
    bs_setState(self, func_80800084_bsbansack(self, sp1C));
}

s32 bsbansack_entrypoint_0(s32 arg0)
{
    return D_80801E10_bsbansack[arg0];
}

void func_80800508_bsbansack(PlayerState* self)
{
    if (self->unk15C.bytes[2] == 0)
    {
        func_808002D4_bsbansack(self);
    }
    func_80800238_bsbansack(self);
}

void func_80800540_bsbansack(PlayerState* self)
{
    self->unk15C.bytes[2] = 0;
    baanim_playForDuration_onceSmooth(self, 0x143, 2.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009DE38(self, 0x583, 1.0f);
    bainput_enable(self, BA_INPUT_2_ENTER_FIRST_PERSON, 0);
}

void func_808005BC_bsbansack(PlayerState* self)
{
    AnimCtrl* sp24;
    BanjoStateId nextState;

    sp24 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    bainput_enable(self, BA_INPUT_2_ENTER_FIRST_PERSON, 1);
    if (anctrl_isAt(sp24, 0.19f) != 0)
    {
        func_8009DE38(self, 0x57C, 1.0f);
    }
    if (anctrl_isAt(sp24, 0.2f) != 0)
    {
        func_8009DBF0(self, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(sp24, 0.48f) != 0)
    {
        func_8009FE58(self);
    }
    if (anctrl_isAt(sp24, 0.52f) != 0)
    {
        func_8009DE38(self, 0x584, 1.0f);
    }
    if (anctrl_isAt(sp24, 0.123f) != 0)
    {
        func_800A0CD0(self, 0);
        _babackpack_set_state(self, 2);
    }
    if (anctrl_isAt(sp24, 0.5145f) != 0)
    {
        self->unk15C.bytes[2] = 1;
        func_808002D4_bsbansack(self);
    }
    if (baanim_isStopped(self) != 0)
    {
        nextState = BS_STATE_165_SACK_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_1(s32 arg0) {
    return D_80801E20_bsbansack[arg0];
}

void func_80800710_bsbansack(PlayerState* self)
{
    if (func_8009E6EC(self) == 0xC)
    {
        if (anctrl_getAnimTimer(baanim_getAnimCtrlPtr(self)) > 0.42f)
        {
            func_80099B94(self);
        }
    }
    else
    {
        func_80800168_bsbansack(self);
    }
}

void func_8080077C_bsbansack(PlayerState* self)
{
    baphysics_reset_gravity(self);
    func_80800238_bsbansack(self);
}
void func_808007A4_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    baanim_playForDuration_onceSmooth(self, 0x28A, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_gravity(self, -800.0f);
    baphysics_set_vertical_velocity(self, 300.0f);
}
void func_80800810_bsbansack(PlayerState* self)
{
    AnimCtrl* temp_v0;
    BanjoStateId nextState;
    s32 temp;


    temp_v0 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    if (anctrl_isAt(temp_v0, 0.2f) != 0)
    {
        func_8009DE38(self, 0x583, 1.1f);
    }
    if (anctrl_isAt(temp_v0, 0.2f) != 0)
    {
        func_8009DBF0(self, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(temp_v0, 0.73f) != 0)
    {
        func_8009FE58(self);
    }
    if (anctrl_isAt(temp_v0, 0.77f) != 0)
    {
        func_8009DE38(self, 0x584, 1.1f);
    }
    if (anctrl_getAnimTimer(temp_v0) < 0.515f)
    {
        func_808001D4_bsbansack(self);
    }
    else
    {
        baphysics_set_target_horizontal_velocity(self, 0.0f);
    }
    if (anctrl_isAt(temp_v0, 0.7307f) != 0)
    {
        _babackpack_set_state(self, 1);
        func_800A0CD0(self, 1);
    }
    if (baanim_isStopped(self) != 0)
    {
        nextState = BS_STATE_1_IDLE;
    }
    if ((anctrl_getAnimTimer(temp_v0) > 0.8f) && (bastick_getZone(self) > 0))
    {
        nextState = BS_STATE_4_RUN;
    }
    if ((anctrl_getAnimTimer(temp_v0) > 0.95f) && (player_inWater(self) != 0))
    {
        if ((player_getWaterHeight(self) - player_getGroundHeight(self)) > 80.0f)
        {
            nextState = BS_STATE_4C_LANDING_IN_WATER;
        }
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_2(s32 arg0) {
    return D_80801E30_bsbansack[arg0];
}

void func_80800A14_bsbansack(PlayerState* self)
{
    if (self->unk15C.bytes[1] == 0)
    {
        self->unk15C.bytes[1] = 1;
        if (baphysics_get_vertical_velocity(self) < 0.0f)
        {
            baphysics_set_vertical_velocity(self, 0.0f);
        }
        func_808003C0_bsbansack(self);
    }
}

void func_80800A78_bsbansack(PlayerState* self)
{
    if (self->unk15C.bytes[1] != 0)
    {
        self->unk15C.bytes[1] = 0;
        func_80800400_bsbansack(self);
    }
}

int func_80800AA4_bsbansack(PlayerState* self)
{
    return player_inWater(self) && baphysics_get_vertical_velocity(self) < 0.0f;
}

void func_80800AF4_bsbansack(PlayerState* self, s32 arg1)
{
    AnimCtrl* sp2C;
    f32 temp_f0;

    self->unk15C.bytes[0] = arg1;
    switch (arg1)
    {
    case 1:
        sp2C = baanim_getAnimCtrlPtr(self);
        func_80800A78_bsbansack(self);
        func_8009DB04(self, 0x3F0, rand_fBounded(0.96f, 1.04f), 0x2710);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
        baphysics_set_gravity(self, -1350.0f);
        if (bastick_distance(self) != 0.0f)
        {
            yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
        }
        temp_f0 = baphysics_get_horizontal_velocity(self);
        baphysics_set_target_horizontal_velocity(self, temp_f0);
        baphysics_set_target_yaw(self, yaw_getIdeal(self));
        baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), temp_f0);
        anctrl_reset(sp2C);
        anctrl_setIndex(sp2C, 0x144);
        anctrl_setSubrange(sp2C, 0.0f, 0.35f);
        anctrl_setDuration(sp2C, 0.7f);
        anctrl_setPlaybackType(sp2C, 1);
        anctrl_start(sp2C);
        baphysics_set_vertical_velocity(self, 710.0f);
        return;
    case 2:
        baanim_setEndAndDuration(self, 0.65f, 3.0f);
        return;
    case 3:
        if (player_inWater(self) != 0)
        {
            func_80800A14_bsbansack(self);
        }
        baanim_setEndAndDuration(self, 0.98f, 0.7f);
        return;
    case 4:
        if (player_inWater(self) != 0)
        {
            func_80800A14_bsbansack(self);
        }
        func_8009D2D8(self, 3);
        func_800A2FCC(self, 0);
        baanim_setEndAndDuration(self, 0.98f, 0.7f);
        return;
    case 0:
        func_80800A78_bsbansack(self);
        baphysics_reset_gravity(self);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
    default:
        return;
    }
}

void func_80800D4C_bsbansack(PlayerState* self)
{
    func_80800AF4_bsbansack(self,0);
    func_80800238_bsbansack(self);
}

void func_80800D78_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    self->unk15C.bytes[1] = 0;
    self->unk15C.bytes[0] = 0;
    func_80800AF4_bsbansack(self, 1U);
}

void func_80800DAC_bsbansack(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp20;

    nextState = BS_STATE_0_INVALID;
    sp20 = baanim_getAnimCtrlPtr(self);
    if ((bakey_released(self, BUTTON_A) != 0) && (baphysics_get_vertical_velocity(self) > 0.0f))
    {
        baphysics_reset_gravity(self);
    }
    func_808001D4_bsbansack(self);
    switch (self->unk15C.bytes[0])
    {
    case 1:
        if (baanim_isAt(self, 0.1f) != 0)
        {
            func_8009D7A4(self, 0.95f, 1.05f);
        }
        if ((func_8008DF8C(self, 0x82) != 0) || (func_80800AA4_bsbansack(self) != 0))
        {
            func_80800AF4_bsbansack(self, 3U);
        }
        else if (anctrl_isStopped(sp20) != 0)
        {
            func_80800AF4_bsbansack(self, 2U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 0);
        break;
    case 2:
        if ((func_8008DF8C(self, 0x5A) != 0) || (func_80800AA4_bsbansack(self) != 0))
        {
            func_80800AF4_bsbansack(self, 3U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 0);
        break;
    case 3:
        func_80800368_bsbansack(self);
        if ((player_isStable(self) != 0) || (player_inWater(self) != 0))
        {
            func_80800AF4_bsbansack(self, 4U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 0);
        break;
    case 4:
        func_80800368_bsbansack(self);
        if (anctrl_isStopped(sp20) != 0) {
            if (baphysics_get_target_horizontal_velocity(self) > 0.0f)
            {
                nextState = BS_STATE_166_SACK_WALK;
            }
            else if (player_inWater(self) != 0)
            {
                nextState = BS_STATE_167_SACK_FLOAT;
            }
            else
            {
                nextState = BS_STATE_165_SACK_IDLE;
            }
        }
        else
        {
            baphysics_set_target_horizontal_velocity(self, 0.0f);
        }
        nextState = func_80800084_bsbansack(self, nextState);
        break;
    }
    if (func_8008E260(self) != 0)
    {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_3(s32 arg0) {
    return D_80801E40_bsbansack[arg0];
}

void func_8080101C_bsbansack(PlayerState* self, s32 arg1)
{
    f32 temp_f0;
    f32 var_f2;

    switch (arg1)
    {
        case 0:
            yaw_setIdeal(self, self->unk174);
            yaw_applyIdeal(self);
            func_800931AC(self, 1);
            break;
        case 1:
            temp_f0 = yaw_get(self);
            self->unk174 = temp_f0;
            func_8009328C(self, temp_f0);
            func_800931AC(self, 3);
            _batimer_set(self, 0, 1.2f);
            break;
        case 2:
            temp_f0 = func_80092BE8(self);
            self->unk170 = temp_f0;
            temp_f0 = func_800F1DCC(self->unk174, temp_f0);
            var_f2 = temp_f0;
            if (temp_f0 < 0.0f)
            {
                var_f2 = 360.0f + temp_f0;
            }
            if (var_f2 < 180.0f)
            {
                var_f2 += 360.0f;
            }
            self->unk174 = self->unk170 + var_f2;
            _batimer_set(self, 0, 0.5f);
            break;
    }
    self->unk15C.bytes[0] = arg1;
}

void func_80801158_bsbansack(PlayerState* self)
{
    func_8080101C_bsbansack(self,0);
}

void func_80801178_bsbansack(PlayerState* self)
{
    self->unk15C.bytes[0] = 0;
    func_8080101C_bsbansack(self, 1);
}

s32 func_8080119C_bsbansack(PlayerState* self)
{
	f32 sp3C;
	s32 temp;
	f32 sp34;
	f32 gameSpeed;
	f32 sp2C;
	f32 temp_f12;

	sp2C = func_80092BE8(self);
	gameSpeed = time_getDelta();
	_batimer_decrement(self, 0);
	switch (self->unk15C.bytes[0])
	{
	case 1:
		sp34 = ml_map_f(_batimer_get(self, 0.0f), 0.0f, 1.2f, 700.0f, 1400.0f);
		sp2C += (sp34 * gameSpeed);
		func_8009328C(self, sp2C);
		if (func_8008DF8C(self, 1) != 0)
		{
			self->unk16C = sp34;
			func_8080101C_bsbansack(self, 2);
		}
		return 0;
	case 2:
		temp_f12 = ml_map_f(_batimer_get(self, 0), 0.0f, 0.5f, 1.0f, 0.0f) * 90.0f;
		sp3C = self->unk174 - self->unk170;
		sp2C = (func_80013970(temp_f12) * (sp3C)) + self->unk170;
		func_8009328C(self, sp2C);
		if (_batimer_get(self, 0) != 0.0f)
		{
			return 0;
		}
		return 1;
	default:
		return 0;
	}
}

void func_80801318_bsbansack(PlayerState* self)
{
    func_80801158_bsbansack(self);
    _babounce_entrypoint_3(self);
    func_80800238_bsbansack(self);
}

void func_80801348_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    baanim_playForDuration_onceSmooth(self, 0x28C, 1.2f);
    _babounce_entrypoint_4(self, 1);
    func_80801178_bsbansack(self);
}

void func_80801390_bsbansack(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_2(self) != 0)
    {
        func_808001D4_bsbansack(self);
    }
    _babounce_entrypoint_10(self);
    if (func_8080119C_bsbansack(self) != 0)
    {
        nextState = BS_STATE_165_SACK_IDLE;
    }
    if (func_8008DF8C(self, 1) != 0)
    {
        if (bastick_getZone(self) > 0) {
            nextState = BS_STATE_166_SACK_WALK;
        }
        nextState = func_80800084_bsbansack(self, nextState);
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_4(s32 arg0) {
    return D_80801E50_bsbansack[arg0];
}

void func_8080143C_bsbansack(PlayerState* self)
{
    func_80801158_bsbansack(self);
    _babounce_entrypoint_3(self);
    func_80800238_bsbansack(self);
}

void func_8080146C_bsbansack(PlayerState* self) {
    func_808002D4_bsbansack(self);
    baanim_playForDuration_onceSmooth(self, 0x28C, 1.2f);
    _babounce_entrypoint_4(self, 2);
    func_80801178_bsbansack(self);
}

void func_808014B4_bsbansack(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_babounce_entrypoint_2(self) != 0)
    {
        func_808001D4_bsbansack(self);
    }
    _babounce_entrypoint_10(self);
    if (func_8080119C_bsbansack(self) != 0)
    {
        nextState = BS_STATE_165_SACK_IDLE;
    }
    if (func_8008DF8C(self, 1) != 0)
    {
        if (bastick_getZone(self) > 0)
        {
            nextState = BS_STATE_166_SACK_WALK;
        }
        nextState = func_80800084_bsbansack(self, nextState);
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_5(s32 arg0) {
    return D_80801E60_bsbansack[arg0];
}

void func_80801560_bsbansack(PlayerState* self)
{
    _bsdrone_entrypoint_2(self);
    func_80800238_bsbansack(self);
}
void func_80801588_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    _bsdrone_entrypoint_0(self);
}
void func_808015B0_bsbansack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}

s32 bsbansack_entrypoint_6(s32 arg0) {
    return D_80801E70_bsbansack[arg0];
}

void func_808015E4_bsbansack(PlayerState* self)
{
    _bsrest_entrypoint_14(self);
    func_80800238_bsbansack(self);
}
void func_8080160C_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    _bsrest_entrypoint_16(self);
}
void func_80801634_bsbansack(PlayerState* self)
{
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0)
    {
        nextState = BS_STATE_165_SACK_IDLE;
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_7(s32 arg0) {
    return D_80801E80_bsbansack[arg0];
}

void func_80801680_bsbansack(PlayerState* self, s32 arg1)
{
    AnimCtrl* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 inWater;
    s32 var_a2;
    f32 sp34;


    self->unk15C.bytes[0] = arg1;
    switch (arg1)
    {
    case 1:
        sp4C = baanim_getAnimCtrlPtr(self);
        inWater = player_inWater(self);
        var_a2 = player_isStable(self) != 0 || inWater;
        func_80800A78_bsbansack(self);
        func_8009DB04(self, 0x3F0, rand_fBounded(0.96f, 1.04f), 0x2710);
        func_800A2EEC(self, 4);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
        if (bastick_distance(self) != 0.0f)
        {
            yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
        }
        func_808001D4_bsbansack(self);
        sp48 = baphysics_get_target_horizontal_velocity(self);
        if (inWater != 0)
        {
            sp44 = ml_map_f(sp48, 100.0f, 500.0f, 0.35f, 0.42000002f);
            sp40 = ml_map_f(sp48, 100.0f, 500.0f, 346.75f, 416.1f);
        }
        else
        {
            sp44 = ml_map_f(sp48, 100.0f, 500.0f, 0.35f, 0.7f);
            sp40 = ml_map_f(sp48, 100.0f, 500.0f, 346.75f, 693.5f);
        }
        baphysics_set_target_yaw(self, yaw_getIdeal(self));
        baphysics_set_horizontal_velocity(self, yaw_getIdeal(self), sp48);
        anctrl_reset(sp4C);
        anctrl_setIndex(sp4C, 0x144);
        anctrl_setSubrange(sp4C, 0.0f, 0.6466f);
        anctrl_setDuration(sp4C, sp44);
        anctrl_setPlaybackType(sp4C, 1);
        anctrl_start(sp4C);
        if (var_a2)
        {
            baphysics_set_vertical_velocity(self, sp40);
            return;
        }
    default:
        return;
    case 2:
        baanim_setEndAndDuration(self, 0.7965f, 3.0f);
        return;
    case 3:
        if (player_inWater(self) != 0)
        {
            func_80800A14_bsbansack(self);
        }
        baanim_setEndAndDuration(self, 0.98f, 0.7f);
        return;
    case 4:
        sp34 = 1.0f;
        self->unk16C = baphysics_get_horizontal_velocity(self) * 0.25f;
        func_8009D2D8(self, 3);
        baphysics_set_target_horizontal_velocity(self, self->unk16C);
        func_800A2FCC(self, 0);
        if (player_inWater(self) != 0)
        {
            func_80800A14_bsbansack(self);
            sp34 = 0.4f;
        }
        baanim_setEndAndDuration(self, 0.98f, 0.7f * sp34);
        return;
    case 0:
        func_80800A78_bsbansack(self);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        break;
    }
}

void func_80801A04_bsbansack(PlayerState* self)
{
    func_80801680_bsbansack(self,0);
    func_80800238_bsbansack(self);
}

void func_80801A30_bsbansack(PlayerState* self)
{
    func_808002D4_bsbansack(self);
    self->unk15C.bytes[1] = 0;
    self->unk15C.bytes[0] = 0;
    func_80801680_bsbansack(self, 1U);
}

void func_80801A64_bsbansack(PlayerState* self)
{
    BanjoStateId nextState;
    AnimCtrl* sp28;

    nextState = BS_STATE_0_INVALID;
    sp28 = baanim_getAnimCtrlPtr(self);
    func_808001D4_bsbansack(self);
    switch (self->unk15C.bytes[0])
    {
    case 1:
        if (baanim_isAt(self, 0.05f) != 0)
        {
            func_8009DEC0(self, 0x58A, 0.95f, 1.05f, 0x2328, 0x2AF8);
        }
        if ((func_8008DF8C(self, 0x82) != 0) || (func_80800AA4_bsbansack(self) != 0))
        {
            func_80801680_bsbansack(self, 3U);
        }
        else if (anctrl_isStopped(sp28) != 0)
        {
            func_80801680_bsbansack(self, 2U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 1);
        break;
    case 2:
        if ((func_8008DF8C(self, 0x82) != 0) || (func_80800AA4_bsbansack(self) != 0))
        {
            func_80801680_bsbansack(self, 3U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 1);
        break;
    case 3:
        func_80800368_bsbansack(self);
        if ((player_isStable(self) != 0) || (player_inWater(self) != 0))
        {
            func_80801680_bsbansack(self, 4U);
        }
        nextState = func_80800000_bsbansack(self, BS_STATE_0_INVALID, 1);
        break;
    case 4:
        func_80800368_bsbansack(self);
        if (anctrl_isStopped(sp28) != 0) {
            if (baphysics_get_target_horizontal_velocity(self) > 0.0f)
            {
                func_80801680_bsbansack(self, 1U);
            }
            else if (player_inWater(self) != 0)
            {
                nextState = BS_STATE_167_SACK_FLOAT;
            }
            else
            {
                nextState = BS_STATE_165_SACK_IDLE;
            }
        }
        else
        {
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
        }
        nextState = func_80800084_bsbansack(self, nextState);
        break;
    }
    if (func_8008E260(self) != 0)
    {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_8(s32 arg0) {
    return D_80801E90_bsbansack[arg0];
}

void func_80801CB4_bsbansack(PlayerState* self)
{
    func_80800238_bsbansack(self);
}

void func_80801CD4_bsbansack(PlayerState* self) {
    func_808002D4_bsbansack(self);
    baanim_playForDuration_loopSmooth(self, 0x289, 1.0f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 1, BA_PHYSICS_2_NORMAL);
}

void func_80801D20_bsbansack(PlayerState* self) {
    BanjoStateId nextState;

    nextState = BS_STATE_0_INVALID;
    if (bastick_getZone(self) > 0)
    {
        nextState = BS_STATE_166_SACK_WALK;
    }
    if (player_inWater(self) != 0)
    {
        nextState = BS_STATE_167_SACK_FLOAT;
    }
    nextState = func_80800084_bsbansack(self, nextState);
    if (func_8008E260(self) != 0)
    {
        nextState = BS_STATE_3D_FALL_TUMBLING;
    }
    bs_setState(self, nextState);
}

s32 bsbansack_entrypoint_9(s32 arg0) {
    return D_80801EA0_bsbansack[arg0];
}