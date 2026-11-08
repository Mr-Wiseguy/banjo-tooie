#include "su/inv.h"

void suinv_entrypoint_0(s32* arg0, s32 failure, s32 success, s32 itemType, s32 amountToRemove)
{
    //If we have negative amount of items or the amount we are trying to remove is too much
    if ((inventory_hasZeroItems(itemType) != 0) || ((inventory_getValue(itemType) - amountToRemove) < 0))
    {
        inventory_showValue(itemType);
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
            inventory_addValue(itemType, -amountToRemove);
        }
        if (success != -1)
        {
            *arg0 = success;
        }
    }
}
