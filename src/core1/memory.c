#include <ultra64.h>

// A custom version of memcpy. It differs from the standard memcpy by having a void return type instead of void* and a signed length.
void rare_memcpy(void* dst, void* src, int length) {
    while (length > 0) {
        *(u8*)dst = *(u8*)src;
        length--;
        dst = (u8*)dst + 1;
        src = (u8*)src + 1;
    }
}

// A custom version of memcpy that copies data in 4 byte intervals. The inputs must have an alignment of 4 bytes to work correctly.
void aligned4_memcpy(void* dst, void* src, int length) {
    while (length > 0) {
        *(u32*)dst = *(u32*)src;
        length -= 4;
        dst = (u32*)dst + 1;
        src = (u32*)src + 1;
    }
}

// A custom version of memmove. It differs from the standard memmove by having a void return type instead of void* and a signed length.
void rare_memmove(void* dst, void* src, int length) {
    // Pick a direction to copy in to avoid overwriting any bytes in the source before reading them.

    // Copy forwards if the source is ahead of the destination.
    if (dst < src) { //copy
        while (length--) {
            *(u8*)dst = *(u8*)src;
            dst = (u8*)dst + 1;
            src = (u8*)src + 1;
        }
    }
    // Otherwise, copy backwards.
    else {
        dst = (u8*)dst + length - 1;
        src = (u8*)src + length - 1;
        while (length--) {
            *(u8*)dst = *(u8*)src;
            dst = (u8*)dst - 1;
            src = (u8*)src - 1;
        }
    }
}

// A custom version of memmove that copies data in 4 byte intervals. The inputs must have an alignment of 4 bytes to work correctly.
void aligned4_memmove(void* dst, void* src, int length) {
    // Adjust the length to account for the 4 byte copies.
    // Cast denominator to s32 because this must be signed division to match.
    length /= (s32)sizeof(u32);

    // Pick a direction to copy in to avoid overwriting any bytes in the source before reading them.

    // Copy forwards if the source is ahead of the destination.
    if (dst < src) { //copy
        while (length--) {
            *(u32*)dst = *(u32*)src;
            dst = (u32*)dst + 1;
            src = (u32*)src + 1;
        }
    }
    // Otherwise, copy backwards.
    else {
        dst = (u32*)dst + length - 1;
        src = (u32*)src + length - 1;
        while (length--) {
            *(u32*)dst = *(u32*)src;
            dst = (u32*)dst - 1;
            src = (u32*)src - 1;
        }
    }
}

// A custom version of memset. It differs from the standard memset by having a void return type instead of void*, a u8 value type and a signed length.
void rare_memset(void* dst, u8 value, int length) {
    u8* cur = (u8*)dst;
    u8* end = (u8*)dst + length;
    while (cur < end) {
        *cur = value;
        cur++;
    }
}
