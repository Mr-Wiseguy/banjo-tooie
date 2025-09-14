#include "core2/1E8DC70.h"

extern s32 D_80127EF0[3];


void func_800B4380(void)
{
    s32 index;
    s32 temp_a0;

    for (index = 0; index < 3; index++)
    {
        temp_a0 = D_80127EF0[index];
        if (temp_a0 != 0)
        {
            D_80127EF0[index] = vector_defrag(temp_a0);
        }
    }
}
