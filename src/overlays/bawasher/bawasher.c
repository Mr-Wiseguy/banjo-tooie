#include "common.h"

#include "overlays/ba/washer.h"

#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1EB2840.h"
#include "core2/1EBA250.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECE0B0.h"

s32 bawasher_entrypoint_0(void){
    return sizeof(BaWasher);
}

void bawasher_entrypoint_1(PlayerState *self) {}

void bawasher_entrypoint_2(PlayerState *self) {
    self->washer->unk0 = 0.0f;
    self->washer->unk4 = 0.0f;
    self->washer->unk8 = 0.0f;
    self->washer->unkC = 0.0f;
}

void bawasher_entrypoint_3(PlayerState *self, f32 arg1[3]) {
    if (!func_80092CDC(self, arg1, 5)) {
        func_8009C128(self, arg1);
    }
}

void bawasher_entrypoint_4(PlayerState *self, f32 arg1) {
    self->washer->unk4 = func_800F0DC0(arg1, 50.0f);
}

void bawasher_entrypoint_5(PlayerState *self, f32 arg1) {
    self->washer->unkC = arg1;
}

void bawasher_entrypoint_6(s32 arg0) {
    PlayerState *self = func_800F53D0(arg0);
    _chlaundry_entrypoint_1(self->washer->unk10, self->washer->unk1C, self->washer->unk28, arg0);
}

void bawasher_entrypoint_7(PlayerState *self) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    if (func_80092CDC(self, sp3C, 4) && func_80092CDC(self, sp30, 5)) {
        func_800EFB24(sp24, sp3C, sp30);
        func_800EF368(sp24, 1200.0f);
    } else {
        _baeggfire_entrypoint_3(self, sp30, sp24);
        func_800EF368(sp24, 100.0f);
        func_800EE780(sp3C, sp30, sp24);
        func_800EF368(sp24, 1200.0f);
        _baeggcursor_entrypoint_8(self);
    }
    bawasher_entrypoint_8(self, sp30, sp3C, sp24);
}

void bawasher_entrypoint_8(PlayerState *self, f32 arg1[3], f32 arg2[3], f32 arg3[3]) {
    func_800EE7F8(self->washer->unk10, arg1);
    func_800EE7F8(self->washer->unk1C, arg2);
    func_800EE7F8(self->washer->unk28, arg3);
    _chbaddiesetup_entrypoint_1(_bawasher_entrypoint_6, self->unk184);
}

void bawasher_entrypoint_9(PlayerState *self) {
    f32 dt = func_800D8FF8();
    Unkfunc_800E0960_1 *tmp_s1;
    self->washer->unk8 += self->washer->unkC * dt;
    self->washer->unk0 = func_800F15F8(self->washer->unk0, self->washer->unk4, dt*200.0f);
    tmp_s1 = func_80092AD8(self);
    func_800E0AF0(tmp_s1, 1.0f);
    func_800E0AFC(tmp_s1, 0x34, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x36, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x35, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x37, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x4E, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(tmp_s1, 0x50, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(tmp_s1, 0x4F, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(tmp_s1, 0x51, 1.0f, self->washer->unk8, 0.0f, 0.0f);
}
