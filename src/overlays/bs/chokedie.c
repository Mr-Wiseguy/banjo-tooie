#include "bs/chokedie.h"

extern s32 D_808002B0_bschokedie[];

void bschokedie_entrypoint_0(PlayerState* self) {
    baanim_playForDuration_onceSmooth(self, 0xF0, 4.2f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
    func_8009BA9C(self, NULL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800A4DFC(self, 0xA);
    _ncbadie_entrypoint_3(func_800A4CA8(self), 30.0f);
    func_800A0180(self);
    _batimer_set(self, 0, 3.8f);
    func_8008E944(self);
    func_80090A0C(self);
    _basudie_entrypoint_1(self);
}

void bschokedie_entrypoint_1(PlayerState* self) {
    if (baanim_isAt(self, 0.4f) != 0) {
        func_80090A2C(self);
    }
    if (baanim_isAt(self, 0.58f) != 0) {
        func_8009514C(self);
    }
    if (baanim_isAt(self, 0.05f) != 0) {
        func_8009DF18(self, 0x574, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(self, 0.2f) != 0) {
        func_8009DF18(self, 0x575, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(self, 0.4f) != 0) {
        func_8009DF18(self, 0x576, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(self, 0.66f) != 0) {
        func_8009DF18(self, 0x577, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(self, 0.5999f) != 0) {
        func_8009DF94(self, 0x417, 1.2f, 0x3E80);
    }
    if (baanim_isAt(self, 0.7891f) != 0) {
        func_8009DF94(self, 0x417, 0.9f, 0x4E20);
    }
    if (baanim_isAt(self, 0.9291f) != 0) {
        func_8009DF94(self, 0x417, 1.4f, 0x2328);
    }
    if (_batimer_decrement(self, 0) != 0) {
        _basudie_entrypoint_0(self);
    }
}

void bschokedie_entrypoint_2(PlayerState* self) {
    func_800951B4(self);
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_800A4E30(self);
}

s32 bschokedie_entrypoint_3(s32 arg0) {
    return D_808002B0_bschokedie[arg0];
}
