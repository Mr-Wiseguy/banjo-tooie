#include "ch/mumbo/pad.h"

extern s16 D_80801086_chmumbopad[][2];
extern s16 D_808010C8_chmumbopad[];
extern s16 D_808010EC_chmumbopad[];
extern ActorData D_80801110_chmumbopad;

void func_80800674_chmumbopad(Actor*, s32);
void func_808008CC_chmumbopad(Actor*, s32);

s16 chmumbopad_entrypoint_0(s32 arg0)
{
    return D_80801086_chmumbopad[arg0][0];
}

void func_80800014_chmumbopad(s32 arg0, f32* arg1, PropId arg2)
{
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg2, arg1), arg1);
}

s32 func_80800048_chmumbopad(Actor* arg0)
{
    s16 temp_a1;

    temp_a1 = D_808010C8_chmumbopad[arg0->unk6C_0];
    if (temp_a1 != -1)
    {
        return flag_getValue((enum flag_e)temp_a1);
    }
    return 0;
}

int func_80800098_chmumbopad(Actor* arg0)
{
    s16 temp_a0;

    switch (arg0->unk6C_0)
    {
    case 12:
        return flag_getValue(FLAG_358_UNK) && flag_getValue(FLAG_359_UNK);
    case 13:
        return flag_getMultipleValue(FLAG_1CA_PROGRESS_SABREMAN_STATE_1, 2) != 0;
    default:
        temp_a0 = D_808010EC_chmumbopad[arg0->unk6C_0];
        if (temp_a0 != -1)
        {
            return flag_getValue(temp_a0);
        }
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800140_chmumbopad.s")

void func_8080044C_chmumbopad(Actor* arg0)
{
    u32 temp_t6;

    switch (arg0->unk70_10)
    {
    case 1:
        if (!(arg0->unk74_29))
        {
            func_80103110(arg0, 0U);
            if (func_80800098_chmumbopad(arg0) != 0)
            {
                _subaddiefade_entrypoint_3(arg0);
                func_80101FDC(arg0, 3U);
            }
        }
        arg0->unk74_29 = 0;
        return;
    case 2:
        if (!(arg0->unk74_29))
        {
            _subaddiefade_entrypoint_3(arg0);
            func_80101FDC(arg0, 3U);
        }
        arg0->unk74_29 = 0;
        return;
    }
}

s32 func_80800514_chmumbopad(Actor* arg0, s32 arg1, s32 arg2)
{

    switch (arg1)
    {
    case EVENT_91_ACTOR_STOOD_ON:

        if (!(arg0->unk64_19) && !(arg0->unk74_29) && !(arg0->unk0->unk28_13))
        {
            func_808008CC_chmumbopad(arg0, arg2);
        }
        func_80103110(arg0, 1U);
        break;
    case 0x32:
        func_80800674_chmumbopad(arg0, arg2);
        break;
    case 0xBB:
        if (arg2 == (arg0->unk6C_0))
        {
            arg0->unk0->unk28_13 = 0;
        }
        break;
    case 0x2E:
        if (((s16*)&arg2)[0] == 0x11DE)
        {
            _chintrotext_entrypoint_1(0x18BD, arg0->unk6C_0, 0, 1);
            arg0->unk64_19 = 0;
        }
    default:
        return 0;
    }
    return 1;
}

void func_8080063C_chmumbopad(Actor* arg0, s32 arg1)
{
    func_800F7874(arg1, arg0->unk0, arg0->position);
    func_800F5FA8(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800674_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_808008CC_chmumbopad.s")

ActorData* chmumbopad_entrypoint_1()
{
    return &D_80801110_chmumbopad;
}
