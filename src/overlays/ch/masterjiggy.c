#include "ch/masterjiggy.h"

extern s16 D_80801620_chmasterjiggy[][2];
extern ActorData D_8080164C_chmasterjiggy;
extern ActorData D_808016F8_chmasterjiggy;
extern s32 B_808017F0_chmasterjiggy;
extern s32 _chmasterjiggy_entrypoint_2;

ActorData* chmasterjiggy_entrypoint_0()
{
    return &D_8080164C_chmasterjiggy;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_8080000C_chmasterjiggy.s")

void func_808001A8_chmasterjiggy(s32 arg0) 
{
}
void func_808001B0_chmasterjiggy(s32 arg0)
{
    _sujiggy_entrypoint_8();
}

s32 func_808001D0_chmasterjiggy(Actor* arg0, s32 arg1)
{
   return _subaddiedialog_entrypoint_11(arg0->unk0, D_80801620_chmasterjiggy[arg1][0], D_80801620_chmasterjiggy[arg1][1], arg0->position, 0x97U);
}

void func_80800220_chmasterjiggy(Actor* arg0, s32 arg1)
{
    f32 sp24[3];

    func_80102424(arg0, arg1);
    switch (arg1)
    {
    case 2:
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(func_8010D5DC, (s32)arg0->unk0);
        func_8008F938(1);
        func_8008F990((s32)&arg0->actorData[4], 500.0f);
        _capod_entrypoint_13(arg0->unk0, NULL, 0x11U, 0x60U);
        return;
    case 3:
        func_800C0658();
        func_8008F8B0();
        func_8008F904(func_8010D5DC, (s32)arg0->unk0);
        func_8008F9F8((f32*)arg0->actorData, 300.0f);
        func_8008F938(0);
        func_80090658(1);
        return;
    case 4:
        func_800DBEFC(func_800BEC10(), 4, sp24);
        func_80090734(4, sp24);
        arg0->unk58 = 1.0f;
        return;
    case 5:
        func_80108A30(0x4B1, &B_808017F0_chmasterjiggy, 0.0f, 0x32);
        ((f32*)&arg0->actorData)[7] = 1.0f;
        return;
    case 9:
        func_80101EE4(arg0, 0.8f);
    default:
        return;
    }
}

int func_80800374_chmasterjiggy(Actor* arg0)
{
    f32 sp1C[3];

    activePlayer_getCoords(sp1C);
    return sp1C[0] >= 1576.0f && activePlayer_getTransformation() == TRANSFORM_1_BK;
}

int func_808003D4_chmasterjiggy(s32 arg0)
{
    return func_80090080() && func_80016B30(0U, 1U) == 1;
}

void func_80800414_chmasterjiggy(Actor* arg0)
{
    if (func_80800374_chmasterjiggy(arg0) != 0)
    {
        if ((flag_getValue(FLAG_533_UNK) == 0) && (func_808001D0_chmasterjiggy(arg0, 3) != 0))
        {
            flag_setValueTrue(FLAG_533_UNK);
        }
        if (func_808003D4_chmasterjiggy(arg0) != 0)
        {
            func_80800220_chmasterjiggy(arg0, 3);
        }
    }
}

void func_8080047C_chmasterjiggy(s32 arg0)
{
    if ((func_800C0638() == 0) && (flag_getValue(FLAG5_D4E_UNK) == 0) && (_glcutDll_entrypoint_20() == 0))
    {
        func_800D2498(0x10EU, func_800D035C(1), 0U);
        func_800D2498(0x106U, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0U);
    }
}

void func_808004FC_chmasterjiggy(Actor* actor)
{

    func_8008FB10(actor->position, 200.0f, 0.0f, 100.0f);
    switch (actor->unk70_10)
    {
    case 1:
        if (_subaddiedialog_entrypoint_6(actor->position, (s32)actor->rotation[1], 0x190U, 0x3CU, 6) != 0)
        {
            if (_sujiggy_entrypoint_21() != 0)
            {
                func_808001D0_chmasterjiggy(actor, 8);
            }
            else
            {
                func_808001D0_chmasterjiggy(actor, 1);
            }
        }
        else
        {
            func_80800414_chmasterjiggy((s32)actor);
        }
        func_8080047C_chmasterjiggy((s32)actor);
        return;
    case 2:
    case 3:
        func_8080047C_chmasterjiggy((s32)actor);
        return;
    case 4:
        if ((func_800C0638() == 0) && (timer_reachedZero(&actor->unk58) != 0))
        {
            func_808001B0_chmasterjiggy((s32)actor);
        }
        func_8080047C_chmasterjiggy((s32)actor);
        return;
    case 5:
        if (timer_reachedZero_dupe((f32*)&actor->actorData[7]) != 0)
        {
            func_80800220_chmasterjiggy(actor, 6);
            return;
        }
    default:
        return;
    case 6:
        if (func_80101DDC(actor) != 0)
        {
            func_80800220_chmasterjiggy(actor, 7);
            return;
        }
        break;
    case 8:
        if ((func_80800374_chmasterjiggy((s32)actor) != 0) && (func_808003D4_chmasterjiggy((s32)actor) != 0))
        {
            func_808001D0_chmasterjiggy(actor, 5);
        }
        else if (_subaddiedialog_entrypoint_6(actor->position, actor->rotation[1], 0x190U, 0x3CU, 6) != 0)
        {
            func_808001D0_chmasterjiggy(actor, 2);
        }
        func_8080047C_chmasterjiggy((s32)actor);
        return;
    case 9:
    case 10:
        if (func_80101DDC(actor) != 0)
        {
            func_80800220_chmasterjiggy(actor, actor->unk70_10 + 1);
        }
        break;
    }
}

void func_80800704_chmasterjiggy(Actor* arg0, s32 arg1, s32 arg2)
{
    _capod_entrypoint_14();
    _capod_entrypoint_13(arg0->unk0, 0, arg2, 0x2030);
}

void func_80800744_chmasterjiggy(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
        case 0x14F6:
            _capod_entrypoint_14();
            flag_setValueTrue(FLAG_35B_FTT_CS_JIGGYWIGGY);
            func_80800220_chmasterjiggy(arg0, 1);
            return;
        case 0x14FC:
        case 0x155B:
        case 0x155C:
        case 0x155D:
        case 0x155E:
            func_80800220_chmasterjiggy(arg0, 1);
            return;
        case 0x1511:
            func_80800220_chmasterjiggy(arg0, 8);
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808007F0_chmasterjiggy.s")


ActorData* chmasterjiggy_entrypoint_1()
{
    return &D_808016F8_chmasterjiggy;
}

void func_8080095C_chmasterjiggy(Actor* actor)
{
    actor->scale = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_8080096C_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800A40_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800C08_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800DDC_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800E58_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80801030_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808010E4_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/chmasterjiggy_entrypoint_2.s")

void func_80801448_chmasterjiggy(Actor* arg0)
{
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chmasterjiggy_entrypoint_2, arg0->unk0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80801488_chmasterjiggy.s")
