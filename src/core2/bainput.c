#include "common.h"

#include "ba/input.h"

#include "ba/key.h"
#include "ba/flag.h"
#include "core2/1E66990.h"
#include "core2/1EA0690.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"

#define NOT(x) ((x) ^ 1)

s32 bainput_getStructSize(void) {
    return sizeof(BaInput);
}

static s32 __bainput_isEnabled(PlayerState *self, BaInputId id) {
    return (self->input->__enabled & (1 << id)); 
}

static void __bainput_enable(PlayerState *self, BaInputId id, s32 value) {
    if (value) {
        self->input->__enabled |= (1 << id);
    } else {
        self->input->__enabled &= ~(1 << id);
    } 
}

static int __bainput_func_800979D8(PlayerState *self, ButtonId button_id, BaInputId input_id) {
    if (bakey_held(self, button_id)) {
        if (!bainput_isEnabled(self, input_id)) {
            __bainput_enable(self, input_id, 0);
        }
        return __bainput_isEnabled(self, input_id);
    } else {
        __bainput_enable(self, input_id, 1);
        return 0;
    }
}

int bainput_should_beak_barge(PlayerState *self) {
    return bakey_pressed(self, BUTTON_B) && func_8008D0A0(self);
}

int bainput_should_beak_bust(PlayerState *self) {
    return bakey_pressed(self, BUTTON_Z) && func_8008D14C(self);
}

int bainput_should_enter_first_person(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_UP) && func_8008D9A4(self) && bainput_isEnabled(self, BA_INPUT_2_ENTER_FIRST_PERSON);
}

int bainput_func_80097B28(PlayerState *self) {
    return NOT(bakey_heldCount(self, BUTTON_R) < 7);
}

int bainput_func_80097B4C(PlayerState *self) {
    return NOT(bakey_heldCount(self, BUTTON_R) < 9);
}

int bainput_should_rotate_camera_left(PlayerState *self) {
    return __bainput_func_800979D8(self, BUTTON_C_LEFT, BA_INPUT_0_ROTATE_CAMERA_LEFT);
}

int bainput_should_rotate_camera_right(PlayerState *self) {
    return __bainput_func_800979D8(self, BUTTON_C_RIGHT, BA_INPUT_1_ROTATE_CAMERA_RIGHT);
}

int bainput_should_exit_first_person(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_DOWN) && bainput_isEnabled(self, BA_INPUT_5_EXIT_FIRST_PERSON);
}

int bainput_should_poop_egg(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_DOWN) && func_8008D280(self);
}

int bainput_should_shoot_egg(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_UP) && func_8008D280(self);
}

int bainput_func_80097C7C(PlayerState *self) {
    if (!func_800F424C(self)) {
        return 0;
    } 

    if (bainput_isEnabled(self, 6)) {
        return 0;
    } 
    
    if (func_800F8004(self->unk184)) {
        return 0;
    }
    
    if (!func_80091E80(self, 0x40)) {
        return 0;
    }
    
    return bakey_newlyReleased(self, BUTTON_R) && (bakey_func_80091940(self, BUTTON_R, 1) < 9);     
}

int bainput_func_80097D28(PlayerState *self) {
    if (!func_800F424C(self)) {
        return 0;
    } 

    if (bainput_isEnabled(self, 6)) {
        return 0;
    } 
    
    return bakey_newlyReleased(self, BUTTON_R) && (bakey_func_80091940(self, BUTTON_R, 1) < 7);     
}

int bainput_should_feathery_flap(PlayerState *self) {
    return bakey_pressed(self, BUTTON_A)
        && !func_8008E39C(self)
        && baflag_isFalse(self, BA_FLAG_12_HAS_FLAPPED);
}

int bainput_func_80097DF4(PlayerState *self) {
    return bakey_pressed(self, BUTTON_A) && func_8008D304(self);
}

int bainput_should_flap_flip(PlayerState *self) {
    return bakey_pressed(self, BUTTON_A) && func_8008D370(self);
}

int bainput_func_80097E74(PlayerState *self) {
    return bakey_held(self, BUTTON_Z) 
        && func_800C6E38(0x22) 
        && !func_8008E39C(self);
}

int bainput_func_80097EC8(PlayerState *self) {
    return bakey_pressed(self, BUTTON_B) && func_8008D568(self);
}

int bainput_func_80097F08(PlayerState *self) {
    return bakey_pressed(self, BUTTON_B) && func_8008D5C4(self);
}

int bainput_should_dive(PlayerState *self) {
    return bakey_pressed(self, BUTTON_B) 
        && (self->input->dive_cooldown == 0.0f)
        && func_8008D214(self);
}

int bainput_func_80097FB8(PlayerState *self) {
    return bakey_pressed(self, BUTTON_B)
        && func_800C6E38(0x1D)
        && baflag_isFalse(self,BA_FLAG_5_HAS_PECKED)
        && !func_8008E39C(self);
}

s32 bainput_isEnabled(PlayerState *self, BaInputId arg1) {
    return self->input->enabled & (1 << arg1);
}

int bainput_func_8009803C(PlayerState *self) {
    s32 sp24;
    if (bakey_pressed(self, BUTTON_Z) && func_8008D850(self)) {
        _suinv_entrypoint_0(&sp24, 0, 1,0x46, 5);
        return sp24;
    }
    return 0;

}

int bainput_should_trot(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_LEFT) && func_8008D8E4(self);
}

int bainput_should_wonderwing(PlayerState *self) {
    return bakey_pressed(self, BUTTON_C_RIGHT) && func_8008D964(self);
}

void bainput_init(PlayerState *self) {
    self->input->enabled = -1;
    self->input->__enabled = -1;
    self->input->dive_cooldown = 0.0f;
}

void bainput_enable(PlayerState *self, BaInputId id, s32 value) {
    if (value) {
        self->input->enabled |= (1 << id);
    } else {
        self->input->enabled &= ~(1 << id);
    } 
}

void bainput_setDiveCooldown(PlayerState *self, s32 arg1, f32 cooldown) {
    self->input->dive_cooldown = cooldown;
}

void bainput_update(PlayerState *self) {
    if (self->input->dive_cooldown != 0.0f) {
        self->input->dive_cooldown = func_800F0E00(self->input->dive_cooldown - func_800D8FF8(), 0.0f);
    }
    bainput_enable(self, 6, 0);
}
