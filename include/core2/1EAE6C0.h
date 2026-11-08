#ifndef __CORE2_1EAE6C0_H__
#define __CORE2_1EAE6C0_H__

#include "common.h"
#include "transformations.h"
#include "core2/1ED4E30.h"
#include "gc/extra.h"

s32 func_800D4DD0(TransformationId);
void transformation_affectCurrentHealth(TransformationId, s32);
u8 transformation_getCurrentHealth(TransformationId);
u8 transformation_getMaxHealth(TransformationId);
s32 transformation_getStartMaxHealth(s32);
void transformation_setCurrentHealth(TransformationId, s32);
s32 transformation_isNotSnowball(s32);
void func_800D5034(TransformationId, TransformationId);
void transformation_setAllMaxHealth();
u8 transformation_getIcon(TransformationId);
void func_800D5234(s32);
s32 func_800D5240(void);

#endif // __CORE2_1EAE6C0_H__
