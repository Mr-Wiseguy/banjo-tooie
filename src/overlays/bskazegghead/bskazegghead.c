#include "common.h"

#include "bs/kazegghead.h"

s32 D_808002F0_bskazegghead[];

void bskazegghead_entrypoint_0(PlayerState* player) {
    _bskaz_entrypoint_1();
    baanim_playForDuration_once(player, 0x28D, 0.75f);
    func_8009FFD8(player, 1, 3, 1, 3);
    yaw_setVelocityBounded(player, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A0CF4(player, 1);
    player->unk160.word = 1;
    player->unk15C.word = 1;
    player->unk164 = func_80094510(player);
    bainput_enable(player, 2, 0);
}


void bskazegghead_entrypoint_1(PlayerState* player) {
    s32 sp2C;
    AnimCtrl* sp28;
    s32 sp24;

    sp2C = 0;
    sp28 = (AnimCtrl*) baanim_getAnimCtrlPtr(player);
    sp24 = func_80094BC0(player) != 0;
    if ((bainput_should_shoot_egg(player) != 0) && (func_80094B14(player) != 0)) {
        player->unk15C.word = func_800F1418(player->unk15C.word + 1, func_800944E0(player, player->unk164));
    }
    if (sp24 != 0) {
        if (anctrl_isAt(sp28, 0.1f) != 0) {
            _baeggsetup_entrypoint_10(player);
        }
        if (anctrl_isAt(sp28, 0.4f) != 0) {
            _baeggsetup_entrypoint_8(player, player->unk164);
        }
        if (anctrl_isAt(sp28, 0.43f) != 0) {
            _baeggsetup_entrypoint_5(player, player->unk164, 33.0f, 80.0f);
            func_800C6DA0(0x43);
        }
        if ((anctrl_isAt(sp28, 0.55f) != 0) && (player->unk160.word < player->unk15C.word)) {
            anctrl_setStart(sp28, 0.32f);
            anctrl_start(sp28);
            player->unk160.word += 1;
        }
    }
    if (func_8008DD04(player) != 0) {
        sp2C = 0xDF;
    }
    if (bakey_held(player, BUTTON_Z) != 0) {
        if (anctrl_isStopped(sp28) != 0) {
            sp2C = 0xDD;
        }
        if (anctrl_getAnimTimer(sp28) > 0.65f) {
            sp2C = _bskazcrouch_entrypoint_0(player, sp2C);
        }
    } else if (anctrl_isStopped(sp28) != 0) {
        sp2C = 0xBB;
    }
    bs_setState(player, sp2C);
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
