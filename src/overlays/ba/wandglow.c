#include "overlays/ba/wandglow.h"

s32 bawandglow_entrypoint_0(void) {
    return sizeof(BaWandGlow);
}

void bawandglow_entrypoint_1(s32 arg0, s32 arg1) {
    PlayerState *self = func_800F53E4(arg1);
    if (self != NULL) {
        self->wandglow->unkC = NULL;
    }
}


void bawandglow_entrypoint_2(s32 arg0) {
    PlayerState *self = func_800F53D0(arg0);
    if (self->wandglow->unk10) {
        self->wandglow->unkC = _chwandglow_entrypoint_0(arg0, _bawandglow_entrypoint_1);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/wandglow/bawandglow_entrypoint_3.s")
#else
void bawandglow_entrypoint_3(PlayerState *self, s32 arg1) {
    if (self->wandglow->unkC != NULL) {
        func_8008F880(self->wandglow->unkC);
    }
    func_8008EEC4(self, self->wandglow->unk0, arg1, 0x27D);
}
#endif

void bawandglow_entrypoint_4(PlayerState *self) {
    self->wandglow->unk10 = 1;
    _chbaddiesetup_entrypoint_1(_bawandglow_entrypoint_2, self->unk184);
}

void bawandglow_entrypoint_5(PlayerState *self) {
    if(self->wandglow->unkC != NULL) {
        _chwandglow_entrypoint_1(self->wandglow->unkC, self);
    }
    self->wandglow->unk10 = 0;
    self->wandglow->unkC = NULL;
}

void bawandglow_entrypoint_6(PlayerState *self) {
    self->wandglow->unk10 = 0;
    self->wandglow->unkC = NULL;
    func_800EFD24(self->wandglow->unk0);
}

void bawandglow_entrypoint_7(PlayerState *self) {
    if (self->wandglow->unkC != NULL) {
        _chwandglow_entrypoint_2(self->wandglow->unkC);
    }
}
