#include "core2/1EAE6C0.h"

extern s32 D_8012B420;
typedef struct {
	u8 uiIcon;
	u8 currentHealth;
	u8 maxHealth;
}HealthInfo;

extern HealthInfo D_8011B640[];

s32 func_800D4DD0(TransformationId arg0)
{
    if (D_8012B420 != 0)
    {
        switch (arg0)
        {
            default:
                break;
            case TRANSFORM_A_BANJO:
                arg0 = 1;
                break;
            case 4:
            case TRANSFORM_B_KAZOOIE:
                arg0 = 0;
                break;
        }
    }
    return arg0;

}

void transformation_affectCurrentHealth(TransformationId arg0, s32 arg1)
{
    if (arg0 == TRANSFORM_9_FIRSTPERSON)
    {
        arg0 = TRANSFORM_1_BK;
    }
    if (arg1 < 0)
    {
        func_800FC660(0x74);
    }
    transformation_setCurrentHealth(arg0, transformation_getCurrentHealth(arg0) + arg1);
}

u8 transformation_getCurrentHealth(TransformationId arg0)
{
    if (arg0 == TRANSFORM_9_FIRSTPERSON)
    {
        arg0 = TRANSFORM_1_BK;
    }
    return D_8011B640[func_800D4DD0(arg0)].currentHealth;
}


u8 transformation_getMaxHealth(TransformationId arg0)
{
    if (arg0 == TRANSFORM_9_FIRSTPERSON)
    {
        arg0 = TRANSFORM_1_BK;
    }
    return D_8011B640[func_800D4DD0(arg0)].maxHealth;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/transformation_getStartMaxHealth.s")

s32 transformation_isNotSnowball(s32 arg0)
{
    if (arg0 == TRANSFORM_2_SNOWBALL)
    {
        return 0;
    }
    return 1;
}

void transformation_setCurrentHealth(TransformationId arg0, s32 arg1)
{
    s32 temp_v0;

    if (arg0 == TRANSFORM_9_FIRSTPERSON)
    {
        arg0 = TRANSFORM_1_BK;
    }
    temp_v0 = func_800D4DD0(arg0);
    if (arg1 < 0)
    {
        arg1 = 0;
    }
    else
    {
        if (D_8011B640[temp_v0].maxHealth < arg1)
        {
            arg1 = D_8011B640[temp_v0].maxHealth;
        }
    }
    D_8011B640[temp_v0].currentHealth = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D5034.s")

void transformation_setAllMaxHealth(void)
{
	s32 numUpgrades;
	s32 transformIdx;
	s32 maxHealth;

	numUpgrades = _gcextra_entrypoint_0();
	D_8012B420 = 0;
	for (transformIdx = 0; transformIdx < 0x14; transformIdx++)
	{
		maxHealth = transformation_getStartMaxHealth(transformIdx);
		if (maxHealth != 0)
		{
			if (transformation_isNotSnowball(transformIdx))
			{
				maxHealth += numUpgrades;
			}
		}
		D_8011B640[transformIdx].maxHealth = maxHealth;
		D_8011B640[transformIdx].currentHealth = maxHealth;
	}
}

u8 transformation_getIcon(TransformationId arg0)
{
    if (arg0 == TRANSFORM_9_FIRSTPERSON)
    {
        arg0 = TRANSFORM_1_BK;
    }
    return D_8011B640[arg0].uiIcon;
}

void func_800D5234(s32 arg0) {
    D_8012B420 = arg0;
}

s32 func_800D5240(void) {
    return D_8012B420;
}