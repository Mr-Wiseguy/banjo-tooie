#include "bs/silowait.h"

extern s32 D_80800140_bssilowait[];

void func_80800000_bssilowait(PlayerState* self) {
    func_80092880(self, 1);
    func_80091E6C(self);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
}

void func_8080003C_bssilowait(PlayerState* self) {
    baanim_playForDuration_loop(self, 0x6F, 5.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_6_AIRBORN);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009BA9C(self, NULL);
    baphysics_set_gravity(self, 0.0f);
    baphysics_set_terminal_velocity(self, 0.0f);
    func_80091E48(self, 0x33);
    func_80092880(self, 0);
}

void func_808000D0_bssilowait(PlayerState* self) {
    if (func_8009E6EC(self) == 0x90) {
        bs_setState(self, BS_STATE_1_IDLE);
        func_8009E830(self, 2);
        return;
    }
    func_80099AA8(self);
}

void func_80800120_bssilowait(PlayerState* self) {}

s32 bssilowait_entrypoint_0(s32 arg0) {
    return D_80800140_bssilowait[arg0];
}