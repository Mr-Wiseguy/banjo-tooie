#ifndef __BS_MUMCAST_H__
#define __BS_MUMCAST_H__

#include <ultra64.h>
#include "ba/playerstate.h"
#include "bs/mum.h"
#include "core2/1E67DA0.h"
#include "core2/1E72EA0.h"
#include "core2/1E78170.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "common.h"

extern s32 D_808004A0_bsmumcast[];

extern void _bsmumcast_entrypoint_0(PlayerState *self);
extern void _bsmumcast_entrypoint_1(PlayerState *self);
extern s32 _bsmumcast_entrypoint_4(s32 idx);

#endif // __BS_MUMCAST_H__
