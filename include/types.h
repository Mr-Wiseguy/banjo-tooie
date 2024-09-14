#ifndef __TYPES_H__
#define __TYPES_H__

#include <ultra64.h>

typedef u32 uintptr_t;

#define offsetof(type, member) \
    ((size_t)&((type*)0)->member)

#endif
