#include "ch/bubbleelevator.h"

#define ELEVATOR_DATA(arg0) ((BubbleElevatorActorData*)(arg0->actorData))

extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern BubbleWarpData D_80800C20_chbubbleelevator[2];
extern u32 D_80800C50_chbubbleelevator[2];
extern u32 D_80800C58_chbubbleelevator;

//Setup
void func_80800000_chbubbleelevator(Actor* arg0)
{
    s32 sp24;
    Prop* temp_v0;
    s32 var_a1;
    MapId temp_v0_2;

    ELEVATOR_DATA(arg0)->unkC = arg0->position[1];
    temp_v0 = _gccubesearch_entrypoint_0(0x299, arg0);
    if (temp_v0 != 0)
    {
        _gspropctrl_entrypoint_11(temp_v0, ELEVATOR_DATA(arg0)->unk0);
    }
    temp_v0_2 = func_800EA05C();
    if (temp_v0_2 != MAP_136_CCL_CLOUD_CUCKOOLAND) //If Map is not CCL
    {
        if (temp_v0_2 == MAP_15A_IOH_WASTELAND) //If Map is Wasteland
        {
            arg0->unk79_4 = 0;
        }
    }
    else //If Map is CCL
    {
        arg0->unk79_4 = 1;
    }
    //If world 7 is unlocked
    if (_sujiggy_entrypoint_20(7) != 0)
    {
        func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
    }
    //Check if the World Open Cheat is active
    var_a1 = func_800D3E40(0xB) != 0;
    if (var_a1 != 0)
    {
        var_a1 = _glcutDll_entrypoint_19(0x81) == 0;
    }
    sp24 = var_a1;
    //Check the world 7 unlock flag if false
    if ((func_800DA298(FLAG_399_PROGRESS_OPENED_WORLD_CCL) == 0) && (var_a1 == 0))
    {
        func_808004DC_chbubbleelevator(arg0, 8);
    }
    //0x6CA Controls whether the elevator is used when entering a level with an elevator
    else if (func_800DA298(FLAG2_6CA_USING_BUBBLEELEVATOR) != 0)
    {
        func_808004DC_chbubbleelevator(arg0, 1);
    }
    else
    {
        func_808004DC_chbubbleelevator(arg0, 4);
    }
    arg0->unk50 = 0.0f;
    arg0->unk54 = 0.0f;
}

//Functionality Update
void func_80800124_chbubbleelevator(Actor* arg0) 
{
    s32 sp44;
    f32 sp38[3];

    func_808008A8_chbubbleelevator(arg0);
    switch (arg0->unk70_10)
    {
    case 1:
        if (func_800D90A4(&arg0->unk58) != 0)
        {
            func_808004DC_chbubbleelevator(arg0, 2);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk10, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk14));
        func_800F8294(func_800F54E4(), arg0->position);
        return;
    case 2:
        func_800F8294(func_800F54E4(), arg0->position);
        return;
    case 3:
        if (ELEVATOR_DATA(arg0)->unk1C < 1.0f)
        {
            _sudeflect_entrypoint_0(arg0->position, 75.0f, 140.0f, 0x1E);
        }
        if (func_800D90A4(&ELEVATOR_DATA(arg0)->unk1C) != 0)
        {
            func_808004DC_chbubbleelevator(arg0, 4);
            return;
        }
    default:
        return;
    case 4:
        sp44 = 0;
        //Are we touching the bubble
        if (func_8010C500(arg0) != 0)
        {
            //Check if we're banjo and kazooie
            if (func_800F64A4(func_800F54E4(), 1) != 0)
            {
                func_808004DC_chbubbleelevator(arg0, 5);
            }
            else
            {
                //Have we been told about the bubble only being accessible as banjo and kazooie
                if (func_800DA298(FLAG2_6EA_BUBBLE_AS_BK_WARNING) == 0)
                {
                    //Set the listened to flag and talk to player
                    func_800DA544(FLAG2_6EA_BUBBLE_AS_BK_WARNING);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1229, 3, arg0->position, 0x6F);
                }
                sp44 = 1;
            }
        }
        else
        {
            sp44 = 1;
        }
        //Repel the player if they're not banjo and kazooie
        if (sp44 != 0)
        {
            _sudeflect_entrypoint_0(arg0->position, 75.0f, 140.0f, 0x1E);
            return;
        }
        break;
    case 5:
        //Used when doing the little popup animation when getting into the bubble
        //Get Player Coordinates
        func_800F5A00(func_800F54E4(), sp38);
        //If the player coordinates is within 50.0f of the bubble start moving bubble
        if (func_800EFFB4(arg0->position, 50.0f, sp38) != 0)
        {
            func_808004DC_chbubbleelevator(arg0, 6);
            return;
        }
        break;
    case 6:
        //Wait for a few seconds before initiating warp
        if (func_800D91EC(&arg0->unk58, 4.75f) != 0)
        {
            func_808004DC_chbubbleelevator(arg0, 7);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk10, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk14));
        //Set Player Position to the bubble's position
        func_800F8294(func_800F54E4(), arg0->position);
        return;
    case 7:
        func_800D91EC(&arg0->unk58, 5.0f);
        func_808004DC_chbubbleelevator(arg0, 1);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk10, D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk14));
        //Set Player Position to the bubble's position
        func_800F8294(func_800F54E4(), arg0->position);
        return;
    case 9:
        if (func_800D90A4(&ELEVATOR_DATA(arg0)->unk10) != 0)
        {
            //Set World Unlocked True
            func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
            func_808004DC_chbubbleelevator(arg0, 4);
        }
        arg0->scale = func_800F12D4(ELEVATOR_DATA(arg0)->unk10, ELEVATOR_DATA(arg0)->unk14, 0.0f, 0.05f, 1.0f);
        break;
    }
}

void func_808004DC_chbubbleelevator(Actor* arg0, s32 arg1)
{
  int new_var2;
  Actor *new_var;
  f32 sp2C;
  switch (arg1)
  {
    case 1:
        arg0->unk58 = 5.0f;
        func_808008A8_chbubbleelevator(arg0);
        func_800F7B9C(func_800F54E4(), 0x7C);
        func_800F8294(func_800F54E4(), arg0->position);
        func_800EFA4C(&sp2C, 0.0f, func_800F1DF4(arg0->position, ELEVATOR_DATA(arg0)->unk0), 0.0f);
        func_800F832C(func_800F54E4(), &sp2C);
        func_800F80E4(func_800F54E4(), 0);
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk0, 0x2001);
        arg0->unk6C_0 = func_80015184();
        func_80015178(3);
        new_var2 = 0;
        ELEVATOR_DATA(arg0)->unk1C = new_var2;
        _subaddieDll_entrypoint_4(arg0, 1U);
        func_800FC6B0(0x4A);
        break;

    case 3:
        func_800C3F48(0x665F44B1);
        //Set Bubble Flag False
        func_800DA524(FLAG2_6CA_USING_BUBBLEELEVATOR);
        arg0->unk58 = 0.0f;
        func_808008A8_chbubbleelevator(arg0);
        func_800F78EC(func_800F54E4(), ELEVATOR_DATA(arg0)->unk0, 840.0f, -1500.0f);
        ELEVATOR_DATA(arg0)->unk1C = 2.0f;
        arg0->unk50 = 3.0f;
        _subaddieaudioloop_entrypoint_2(arg0);
        func_800FC74C(0x4A);
        func_800F80E4(func_800F54E4(), 1);
        break;

    case 4:
        ELEVATOR_DATA(arg0)->unk1C = 0.0f;
        arg0->unk58 = 0.0f;
        _subaddieDll_entrypoint_4(arg0, 0U);
        if (arg0->unk6C_0 != 0)
        {
            func_80015178(arg0->unk6C_0);
        }
        break;

    case 5:
        //Entering Bubble
        func_800C3F48(0x7FF194D5);
        //Move the character towards the bubble
        func_800F78EC(func_800F54E4(), arg0->position, 840.0f, -1500.0f);
        new_var = arg0;
        _subaddieDll_entrypoint_4(new_var, 1U);
        break;

    case 6:
        //Moving Bubble
        func_800C3F48(0x665F44B1);
        func_800FC6B0(0x4A);
        //Set Bubbled Flag True
        func_800DA544(FLAG2_6CA_USING_BUBBLEELEVATOR);
        arg0->unk58 = 0.0f;
        func_808008A8_chbubbleelevator(arg0);
        //Set Bubbled Animation State
        func_800F7B9C(func_800F54E4(), 0x7C);
        func_800F80E4(func_800F54E4(), 0);
        //Move Player to bubble position
        func_800F8294(func_800F54E4(), arg0->position);
        //Set Cutscene camera
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk1, 0x4001);
        arg0->unk6C_0 = func_80015184();
        func_80015178(3);
        arg0->unk50 = 3.0f;
        break;

    case 7:
        //Reached end of bubble route
        //Warp the player
        _gcgoto_entrypoint_1(D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].mapId, D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].entranceId);
        _subaddieaudioloop_entrypoint_2(arg0);
        func_800FC74C(0x4A);
        break;

    case 8:
        //The world is not unlocked
        func_80103110(arg0, 0);
        break;

    case 9:
        func_80103110(arg0, 1);
        _subaddieDll_entrypoint_4(arg0, 1U);
        arg0->scale = 0.05f;
        arg0->unk50 = 3.0f;
        ELEVATOR_DATA(arg0)->unk10 = ELEVATOR_DATA(arg0)->unk14;
        func_800C3F48(0x7FFF468B);
        break;

  }
  //Delete The Bubble
  func_80101FDC(arg0, (u32) arg1);
}

//Update bubble vertical position
void func_808008A8_chbubbleelevator(Actor* arg0)
{
    arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 5.0f, 0.0f, D_80800C20_chbubbleelevator[arg0->unk79_4].unkC) + ELEVATOR_DATA(arg0)->unkC;
}

s32 func_8080090C_chbubbleelevator(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 7:
        ELEVATOR_DATA(arg0)->unk14 = arg2;
        func_808004DC_chbubbleelevator(arg0, 9);
        return 1;
    case 11:
        //Triggered on bubble reaching the destination
        if (arg2 == D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk0)
        {
            //Exit Bubble
            func_808004DC_chbubbleelevator(arg0, 3);
        }
        //If we're in CCL and Canary Mary is not in CCL
        if ((func_800EA05C() == MAP_136_CCL_CLOUD_CUCKOOLAND) && (arg2 == D_80800C20_chbubbleelevator[(u32)arg0->unk79_4].unk0 && (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0)))
        {
            return func_80101180(0x383, 0xB, arg2);
        }
        return 2;
    default:
        return 0;
    }
}

//Draw Update
void func_80800A10_chbubbleelevator(Actor* arg0, s32 arg1) {
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp38[2];

    if (arg0->unk70_10 != 8)
    {
        func_800D90A4(&arg0->unk50);
        arg0->unk54 += (func_800D8FF8() * func_800F10B4(arg0->unk50, 0.0f, 3.0f, 1.0f, 3.0f));
        if (arg0->unk54 > 1.0f)
        {
            arg0->unk54 = (arg0->unk54 - 1.0f);
        }
        sp5C = arg0->unk54 * 360.0f;
        sp58 = func_800F10B4(arg0->unk50, 0.0f, 3.0f, 0.075f, 0.200000003f);
        func_800EE7F8(sp4C, arg0->position);
        sp4C[1] += 75.0f;
        func_800E3980(sp40);
        func_800F18FC(sp4C, sp40, sp38);
        func_800EEBF0(sp40, sp38, 75.0f);
        func_800EF04C(sp4C, sp40);
        sp38[0] = (func_80013970(sp5C) * sp58) + 1.0f;
        sp38[1] = (func_800138D0(sp5C) * sp58) + 1.0f;
        arg0->unk7C_12 = _chbubble_entrypoint_0(arg1, sp4C, sp38, arg0->scale, 4000.0f);
    }
}

u32* chbubbleelevator_entrypoint_0(void)
{
    return &D_80800C58_chbubbleelevator;
}
