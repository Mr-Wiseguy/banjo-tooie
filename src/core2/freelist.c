#include "memory.h"
#include "freelist.h"

void freelist_clear(FreeList* list) {
    s32 i;
    FreeListElement* current_element;

    current_element = list->data;
    for (i = 1; i < list->capacity; i++) {
        current_element->next_free = i;
        current_element = (FreeListElement*)((u8*)current_element + list->element_size);
    }
    current_element->next_free = 0;
}

void* freelist_at(FreeList* list, s32 index) {
    return (u8*)list->data + index * list->element_size;
}

s16 freelist_capacity(FreeList* list) {
    return list->capacity;
}

void* freelist_data(FreeList* list) {
    return list->data;
}

void* freelist_next(FreeList** list, s32* index_out) {
    s32 new_count;
    FreeList* cur_list;
    FreeListElement* cur_element;
    FreeListElement* next_element;
    s32 prev_count;
    s32 i;

    cur_list = *list;
    cur_element = cur_list->data;

    // If there's no free elements, resize the freelist.
    if (cur_element->next_free == 0) {
        prev_count = cur_list->capacity;
        new_count = prev_count + 10;
        cur_list = (FreeList*)heap_realloc(cur_list, sizeof(FreeList) + (cur_list->element_size * new_count));
        cur_element = cur_list->data;
        cur_list->capacity = new_count;
        *list = cur_list;
        
        // Seek backwards from the end of the freelist and populate the next_free of every new element.
        for (i = new_count - 1, next_element = (FreeListElement*)((u8*)cur_list->data + i * cur_list->element_size); i >= prev_count; i--) {
            next_element->next_free = cur_element->next_free;
            cur_element->next_free = i;
            next_element = (FreeListElement*)((u8*)next_element - cur_list->element_size);
        }
    }
    i = cur_element->next_free;
    next_element = (FreeListElement*)((u8*)cur_element + i * cur_list->element_size);
    *index_out = i;
    cur_element->next_free = next_element->next_free;
    return next_element;
}

s32 freelist_is_element_alive(FreeList* list, s32 index) {
    FreeListElement* start;
    FreeListElement* cur;

    start = list->data;
    for (cur = start; cur->next_free != 0; cur = ((FreeListElement*)((u8*)start + cur->next_free * list->element_size))) {
        if (cur->next_free == index) {
            return 0;
        }
    }
    return 1;
}

s32 freelist_used_count(FreeList* list) {
    FreeListElement* start;
    FreeListElement* cur;
    s32 free_count = 1;

    start = list->data;
    for (cur = start; cur->next_free != 0; cur = ((FreeListElement*)((u8*)start + cur->next_free * list->element_size))) {
        free_count++;
    }
    return list->capacity - free_count;
}

void freelist_free(FreeList *list) {
    heap_free(list);
}

FreeList* freelist_new(s32 element_size, s32 capacity) {
    FreeList *ret;
    capacity++;
    ret = (FreeList *) heap_alloc(element_size * capacity + sizeof(FreeList));
    ret->element_size = element_size;
    ret->capacity = capacity;
    freelist_clear(ret);
    return ret;
}

void freelist_erase(FreeList* list, s32 index) {
    FreeListElement* element = (FreeListElement*)((u8*)list->data + index * list->element_size);
    element->next_free = list->data[0].next_free;
    list->data[0].next_free = index;
}

FreeList* freelist_defrag(FreeList* list) {
    return (FreeList*)defrag(list);
}
