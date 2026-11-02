#include "ch/gameselect.h"

extern s32 D_8011A3F0;

extern ActorData D_80807FD8_chgameselect;
extern ActorData D_80808038_chgameselect;
extern ActorData D_808080C8_chgameselect;
extern ActorData D_80808298_chgameselect;
extern ActorData D_808082E0_chgameselect;
extern ActorData D_80808328_chgameselect;
extern ActorData D_808084B4_chgameselect;
extern ActorData D_80808504_chgameselect;
void func_808005D4_chgameselect(Actor*, s32);
void func_808006A0_chgameselect(Actor*, s32);
void func_8080086C_chgameselect(Actor*, s32);
void func_808020CC_chgameselect(Actor*, s32);
void func_80803D00_chgameselect(s32, s32);
s32 func_80803D60_chgameselect(s32);
void func_808065F4_chgameselect(Actor*);
extern f32 B_80808578_chgameselect;



typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}GameSelectActorData;

#define GAMESELECT_DATA(arg0) ((GameSelectActorData*)(arg0->actorData))

typedef struct
{
    u8 unk0[0xD0];
} GameSelectStruct;

typedef struct {

    void (*unk0)(void);
    u8 unk4[0x30];
}unkD_80807DFC_GAMESELECT;

extern unkD_80807DFC_GAMESELECT D_80807DFC_chgameselect[];

void func_80801658_chgameselect(s32, s32);
s32 func_80800D3C_chgameselect(Unk80132ED0*);
s32 func_80801338_chgameselect(Actor*, s32);
s32 func_808013C8_chgameselect(Actor*, s32);
s32 func_808014F0_chgameselect(Actor*, u8*);
void func_80803638_chgameselect();
void func_80800478_chgameselect(Actor*, s32);
void func_808016E8_chgameselect(s32, u32, Actor*);
void func_808036D8_chgameselect();
void func_80803C80_chgameselect();
s32 func_80803E40_chgameselect();

ActorData* chgameselect_entrypoint_0(void)
{
    return &D_80807FD8_chgameselect;
}

void func_8080000C_chgameselect(Actor* arg0) {
    s32 temp_s0;
    u32 var_s0;

    func_80016BDC(4);
    temp_s0 = func_800D395C();
    _gcfrontend_entrypoint_0();
    if (func_800AA0B8() != 0)
    {
        arg0->unk79_4 = 5;
        arg0->unk6C_0 = 5;
    }
    else if (temp_s0 != 0)
    {
        arg0->unk79_4 = 7;
        arg0->unk6C_0 = 7;
        func_800AA00C();
    }
    else
    {
        arg0->unk79_4 = 0;
        arg0->unk6C_0 = 1;
        func_800AA00C();
    }
    func_80803638_chgameselect();
    func_80108B04(arg0, 0x4ABU);
    var_s0 = 0;
    do {
        func_80108B04(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 != 8);
    func_80108B04(arg0, 0x4AAU);
    func_80108B04(arg0, 0x4A9U);
    func_80108B04(arg0, 0x4ACU);
    func_80108B04(arg0, 0x4B9U);
    arg0->actorData[7] = 0;
    arg0->unk58 = 0.1f;
    //I didn't want to mess with the actor data until I saw this happening multiple times
    *(f32**)&arg0->unk50 = (f32*)heap_alloc(0x100);
}

void func_8080015C_chgameselect(Actor* arg0)
{
    s32 sp1C;

    switch (arg0->unk70_10)
    {
    case 1:
        sp1C = func_80803E40_chgameselect();
        if (sp1C != 0)
        {
            if (_gcstatusDll_entrypoint_10() != sp1C)
            {
                _gcstatusDll_entrypoint_2(sp1C);
                return;
            }
        }
        return;
    case 9:
        if (timer_reachedZero(&arg0->unk58) != 0)
        {
            if (D_8011A3F0 != 0)
            {
                func_80803C80_chgameselect();
            }
            func_808016E8_chgameselect(arg0->actorData[4], arg0->unk79_4, arg0);
            func_80800478_chgameselect(arg0, arg0->unk6C_0);
        }
        break;
    }
}

s32 func_80800228_chgameselect(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;
    switch (arg1)
    {
    case EVENT_95_ACTOR_SPAWNED:
        func_80803D00_chgameselect(0, 0);
        break;

    case 0x3D:
    {
        if (arg2 >= 9)
        {
            temp_v0 = func_80108528(arg2, &B_80808578_chgameselect, 0, &arg0);
            temp_v0->unk79_4 = arg0->unk79_4;
            switch (arg2)
            {
            default:
                arg0->unk3C = temp_v0->unk0;
                break;
            case 0x4AB:
                arg0->actorData[4] = (u32)temp_v0->unk0;
                temp_v0->scale = arg0->scale;
                break;
            case 0x4AA:
                arg0->actorData[5] = (u32)temp_v0->unk0;
                break;
            case 0x4A9:
                arg0->actorData[3] = (u32)temp_v0->unk0;
                temp_v0->unk64_20 = 1;
                break;
            case 0x4AC:
                arg0->actorData[6] = (u32)temp_v0->unk0;
                break;
            case 0x1E8:
                arg0->actorData[7] = (u32)temp_v0->unk0;
                break;
            }
        }
        else
        {
            temp_v0 = func_80108528(0x4A8, &B_80808578_chgameselect, 0, &arg0);
            temp_v0->unk79_4 = arg2;
            func_808020CC_chgameselect(temp_v0, func_80803D60_chgameselect(arg2));
        }
        temp_v0->unk3C = arg0->unk0;
        break;
    }
    case 0xA:
        func_808005D4_chgameselect(arg0, arg2);
        break;
    case 0x7:
        func_808006A0_chgameselect(arg0, arg2);
        break;
    case 0x8:
        func_8080086C_chgameselect(arg0, arg2);
        break;
    case 0x23:
    {
        if ((arg0->unk70_10) == 5)
        {
            func_808065F4_chgameselect(arg0);
        }
        break;
    }
    default:
        return 0;
    }

    return 1;
}

void func_80800440_chgameselect(Actor* arg0) {
    s32 temp_a0;

    func_808036D8_chgameselect();
    temp_a0 = *(f32**)&arg0->unk50;
    if (temp_a0 != 0)
    {
        heap_free(temp_a0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800478_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808005D4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808006A0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080086C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808008D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800944_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800998_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808009EC_chgameselect.s")

void func_80800A4C_chgameselect(Actor* arg0)
{
    void (*temp_v0)();

    temp_v0 = D_80807DFC_chgameselect[arg0->unk70_10].unk0;
    if (temp_v0 != NULL)
    {
        temp_v0();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800A9C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800AEC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800CA0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800D3C_chgameselect.s")

ActorData* chgameselect_entrypoint_1()
{
    return &D_80808038_chgameselect;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80800D74_chgameselect.s")

void func_80800E24_chgameselect(Actor* arg0)
{
    GameSelectStruct* sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;


    sp34 = (GameSelectStruct*)func_80100094(arg0, 0U);
    sp30 = time_getDelta();
    if (func_80800D3C_chgameselect(arg0->unk3C) != 0)
    {
        if (arg0->unk58 >= 0.0f)
        {
            arg0->unk58 = arg0->unk58 - sp30;
        }
        if (!(arg0->unk64_19) && (arg0->unk58 <= 0.0f))
        {
            func_80016068(0U, &sp28);
            if (mlAbsF(sp28) > mlAbsF(sp2C))
            {
                sp2C = 0.0f;
            }
            else
            {
                sp28 = 0.0f;
            }
            if ((sp28 < -0.1f) && (((u8)arg0->unk79_4) & 3))
            {
                func_80801338_chgameselect(arg0, -1);
            }
            else if ((sp28 > 0.1f) && ((((u8)arg0->unk79_4) & 3) != 3))
            {
                func_80801338_chgameselect(arg0, 1);
            }
            if ((sp2C < -0.1f) && ((arg0->unk79_4 & 4) != 4))
            {
                func_808013C8_chgameselect(arg0, arg0->unk79_4 + 4);
            }
            else if (sp2C > 0.1f)
            {
                if (arg0->unk79_4 & 4)
                {
                    func_808013C8_chgameselect(arg0, arg0->unk79_4 - 4);
                }
            }
        }
        if (flag_getValue(FLAG2_64A_UNK) != 0)
        {
            if (func_80016B30(0U, 1U) == 1)
            {
                func_8010114C(arg0->unk3C, 8, arg0->unk79_4);
            }
            else if (func_80016B30(0U, 0U) == 1)
            {
                func_8010114C(arg0->unk3C, 7, arg0->unk79_4);
            }
        }
        if (((arg0->unk6C_0) == 1) && (arg0->unk7C_12))
        {
            if ((sp34->unk0[arg0->unk79_4 + 0xC0] != 0) && (func_808014F0_chgameselect(arg0, &sp34->unk0[arg0->unk79_4 * 0xC + 0x60])))
            {
                arg0->unk58 = 0.0f;
            }
        }
        if ((arg0->unk64_19) && !(arg0->unk64_20))
        {
            if (GAMESELECT_DATA(arg0)->unk1C > 0.0f)
            {
                GAMESELECT_DATA(arg0)->unk1C -= ((1 * time_getDelta()));
                if (GAMESELECT_DATA(arg0)->unk1C < 0.0f)
                {
                    GAMESELECT_DATA(arg0)->unk1C = 0;
                }
            }
        }
        else if (GAMESELECT_DATA(arg0)->unk1C < 1.0f)
        {
            GAMESELECT_DATA(arg0)->unk1C += ((1 * time_getDelta()));
            if (GAMESELECT_DATA(arg0)->unk1C > 1.0f)
            {
                GAMESELECT_DATA(arg0)->unk1C = 1.0f;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808011B4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808012E4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801338_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808013C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080145C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808014F0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808015DC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801658_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808016A0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808016E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801714_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801758_chgameselect.s")

ActorData* chgameselect_entrypoint_2()
{
    return &D_808080C8_chgameselect;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080179C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801AC4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801BA8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80801D74_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802070_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808020CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080218C_chgameselect.s")

ActorData* chgameselect_entrypoint_3()
{
    return &D_80808298_chgameselect;
}
ActorData* chgameselect_entrypoint_4()
{
    return &D_808082E0_chgameselect;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808021E4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802248_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802480_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808024D4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802530_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802588_chgameselect.s")

void func_808025CC_chgameselect(Actor* arg0)
{
    _gczoombox_entrypoint_2(arg0->actorData[4]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808025EC_chgameselect.s")

void func_80802620_chgameselect(Actor* arg0)
{
    _gczoombox_entrypoint_0(arg0->actorData[4]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802640_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808026C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802730_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802780_chgameselect.s")

ActorData* chgameselect_entrypoint_5()
{
    return &D_80808328_chgameselect;
}
void func_808027D4_chgameselect(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808027DC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802994_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808029D8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802A0C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802AD4_chgameselect.s")

void func_80802BE8_chgameselect(Unk80132ED0* arg0)
{
    func_808029D8_chgameselect(func_80106790(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C10_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C48_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802C7C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802CC0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802D04_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802D40_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802DB4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802E38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802F8C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80802FE4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803048_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808030EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808031F4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803248_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808032CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803420_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808034BC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803604_chgameselect.s")

void func_80803638_chgameselect()
{
    _glsavegame_entrypoint_0();
}

void func_80803658_chgameselect()
{
    _glsavegame_entrypoint_9();
}

void func_80803678_chgameselect()
{
    func_800D37C0();
}

void func_80803698_chgameselect()
{
    _glsavegame_entrypoint_10();
}

void func_808036B8_chgameselect()
{
    func_800D37D4();
}

void func_808036D8_chgameselect()
{
    _glsavegame_entrypoint_1();
}

void func_808036F8_chgameselect()
{
    _glsavegame_entrypoint_2();
}

void func_80803718_chgameselect()
{
    _glsavegame_entrypoint_3();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803738_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808037C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803888_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808038EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803940_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803988_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808039D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803A18_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803A58_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803A88_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803AB0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803B3C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803B84_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803BE8_chgameselect.s")

void func_80803C60_chgameselect()
{
    func_800FC660(0xF);
}

void func_80803C80_chgameselect()
{
    func_800FC660(0xE);
}

void func_80803CA0_chgameselect()
{
    func_800FC660(0x10);
}

void func_80803CC0_chgameselect()
{
    func_800FC660(0x96);
}

void func_80803CE0_chgameselect()
{
    func_800FC660(0x97);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803D00_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803D60_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803DCC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803E40_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803E94_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80803F90_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080401C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080407C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808040DC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080413C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808041C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804220_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808042A8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804404_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080444C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808044A4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080450C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808045E4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080462C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804694_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808046D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804750_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804878_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808048F8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804948_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080499C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808049E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804A38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804A8C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804AF0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804B4C_chgameselect.s")

void func_80804B90_chgameselect(Actor* arg0)
{
    func_80801658_chgameselect(arg0->actorData[4], 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804BB4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804BF4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804C30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804D30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804E34_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804F14_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80804F38_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808051B4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805310_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080537C_chgameselect.s")

void func_80805474_chgameselect(s32 arg0,s32 arg1)
{
    func_8080537C_chgameselect(arg0,0x1,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805498_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080569C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080595C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805AC0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805BA0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805BFC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805CD8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805ECC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805F30_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80805FCC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806068_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808061A8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806218_chgameselect.s")

s32 func_808062A8_chgameselect(void)
{
    return _gcstatusDll_entrypoint_13() - 1;
}

void func_808062CC_chgameselect(s32 arg0, s32 arg1)
{
    _gcstatusDll_entrypoint_3(arg0, arg1 + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808062EC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806370_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806408_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808064E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806540_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808065C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808065F4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808066CC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806744_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806800_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806834_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808068AC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808068E8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808069C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806A30_chgameselect.s")

void func_80806A88_chgameselect()
{
    _gcstatusDll_entrypoint_5();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806AA8_chgameselect.s")

void func_80806AD4_chgameselect()
{
    _gcstatusDll_entrypoint_10();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806AF4_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806B5C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806BD4_chgameselect.s")

ActorData* chgameselect_entrypoint_6()
{
    return &D_808084B4_chgameselect;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806C54_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806D98_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80806FAC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807030_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808070C0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_8080714C_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808073AC_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808074C8_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808075D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807790_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807824_chgameselect.s")


ActorData* chgameselect_entrypoint_7()
{
    return &D_80808504_chgameselect;
}

void func_808078F0_chgameselect(Actor* arg0)
{
    arg0->unk6C_0 = 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807900_chgameselect.s")

void func_808079C8_chgameselect(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_808079D0_chgameselect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gameselect/func_80807A10_chgameselect.s")
