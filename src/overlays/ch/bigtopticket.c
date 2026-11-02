#include "ch/bigtopticket.h"

void func_8080000C_chbigtopticket(s32);
void func_80800014_chbigtopticket(Actor*);
void func_80800058_chbigtopticket(Actor*, void*);
s32 func_8080008C_chbigtopticket(Actor*, s32, s32);

ActorData D_80800120_chbigtopticket =
{
	/*0x0*/ 0x0329,
	/*0x2*/ 0x03C6,
	/*0x4*/ 0x07BF,
	/*0x6*/ 0x0001,
	/*0x8*/ 0x00000000,
	/*0xC*/ func_80800014_chbigtopticket,
	/*0x10*/ func_80105834,
	/*0x14*/ func_80800058_chbigtopticket,
	/*0x18*/ 0x0000,
	/*0x1A*/ 0x0000,
	/*0x1C*/ 1.0f,
	/*0x20*/ 0x0000,
	/*0x22*/ 0x0000,
	/*0x24*/ 0x4004,
	/*0x26*/ 0x0004,
	/*0x28*/ 0x00000000,
	/*0x2C*/ func_80108ED0,
	/*0x30*/ 0x0000,
	/*0x32*/ 0x0000,
	/*0x34*/ func_8080000C_chbigtopticket,
	/*0x38*/ func_80107C2C,
	/*0x3C*/ 0x8000,
	/*0x3E*/ 0x1814,
	/*0x40*/ func_8080008C_chbigtopticket,
	/*0x44*/ 0x0000,
	/*0x46*/ 0x0000
};
ActorData* chbigtopticket_entrypoint_0()
{
    return &D_80800120_chbigtopticket;
}
void func_8080000C_chbigtopticket(s32 arg0) 
{
}
void func_80800014_chbigtopticket(Actor* arg0) {
    arg0->rotation[1] -= time_getDelta() * 175.0f;
    func_80103110(arg0, 0U);
}

void func_80800058_chbigtopticket(Actor* arg0, void* arg1) {
    func_80101870(arg0, arg1);
    func_80103110(arg0, arg0->unk7C_12);
}

s32 func_8080008C_chbigtopticket(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1) 
    {
        case EVENT_3E_ACTOR_TOUCHED:
            _sudialog_entrypoint_0(0x19F, 4);
            collectable_collectItem(arg0->unk54s, 8);
            inventory_incrementValue(0x4D);
            func_800FC6B0(0x73);
            _fxsparkle_entrypoint_1(arg0->position, 0x11U);
            actor_disableCollision(arg0);
            actor_mark_delete(arg0);
            break;
        case 0x13:
            arg0->unk54s = arg2;
            break;
        default:
            return 0;
    }
    return 1;
}
