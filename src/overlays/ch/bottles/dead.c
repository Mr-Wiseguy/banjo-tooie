#include "ch/bottles/dead.h"

extern ActorData D_808000C0_chbottlesdead;

void func_80800000_chbottlesdead(Actor* arg0) 
{
    func_80102FDC(arg0, arg0->scale * 0.15f);
}
void func_80800034_chbottlesdead()
{
    func_8010C964();
}

void func_80800054_chbottlesdead(Actor* arg0, void* arg1) 
{
    func_800DF744(3, 0);
    func_80101870(arg0, arg1);
}

ActorData* chbottlesdead_entrypoint_0()
{
    return &D_808000C0_chbottlesdead;
}
