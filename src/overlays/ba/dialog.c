#include "ba/dialog.h"

void badialog_entrypoint_0(UNKBADIALOGARG0* arg0, s32 arg1, s32 arg2)
{
    PlayerState* sp1C;

    sp1C = character_getPlayerState(arg0->unk1A_5);
    func_8009AD20(sp1C, arg1);
    func_8009AD2C(sp1C, arg2);
    func_8009E7C8(sp1C, 0x81);
}
void badialog_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {}

s32 badialog_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}

s32 badialog_entrypoint_3(PlayerState* arg0, u32 arg1, u32 arg2)
{
    f32 sp2C[3];

    player_getCoords(arg0, sp2C);
    return func_800C0534(arg1, arg2, sp2C, func_8008E938(arg0), _badialog_entrypoint_0, _badialog_entrypoint_1, _badialog_entrypoint_2, 0);
}

s32 badialog_entrypoint_4(PlayerState* arg0, u32 arg1, u32 arg2, GameFlag arg3)
{
    if (flag_getValue(arg3) != 0)
    {
        return 0;
    }
    if (badialog_entrypoint_3(arg0, arg1, arg2) != 0)
    {
        flag_setValue(arg3, 1);
    }
    return flag_getValue(arg3);
}