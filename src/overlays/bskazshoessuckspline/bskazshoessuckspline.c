#include "common.h"

#include "bs/kazshoessuckspline.h"

extern s32 D_80800470_bskazshoessuckspline[];
extern s32 D_80800480_bskazshoessuckspline[];

void bskazshoessuckspline_entrypoint_0(PlayerState *self) {
    f32 sp24[3];

    if ((_bashoes_entrypoint_1(self) == 4) && (func_8009E6EC(self) == 0x58)) {
        if (baflag_isTrue(self, BA_FLAG_3D) == 0) {
            func_80099A7C(self, &sp24);
            if (_bashoessuck_entrypoint_5(self, &sp24) != 0) {
                baflag_set(self, BA_FLAG_3D);
                bs_setState(self, 0x188);
                func_8009E830(self, 2);
            }
        }
    } else {
        func_80099B94(self);
    }
}

void func_808000A4_bskazshoessuckspline(PlayerState *self) {
    if (func_8009CA70(self, func_8009E710(self), 0x800) == 0) {
        _bashoessuck_entrypoint_3(self);
        func_80092880(self, 0);
        func_800A2018(self, 3);
        func_800A4DA4(self, 0x19);
    }
}

void func_80800110_bskazshoessuckspline(PlayerState *self) {
    if (func_8009CA70(self, func_8009E704(self), 0x800) == 0) {
        _bashoessuck_entrypoint_2(self);
        baflag_clear(self, BA_FLAG_3D);
        func_80092880(self, 1);
        func_800A2018(self, -1);
        func_800A4E30(self);
    }
}

void bskazshoessuckspline_entrypoint_1(PlayerState *self) {
    func_80800110_bskazshoessuckspline(self);
    _bskaz_entrypoint_2(self);
}

void bskazshoessuckspline_entrypoint_2(PlayerState *self) {
    _bskaz_entrypoint_1();
    func_808000A4_bskazshoessuckspline(self);
    _bskazmove_entrypoint_5(self, 4);
    func_8009FFD8(self, 2, 1, 9, 0x12);
}

void bskazshoessuckspline_entrypoint_3(PlayerState *self) {
    s32 sp2C;
    f32 sp20[3];

    sp2C = 0;
    func_800956B8();
    _bskazmove_entrypoint_6(self);
    _bskazmove_entrypoint_0(self);
    _bashoessuck_entrypoint_4(self);
    if ((bastick_getZone(self) == 0) && (func_8009BCD4(self, 1) != 0)) {
        sp2C = 0x187;
    }
    if (bakey_pressed(self, 8) != 0) {
        sp2C = _bskaz_entrypoint_3(self);
    }
    if ((_bamovespline_entrypoint_1(self, 100) != 0) || (_bashoes_entrypoint_1(self) != 4)) {
        sp2C = 0xDF;
    }
    if (_bamovespline_entrypoint_3(self) != 0) {
        sp2C = 0xC7;
    }
    if (_bamovespline_entrypoint_2(self) != 0) {
        if (_bashoes_entrypoint_2(self) == 2) {
            _bashoessuck_entrypoint_1(self, &sp20);
            sp2C = _badrone_entrypoint_23(self, &sp20);
        } else {
            sp2C = 0xC7;
        }
    }
    bs_setState(self, sp2C);
}

s32 bskazshoessuckspline_entrypoint_4(s32 idx) {
    return D_80800470_bskazshoessuckspline[idx];
}

void bskazshoessuckspline_entrypoint_5(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    func_808000A4_bskazshoessuckspline(self);
    baanim_playForDuration_loopSmooth(self, ASSET_A4_ANIM_BSKAZSHOESSUCKSPLINE, 6.5);
    func_8009FFD8(self, 1, 1, 9, 0x12);
    baphysics_set_target_horizontal_velocity(self, 0);
}

void bskazshoessuckspline_entrypoint_6(PlayerState *self) {
    s32 state;

    state = 0;
    if ((baflag_isTrue(self, BA_FLAG_3D) != 0) && (_bashoes_entrypoint_1(self) == 4)) {
        _bashoessuck_entrypoint_4(self);
        if (bastick_getZone(self) > 0) {
            state = 0x188;
        }
    } else {
        if (func_8008DD04(self) != 0) {
            state = 0xDF;
        } else {
            state = 0xBB;
        }
    }
    bs_setState(self, state);
}

void bskazshoessuckspline_entrypoint_7(PlayerState *self) {
    func_80800110_bskazshoessuckspline(self);
    _bskaz_entrypoint_2(self);
}

s32 bskazshoessuckspline_entrypoint_8(s32 idx) {
    return D_80800480_bskazshoessuckspline[idx];
}