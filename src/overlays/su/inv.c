#include "su/inv.h"

void suinv_entrypoint_0(s32* arg0, s32 failure, s32 success, s32 itemType, s32 amountToRemove)
{
    //If we have negative amount of items or the amount we are trying to remove is too much
    if ((func_800D1C38(itemType) != 0) || ((func_800D1A04(itemType) - amountToRemove) < 0))
    {
        func_800D1824(itemType);
        func_800FC63C(0xF, 0x55F0);
        if (failure != -1)
        {
            *arg0 = failure;
        }
    }
    else
    {
        if (amountToRemove != 0)
        {
            func_800D175C(itemType, -amountToRemove);
        }
        if (success != -1)
        {
            *arg0 = success;
        }
    }
}