#include "ch/jiggypost.h"

extern void* D_80800380_chjiggypost;
extern ActorData* D_808003C8_chjiggypost;

ActorData* chjiggypost_entrypoint_0(void)
{
    return &D_80800380_chjiggypost;
}

void func_8080000C_chjiggypost(s32 arg0) 
{

}

void func_80800014_chjiggypost(Actor* arg0, s32 arg1)
{
    u8 var_a2;

    if (arg1 == 0x1515)
    {
        var_a2 = 0x4E;
    }
    else
    {
        var_a2 = 0xF;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, var_a2, arg0->position, 0x97);
    func_80101FDC(arg0, 2);
}

void func_80800068_chjiggypost(Actor* arg0)
{

    s32 temp_a0;
    s32 temp;

    if (func_800C0638() == 0)
    {
        func_800D2498(0x10EU, func_800D035C(1), 0U);
        temp = _sujiggy_entrypoint_0();
        temp_a0 = (arg0->unk74_7) - 0x33;
        if (temp <= temp_a0)
        {
            temp = _sujiggy_entrypoint_2(temp_a0) - func_800D035C(1);
            if (temp > 0)
            {
                func_800D2498(0x106U, temp, 0U);
            }
        }
    }
    if ((arg0->unk70_10) == 1)
    {
        if (flag_getValue(FLAG_4E8_FTT_ALTAR_OF_KNOWLEDGE) == 0)
        {
            func_80800014_chjiggypost(arg0, 0x1512);
            return;
        }
        if (_subaddiedialog_entrypoint_5(arg0->position, 0xFAU, 0x3CU, 0U) != 0)
        {
            if ((((s32)arg0->unk74_7) - 0x33) < _sujiggy_entrypoint_0())
            {
                temp = 0x1517;
            }
            else if (cheat_isActive(0xB) != 0)
            {
                temp = 0x155A;
            }
            else
            {

                if (_sujiggy_entrypoint_2(arg0->unk74_7 - 0x33) == 1)
                {
                    temp = 0x1513;
                }
                else
                {
                    temp = 0x1514;
                }
            }
            func_80800014_chjiggypost(arg0, temp);
        }
    }
}

void func_808001C4_chjiggypost(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 var_a1;

    switch (arg1)
    {
    case 0x1513:
    case 0x1514:
        if (flag_getValue(FLAG_35B_FTT_CS_JIGGYWIGGY) != 0)
        {
            if (func_800D035C(1) >= _sujiggy_entrypoint_2(arg0->unk74_7 - 0x33))
            {
                if (activePlayer_getTransformation() == TRANSFORM_1_BK)
                {
                    var_a1 = 0x1515;
                }
                else {
                    var_a1 = 0x152E;
                }
            }
            else
            {
                var_a1 = 0x1516;
            }
            func_80800014_chjiggypost(arg0, var_a1);
        }
        else
        {
            func_800C0850();
            func_800C01A8(0x64, 0);
            func_80101FDC(arg0, 1U);
        }
        break;

    case 0x1512:
        flag_setValueTrue(FLAG_4E8_FTT_ALTAR_OF_KNOWLEDGE);
    default:
        func_80101FDC(arg0, 1U);
        break;
    }
    if ((arg1 == 0x1515) && (arg2 == 1))
    {
        _gcgoto_entrypoint_1(MAP_151_IOH_JIGGYWIGGY_TEMPLE, 4);
    }

}

s32 func_808002DC_chjiggypost(Actor* arg0, s32 arg1, s32 arg2)
{
    splitS32* split = (splitS32*)&arg2;
    switch (arg1)
    {
        //Finished a dialog
        case EVENT_2E_ACTOR_DIALOG_ENDED:
            func_808001C4_chjiggypost(arg0, split->upper, split->lower);
        case EVENT_95_ACTOR_SPAWNED:
            break;
        case 0x30:
            return _sujiggy_entrypoint_2(arg0->unk74_7 - 0x33);
        case 0x52:
            _gcdialogcamera_entrypoint_3((u32 *) &D_808003C8_chjiggypost, arg0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}
