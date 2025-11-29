#include "core2/1EA0AA0.h"

typedef struct {
    u8 unk0;
    s8 unk1;
} D_8012760C_unk;
extern u8 D_8011A904;
extern s16 D_8011A910[];
extern D_8012760C_unk D_8012760C;
extern s8 D_8012AAF0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C71B0.s")

void func_800C7230(s32 arg0)
{
    func_800FF01C(func_800C71B0(arg0, 0.2f));
}

void func_800C725C(s32 arg0)
{
    func_800C4308(func_800C71B0(arg0, 0.51f), 1.0f);
}

void func_800C7290(s32 arg0) 
{
    func_800FC9B4(1, func_800C71B0(arg0, 0.2f));
}
void func_800C72C0(s32* arg0)
{
    if (D_8011A904 != 0)
    {
        D_8011A904 = 0;
        arg0[1] = 0;
    }
}

void func_800C72E4(s32 arg0) 
{
}
void func_800C72EC(s32* arg0)
{
    if (D_8011A904 != 0) {
        D_8011A904 = 0;
        arg0[1] = 0;
    }
}

void func_800C7310(s32 arg0) 
{
    _gcgoto_entrypoint_8(0, 0);
}

s32 func_800C7338(s32 arg0)
{
    f32 sp1C[3];

    if (_gccubesearch_entrypoint_3(arg0, sp1C) != 0)
    {
        return 1;
    }
    return 0;
}

void func_800C7364(s32 arg0, s32 arg1, s32* arg2)
{
    if ((func_800C7338(arg0) != 0) && (*arg2 == 0))
    {
        *arg2 = arg1;
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C73A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C7494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C7500.s")

void func_800C7574(s32 arg0, s32 arg1)
{
    if (arg1 == 2)
    {
        D_8012AAF0 = 1;
        return;
    }
    D_8012AAF0 = 0;
}

s32 func_800C75A0(s32 arg0)
{
    return D_8011A910[arg0];
}

u8 func_800C75B4(void) {
    return D_8012760C.unk0;
}

void func_800C75C0(void)
{
    func_800C77DC(1);
    func_800FC81C();
}

void func_800C75E8(void)
{
    D_8012760C.unk0 = 0;
    D_8012760C.unk1 = 0;
    func_800C77DC(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C7618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C76E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C775C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0AA0/func_800C77DC.s")

void func_800C78CC(u32 arg0)
{
    if (arg0 != 0) {
        func_800C76E8();
        return;
    }
    func_800C775C();
}

void func_800C7900(void) 
{
    s32 sp1C;
    s32 temp_v0;

    if ((D_8012760C.unk1 == 0) && ((s32)D_8012760C.unk0 >= 2) && (func_8001210C(3) != 0))
    {
        temp_v0 = func_800C75A0(D_8012760C.unk0);
        sp1C = temp_v0;
        if (func_800FCCD4(temp_v0) == 0)
        {
            func_800C7618(sp1C, -1);
        }
    }
}