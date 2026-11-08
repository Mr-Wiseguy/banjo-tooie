#include "core2/1EB57A0.h"

void func_800DBEB0(UNKfunc_800DBEB0_ARG0* arg0)
{
    Vec3f* iter;
    for (iter = &arg0->unk4[0]; iter < &arg0->unk4[0x17]; iter++)
    {
        ml_vec3f_clear(iter->f);
    }
}

void func_800DBEFC(UNKfunc_800DBEB0_ARG0* arg0, s32 arg1, f32* arg2)
{
    ml_vec3f_copy(arg2, arg0->unk4[arg1].f);
}

void func_800DBF38(UNKfunc_800DBEB0_ARG0* arg0, s32 arg1, s32* arg2)
{
    ml_vec3f_to_vec3i(arg2, arg0->unk4[arg1].f);
}

void func_800DBF74(UNKfunc_800DBEB0_ARG0* arg0, s32 arg1, s32 arg2, f32* arg3)
{
    ml_getdiff_vec3f(arg3, arg0->unk4[arg2].f, arg0->unk4[arg1].f);
    ml_vec3f_normalizeMagnitude(arg3);
}

void func_800DBFD8(UNKfunc_800DBEB0_ARG0* arg0)
{
    heap_free(arg0);
}

UNKfunc_800DBEB0_ARG0* func_800DBFF8(void)
{
    UNKfunc_800DBEB0_ARG0* temp_v0;
    temp_v0 = heap_alloc(sizeof(UNKfunc_800DBEB0_ARG0));
    func_800DBEB0(temp_v0);
    return temp_v0;
}

void func_800DC028(UNKfunc_800DBEB0_ARG0* arg0, s32 arg1, f32* arg2)
{
    ml_vec3f_copy(arg0->unk4[arg1].f, arg2);
}

UNKfunc_800DBEB0_ARG0* func_800DC060(UNKfunc_800DBEB0_ARG0* arg0)
{
    if (arg0 != 0)
    {
        arg0 = defrag(arg0);
    }
    return arg0;
}
