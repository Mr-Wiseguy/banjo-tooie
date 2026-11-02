#ifndef __CORE2_1EDA900_H__
#define __CORE2_1EDA900_H__

#include "common.h"
#include "overlays.h"
#include "props.h"
#include "core2/1ED8C80.h"
#include "core2/1EDFED0.h"
#include "actorevents.h"

void func_80101038(f32*);
f32 func_80101068();
//Store a pointer in reserved memory
void func_80101074(void*);
//Retrieve a pointer from reserved memory
void* func_80101080(void);

//Send an event to the actor's event handler
s32 event_sendToActor(Actor*, ActorEventId, s32);

//Send an event to Actor that has Unk80132ED0*
s32 func_8010114C(Unk80132ED0*, ActorEventId, s32);

//Send an event to items of type
s32 event_sendToActorsOfType(s32 propId, ActorEventId eventId, s32);
void func_80101238(s32, s32);
void func_801013A8(f32*, s32, s32);
#endif // __CORE2_1EDA900_H__
