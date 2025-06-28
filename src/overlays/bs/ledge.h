#ifndef __BS_LEDGE_H__
#define __BS_LEDGE_H__

#include <ultra64.h>

#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/key.h"
#include "overlays/ba/motor.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/translate.h"
#include "overlays/ba/packctrl.h"
#include "overlays/bs/rest.h"
#include "overlays/bs/state.h"
#include "core2/1E66990.h"
#include "core2/1E6B900.h"
#include "core2/1E6F080.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1E79FD0.h"
#include "core2/1E7B250.h"
#include "core2/1E7D460.h"
#include "core2/1EB5980.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1EEBA50.h"
#include "common.h"
#include "funcs.h"

extern s16 D_80801340_bsledge[];
extern s32 D_80801348_bsledge[];
extern s32 D_80801358_bsledge[];
extern s32 D_80801368_bsledge[];
extern s32 D_80801378_bsledge[];
extern u8 D_80801388_bsledge[];
extern u8 D_80801390_bsledge[];
extern s32 D_80801398_bsledge[];
extern s32 D_808013A8_bsledge[];

extern s32 _bsledge_entrypoint_0(s32 idx);
extern s32 _bsledge_entrypoint_1(s32 idx);
extern s32 _bsledge_entrypoint_2(s32 idx);
extern s32 _bsledge_entrypoint_3(s32 idx);
extern s32 _bsledge_entrypoint_4(s32 idx);
extern void _bsledge_entrypoint_5(PlayerState *self);
extern void _bsledge_entrypoint_6(PlayerState *self);
extern void _bsledge_entrypoint_7(PlayerState *self);
extern s32 _bsledge_entrypoint_8(s32 idx);

#endif // __BS_LEDGE_H__
