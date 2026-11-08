#ifndef __CORE2_1EDFED0_H__
#define __CORE2_1EDFED0_H__

#include "common.h"
#include "freelist.h"
#include "vector.h"

//Create new Actor Array
void actorList_new(void);
//Free Actor Array
void actorList_free(void);
//Defrag Actors
void actorList_defrag();
//Allocate New Actor
void* actorList_pushback(s32*);
//Erase an actor at index
void actorList_erase(u32);
//Get Number of Active Actors
s32 actorList_getSize(void);
//Get Actor at index
Actor* actorList_getAtIndex(s32);
Actor* func_80106790(Unk80132ED0 *);
//Get the last actor in list
Actor* actorList_getLast(s32*);
//Get the next actor in the list
Actor* actorList_getNext(s32* currentIndex);
Actor* func_801068A8(s32* index);
s32 func_801069A4(Unk80132ED0*);

#endif
