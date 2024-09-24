#ifndef __FREELIST_H__
#define __FREELIST_H__

#include <ultra64.h>

typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;

typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

void freelist_clear(FreeList* list);
void* freelist_at(FreeList* list, s32 index);
s16 freelist_capacity(FreeList* list);
void* freelist_data(FreeList* list);
void* freelist_next(FreeList** list, s32* index_out);
s32 freelist_is_element_alive(FreeList* list, s32 index);
s32 freelist_used_count(FreeList* list);
void freelist_free(FreeList *list);
FreeList* freelist_new(s32 element_size, s32 capacity);
void freelist_erase(FreeList* list, s32 index);
FreeList* freelist_defrag(FreeList* list);

#endif
