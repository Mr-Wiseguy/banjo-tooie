#include "common.h"

#include "ba/translate.h"
#include "ba/yaw.h"
#include "db/skeleton.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1EC8070.h"

void batranslate_entrypoint_3(PlayerState *self, s32 arg1);

s32 batranslate_entrypoint_0(void) {
    return sizeof(BaTranslate);
}

void func_80800008_batranslate(PlayerState *self, f32 arg1[3]) {
    f32 yaw;

    ml_vec3f_apply_scale(arg1, _dbskeleton_entrypoint_1(func_800B27E0(func_80092B04(self, 0))));

    yaw = yaw_get(self);
    func_800EF934(arg1, arg1, yaw);
}

void batranslate_entrypoint_1(PlayerState *self) {}

void batranslate_entrypoint_2(PlayerState *self) {
    ml_vec3f_clear(self->translate->unk8);
    ml_vec3f_clear(self->translate->unk14);
    self->translate->unk0 = 0;
    self->translate->unk4 = 0;
    batranslate_entrypoint_3(self, 1);
}

void batranslate_entrypoint_3(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 1:
            func_8008C9E4(self, 0);
            func_8009ADF0(self, 6, 0);
            break;

        case 2:
            ml_vec3f_clear(self->translate->unk8);
            self->translate->unk0 = 2;
            func_8009ADF0(self, 6, 1);
            break;
    }
    self->translate->unk4 = arg1;
}

void batranslate_entrypoint_4(PlayerState *self) {
    f32 sp2C[3];
    if (self->translate->unk4 != 2) {
        return;
    }
    if ((self->translate->unk0 != 0)) {
        self->translate->unk0--;
        if(self->translate->unk0 != 0) {
            return;
        }
        func_8008C9E4(self, 1);
    }
    player_getCoords(self, sp2C);
    ml_vec3f_subtract(sp2C, self->translate->unk8);
    func_8008C958(self, self->translate->unk8);
    func_80800008_batranslate(self, self->translate->unk8);
    ml_vec3f_add(sp2C, self->translate->unk8);
    player_setCoords(self, sp2C);
}
