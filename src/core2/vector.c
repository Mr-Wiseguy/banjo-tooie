#include "memory.h"
#include "vector.h"

// Alternate memory management functions?
s16 func_8001B668(s32, s32); // alloc
void* func_8001B798(s16); // get
void* func_8001B710(s16, s32); // realloc
void func_8001B754(s16); // free

// vector getter related to func_800B2D70
Vector* func_800B2890(s16 arg0) {
    return (Vector*)func_8001B798(arg0);
}

void vector_clear(Vector* vec) {
    vec->end = vec->begin;
}

void* vector_begin(Vector* vec) {
    return vec->begin;
}

void* vector_at(Vector* vec, s32 index) {
    return (u8*)vec->begin + index * vec->element_size;
}

s32 vector_index_of(Vector* vec, void* element) {
    return ((u8*)element - (u8*)vec->begin) / vec->element_size;
}

s32 vector_size(Vector* vec) {
    return ((u8*)vec->end - (u8*)vec->begin) / vec->element_size;
}

void* vector_end(Vector* vec) {
    return vec->end;
}

void* vector_push_back(Vector** vec_ptr) {
    void* new_element;
    Vector* vec;
    s32 size;
    s32 mem_size;

    vec = *vec_ptr;
    if(vec->end == vec->mem_end) {
        size = ((u8*)vec->end - (u8*)vec->begin)/vec->element_size;
        mem_size = size + 5;
        vec = heap_realloc(vec, mem_size * vec->element_size + sizeof(Vector));
        vec->begin = &vec->data;
        vec->end = (u8*)vec->begin + size * vec->element_size;
        vec->mem_end = (u8*)vec->begin + mem_size * vec->element_size;
        *vec_ptr = vec; 
    }
    new_element = vec->end;
    vec->end = (u8*)vec->end + vec->element_size;
    return new_element;
}

// variant of vector_push_back
void* func_800B2A58(s16 arg0) {
    void* new_element;
    Vector* vec;
    s32 size;
    s32 mem_size;

    vec = func_8001B798(arg0);
    if(vec->end == vec->mem_end) {
        size = ((u8*)vec->end - (u8*)vec->begin)/vec->element_size;
        mem_size = size + 5;
        vec = func_8001B710(arg0, mem_size * vec->element_size + sizeof(Vector));
        vec->begin = &vec->data;
        vec->end = (u8*)vec->begin + size * vec->element_size;
        vec->mem_end = (u8*)vec->begin + mem_size * vec->element_size;
    }
    new_element = vec->end;
    vec->end = (u8*)vec->end + vec->element_size;
    return new_element;
}

void* vector_insert(Vector** vec_ptr, s32 index) {
    Vector* vec;
    s32 i;

    vector_push_back(vec_ptr);
    vec = *vec_ptr;
    i = ((u8*)vec->end - (u8*)vec->begin) / vec->element_size;
    while(index < --i) {
        aligned4_memcpy((u8*)vec->begin + i *vec->element_size, (u8*)vec->begin + (i - 1) * vec->element_size, vec->element_size);
    }
    return (u8*)vec->begin + index * vec->element_size;
}

// variant of vector_insert (unused)
void* func_800B2C1C(s16 arg0, s32 index) {
    Vector* vec;
    s32 i;

    vec = func_8001B798(arg0);
    func_800B2A58(arg0);
    //! BUG: Use after free: func_800B2A58 can reallocate the vector, so `vec` may be invalid at this point.
    i = ((u8*)vec->end - (u8*)vec->begin) / vec->element_size;
    while(index < --i) {
        aligned4_memcpy((u8*)vec->begin + i *vec->element_size, (u8*)vec->begin + (i - 1) * vec->element_size, vec->element_size);
    }
    return (u8*)vec->begin + index * vec->element_size;
}

void vector_free(Vector* vec) {
    heap_free(vec);
}

// variant of vector_free, paired up with func_800B2DC0
void func_800B2D48(s16 arg0) {
    func_8001B754(arg0);
}

Vector* vector_new(u32 element_size, u32 count) {
    Vector* vec = heap_alloc(count * element_size + sizeof(Vector));

    vec->element_size = element_size;
    vec->begin = vec->data;
    vec->end = vec->data;
    vec->mem_end = (u8*)vec->end + count * element_size;
    return vec;
}

// variant of vector_new
s16 func_800B2DC0(u32 element_size, u32 count) {
    s16 ret = func_8001B668(5, count * element_size + sizeof(Vector));
    Vector* vec = func_8001B798(ret);

    vec->element_size = element_size;
    vec->begin = vec->data;
    vec->end = vec->data;
    vec->mem_end = (u8*)vec->end + count * element_size;
    return ret;
}

void vector_erase(Vector* vec, u32 index) {
    u8* cur_element = (u8*)vec->begin + index * vec->element_size;\
    u8* next_element = (u8*)vec->begin + (index + 1) * vec->element_size;\
    u32 size = (u8*)vec->end - (u8*)vec->begin;
    
    aligned4_memcpy(cur_element, next_element, size - (index + 1) * vec->element_size);
    vec->end = (u8*)vec->end - vec->element_size;
}

// Erases the element at the given index and swaps the last one into it, then shrinks the vector by 1 element.
void vector_erase_unordered(Vector *vec, u32 index) {
    u8* cur_element = (u8*)vec->begin + index * vec->element_size;\
    u8* last_element = (u8*)vec->end - vec->element_size;
    
    aligned4_memcpy(cur_element, last_element, vec->element_size);
    vec->end = (u8*)vec->end - vec->element_size;
}

void vector_pop_back_n(Vector* vec, u32 count) {
    vec->end = (u8*)vec->end - count * vec->element_size;
}

void vector_assign(Vector* vec, s32 index, void* value) {
    aligned4_memcpy((u8*)vec->begin + index * vec->element_size, value, vec->element_size);
}

Vector* vector_defrag(Vector* vec) {
    s32 old_size;
    s32 old_mem_size;

    old_size = (u8*)vec->end - (u8*)vec->begin;
    old_mem_size = (u8*) vec->mem_end - (u8*)vec->begin;
    vec = (Vector*)defrag(vec);
    vec->begin = vec->data;
    vec->end = (u8*)vec->begin + old_size;
    vec->mem_end = (u8*)vec->begin + old_mem_size;
    return vec;
}

void vector_update_pointers(Vector* vec) {
    u32 size = (u8*)vec->end - (u8*)vec->begin;
    u32 mem_size = (u8*)vec->mem_end - (u8*)vec->begin;
    vec->begin = vec->data;
    vec->end = (u8*)vec->begin + size;
    vec->mem_end = (u8*)vec->begin + mem_size;
}
