#include "bs/drone/fired.h"

void bsdronefired_entrypoint_0(PlayerState* self)
{
    _babounce_entrypoint_3(self);
}

void bsdronefired_entrypoint_1(PlayerState* self) {
    f32 sp34;
    AssetId sp30;
    s32 var_a1;

    _badata_entrypoint_7(self, &sp30, &sp34);
    baanim_playForDuration_loopSmooth(self, sp30, sp34);
    _babounce_entrypoint_4(self, 2);
    yaw_setIdeal(self, yaw_getIdeal(self) + 180.0f);
    yaw_applyIdeal(self);
    switch (player_getTransformation(self))
    {
    default:
        return;
    case TRANSFORM_1_BK:
    case TRANSFORM_A_BANJO:
        var_a1 = 0x420;
        break;
    case TRANSFORM_B_KAZOOIE:
        var_a1 = 0x598;
        break;
    case TRANSFORM_D_MUMBO:
        var_a1 = 0x5A3;
        break;
    }
    func_8009DF18(self, var_a1, _badata_entrypoint_18(self) + 1.0f, 0x6D60);
    return;
}

void bsdronefired_entrypoint_2(PlayerState* self)
{
    func_80099AA8(self);
}

void bsdronefired_entrypoint_3(PlayerState* self)
{
    if (_babounce_entrypoint_10(self) != 0)
    {
        bs_setState(self, _badata_entrypoint_24(self));
    }
}
