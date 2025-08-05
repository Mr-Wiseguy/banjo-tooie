#ifndef __CH_HANDCART_H__
#define __CH_HANDCART_H__
#include "common.h"

#include "core2/1E2B200.h"

#include "core2/1E2D890.h"

#include "core2/1E691A0.h"
#include "core2/1E78170.h"

#include "core2/1E97EF0.h"
#include "core2/1E9A960.h"

#include "core2/1EAF950.h"
#include "core2/1EB2840.h"

#include "core2/1EB3750.h"
#include "core2/1EB5980.h"
#include "core2/1EBA250.h"

#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECB0F0.h"
#include "core2/1ECE0B0.h"

#include "core2/1ED4E30.h"
#include "core2/1ED68A0.h"
#include "core2/1ED8C80.h"
#include "core2/1EDAEA0.h"

#include "core2/1EDB4D0.h"
#include "core2/1EDC070.h"

#include "core2/1EDCA30.h"

#include "core2/1EDED00.h"
#include "core2/1EDFED0.h"
#include "core2/1EE5DF0.h"

#include "gc/cubesearch.h"

#include "su/deflect.h"
#include "su/baddieaudioquick.h"
#include "su/expression.h"
#include "su/baddieDll.h"
#include "su/baddiedialog.h"
#include "su/splinet.h"

extern u32 D_80804DA4_chhandcart;


extern void* D_80804DC4_chhandcart;
extern void* D_80804E6C_chhandcart;

typedef struct {
    u16 unk0;
    u16 unk2;
    f32 unk4;
    f32 unk8;
    f32 unkC[0xB4][0x3];
    u8 unk87C[0x78];
    u8 unk8F4;
    u8 unk8F5;
    u8 unk8F6;
    u8 unk8F7;
    u8 unk8F8;
    u8 unk8F9;
    u8 unk8FA;
    u8 unk8FB[0x08];
    f32 unk904;
    f32 unk908;
    f32 rewardSpawn[3]; //0x90C Reward Spawn Location
    f32 unk918;
    f32 unk91C;
    f32 unk920;
    f32 unk924;
    f32 unk928[3];
    u32 unk934;
    u32 unk938;
    f32 unk93C;
} HandcartMemory;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10[0x14];
    u8 unk24;
    u8 unk25[0x62];
    f32 CameraPosition[3]; //0x38
    f32 CameraRotation[3];
    f32 CameraZoom;
    u16 unk72;
    u8 unk74[0x86];
    u8 unkFA;
    u8 unkFB[0x5];
    u8 unk100;
} CanaryMaryMemory;

extern f32 func_80013970(f32);

//Size 0x9C
extern u32 D_808046C0_chhandcart;
extern u32 D_808046D4_chhandcart;
extern u32 D_808046E8_chhandcart;
extern u32 D_80804E0C_chhandcart;
extern u32 D_80804E18_chhandcart;
extern u32 D_80804E2C_chhandcart;
extern u32 D_80804E38_chhandcart;


extern u32 D_80804704_chhandcart;
extern u32 D_80804714_chhandcart;
s32 func_80800000_chhandcart(void);
s32 func_80800090_chhandcart(void);
void func_808000B4_chhandcart(Actor* arg0);
void func_808002B8_chhandcart(Actor*, s32);
void func_808007F0_chhandcart(Actor* arg0);
void func_80800998_chhandcart(Actor*, u32, u32, Unk80132ED0*);
void func_80800CD0_chhandcart(Actor*);
void func_80800FA0_chhandcart(Actor*, s32);
void func_80801290_chhandcart(Actor*);
void func_808014D8_chhandcart(Actor*, u32);
void func_8080169C_chhandcart(Actor*, u32, f32*);
void func_80801850_chhandcart(Actor*);
void func_80801FFC_chhandcart(Actor*);
void func_80802394_chhandcart(Actor*);
void func_80802CE8_chhandcart(Actor*, s32);
void func_808031D0_chhandcart(Actor* arg0, s32 arg1);

#endif