#include "ch/boiler/bossdoor.h"

extern ActorData D_808000F0_chboilerbossdoor;
ActorData* chboilerbossdoor_entrypoint_0()
{
    return &D_808000F0_chboilerbossdoor;
}

void func_8080000C_chboilerbossdoor(Actor* arg0)
{
    s32 pad;
    s32 var_v1;

    var_v1 = flag_getValue(FLAG_179_RETRY_BOSS_OLD_KING_COAL) != 0;
    if (var_v1 == 0)
    {
        var_v1 = _glcutDll_entrypoint_20() != 0;
    }
    if (var_v1 != 0)
    {
        func_80101FDC(arg0, 1U);
    }
    func_80102FDC(arg0, arg0->scale * 1.1f);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 400.0f, 0x802, -1) != 0)
    {
        _chdoormake_entrypoint_5(arg0, 4.0f);
        _chdoormake_entrypoint_8(arg0, 0xCU);
    }
    if (var_v1 == 0)
    {
        event_sendToActor(arg0, 8, 0);
    }
}