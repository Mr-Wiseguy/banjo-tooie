#include "fx/dialog.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
}unkB_80800290_fxdialog;


extern unkB_80800290_fxdialog B_80800290_fxdialog;

void fxdialog_entrypoint_0(void)
{
    B_80800290_fxdialog.unk10 = 1.0f;
    B_80800290_fxdialog.unk4 = 0.0f;
    B_80800290_fxdialog.unkC = 0;
    B_80800290_fxdialog.unk8 = 0;
    B_80800290_fxdialog.unk0 = B_80800290_fxdialog.unk4;
}
void fxdialog_entrypoint_1(s32 arg0, s32 arg1)
{
    B_80800290_fxdialog.unk8 = (s32)(arg0 * 4);
    B_80800290_fxdialog.unkC = (s32)(arg1 * 4);
    B_80800290_fxdialog.unk0 = (f32)arg0;
    B_80800290_fxdialog.unk4 = (f32)arg1;
}

void fxdialog_entrypoint_2(f32 arg0)
{
    if (arg0 > 0.0f)
    {
        B_80800290_fxdialog.unk10 = arg0;
        B_80800290_fxdialog.unk14 = (f32)(1.0f / arg0);
    }
}

void fxdialog_entrypoint_3(GraphicsBuffers* arg0, f32 arg1, s32 arg2, s32 arg3)
{
    f32 sp40[2];
    f32 sp34[3];
    s32 temp_v0;

    temp_v0 = func_801040D0();
    sp40[1] = -24.0f;
    sp40[0] = 0.0f;
    ml_vec3f_assign_value(sp34, (arg1 * 0.041666668f * B_80800290_fxdialog.unk14) - 2.0f, 0.0f, 0.0f);
    func_800DFFA0(temp_v0, 0x2A, sp34);
    func_800DF41C(temp_v0);
    func_800DF410(arg3);
    // a4 is declared as u8 -> probably needs to be a void * or f32 * / f32[2] more specifically?
    func_800DF944(arg0, &B_80800290_fxdialog.unk0, arg2 * 90.0f, B_80800290_fxdialog.unk10, sp40, 0U, asset_load(0x9F1));
}

void fxdialog_entrypoint_4(GraphicsBuffers* arg0, s32 icon, s32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6)
{
    s32 sp28[2];
    f32 var_f12;
    f32 sp20;
    if (arg6 != 0)
    {
        var_f12 = -B_80800290_fxdialog.unk10;
    }
    else
    {
        var_f12 = B_80800290_fxdialog.unk10;
    }
    sp20 = B_80800290_fxdialog.unk10;

    func_800E2554(var_f12, sp20);
    func_800E257C(arg5);
    sp28[0] = B_80800290_fxdialog.unk8 + (arg3 * 4.0f * var_f12);
    sp28[1] = B_80800290_fxdialog.unkC + (arg4 * 4.0f * sp20);
    //Draw the icon
    draw_2D_Image(arg0, asset_load(icon), arg2, sp28);
}