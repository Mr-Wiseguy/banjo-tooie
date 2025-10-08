#include "ch/secreteggs.h"

extern unkEggData D_80800494_chsecreteggs[0x3];
extern s32 D_808004A8_chsecreteggs;
extern f32 D_808004EC_chsecreteggs[5];
extern f32 D_80800500_chsecreteggs[3];
extern u32 D_8080050C_chsecreteggs;

void func_80800000_chsecreteggs(Actor* arg0)
{
    s32 temp_v0;

    temp_v0 = func_800B53A4(0x14);
    func_800BABB8(temp_v0, arg0->position, arg0->position, 1.0f, &D_808004A8_chsecreteggs);
    switch (arg0->unk0->unk14)
    {
    case 0x974:
        func_800BA3FC(temp_v0, 0x9DF);
        break;
    case 0x975:
        func_800BA3FC(temp_v0, 0x9E0);
        break;
    case 0x976:
        func_800BA3FC(temp_v0, 0x9E2);
        break;
    }
    func_800BA22C(temp_v0, 0x14);
}

void func_808000C0_chsecreteggs(Actor* arg0)
{
    if (arg0->unk7A_5)
    {
        if (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) != 0)
        {
            func_800FFA88(arg0->unk0);
            return;
        }
        func_8010A570(arg0);
    }
}

void func_80800118_chsecreteggs(Actor* arg0) 
{
    switch (arg0->unk70_10)
    {
    case 1:
    {
        f32 sp3C[5] = D_808004EC_chsecreteggs;
        f32 sp30[3] = D_80800500_chsecreteggs;
        if (func_80101E4C(arg0, sp3C) != 0)
        {
            func_800C4140(0xF2EFA53F, arg0->position, 0x04B000FA);
        }
        else if (func_80101E4C(arg0, sp30) != 0)
        {
            func_800C4140(0xBFCFA53D, arg0->position, 0x04B000FA);
        }
        if (arg0->unk7A_5)
        {
            s32 temp_v0 = _plsu_entrypoint_3(arg0->unk0);
            if (temp_v0 != -1)
            {
                func_800F7BC8(temp_v0, 0x53, arg0->unk0);
                return;
            }
        }
    }
    return;
    case 2:
        if (func_80101E14(arg0, 0.32f) != 0)
        {
            func_800C4140(0x7FFF4561, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.4f) != 0)
        {
            func_80800000_chsecreteggs(arg0);
            if (arg0->unk7A_5)
            {
                func_800F7700(func_800F54E4(), 9, arg0->position);
                return;
            }
        }
        else if (func_80101DDC(arg0) != 0)
        {
            if ((arg0->unk7A_5) && (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) == 0))
            {
                func_800DA544(FLAG_3E7_SNS_EGG_HATCHED_YELLOW);

                func_80101180(0x514, 0x18, arg0->unk7A_5 ? 1 : 0);
            }
            _subaddiefade_entrypoint_3(arg0);
        }
        break;
    }
}

s32 func_80800328_chsecreteggs(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 var_a1;

    switch (arg1)
    {
    case 0x18:
        if (arg0->unk70_10 != 2)
        {
            func_80102424(arg0, 2);
        }
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        switch (D_80800494_chsecreteggs[arg0->unk70_10].unk0)
        {
        case 0x1D4:
            func_800DF744(1, 1);
            break;
        case 0x1D5:
            func_800DF744(1, 2);
            break;
        }
        return 1;
    case 0x3E:
        var_a1 = 0;
        if (arg0->unk0->unk14 != 0x974)
        {
            if (arg0->unk0->unk14 == 0x975)
            {
                func_800DA544(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE);
                var_a1 = 0x1551;
            }
        }
        else
        {
            func_800DA544(FLAG_3E5_SNS_EGG_ACQUIRED_PINK);
            var_a1 = 0x1552;
        }
        if (var_a1 != 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, 4, arg0->position, 0x6F);
        }
        func_800D1844(0x52);
        func_80800000_chsecreteggs(arg0);
        func_800FC660(0xE);
        func_800FFA88(arg0->unk0);
        return 1;
    default:
        return 0;
    }
}

u32* chsecreteggs_entrypoint_0(void) 
{
    return &D_8080050C_chsecreteggs;
}