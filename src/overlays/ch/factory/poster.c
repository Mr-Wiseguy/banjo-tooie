#include "ch/factory/poster.h"

extern ActorData D_80800110_chfactoryposter;
extern s32 D_80800158_chfactoryposter;

ActorData* chfactoryposter_entrypoint_0()
{
    return &D_80800110_chfactoryposter;
}

void func_8080000C_chfactoryposter(Actor* arg0)
{
    if (flag_getValue(FLAG_03D_UNK) != 0)
    {
        func_800BF744(2, 2);
        actor_mark_delete(arg0);
        return;
    }
    func_800BF744(2, 1);
}

void func_8080005C_chfactoryposter(Actor* arg0)
{
    f32 sp24[3];

    if (arg0->unk70_10 == 1 && func_800F6438(character_getActiveIndex()) != 0)
    {
        character_getCoords(character_getActiveIndex(), sp24);
        if (sp24[0] < arg0->position[0]) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800158_chfactoryposter);
            func_800BF744(2, 2);
            flag_setValueTrue(FLAG_03D_UNK);
            actor_mark_delete(arg0);
        }
    }
}