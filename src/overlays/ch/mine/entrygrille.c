#include "ch/mineentrygrill.h"

extern s32 D_80800140_chmineentrygrille[];
extern u32 D_80800180_chmineentrygrille;
extern u32 D_80800194_chmineentrygrille;

s32 func_80800000_chmineentrygrille(Unk80800000MineEntryGrilleArg0* arg0, s32 arg1, u32 arg2) {
    s32 temp_v0;

    switch (arg1) 
    {
    case 0x7:
        _chexploder_entrypoint_3(arg0, &arg0->unk4, 8);
        //Set Flag True
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        return 1;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6);
        _chexploder_entrypoint_15(temp_v0, 2, 1.0f);

        func_800BABB8(0, &arg0->unk4, &arg0->unk4, arg0->unk38, D_80800140_chmineentrygrille);
        func_800C4AF0(&arg0->unk4, &D_80800180_chmineentrygrille);
        return 1;
    default:
        return 0;
    }
}

void func_808000C4_chmineentrygrille(s32 arg0) 
{
    if (_sujiggy_entrypoint_20(1) != 0)
    {
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        func_800FFAB0(arg0);
        return;
    }
    //Check if the cheat is not active and something about cutscenes
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7B) == 0))
    {
        func_800FFAB0(arg0);
    }
}

void* chmineentrygrille_entrypoint_0(void) {
    return &D_80800194_chmineentrygrille;
}
