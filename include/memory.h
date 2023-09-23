#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "types.h"

typedef enum {
    HEAP_BLOCK_STATE_EMPTY = 0,
    HEAP_BLOCK_STATE_USED  = 1,
    HEAP_BLOCK_STATE_PERM  = 2
} HeapBlockState;

struct HeapHeader {
    struct HeapHeader* prev;
    struct HeapHeader* next;
    s32 unk8;
    u32 allocation_overhead : 24;
    u32 state : 2;
    u32 unkC_26 : 2;
    u32 unkC_28 : 1;
    u32 unkC_29 : 1;
    u32 unkC_30 : 2;
};

struct EmptyHeapBlock {
    struct HeapHeader header;
    struct EmptyHeapBlock* prev_free;
    struct EmptyHeapBlock* next_free;
    long long padding; // Pads to 0x20 bytes
};

#define GET_BLOCK_HEADER(x) ((struct HeapHeader*)((char*)(x) - sizeof(struct HeapHeader)))

#define GET_BLOCK_TOTAL_SIZE(x) ((char*)(x)->next - (char*)(x))

#define GET_BLOCK_MEM_SIZE(block) \
    (GET_BLOCK_TOTAL_SIZE(block) - sizeof(struct HeapHeader))

#define BLOCK_CAN_HOLD(block, size) \
    (GET_BLOCK_MEM_SIZE(block) >= (size))

#define GET_BLOCK_CONTENTS(x) \
    ((char*)(x) + sizeof(struct HeapHeader))

#define AS_EMPTY_BLOCK(x) ((struct EmptyHeapBlock*)(x))

#define BLOCK_CAN_HOLD(block, size) \
    (GET_BLOCK_MEM_SIZE(block) >= (size))

#define HEAP_END() \
    (D_8007E990 + heap_bytes_allocated())

// The fixed block at the start of the heap
#define FIRST_BLOCK() \
    AS_EMPTY_BLOCK(D_8007E990)

// The initial block which contains the entire heap during initialization
#define INITIAL_BLOCK() \
    AS_EMPTY_BLOCK(D_8007E990 + sizeof(struct EmptyHeapBlock))

// The fixed block at the end of the heap
#define LAST_BLOCK() \
    AS_EMPTY_BLOCK(HEAP_END() - sizeof(struct EmptyHeapBlock))

// Used as the end of the heap block list, not a real block
#define TERMINATOR_BLOCK() \
    AS_EMPTY_BLOCK(HEAP_END())

// heap_start
extern char* D_8007E990;

// get_heap_size
s32 heap_bytes_allocated();

void* heap_alloc(s32 size);
void* heap_alloc_sided(s32 size, s32 alloc_side);

#endif
