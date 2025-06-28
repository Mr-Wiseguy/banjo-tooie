#include "common.h"

#include "overlays/ba/key.h"

#define AS_BOOL(x) ((x) != 0)


s32 bakey_getStructSize(void) {
    return sizeof(BaKey);
}

s32 bakey_getControllerIndex(PlayerState *self) {
    return func_800BCCF4(self->key->unk0);
}

void bakey_func_8009191C(PlayerState *self, ButtonId id, s32 arg2) {
    func_800BCCFC(self->key->unk0, id, arg2);
}

void bakey_func_80091940(PlayerState *self, ButtonId id, s32 arg2) {
    func_800BCD78(self->key->unk0, id, arg2);
}

s32 bakey_func_80091964(PlayerState *self){
    return self->key->unk9;
}

s32 bakey_heldCount(PlayerState *self, ButtonId id) {
    if(self->key->prev_state[id]) {
        return 0;
    }
    return func_800BCF28(self->key->unk0, id);
}

s32 bakey_releaseCount(PlayerState *self, ButtonId id) {
    return func_800BCEC0(self->key->unk0, id);
}

void bakey_getStick(PlayerState *self, f32 pStickValues[2]) {
    func_800BCF90(self->key->unk0, pStickValues);
}

int bakey_held(PlayerState *self, ButtonId id) {
    if (self->key->prev_state[id]) {
        return 0;
    }
    return func_800BCE84(self->key->unk0, id);
}

int bakey_released(PlayerState *self, ButtonId id) {
    return !func_800BCE84(self->key->unk0, id);
}

int bakey_pressed(PlayerState *self, ButtonId id) {
    if (self->key->prev_state[id]) {
        return 0;
    }
    return func_800BD030(self->key->unk0, id);
}

int bakey_newlyReleased(PlayerState *self, ButtonId id) {
    return func_800BCFC4(self->key->unk0, id);
}

void bakey_free(PlayerState *self) {
    func_800BD09C(self->key->unk0);
}

void bakey_defrag(PlayerState *self) {
    self->key->unk0 = func_800BD0BC(self->key->unk0);
}

void bakey_init(PlayerState *self) {
    ButtonId id;
    self->key->unk0 = func_800BD0DC(2);
    self->key->unk9 = 0;
    self->key->unk4 = 0;
    self->key->unk8 = 1;
    for (id = 0; id < BUTTON_COUNT; id++) {
        self->key->state[id] = 0;
        self->key->prev_state[id] = 0;
    }
}

void bakey_setControllerIndex(PlayerState *self, s32 arg1) {
    func_800BD268(self->key->unk0, arg1);
}

void bakey_func_80091C14(PlayerState *self, s32 value) {
    int i;
    for (i = 0; i < BUTTON_COUNT; i++) {
        bakey_setState(self, i, value);
    } 
}

void bakey_func_80091C74(PlayerState *self, s32 arg1) {
    self->key->unk9 = arg1;
}

s32 bakey_setState(PlayerState *self, ButtonId id, int arg2) {
    int value = self->key->state[id];
    if (AS_BOOL(value == 1) && AS_BOOL(arg2 == 2)) {
        return self->key->prev_state[id];
    }

    if (arg2 != 0) {
        self->key->unk4 |= (1 << id);
    } else {
        self->key->unk4 &= ~(1 << id);
    }
    self->key->state[id] = arg2;
    return self->key->prev_state[id];
}

int bakey_getBitfield(PlayerState *self) {
    return (self->key->unk4 ^ 0x3FFF) == 0;
}

void bakey_update(PlayerState *self) {
    ButtonId id;
    func_800BD2D0(self->key->unk0);
    if (!func_80091E80(self, 0x40) || self->key->unk9 || self->key->unk8) {
        self->key->unk8 = 0;
        for(id = 0; id < BUTTON_COUNT; id++){
            bakey_setState(self, id, 2);
        }
    }
    for(id = 0; id < BUTTON_COUNT; id++){
        self->key->prev_state[id] = self->key->state[id];
        if(self->key->state[id]) {
            if (self->key->state[id] == 2) {
                bakey_setState(self, id, 0);
            }
        }
    }
}
