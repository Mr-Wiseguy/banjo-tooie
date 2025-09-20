#include "ch/honeycarrier.h"

extern u32 D_808003E0_chhoneycarrier[3];
extern f32 D_808003EC_chhoneycarrier[2];
extern u32 D_808003F4_chhoneycarrier;

//Called when the object is touched
void func_80800000_chhoneycarrier(Actor* arg0, unkStructHoneyCarrier* arg1)
{
    if ((func_800F4B4C((u32)arg1->unk1A >> 5) != 0) && (func_800DA298(FLAG2_663_EMPTY_HONEYCOMB_COLLISION) == 0))
    {
        if (arg0->unk6C_0 != 0)
        {
            func_800C8B84(arg0->unk6C_0);
        }
        //Set the collected flag
        func_800D0BD4(arg0->unk50, 2);
        //Play collected sound effect
        func_800FC63C(9, 0x6D60);
        //Wait 2 seconds before trying to show the tutorial
        func_800C9E20(2.0f, &_sudialog_entrypoint_0, FLAG_032_FTT_ITEM_EMPTY_HONEYCOMB, 0);
        //Increment Inventory Value for honeycomb
        func_800D1844(0x49);
        _fxsparkle_entrypoint_1(arg0->position, 0);
        func_800FFA88(arg0->unk0);
    }
}

s32 func_808000C4_chhoneycarrier(Actor* arg0, s32 arg1, s32 arg2)
{
    f32 sp2C[3];
    switch (arg1)
    {
    case 0x3E:
        func_80800000_chhoneycarrier(arg0, (unkStructHoneyCarrier*)arg2);
        break;
    case 0x12:
        arg0->unk64_19 = arg2;
        break;
    case 0x13:
        arg0->unk50 = (f32)arg2;
        break;
    case 0x55:
        arg0->unk6C_0 = func_800C8A98();
        func_800C8CB8(arg0->unk6C_0, arg0->position);
        func_800C8D4C(arg0->unk6C_0, D_808003EC_chhoneycarrier);
        func_800C8E84(arg0->unk6C_0, D_808003E0_chhoneycarrier);
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] += 150.0f;
        func_800C8CB8(arg0->unk6C_0, sp2C);
        break;
    default:
        return 0;
    }
    if (arg2)
    {
    }
    return 1;
}

void func_80800210_chhoneycarrier(Actor* arg0)
{
    if (func_800DC298(0.5f) != 0)
    {
        arg0->unk58 = 200.0f;
        return;
    }
    arg0->unk58 = -200.0f;
}

void func_80800260_chhoneycarrier(Actor* arg0)
{

    s32 var_s1 = 0;
    f32 sp58[3];

    arg0->rotation[1] += func_800D8FF8() * arg0->unk58;
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
    if (arg0->unk7C_12)
    {
        var_s1 = 0;
        do {
            if (func_800DC298(0.03f) != 0)
            {
                func_80103DFC(arg0, sp58);
                func_800EF214(sp58, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 60.0f);
                _fxtwinkle_entrypoint_0(sp58);
            }
            var_s1 += 1;
        } while (var_s1 != 4);
    }
    func_80103110(arg0, 0U);
}

void func_80800380_chhoneycarrier(Actor* arg0,void* arg1)
{
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12)
    {
        func_80103110(arg0, 1);
    }
}

u32* chhoneycarrier_entrypoint_0(void)
{
    return &D_808003F4_chhoneycarrier;
}