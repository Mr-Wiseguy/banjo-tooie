#include "ch/mole.h"

extern MoveData D_808001E0_chmole_maya[];

extern ActorData D_80800210_chmole_maya;
extern ActorData D_80800258_chmole_maya;

void func_80800000_chmole_maya(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808001E0_chmole_maya);
}

void func_80800024_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808001E0_chmole_maya);
}

ActorData* chmole_maya_entrypoint_0()
{
	return &D_80800210_chmole_maya;
}

void func_808000C0_chmole_maya(Actor* actor)
{
    if ((func_8010C500(actor) != 0) && (func_8008FA2C(-1, 0) != 0))
    {
        actor->unk7C_14 = 0;
        flag_setValueTrue(FLAG_506_FTT_CS_JAMJARS);
        _subaddiedialog_entrypoint_11(actor->unk0, 0xDBFU, 0xCU, actor->position, 0x6FU);
        _capod_entrypoint_13(actor->unk0, NULL, 0xBU, 0x20U);
    }
}

void func_80800144_chmole_maya(s32 arg0) 
{

}

void func_8080014C_chmole_maya(Actor* actor)
{
    if (flag_getValue(FLAG_506_FTT_CS_JAMJARS) != 0)
    {
        actor_mark_delete(actor);
    }
}

s32 func_80800180_chmole_maya(Actor* actor, s32 eventId, s32 arg2)
{
    switch (eventId)
    {
        case EVENT_2E_ACTOR_DIALOG_ENDED:
        {
            _capod_entrypoint_14();
            actor_mark_delete(actor);
            break;
        }
        default:
            return 0;
    }
    return 1;
}

ActorData* chmole_maya_entrypoint_1()
{
    return &D_80800258_chmole_maya;
}
