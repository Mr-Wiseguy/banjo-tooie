#include "ch/terryteeth.h"

extern s32 D_80800150_chterryteeth;
extern s32 D_80800190_chterryteeth;
extern ActorData D_808001A4_chterryteeth;

void func_80800000_chterryteeth(Actor* arg0)
{
    if (_sujiggy_entrypoint_20(4U) != 0)
    {
        func_800DA544(FLAG_396_PROGRESS_OPENED_WORLD_TDL);
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7EU) == 0))
    {
        func_800FFAB0(arg0);
    }
}

s32 func_8080006C_chterryteeth(Actor* arg0, s32 arg1, s32 arg2) 
{
    Actor* temp_v0;

    switch (arg1)
    {

    case 0x7:
        _chexploder_entrypoint_3(arg0, arg0->position, 8U);
        break;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6U);
        _chexploder_entrypoint_15(temp_v0, 2U, 1.0f);
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800150_chterryteeth);
        func_800C4AF0(arg0->position, &D_80800190_chterryteeth);
        func_800DA544(FLAG_396_PROGRESS_OPENED_WORLD_TDL);
        break;
    default:
        return 0;
    }
    return 1;
}

ActorData* chterryteeth_entrypoint_0(void)
{
    return &D_808001A4_chterryteeth;
}