#include "common.h"

#include "overlays/ba/wobble.h"

#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1EBA250.h"
#include "core2/1ECA640.h"

extern Unkfunc_800E0960_1 * func_80092AD8(PlayerState *);

s32 bawobble_entrypoint_0(void) {
    return sizeof(BaWobble);
}

void func_80800008_bawobble(PlayerState *self, s32 arg1) {
    switch(arg1) {
        case 2:
            self->wobble->unk18 = self->wobble->unk10;
            break;
        case 3:
            self->wobble->unk18 = self->wobble->unk14;
            break;
    }
    self->wobble->unk1C = arg1;
}

void func_8080004C_bawobble(PlayerState *self, s32 arg1) {
    if ((arg1 != 1) && (arg1 == 2)) {
        if (self->wobble->unkC == 2) {
            return;
        }
        self->wobble->unk8 = 0.0f;
        func_80800008_bawobble(self, 2);
    }
    self->wobble->unkC = arg1;
}

void bawobble_entrypoint_1(PlayerState *self) {
    self->wobble->unk1D = 0;
    func_80800008_bawobble(self, 1);
    func_8080004C_bawobble(self, 1);
    bawobble_entrypoint_4(self, 0.0f, 0.0f);
}

void bawobble_entrypoint_2(PlayerState *self) {
    func_8080004C_bawobble(self, 0);
}

void bawobble_entrypoint_3(PlayerState *self) {
    self->wobble->unkC = 0;
    func_8080004C_bawobble(self, 1);
    bawobble_entrypoint_1(self);
}

void bawobble_entrypoint_4(PlayerState *self, f32 arg1, f32 arg2) {
    self->wobble->unk10 = arg1;
    self->wobble->unk14 = arg2;
}

void bawobble_entrypoint_5(PlayerState *self, f32 arg1, f32 arg2) {
    self->wobble->unk4 = arg1;
    self->wobble->unk0 = arg2;
}

void bawobble_entrypoint_6(PlayerState *self) {
    func_8080004C_bawobble(self, 2);
}

void bawobble_entrypoint_7(PlayerState *self) {
    self->wobble->unk1D = 1;
} 

void func_808001C0_bawobble(PlayerState *self, f32 arg1) {
    f32 sp4C[3];
    Unkfunc_800E0960_1 *sp48 = func_80092AD8(self);
    s32 i;

    func_800E0AF0(sp48, 1.0f);
    func_800D91B8(&self->wobble->unk8);
    for (i = 0; i < 3; i++) {
        sp4C[i] = func_800F101C(self->wobble->unk8 + (0.2f*(f32)i)*0.25f, 0.2f);
        sp4C[i] = func_800F1214(sp4C[i], self->wobble->unk0, self->wobble->unk4);
    }
    func_800E0B8C(sp48, 3, arg1, sp4C[0], sp4C[1], sp4C[2]);
}

void bawobble_entrypoint_8(PlayerState *self) {
    f32 sp2C;

    if(self->wobble->unkC != 2) {
        return;
    }

    switch (self->wobble->unk1C) {
        case 2:
            func_800D9078(&self->wobble->unk18);
            sp2C = func_800F10B4(self->wobble->unk18, 0.0f, self->wobble->unk10, 1.0f, 0);
            if ((sp2C == 1.0f) &&  (self->wobble->unk1D)) {
                func_80800008_bawobble(self, 3);
            }
            break;
        case 3:
            func_800D9078(&self->wobble->unk18);
            sp2C = func_800F10B4(self->wobble->unk18, 0.0f, self->wobble->unk14, 0, 1.0f);
            if ((sp2C == 0.0f)) {
                func_8080004C_bawobble(self, 1);
            }
            break;
    }
    func_808001C0_bawobble(self, sp2C);
}
