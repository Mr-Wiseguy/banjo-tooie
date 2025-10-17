#ifndef __SU_JIGGY_H__
#define __SU_JIGGY_H__

#include "common.h"
#include "core2/1EA9160.h"
#include "core2/1EB3750.h"
#include "core2/1EAB8B0.h"
#include "core2/1E831D0.h"
#include "core2/1ED4E30.h"
#include "core2/1ED68A0.h"
#include "gl/cutDll.h"
#include "gl/reflight.h"

typedef struct
{
    u8 WorldCost;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u16 unk14;
    u16 unk16;

}JiggyData;

s32 _sujiggy_entrypoint_0();

//Get the required amount of jiggies for the given world
s32 _sujiggy_entrypoint_2(s32);
s32 sujiggy_entrypoint_4(s32);
s32 sujiggy_entrypoint_5(s32);
s32 sujiggy_entrypoint_19(void);
//Check if world is unlocked
s32 _sujiggy_entrypoint_20(u32);
s32 sujiggy_entrypoint_21(void);
s32 sujiggy_entrypoint_24(void);
#endif
