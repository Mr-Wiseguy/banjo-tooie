#include "core2/1E77A20.h"

s32 func_8009E130() 
{
    return 0xF4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E154.s")

void func_8009E388(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E5A4.s")

s32 func_8009E5C0() 
{
    return 0x14;
}


void (*func_8009CAAC(PlayerState *, BanjoStateId))(PlayerState *);
void (*func_8009CAF8(PlayerState *, BanjoStateId))(PlayerState *);

void bs_setState(PlayerState *self, BanjoStateId nextState) {
    if (nextState != BS_STATE_0_INVALID) {
        self->state->next = nextState;
        if (func_8009CAAC(self, self->state->current) != NULL) {
            func_8009CAAC(self, self->state->current)(self);
        }
        self->state->previous = self->state->current;
        self->state->current = self->state->next;
        self->state->next = NULL;
        if (func_8009CAF8(self, self->state->current) != NULL) {
            func_8009CAF8(self, self->state->current)(self);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E6C4.s")

s16 func_8009E6EC(PlayerState *self) {
    return self->state->unkC;
}

s32 bs_getCurrentState(PlayerState *self) {
    return self->state->current;
}

s32 bs_getNextState(PlayerState *self) {
    return self->state->next;
}

s32 bs_getPreviousState(PlayerState *self) {
    return self->state->previous;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E77C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E7AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E83C.s")
