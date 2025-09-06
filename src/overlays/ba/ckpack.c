#include "common.h"

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/backpack.h"
#include "overlays/ba/playerstate.h"

#include "core2/1EB5E70.h"

s32 func_8008CA74(PlayerState *self);

s32 babackpack_get_size(void) {
    return sizeof(BaBackpack);
}

void __babackpack_free(PlayerState *self) {
    func_8008ADBC(self->backpack->anctrl);
    self->backpack->anctrl = NULL;
}

void func_8080003C_babackpack(PlayerState *self) {
    self->backpack->anctrl = func_8008AD80(1);
    anctrl_setSmoothTransition(self->backpack->anctrl, 0);
    anctrl_setIndex(self->backpack->anctrl, 0x21);
    func_8008B10C(self->backpack->anctrl, baanim_getTimer(self));
    anctrl_setPlaybackType(self->backpack->anctrl, 1);
    anctrl_setDuration(self->backpack->anctrl, 1000.0f);
    anctrl_start(self->backpack->anctrl);
    func_8008B304(self->backpack->anctrl);
}

s32 babackpack_entrypoint_1(PlayerState *self) {
    if(self->backpack->unk0 != 0) {
        return func_800D674C(self->backpack->unk0);
    } else {
        return 0;
    }
}

void func_8080011C_babackpack(PlayerState *self, s32 arg1, f32 scale) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    
    self->backpack->scale = scale;
    func_8009272C(self, 1);
    if(self->backpack->unk4 == 0) {
        self->backpack->unk4 = func_800DBFF8();
    }

    if (self->backpack->unk0 == 0) {
        self->backpack->unk0 = arg1;
    }

    if (self->backpack->unk8 == 0) {
        sp2C = babackpack_entrypoint_1(self);
        if (func_800B26F0(sp2C)) {
            self->backpack->unkA = 1;
        } else {
            self->backpack->unkA = 0;
        }
        sp34 = self->backpack->unkA + 1;
        self->backpack->unk8 = func_80100D24(sp2C, self->backpack->unk0, sp34, func_800A25D0(self), 0, 0);
        self->backpack->unk9 = 0;
    }
}

s32 func_8080021C_babackpack(PlayerState *self) {
    s32 tmp_v1 = self->backpack->unk8;
    if (tmp_v1) {
        tmp_v1 = func_80100A74((s16)tmp_v1, self->backpack->unk9);
    } else {
        tmp_v1 = 0;
    }
    return tmp_v1;
}

void babackpack_entrypoint_2(PlayerState *self) {
    if (self->backpack->state == 7) {
        func_8008B10C(self->backpack->anctrl, baanim_getTimer(self));
        func_8008B304(self->backpack->anctrl);
        func_800DF41C(func_8008B4D4(self->backpack->anctrl));
        func_800A0714(self, self->backpack->unk0);
    } else if (self->backpack->unkA) {
        func_800DF818(func_8080021C_babackpack(self));
    } else {
        func_800DF41C(func_8008CA74(self));
    }
}

void babackpack_entrypoint_3(PlayerState *self, f32 *position, f32 *arg2, s32 arg3, f32 *arg4) {
    func_800DF738(self->backpack->unk4);
    func_800DF818(func_8080021C_babackpack(self));
    func_800DF720(func_80100AC4(self->backpack->unk8));
    if (self->backpack->state == 7) {
        func_8008B10C(self->backpack->anctrl, baanim_getTimer(self));
        func_8008B304(self->backpack->anctrl);
        func_800DF41C(func_8008B4D4(self->backpack->anctrl));
        func_800A0714(self, self->backpack->unk0);
    } else {
        func_800DF41C(func_8008CA74(self));
    }
    func_800DE448(position, arg2, self->backpack->scale, arg4, babackpack_entrypoint_1(self));
    if (self->backpack->unkA != 0) {
        self->backpack->unk9 ^= 1;
    }
}

s32 babackpack_get_state(PlayerState *self) {
    return self->backpack->state;
}

void babackpack_entrypoint_5(PlayerState *self, s32 arg1, s32 arg2) {
    func_800DBEFC(self->backpack->unk4, (s16) arg2, arg1);
}

void babackpack_entrypoint_6(PlayerState *self, s32 arg1, s32 arg2) {
    func_800DBEFC(self->backpack->unk4, 4, arg1);
}


f32 babackpack_get_scale(PlayerState *self) {
    return self->backpack->scale;
}

void babackpack_entrypoint_8(PlayerState *self) {
    babackpack_set_state(self, 0);
}

void babackpack_entrypoint_9(PlayerState *self) {
    self->backpack->unk0 = 0;
    self->backpack->unk4 = 0;
    self->backpack->unk8 = 0;
    self->backpack->unk9 = 0;
    self->backpack->unkA = 0;
    self->backpack->scale = 1.0f;
    self->backpack->anctrl = NULL; 
    self->backpack->state = 0;
    babackpack_set_state(self, 1);
}

void babackpack_set_state(PlayerState *self, BaBackpackState state) {
    s16 sp2E;
    s16 sp2C;
    s32 tmp_v1;

    if (self->backpack->state == BA_BACKPACK_STATE_7_FREE) {
        __babackpack_free(self);
    }

    if ((self->backpack->state != 0) && (self->backpack->state != 1)
        && (state != 0) && (state != 1)
    ) {
        tmp_v1 = self->backpack->unk8;
        if (tmp_v1) {
            func_80100E18((s16)tmp_v1);
        }
        self->backpack->unk8 = 0;
        self->backpack->unk0 = 0;
    }

    switch (state) {
        case 0:
            func_8009272C(self, 0);
            break;

        case 1:

            if (self->backpack->state == 1) {
                break;
            }

            func_8009272C(self, 0);

            if (self->backpack->unk4 != 0) {
                func_800DBFD8(self->backpack->unk4);
            }
            self->backpack->unk4 = NULL;

            tmp_v1 = self->backpack->unk8;
            if (tmp_v1) {
                func_80100E18((s16)tmp_v1);
            }

            self->backpack->unk8 = 0;
            self->backpack->unk0 = 0;

            break;

        case 2:
            func_8080011C_babackpack(self, 0x621, 1.0f);
            break;

        case 3:
            func_8080011C_babackpack(self, 0x625, 0.1f);
            break;

        case 4:
            func_8080011C_babackpack(self, 0x60A, 0.1f);
            break;

        case 5:
            func_8080011C_babackpack(self, 0x61B, 0.1f);
            break;

        case 6:
            func_8080011C_babackpack(self, 0x831, 0.1f);
            break;

        case 7:
            _bapreload_entrypoint_0(self, 0xB, &sp2E, &sp2C);
            func_8080003C_babackpack(self);
            func_8080011C_babackpack(self, sp2E, 1.0f);
            break;

        default:
            break;
    }
    self->backpack->state = state;
}
