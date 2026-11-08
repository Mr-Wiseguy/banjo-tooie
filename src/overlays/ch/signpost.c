#include "ch/signpost.h"

extern ActorData D_808002E0_chsignpost;
extern f32 D_80800328_chsignpost[];

void func_80800230_chsignpost(Actor*, s16, s16);
void func_80800264_chsignpost(s32, s32, s32);
s32 func_80800274_chsignpost(Actor*);

ActorData* chsignpost_entrypoint_0(void) {
    return &D_808002E0_chsignpost;
}

void func_8080000C_chsignpost(Actor* arg0) 
{
    func_80102FDC(arg0, arg0->scale * 0.75f);
    arg0->actorData[4] = arg0->unk74_7 - 0x32;
}

void func_80800058_chsignpost(Actor* arg0)
{
    s32 var_v1;
    u32 var_a2;

    switch (arg0->unk70_10)
    {
    case 1:
        if (flag_getValue(FLAG_03A_FTT_SIGNPOST) == 0)
        {
            if ((func_8010CAC0(arg0->position, 0x15EU) != 0) && (func_8010CD88(arg0, 360.0f, 70.0f) != 0) && (func_800F4B8C(character_getActiveIndex(), -1U, 0) != 0))
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x16C2U, 0xEU, arg0->position, 0x28U);
                func_80101FDC(arg0, 2U);
                flag_setValueTrue(FLAG_03A_FTT_SIGNPOST);
                return;
            }
        }
        else
        {


            if (arg0->unk70_0 != 0)
            {
                var_v1 = 4;
            }
            else
            {
                var_v1 = 0;
            }
            if (arg0->unk70_0 != 0)
            {
                var_a2 = 0x15E;
            }
            else
            {
                var_a2 = 0xFA;
            }
            if (_subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], var_a2, 0x46U, var_v1) != 0)
            {
                arg0->unk70_10 = 2;
                func_80800274_chsignpost(arg0);
            }
    case 2:
        return;
        }
        break;
    }
}

s32 func_8080019C_chsignpost(Actor* arg0, s32 arg1, s32 arg2) {
    switch (arg1)
    {

    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_80800230_chsignpost(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
        break;
    case 0x2F:
        func_80800264_chsignpost(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800328_chsignpost, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800230_chsignpost(Actor* arg0, s16 arg1, s16 arg2)
{
    if ((arg0->unk70_10) == 2)
    {
        arg0->unk70_10 = 1;
    }
}

void func_80800264_chsignpost(s32 arg0, s32 arg1, s32 arg2) {
}

s32 func_80800274_chsignpost(Actor* arg0)
{
    s32 sp20;
    s32 var_a1;

    var_a1 = arg0->actorData[4] + 0x1686;
    if ((var_a1 >= 0x16B7) && (var_a1 < 0x16BF))
    {
        sp20 = var_a1;
        if (cheat_isActive(CHEAT_6_GETJIGGY) == 0)
        {
            var_a1 = 0x16BF;
        }
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, 0xFU, arg0->position, 0x28U);
    return 1;
}
