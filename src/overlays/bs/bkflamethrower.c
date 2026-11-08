#include "bs/bkflamethrower.h"

extern s32 D_80800450_bsbkflamethrower[];

/* .code */
void bsbkflamethrower_entrypoint_0(PlayerState* self, f32 arg1[2], f32 arg2[2]) {
    f32 sp24[3];
    s32 pad;
    f32 sp1C;

    sp1C = func_8009BFCC(self);
    func_800EEC30(arg2, -sp1C, yaw_get(self), 1.0f);
    player_getCoords(self, arg1);
    func_800EFA98(sp24, arg2, 40.0f);
    ml_vec3f_add(arg1, sp24);
    arg1[1] += 94.0f;
}

void func_80800094_bsbkflamethrower(PlayerState* self, u32 arg1)
{
    AnimCtrl* anim_ctrl;
    f32 var_f0;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk15C.word = arg1;
    switch (arg1)
    {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0xE0, 1.0f);
            func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 8, BA_PHYSICS_2_NORMAL);
            yaw_setVelocityBounded(self, 300.0f, 1.6f);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_800A0CF4(self, 1);
            func_8009D874(self);
            if (ability_getValue(0x32) != 0) {
                var_f0 = 0.24f;
            } else {
                var_f0 = 0.0f;
            }
            _batimer_set(self, 0, var_f0);
            _baflamethrower_entrypoint_2(self, _bsbkflamethrower_entrypoint_0);
            return;
        case 2:
            anctrl_setSubrange(anim_ctrl, 0.4f, 0.6f);
            anctrl_setPlaybackType(anim_ctrl, 4);
            _batimer_set(self, 2, 0.14f);
            _baflamethrower_entrypoint_3(self);
            return;
        case 3:
            _baflamethrower_entrypoint_4(self);
            _batimer_set(self, 1, 0.05f);
            return;
        case 4:
            anctrl_setPlaybackType(anim_ctrl, 1);
            baanim_setEnd(self, 1.0f);
            return;
        case 0:
            _baflamethrower_entrypoint_1(self);
            func_800A0CF4(self, 0);
            /* fallthrough */
        default:
            return;
    }
}

void bsbkflamethrower_entrypoint_1(PlayerState* self)
{
    func_80800094_bsbkflamethrower(self, 0);
}

void bsbkflamethrower_entrypoint_2(PlayerState* self)
{
    self->unk15C.word = 0;
    func_80800094_bsbkflamethrower(self, 1);
}

void bsbkflamethrower_entrypoint_3(PlayerState* self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if ((_batimer_get(self, 0) != 0.0f) && (bakey_pressed(self, BUTTON_B) != 0)) {
        next_state = BS_STATE_189_BREEGULL_BASH;
    }
    _batimer_decrement(self, 0);
    switch (self->unk15C.word) {
        case 1:
            if (baanim_isAt(self, 0.22f) != 0) {
                func_8009DF18(self, 0x459F, 1.0f, 0x6590);
            }
            if (baanim_isAt(self, 0.4f) != 0) {
                func_80800094_bsbkflamethrower(self, 2);
            }
            break;
        case 2:
            _batimer_decrement(self, 2);
            if ((_batimer_isZero(self, 2) != 0) && (bakey_released(self, 9) != 0)) {
                func_80800094_bsbkflamethrower(self, 3);
            }
            break;
        case 3:
            if (_batimer_decrement(self, 1) != 0) {
                func_80800094_bsbkflamethrower(self, 4);
            }
            break;
        case 4:
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_1_IDLE;
            }
            if (baanim_getTimer(self) > 0.7f) {
                next_state = _bsstand_entrypoint_8(self, next_state);
            }
            break;
    }
    _baflamethrower_entrypoint_5(self);
    bs_setState(self, next_state);
}

s32 bsbkflamethrower_entrypoint_4(s32 arg0)
{
    return D_80800450_bsbkflamethrower[arg0];
}
