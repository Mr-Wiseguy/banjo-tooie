#include "fx/airbub.h"

extern s32 D_80800100_fxairbub;

void fxairbub_entrypoint_0(s32 arg0,s32 arg1)
{
    _fxripple_entrypoint_0(0, arg1);
}

s32 fxairbub_entrypoint_1(f32* arg0, f32 arg1, f32 arg2, f32 arg3)
{
    s32 temp_v0;

    temp_v0 = func_800B5BE4(2);
    func_800BA568(temp_v0, arg2);
    func_800BA6B0(temp_v0, -arg1, 0, -arg1, arg1, 0, arg1);
    func_800BA544(temp_v0, &_fxairbub_entrypoint_0);
    return func_800BABB8(temp_v0, arg0, 0, arg3, &D_80800100_fxairbub);
}