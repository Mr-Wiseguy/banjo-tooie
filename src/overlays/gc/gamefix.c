#include "gc/gamefix.h"

void gcgamefix_entrypoint_0(void)
{
    func_808000D0_gcgamefix();
    func_8080011C_gcgamefix();
    func_80800164_gcgamefix();
    func_800D1864(0x4B, 0, 0);
    func_800D1864(0x4C, 0, 0);
}

void gcgamefix_entrypoint_1(s32 arg0)
{
    u32 temp_s1;
    u32 temp_s1_2;
    u32 var_s0;

    var_s0 = 0;
    do {
        temp_s1 = func_800D1338(var_s0);
        if (func_800D129C(var_s0) == temp_s1)
        {
            temp_s1_2 = var_s0 + 0x51;
            if (func_800D0B68(temp_s1_2, 1U) == 0)
            {
                func_800D0C78(temp_s1_2, 1U, 1U);
            }
        }
        var_s0 += 1;
    } while (var_s0 != 9);
}

void func_808000D0_gcgamefix(void)
{
    if (func_800DA298(0x66) != 0)
    {
        func_800DA544(0x507);
    }
    if (func_800D0A9C(4, 4) != 0)
    {
        func_800DA544(0x504);
    }
}

void func_8080011C_gcgamefix(void)
{
    if (func_800DA298(0x4FC) != 0)
    {
        func_800DA544(0x4FD);
    }
    if (func_800DA298(0x4FF) != 0)
    {
        func_800DA544(0x500);
    }
}

void func_80800164_gcgamefix(void)
{
    if ((func_800DA298(0x327) != 0) && (func_800D0B68(0x2A, 1) == 0))
    {
        func_800D0C78(0x2A, 1, 1);
    }
}