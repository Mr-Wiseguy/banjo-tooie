#ifndef __BUFERS_H__
#define __BUFERS_H__

#include <ultra64.h>

struct Overlay {
    u8* rom_start;
    u8* rom_end;
};

extern struct Overlay D_80012010[];

#endif
