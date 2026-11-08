#include "ch/grunty/lairexttowerwindow.h"

void func_80800070_chgruntylairexttowerwindow(Actor* arg0);
extern s32 D_808000D0_chgruntylairexttowerwindow;
extern s32 D_8080013C_chgruntylairexttowerwindow;
extern ActorData D_80800150_chgruntylairexttowerwindow;

void func_80800000_chgruntylairexttowerwindow(s32 arg0) 
{
}

s32 func_80800008_chgruntylairexttowerwindow(Actor* arg0, s32 arg1, s32 arg2)
{
    switch (arg1)
    {
    case 0x40:
        _chexploder_entrypoint_3(arg0, arg0->position, 0xCU);
        break;
    case 0x90:
        func_80800070_chgruntylairexttowerwindow(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800070_chgruntylairexttowerwindow(Actor* arg0)
{
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_808000D0_chgruntylairexttowerwindow);
    func_800C4AF0(arg0->position, &D_8080013C_chgruntylairexttowerwindow);
}


ActorData* chgruntylairexttowerwindow_entrypoint_0()
{
    return &D_80800150_chgruntylairexttowerwindow;
}
