#include "ch/jadesnake.h"

extern s32 D_80800938_chjadesnake;
extern ActorData D_808009F4_chjadesnake;

extern s32 D_80800910_chjadesnake;
extern s32 D_80800920_chjadesnake;
extern s32 D_8080092C_chjadesnake;
extern u32 D_80800948_chjadesnake;
extern u32 D_80800958_chjadesnake;
extern s32 D_80800964_chjadesnake;
extern f32 D_808009C0_chjadesnake;
extern u32 D_808009DC_chjadesnake;
extern u32 D_808009E4_chjadesnake;

void func_80800000_chjadesnake(Actor* arg0)
{
    func_8010A85C(arg0, 2);
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80102424(arg0, 9);
        func_8010A85C(arg0, 1);
    }
}

void func_80800048_chjadesnake(Actor* arg0)
{
    collectable_spawnItem(MT_SSSLUMBER, 1U, &arg0->actorData[4], 3U, arg0->unk0);
    _subaddieaudioquick_entrypoint_2(arg0, &arg0->actorData[4], &D_80800938_chjadesnake);
}

int func_8080009C_chjadesnake(s32 arg0)
{
    s32 currentPlayerIndex;
    s32 playerHorizontalUnk;
    s32 isGrounded;
    s32 justLanded;
    s32 currentHitbox;
    s32 unk;

    currentPlayerIndex = character_getActiveIndex();
    playerHorizontalUnk = func_800F651C(currentPlayerIndex);
    isGrounded = character_isStable(currentPlayerIndex);
    justLanded = func_800F72DC(currentPlayerIndex);
    currentHitbox = func_800F56AC(currentPlayerIndex) == 0x10;
    unk = func_800F6478(currentPlayerIndex);
    //This is if we're in the hitbox or above it something to that effect
    if (!currentHitbox) {
        return 0;
    }

    //Wake up the snake
    return unk && (justLanded || isGrounded && !playerHorizontalUnk);
}

void func_80800150_chjadesnake(Actor* arg0)
{
    f32 sp54[3];
    s32 sp50;
    s32 sp4C;
    s32 temp_v0;
    f32 sp44;
    f32 sp38[3];
    Actor* temp_v0_2;

    sp50 = collectable_isCollected(0xAU, 1U);
    sp4C = collectable_isSpawned(0xAU, 1U);
    func_8010D254(sp54);
    switch (arg0->unk70_10)
    {
    case 1:
        if ((arg0->unk7C_12) && (sp50 == 0) && (sp4C == 0))
        {
            collectable_spawnItem(0xAU, 1U, &arg0->actorData[0], 3U, arg0->unk0);
        }
        temp_v0 = func_80101E4C(arg0, &D_808009C0_chjadesnake);
        if (temp_v0 != 0)
        {
            func_800C4B7C(temp_v0 & 1 ? 0x5C6 : 0x5C7);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800964_chjadesnake);
        }
        if ((sp50 == 0) && (sp4C != 0) && (func_8080009C_chjadesnake(arg0) != 0))
        {
            _subaddieaudioquick_entrypoint_2(arg0, &sp54, &D_80800910_chjadesnake);
            func_80090734(2, arg0->position);
            func_8010A85C(arg0, 1);
            func_80102424(arg0, 2);
            if (func_800DA9E4(FLAG2_677_UNK, 1) == 0)
            {
                arg0->unk64_20 = 1;
                _capod_entrypoint_13(arg0->unk0, NULL, 2U, 0x10U);
            }
            else
            {
                arg0->unk64_20 = 0;
            }
        }
        break;
    case 2:
        if (sp50 != 0)
        {
            func_8010A85C(arg0, 2);
            func_80102424(arg0, 1);
            func_80090708(0);
        }
        if (func_80101E14(arg0, 0.73f) != 0)
        {
            func_800D119C(0xA, 1);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080092C_chjadesnake);
        }
        if (func_80101DDC(arg0) != 0)
        {
            if (flag_getValue(FLAG_434_FTT_MT_SSSLUMBER) != 0)
            {
                func_80102424(arg0, 3);
                func_80090708(0);
            }
            else
            {
                flag_setValueTrue(FLAG_434_FTT_MT_SSSLUMBER);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF3CU, 0xCU, arg0->position, 0x46U);
                func_80102424(arg0, 5);
            }
        }
        break;
    case 6:
        _capod_entrypoint_14();
        func_80090708(0);
        func_80102424(arg0, 3);
        break;
    case 3:
        sp44 = func_80101F24(arg0);
        func_8010D254(sp38);
        if ((func_800F56AC(character_getActiveIndex()) != 0x10) && (sp38[1] < 1160.0f))
        {
            func_80102424(arg0, 4);
            if (arg0->unk64_20)
            {
                _capod_entrypoint_13(arg0->unk0, NULL, 0U, 0x10U);
            }
        }
        if ((sp44 > 0.13f) && (sp44 < 0.64f))
        {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1U, &D_80800948_chjadesnake);
        }
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800958_chjadesnake, &D_808009DC_chjadesnake);
        break;
    case 4:
        if ((func_80101E14(arg0, 0.18f) != 0) && (sp4C == 0))
        {
            if (flag_getValue(FLAG_435_UNK) != 0)
            {
                func_80800048_chjadesnake(arg0);
            }
            else
            {
                flag_setValueTrue(FLAG_435_UNK);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF3DU, 0xCU, arg0->position, 0x46U);
                func_80102424(arg0, 7);
            }
        }
        if (func_80101DDC(arg0) != 0)
        {
            if (flag_getValue(FLAG_435_UNK) == 0)
            {
                func_80102424(arg0, 7);
            }
            else
            {
                func_8010A85C(arg0, 2);
                func_80102424(arg0, 1);
            }
        }
        if ((sp50 == 0) && (sp4C != 0) && (func_8080009C_chjadesnake(arg0) != 0))
        {
            _subaddieaudioquick_entrypoint_2(arg0, &sp54, &D_80800910_chjadesnake);
            func_80090734(2, arg0->position);
            func_8010A85C(arg0, 1);
            func_80102424(arg0, 2);
            func_80101EE4(arg0, 0.57f);
        }
        break;
    case 7:
        if (sp4C == 0)
        {
            func_80800048_chjadesnake(arg0);
        }
        break;
    case 8:
        if (func_80101DDC(arg0) != 0)
        {
            if (sp4C != 0)
            {
                func_8010A85C(arg0, 2);
                func_80102424(arg0, 1);
            }
            else
            {
                func_80800048_chjadesnake(arg0);
                func_80090708(0);
                func_80102424(arg0, 4);
            }
        }
        break;
    }
    if ((arg0->unk6C_0) && (func_800D0634(0xAU, 1U) != 0))
    {
        temp_v0_2 = func_80106790(func_800D0634(0xAU, 1U));
        ml_vec3f_add(temp_v0_2->position, (f32*)&temp_v0_2->actorData[4]);
        arg0->unk6C_0--;
        if (arg0->unk6C_0 == 2)
        {
            _subaddieaudioquick_entrypoint_2(temp_v0_2, temp_v0_2->position, &D_80800920_chjadesnake);
            return;
        }
        if (arg0->unk6C_0 == 0)
        {
            ml_vec3f_copy(temp_v0_2->position, (f32*)arg0->actorData);
            func_80102FE8(temp_v0_2, 1);
            func_80103014(temp_v0_2);
        }
    }
}

void func_80800728_chjadesnake(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 != 0xF3C)
    {
        if (arg1 == 0xF3D)
        {
            func_80102424(arg0, 8);
        }
    }
    else
    {
        func_80102424(arg0, 6);
    }
}

void func_80800770_chjadesnake(Actor* arg0, void* arg1)
{
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12)
    {
        func_800DBEFC(func_80104130(), 4, &arg0->actorData[0]);
        func_800DBEFC(func_80104130(), 5, &arg0->actorData[4]);
    }
}

s32 func_808007DC_chjadesnake(Actor* arg0, s32 arg1, u32 arg2)
{
    Actor* temp_v0;
    // FAKE
    if (arg0);

    switch (arg1)
    {
    case 0xD:
        if ((arg0->unk70_10) != 1)
        {
            temp_v0 = func_80106790(func_80101080());
            ml_getdiff_vec3f(&temp_v0->actorData[4], &arg0->actorData[0], &arg0->actorData[4]);
            //Apply Scale
            ml_vec3f_apply_scale(&temp_v0->actorData[4], 0.14285715f);
            arg0->unk6C_0 = 7;
            func_80102FE8(temp_v0, 0);
        }
        break;
    case EVENT_2E_ACTOR_DIALOG_ENDED:
        func_80800728_chjadesnake(arg0, ((s16*)(&arg2))[0], ((s16*)(&arg2))[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_808009E4_chjadesnake, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

ActorData* chjadesnake_entrypoint_0(void) 
{
    return &D_808009F4_chjadesnake;
}
