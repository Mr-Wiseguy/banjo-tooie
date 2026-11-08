#include "gc/extra.h"

s32 gcextra_entrypoint_0(void)
{
    return flag_getMultipleValue(FLAG_4EA_HONEY_B_HONEY_UPGRADES_1, 3);
}

s32 gcextra_entrypoint_1() 
{
    return 0x5;
}

void gcextra_entrypoint_2(s32 arg0)
{
    s32 var_a1;
    s32 temp_v0;

    var_a1 = gcextra_entrypoint_0() + arg0;
    temp_v0 = gcextra_entrypoint_1();
    if (temp_v0 < var_a1)
    {
        var_a1 = temp_v0;
    }
    flag_setMultipleValue(FLAG_4EA_HONEY_B_HONEY_UPGRADES_1, var_a1, 3);
    transformation_setAllMaxHealth();
}
