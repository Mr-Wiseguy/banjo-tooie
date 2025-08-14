#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"

// This hacky structure allows coords to be accessed using
// coord->x, coord->y and coord->z, but also as
// coord->f[0], coord->f[1] and coord->f[2].
// In some places code only matches when using the float array.
typedef union Vec3f {
    struct {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    f32 f[3];
} Vec3f;

#endif // __COMMON_H__
