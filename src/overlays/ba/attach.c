#include "common.h"

#include "overlays/ba/attach.h"

s32 baattach_entrypoint_0(void) {
    return sizeof(BaAttach);
}

s32 baattach_entrypoint_1(PlayerState *self) {
    if (self->attach->unk0) {
        return 1;
    } else {
        return 0;
    }
}

s32 baattach_entrypoint_2(PlayerState *self, s32 arg1, void (*arg2)(s32, s32, s32, s32)) {
    self->attach->unk0 = arg1;
    self->attach->unk4 = arg2;
    return 1;
}

void baattach_entrypoint_3(PlayerState *self) {
    baattach_entrypoint_6(self, 3, 0, 0);
}

void baattach_entrypoint_4(PlayerState *self) {
    self->attach->unk0 = 0;
}

void baattach_entrypoint_5(PlayerState *self, s32 arg1) {
    if (self->attach->unk0) {
        self->attach->unk0  = 0;
    }
}

void baattach_entrypoint_6(PlayerState *self, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad;
    s32 sp18 = self->attach->unk0;
    if (sp18) {
        self->attach->unk4(sp18, arg1, arg2, arg3);
    }
}
