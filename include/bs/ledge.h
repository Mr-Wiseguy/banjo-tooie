#ifndef __BS_LEDGE__
#define __BS_LEDGE__


#include <ultra64.h>
#include "common.h"

#include "ba/anim.h"
#include "ba/key.h"
#include "ba/motor.h"
#include "ba/physics.h"
#include "ba/playerstate.h"
#include "ba/stick.h"
#include "ba/yaw.h"
#include "ba/translate.h"
#include "ba/packctrl.h"

#include "bs/rest.h"
#include "bs/state.h"

#include "core2/anctrl.h"

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
#include "core2/1ECB9F0.h"
#include "core2/1ECB0F0.h"
#include "core2/1EEBA50.h"

// func_80800000_bsledge
void func_80800040_bsledge(PlayerState*, f32[3]);
void func_808001A8_bsledge(PlayerState*);
void func_80800238_bsledge(PlayerState*);
void func_80800324_bsledge(PlayerState*);
void func_80800334_bsledge(PlayerState*);
// func_808003D0_bsledge
// func_80800410_bsledge
s32 func_80800450_bsledge(PlayerState*);
void func_80800488_bsledge(PlayerState*, f32[3]);
void func_808004A8_bsledge(PlayerState*);
void func_808004D8_bsledge(PlayerState*);
void func_80800504_bsledge(PlayerState*);
void func_80800540_bsledge(PlayerState*);
void func_808005E0_bsledge(PlayerState*);
s32 _bsledge_entrypoint_0(s32);
void func_8080072C_bsledge(PlayerState*);
void func_80800764_bsledge(PlayerState*);
void func_808007F4_bsledge(PlayerState*);
s32 _bsledge_entrypoint_1(s32);
void func_808008D4_bsledge(PlayerState*);
void func_808008F4_bsledge(PlayerState*);
void func_808009C8_bsledge(PlayerState*);
s32 _bsledge_entrypoint_2(s32);
AssetId func_80800AA0_bsledge(PlayerState*);
void func_80800AC0_bsledge(PlayerState*);
void func_80800AE0_bsledge(PlayerState*);
void func_80800B70_bsledge(PlayerState*);
s32 _bsledge_entrypoint_3(s32);
s32 func_80800CF4_bsledge(PlayerState*, u8*, u32);
s32 func_80800D24_bsledge(PlayerState*);
// func_80800D78_bsledge
void func_80800EE0_bsledge(PlayerState*);
void func_80800F0C_bsledge(PlayerState*);
void func_80800F70_bsledge(PlayerState*);
s32 _bsledge_entrypoint_4(s32);
void _bsledge_entrypoint_5(PlayerState*);
void _bsledge_entrypoint_6(PlayerState*);
void _bsledge_entrypoint_7(PlayerState*);
s32 _bsledge_entrypoint_8(s32);

#endif // __BS_LEDGE__
