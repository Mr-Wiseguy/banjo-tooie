#include "common.h"
#include "core1/heap.h"
#include "core1/1E29B60.h"

s32 func_8001E7E0(void) {
    return 0x80400000;
}

extern s32 D_8007E994;
extern s32 D_8007E998;

void func_8001E7E8(void) {
    s32 temp_t7;

    D_8007E998 = func_8001E7E0();
    D_8007E994 = D_8007E990 = D_8007E998 - func_8001E830();
}


s32 func_8001E830(void) 
{
    return 0x2C8800;
}
