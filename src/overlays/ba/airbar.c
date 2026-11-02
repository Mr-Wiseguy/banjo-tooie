#include "ba/airbar.h"

void baairbar_entrypoint_0(PlayerState *self, s32 arg1) {
    if (flag_getValue(FLAG_0E9_MAGIC_SUNLIGHT_OXYGENATED_WATER) && _gclevel_entrypoint_4(0x10)) 
    {
        return;
    }
    
    if (!func_8008DAA8(self)) 
    {
        return;
    }

    if (bs_getSplitStatus() == SPLIT_STATE_TALON_TORPEDO) 
    {
        return;
    }

    switch (arg1) 
    {
        case 1:
            func_800CF494();
            break;

        case 2:
            func_800CF2D4(1);
            break;
    }
}
