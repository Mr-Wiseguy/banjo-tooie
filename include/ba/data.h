#ifndef __BA_DATA_H__
#define __BA_DATA_H__

#include <ultra64.h>
#include "common.h"

#include "ba/assets.h"
#include "ba/statetimer.h"
#include "core2/1E6F080.h"
#include "core2/1E75920.h"
#include "core2/1E76360.h"
#include "core2/1EB5980.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
} BaData_1;

typedef struct {
    BaData_1 *unk0;
    s32 count;
    f32 unk8;
} BaData_5;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
} BaData_4;

typedef struct {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} BaData_3;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} BaData_2;

extern BaData_5 D_808010C8_badata[];
extern BaData_5 D_80801298_badata[];
extern s16 D_80801448_badata[];
extern s16 D_80801490_badata[];
extern s16 D_808014D8_badata[];
extern s16 D_80801520_badata[];
extern BaData_2 D_80801568_badata[];
extern u8 D_80801640_badata[];
extern u8 D_80801664_badata[];
extern s32 D_80801688_badata[];
extern BaData_3 D_80801718_badata[];
extern BaData_1 D_80801958_badata[];
extern BaData_1 D_80801A78_badata[];
extern BaData_1 D_80801B98_badata[];
extern BaData_1 D_80801CB8_badata[];
extern BaData_1 D_80801DD8_badata[];
extern BaData_1 D_80801EF8_badata[];
extern BaData_1 D_80802018_badata[];
extern BaData_1 D_80802138_badata[];
extern BaData_1 D_80802258_badata[];
extern BaData_1 D_80802378_badata[];
extern BaData_4 D_80802498_badata[];
extern BaData_4 D_80802648_badata[];

extern void _badata_entrypoint_0(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_1(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_2(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_3(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_4(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_5(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_6(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern void _badata_entrypoint_7(PlayerState * self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_8(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3);
extern void _badata_entrypoint_9(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_10(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_11(PlayerState *self, AssetId *assetId, f32 *arg2);
extern void _badata_entrypoint_12(PlayerState *self, s32 *arg1, f32 *arg2);
extern void _badata_entrypoint_13(PlayerState *self, s32 *arg1, f32 *arg2);
extern s32 _badata_entrypoint_14(PlayerState *self);
extern s32 _badata_entrypoint_15(PlayerState *self);
extern s32 _badata_entrypoint_16(void);
extern void _badata_entrypoint_17(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4);
extern f32 _badata_entrypoint_18(PlayerState *self);
extern void _badata_entrypoint_19(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4);
extern s32 _badata_entrypoint_20(PlayerState *self);
extern s32 _badata_entrypoint_21(PlayerState *self);
extern s32 _badata_entrypoint_22(PlayerState *self);
extern s32 _badata_entrypoint_23(PlayerState *self);
extern s32 _badata_entrypoint_24(PlayerState *self);
extern s32 _badata_entrypoint_25(PlayerState *self);
extern s32 _badata_entrypoint_26(PlayerState *self);
extern s32 _badata_entrypoint_27(PlayerState *self);
extern s32 _badata_entrypoint_28(PlayerState *self);
extern s32 _badata_entrypoint_29(PlayerState *self);
extern s32 _badata_entrypoint_30(PlayerState *self, s32 arg1);
extern s32 _badata_entrypoint_31(PlayerState *self);
// This might return a BanjoStateId
extern s32 _badata_entrypoint_32(PlayerState *self);
extern s32 _badata_entrypoint_33(PlayerState *self);
extern s32 _badata_entrypoint_34(PlayerState *self);
extern s32 _badata_entrypoint_35(PlayerState *self);

#endif // __BA_DATA_H__
