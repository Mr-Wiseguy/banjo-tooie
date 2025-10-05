#include "common.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "su/baddieaudioquick.h"

extern f32 D_80800F40_chcablecar[3];
extern s16 D_80800F4C_chcablecar[];
extern s16 D_80800F58_chcablecar[];

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 unk10;
} cablecarMemory;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/chcablecar_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/chcablecar_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800018_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808002E0_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800424_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808004EC_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800598_chcablecar.s")

void func_808005E0_chcablecar(Actor* arg0) {
    void* temp_a0;
    cablecarMemory* temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    temp_a0 = &temp_v0->unk10;
    if (temp_v0->unkC < 0.5f) {
        if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F4C_chcablecar);
        }
    } else if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F58_chcablecar);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_8080069C_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_8080070C_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_808007C8_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800914_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800AF4_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800B74_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800BD0_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800D14_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800DC8_chcablecar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cablecar/func_80800E30_chcablecar.s")
