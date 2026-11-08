#include "core2/1EE7920.h"

extern void* D_80127614;

void func_8010E030(void)
{
    if (D_80127614 != NULL)
    {
        D_80127614 = defrag(D_80127614);
    }
}