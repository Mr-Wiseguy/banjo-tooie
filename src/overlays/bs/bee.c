#include "bs/bee.h"

/* .code */

void bsbee_entrypoint_0(PlayerState* self) {
    if (func_8009E74C(self, 1) == 0) {
        func_800947EC(self, 1, 0);
        func_8009BF5C(self, 0.0f);
        baroll_setIdeal(self, 0.0f);
        bastick_popZone(self);
        func_800A0CF4(self, 0);
        func_800A0CE8(self, 0);
        baflag_clear(self, BA_FLAG_3);
        baflag_clear(self, BA_FLAG_4);
        func_8009E474(self);
        func_80095A40(self);
        _babee_entrypoint_3(self);
        func_80092864(self, 1.0f);
    }
}

void bsbee_entrypoint_1(PlayerState* self) {
    if (func_8009E77C(self, 1) == 0) {
        _babee_entrypoint_4(self);
        func_8009BFE4(self, 1000.0f, 12.0f);
        baroll_setAngularVelocity(self, 1000.0f, 12.0f);
        func_800959C8(self, 50.0f, 25.0f);
        baflag_set(self, BA_FLAG_3);
        baflag_set(self, BA_FLAG_4);
        bastick_pushZone(self);
        bastick_setZoneMax(self, 0, 0.03f);
        bastick_setZoneMax(self, 1, 1.0f);
        func_8009E4AC(self);
        func_8009E55C(self, 0, 30.0f);
        func_8009E55C(self, 1, 40.0f);
        func_800959C8(self, 75.0f, 43.0f);
        func_8009590C(self, 75.0f);
        func_800947EC(self, 1, 1);
        func_80092864(self, 1.0999909f);
    }
}

void bsbee_entrypoint_2(PlayerState* self) {
    _babee_entrypoint_8(self);
}
