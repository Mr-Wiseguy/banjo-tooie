#include "bs/kaz.h"

void bskaz_entrypoint_0(PlayerState *self, s32 arg1, s32 arg2) {
    if (arg1 != arg2) {
        if (arg1 == 3) {
            func_800962B0(self, 0);
        }
    }
}

void bskaz_entrypoint_1(PlayerState *self) {
    _bashoes_entrypoint_15();
    _bashoes_entrypoint_7(self, &_bskaz_entrypoint_0);
    _bashoes_entrypoint_8(self, &_bskazmove_entrypoint_11);
    bastick_func_8009F258(self);
    baflag_set(self, BA_FLAG_3);
    func_80092864(self, 0.8999939);
}

void bskaz_entrypoint_2(PlayerState *self) {
    baflag_clear(self, 3);
    _bashoes_entrypoint_14(self);
    func_80092864(self, 1);
}

BanjoStateId bskaz_entrypoint_3(PlayerState *self) {
    if (player_wearingSpringyStep(self) != 0) {
        return BS_STATE_186;
    }
    
    if (player_canFly(self) != 0) {
        return BS_STATE_161;
    }
    
    if ((bakey_held(self, BUTTON_Z) != 0) && (ability_getValue(ABILITY_24_LEG_SPRING) != 0)) {
        return BS_STATE_C6;
    }
    
    return BS_STATE_BD_KAZ_JUMP;
}


BanjoStateId bskaz_entrypoint_4(PlayerState *self) {
    if (bs_getDragonKazooieState() != 0) {
        return BS_STATE_18B;
    }

    return BS_STATE_C2;
}
