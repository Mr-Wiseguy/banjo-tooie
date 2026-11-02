#include "ch/honeyb.h"

extern ActorData D_80801020_chhoneyb;
extern ActorData D_80801068_chhoneyb;
extern s32 D_808010B0_chhoneyb;
extern s32 D_808010C0_chhoneyb;
extern s32 D_808010D0_chhoneyb;

void func_8080062C_chhoneyb(Actor*);
void func_80800680_chhoneyb(Actor*);
void func_80800744_chhoneyb(Actor* arg0, s32 arg1, s32 arg2);
s32 func_80800B2C_chhoneyb(Actor*);
s32 func_80800B58_chhoneyb();
s32 func_80800B78_chhoneyb();
s32 func_80800B98_chhoneyb(s32);
s32 func_80800BD8_chhoneyb(void);
s32 func_80800C0C_chhoneyb(void);

ActorData* chhoneyb_entrypoint_0(void) 
{
    return &D_80801020_chhoneyb;
}

ActorData* chhoneyb_entrypoint_1(void) 
{
    return &D_80801068_chhoneyb;
}

void func_80800018_chhoneyb(Actor* arg0, s32 arg1, s32 arg2)
{
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x9B);
    func_80102424(arg0, 2);
}

void func_80800058_chhoneyb(Actor* arg0)
{
    s32 var_s0;

    arg0->actorData[4] = 0;
    arg0->actorData[5] = 0;
    var_s0 = func_80800B78_chhoneyb() + 1;

    while (_gcextra_entrypoint_1() >= var_s0)
    {
        if ((func_80800B58_chhoneyb() - (s32)arg0->actorData[5]) >= func_80800B98_chhoneyb(var_s0))
        {
            arg0->actorData[4] = (arg0->actorData[4] + 1);
            arg0->actorData[5] = (func_80800B98_chhoneyb(var_s0) + arg0->actorData[5]);
        }
        var_s0 += 1;
    }

    _subaddieitem_entrypoint_1(&((unkSubGameStruct*)func_80100094(arg0, 1))->unk18, arg0->actorData[5]);
}

void func_8080011C_chhoneyb(Actor* arg0)
{
    s32 temp_v0;

    func_80090708(2);
    func_80102424(arg0, 3);
    *(f32*)&arg0->actorData[7] = 1.0f;
    arg0->unk58 = 0.25f;
    temp_v0 = activePlayer_getMaxHealth();
    arg0->actorData[6] = temp_v0;
    arg0->actorData[3] = (s32)(arg0->actorData[4] + temp_v0);
    arg0->unk74_30 = 0;
    func_800FC6B0(0xA);
}

void func_80800194_chhoneyb(Actor* arg0)
{
    s32 temp[3];
    f32 sp28[3];

    if (_subaddiemarker_entrypoint_0(arg0, 0x1C1, sp28, 1) != 0)
    {
        ml_vec3f_copy(&arg0->actorData[0], sp28);
    }
    _subaddieitem_entrypoint_0(&((unkSubGameStruct*)func_80100094(arg0, 1))->unk18, 0x4B7, 0x258, 3);
    func_80800058_chhoneyb(arg0);
    _susubgame_entrypoint_0(arg0, (unkSubGameStruct*)func_80100094(arg0, 1), 0);
    _susubgame_entrypoint_12((unkSubGameStruct*)func_80100094(arg0, 1), &D_808010B0_chhoneyb);
    func_800A16BC(1);
}

void func_80800240_chhoneyb(Actor* arg0)
{
    if (_suexpression_entrypoint_20() != 0)
    {
        _suexpression_entrypoint_8(arg0, 0);
    }
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 1)) != 0)
    {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 1));
    }
}

void func_808002AC_chhoneyb(Actor* arg0)
{
    f32 sp34[3];

    func_80800680_chhoneyb(arg0);
    _sudeflect_entrypoint_1(arg0->position, 400.0f, 0.0f, 80.0f, 0xE);
    func_80800B2C_chhoneyb(arg0);
    func_8008FBE0(arg0->unk70_10 == 1);
    switch (arg0->unk70_10)
    {
    case 1:
        if (_glcutDll_entrypoint_20() == 0)
        {
            inventory_showValue(0x49);
            if (arg0->actorData[4] == 0)
            {
                if (func_80800B78_chhoneyb() < _gcextra_entrypoint_1())
                {
                    func_800D2498(0x107, func_80800C0C_chhoneyb(), 0);
                }
            }
        }
        if (_subaddiedialog_entrypoint_5(arg0->position, 0x258, 0x3C, 0) != 0)
        {
            if (func_80800B78_chhoneyb() >= _gcextra_entrypoint_1())
            {
                _susubgame_entrypoint_5(arg0, (unkSubGameStruct*)func_80100094(arg0, 1), 3, 0, 0);
                func_80800018_chhoneyb(arg0, 0x1521, 0xF);
                return;
            }
            if (flag_getValue(0) != 0)
            {
                func_80800744_chhoneyb(arg0, 0x1519, 0);
                return;
            }
            _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 0, 0);
            func_80800018_chhoneyb(arg0, 0x1519, 0xF);
            return;
        }
        return;
    case 4:
        if (arg0->unk74_29)
        {
            _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 0, 0);
            func_80800018_chhoneyb(arg0, 0x1518, 0xF);
            return;
        }
        break;
    case 5:
        func_80103DFC(arg0, sp34);
        if (_subaddieitem_entrypoint_3(arg0, sp34, &((unkSubGameStruct*)func_80100094(arg0, 1))->unk18) != 0)
        {
            func_80800018_chhoneyb(arg0, 0x1553, 0xF);
            return;
        }
        break;
    case 3:
        func_800FA9F4(0, *(f32*)&arg0->actorData[7]);
        func_800D2498(0x119, arg0->actorData[6], arg0->actorData[3]);
        if (func_800D27F4(0x119) != 0)
        {
            if (*(f32*)&arg0->actorData[7] < 1.0f)
            {
                *(f32*)&arg0->actorData[7] += (time_getDelta() * 2/*.0f*/);
                if (*(f32*)&arg0->actorData[7] > 1.0f)
                {
                    *(f32*)&arg0->actorData[7] = 1.0f;
                    func_800C3FC0(0x66C, ml_map_f(*(s32*)&arg0->actorData[6], 1/*.0f*/, 10.0f, 0.8f, 1.5f), 0x7D00);
                }
            }
            if (timer_reachedZero(&arg0->unk58) != 0)
            {
                if ((s32)arg0->actorData[6] >= (s32)arg0->actorData[3])
                {
                    func_8080062C_chhoneyb(arg0);
                    func_80090708(0);
                    func_80102424(arg0, 1);
                    return;
                }
                arg0->actorData[6]++;
                *(f32*)&arg0->actorData[7] = 0.0f;
                arg0->unk58 = 0.75f;
            }
        }
        break;
    }
}

void func_8080062C_chhoneyb(Actor* arg0)
{
    _gcextra_entrypoint_2(arg0->actorData[4]);
    func_800A1658(activePlayer_getTransformation());
    func_80800058_chhoneyb(arg0);

    event_sendToActorsOfType(0x4B8, 0x23, func_80800B78_chhoneyb());
}

void func_80800680_chhoneyb(Actor* arg0)
{
    s32 sp1C;
    s32 sp18;
    f32 temp_f0;
    s32 temp_v0;

    temp_v0 = _suexpression_entrypoint_20();
    sp1C = temp_v0;
    sp18 = 0;
    if (temp_v0 != 0)
    {
        if ((func_801022E4(arg0) == 0x4AD) && ((temp_f0 = func_80101F24(arg0), (temp_f0 < 0.12f)) || (temp_f0 > 0.97f) || (func_80102320(arg0, 0.55f, 0.7f) != 0)))
        {
            sp18 = 1;
        }
        if (sp18 != 0)
        {
            _suexpression_entrypoint_18(sp1C, 1);
        }
        _suexpression_entrypoint_10(sp1C, arg0->unk0, 0);
    }
}


void func_80800744_chhoneyb(Actor* arg0, s32 arg1, s32 arg2)
{
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;

    sp2C = 0;
    sp28 = 0xF;
    switch (arg1)
    {
    case 0x1518:
        flag_setValueTrue(FLAG_4E9_FTT_HONEY_B);
    case 0x1519:
        flag_setValueTrue(0);
        temp_v0 = arg0->actorData[4];
        if (temp_v0 == 0)
        {
            if (func_80800BD8_chhoneyb() == 1)
            {
                sp2C = 0x151F;
            }
            else
            {
                sp2C = 0x1520;
            }
        }
        else if (temp_v0 == 1) {
            sp2C = 0x151A;
        }
        else {
            sp2C = 0x151B;
        }
        _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 1, 0);
        break;
    case 0x151A:
    case 0x151B:
        sp2C = 0x151C;
        break;
    case 0x151C:
        if (arg2 == 1) {
            sp2C = 0x151D;
        }
        else {
            sp2C = 0x151E;
        }
        sp28 = 0x4E;
        break;
    case 0x151D:
        _subaddieitem_entrypoint_2(&((unkSubGameStruct*)func_80100094(arg0, 1))->unk18);
        _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 2, 1, 0);
        func_80102424(arg0, 5);
        break;
    case 0x1553:
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 1));
        func_8080011C_chhoneyb(arg0);
        break;
    default:
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 1));
        func_80102424(arg0, 1);
        break;
    }
    if (sp2C != 0)
    {
        func_80800018_chhoneyb(arg0, sp2C, sp28);
    }
}


s32 func_80800920_chhoneyb(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0x1520) 
    {
        return func_80800BD8_chhoneyb();
    }

    if (arg1 == 0x151B) 
    {
        return arg0->actorData[4];
    }

    return -1;
}

s32 func_80800968_chhoneyb(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_80800744_chhoneyb(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
        break;
    case 0x30:
        return func_80800920_chhoneyb(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
    case 0x32:
        func_800904C8(0x8D);
        arg0->unk74_29 = 1;
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_808010C0_chhoneyb, arg0->scale);
        break;
    case 0xB:
        return 3;
    case EVENT_95_ACTOR_SPAWNED:
        _suexpression_entrypoint_12(_suexpression_entrypoint_7(arg0, 0, 0x9B), 60.0f, 20.0f);
        if ((flag_getValue(0x4E9) == 0) && (_glcutDll_entrypoint_20() == 0))
        {
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, arg0->unk0);
            func_8008F8D8(1);
            func_8008F990(&arg0->actorData[0], 300.0f);
            _susubgame_entrypoint_6(arg0, func_80100094(arg0, 1), 1, 0x60, 0);
            func_80102424(arg0, 4);
        }
        break;
    case 0x57:
        return _susubgame_entrypoint_3(arg0, func_80100094(arg0, 1), arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 0x10);
    default:
        return 0;
    }
    return 1;
}

s32 func_80800B2C_chhoneyb(Actor* arg0)
{
   return _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_808010D0_chhoneyb);
}

s32 func_80800B58_chhoneyb()
{
    return inventory_getValue(0x49);
}

s32 func_80800B78_chhoneyb()
{
    return _gcextra_entrypoint_0();
}

s32 func_80800B98_chhoneyb(s32 arg0) 
{
    if ((arg0 <= 0) || (_gcextra_entrypoint_1() < arg0))
    {
        return -1;
    }
    return (arg0 * 2) - 1;
}

s32 func_80800BD8_chhoneyb(void) 
{
    s32 sp1C;
    sp1C = func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
    return sp1C - func_80800B58_chhoneyb();
}

s32 func_80800C0C_chhoneyb(void)
{
    return func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
}

void func_80800C34_chhoneyb(Actor* arg0) 
{
    func_8010A3E8(arg0, 0.7f);
}

void func_80800C58_chhoneyb()
{
    func_8010C964();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800C78_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/chhoneyb_entrypoint_2.s")
