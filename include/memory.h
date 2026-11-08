#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "types.h"
#include "core1/heap.h"

void rare_memcpy(void* dst, void* src, int length);
void aligned4_memcpy(void* dst, void* src, int length);
void aligned8_memcpy(void* dst, void* src, int size);

void rare_memmove(void* dst, void* src, int length);
void aligned4_memmove(void* dst, void* src, int length);

void rare_memset(void* dst, u8 value, int length);
void aligned8_memset(void* dst, u32 value, int size);
void* defrag(void* mem);


#endif
