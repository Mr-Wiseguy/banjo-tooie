#ifndef __BS_DRONE__
#define __BS_DRONE__


#include <ultra64.h>
#include "common.h"
#include "ba/drone.h"
#include "bs/drone/bitten.h"
#include "bs/drone/bubbled.h"
#include "bs/drone/falldie.h"
#include "bs/drone/goto.h"
#include "bs/drone/slide.h"
#include "bs/drone/suckunder.h"
#include "bs/drone/vanish.h"
#include "bs/drone/xform.h"
#include "ba/playerstate.h"

// func_80800000_bsdrone
extern void _bsdrone_entrypoint_0(PlayerState *self);
extern void _bsdrone_entrypoint_1(PlayerState *self);
extern void _bsdrone_entrypoint_2(PlayerState *self);
extern void _bsdrone_entrypoint_3(PlayerState *self);


#endif // __BS_DRONE__
