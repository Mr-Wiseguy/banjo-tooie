#include "ch/dippy.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
} DippyActorData;
#define DIPPY_DATA(x) ((DippyActorData*)x->actorData)

extern u32 D_80801480_chdippy;
extern u32 D_80801490_chdippy;
extern u32 D_808014A0_chdippy;
extern s32 D_808014B0_chdippy;
extern s32 D_808014D8_chdippy;


extern ActorData D_80801580_chdippy;
extern ActorData D_808015C8_chdippy;
extern s32 D_80801610_chdippy;
extern s32 D_80801620_chdippy;
extern u32 D_8080164C_chdippy;
extern u32 D_8080165C_chdippy;
extern u32 D_8080166C_chdippy;
extern u32 D_80801688_chdippy;
extern u32 D_80801698_chdippy; 
extern u32 D_808016A4_chdippy;
extern u32 D_808016B4_chdippy;
extern u32 D_808016C4_chdippy;
extern u32 D_808016DC_chdippy;
extern u8 D_808016E8_chdippy[][2];
extern s32 D_808016F0_chdippy;
extern s32 D_80801734_chdippy;
extern s32 D_8080174C_chdippy;

void func_8080047C_chdippy(Actor*, s32, s32);
void func_80800530_chdippy(Actor*);
void func_80800654_chdippy(Actor*, s32);
void func_80800800_chdippy(Actor*);
void func_80800948_chdippy(Actor*);
void func_80800990_chdippy(Actor*);
void func_808009D8_chdippy(Actor*);
void func_80800CBC_chdippy(Actor*, u32, u32);
void func_80800D44_chdippy(Actor*);
void func_80801200_chdippy();


ActorData* chdippy_entrypoint_0()
{
    return &D_80801580_chdippy;
}
ActorData* chdippy_entrypoint_1()
{
    return &D_808015C8_chdippy;
}

void func_80800018_chdippy(Actor* arg0)
{
    f32 sp2C[3];
    s32 pad;
    s32 var_a2;

    var_a2 = _glcutDll_entrypoint_20() != 0;
    if (var_a2 != 0)
    {
        var_a2 = _chcredits_entrypoint_1() == 0x61;
    }
    _gccubesearch_entrypoint_3(0x3AD, sp2C);
    arg0->unk70_25 = func_800CBC3C(sp2C) + 1;
    arg0->unk70_4 = 1;
    if (flag_getValue(FLAG_327_UNK) != 0)
    {
        flag_setValueTrue(FLAG_328_UNK);
    }
    if (var_a2 != 0)
    {
        var_a2 = 0xE;
    }
    else
    {
        var_a2 = 1;
    }
    func_80800654_chdippy(arg0, var_a2);
}

void func_808000D8_chdippy(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 1:
        func_80800530_chdippy(arg0);
        return;
    case 3:
        if (func_80101E14(arg0, 0.6f) != 0)
        {
            _chintrotext_entrypoint_1(0x18B9, 0xE, 1, 0);
        }
        func_80800800_chdippy(arg0);
        if (func_80101DDC(arg0) != 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E9, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 5);
            return;
        }
    default:
        return;
    case 4:
        func_80800948_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) 
        {
            if (flag_getValue(FLAG_327_UNK) != 0) 
            {
                func_80800654_chdippy(arg0, 0xA);
                return;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EA, 7, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 5);
            return;
        }
        break;
    case 6:
        if (func_80101DDC(arg0) != 0) 
        {
            func_80800D44_chdippy(arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 7:
        func_80800990_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) 
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EB, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 8);
            return;
        }
        break;
    case 9:
        if (func_80101DDC(arg0) != 0) 
        {
            func_80800D44_chdippy(arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 10:
        func_808009D8_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) 
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17EC, 6, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 8);
            return;
        }
        break;
    case 11:
        if (func_80101DDC(arg0) != 0) 
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17ED, 7, arg0->position, 0xAC);
            func_80800654_chdippy(arg0, 0xC);
            return;
        }
        break;
    case 13:
        if (func_80101DDC(arg0) != 0) 
        {
            func_80800D44_chdippy(arg0);
            func_80800654_chdippy(arg0, 1);
            return;
        }
        break;
    case 14:
        func_80800990_chdippy(arg0);
        if (func_80101DDC(arg0) != 0) 
        {
            func_80800654_chdippy(arg0, 0xF);
        }
        break;
    }
}

s32 func_80800374_chdippy(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_8080047C_chdippy(arg0, ((s16*)&arg2)[0], ((s16*)&arg2)[1]);
        break;
    case 0xB:
        switch (arg2)
        {
        case 0x47:
            func_80800654_chdippy(arg0, 7);
            return 4;
        case 0x37:
            func_80800D44_chdippy(arg0);
            if (_glcutDll_entrypoint_19(0x36U) != 0)
            {
                _glcutDll_entrypoint_17();
            }
            return 4;
        default:
            return 3;
        }
    case EVENT_95_ACTOR_SPAWNED:
        if (_glcutDll_entrypoint_19(0x36U) != 0)
        {
            _subaddieDll_entrypoint_4(arg0, 1U);
            func_80800654_chdippy(arg0, 2);
            func_80800CBC_chdippy(arg0, 0x47U, 0x2030U);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080047C_chdippy(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x17E9:
        func_80800654_chdippy(arg0, 6);
        return;
    case 0x17EA:
        func_80800654_chdippy(arg0, 6);
        return;
    case 0x17EB:
        func_80800654_chdippy(arg0, 0xA);
        return;
    case 0x17EC:
        func_800D0C78(0x2AU, 1U, 0U);
        func_80800654_chdippy(arg0, 9);
        return;
    case 0x17ED:
        func_80800654_chdippy(arg0, 0xD);
    default:
        return;
    }
}

void func_80800530_chdippy(Actor* arg0)
{
    u32 sp2C;
    f32 sp20[3];

    sp2C = character_getActiveIndex();
    if ((func_8010D23C() != 0) && (character_isStable((s32)sp2C) != 0) && (character_includedInTransformMask((s32)sp2C, 0x601) != 0) && (func_8010C500(arg0) != 0))
    {
        if (flag_getValue(FLAG_328_UNK) == 0)
        {
            func_80800654_chdippy((s32)arg0, 3);
            return;
        }
        if ((func_80016B30(0U, 1U) == 1) && (func_800F4BB8(sp2C, -1U, 0) != 0))
        {
            func_8010D254(sp20);
            if (func_800F20BC(func_800F5F24(sp2C), func_800F1DF4(sp20, arg0->position), 60.0f) == 0)
            {
                func_800F5FE0((s32)sp2C);
                return;
            }
            if (flag_getValue(FLAG_327_UNK) != 0) {
                func_80800654_chdippy((s32)arg0, 0xB);
                return;
            }
            func_80800654_chdippy((s32)arg0, 4);
        }
    }
}

void func_80800654_chdippy(Actor* arg0, s32 arg1)
{
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, &sp1C);
    func_80102424(arg0, arg1);
    arg0->unk64_16 = 1;
    switch (arg1)
    {
    case 1:
    case 2:
        arg0->unk64_16 = 0;
        return;
    case 3:
        flag_setValueTrue(FLAG_328_UNK);
        func_80800CBC_chdippy(arg0, 0x29U, 0x30U);
        return;
    case 4:
        func_80800CBC_chdippy(arg0, 0x2EU, 0x30U);
        return;
    case 5:
        func_80800CBC_chdippy(arg0, 0x31U, 0x30U);
        return;
    case 6:
        func_80800CBC_chdippy(arg0, 0x37U, 0x30U);
        _subaddieaudioquick_entrypoint_2(arg0, sp1C, &D_80801610_chdippy);
        return;
    case 7:
        func_80800CBC_chdippy(arg0, 0x2EU, 0x30U);
        return;
    case 8:
        func_80800CBC_chdippy(arg0, 0x31U, 0x30U);
        return;
    case 9:
        func_80800CBC_chdippy(arg0, 0x37U, 0x30U);
        return;
    case 10:
        func_80800CBC_chdippy(arg0, 0x34U, 0x30U);
        return;
    case 11:
        func_80800CBC_chdippy(arg0, 0x2EU, 0x30U);
        return;
    case 12:
        func_80800CBC_chdippy(arg0, 0x31U, 0x30U);
        return;
    case 13:
        func_80800CBC_chdippy(arg0, 0x37U, 0x30U);
    default:
        return;
    }
}

void func_80800800_chdippy(Actor* arg0)
{
    f32 sp34[3];
    f32 sp30;
    s32 sp2C;

    sp30 = func_80101F24(arg0);
    sp2C = func_8001211C();
    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp34);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, &D_808014A0_chdippy, &D_80801688_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_80801480_chdippy, 0.43f);
    _subaddieaudioquick_entrypoint_4(arg0, sp34, &D_8080164C_chdippy, &D_80801698_chdippy);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_8080165C_chdippy, 0.9f);
    _subaddieaudioquick_entrypoint_3(arg0, sp34, &D_8080166C_chdippy, 0.61f);
    if ((sp30 > 0.61f) && (sp30 < 0.66f) && !(sp2C & 1) && (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp34) != 0)) {
        func_800BBCB8(sp34, NULL, 1.0f, 1, &D_80801620_chdippy);
    }
}

void func_80800948_chdippy(Actor* arg0)
{
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, &sp1C, &D_80801480_chdippy, 0.4f);
}

void func_80800990_chdippy(Actor* arg0)
{
    f32 sp1C[3];

    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801490_chdippy, 0.15f);
}

void func_808009D8_chdippy(Actor* arg0)
{
    f32 sp8C[3];
    f32 sp88;
    f32 sp7C[3];
    s32 sp78;
    Vec3f sp48[4];
    f32* var_s1;
    s32 temp_v0;
    s32 i;

    sp88 = func_80101F24(arg0);
    _subaddieskeleton_entrypoint_3((s32)arg0->unk0, 5, sp8C);
    _subaddieaudioquick_entrypoint_4(arg0, sp8C, &D_808016A4_chdippy, &D_808016C4_chdippy);
    _subaddieaudioquick_entrypoint_4(arg0, sp8C, &D_808016B4_chdippy, &D_808016DC_chdippy);
    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp7C) && sp7C[1] < 1500.0f)
    {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 5, sp8C);
        sp8C[1] = 1500.0f;
        func_800BBCB8(sp8C, NULL, 1.5f, 1, &D_808014B0_chdippy);
        _subaddieskeleton_entrypoint_2(arg0->unk0, 7, sp8C);
        sp8C[1] = 1500.0f;
        func_800BBCB8(sp8C, NULL, 1.5f, 1, &D_808014B0_chdippy);
    }
    if (sp88 > 0.3f && arg0->unk7C_12 && sp7C[1] > 1500.0f)
    {
        sp78 = rand_iBounded(0, 3);
        for (i = 0; i < 4; i++) {
            _subaddieskeleton_entrypoint_2(arg0->unk0, i + 5, sp48[i].f);
        }
        temp_v0 = func_800B53A4(1);
        func_800BA994(temp_v0, -0x2D, arg0->rotation[1] - 25.0f, 0x19, -0x19, arg0->rotation[1] + 25.0f, 0x4B);
        func_800BA5A8(temp_v0, 0x1200);
        func_800BABB8(temp_v0, sp7C, NULL, 1.0f, &D_808014D8_chdippy);
        func_800BA4D0(temp_v0, 0x5DC);
        func_800BA544(temp_v0, &_chdippy_entrypoint_2);
        func_800BA1D0(temp_v0, &sp48[D_808016E8_chdippy[sp78][0]], &sp48[D_808016E8_chdippy[sp78][1]], 1);
    }
}

void chdippy_entrypoint_2(s32 arg0, f32* arg1)
{
    func_800BBCB8(arg1, NULL, 1.2f, 1, &D_808014B0_chdippy);
}

void func_80800CBC_chdippy(Actor* arg0, u32 arg1, u32 arg2)
{
    if (arg0->unk64_20)
    {
        _capod_entrypoint_14();
        arg2 = arg2 | 0x2000;
    }
    if (_glcutDll_entrypoint_19(0x36U) != 0)
    {
        arg2 |= 0x800;
    }
    _capod_entrypoint_13(arg0->unk0, NULL, arg1, arg2);
    arg0->unk64_20 = 1;
}

void func_80800D44_chdippy(Actor* arg0)
{
    if (arg0->unk64_20)
    {
        _capod_entrypoint_14();
        arg0->unk64_20 = 0;
    }
}

void func_80800D84_chdippy(Actor* arg0)
{
    arg0->unk64_16 = 0;
    (f32)arg0->actorData[1] = arg0->position[1];
}

void func_80800D9C_chdippy(Actor* arg0)
{
    s32 sp54;
    f32 sp48[3];
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 pad;

    switch (arg0->unk70_10)
    {
        default:
            break;
        case 2:
            timer_reachedZero(&arg0->unk58);
            DIPPY_DATA(arg0)->unk0 = func_800F12D4(arg0->unk58, 0.0f, 6.0f, 0.0f, -2000.0f);
            arg0->position[1] = DIPPY_DATA(arg0)->unk0 + DIPPY_DATA(arg0)->unk4;
            if (arg0->unk58 > 1.0f)
            {
                func_800BBCB8(arg0->position, arg0->position, 1.0f, 2, &D_808016F0_chdippy);
            }
            else
            {
                arg0->alpha = (s32)ml_map_f(arg0->unk58, 1.0f, 0.0f, 255.0f, 0.0f);
            }
            arg0->unk64_16 = 1;
            if (timer_reachedZero_dupe(&DIPPY_DATA(arg0)->unk8) != 0)
            {
                arg0->unk64_16 = 0;
                func_80101FDC(arg0, 3U);
            }
            else
            {
                if (timer_reachedZero_dupe(&DIPPY_DATA(arg0)->unkC) != 0)
                {
                    DIPPY_DATA(arg0)->unkC = rand_fBounded(0.2f, 0.5f);
                    func_8010D930(9, -1, arg0->position, &D_80801734_chdippy);
                }
                if (DIPPY_DATA(arg0)->unk8 < 15.0f)
                {
                    if (rand_f() < ml_map_f((f32)DIPPY_DATA(arg0)->unk8, 15.0f, 0.0f, 1.0f, 0.0f))
                    {
                        sp54 = 1;
                    }
                    else
                    {
                        sp54 = 0;
                    }
                }
                else
                {
                    sp54 = (s32)ml_map_f(DIPPY_DATA(arg0)->unk8, 30.0f, 0.0f, 3.0f, 1.0f);
                }
                if (sp54 != 0)
                {
                    sp44 = func_800B53A4(sp54);
                    ml_vec3f_copy(sp48, arg0->position);
                    sp48[1] += 6000.0f;
                    func_800BA5A8(sp44, 0x200);
                    func_800BA714(sp44, 0x1F4, 0x1F4);
                    func_800BABB8(sp44, sp48, NULL, 1.0f, &D_808014D8_chdippy);
                    func_800BA4D0(sp44, 0x5DC);
                    func_800BA544(sp44, &_chdippy_entrypoint_2);
                    func_800BA22C(sp44, sp54);
                }
            }
            break;
        case 1:
        case 3:
            sp40 = func_800BEA88(1);
            _glid_entrypoint_0(sp40, 1, _chdippy_entrypoint_3, arg0->unk0);
            _glid_entrypoint_0(sp40, 2, _chdippy_entrypoint_3, arg0->unk0);
            if (arg0->unk79_4-- == 0)
            {
                actor_mark_delete(arg0);
            }
            break;
    }
    sp3C = func_800BEA88(1);
    sp40 = _idworld_entrypoint_4(sp3C, 1);
    if (sp40 != 0)
    {
        _idwibble_entrypoint_5(sp40, DIPPY_DATA(arg0)->unk0);
    }
    _glid_entrypoint_0(sp3C, 2, _chdippy_entrypoint_3, arg0->unk0);
}

s32 func_80801110_chdippy(Actor* arg0, s32 arg1, s32 arg2)
{
    f32 sp34[3];
    switch (arg1)
    {
        case EVENT_95_ACTOR_SPAWNED:
        {
            func_80801200_chdippy();
            return 1;
        }
        case EVENT_1F_ACTOR_ONSCREEN:
        {
            if (arg0->unk64_16)
            {
                func_801015D0(arg0);
                func_800E3980(&sp34);
                arg0->rotation[1] = func_800F1DF4(arg0->position, sp34);
                if (arg0->unk58 < 3.0f)
                {
                    func_800DF500(1.0f, ml_map_f(arg0->unk58, 3.0f, 0.0f, 5.0f, 0.001f), 1.0f);
                }
                else
                {
                    func_800DF500(1.0f, 5.0f, 1.0f);
                }
            }
            return 1;
        }
    }
    return 0;
}

void func_80801200_chdippy(Actor* arg0)
{
    s32 sp24;

    sp24 = func_800BEA88(1);
    if (_glcutDll_entrypoint_20() != 0)
    {
        arg0->unk79_4 = 2;
        (f32)arg0->actorData[0] = 0;
        func_80101FDC(arg0, 3U);
    }
    else if (_glcutDll_entrypoint_19(0x36U) != 0)
    {
        arg0->unk58 = 6.0f;
        func_80101FDC(arg0, 2U);
        arg0->unk64_16 = 1;
        (f32)arg0->actorData[2] = 30.0f;
        (f32)arg0->actorData[3] = rand_fBounded(0.2f, 0.5f);
    }
    else if (flag_getValue(FLAG_327_UNK) == 0)
    {
        arg0->unk79_4 = 2;
        (f32)arg0->actorData[0] = -2000.0f;
        func_80101FDC(arg0, 1U);
        return;
    }
    else
    {
        arg0->unk79_4 = 2;
        (f32)arg0->actorData[0] = 0;
        func_80101FDC(arg0, 3U);
    }
    _idworldmake_entrypoint_1(sp24, 0x659, 1, 1);
    if (arg0->unk70_10 == 2)
    {
        func_800C4AF0((f32*)arg0->actorData, &D_8080174C_chdippy);
    }
}

void chdippy_entrypoint_3(s32 arg0, ChDippyUnk* arg1, ChDippyUnk* arg2, s32 arg3, Unk80132ED0* arg4)
{
    s16 temp_v1;
    ChDippyUnk* end;
    u32 i;

    temp_v1 = DIPPY_DATA(func_80106790(arg4))->unk0;
    for (end = &arg2[arg3]; arg2 < end; arg1++, arg2++)
    {
        arg2->unk2 = arg1->unk2 + temp_v1;
    }
}
