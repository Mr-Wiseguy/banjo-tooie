#ifndef __CH_JIGGY_POST_H__
#define __CH_JIGGY_POST_H__
#include "common.h"
#include "su/baddiedialog.h"
#include "su/jiggy.h"
#include "core2/1EDB4D0.h"
#include "gc/goto.h"
#include "gc/dialogcamera.h"

typedef struct {
    u32 unk0;//0x0
    f32 unk2;//0x4
    u8 unk8[0x30];
    u32 unk38;//0x38
    u8 unk3C[0x36];
    u16 unk72;
    u16 unk74;
    u16 unk76;
} unkStructChJiggyPost;

typedef struct {
    s16 upper;
    s16 lower;
} splitS32;

extern void* D_80800380_chjiggypost;
extern void* D_808003C8_chjiggypost;

void func_80800014_chjiggypost(unkStructChJiggyPost* arg0, s32 arg1);

#endif