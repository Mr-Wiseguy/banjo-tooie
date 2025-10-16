#include "gc/level.h"

extern u8 D_8012762C;
extern s8 D_8012762D;
extern u8 D_808003C0_gclevel[];

void gclevel_entrypoint_0(s32 arg0, s32 arg1)
{
    s32 sp1C;
    s32 sp18;

    sp1C = D_8012762C;
    sp18 = gclevel_entrypoint_2(arg0);
    if (func_800A824C() != 0)
    {
        func_800A8240();
        return;
    }
    if (func_80800270_gclevel(arg0, arg1, sp18) != 0)
    {
        D_8012762D = sp18;
    }
    _cosectionstor_entrypoint_0();
    func_800A13A0();
    func_800CE524();
    func_800CEF7C();
    func_800DA104();
    func_8009E9A8();
    func_8080016C_gclevel(sp1C, sp18, arg0, arg1);
    func_800C75E8();
}

void gclevel_entrypoint_1(void)
{
    if (func_800A824C() == 0)
    {
        func_8009E9A0();
        func_800CF2B0();
        func_800CE7DC();
        _cosectionstor_entrypoint_1();
        func_800C75C0();
    }
}

s32 gclevel_entrypoint_2(s32 arg0)
{
    return D_8012762C = _gcsectionDll_entrypoint_4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/level/gclevel_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/level/func_8080016C_gclevel.s")

s32 gclevel_entrypoint_4(s32 arg0)
{
    if (D_8012762C >= 0xD && D_8012762C < 0x1C)
    {
        return (D_808003C0_gclevel[D_8012762C - 0xD]) & arg0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/level/func_80800270_gclevel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/level/func_80800314_gclevel.s")
