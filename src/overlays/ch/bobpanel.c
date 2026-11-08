#include "ch/bobpanel.h"

void func_80800000_chbobpanel(Actor* arg0)
{
    _sudeflect_entrypoint_1(arg0->position, func_80103EF4(arg0), 0.0f, func_80103EAC(arg0), 0x1E);
}

s32 func_8080004C_chbobpanel(Actor* arg0, s32 arg1, s32 arg2)
{
    if (arg1 == 0x1F)
    {
        func_801015D0(arg0);
        func_800DF744(2, 3);
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        return 1;
    }
    return 0;
}
extern ActorData D_808000C0_chbobpanel;
ActorData* chbobpanel_entrypoint_0()
{
    return &D_808000C0_chbobpanel;
}
