#include "overlays/bs/rest.h"

extern enum bs_state_e bsrest_entrypoint_13(PlayerState *self);
extern void bsrest_entrypoint_17(PlayerState *self, s32);

static void func_80800000_bsrest(PlayerState *self) {
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    if (player_isStable(self) != 0) {
        func_8009BA9C(self, NULL);
    }
}

static void func_8080003C_bsrest(PlayerState *self) {
    if (baflag_isFalse(self, BA_FLAG_18) == 0) {
        baflag_clear(self, BA_FLAG_18);
        func_80110C2C(func_800A4CA8(self));
    }
}

static void func_80800080_bsrest(PlayerState *self) {
    f32 sp1C[3];
    PlayerState *sp18;

    sp18 = func_800A4CA8(self);
    if (func_8009CC68(self) == 4) {
        baflag_set(self, BA_FLAG_18);
        func_80110BF0(sp18);
        func_800F3BD0(self, 5, sp1C);
        _ncba1p_entrypoint_6(sp18, sp1C);
    }
}

static void func_808000E4_bsrest(PlayerState *self) {
    PlayerState *sp54;
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    sp54 = func_800A4CA8(self);
    if ((func_8009CC68(self) == 4) && (baflag_isFalse(self, BA_FLAG_18) == 0)) {
        func_800F3BD0(self, 5, sp24);
        _ncba1p_entrypoint_6(sp54, sp24);
        func_800F3BD0(self, 5, sp3C);
        func_8009CC18(self, sp30);
        func_800A516C(sp48, sp30, sp3C);
        _ncba1p_entrypoint_7(sp54, sp48);
    }
}

void bsrest_entrypoint_0(PlayerState *self) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    if (func_8009CC68(self) != 0) {
        func_8009C128(self, sp30);
        if (func_8009CC18(self, sp24) == 0) {
            func_801160DC(func_800A4CA8(self), 0);
            return;
        }

        if (func_800F1E6C(sp30, sp24, &sp3C) != 0) {
            yaw_setIdeal(self, sp3C);
        }
    }
}

static void func_8080020C_bsrest(PlayerState *self, enum asset_e animId, f32 duration) {
    AnimCtrl *animCtrl;

    animCtrl = baanim_getAnimCtrlPtr(self);
    if (animId == ASSET_50_ANIM_BSREST_UNKNOWN) {
        func_800A0CF4(self, 1);
        switch (anctrl_getIndex(baanim_getAnimCtrlPtr(self))) {
            case ASSET_50_ANIM_BSREST_UNKNOWN:
                baanim_playForDuration_loopSmooth(self, animId, duration);
                break;
            case ASSET_5B_ANIM_BSREST_UNKNOWN:
                anctrl_reset(animCtrl);
                anctrl_setIndex(animCtrl, ASSET_5B_ANIM_BSREST_UNKNOWN);
                anctrl_setDuration(animCtrl, 0.4f);
                anctrl_setPlaybackType(animCtrl, 1);
                break;
            default:
                baanim_playForDuration_onceSmooth(self, ASSET_5B_ANIM_BSREST_UNKNOWN, 0.5f);
                anctrl_setPlaybackType(animCtrl, 1);
                break;
        }
    } else {
        baanim_playForDuration_loopSmooth(self, animId, duration);
    }

    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    func_80800000_bsrest(self);
    bsrest_entrypoint_0(self);
}

static s32 func_8080032C_bsrest(PlayerState *self) {
    AnimCtrl *animCtrl;
    s32 sp20;
    enum asset_e animIndex;

    animCtrl = baanim_getAnimCtrlPtr(self);
    bsrest_entrypoint_0(self);
    sp20 = 0;
    animIndex = anctrl_getIndex(animCtrl);
    switch (animIndex) {
        case ASSET_5B_ANIM_BSREST_UNKNOWN:
            if (baanim_isStopped(self) != 0) {
                if (func_8008B28C(animCtrl) != 0) {
                    baanim_playForDuration_loopSmooth(self, ASSET_50_ANIM_BSREST_UNKNOWN, 11.4f);
                } else if (func_8009CC68(self) == 0) {
                    sp20 = 1;
                }
            }
            break;
        case ASSET_50_ANIM_BSREST_UNKNOWN:
            if (func_8009CC68(self) == 0) {
                sp20 = 1;
            }
            break;
        default:
            if (func_8009CC68(self) == 0) {
                sp20 = 1;
            }
            break;
    }

    return sp20;
}

static void func_808003FC_bsrest(PlayerState *self) {
    if (func_800A0C20(self) != 0) {
        func_800A0D14(self, 0, 0.5f);
    }
}

void bsrest_entrypoint_1(PlayerState *self) {
    enum asset_e assetId;
    f32 duration;

    _badata_entrypoint_9(self, &assetId, &duration);
    func_8080020C_bsrest(self, assetId, duration);
}

void bsrest_entrypoint_2(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        next_state = bsrest_entrypoint_13(self);
    }

    bs_setState(self, next_state);
}

void bsrest_entrypoint_3(PlayerState *self) {
    func_808003FC_bsrest(self);
}

s32 bsrest_entrypoint_4(s32 idx) {
    return D_80800910_bsrest[idx];
}

void bsrest_entrypoint_5(PlayerState *self) {
    enum asset_e assetId;
    f32 duration;

    _badata_entrypoint_10(self, &assetId, &duration);
    func_8080020C_bsrest(self, assetId, duration);
}

void bsrest_entrypoint_6(PlayerState *self) {
    enum bs_state_e sp1C;

    sp1C = BS_STATE_0_INVALID;
    if (player_inWater(self) != 0) {
        sp1C = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        sp1C = bsrest_entrypoint_13(self);
    }

    bs_setState(self, sp1C);
}

void bsrest_entrypoint_7(PlayerState *self) {
    func_808003FC_bsrest(self);
}

s32 bsrest_entrypoint_8(s32 idx) {
    return D_80800920_bsrest[idx];
}

void bsrest_entrypoint_9(PlayerState *self) {
    enum asset_e assetId;
    f32 duration;

    _badata_entrypoint_11(self, &assetId, &duration);
    func_8080020C_bsrest(self, assetId, duration);
    func_80800080_bsrest(self);
}

void bsrest_entrypoint_10(PlayerState *self) {
    enum bs_state_e next_state;

    next_state = BS_STATE_0_INVALID;
    func_808000E4_bsrest(self);
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_77;
    }

    if (func_8080032C_bsrest(self) != 0) {
        next_state = bsrest_entrypoint_13(self);
    }

    bs_setState(self, next_state);
}

void bsrest_entrypoint_11(PlayerState *self) {
    func_808003FC_bsrest(self);
    func_8080003C_bsrest(self);
}

s32 bsrest_entrypoint_12(s32 idx) {
    return D_80800930_bsrest[idx];
}

enum bs_state_e bsrest_entrypoint_13(PlayerState *self) {
    if (_bafpctrl_entrypoint_4(self) == 3) {
        return _badrone_entrypoint_24(self);
    }

    return _badata_entrypoint_34(self);
}

void bsrest_entrypoint_14(PlayerState *self) {
    func_8009BF5C(self, 0.0f);
    baroll_setIdeal(self, 0.0f);
    func_8080003C_bsrest(self);
}

void bsrest_entrypoint_15(PlayerState *self, s32 arg1) {
    f32 duration;
    enum asset_e assetId;

    switch (func_8009CC68(self)) {
        case 1:
            _badata_entrypoint_9(self, &assetId, &duration);
            break;
        case 3:
            _badata_entrypoint_10(self, &assetId, &duration);
            break;
        default:
        case 2:
            _badata_entrypoint_11(self, &assetId, &duration);
            break;
    }
    if (assetId != 0) {
        baanim_playForDuration_loopSmooth(self, assetId, duration);
    }
    bsrest_entrypoint_17(self, arg1);
}

void bsrest_entrypoint_16(PlayerState *self) {
    bsrest_entrypoint_15(self, 1);
}

void bsrest_entrypoint_17(PlayerState *self, s32 arg1) {
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
    func_80800000_bsrest(self);
    func_80800080_bsrest(self);
    if (arg1 != 0) {
        bsrest_entrypoint_0(self);
    }
}

void bsrest_entrypoint_18(PlayerState *self) {
    bsrest_entrypoint_17(self, 1);
}

s32 bsrest_entrypoint_19(PlayerState *self, s32 arg1) {
    if (arg1 != 0) {
        bsrest_entrypoint_0(self);
        if (_badata_entrypoint_15(self) != 0) {
            func_8009D3A8(self, 0);
        }
    } else {
        func_801160DC(func_800A4CA8(self), 0);
    }

    func_808000E4_bsrest(self);
    if (func_8009CC68(self) == 0) {
        return 1;
    }

    return 0;
}

s32 bsrest_entrypoint_20(PlayerState *self) {
    return bsrest_entrypoint_19(self, 1);
}