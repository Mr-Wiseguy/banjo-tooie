#include "core2/1E7F3A0.h"

extern unkD_80127100 D_8011A1B0;
extern UNKD_8011A1BC D_8011A1BC[];
extern unkD_80127100* D_80127100;
extern u8 D_8012762C;

void func_800A5AB0(void)
{
    s32 index;
    s32 var_a0 = D_8012762C;
    s32 pad;
    unkD_80127100* var_a2 = &D_8011A1B0;
    enum map_e currentMap;

    for (index = 0; D_8011A1BC[index].unk0 != 0; index++)
    {
        if (var_a0 == D_8011A1BC[index].unk0)
        {
            var_a2 = D_8011A1BC[index].unk4;
        }
    }
    currentMap = map_getCurrent();
    for (index = 0; var_a2[index].unk0 != 0; index++)
    {
        if (currentMap == var_a2[index].unk0)
        {
            break;
        }
    }
    D_80127100 = &var_a2[index];
}

s32 func_800A5B6C(void)
{
    return D_80127100->unk2[0];
}
s32 func_800A5B7C(void) {
    return D_80127100->unk2[1];
}

f32 func_800A5B8C(void) {
    return D_80127100->unk4;
}

u8 func_800A5B9C(void) {
    return D_80127100->unk8[0];
}
u8 func_800A5BAC(void) {
    return D_80127100->unk8[1];
}
s32 func_800A5BBC(void) {
    return D_80127100->unk8[2];
}
s32 func_800A5BCC(void) {
    return D_80127100->unk8[3];
}