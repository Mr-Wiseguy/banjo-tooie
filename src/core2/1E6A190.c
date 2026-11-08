#include "common.h"

#include "core2/1E6A190.h"

extern f32 D_80117CC0;
extern f32 D_80117CFC;
extern f32 D_80117D80;

s32 func_800908A0(void) {
    return sizeof(BaUnknown20);
}

f32 *func_800908A8(s32 arg0) {
    switch (arg0) {
    case 0:
        return &D_80117D80;

    case 1:
        return &D_80117CFC;
    
    case 2:
        return &D_80117CC0;

    default:
        return NULL;
    }
}

void func_800908F0(PlayerState *self, s32 arg1) {
    self->unk20->unk9 = arg1;
    if (arg1 == 1) {
        func_8009ADF0(self, 4, 0);
    } else {
        func_8009ADF0(self, 4, 1);
    }
}

void func_80090938(PlayerState *self) {
    self->unk20->unk0 = 0;
    self->unk20->unk4 = 0.0f;
    self->unk20->unk8 = 0;
    self->unk20->unk9 = 0;
    func_800908F0(self, 1);

}

void func_8009097C(PlayerState *self, s32 arg1) {
    self->unk20->unk0 = arg1;
    self->unk20->unk8 = 0;
    self->unk20->unk4 = func_800908A8(arg1)[0];
    func_800908F0(self, 2);
}

void func_800909CC(PlayerState *self) {
    func_8009097C(self, 1);
}

void func_800909EC(PlayerState *self) {
    func_8009097C(self, 0);
}

void func_80090A0C(PlayerState *self) {
    func_8009097C(self, 2);
}

void func_80090A2C(PlayerState *self) {
    func_800908F0(self, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A190/func_80090A4C.s")
