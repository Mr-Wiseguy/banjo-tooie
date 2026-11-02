#include "ba/dust.h"

void badust_entrypoint_12(PlayerState*, s32);
void badust_entrypoint_4(PlayerState*, f32, f32);

s32 badust_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_badust(s32 arg0) 
{
}
void func_80800010_badust(PlayerState* arg0)
{
    if (_batimer_decrement(arg0, 8) != 0)
    {
        func_800A2EEC(arg0, 0);
        _batimer_set(arg0, 8, 0.12f);
    }
    arg0->dust->unk9 = (arg0->dust->unk9 + 1) % 2;
    switch (arg0->dust->unk9)
    {
    case 0:
        badust_entrypoint_4(arg0, (func_8009BB18(arg0) + 180.0f) - 70.0f, 20.0f);
        return;
    case 1:
        badust_entrypoint_4(arg0, (func_8009BB18(arg0) + 180.0f) - 10.0f, 20.0f);
        return;
    case 2:
        badust_entrypoint_4(arg0, func_8009BB18(arg0) + 180.0f + 50.0f, 20.0f);
        return;
    }
}

void badust_entrypoint_1(PlayerState* arg0)
{
    f32 sp24;
    if ((func_80096544(arg0) == 0) || (sp24 = player_getWaterHeight(arg0), !(player_getCoordVertical(arg0) < sp24)))
    {
        if (arg0->dust->unk4 != 0)
        {
            arg0->dust->unk4 = 0;
        }
        else
        {
            arg0->dust->unk4 = 1;
        }
        if (baphysics_get_horizontal_velocity(arg0) > 100.0f)
        {
            if (arg0->dust->unk4 != 0)
            {
                badust_entrypoint_4(arg0, func_8009BB18(arg0) - 20.0f, 20.0f);
                return;
            }
            badust_entrypoint_4(arg0, func_8009BB18(arg0) + 20.0f, 20.0f);
        }
    }
}

void badust_entrypoint_2(PlayerState* arg0, f32* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5)
{
    f32 temp_f0;
    unkStruct800BA198* temp_v0;
    temp_v0 = _fxdlsmoke_entrypoint_0(arg1);
    func_800BA930(temp_v0, arg2[0], arg2[1], arg2[2], arg2[0], arg2[1], arg2[2]);
    func_800BA450(temp_v0, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(temp_v0, arg3, arg3);
    func_800BA7FC(temp_v0, arg4, arg4);
    func_800BA8F8(temp_v0, arg5, arg5);
    temp_f0 = 19.0f / arg5;
    func_800BA5BC(temp_v0, temp_f0, temp_f0);
    func_800BA22C(temp_v0, 1);
}

void badust_entrypoint_3(PlayerState* arg0, f32 arg1, f32 arg2)
{
    f32 sp2C[3];
    f32 sp20[3];
    arg2 *= 0.51f;
    player_getCoords(arg0, sp20);
    sp20[1] += 12.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = 50.0f;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 1.0f);
}

void badust_entrypoint_4(PlayerState* arg0, f32 arg1, f32 arg2)
{
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    unkStruct800BA198* temp_v0;

    ml_vec3f_assign_value(sp34, 0.0f, 40.0f, 0.0f);
    player_getCoords(arg0, sp40);
    func_800EFCD8(sp4C, arg1, arg2);
    sp4C[1] = 15.0f;
    ml_vec3f_add(sp40, sp4C);
    temp_v0 = _fxdlsmoke_entrypoint_0(sp40);
    func_800BA930(temp_v0, sp34[0], sp34[1], sp34[2], sp34[0], sp34[1], sp34[2]);
    func_800BA450((s32)temp_v0, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(temp_v0, 0.2f, 0.2f);
    func_800BA7FC(temp_v0, 0.7f, 0.75f);
    func_800BA8F8(temp_v0, 0.6f, 0.7f);
    func_800BA5BC(temp_v0, 19.0f, 19.0f);
    func_800BA22C(temp_v0, 1);
}

void badust_entrypoint_5(PlayerState* arg0, f32 arg1, f32 arg2)
{
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    player_getCoords(arg0, sp20);
    sp20[1] += 2.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = 50.0f;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 1.0f);
}

void badust_entrypoint_6(PlayerState* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    f32 sp2C[3];
    f32 sp20[3];

    arg3 *= 0.51f;
    player_getCoords(arg0, sp20);
    sp20[1] += 12.0f + arg1;
    func_800EFCD8(&sp2C, arg2, arg3);
    sp2C[1] = arg4;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 0.7f);
}

void badust_entrypoint_7(PlayerState* arg0)
{
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;

    player_getCoords(arg0, sp50);
    sp50[1] += 20.0f;
    arg0->dust->unk8 = (arg0->dust->unk8 + 1);
    if (arg0->dust->unk8 >= 3)
    {
        arg0->dust->unk8 = 0U;
    }
    if (arg0->dust->unk8 != 0)
    {
        sp40 = func_800136E4(yaw_get(arg0) + rand_fBounded(70.0f, 90.0f));
        func_800EFCD8(sp44, sp40, (rand_f() * 15.0f) + 20.0f);
        sp44[1] = 0.0f;
    }
    switch (arg0->dust->unk8)
    {
    case 0:
        break;
    case 1:
        ml_vec3f_apply_scale(sp44, -1.0f);
        ml_vec3f_add(sp50, sp44);
        break;
    case 2:
        ml_vec3f_add(sp50, sp44);
        break;
    }
    func_800EFCD8(sp5C, yaw_get(arg0), 40.0f);
    sp5C[1] = rand_fBounded(50.0f, 90.0f);
    badust_entrypoint_2(arg0, sp50, sp5C, rand_fBounded(0.4f, 0.5f), rand_fBounded(0.7f, 0.9f), rand_fBounded(0.8f, 1.3f));
}

void badust_entrypoint_8(PlayerState* arg0)
{
    f32 var_f20;

    var_f20 = 0.0f;
    while (var_f20 < 360.0f)
    {
        badust_entrypoint_5(arg0, var_f20, 230.0f);
        var_f20 += 45.0f;
    }
}

void badust_entrypoint_9(PlayerState* arg0)
{
    switch (arg0->dust->unk4)
    {
    case 0:
        badust_entrypoint_4(arg0, func_8009BB18(arg0) - 20.0f, 40.0f);
        break;
    case 1:
        badust_entrypoint_4(arg0, func_8009BB18(arg0) + 20.0f, 40.0f);
        break;
    case 2:
        badust_entrypoint_4(arg0, func_8009BB18(arg0), 30.0f);
        break;
    }
    arg0->dust->unk4++;
    if (arg0->dust->unk4 >= 3)
    {
        arg0->dust->unk4 = 0;
    }
}

void badust_entrypoint_10(PlayerState* arg0, f32 arg1)
{
    f32 var_f20;

    var_f20 = 0.0f;
    while (var_f20 < 359.0f)
    {
        badust_entrypoint_6(arg0, arg1, var_f20, 730.0f, 100.0f);
        var_f20 += 60.0f;
    }
    var_f20 = 0.0f;
    while (var_f20 < 359.0f)
    {
        badust_entrypoint_6(arg0, arg1, func_800136E4(var_f20 + 30.0f), 430.0f, 40.0f);
        var_f20 += 60.0f;
    }
}

void badust_entrypoint_11(PlayerState* arg0)
{
    arg0->dust->unk4 = 0;
    arg0->dust->unk8 = 0;
    arg0->dust->unk0 = 0;
    badust_entrypoint_12(arg0, 1);
}

void badust_entrypoint_12(PlayerState* arg0, s32 arg1)
{
    arg0->dust->unk0 = arg1;
    switch (arg1)
    {
    case 2:
        func_8009ADF0(arg0, 3, 1);
        arg0->dust->unk9 = 0;
        _batimer_set(arg0, 8, 0.01f);
        return;
    case 3:
        func_8009ADF0(arg0, 3, 1);
        return;
    case 1:
        func_8009ADF0(arg0, 3, 0);
        return;
    }
}

void badust_entrypoint_13(PlayerState* arg0)
{

    switch (arg0->dust->unk0)
    {
    case 2:
        func_80800010_badust(arg0);
        return;
    case 3:
        func_80800008_badust((s32)arg0);
        return;
    }
}