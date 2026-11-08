#ifndef __BS_STAND_H__
#define __BS_STAND_H__

#include "common.h"
#include "ba/anim.h"
#include "ba/drone.h"
#include "ba/duo.h"
#include "ba/input.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "bs/mum/move.h"
#include "bs/mum/still.h"
#include "bs/stand.h"
#include "bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6A190.h"
#include "core2/1E6E870.h"
#include "core2/1E71B00.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/anctrl.h"
#include "player.h"

#include "ba/playerstate.h"

// func_80800000_bsstand
// func_80800018_bsstand
// func_80800038_bsstand
// bsstand_entrypoint_0
// func_80800274_bsstand
// bsstand_entrypoint_1
// bsstand_entrypoint_2
// bsstand_entrypoint_3
// bsstand_entrypoint_4
// bsstand_entrypoint_5
void bsstand_entrypoint_6(s32);
// bsstand_entrypoint_7
BanjoStateId _bsstand_entrypoint_8(PlayerState*, BanjoStateId); 
void bsstand_entrypoint_9(PlayerState*);
void bsstand_entrypoint_10(PlayerState*);
void bsstand_entrypoint_11(PlayerState*);
// bsstand_entrypoint_12

#endif // __BS_STAND_H__
