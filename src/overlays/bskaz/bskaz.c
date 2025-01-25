#include "common.h"

#include "bs/kaz.h"

void bskaz_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != arg2) {
        if (arg1 == 3) {
            func_800962B0(arg0, 0);
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

s32 bskaz_entrypoint_3(PlayerState *self) {
    if (func_8008E430() != 0) {
        return 0x186;
    }
    
    if (func_8008D3B0(self) != 0) {
        return 0x161;
    }
    
    if ((bakey_held(self, 1) != 0) && (func_800C6E38(0x24) != 0)) {
        return 0xC6;
    }
    
    return 0xBD;
}


s32 bskaz_entrypoint_4(s32 arg0) {
    if (func_8009EA2C() != 0) {
        return 0x18B;
    }

    return 0xC2;
}
