#include "ch/pawnbroker.h"

extern s32 D_80800ED0_chpawnbroker;
extern s32 D_80800F08_chpawnbroker;
extern s32 D_80800F40_chpawnbroker;

extern u32 D_80800F60_chpawnbroker;

extern ActorData D_80800FD0_chpawnbroker;

extern ActorData D_80801018_chpawnbroker;

extern ActorData D_80801060_chpawnbroker;

extern s32 D_808010A8_chpawnbroker;
extern f32 D_808010B8_chpawnbroker;

extern u32 D_808010C4_chpawnbroker;
extern u32 D_808010CC_chpawnbroker;
extern u32 D_808010D8_chpawnbroker;
extern u32 D_808010E4_chpawnbroker;
extern u32 D_808010F0_chpawnbroker;

extern s32 D_80801100_chpawnbroker;
extern s32 D_80801134_chpawnbroker;

extern u32 D_80801144_chpawnbroker;
extern u32 D_8080114C_chpawnbroker;
extern u32 D_80801154_chpawnbroker;

void func_80800664_chpawnbroker(Actor*);
void func_80800694_chpawnbroker(Actor*);
void func_808006FC_chpawnbroker(Actor*, s32);
s32 func_808007BC_chpawnbroker(Actor*, s16*, s32, s32, s32);
void func_8080083C_chpawnbroker(Actor*, s32, s32);
s32 func_80800A50_chpawnbroker(Actor*, s32, s32);
void func_80800AA8_chpawnbroker(Actor*);
void func_80800AE4_chpawnbroker(Actor*, s32, s32);
void func_80800B88_chpawnbroker(Actor*, s32, s32);
s32 func_80800C00_chpawnbroker(s32, s32);
void func_80800CB4_chpawnbroker(Actor*);
void func_80800E3C_chpawnbroker(Actor*);

//Pawno
ActorData* chpawnbroker_entrypoint_0(void)
{
    return &D_80800FD0_chpawnbroker;
}

//Glass Cabinet
ActorData* chpawnbroker_entrypoint_1(void) {
    return &D_80801018_chpawnbroker;
}

//Cash Register
ActorData* chpawnbroker_entrypoint_2(void) {
    return &D_80801060_chpawnbroker;
}

//Pawno Update
void func_80800024_chpawnbroker(Actor* arg0)
{
    u32* sp3C;
    f32 temp[3];
    sp3C = func_80100094(arg0, 1U);
    inventory_showValue(0x4E);
    _sudeflect_entrypoint_1(&D_808010B8_chpawnbroker, 60.0f, 0.0f, 60.0f, 2);
    _sudeflect_entrypoint_1(arg0->position, 250.0f, 0.0f, 100.0f, 0xA);
    _suexpression_entrypoint_10(sp3C, arg0->unk0, 0U);
    if ((func_801022E4(arg0) != 0x115) || (func_80102320(arg0, 0.55f, 0.99f) == 0))
    {
        _suexpression_entrypoint_18((s32)sp3C, 1);
    }
    switch (arg0->unk70_10)
    {
        //Exit Dialog
        case 2:
            func_80800694_chpawnbroker(arg0);
            if (func_808007BC_chpawnbroker(arg0, &D_808010A8_chpawnbroker, &D_80800ED0_chpawnbroker, 7, 0x6A5) != 0)
            {
                func_80800AE4_chpawnbroker(arg0, 3, 0);
                return;
            }
            return;
        //Second Item Available Idle
        case 6:
            func_80800694_chpawnbroker(arg0);
            if (func_808007BC_chpawnbroker(arg0, &D_808010A8_chpawnbroker, &D_80800F08_chpawnbroker, 7, 0x6A6) != 0)
            {
                func_80800AE4_chpawnbroker(arg0, 3, 0);
                return;
            }
            break;
        //Just Sold First Item
        case 5:
            func_80800694_chpawnbroker(arg0);
            if (func_808007BC_chpawnbroker(arg0, &D_808010A8_chpawnbroker, &D_80800F40_chpawnbroker, 4, 0) != 0)
            {
                func_80800AE4_chpawnbroker(arg0, 5, 1);
                return;
            }
            break;
        //Everything has been sold
        case 8:
            func_80800694_chpawnbroker(arg0);
            if (func_808007BC_chpawnbroker(arg0, &D_808010A8_chpawnbroker, &D_80800F40_chpawnbroker, 4, 0) != 0)
            {
                func_80800AE4_chpawnbroker(arg0, 5, 1);
                return;
            }
            break;
        //Purchasing First Item
        case 4:
            func_80800664_chpawnbroker(arg0);
            if (func_80101DDC(arg0) != 0)
            {
                func_80102424(arg0, 5);
                //Explode the glass cage
                event_sendToActorsOfType(0x353, 5, 0);
                flag_setValueTrue(FLAG_0B4_PROGRESS_JRL_PAWNOS_JIGGY_PURCHASED);
                return;
            }
            break;
        //Throwing the gold to Pawno
        case 3:
            func_80800694_chpawnbroker(arg0);
            func_80103DFC(arg0, &temp);
            if (_subaddieitem_entrypoint_3(arg0, &temp, func_80100094(arg0, 0U)) != 0)
            {
                //Start Sale Complete Dialog
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xFE8U, 0xEU, arg0->position, 0x53U);
                func_80102424(arg0, 1);
                return;
            }
            break;
        //Purchasing Second Item
        case 7:
            func_80800664_chpawnbroker(arg0);
            if (func_80101DDC(arg0) != 0)
            {
                func_80102424(arg0, 8);
                //Explode the glass cage
                event_sendToActorsOfType(0x353, 5, 0);
                flag_setValueTrue(FLAG_0B5_PROGRESS_JRL_PAWNOS_CHEATO_PAGE_PURCHASED);
                return;
            }
            break;
        default:
            func_80800694_chpawnbroker(arg0);
            break;
    }
}

//Pawno
void func_80800320_chpawnbroker(Actor* arg0)
{
    u32 sp44;
    Prop* temp_a1;
    s32 pad_sp3C;
    s32 pad_sp38;
    f32 sp34;
    s32 sp30;

    temp_a1 = _gccubesearch_entrypoint_0(0x154U, arg0);
    ml_vec3s_to_vec3f((f32*)arg0->actorData, temp_a1->position);
    if ((collectable_isCollected(0x27U, 1U) != 0) && (collectable_isCollected(0xAU, 4U) != 0))
    {
        sp44 = 8;
    }
    else if (collectable_isCollected(0x27U, 1U) != 0)
    {
        sp30 = 1;
        if ((_plsu_entrypoint_0(&sp34, arg0->actorData) != -1) && (ml_vec3f_distance(&sp34, (f32*)arg0->actorData) < 250.0f))
        {
            sp30 = 0;
        }
        if (flag_getValue(FLAG_0B5_PROGRESS_JRL_PAWNOS_CHEATO_PAGE_PURCHASED) != 0)
        {
            if (collectable_isSpawned(0xAU, 4U) == 0)
            {
                collectable_spawnItem(0xAU, 4U, (f32*)arg0->actorData, 3U, NULL);
            }
            sp44 = 8;
        }
        else if (sp30 != 0)
        {
            if (collectable_isSpawned(0xAU, 4U) == 0)
            {
                collectable_spawnItem(0xAU, 4U, (f32*)arg0->actorData, 3U, NULL);
            }
            sp44 = 6;
        }
        else
        {
            sp44 = 5;
        }
    }
    else if (flag_getValue(FLAG_0B4_PROGRESS_JRL_PAWNOS_JIGGY_PURCHASED) != 0)
    {
        sp44 = 5;
    }
    else
    {
        sp44 = 2;
    }
    if ((sp44 != 5) && (sp44 != 8))
    {
        func_80108B04(arg0, 0x353U);
    }
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0U), 0x4E4U, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0U), flag_getValue(FLAG_0B4_PROGRESS_JRL_PAWNOS_JIGGY_PURCHASED) != 0 ? 5 : 0x14);
    func_80101FDC(arg0, sp44);
    func_8010A3E8(arg0, 0.8f);
}

//Pawno
void func_80800514_chpawnbroker(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}

//Pawno Event Handler
s32 func_80800534_chpawnbroker(Actor* actor, s32 eventType, s32 arg2)
{
    s32 sp1C;
    s16* temp = &arg2;

    switch (eventType)
    {
        //Just Finished a dialog
        case EVENT_2E_ACTOR_DIALOG_ENDED:
            func_8080083C_chpawnbroker(actor, temp[0], temp[1]);
            break;
        case 0x3D:
            func_808006FC_chpawnbroker(actor, arg2);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800F60_chpawnbroker, actor->scale);
            break;
        case 0x57:
            return func_80800A50_chpawnbroker(actor, arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 0x10);
        case 0xB:
            func_80800AA8_chpawnbroker(actor);
            return 4;
        case EVENT_95_ACTOR_SPAWNED:
            sp1C = _suexpression_entrypoint_7(actor, 1U, 0x53U);
            _suexpression_entrypoint_12((void*)sp1C, 70.0f, 30.0f);
            _suexpression_entrypoint_17(sp1C, 0x3E8);
            func_80108B04(actor, 0x354U);
            break;
        default:
            return 0;
    }

    return 1;
}

void func_80800664_chpawnbroker(Actor* arg0) 
{
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808010C4_chpawnbroker, 0.52f);
}

void func_80800694_chpawnbroker(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808010D8_chpawnbroker, &D_808010F0_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808010CC_chpawnbroker, 0.0f);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808010E4_chpawnbroker, 0.0f);
}

void func_808006FC_chpawnbroker(Actor* arg0, s32 arg1)
{
    Actor* temp_v0;

    switch (arg1)
    {
        case 0x136:
            func_80108528(arg1, (f32*)arg0->actorData, 0xA, &arg0);
            return;
        case 0x353:
            func_80108528(arg1, (f32*)arg0->actorData, 0, &arg0);
            return;
        case 0x354:
            temp_v0 = func_801084B0(arg1, &arg0);
            func_80102FDC(temp_v0, arg0->scale);
            func_80108944(temp_v0, arg0);
            arg0->unk3C = temp_v0->unk0;
            return;
    }
}

s32 func_808007BC_chpawnbroker(Actor* arg0, s16* arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_v0;

    arg1[0] = arg4;
    temp_v0 = _subaddiedialog_entrypoint_8(arg0, arg0->position, arg1, arg2, arg3);
    if (temp_v0 == 0)
    {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9(arg0, temp_v0, arg2, arg3) != 3)
    {
        return 1;
    }
    return 0;
}

//Returned from a dialog
void func_8080083C_chpawnbroker(Actor* arg0, s32 dialogEnded, s32 choiceResult)
{
    s32 SecondSaleResponse;
    s32 FirstSaleResponse;
    s32 NextState;

    switch (dialogEnded)
    {
        case 0xFE4:
        case 0xFE6:
        case 0x105B:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xFEAU, 0x4EU, arg0->position, 0x53U);
            return;
        case 0xFEA:
            if (flag_getValue(FLAG_0B4_PROGRESS_JRL_PAWNOS_JIGGY_PURCHASED) != 0)
            {
                SecondSaleResponse = func_80800C00_chpawnbroker(5, choiceResult);
                _subaddiedialog_entrypoint_11(arg0->unk0, (u32)SecondSaleResponse, 0xEU, arg0->position, 0x53U);
                //If we are going through with the sale
                if (SecondSaleResponse == 0x1040)
                {
                    arg0->unk64_20 = 0;
                }
            }
            else
            {
                FirstSaleResponse = func_80800C00_chpawnbroker(20, choiceResult);
                _subaddiedialog_entrypoint_11(arg0->unk0, FirstSaleResponse, 0xEU, arg0->position, 0x53U);
                //If we are going through with the sale
                if (FirstSaleResponse == 0x1040)
                {
                    arg0->unk64_20 = 1;
                }
            }
            return;
        //Let's see some gold
        case 0x1040:
            _subaddieitem_entrypoint_2(func_80100094(arg0, 0U));
            func_80102424(arg0, 3);
            return;
        //Pleasure doing business
        case 0xFE8:
            if (arg0->unk64_20 != 0)
            {
                //Sell First Item
                NextState = 4;
            }
            else
            {
                //Sell Second Item
                NextState = 7;
            }
            func_80102424(arg0, NextState);
            func_80102424(func_80106790(arg0->unk3C), 2);
            func_80800B88_chpawnbroker(arg0, 3, 0x30);
            return;
    }
    if (flag_getValue(FLAG_0B5_PROGRESS_JRL_PAWNOS_CHEATO_PAGE_PURCHASED) != 0)
    {
        //Already sold everything state
        NextState = 8;
    }
    else
    {
        if (flag_getValue(FLAG_0B4_PROGRESS_JRL_PAWNOS_JIGGY_PURCHASED) != 0)
        {
            //If we have collected the jiggy and have spawned the second item
            if ((collectable_isCollected(0x27U, 1U) != 0) && (collectable_isSpawned(0xAU, 4U) != 0))
            {
                //Go Collect item 2
                NextState = 6;
            }
            else
            {
                //Go Collect item 1
                NextState = 5;
            }
        }
        else
        {
            //End Dialog
            NextState = 2;
        }
    }
    func_80800AA8_chpawnbroker(arg0);
    func_80102424(arg0, NextState);
}

s32 func_80800A50_chpawnbroker(Actor* arg0, s32 arg1, s32 arg2)
{
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0)
    {
        if (arg0->actorData[4] != 2)
        {
            func_80800AE4_chpawnbroker(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80800AA8_chpawnbroker(Actor* arg0)
{
    if (arg0->actorData[4] != 0)
    {
        _capod_entrypoint_3(0U);
        arg0->actorData[4] = 0;
    }
}

void func_80800AE4_chpawnbroker(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg0->actorData[4])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x11U, 0);
    case 1:
        _capod_entrypoint_8(1);
        arg0->actorData[4] = 2;
        _gcdialogcamera_entrypoint_3(&D_80800F60_chpawnbroker, arg0->scale);
        _gcdialogcamera_entrypoint_4(arg0->position);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(arg1, arg2);
        return;
    }
}

void func_80800B88_chpawnbroker(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg0->actorData[4])
    {
    case 0:
        _capod_entrypoint_2(arg0->unk0, 0x11U, arg2);
    case 2:
        arg0->actorData[4] = 1;
    case 1:
        _capod_entrypoint_6(arg0->unk0, arg1, arg2);
        return;
    }
}

//Get the Dialog Response for trying to pay for an item
s32 func_80800C00_chpawnbroker(s32 NumDoubloons, s32 SaleConfirmation)
{
    if (SaleConfirmation > 0)
    {
        //Check if we have enough doubloons
        if (inventory_getValue(0x4E) >= NumDoubloons)
        {
            //Check the current player's transformation if valid
            if (character_includedInTransformMask(character_getActiveIndex(), ALLOW_BANJO | ALLOW_BK) != 0)
            {
                //Sure
                return 0x1040;
            }
            //Not Correct Transformation
            return 0x1225;
        }
        //Cannot Afford it
        return 0xFE9;
    }
    //Player Declined to sell
    return 0xFE7;
}

//Glass Cabinet Update
void func_80800C70_chpawnbroker(Actor* arg0)
{
    switch (arg0->unk70_10)
    {
        case 1:
            func_80800CB4_chpawnbroker(arg0);
        case 2:
            return;
    }
}

//Glass Cabinet
void func_80800CB4_chpawnbroker(Actor* arg0)
{
    Actor* ItemForSale;

    arg0->position[1] -= 40.0f;
    //Have we collected the jiggy
    if (collectable_isCollected(JRL_PAWNOS, 1U) == 0)
    {
        ItemForSale = func_80106790(func_800D0634(JRL_PAWNOS, 1U));
    }
    //Have we collected the Cheato page
    else if (collectable_isCollected(0xAU, 4U) == 0)
    {
        ItemForSale = _subaddiefind_entrypoint_0(arg0->position, 0x136, -1, 0);
    }

    arg0->unk3C = ItemForSale->unk0;
    //Disable Collision
    actor_disableCollision(ItemForSale);
    func_80102424(arg0, 2);
}

//Glass Cabinet Event Handler
s32 func_80800D5C_chpawnbroker(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 5)
    {
        func_800BBCB8(arg0->position, arg0->position, arg0->scale, 0x28, &D_80801100_chpawnbroker);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801134_chpawnbroker);
        actor_enableCollision(func_80106790(arg0->unk3C));
        actor_mark_delete(arg0);
        return 1;
    }
    return 0;
}

//Cash Register Update
void func_80800DE8_chpawnbroker(Actor* arg0)
{
    if (arg0->unk70_10 == 2)
    {
        func_80800E3C_chpawnbroker(arg0);
        if (func_80101DDC(arg0) != 0)
        {
            func_80102424(arg0, 1);
        }
    }
}

//Cash Register
void func_80800E34_chpawnbroker(s32 arg0) 
{
}

//Cash Register
void func_80800E3C_chpawnbroker(Actor* arg0)
{
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80801144_chpawnbroker, &D_80801154_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_8080114C_chpawnbroker, 0.5f);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_8080114C_chpawnbroker, 0.87f);
}
