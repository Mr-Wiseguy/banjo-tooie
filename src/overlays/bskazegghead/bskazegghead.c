#include "common.h"

#include "bs/kazegghead.h"

s32 D_808002F0_bskazegghead[];

void bskazegghead_entrypoint_0(PlayerState* player) {
    _bskaz_entrypoint_1(player);
    baanim_playForDuration_once(player, 0x28D, 0.75f);
    func_8009FFD8(player, 1, 3, 1, 3);
    yaw_setVelocityBounded(player, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A0CF4(player, 1);
    player->unk160.word = 1;
    player->unk15C.word = 1;
    player->unk164.word = func_80094510(player);
    bainput_enable(player, 2, 0);
}


void bskazegghead_entrypoint_1(PlayerState* player) {
    BanjoStateId next_state;
    AnimCtrl* sp28;
    s32 sp24;

    next_state = BS_STATE_0_INVALID;
    sp28 = (AnimCtrl*) baanim_getAnimCtrlPtr(player);
    sp24 = func_80094BC0(player) != 0;
    if ((bainput_should_shoot_egg(player) != 0) && (func_80094B14(player) != 0)) {
        player->unk15C.word = func_800F1418(player->unk15C.word + 1, func_800944E0(player, player->unk164.word));
    }
    if (sp24 != 0) {
        if (anctrl_isAt(sp28, 0.1f) != 0) {
            _baeggsetup_entrypoint_10(player);
        }
        if (anctrl_isAt(sp28, 0.4f) != 0) {
            _baeggsetup_entrypoint_8(player, player->unk164.word);
        }
        if (anctrl_isAt(sp28, 0.43f) != 0) {
            _baeggsetup_entrypoint_5(player, player->unk164.word, 33.0f, 80.0f);
            func_800C6DA0(0x43);
        }
        if ((anctrl_isAt(sp28, 0.55f) != 0) && (player->unk160.word < player->unk15C.word)) {
            anctrl_setStart(sp28, 0.32f);
            anctrl_start(sp28);
            player->unk160.word += 1;
        }
    }
    if (func_8008DD04(player) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bakey_held(player, BUTTON_Z) != 0) {
        if (anctrl_isStopped(sp28) != 0) {
            next_state = BS_STATE_DD;
        }
        if (anctrl_getAnimTimer(sp28) > 0.65f) {
            next_state = _bskazcrouch_entrypoint_0(player, next_state);
        }
    } else if (anctrl_isStopped(sp28) != 0) {
        next_state = BS_STATE_BB;
    }
    bs_setState(player, next_state);
}

void bskazegghead_entrypoint_2(PlayerState* player) {
    bainput_enable(player, 2, 1);
    baphysics_reset_gravity(player);
    func_800A0CF4(player, 0);
    _bskaz_entrypoint_2(player);
}

s32 bskazegghead_entrypoint_3(s32 arg0) {
    return D_808002F0_bskazegghead[arg0];
}
