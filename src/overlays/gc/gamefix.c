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
    u32 i;

    for (i = 0; i < 9; i++) 
    {
        //Get the number of Jinjos collected for a certain type
        if (func_800D1338(i) == func_800D129C(i))
        {
            //Check if we've collected the associated jiggy
            if (func_800D0B68(i + IoH_JV_JINJO_FAMILY_WHITE, 1U) == 0)
            {
                //Set Jiggy Collected
                func_800D0C78(i + IoH_JV_JINJO_FAMILY_WHITE, 1U, 1U);
            }
        }
    }
}

void func_808000D0_gcgamefix(void)
{
    //If canary Mary has been freed
    if (func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) != 0)
    {
        //Set Canary Mary Ready to Race Flag
        func_800DA544(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE);
    }
    //Check if the cheato page from Canary Mary Race 2 was spawned
    if (func_800D0A9C(4, 4) != 0)
    {
        //Set Canary Mary In CCL
        func_800DA544(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL);
    }
}

void func_8080011C_gcgamefix(void)
{
    if (func_800DA298(FLAG_4FC_UNK) != 0)
    {
        func_800DA544(FLAG_4FD_UNK);
    }
    if (func_800DA298(FLAG_4FF_UNK) != 0)
    {
        func_800DA544(FLAG_500_UNK);
    }
}

void func_80800164_gcgamefix(void)
{
    //Check if we've given dippy water but didnt get the reward
    if ((func_800DA298(FLAG_327_UNK) != 0) && (func_800D0B68(TDL_DIPPY, 1) == 0))
    {
        //Give the dippy reward
        func_800D0C78(TDL_DIPPY, 1, 1);
    }
}