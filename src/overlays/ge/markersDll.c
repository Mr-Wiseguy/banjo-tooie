#include "ge/markersDll.h"

extern s32* D_80800090_gemarkersDll;

s32 gemarkersDll_entrypoint_0(s32 arg0)
{
    if ((arg0 < 0xB6) || (arg0 >= 0x546))
    {
        return 0;
    }
    //Get the entrypoint address for a given object id
    return *(&D_80800090_gemarkersDll - 0xB6 + (arg0));
}

s32 gemarkersDll_entrypoint_1(s32 arg0)
{
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if (func_800A9C98() != 0)
    {
        if ((arg0 > 0) && (arg0 < 9))
        {
            var_v1 = arg0 + 0x7F;
        }
    }
    else if ((arg0 > 0) && (arg0 < 0x29))
    {
        var_v1 = arg0;
    }
    return var_v1;
}