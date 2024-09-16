#ifndef __TYPES_H__
#define __TYPES_H__

#include <ultra64.h>

#define SQ(x) ((x) * (x))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

typedef u32 uintptr_t;

#define offsetof(type, member) \
    ((size_t)&((type*)0)->member)

#define UNUSED

#endif
