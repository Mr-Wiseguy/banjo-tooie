#include "common.h"

#include "overlays/ba/van.h"

#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1E76CC0.h"
#include "core2/1EB2840.h"
#include "core2/1E9A960.h"
#include "core2/1EBA250.h"
#include "core2/1ECA640.h"

extern s32 D_808002F0_bavan; // 02 06 00 13 05 06 00 0A  01 00 00 00 00 00 00 00  

s32 bavan_entrypoint_0(void) {
    return sizeof(BaVan);
}

void bavan_entrypoint_1(PlayerState *self) {
    f32 sp1C[3];
    func_8009DE38(self, 0x505, 1.0f);
    func_8009C128(self, sp1C);
    func_801013A8(sp1C, 0x19, self->unk184);
}

void bavan_entrypoint_2(PlayerState *self) {
    func_800C2FDC(self->van->unk10);
    self->van->unk10 = 0;
}

void bavan_entrypoint_3(PlayerState *self) {
    self->van->unk0 = 0.0f;
    self->van->unk4 = 0.0f;
    self->van->unk8 = 0.0f;
    self->van->unkC = 0.0f;
    self->van->unk10 = func_8009D454(self, 0, &D_808002F0_bavan);
    self->van->unk14 = 1.0f;
    func_800C368C(self->van->unk10, 0);
    func_800C334C(self->van->unk10, 0x40);
    func_800C3BDC(self->van->unk10);
}

void bavan_entrypoint_4(PlayerState *self, f32 arg1) {
    self->van->unk14 = arg1;
}

void bavan_entrypoint_5(PlayerState *self, f32 arg1) {
    self->van->unk4 = func_800F0DC0(arg1, 50.0f);
}

void bavan_entrypoint_6(PlayerState *self, f32 arg1) {
    self->van->unkC = arg1;
}

void bavan_entrypoint_7(PlayerState *self, f32 arg1) {
    self->van->unk8 = arg1;
}

void bavan_entrypoint_8(PlayerState *self) {
    Unkfunc_800E0960_1 *tmp_s1;
    f32 sp38[3];
    f32 dt;
    
    dt = func_800D8FF8();
    self->van->unk8 += self->van->unkC* dt;
    self->van->unk0 = func_800F15F8(self->van->unk0, self->van->unk4, dt*200.0f);
    tmp_s1 = func_80092AD8(self);
    func_800E0AF0(tmp_s1, 1.0f);
    func_800E0AFC(tmp_s1, 0x2A, 1.0f, self->van->unk8, self->van->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x2B, 1.0f, self->van->unk8, self->van->unk0, 0.0f);
    func_800E0AFC(tmp_s1, 0x2C, 1.0f, self->van->unk8, 0.0f, 0.0f);
    func_800E0AFC(tmp_s1, 0x2D, 1.0f, self->van->unk8, 0.0f, 0.0f);
    func_8009C128(self, sp38);
    func_800C368C(self->van->unk10, 0);
    func_800C334C(self->van->unk10, 0x40);
    func_800C31DC(self->van->unk10, self->van->unk14);
    func_800C3BDC(self->van->unk10);
}
