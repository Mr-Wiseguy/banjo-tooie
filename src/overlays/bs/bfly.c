#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800000_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808000AC_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800128_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800188_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800248_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800320_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808003E0_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_0.s")

void func_8080042C_bsbfly(s32 arg0)
{
    func_8009E6EC();
    func_80801BB4_bsbfly(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800454_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080050C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800624_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808009D0_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800A24_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800C38_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800D50_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800D80_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800F10_bsbfly.s")

void func_80801138_bsbfly(s32 arg0)
{
    func_80800A24_bsbfly(arg0,0);
    func_80800188_bsbfly(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801178_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801208_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801334_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080145C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808014E8_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808015C4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808016B4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080183C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080188C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808018D0_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808018F4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080193C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801980_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808019A4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808019EC_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801A1C_bsbfly.s")

void func_80801A44_bsbfly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801A80_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801AEC_bsbfly.s")

void func_80801B80_bsbfly()
{
    func_80800188_bsbfly();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801BB4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801C58_bsbfly.s")

void func_80801C9C_bsbfly(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void func_80801CBC_bsbfly(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800188_bsbfly(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/bsbfly_entrypoint_9.s")
