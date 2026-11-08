#include "core2/1E7E9A0.h"

void func_800A50B0(s32 arg0)
{
    func_8010F9C0(func_8008FFE8(),arg0);
}

void func_800A50DC()
{
    func_8010FAE4(func_8008FFE8());
}

void func_800A5104()
{
    func_800A92A8();
}

void func_800A5124()
{
    func_800A9318();
}

void func_800A5144()
{
    func_8010FD88(func_8008FFE8());
}

void func_800A516C(f32* arg0, f32* arg1, f32* arg2)
{
    func_800F18FC(arg1, arg2, arg0);
    arg0[0] = ml_normalizeAngle_f(-arg0[0]);
    arg0[2] = 0.0f;
}