#include "common.h"

#include "overlays/ba/alarm.h"
#include "overlays/ba/playerstate.h"

#include "core2/1E75920.h"
#include "core2/1E9A960.h"
#include "core2/1ECA640.h"

s32 baalarm_get_size(void) {
    return sizeof(BaAlarm);
}

void baalarm_free(PlayerState *self) {
    if (self->alarm->id) {
        func_800C2FDC(self->alarm->id);
    }
    self->alarm->id = 0;
}

void baalarm_new(PlayerState *self) {
    self->alarm->id = func_800C2E04();
    func_800C3418(self->alarm->id, 0);
    func_800C330C(self->alarm->id, 2);
    func_800C431C(self->alarm->id, 0);
    self->alarm->active = 1;
}

void baalarm_entrypoint_3(PlayerState *self, f32 arg1, f32 arg2) {
    f32 f20;
    f32 f22;
    f32 sp64[3];
    s32 s0;

    if (self->alarm->active == 0) {
        return;
    }

    func_8009C128(self, sp64);
    if (arg2 < 1.0f) {
        if (arg1 != arg2) {
            func_80800294_baalarm(self->alarm->id, 2);
            func_800C35E8(self->alarm->id, sp64);
            func_800C301C(self->alarm->id, 0x414);
            func_800C3058(self->alarm->id, 0x7FFF);
            func_800C3BDC(self->alarm->id);
        }
    } else {
        f20 = 5.0f;
        s0 = 0;
        while(0.0f < f20){
            if(f20 <= arg1 && arg2 < f20){
            func_800C35E8(self->alarm->id, sp64);
                func_800C301C(self->alarm->id, (s0) ? 0x41C: 0x438);
                func_800C3058(self->alarm->id, 0x7FFF);
                func_80800294_baalarm(self->alarm->id, 3);
                func_800C3BDC(self->alarm->id);
                break;
            }
            s0 ^= 1;
            f20 -= func_800F10B4(f20, 0.0f, 5.0f, 0.1f, 0.25f);
        }
    }
}

void func_80800294_baalarm(u8 id, s32 arg1) {
    if (func_800C39A0(id) != arg1){
        func_800C3CE8(id);
        func_800C330C(id, arg1);
    }
}
