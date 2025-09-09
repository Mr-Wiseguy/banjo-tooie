#include "gc/gamefix.h"

void gcgamefix_entrypoint_0(void)
{
    func_808000D0_gcgamefix();
    func_8080011C_gcgamefix();
    func_80800164_gcgamefix();
    func_800D1864(0x4B, 0, 0);
    func_800D1864(0x4C, 0, 0);
}

void gcgamefix_entrypoint_1(s32 arg0)
{
    u32 temp_s1;
    u32 temp_s1_2;
    u32 var_s0;

    var_s0 = 0;
    do {
        //Get the number of Jinjos collected for a certain type
        temp_s1 = func_800D1338(var_s0);
        //Compare collected number of jinjos to the total number of jinjos for a type
        if (func_800D129C(var_s0) == temp_s1)
        {
            temp_s1_2 = var_s0 + IoH_JV_JINJO_FAMILY_WHITE;
            //Check if we've collected the associated jiggy
            if (func_800D0B68(temp_s1_2, 1U) == 0)
            {
                //Set Jiggy Collected
                func_800D0C78(temp_s1_2, 1U, 1U);
            }
        }
        var_s0 += 1;
    } while (var_s0 != 9);
}

void func_808000D0_gcgamefix(void)
{
    //If canary Mary has been freed
    if (func_800DA298(0x66) != 0)
    {
        //Set Canary Mary Ready to Race Flag
        func_800DA544(0x507);
    }
    //Check if the cheato page from Canary Mary Race 2 was spawned
    if (func_800D0A9C(4, 4) != 0)
    {
        //Set Canary Mary In CCL
        func_800DA544(0x504);
    }
}

void func_8080011C_gcgamefix(void)
{
    if (func_800DA298(0x4FC) != 0)
    {
        func_800DA544(0x4FD);
    }
    if (func_800DA298(0x4FF) != 0)
    {
        func_800DA544(0x500);
    }
}

void func_80800164_gcgamefix(void)
{
    //Check if we've given dippy water but didnt get the reward
    if ((func_800DA298(0x327) != 0) && (func_800D0B68(TDL_DIPPY, 1) == 0))
    {
        //Give the dippy reward
        func_800D0C78(TDL_DIPPY, 1, 1);
    }
}