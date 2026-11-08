#include "ch/intro/ticker.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800000_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808000B0_chintroticker.s")

void func_80800188_chintroticker(Actor* actor, s32 arg1)
{
    if ((arg1 == MAP_A1_CS_INTRO) || (arg1 == MAP_18B_CS_STARTUP_INTRO) || (arg1 == MAP_18E_MEANWHILE) || (arg1 == MAP_194_CS_ABOUT_TO_BOB) || (arg1 == MAP_196_CS_GRUNTY_HEAD_PLAYING))
    {
        switch (actor->unk79_4)
        {

        case 1:
            if (controller_getError())
            {
                _chattract_entrypoint_1(3);
                return;
            }
            break;
        case 2:
            flag_setValueTrue(FLAG_578_PROGRESS_BOTTLES_ENERGY_RESTORED);
            return;
        case 3:
            flag_setValueFalse(FLAG_360_PROGRESS_JINGALING_LIFE_SAPPED);
            flag_setValueFalse(FLAG_03B_PROGRESS_FINISHED_TOWER_OF_TRAGEDY);
            return;
        case 4:
            flag_setValueTrue(FLAG_360_PROGRESS_JINGALING_LIFE_SAPPED);
            flag_setValueFalse(FLAG_03B_PROGRESS_FINISHED_TOWER_OF_TRAGEDY);
            flag_setValueFalse(FLAG_578_PROGRESS_BOTTLES_ENERGY_RESTORED);
            break;
        case 0:
        case 5:
        default:
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800254_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808002DC_chintroticker.s")

void func_808003BC_chintroticker(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808003C4_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808004A8_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800530_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808005AC_chintroticker.s")

extern ActorData D_80800934_chintroticker;
ActorData* chintroticker_entrypoint_0()
{
    return &D_80800934_chintroticker;
}
