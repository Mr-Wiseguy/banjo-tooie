#ifndef __CORE2_1EA9160_H__
#define __CORE2_1EA9160_H__

#include "common.h"
#include "props.h"
#include "collectableTypes.h"

#include "ch/baddiesetup.h"
#include "ch/bounce.h"
#include "ch/nests.h"
#include "su/baddieDll.h"

#include "core2/1EA1DA0.h"
#include "core2/1EB3750.h"
#include "core2/1EB5980.h"

#include "core2/1EC8070.h"
#include "core2/1ED4E30.h"
#include "core2/1EDA900.h"
#include "core2/1EDC7B0.h"

#include "core2/1EDFED0.h"
#include "core2/1EE1510.h"

void func_800CF870(s32);
s32 func_800CF87C();
void func_800CF9E4(s32, s32, s32);
s32 collectable_setJinjoPattern();
void func_800CFBC8(Actor*, s32, CollectableId, s32);
s32 collectable_getTotalInLevel(CollectableId, s32);
s32 func_800CFFBC(s32, CollectableId);
//Get Total Number of Given Object
s32 collectable_getCollectedInLevel(CollectableId, s32);
s32 func_800D035C(s16 a0);
void func_800D053C(u32, u32);
void func_800D0594(s32, CollectableId, s16);
void func_800D05E4(s32, CollectableId, Unk80132ED0*);
s32 func_800D0634(s32, CollectableId);
s16 func_800D0684(s32, CollectableId);
//Get Associated Level Id of given item
s32 func_800D06D4(s32 itemIndex, CollectableId itemType);
void func_800D0778(s32, s32, f32*);
void collectable_getJiggyCoords(s32, CollectableId, f32*);
//Check if collectable is valid type
s32 collectable_getStartIdx(CollectableId itemType);
s32 collectable_getTotalCount(CollectableId itemType);
s32 collectable_getSpawnFlag(s32, CollectableId);
s32 collectable_getCollectedFlag(s32, CollectableId);
//Is Item Spawned
s32 collectable_isSpawned(s32, CollectableId);
void collectable_setSpawnedTrue(s32, CollectableId);
void collectable_setSpawnedFalse(s32, CollectableId);
//Is Item Collected
s32 collectable_isCollected(s32, CollectableId);
void collectable_collectItem(s32, CollectableId);
void func_800D0C78(s32, CollectableId, u32);
//Set Item Collected Flag
s32 func_800D0CC8(s32);
Unk80132ED0* collectable_itemSetup(s32, f32*, s32, Unk80132ED0*);
//Spawn Collectable
void collectable_spawnItem(u32, CollectableId, f32*, u32, Unk80132ED0*);
//Despawn Collectable
void func_800D119C(s32, CollectableId);
void func_800D1218(s32, CollectableId, f32*);
void func_800D1254(s32, CollectableId, f32*);
//Get Total Number of Jinjos of Type
s32 func_800D129C(u32);
//Get Total Number of Jinjos Collected of Type
s32 collectable_getNumJinjoCollectedColor(s32 JinjoColor);
s32 func_800D13E8(s32, s32);

#endif
