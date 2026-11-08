#include "core2/1EDED00.h"
extern s32 D_80136ED8;
extern FreeList* D_80136EC0;

void func_80105410(void) {
	D_80136EC0 = freelist_new(0x48, 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105438.s")

void func_8010545C()
{
    if(D_80136EC0)
    {
       D_80136EC0 = freelist_defrag(D_80136EC0);
    }
}

void* func_80105494(Actor* arg0) {
    if (arg0->unk7C_0 == 0) {
        return NULL;
    }
    return freelist_at(D_80136EC0, arg0->unk7C_0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801054D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801056EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010573C.s")

void func_80105834(Actor* arg0)
{
    func_801054D4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010588C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801058C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105AC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105BAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801060E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801061D8.s")

s32 func_80106314()
{
    return D_80136ED8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801063C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801063EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010647C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801065A4.s")
