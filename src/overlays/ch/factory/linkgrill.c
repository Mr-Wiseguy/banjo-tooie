#include "ch/factory/linkgrill.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_80800000_chfactorylinkgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_8080006C_chfactorylinkgrill.s")

extern ActorData D_80800250_chfactorylinkgrill;
ActorData* chfactorylinkgrill_entrypoint_0()
{
    return &D_80800250_chfactorylinkgrill;
}
void func_80800124_chfactorylinkgrill(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D9_UNK);
    _chswitch_entrypoint_9(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_80800150_chfactorylinkgrill.s")

extern ActorData D_80800298_chfactorylinkgrill;
ActorData* chfactorylinkgrill_entrypoint_1()
{
    return &D_80800298_chfactorylinkgrill;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/linkgrill/func_808001B0_chfactorylinkgrill.s")

extern ActorData D_808002E0_chfactorylinkgrill;
ActorData* chfactorylinkgrill_entrypoint_2()
{
    return &D_808002E0_chfactorylinkgrill;
}
