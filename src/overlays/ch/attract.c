#include "ch/attract.h"

extern ActorData D_808004F4_chattract;
extern s32 B_80800540_chattract;
void chattract_entrypoint_2(s32);
ActorData* chattract_entrypoint_0()
{
    return &D_808004F4_chattract;
}
void func_8080000C_chattract(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_80800014_chattract.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_80800204_chattract.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_808002AC_chattract.s")

void chattract_entrypoint_1(s32 arg0) {
    _chbaddiesetup_entrypoint_1(&_chattract_entrypoint_2, arg0);
}

void chattract_entrypoint_2(s32 arg0)
{
    Actor* temp_v0;

    temp_v0 = func_80108454(0x4B5, &B_80800540_chattract, 0);
    if (temp_v0 != 0)
    {
        temp_v0->unk74_7 = arg0 + 1;
        temp_v0->unk0->unk12_1 = 1;
        func_800EC828();
    }
}