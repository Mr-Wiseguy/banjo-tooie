#ifndef __CORE1_HEAP__
#define __CORE1_HEAP__

#include "common.h"

s32 func_8001A6C0(s32 arg0, s32 size);
s32 has_free_block_after(s32 size);
void* heap_alloc(s32 size);

#endif
