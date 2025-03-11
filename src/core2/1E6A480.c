/* This file maps to BK: core2/code_9290.c */
#include "common.h"
#include "core2/1E75920.h"
#include "core2/1E7D460.h"

#include "ba/1E6A480.h"

s32 func_80090B90(void) {
    return sizeof(BaUnknown2C);
}

void func_80090B98(PlayerState *self) {
    self->unk2C->unk0 = self->unk2C->unk4 = -1;
    self->unk2C->unk18 = 0;
    self->unk2C->unk8 = -1;
    func_8009C128(self, self->unk2C->unkC);
    self->unk2C->unk19 = self->unk2C->unk1A = 0;
}

void func_80090C00(PlayerState *self, s32 arg1, s32 arg2) {
    func_800CBB70(arg1, arg2);
}

void func_80090C28(PlayerState *self, s32 arg1) {
    self->unk2C->unk18 = arg1;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A480/func_80090C34.s")
#else
s32 func_80090C34(PlayerState *self) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 v1;
    s32 sp44;
    s32 sp40;
    f32 sp34[3];
    s32 a1;


    self->unk2C->unk1A = self->unk2C->unk19;
    self->unk2C->unk19 = 0;
    a1 = func_8008E37C(self) && 1;
    
    if ( (self->unk2C->unk18 != 0) || player_isStable(self)
        || (a1) 
        || (func_800F3ED0(self) == 0x5) || (func_8009E6F8(self) == 0xB)
    ){
        func_8009C128(self, self->unk2C->unkC);
    }

    if (func_800F3ED0(self) == 0xA) {
        self->unk2C->unk8 = -1;
        return;
    }

    sp50 = (func_8008E37C(self)) ? 0x6 : 0x1;
    sp44 = self->unk2C->unk0;
    sp40 = self->unk2C->unk4;
    sp4C =func_800CCDF4(self->unk2C->unkC, &self->unk2C->unk0, &self->unk2C->unk4, 0x12C, sp50);
    v1 = (sp4C != 0);
    if (v1) {
        self->unk2C->unk19 = 1;
    }

    if ((v1 == 0) && (self->unk2C->unk8 != -1)) {
        func_801107F0(func_800A4CA8(self), sp34);
        sp4C = func_800CCDF4(sp34, &sp44, &sp40, 0x384, sp50);
        if (sp4C) {
            if(func_800CBBC0(sp44) != self->unk2C->unk8) {
                sp4C = 0;
            } else {
                self->unk2C->unk0 = sp44;
                self->unk2C->unk4 = sp40;
            }
        }
    }

    if (sp4C) {
        self->unk2C->unk8 = func_800CBBC0(self->unk2C->unk0);
    } else {
        self->unk2C->unk8 = -1;
    }
}
#endif

s32 func_80090E24(PlayerState *self) {
    return self->unk2C->unk8;
}

s32 func_80090E30(PlayerState *self) {
    return self->unk2C->unk1A;
}
