#ifndef __CORE2_VECTOR_H__
#define __CORE2_VECTOR_H__

#include "common.h"
#include "core1/memory.h"

typedef struct {
    s32 element_size;
    void* begin;
    void* end;
    void* mem_end;
    u8 data[];
} Vector;

Vector* func_800B2890(s16 arg0);
void vector_clear(Vector* vec);
void* vector_begin(Vector* vec);
void* vector_at(Vector* vec, s32 index);
s32 vector_index_of(Vector* vec, void* element);
s32 vector_size(Vector* vec);
void* vector_end(Vector* vec);
void* vector_push_back(Vector** vec_ptr);
void* func_800B2A58(s16 arg0);
void* vector_insert(Vector** vec_ptr, s32 index);
void* func_800B2C1C(s16 arg0, s32 index);
void vector_free(Vector* vec);
void func_800B2D48(s16 arg0);
Vector* vector_new(u32 element_size, u32 count);
s16 func_800B2DC0(u32 element_size, u32 count);
void vector_erase(Vector* vec, u32 index);
void vector_erase_unordered(Vector *vec, u32 index);
void vector_pop_back_n(Vector* vec, u32 count);
void vector_assign(Vector* vec, s32 index, void* value);
Vector* vector_defrag(Vector* vec);
void vector_update_pointers(Vector* vec);

#endif // __CORE2_VECTOR_H__
