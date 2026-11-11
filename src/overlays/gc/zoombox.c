#include "gc/zoombox.h"

void func_80800294_gczoombox(ZoomboxStruct*, s32);

void gczoombox_entrypoint_16(ZoomboxStruct*);

extern s16 D_80803E80_gczoombox[];


void func_80800000_gczoombox(ZoomboxStruct* arg0)
{
    s32 var_s1;

    if (arg0->unk14C == -1.0f)
    {
        if (func_800FCCD4(arg0->unk144[0]) != 0)
        {
            func_800FC74C(arg0->unk144[0]);
        }
    }
    else
    {
        for (var_s1 = 0; var_s1 < 5; var_s1++)
        {
            if (arg0->unk144[var_s1] != 0)
            {
                func_800C2FDC(arg0->unk144[var_s1]);
                arg0->unk178--;
            }

        }
    }
    for (var_s1 = 0; var_s1 < 5; var_s1++)
    {
        arg0->unk144[var_s1] = 0;
    }
}

void func_808000C4_gczoombox(ZoomboxStruct* arg0)
{
    if (arg0->unk142 != 0) {
        arg0->unk142 = 0U;
    }
}

void func_808000DC_gczoombox(ZoomboxStruct* arg0)
{
    if (arg0->unk140 != 0)
    {
        arg0->unk140 = 0U;
    }
    func_808000C4_gczoombox(arg0);
}

void gczoombox_entrypoint_0(ZoomboxStruct* arg0)
{
    if (arg0 != NULL) {
        func_800D52B0();
        func_80800000_gczoombox(arg0);
        func_808000DC_gczoombox(arg0);
        heap_free(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_8080014C_gczoombox.s")

void func_808001D4_gczoombox(char* arg0, s32 arg1)
{
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800228_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800294_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808002E4_gczoombox.s")

void func_80800358_gczoombox(ZoomboxStruct* arg0, f32 arg1) {
    arg0->unk1F0 = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800364_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808003D8_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800470_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808004D0_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808005F0_gczoombox.s")

void gczoombox_entrypoint_1(char* arg0)
{
    string_length(arg0);
}

s32 func_808006B4_gczoombox(ZoomboxStruct* arg0, s32 arg1)
{
    s32 temp = 0;
    if (arg1 == -1)
    {
        temp = 0;
    }
    else
    {
        temp = arg1 == arg0->unk12_1;
    }
    return temp;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808006E0_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808008F4_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800964_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808009E4_gczoombox.s")

int func_80800E24_gczoombox(u8 arg0)
{
    return arg0 >= 0x7F && arg0 < 0x88;
}

void func_80800E44_gczoombox(ZoomboxStruct* arg0, char* dst, char* arg2)
{
    char* var_s0 = dst;
    char* var_s1 = arg2;
    s32 sp34[3];
    f32 temp_f0;
    temp_f0 = arg0->unk1AC / 255.0f;
    sp34[0] = arg0->unk1B4 * temp_f0;
    sp34[1] = arg0->unk1B5 * temp_f0;
    sp34[2] = arg0->unk1B6 * temp_f0;
    *dst = 0;
    while (*var_s1 != '\0')
    {
        //is this character between 0x7F and 0x88
        if (func_80800E24_gczoombox(*var_s1) != 0)
        {
            *var_s0 = 0;
            _fxfontstring_entrypoint_3(dst, D_80803E80_gczoombox[95 - *var_s1], arg0->unk1E8);
            var_s0 = dst;
            while (*var_s0 != '\0')
            {
                var_s0++;
            }
        }
        else
        {
            *var_s0 = *var_s1;
            var_s0++;
        }
        var_s1++;
    }

    *var_s0 = '\0';
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800FE0_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80801424_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808014A8_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_8080156C_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80801B30_gczoombox.s")

void func_80801B90_gczoombox(ZoomboxStruct* arg0)
{
    arg0->unk171 = 9;
    gczoombox_entrypoint_16(arg0);
    arg0->unk1E0 = 0.0f;
}

s32 gczoombox_entrypoint_3(ZoomboxStruct* arg0)
{
    return arg0->unk170;
}

void func_80801BD0_gczoombox(ZoomboxStruct* arg0, s32 arg1)
{

    if (arg1 != arg0->unk170)
    {
        arg0->unk170 = arg1;
        if (arg0->unk16C != NULL)
        {
            arg0->unk16C(arg0->unk172);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80801C0C_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802B94_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802BF4_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802C80_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_5.s")

s32 gczoombox_entrypoint_6(ZoomboxStruct* arg0) {
    return arg0->unk178;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_8.s")

void gczoombox_entrypoint_9(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 | 1);
}

void gczoombox_entrypoint_10(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 | 0x10);
}

void gczoombox_entrypoint_11(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 | 2);
}

void gczoombox_entrypoint_12(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 | 8);
}

void gczoombox_entrypoint_13(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 | 0x20);
}

void gczoombox_entrypoint_14(ZoomboxStruct* arg0) {
    s32 var_v0;
    var_v0 = 0;
    for (var_v0 = 0; var_v0 < 8; var_v0++)
    {
        arg0->unk17C[var_v0] = 0;
    }
    arg0->unk174 = 0;
    arg0->unk175 = 0;
    arg0->unk177 = (u8)(arg0->unk177 & 0xFB);
}

void gczoombox_entrypoint_15(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 & 0xFE);
}

void gczoombox_entrypoint_16(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 & 0xEF);
}
void gczoombox_entrypoint_17(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 & 0xFD);
}

void gczoombox_entrypoint_18(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 & 0xF7);
}

void gczoombox_entrypoint_19(ZoomboxStruct* arg0) {
    arg0->unk177 = (u8)(arg0->unk177 & 0xDF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_20.s")

void gczoombox_entrypoint_21(ZoomboxStruct* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk1E4_18 = 1;
        return;
    }
    arg0->unk1E4_18 = 0;
}

u32 gczoombox_entrypoint_22(ZoomboxStruct* arg0) {
    return arg0->unk1E4_18;
}

void gczoombox_entrypoint_23(ZoomboxStruct* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg1 != 0) {
            arg0->unk1E4_11 = 1;
            return;
        }
        arg0->unk1E4_11 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_26.s")

void gczoombox_entrypoint_27(ZoomboxStruct* arg0, s16* arg1)
{
    if (arg0 != NULL)
    {
        arg0->unk1B4 = (s8)arg1[0];
        arg0->unk1B5 = (s8)arg1[1];
        arg0->unk1B6 = (s8)arg1[2];
    }
}

void gczoombox_entrypoint_28(ZoomboxStruct* arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->unk1BC = arg1;
    }
}

s32 gczoombox_entrypoint_29(ZoomboxStruct* arg0) {
    if (arg0 == NULL) {
        return 0xFF;
    }
    return arg0->unk1BC;
}

void gczoombox_entrypoint_30(ZoomboxStruct* arg0, s32 arg1) {
    if (arg0 != NULL) {
        arg0->unk16A = arg1;
    }
}

void gczoombox_entrypoint_31(ZoomboxStruct* arg0) {
    arg0->unk177 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_32.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_33.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_34.s")

void gczoombox_entrypoint_35(ZoomboxStruct* arg0, Unk80132ED0* arg1, s16 arg2, s32 arg3) {
    arg0->unk130 = arg1;
    arg0->unk13A = arg2;
    arg0->unk13C = arg3;
    func_800EC370(arg1, arg0->unk134);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_36.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_37.s")

void gczoombox_entrypoint_38(ZoomboxStruct* arg0, s32 arg1) {
    if (arg0 != NULL) {
        arg0->unk1B0 = arg1;
        func_80800294_gczoombox(arg0, arg1);
    }
}

int gczoombox_entrypoint_39(ZoomboxStruct* arg0) {
    return arg0 != NULL && arg0->unk171 == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_40.s")

void gczoombox_entrypoint_41(ZoomboxStruct* arg0, f32 arg1) {
    arg0->unk1D8 = (f32)(1.0f / arg1);
}

void gczoombox_entrypoint_42(ZoomboxStruct* arg0, f32 arg1) {
    func_80800358_gczoombox(arg0, arg1);
}

void gczoombox_entrypoint_43(ZoomboxStruct* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk1E4_6 = 1;
        return;
    }
    arg0->unk1E4_6 = 0;
}

void gczoombox_entrypoint_44(ZoomboxStruct* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk1E4_5 = 1;
        return;
    }
    arg0->unk1E4_5 = 0;
}

void gczoombox_entrypoint_45(ZoomboxStruct* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk1E4_4 = 1;
        return;
    }
    arg0->unk1E4_4 = 0;
}
