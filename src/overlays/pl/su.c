#include "pl/su.h"

s32 plsu_entrypoint_0(f32* arg0, f32* arg1)
{
    f32 sp44[3];
    f32 temp_f0;
    f32 var_f20;
    s32 charIndex;
    s32 sp34;

    var_f20 = 3.4028235e38f;
    for (charIndex = 0; charIndex < character_getMaxCharacters(); charIndex++)
    {
        if (character_existsAtIndex(charIndex) != 0)
        {
            character_getCoords(charIndex, &sp44);
            temp_f0 = ml_vec3f_distance_sq(&sp44, arg1);
            if (temp_f0 < var_f20)
            {
                var_f20 = temp_f0;
                sp34 = charIndex;
                ml_vec3f_copy(arg0, &sp44);
            }
        }
    }

    return sp34;
}

s32 character_findCharOfTransform(TransformationId arg0)
{
    s32 charIndex;

    for (charIndex = 0; charIndex < character_getMaxCharacters(); charIndex++)
    {
        if ((character_existsAtIndex(charIndex)) && (character_getTransform(charIndex) == arg0))
        {
            return charIndex;
        }
    }
    return -1;
}

s32 character_soloCharactersExist(void)
{
    if (character_findCharOfTransform(TRANSFORM_A_BANJO) == -1)
    {
        return 0;
    }
    if (character_findCharOfTransform(TRANSFORM_B_KAZOOIE) == -1)
    {
        return 0;
    }
    return 1;
}

s32 plsu_entrypoint_3(Unk80132ED0* arg0)
{
    s32 charIndex;
    for (charIndex = 0; charIndex < character_getMaxCharacters(); charIndex++)
    {
        if ((character_existsAtIndex(charIndex)) && (character_isStable(charIndex)) && (func_800F55D0(charIndex) == arg0))
        {
            return charIndex;
        }
    }
    return -1;
}