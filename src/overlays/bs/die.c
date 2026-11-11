#include "bs/die.h"

extern s32 D_80800960_bsdie[];
extern s32 D_80800970_bsdie[];
extern s32 D_80800980_bsdie[];

void func_80800000_bsdie(PlayerState* self) {
    f32 var_f20;

    var_f20 = 0.0f;
    while (var_f20 < 360.0f)
    {
        _badust_entrypoint_5(self, var_f20, 230.0f);
        var_f20 += 45.0f;
    }
}

void bsdie_entrypoint_0(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 9);
    anctrl_setSubrange(temp_v0, 0.0f, 0.3356f);
    anctrl_setDuration(temp_v0, 2.0f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    self->unk16C = 250.0f;
    _basudie_entrypoint_4(self, 250.0f, 510.0f, -1400.0f, 25.0f, 3.5f);
    func_800A0CF4(self, 1);
    func_8009D820(self, 1.0f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    self->unk15C.word = 0;
}

void bsdie_entrypoint_1(PlayerState* self)
{
    AnimCtrl* sp24;
    BanjoStateId nextState;
    f32 temp_f0;

    sp24 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word)
    {
    case 3:
        break;
    case 0:
        if (player_isStable(self) != 0) {
            anctrl_setSubrange(sp24, 0.0f, 1.0f);
            anctrl_setPlaybackType(sp24, 1);
            baphysics_set_vertical_velocity(self, 400.0f);
            func_8009E058(self);
            func_8009DF18(self, 0x428, 1.0f, 0x4650);
            _bamotor_entrypoint_1(self, 1, 1, 0.4f);
            func_80800000_bsdie(self);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0) {
            func_8009E084(self);
            func_8009DF18(self, 0x427, 1.0f, 0x4650);
            _bamotor_entrypoint_1(self, 1.0f, 0.5f, 0.4f);
            self->unk15C.word = 2;
        }
        break;
    case 2:
        temp_f0 = ml_max_f(self->unk16C - 12.0f, 0.0f);
        self->unk16C = temp_f0;
        if (temp_f0 > 140.0f) {
            _badust_entrypoint_9(self);
        }
        if (anctrl_isAt(sp24, 0.6538f) != 0) {
            anctrl_setDuration(sp24, 4.0f);
        }
        if (anctrl_isStopped(sp24) != 0) {
            self->unk15C.word = 3;
            self->unk16C = 0.0f;
        }
        break;
    }
    if (_basudie_entrypoint_7(self) != 0) {
        nextState = 0x54;
    }
    bs_setState(self, nextState);
}

void bsdie_entrypoint_2(PlayerState* self) {
    _basudie_entrypoint_6(self);
    func_800A0CF4(self, 0);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

s32 bsdie_entrypoint_3(s32 arg0) {
    return D_80800960_bsdie[arg0];
}

void bsdie_entrypoint_4(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0xD8);
    anctrl_setSubrange(temp_v0, 0.0f, 0.0932f);
    anctrl_setDuration(temp_v0, 4.7f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    self->unk16C = 250.0f;
    _basudie_entrypoint_4(self, 250.0f, 510.0f, -1400.0f, 30.0f, 4.0f);
    func_800A0CF4(self, 1);
    func_8009BFE4(self, 1000.0f, 12.0f);
    func_8009D820(self, 1.0f);
    self->unk15C.word = 0;
}

void bsdie_entrypoint_5(PlayerState* self) {
    AnimCtrl* sp24;
    BanjoStateId nextState;

    sp24 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word)
    {
        case 3:
            break;
        case 0:
            if (func_8008DF8C(self, 0x96) != 0) {
                baanim_setEnd(self, 0.1863f);
                self->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(self) != 0) {
                func_8009DF18(self, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(self, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(self);
                func_8009E058(self);
                baanim_setEnd(self, 0.3333f);
                self->unk15C.word = 2;
            }
            break;
        case 2:
            self->unk16C = ml_max_f(self->unk16C - 12.0f, 0.0f);
            if (self->unk16C > 140.0f) {
                _badust_entrypoint_9(self);
            }
            if (anctrl_isStopped(sp24) != 0) {
                baanim_setEnd(self, 1.0f);
                self->unk15C.word = 3;
                self->unk16C = 0.0f;
            }
            break;
    }
    if (_basudie_entrypoint_7(self) != 0) {
        nextState = 0x54;
    }
    bs_setState(self, nextState);
}

void bsdie_entrypoint_6(PlayerState* self) {
    _basudie_entrypoint_6(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_800A0CF4(self, 0);
}

s32 bsdie_entrypoint_7(s32 arg0) {
    return D_80800970_bsdie[arg0];
}

void bsdie_entrypoint_8(PlayerState* self) {
    AnimCtrl* temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(self);
    self->unk16C = 250.0f;
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0xD7);
    anctrl_setSubrange(temp_v0, 0.0f, 0.0981f);
    anctrl_setDuration(temp_v0, 3.8f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    _basudie_entrypoint_4(self, self->unk16C, 510.0f, -1400.0f, 30.0f, 3.3999999f);
    func_8009BFE4(self, 1000.0f, 12.0f);
    func_8009D820(self, 1.0f);
    self->unk15C.word = 0;
}

void bsdie_entrypoint_9(PlayerState* self) {
    AnimCtrl* sp24;
    BanjoStateId nextState;

    sp24 = baanim_getAnimCtrlPtr(self);
    nextState = BS_STATE_0_INVALID;
    _basudie_entrypoint_5(self);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    switch (self->unk15C.word)
    {
    case 3:
        break;
    case 0:
        if (func_8008DF8C(self, 0xC8) != 0) {
            baanim_setEndAndDuration(self, 0.1961f, 3.1f);
            self->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(self) != 0) {
            func_8009DF18(self, 0x428, 1.0f, 0x4650);
            _bamotor_entrypoint_1(self, 1.0f, 1.0f, 0.4f);
            func_80800000_bsdie(self);
            func_8009E058(self);
            baanim_setEnd(self, 0.75f);
            self->unk15C.word = 2;
        }
        break;
    case 2:
        self->unk16C = ml_max_f(self->unk16C - 7.0f, 0.0f);
        if (self->unk16C > 140.0f) {
            _badust_entrypoint_9(self);
        }
        if (anctrl_isStopped(sp24) != 0) {
            baanim_setEnd(self, 1.0f);
            self->unk15C.word = 3;
            self->unk16C = 0.0f;
        }
        break;
    }
    if (_basudie_entrypoint_7(self) != 0) {
        nextState = 0x54;
    }
    bs_setState(self, nextState);
}

void bsdie_entrypoint_10(PlayerState* self) {
    _basudie_entrypoint_6(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
}

s32 bsdie_entrypoint_11(s32 arg0) {
    return D_80800980_bsdie[arg0];
}
