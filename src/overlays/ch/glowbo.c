#include "ch/glowbo.h"

#define GLOWBO_DATA(arg0) ((GlowboActorData*)(arg0->actorData))
void func_8080013C_chglowbo(Actor*);
void func_808002F4_chglowbo(Actor*);
s32 func_80800880_chglowbo(Actor*, s32, s32);
void func_80800A48_chglowbo(Actor*);
void func_80800B10_chglowbo(Actor*);
void func_80800E28_chglowbo(Actor*);
void func_80800F64_chglowbo(Actor*);
void func_80801118_chglowbo(Actor*, s32);
s32 func_8080115C_chglowbo(Actor*, s32, u32);
void func_80801258_chglowbo(Actor* );


s32 D_808013B0_chglowbo[] = {
    0x00000000,0x00000000,0x3F000000,0x3F800000,0x3F800000,0x00000000
};
s32 D_808013C8_chglowbo[] = {
    0x00000000,0x00000000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F333333,0x02120000,0x3F666666,0x02130000,0x3F333333,0x02120000
};
u32 D_80801420_chglowbo[] = {
    0x00130661,0x001655F0,0x000105DC,0x09C40000
};
u32 D_80801430_chglowbo[] = {
    0x001304D5,0x00161770,0x00000000
};
u32 D_8080143C_chglowbo[] = {
    0x00130402,0x00162EE0,0x00000000
};
u32 D_80801448_chglowbo[] = {
    0x00130402,0x00166590,0x00000000
};
u32 D_80801454_chglowbo[] = {
    0x001304DD,0x001661A8,0x00000000
};
s32 D_80801460_chglowbo[3] = {
    0x000000FF,0x00000060,0x00000060
};
f32 D_8080146C_chglowbo[18] = { 400.0f,
200.0f,
200.0f,
230.0f,
230.0f,
260.0f,
260.0f,
290.0f,
290.0f,
320.0f,
320.0f,
350.0f,
350.0f,
380.0f,
380.0f,
410.0f,
410.0f,
300.0f 
};
Vec3s32 D_808014B4_chglowbo = { 0x3F800000 ,0xBB03126F ,0x3EB33333 };
ActorData D_808014C0_chglowbo =
{
    /*0x0*/ 0x0039,
    /*0x2*/ PROP_21B_GLOWBO_REAL,
    /*0x4*/ 0x0766,
    /*0x6*/ 0x0002,
    /*0x8*/ D_808013C8_chglowbo,
    /*0xC*/ func_808002F4_chglowbo,
    /*0x10*/ func_80105834,
    /*0x14*/ func_80101870,
    /*0x18*/ 0x1388,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 1.5f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0004,
    /*0x26*/ 0x0144,
    /*0x28*/ 0x00000000,
    /*0x2C*/ func_80108ED0,
    /*0x30*/ 0x0018,
    /*0x32*/ 0x000C,
    /*0x34*/ func_8080013C_chglowbo,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x0000,
    /*0x3E*/ 0x0000,
    /*0x40*/ func_80800880_chglowbo,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
};

u32 D_80801508_chglowbo[] = {
    0x001D09E4,
    0x00220026,
    0x00330019,
    0x00140027,
    0x000000C8,
    0x000000F0,
    0x00161000,
    0x00150033,
    0x0099002B,
    0x00330066,
    0x002CFFCE,
    0x0028FFCE,
    0x00320050,
    0x00320000
};
ActorData D_80801540_chglowbo =
{
    /*0x0*/ 0x01FF,
    /*0x2*/ 0x029F,
    /*0x4*/ 0x0766,
    /*0x6*/ 0x0004,
    /*0x8*/ D_808013C8_chglowbo,
    /*0xC*/ func_80800B10_chglowbo,
    /*0x10*/ func_80105834,
    /*0x14*/ func_80101870,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 1.5f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0000,
    /*0x26*/ 0x0144,
    /*0x28*/ 0x00000000,
    /*0x2C*/ 0x00000000,
    /*0x30*/ 0x0018,
    /*0x32*/ 0x0000,
    /*0x34*/ func_80800A48_chglowbo,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x0002,
    /*0x40*/ 0x00000000,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
};
ActorData D_80801588_chglowbo =
{
    /*0x0*/ 0x01FF,
    /*0x2*/ 0x0523,
    /*0x4*/ 0x0766,
    /*0x6*/ 0x0004,
    /*0x8*/ D_808013C8_chglowbo,
    /*0xC*/ func_80800B10_chglowbo,
    /*0x10*/ func_80105834,
    /*0x14*/ func_80101870,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 1.5f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0000,
    /*0x26*/ 0x0144,
    /*0x28*/ 0x00000000,
    /*0x2C*/ 0x00000000,
    /*0x30*/ 0x0018,
    /*0x32*/ 0x0000,
    /*0x34*/ func_80800A48_chglowbo,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x0002,
    /*0x40*/ 0x00000000,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
};

ActorData D_808015D0_chglowbo =
{
    /*0x0*/ 0x0200,
    /*0x2*/ 0x02A0,
    /*0x4*/ 0x0766,
    /*0x6*/ 0x0008,
    /*0x8*/ D_808013C8_chglowbo,
    /*0xC*/ func_80800F64_chglowbo,
    /*0x10*/ func_80105834,
    /*0x14*/ func_80801118_chglowbo,
    /*0x18*/ 0x0000,
    /*0x1A*/ 0x0000,
    /*0x1C*/ 1.5f,
    /*0x20*/ 0x0000,
    /*0x22*/ 0x0000,
    /*0x24*/ 0x0004,
    /*0x26*/ 0x0104,
    /*0x28*/ 0x00000000,
    /*0x2C*/ 0x00000000,
    /*0x30*/ 0x0000,
    /*0x32*/ 0x0000,
    /*0x34*/ func_80800E28_chglowbo,
    /*0x38*/ func_80107C2C,
    /*0x3C*/ 0x8000,
    /*0x3E*/ 0x0002,
    /*0x40*/ func_8080115C_chglowbo,
    /*0x44*/ 0x0000,
    /*0x46*/ 0x0000
}; 
f32 D_80801618_chglowbo[] = 
{
    0,-26.0f,0,0,0,0
};

void func_80800000_chglowbo(Actor* arg0) 
{
    glowboStruct* temp_v0 = (glowboStruct*)func_80100094(arg0, 0U);
    s32 sp18[3] = D_80801460_chglowbo;

    if (temp_v0->unk16 == 1)
    {
        temp_v0->unk8 = (f32)(temp_v0->unk8 + 0.02f);
        if (temp_v0->unk8 > 1.0f)
        {
            temp_v0->unk8 = 1.0f;
            temp_v0->unk16 = 0U;
        }
    }
    else {
        temp_v0->unk8 = (f32)(temp_v0->unk8 - 0.02f);
        if (temp_v0->unk8 < 0.6f)
        {
            temp_v0->unk8 = 0.6f;
            temp_v0->unk16 = 1U;
        }
    }
    sp18[0] = (s32)sp18[0] * temp_v0->unk8;
    sp18[1] = (s32)sp18[1] * temp_v0->unk8;
    sp18[2] = (s32)sp18[2] * temp_v0->unk8;
    func_800C8E84(temp_v0->unk4, sp18);
}

void func_8080013C_chglowbo(Actor* arg0)
{
    glowboStruct* sp2C;

    sp2C = (glowboStruct*)func_80100094(arg0, 0U);
    if (arg0->scale == 2.0f)
    {

        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29)
    {

        arg0->unk74_17 = 1;
        arg0->scale = 0.75f;
    }
    else
    {
        arg0->scale = 0.4f;
    }
    if ((arg0->unk74_29) && (flag_getValue(FLAG_056_STATE_MEGA_GLOWBO) != 0))
    {
        actor_mark_delete(arg0);
        return;
    }

    if (_subaddieDll_entrypoint_1(arg0) == 0)
    {
        arg0->unk58 = 0.0f;
        func_80101FDC(arg0, 0xA);
        ml_vec3f_copy(&GLOWBO_DATA(arg0)->unk10, arg0->position);
    }
    else if (arg0->unk74_29)
    {
        arg0->unk58 = D_8080146C_chglowbo[0];
    }
    else
    {
        arg0->unk58 = D_8080146C_chglowbo[sp2C->unk0];
    }
    GLOWBO_DATA(arg0)->unkC = 100.0f;

    switch (map_getCurrent()) {
    case MAP_1A7_JRL_JOLLY_ROGERS_LAGOON:
    case MAP_1A8_JRL_ATLANTIS:
    case MAP_1A9_JRL_SEA_BOTTOM:

        arg0->unk64_19 = 1;
        sp2C->unk17 = _subaddiesect_entrypoint_1(arg0);
        break;

    }
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 1U), arg0->position);
}

void func_808002F4_chglowbo(Actor* arg0)
{
    glowboStruct* sp74;
    glowboStruct2* sp70;
    f32 gamespeed;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    sp74 = (glowboStruct*)func_80100094(arg0, 0U);
    sp70 = (glowboStruct2*)func_80100094(arg0, 1U);
    if ((!arg0->unk64_19) || (_subaddiesect_entrypoint_0(arg0, sp74->unk17, 0xB) != 0))
    {
        gamespeed = time_getDelta();
        if (arg0->unk7C_12 && (rand_percentChance(0.05f) != 0))
        {
            ml_vec3f_assign_value(sp60, arg0->position[0] + rand_fBounded(-30.0f, 30.0f), arg0->position[1] + rand_fBounded(25.0f, 55.0f), arg0->position[2] + rand_fBounded(-30.0f, 30.0f));
            _fxtwinkle_entrypoint_1(sp60, ASSET_9E4_RED_SPARKLE);
        }
        func_8010D254(GLOWBO_DATA(arg0)->unk0);
        if (arg0->unk70_10 != 1)
        {
            switch (arg0->unk70_10)
            {
            case 2:
                if (_subaddierouteDll_entrypoint_4(arg0) != 0)
                {
                    if ((func_80090128() != 0) && ((func_8010C500(arg0) != 0) || (func_8010C710(arg0) < 0x9C400)))
                    {
                        arg0->unk54 = func_8010CD50(arg0, character_getActiveIndex()) - 180.0f;
                    }
                    else
                    {
                        _subaddierouteDll_entrypoint_6(arg0, sp70, sp74->unk14, 0x3F, 0.4f, 0x14, 0x28);
                    }
                    _subaddierouteDll_entrypoint_7(arg0, sp70, arg0->rotation[1], arg0->unk54, 75.0f, 0x4803);
                    sp74->unk14 = (u16)sp70->unk6;
                }
                _subaddierouteDll_entrypoint_5(arg0, sp70, sp74->unk14, 0.15f, 8.0f, 200.0f);
                if (func_8010CB84(arg0->position, 0x320) != 0)
                {
                    sp74->unk10 = (f32)arg0->unk58;
                }
                else
                {
                    sp74->unk10 = 100.0f;
                }
                GLOWBO_DATA(arg0)->unkC = func_800F15F8(GLOWBO_DATA(arg0)->unkC, sp74->unk10, gamespeed * 250.0f);
                func_801026CC(arg0, D_808014B4_chglowbo, GLOWBO_DATA(arg0)->unkC);
                func_8010C3A8(arg0, 0x305425, func_800F3780(func_80101F24(arg0), &D_808013B0_chglowbo, 3));
                if (sp74->unk4 != 0)
                {
                    ml_vec3f_copy(sp54, arg0->position);
                    sp54[1] += 150.0f;
                    func_800C8CB8(sp74->unk4, sp54);
                    func_80800000_chglowbo(arg0);
                }
                if (((sp74->unkC <= 0.0f) && (rand_percentChance(0.1f) != 0)) && (func_8010CAC0(arg0->position, 0x5DCU) != 0))
                {
                    sp74->unkC = 4.0f;
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801420_chglowbo);
                }
                else
                {
                    sp74->unkC = (f32)(sp74->unkC - time_getDelta());
                }
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801430_chglowbo, 0.3f);
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_8080143C_chglowbo, 0.8f);
                break;

            case 0xa:
                ml_vec3f_copy(arg0->position, &GLOWBO_DATA(arg0)->unk10);
                func_800EF1B8(arg0->position, arg0->rotation[1] - 90.0f, arg0->unk74_7);
                arg0->rotation[1] += (time_getDelta() * 100.0f) * func_800F3780(func_80101F24(arg0), &D_808013B0_chglowbo, 3);
                if (sp74->unk4 != 0)
                {
                    sp48[0] = arg0->position[0];
                    sp48[1] = arg0->position[1] + 150.0f;
                    sp48[2] = arg0->position[2];
                    func_800C8CB8(sp74->unk4, sp48);
                    func_80800000_chglowbo(arg0);
                }
                if (func_80101E14(arg0, 0.3f) != 0)
                {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801430_chglowbo);
                }
                if (func_80101E14(arg0, 0.8f) != 0)
                {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080143C_chglowbo);
                }

            }

        }
        else
        {
            if (sp74->unk4 != 0)
            {
                func_800C8B84(sp74->unk4);
            }
            actor_mark_delete(arg0);
        }
    }
}

s32 func_80800880_chglowbo(Actor* arg0, s32 arg1, s32 arg2)
{
    glowboStruct* sp2C;

    sp2C = (glowboStruct*)func_80100094(arg0, 0U);
    switch (arg1)
    {
        case EVENT_95_ACTOR_SPAWNED:
            _subaddierouteDll_entrypoint_1(arg0);
            actor_setCollision(arg0, flag_getValue(FLAG2_64E_UNK));
            break;
        case EVENT_3E_ACTOR_TOUCHED:
            _fxsparkle_entrypoint_1(arg0->position, 6U);
            if (arg0->unk74_29) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xD03U, 0U, arg0->position, 0U);
                flag_setValueTrue(FLAG_056_STATE_MEGA_GLOWBO);
                inventory_incrementValue(0x54U);
            }
            else {
                _sudialog_entrypoint_0(0x2A, 0);
                collectable_collectItem(sp2C->unk0, 3U);
                inventory_incrementValue(0x48U);
            }
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801454_chglowbo);
            func_80101FDC(arg0, 1U);
            if (sp2C->unk4) {
                func_800C8E54(sp2C->unk4, 0.0f, 0.0f);
                func_800C8FB0(sp2C->unk4, 0U, 0U, 0U);
            }
            break;
        case 0x13:
            sp2C->unk0 = arg2;
            break;
        case 0x55:
            sp2C->unk4 = func_800C8A98();
            func_800C8E54(sp2C->unk4, 100.0f, 750.0f);
            sp2C->unk16 = 1;
            sp2C->unk8 = 0.5f;
            break;
        default:
            return 0;
    }
    return 1;
}

ActorData* chglowbo_entrypoint_0(void) {
    return &D_808014C0_chglowbo;
}

void func_80800A48_chglowbo(Actor* arg0)
{
    glowboStruct* sp1C;
    s32 temp_v0;

    sp1C = (glowboStruct*)func_80100094(arg0, 0U);
    if (map_getCurrent() == MAP_157_IOH_WUMBA)
    {
        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29) //Set the Scale for Mega Glowbo
    {
        arg0->scale = 0.75f;
    }
    else //Set the Scale for Normal Glowbo
    {
        arg0->scale = 0.25f;
    }
    GLOWBO_DATA(arg0)->unkC = 100.0f;
    temp_v0 = func_800C8A98();
    sp1C->unk4 = temp_v0;
    func_800C8E54(temp_v0, 100.0f, 750.0f);
    sp1C->unk8 = 0.5f;
    sp1C->unk16 = 1;
}

void func_80800B10_chglowbo(Actor* arg0)
{
    glowboStruct* temp_v0 = (glowboStruct*)func_80100094(arg0, 0U);
    func_800BBCB8(arg0->position, NULL, 1.0f, 1, &D_80801508_chglowbo);
    switch (arg0->unk70_10)
    {
    case 4:
        if (arg0->unk74_30)
        {
            func_80101FDC(arg0, 3U);
            return;
        }
    default:
        return;
    case 3:
        arg0->unk54 = func_800F1DF4(arg0->position, GLOWBO_DATA(arg0)->unk0);
        GLOWBO_DATA(arg0)->unk14 = func_800EFB8C(arg0->position, GLOWBO_DATA(arg0)->unk0) / 25.0f;
        GLOWBO_DATA(arg0)->unk1C = -80.0f;
        func_80801258_chglowbo(arg0);
        GLOWBO_DATA(arg0)->unk14 = 50.0f;
        arg0->unk6C_0 = 0;
        func_800C9C70(0.25f, 0x4DEU, 1.0f, 0x4650U, arg0->position, 500.0f, 2500.0f);
        func_80101FDC(arg0, 5U);
        return;
    case 5:
        func_80801258_chglowbo(arg0);
        if ((GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1]) || (GLOWBO_DATA(arg0)->unk14 > 0.0f))
        {
            GLOWBO_DATA(arg0)->unk14 += GLOWBO_DATA(arg0)->unk1C * time_getDelta();
            func_800EFCD8(&GLOWBO_DATA(arg0)->unk10, arg0->unk54, GLOWBO_DATA(arg0)->unkC);
            ml_vec3f_add(arg0->position, &GLOWBO_DATA(arg0)->unk10);
            arg0->unk6C_0 += 1;
        }
        else if (arg0->unk64_19)
        {
            func_80101FDC(arg0, 1U);
        }
        else
        {
            GLOWBO_DATA(arg0)->unk0[1] -= 75.0f;
            func_80101FDC(arg0, 6U);
        }
        arg0->rotation[0] += 18.0f;
        func_80800000_chglowbo(arg0);
        return;
    case 6:
        func_800C8FB0(temp_v0->unk4, 0, 0, 0);
        if ((s32)arg0->alpha >= 0xF)
        {
            arg0->alpha -= 0xF;
        }
        if (GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1])
        {
            arg0->position[1] += -6.0f;
            return;
        }
        if (GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1])
        {
            arg0->position[1] += -6.0f;
            return;
        }
        func_80101FDC(arg0, 7U);
        return;
    case 7:
        func_80101FDC(arg0, 1U);
        return;
    case 1:
        func_800C8B84(temp_v0->unk4);
        actor_mark_delete(arg0);
        break;
    }
}

ActorData* chglowbo_entrypoint_1(void) {
    return &D_80801540_chglowbo;
}

ActorData* chglowbo_entrypoint_2(void) {
    return &D_80801588_chglowbo;
}

void func_80800E28_chglowbo(Actor* arg0)
{
    f32 sp3C[3];

    if (map_getCurrent() == MAP_157_IOH_WUMBA)
    {
        arg0->unk74_29 = 1;
    }
    else
    {
        arg0->unk74_29 = 0;
    }
    if (arg0->unk74_29) //Mega Glowbo Scale
    {
        arg0->scale = 0.75f;
    }
    else //Normal Glowbo Scale
    {
        arg0->scale = 0.25f;
    }
    arg0->rotation[1] = (func_80090010() + rand_fBounded(-110.0f, 110.0f));
    func_8010D254(sp3C);
    func_800EEB9C(GLOWBO_DATA(arg0)->unk0, arg0->rotation[1], 400.0f);
    ml_vec3f_add(GLOWBO_DATA(arg0)->unk0, arg0->position);
    GLOWBO_DATA(arg0)->unk0[1] = (f32)(sp3C[1] + 20.0f);
    GLOWBO_DATA(arg0)->unk1C = -80.0f;
    GLOWBO_DATA(arg0)->unk14 = 30.0f;
    func_800C9C70(0.25f, 0x4DE, 0.5f, 0x4650, arg0->position, 500.0f, 2500.0f);
}

void func_80800F64_chglowbo(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
    case 8:
        func_80801258_chglowbo(arg0);
        arg0->rotation[0] = (f32)(arg0->rotation[0] + 18.0f);
        if ((GLOWBO_DATA(arg0)->unk0[1] < arg0->position[1]) || (GLOWBO_DATA(arg0)->unk14 > 0.0f))
        {
            GLOWBO_DATA(arg0)->unk14 += (GLOWBO_DATA(arg0)->unk1C * time_getDelta());
            func_800EF1B8(arg0->position, arg0->rotation[1], GLOWBO_DATA(arg0)->unkC);
            arg0->position[1] = (f32)(arg0->position[1] + GLOWBO_DATA(arg0)->unk14);
        }
        if ((arg0->position[1] <= GLOWBO_DATA(arg0)->unk0[1]) && (GLOWBO_DATA(arg0)->unk14 <= 0.0f))
        {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801448_chglowbo);
            arg0->position[1] = (f32)GLOWBO_DATA(arg0)->unk0[1];
            GLOWBO_DATA(arg0)->unk14 = 0.0f;
            GLOWBO_DATA(arg0)->unkC = 100.0f;
            arg0->rotation[0] = func_800136E4(arg0->rotation[0]);
            arg0->unk58 = 6.0f;
            func_80101FDC(arg0, 9);
            return;
        }
        return;
    case 9:
        arg0->rotation[0] += ((360.0f - arg0->rotation[0]) * 0.1f);
        if (func_8010B990(arg0, 0x501105) & 0x24)
        {
            _subaddiefade_entrypoint_3(arg0);
        }
        if (func_8010CAC0(arg0->position, 0x12CU) == 0)
        {
            _subaddiefade_entrypoint_3(arg0);
        }
        break;
    }
}

void func_80801118_chglowbo(Actor* arg0, s32 arg1)
{
    func_800DF5D8(0x80, 0x80, 0x80, _subaddiefade_entrypoint_0(arg0));
    func_80101870(arg0, arg1);
}

s32 func_8080115C_chglowbo(Actor* arg0, s32 arg1, u32 arg2) {
    if (arg1 == 0x4D) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

ActorData* chglowbo_entrypoint_3(void)
{
    return &D_808015D0_chglowbo;
}

Actor* chglowbo_entrypoint_4(void)
{
    return func_80108474(0x2A0, &D_80801618_chglowbo, rand_fBounded(0.0f, 359.0f));
}

Actor* chglowbo_entrypoint_5(void)
{
    f32 sp1C[3];
    func_8008FE94(1, sp1C);
    return func_80108474(0x2A0U, sp1C, (s32)rand_fBounded(0.0f, 359.0f));
}

void chglowbo_entrypoint_6(void) 
{
    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_5);
}

void func_80801258_chglowbo(Actor* arg0)
{
    f32 sp44[3];
    f32 var_f20 = GLOWBO_DATA(arg0)->unk14;
    s32 var_s1 = 0;

    ml_vec3f_copy(sp44, arg0->position);

    while ((GLOWBO_DATA(arg0)->unk0[1] < sp44[1]) || (var_f20 > 0.0f))
    {
        var_f20 += GLOWBO_DATA(arg0)->unk1C * time_getDelta();
        var_s1++;
        sp44[1] = sp44[1] + var_f20;
    }

    GLOWBO_DATA(arg0)->unkC = func_800EFB8C(arg0->position, GLOWBO_DATA(arg0)->unk0);
    if (var_s1 > 0)
    {
        GLOWBO_DATA(arg0)->unkC = (f32)(GLOWBO_DATA(arg0)->unkC / (f32)var_s1);
        return;
    }
    GLOWBO_DATA(arg0)->unkC = 0.0f;
}
