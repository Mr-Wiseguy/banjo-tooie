#include "ch/factory/flypad.h"

extern ActorData D_80800250_chfactoryflypad;
ActorData* chfactoryflypad_entrypoint_0()
{
    return &D_80800250_chfactoryflypad;
}
extern ActorData D_80800298_chfactoryflypad;
ActorData* chfactoryflypad_entrypoint_1()
{
    return &D_80800298_chfactoryflypad;
}
void func_80800018_chfactoryflypad(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_16B_UNK);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/flypad/func_80800044_chfactoryflypad.s")

void func_80800080_chfactoryflypad(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/flypad/func_80800088_chfactoryflypad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/flypad/func_80800130_chfactoryflypad.s")
