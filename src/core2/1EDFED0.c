#include "core2/1EDFED0.h"

extern Vector* D_80136EE0;

void actorList_new(void)
{
	D_80136EE0 = vector_new(sizeof(Actor), 0x1EU);
}

void actorList_free(void)
{
	vector_free(D_80136EE0);
	D_80136EE0 = NULL;
}

void actorList_defrag()
{
    if(D_80136EE0)
    {
       D_80136EE0 = vector_defrag(D_80136EE0);
    }
}
void* actorList_pushback(s32* indexCreated)
{
	void* newElementAddress;

	* indexCreated = 0;
	newElementAddress = vector_push_back(&D_80136EE0);
	*indexCreated = vector_index_of(D_80136EE0, newElementAddress);
	bzero(newElementAddress, sizeof(Actor));
	return newElementAddress;
}

//Erase an actor at index
void actorList_erase(u32 index)
{
	Unk80132ED0* temp_v1;
	//Erase the Actor
	vector_erase_unordered(D_80136EE0, index);
	if ((s32)index < vector_size(D_80136EE0))
	{
		//Get the new actor that is at this index
		temp_v1 = ((Actor*)vector_at(D_80136EE0, index))->unk0;
		//Update the actor's index array reference
		temp_v1->unk18_5 = index;
	}
}

//Get Number of Active Actors
s32 actorList_getSize(void)
{
	if (D_80136EE0 == NULL)
	{
		return 0;
	}
	return vector_size(D_80136EE0);
}

//Get Actor at index
Actor* actorList_getAtIndex(s32 arg0)
{
	return vector_at(D_80136EE0, arg0);
}

Actor* func_80106790(Unk80132ED0* arg0)
{
	return vector_at(D_80136EE0, arg0->unk18_5);
}

Actor* actorList_getLast(s32* lastIndex)
{
    if (D_80136EE0 == NULL)
    {
        return NULL;
    }
    *lastIndex = vector_size(D_80136EE0) - 1;
    if (*lastIndex >= 0)
    {
        return vector_at(D_80136EE0, *lastIndex);
    }
    return NULL;
}

Actor* actorList_getNext(s32* currentIndex)
{
    s32 NumActors;
    if (D_80136EE0 == NULL)
    {
        return NULL;
    }
    NumActors = vector_size(D_80136EE0);
    //Clamp index if it is above the size of the vector
    if (*currentIndex >= NumActors)
    {
        *currentIndex = NumActors;
    }
    if (*currentIndex > 0)
    {
        //Decrement index and return the actor
        *currentIndex = *currentIndex - 1;
        return vector_at(D_80136EE0, *currentIndex);
    }
    else
    {
        return NULL;
    }
}

Actor* func_801068A8(s32* index)
{
	s32 numActors;

	if (D_80136EE0 == NULL)
	{
		return NULL;
	}
	numActors = vector_size(D_80136EE0);
	if (numActors > 0)
	{
		if ((*index < 0) || (*index >= numActors))
		{
			*index = 0;
		}
		return vector_at(D_80136EE0, *index);
	}
	return NULL;
}

void* func_80106920(s32* arg0)
{
	s32 numActors;

	if (D_80136EE0 == NULL)
	{
		return NULL;
	}
	numActors = vector_size(D_80136EE0);
	(*arg0)--;
	if ((*arg0 < 0) || (*arg0 >= numActors))
	{
		*arg0 = numActors - 1;
	}
	if (*arg0 >= 0)
	{
		return vector_at(D_80136EE0, *arg0);
	}
	return NULL;
}

s32 func_801069A4(Unk80132ED0* arg0)
{
	s32 isActorOutsideActorArrayBounds;
	if (D_80136EE0 == NULL)
	{
		return 0;
	}
	if ((arg0 == NULL) || !arg0->unk18_16)
	{
		return 0;
	}
	isActorOutsideActorArrayBounds = (s32)arg0->unk18_5 < vector_size(D_80136EE0);
	return isActorOutsideActorArrayBounds;
}