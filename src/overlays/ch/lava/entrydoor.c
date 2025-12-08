#include "ch/lavaentrydoor.h"

extern s32 D_80800150_chlavaentrydoor;
extern s32 D_80800190_chlavaentrydoor;
extern ActorData D_808001A4_chlavaentrydoor;

s32 func_80800000_chlavaentrydoor(Actor* arg0, s32 arg1, s32 arg2)
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
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800150_chlavaentrydoor);
        func_800C4AF0(arg0->position, &D_80800190_chlavaentrydoor);
        func_800DA544(FLAG_398_PROGRESS_OPENED_WORLD_HFP);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_808000CC_chlavaentrydoor(Actor* arg0)
{
    if (_sujiggy_entrypoint_20(6U) != 0)
    {
        func_800DA544(FLAG_398_PROGRESS_OPENED_WORLD_HFP);
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800D3E40(0xBU) != 0) && (_glcutDll_entrypoint_19(0x80U) == 0))
    {
        func_800FFAB0(arg0);
    }
}

ActorData* chlavaentrydoor_entrypoint_0(void) {
    return &D_808001A4_chlavaentrydoor;
}