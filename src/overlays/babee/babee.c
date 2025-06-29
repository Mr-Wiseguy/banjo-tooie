#include "common.h"

#include "overlays/ba/bee.h"
#include "overlays/ba/yaw.h"

#include "overlays/ch/stinger.h"

#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E93440.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECE0B0.h"
#include "core2/1ECD170.h"

extern s32 D_80800390_babee;
extern s32 D_808003BC_babee;

s32 babee_entrypoint_0(void) {
    return sizeof(BaBee);
}

void func_80800008_babee(f32 arg0[3], f32 arg1[3], f32 arg2) {
    f32 sp24[3];
    func_800EFA98(sp24, arg1, arg2);
    func_800EF04C(sp24, arg0);
    func_800BBCB8(sp24, 0, 1.0f, 1, &D_80800390_babee);
}

void babee_entrypoint_1(s32 arg0) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    s32 sp40;
    s32 sp3C;
    PlayerState *self;
    BaBee *bee;
    f32 sp30;
    
    self = func_800F53D0(arg0);
    bee = self->bee;
    sp3C = func_80092CDC(self, sp50, 4);
    sp40 = func_80092EB0(self);
    if (sp3C && sp40) {
        sp30 = (player_isStable(self)) ? 0.0f : -func_8009BFCC(self);
        func_800F3BD0(self, 0x5, sp5C);
        func_800EEC30(sp44, sp30, yaw_get(self), bee->unk0[bee->index].unk0);
        func_80800008_babee(sp50, sp44, 0.0f);
    } else {
        _baeggfire_entrypoint_3(self, sp5C, sp44);
        func_800EF368(sp44, 100.0f);
        func_800EE780(sp50, sp5C, sp44);
        func_800EF368(sp44, bee->unk0[bee->index].unk0);
        _baeggcursor_entrypoint_8(self);
        func_80800008_babee(sp50, sp44, 80.0f);
    }
    _chstinger_entrypoint_0(sp50, sp5C, sp44, bee->unk0[bee->index].unk8, arg0);
}

void babee_entrypoint_2(PlayerState *self) {
    BaBee *bee = self->bee;
    f32 sp20[3];

    if (!(0.0f < bee->cooldown)) {
        bee->cooldown += bee->unk0[bee->index].cooldown_time;
        func_8009C128(self, sp20);
        func_8010D930(0xB, -1, sp20, &D_808003BC_babee);
        _chbaddiesetup_entrypoint_1(_babee_entrypoint_1, self->unk184);
    }
}

void babee_entrypoint_3(PlayerState *self) {}

void babee_entrypoint_4(PlayerState *self) {
    BaBee *bee = self->bee;
    bee->index = 0;
    bee->cooldown = 0.0f;
    bee->unk0[0].unk8 = 3000.0f;
    bee->unk0[0].cooldown_time = 0.5f;
    bee->unk0[0].unk0 = 1500.0f;
}

void babee_entrypoint_5(PlayerState *self) {
    BaBee *bee = self->bee;
    bee->index--;
}
void babee_entrypoint_6(PlayerState *self) {
    BaBee *bee = self->bee;
    bee->index++;
}

void babee_entrypoint_7(PlayerState *self, f32 arg1, f32 cooldown, f32 arg3) {
    BaBee *bee = self->bee;
    bee->unk0[bee->index].unk0 = arg1;
    bee->unk0[bee->index].cooldown_time = cooldown;
    bee->unk0[bee->index].unk8 = arg3;
}

void babee_entrypoint_8(PlayerState *self) {
    BaBee *bee = self->bee;
    if (0.0f < bee->cooldown) {
        bee->cooldown -= func_800D8FF8();
    }
}
