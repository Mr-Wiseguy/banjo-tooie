#include "gs/propmarker.h"

Prop* gspropmarker_entrypoint_0(s16* arg0, s32 arg1)
{
    Prop* var_v1;
    Prop* temp_v0;

    if ((arg0 != NULL) && (func_800E9DC4(arg0) != 0))
    {
        var_v1 = func_800E9D68(arg0);
        temp_v0 = func_800E9D90(arg0);
        for (var_v1; var_v1 < temp_v0; var_v1++)
        {
            if (((u32)var_v1->unk6_0 == 1 || var_v1->unk6_0 == 0 && var_v1->unk12_8 == 1)
                && var_v1->unk6_1 == 6 && arg1 == var_v1->PropID)
            {
                return var_v1;
            }
        }
    }
    return NULL;
}

s32 gspropmarker_entrypoint_1(s16* arg0, s32* arg1, s32* arg2, s32 arg3)
{
    s32 var_t0;
    s32 temp;
    Prop* currentProp;
    Prop* propListEnd;
    s32 index;
    s32* temp2;
    var_t0 = 0;
    if (arg3 == 0)
    {
        return 0;
    }
    if (arg0 != NULL)
    {
        if (func_800E9DC4(arg0) != 0)
        {
            currentProp = func_800E9D68(arg0);
            propListEnd = func_800E9D90(arg0);
            for (currentProp; currentProp < propListEnd && var_t0 < arg3; currentProp++)
            {
                if ((currentProp->unk6_0 == 1U || currentProp->unk6_0 == 0 && currentProp->unk12_8 == 1)
                    && currentProp->unk6_1 == 6)
                {
                    for (temp2 = arg1; *temp2 != -1; temp2++)
                    {
                        if (currentProp->PropID == *temp2)
                        {
                            arg2[var_t0++] = currentProp;
                            break;
                        }
                    }
                }
            }
        }
    }
    return var_t0;
}

s32 gspropmarker_entrypoint_2(s16* arg0, s32 arg1, f32 arg2[][3], s32 arg3)
{
    s32 var_t0;
    Prop* currentProp;
    Prop* propListEnd;

    var_t0 = 0;
    if (arg0 != NULL)
    {
        var_t0 = 0;
        if (func_800E9DC4(arg0) != 0)
        {
            currentProp = func_800E9D68(arg0);
            propListEnd = func_800E9D90(arg0);
            for (currentProp; currentProp < propListEnd && arg3 > var_t0; currentProp++)
            {
                if (((u32)currentProp->unk6_0 == 1 || currentProp->unk6_0 == 0 && currentProp->unk12_8 == 1)
                    && currentProp->unk6_1 == 6 && arg1 == currentProp->PropID)
                {
                    arg2[var_t0][0] = (f32)currentProp->position[0];
                    arg2[var_t0][1] = (f32)currentProp->position[1];
                    arg2[var_t0][2] = (f32)currentProp->position[2];
                    var_t0 += 1;
                }
            }
        }
    }
    return var_t0;
}

f32 gspropmarker_entrypoint_3(s32* arg0)
{
    f32 var_f6;
    u32 temp_t6;
    temp_t6 = arg0[3] & 0x7FFFFF;
    if (temp_t6 != 0)
    {
        if (temp_t6 < 0)
        {
            temp_t6 += 4294967296.0f;
        }
        var_f6 = temp_t6 * 0.01f;
    }
    else
    {
        var_f6 = 1.0f;
    }
    return var_f6;
}