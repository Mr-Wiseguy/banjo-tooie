#include "overlays/bs/kaz/hatch.h"

void func_80800000_bskazhatch(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 0:
        case 3:
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_13F_ANIM_KAZHATCH_UNKNOWN, 2.5);
            func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
            baphysics_set_target_horizontal_velocity(self, 0);
            break;
        case 2:
            baanim_playForDuration_onceSmooth(self, ASSET_140_ANIM_KAZHATCH_UNKNOWN, 3);
            break;
    }
    self->unk15C.bytes[0] = (s8)arg1;
}

void func_808000A8_bskazhatch(PlayerState *self) {
    func_80800000_bskazhatch(self, 0);
    _bskaz_entrypoint_2(self);
}

void func_808000D4_bskazhatch(PlayerState *self) {
    _bskaz_entrypoint_1(self);
    self->unk15C.bytes[0] = 0;
    self->unk160.word = 0;
    func_80800000_bskazhatch(self, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/hatch/func_80800108_bskazhatch.s")

BanjoStateId func_808001E4_bskazhatch(PlayerState *self) {
    if (func_8008E124(self) != 0) {
        return _badata_entrypoint_32(self);
    }
    return BS_STATE_BB;
}

void func_80800220_bskazhatch(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;

    switch (self->unk15C.bytes[0]) {
        case 1:
            if (baanim_isAt(self, 0.01) != 0) {
                func_8009DEC0(self, 0x459A, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.2) != 0) {
                func_8009DEC0(self, 0x459B, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.4) != 0) {
                func_8009DEC0(self, 0x459C, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.46) != 0) {
                if ((self->unk160.word != 0) && (func_8010114C(self->unk160.word, 0xA0, 1) <= 0)) {
                    func_80800000_bskazhatch(self, 2);
                } else {
                    func_80800000_bskazhatch(self, 3);
                }
            }
            break;

        case 2:
            if (baanim_isAt(self,  0.6) != 0) {
                func_8009DEC0(self, 0x4599, 0.95, 1.05, 26000, 26000);
            }
            if (baanim_isStopped(self) != 0) {
                baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
                if (func_8010114C(self->unk160.word, 0x18, self->unk184) > 0) {
                    return;
                }
                next_state = func_808001E4_bskazhatch(self);
            }
            break;

        case 3:
            if (baanim_isAt(self, 0.6) != 0) {
                func_8009DEC0(self, 0x459D, 0.95, 1.05, 26000, 26000);
            }
            if (baanim_isStopped(self) != 0) {
                next_state = func_808001E4_bskazhatch(self);
            }
            break;
    }
    
    bs_setState(self, next_state);
}

s32 bskazhatch_entrypoint_0(s32 idx) {
    return D_808004E0_bskazhatch[idx];
}
