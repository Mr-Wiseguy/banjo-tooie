#include "overlays/ba/airr.h"

#include "overlays/ba/playerstate.h"

void baairbar_entrypoint_0(PlayerState *self, s32 arg1) {
    if (func_800DA298(0xE9) && _gclevel_entrypoint_4(0x10)) {
        return;
    }
    
    if (!func_8008DAA8(self)) {
        return;
    }

    if (func_800F8B88() == 3) {
        return;
    }

    switch (arg1) {
        case 1:
            func_800CF494();
            break;

        case 2:
            func_800CF2D4(1);
            break;
    }
}
