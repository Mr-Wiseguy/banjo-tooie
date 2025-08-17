#include "common.h"

#include "overlays/bs/kaz/flamethrower.h"

extern s32 D_808003B0_bskazflamethrower[];

void bskazflamethrower_entrypoint_0(PlayerState *self, f32 arg1[3], f32 arg2[3]) {
    f32 unk0[3];
    s32 pad2;
    f32 unk1;

    unk1 = func_8009BFCC(self);
    func_800EEC30(arg2, -unk1, yaw_get(self), 1);
    func_8009C128(self, arg1);
    func_800EFA98(unk0, arg2, 17);
    func_800EF04C(arg1, unk0);
    arg1[1] += 57.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/kaz/flamethrower/func_80800094_bskazflamethrower.s")

void bskazflamethrower_entrypoint_1(PlayerState *self) {
    func_80800094_bskazflamethrower(self, 0);
}

void bskazflamethrower_entrypoint_2(PlayerState *self) {
    self->unk15C.word = 0;
    func_80800094_bskazflamethrower(self, 1);
}

void bskazflamethrower_entrypoint_3(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    switch (self->unk15C.word) {
        case 1:
            if (baanim_isAt(self, 0.2) != 0) {
                func_8009DF18(self, 0x459F, 1, 0x6590);
            }
            if (baanim_isAt(self, 0.375) != 0) {
                func_80800094_bskazflamethrower(self, 2);
            }
            break;
        case 2:
            _batimer_decrement(self, 2);
            if ((_batimer_isZero(self, 2) != 0) && (bakey_released(self, 9) != 0)) {
                func_80800094_bskazflamethrower(self, 3);
            }
            break;
        case 3:
            if (_batimer_decrement(self, 1) != 0) {
                func_80800094_bskazflamethrower(self, 4);
            }
            break;
        case 4:
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_BB;
            }
            if (baanim_getTimer(self) > 0.7f) {
                next_state = _bskazstill_entrypoint_4(self, next_state);
            }
            break;
    }
    _baflamethrower_entrypoint_5(self);
    bs_setState(self, next_state);
}

s32 bskazflamethrower_entrypoint_4(s32 idx) {
    return D_808003B0_bskazflamethrower[idx];
}