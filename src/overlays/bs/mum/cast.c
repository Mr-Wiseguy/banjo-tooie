#include "overlays/bs/mum/cast.h"

#ifndef NONMATCHINGS
s32 func_80800000_bsmumcast(PlayerState *self, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/mum/cast/func_80800000_bsmumcast.s")
#else
// Decomp failure
#endif

void bsmumcast_entrypoint_0(PlayerState *self) {
    func_8008E95C(self);
    func_800A0DA0(self, 0);
    func_800A0DAC(self, 1);
    _bsmum_entrypoint_1(self);
}

void bsmumcast_entrypoint_1(PlayerState *self) {
    f32 sp24[3];

    _bsmum_entrypoint_2(self);
    func_8008E944(self);
    func_80099A7C(self, sp24);
    func_800A00CC(self, sp24);
    self->unk15C.word = 0;
    if (func_8009EA20() != 0) {
        func_80800000_bsmumcast(self, 4);
        return;
    }
    func_80800000_bsmumcast(self, 1);
}

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/mum/cast/bsmumcast_entrypoint_2.s")
#else
// Decomp failure
#endif

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/mum/cast/bsmumcast_entrypoint_3.s")
#else
// Decomp failure
#endif

s32 bsmumcast_entrypoint_4(s32 idx) {
    return D_808004A0_bsmumcast[idx];
}
