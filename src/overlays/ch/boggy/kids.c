#include "ch/boggy/kids.h"
extern u16 D_808000E0_chboggykids[];

s32 chboggykids_entrypoint_0(Actor* arg0)
{
    s32 sp1C;
    s32 temp;

    if (flag_getMultipleValue(FLAG_59D_RANDOMISER_MOGGY_1, 2) == 0)
    {
        flag_setMultipleValue(FLAG_59D_RANDOMISER_MOGGY_1, rand_iBounded(0, 3) + 1, 2);
        flag_setMultipleValue(FLAG_59F_RANDOMISER_SOGGY_1, rand_iBounded(0, 3) + 1, 2);
        flag_setMultipleValue(FLAG_5A1_RANDOMISER_GROGGY_1, rand_iBounded(0, 3) + 1, 2);
    }
    sp1C = (arg0->unk74_7) - 0x32;
    temp = arg0->unk0->unk24_22 - 0x192;
    if (flag_getMultipleValue((enum flag_e)D_808000E0_chboggykids[temp], 2) != (sp1C + 1))
    {
        return 0;
    }
    return 1;
}