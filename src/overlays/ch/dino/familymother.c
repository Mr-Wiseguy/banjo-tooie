#include "ch/dino/familymother.h"

typedef struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
}unkDinoFamilyMother;

void func_808005EC_chdinofamilymother(Actor*, s32);
void func_808008E4_chdinofamilymother(Actor*);
void func_8080096C_chdinofamilymother(Actor*);
void func_80801118_chdinofamilymother(Actor*, Unk80132ED0*, s32, s32);
void func_8080119C_chdinofamilymother(Actor*, s32, s32, s32);
void func_80801228_chdinofamilymother(Actor*);
extern unkDinoFamilyMother D_80801344_chdinofamilymother[];
extern s32 D_80801398_chdinofamilymother;
extern s16 D_8080139C_chdinofamilymother;
extern s32 D_808013B4_chdinofamilymother;
extern s16 D_808013B8_chdinofamilymother;
extern f32 D_808013D0_chdinofamilymother;
extern u32 D_808013DC_chdinofamilymother;
extern f32 D_808013EC_chdinofamilymother[3];
extern f32 D_808013F8_chdinofamilymother[3];
extern s32 D_80801404_chdinofamilymother;
extern s32 D_80801440_chdinofamilymother;
extern ActorData D_80801474_chdinofamilymother;

void func_80800000_chdinofamilymother(Actor* arg0)
{
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_808005EC_chdinofamilymother(arg0, 0xA);
    }
    else if ((flag_getValue(FLAG_15E_UNK) != 0) && (flag_getValue(FLAG_189_UNK) == 0) && (flag_getValue(FLAG_15F_UNK) != 0) && (flag_getValue(FLAG_08A_UNK) != 0))
    {
        func_808005EC_chdinofamilymother(arg0, 9);
    }
    ml_vec3f_copy(arg0->actorData, arg0->position);
    arg0->actorData[7] = 0;
    ((f32*)&arg0->actorData)[1] = 0.0f;
}

void func_808000A0_chdinofamilymother(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 1:
        if (flag_getValue(FLAG_08A_UNK) != 0) {
            if (character_getTransform(character_getActiveIndex()) == TRANSFORM_B_KAZOOIE)
            {
                D_808013B8_chdinofamilymother = 0x1814;
            }
            if (_subaddiedialog_entrypoint_7(arg0, arg0->actorData, &D_808013B4_chdinofamilymother) != 0)
            {
                func_8080119C_chdinofamilymother(arg0, 2, 0, 0);
            }
        }
        else
        {
            switch (character_getTransform(character_getActiveIndex()))
            {
            case TRANSFORM_A_BANJO:
                D_8080139C_chdinofamilymother = 0x1812;
                break;
            case TRANSFORM_B_KAZOOIE:
                D_8080139C_chdinofamilymother = 0x1813;
                break;
            }
            if (_subaddiedialog_entrypoint_7(arg0, (s32)arg0->actorData, &D_80801398_chdinofamilymother) != 0)
            {
                func_8080119C_chdinofamilymother(arg0, 2, 0, 0);
            }
        }
        break;
    case 9:
        if (_subaddiedialog_entrypoint_4((f32*)arg0->actorData, 0x4B0, 0) != 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C6U, 0xCU, (f32*)arg0->actorData, 0x65U);
        }
        break;
    }
    func_808008E4_chdinofamilymother(arg0);
    func_8080096C_chdinofamilymother(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80800218_chdinofamilymother.s")

void func_808005EC_chdinofamilymother(Actor* arg0, s32 arg1)
{
    u32 sp2C;

    switch (arg1)
    {
    case 1:
        func_80801228_chdinofamilymother(arg0);
        break;
    case 2:
        if ((_subaddiefind_entrypoint_2(0x52D, 0) != NULL) || (_subaddiefind_entrypoint_2(0x291, 0) != NULL))
        {
            func_80801118_chdinofamilymother(arg0, arg0->unk0, 0, 0x10);
            if (character_getTransform(character_getActiveIndex()) == TRANSFORM_A_BANJO)
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1815U, 0xCU, (f32*)arg0->actorData, 0x65U);
            }
            else
            {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17BCU, 0xCU, (f32*)arg0->actorData, 0x65U);
            }
            event_sendToActorsOfType(0x291, 0x37, 0);
            break;
        }
    case 3:
        arg1 = 3;
        if (flag_getValue(FLAG_15F_UNK) == 0)
        {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17BDU, 0xCU, (f32*)arg0->actorData, 0x65U);
            func_80801118_chdinofamilymother(arg0, arg0->unk0, 2, 0x10);
            break;
        }

    case 4:
        arg1 = 4;
        if (flag_getValue(FLAG_08A_UNK) == 0)
        {
            switch (character_getTransform(character_getActiveIndex()))
            {
            case TRANSFORM_1_BK:
                sp2C = 0x17BE;
                break;
            case TRANSFORM_A_BANJO:
                sp2C = 0x1816;
                break;
            case TRANSFORM_B_KAZOOIE:
                sp2C = 0x1817;
                break;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, sp2C, 0xCU, (f32*)arg0->actorData, 0x65U);
            func_80801118_chdinofamilymother(arg0, arg0->unk0, 4, 0x10);
            break;
        }
    case 5:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17BFU, 0xCU, (f32*)arg0->actorData, 0x65U);
        break;
    case 6:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C1U, 0xCU, (f32*)arg0->actorData, 0x65U);
        func_80801118_chdinofamilymother(arg0, arg0->unk0, 0x1D, 0x30);
        break;
    case 7:
        if (character_includedInTransformMask(character_getActiveIndex(), 0x1000) != 0)
        {
            collectable_spawnItem(TDL_SCROTTY, 1U, NULL, 1U, NULL);
            func_80801118_chdinofamilymother(arg0, arg0->unk0, 9, 0x10);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1818U, 0xCU, (f32*)arg0->actorData, 0x65U);
        }
        else
        {
            func_800D0C78(0x2BU, 1U, 0U);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C2U, 0xCU, (f32*)arg0->actorData, 0x65U);
        }
        break;
    case 9:
        func_80801228_chdinofamilymother(arg0);
        break;
    }
    func_80102424(arg0, arg1);
}

void func_808008E4_chdinofamilymother(Actor* arg0)
{
    f32 sp24[3] = D_808013EC_chdinofamilymother;
    f32 sp18[3] = D_808013F8_chdinofamilymother;

    func_8010C93C(arg0, sp24, 0.1f);
    func_8010C93C(arg0, sp18, 0.3f);
}

void func_8080096C_chdinofamilymother(Actor* arg0)
{
    f32 spDC[3];
    f32 spD0[3];
    s32 spCC;
    s32 spC8;
    f32 spBC[3];
    f32 spB0[3];
    f32 spA4[3];
    s32 spA0;
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30;

    if (D_80801344_chdinofamilymother[arg0->unk70_10].unk0 == 0x3AC)
    {
        if ((func_80101E14(arg0, 0.23f) != 0) || (func_80101E14(arg0, 0.57f) != 0) || (func_80101E14(arg0, 0.79f) != 0) || (func_80101E14(arg0, 0.94f) != 0) || (func_80101E14(arg0, 0.99f) != 0)) {
            spCC = func_800B53A4(2);
            spC8 = func_800B53A4(3);
            _subaddieskeleton_entrypoint_0(arg0, 0x35, spDC);
            _subaddieskeleton_entrypoint_0(arg0, 0x37, spD0);
            func_800BABB8(spCC, spDC, NULL, 1.0f, &D_80801404_chdinofamilymother);
            func_800BA1D0(spCC, spDC, spD0, 2);
            spD0[1] -= 50.0f;
            func_800BA670(spC8, rand_f() < 0.5f ? 0x8A2 : 0x8A3);
            func_800BAA60(spC8, spD0, 0x64, 0xC8);
            spD0[1] += 50.0f;
            func_800BABB8(spC8, spD0, NULL, 1.0f, &D_80801440_chdinofamilymother);
            func_800BA22C(spC8, 3);
            func_800C4140(0x59957C4B, spD0, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.92f) != 0)
        {
            spA0 = func_800B53A4(6);
            _subaddieskeleton_entrypoint_0(arg0, 0x10, spBC);
            ml_vec3f_copy(spB0, spBC);
            spB0[1] -= 300.0f;
            func_800BEF00(spBC, spB0, spA4, 0);
            func_800BA670(spA0, rand_f() < 0.5f ? 0x8A2 : 0x8A3);
            func_800BA930(spA0, -0x15E, 0x96, -0xC8, -0x12C, 0xC8, -0x96);
            func_800BA450(spA0, 0x64, -0x64, 0x32, 0xAF, -0xC8, 0x64);
            func_800BABB8(spA0, spB0, NULL, 1.0f, &D_80801440_chdinofamilymother);
            func_800BA22C(spA0, 6);
            func_800BBCB8(spB0, NULL, 1.0f, 3, &D_80801404_chdinofamilymother);
            func_800C4140(0x4CAEA44B, spB0, 0x0BB80190);
        }
        else if ((func_80101E14(arg0, 0.1f) != 0) || (func_80101E14(arg0, 0.18f) != 0) || (func_80101E14(arg0, 0.25f) != 0))
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x10, sp94);
            ml_vec3f_copy(sp88, sp94);
            sp88[1] -= 300.0f;
            func_800BEF00(sp94, sp88, sp7C, 0);
            func_800BBCB8(sp88, NULL, 1.0f, 1, &D_80801404_chdinofamilymother);
            func_800C4140(0x4CAEA44B, sp88, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.42f) != 0)
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x2B, sp70);
            func_800C4140((((u16)(rand_fBounded(0.45f, 0.55f) * 1023.0f)) << 0x15) + 0xBBCCA, sp70, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.772f) != 0)
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x2B, sp64);
            func_800C4140((((u16)(rand_fBounded(0.75f, 0.85f) * 1023.0f)) << 0x15) + 0xBBCCA, sp64, 0x0BB80190);
        }
    }
    else
    {
        if ((func_80101E14(arg0, 0.025f) != 0) || (func_80101E14(arg0, 0.19f) != 0) || (func_80101E14(arg0, 0.36f) != 0) || (func_80101E14(arg0, 0.52f) != 0) || (func_80101E14(arg0, 0.7f) != 0) || (func_80101E14(arg0, 0.85f) != 0))
        {
            _subaddieskeleton_entrypoint_0(arg0, 0x37, sp58);
            func_800BBCB8(sp58, NULL, 1.0f, 1, &D_80801404_chdinofamilymother);
            func_800C4140(0x4CB57C4B, sp58, 0x0BB80190);
        }
        if ((func_80101E14(arg0, 0.5f) != 0) || (func_80101E14(arg0, 0.7f) != 0))
        {
            sp30 = func_800B53A4(6);
            _subaddieskeleton_entrypoint_0(arg0, 0x10, sp4C);
            ml_vec3f_copy(sp40, sp4C);
            sp40[1] -= 300.0f;
            func_800BEF00(sp4C, sp40, sp34, 0);
            func_800BA930(sp30, 0x96, 0x96, 0x12C, 0xC8, 0xC8, 0x15E);
            func_800BA450(sp30, -0x32, -0x64, -0x64, -0x64, -0xC8, -0xAF);
            func_800BABB8(sp30, sp40, NULL, 1.0f, &D_80801440_chdinofamilymother);
            func_800BA22C(sp30, 6);
            func_800BBCB8(sp40, NULL, 1.0f, 1, &D_80801404_chdinofamilymother);
            func_800C4140(0x3FEDAC11, sp40, 0x0BB80190);
        }
    }
}

void func_80801118_chdinofamilymother(Actor* arg0, Unk80132ED0* arg1, s32 arg2, s32 arg3)
{
    switch (arg0->actorData[7])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x27U, arg3 | 0x10);
    case 1:
        arg0->actorData[7] = 2;
    case 2:
        _capod_entrypoint_6(arg1, arg2, arg3);
        return;
    }
}

void func_8080119C_chdinofamilymother(Actor* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    switch (arg0->actorData[7])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x27U, arg3 | 0x10);
    case 2:
        _capod_entrypoint_8(1);
        arg0->actorData[7] = 1;
        _gcdialogcamera_entrypoint_6(arg0->unk0);
        _gcdialogcamera_entrypoint_8();
    case 1:
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}

void func_80801228_chdinofamilymother(Actor* arg0)
{
    if (arg0->actorData[7] != 0)
    {
        _capod_entrypoint_3(0U);
        arg0->actorData[7] = 0;
    }
}

ActorData* chdinofamilymother_entrypoint_0()
{
    return &D_80801474_chdinofamilymother;
}
