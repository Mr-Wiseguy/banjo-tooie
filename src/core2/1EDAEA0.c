#include "core2/1EDAEA0.h"


void* func_800DE448(f32*, f32*, f32, f32*, s32);
void func_800DF47C(s32 (*arg0)(Actor*), Actor*);
f32* func_801018D8(Actor*);
f32* func_801027F4(Actor*);
s32 func_801015D0(Actor*);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801015B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801015BC.s")

void func_801015C8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801015D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801017D0.s")

// the real actor_draw?
void func_80101808(Actor* arg0, s32 (*arg1)(Actor*)) {
    s32 pad[2];
    f32* sp2C;
    f32* sp28;

    func_800DF47C(arg1, arg0);
    sp28 = func_801027F4(arg0);
    sp2C = func_801018D8(arg0);
    func_800DE448(arg0->position, sp28, arg0->scale, sp2C, func_8010347C(arg0->unk0));
}

void func_80101870(Actor* arg0, void* arg1) {
    func_80101970(arg0);
    func_80101808(arg0, func_801015D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801018A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_801018D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDAEA0/func_80101BA0.s")
