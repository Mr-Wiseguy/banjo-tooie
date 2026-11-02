#include "core2/1EDA900.h"

extern f32 D_80135A70[3];
extern f32 D_80135A7C;
extern void* D_80135A80;

void func_80101010(f32* arg0)
{
    ml_vec3f_copy(D_80135A70, arg0);
}

void func_80101038(f32* arg0)
{
    ml_vec3f_copy(arg0, D_80135A70);
}

void func_8010105C(f32 arg0) {
    D_80135A7C = arg0;
}

f32 func_80101068(void) {
    return D_80135A7C;
}

void func_80101074(void* arg0) {
    D_80135A80 = arg0;
}

void* func_80101080()
{
    return D_80135A80;
}

s32 event_sendToActor(Actor* actor, ActorEventId eventId, s32 arg2)
{
    s32 pad;
    s32 sp28;
    s32 sp24;
    s32 syscallIndex;

    if (actor->unk74_28)
    {
        syscallIndex = func_80081D34(actor->pointerToSyscallEntry);
        if (syscallIndex != 0)
        {
            sp24 = func_80081D80(syscallIndex);
        }
        else
        {
            sp24 = 0;
        }
        //Call the actor's event handler function
        sp28 = (func_80100368(actor))->eventHandler(actor, eventId, arg2);
        if ((syscallIndex != 0) && (sp24 == 0) && (sp28 <= 0))
        {
            func_800819B4((Syscall*)actor->pointerToSyscallEntry);
        }
        return sp28;
    }
    return -1;
}

s32 func_8010114C(Unk80132ED0* arg0, ActorEventId eventId, s32 arg2)
{
    return event_sendToActor(func_80106790(arg0), eventId, arg2);
}

s32 event_sendToActorsOfType(s32 propId, ActorEventId eventId, s32 arg2)
{
    Actor* actorToCheck;
    s32 LastIndex;
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    actorToCheck = actorList_getLast(&LastIndex);
    //Loop through the actors to find matching propIds to send events to
    while (actorToCheck != NULL)
    {
        if (!(actorToCheck->unk64_17) && (propId == actorToCheck->unk6C_9))
        {
            //Send the event to the actor's event handler
            temp_v0 = event_sendToActor(actorToCheck, eventId, arg2);
            if ((temp_v0 > 0) && (var_s0 == 0))
            {
                var_s0 = temp_v0;
            }
        }
        //Get the next Actor in the list
        actorToCheck = actorList_getNext(&LastIndex);
    }
    return var_s0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801012D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801013A8.s")
