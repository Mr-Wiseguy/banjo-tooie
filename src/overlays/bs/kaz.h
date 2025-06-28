#ifndef __BS_KAZ_H__
#define __BS_KAZ_H__

#include "common.h"
#include <ultra64.h>

#include "overlays/ba/flag.h"
#include "overlays/ba/key.h"
#include "overlays/ba/shoes.h"
#include "overlays/ba/stick.h"
#include "overlays/bs/kaz.h"
#include "overlays/bs/kazmove.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E78170.h"
#include "core2/1EA0690.h"

extern void _bskaz_entrypoint_0(PlayerState *self, s32 arg1, s32 arg2);
extern void _bskaz_entrypoint_1(PlayerState *self);
extern void _bskaz_entrypoint_2(PlayerState *self);
extern BanjoStateId _bskaz_entrypoint_3(PlayerState *self);
extern BanjoStateId _bskaz_entrypoint_4(PlayerState *self);

#endif // __BS_KAZ_H__
