#include "core2/1E691A0.h"

void func_8008F8B0()
{
    func_800F497C(character_getActiveIndex());
}

void func_8008F8D8(s32 arg0)
{
    func_800F49A8(character_getActiveIndex(),arg0);
}

void func_8008F904(void* arg0,s32 arg1)
{
    func_800F49D4(character_getActiveIndex(),arg0,arg1);
}

void func_8008F938(s32 arg0)
{
    func_800F4A00(character_getActiveIndex(),arg0);
}

void func_8008F964(f32* arg0)
{
    func_800F4A2C(character_getActiveIndex(),arg0);
}

void func_8008F990(s32 arg0,f32 arg1)
{
    func_800F4A58(character_getActiveIndex(),arg0,arg1);
}

void func_8008F9C4(s32 arg0,s32 arg1)
{
    func_800F4A8C(character_getActiveIndex(),arg0,arg1);
}

void func_8008F9F8(f32* arg0,f32 arg1)
{
    func_800F4AC0(character_getActiveIndex(),arg0,arg1);
}

s32 func_8008FA2C(s32 arg0,s32 arg1)
{
    return func_800F4B8C(character_getActiveIndex(),arg0,arg1);
}

s32 func_8008FA60(s32 arg0,s32 arg1)
{
    return func_800F4BB8(character_getActiveIndex(),arg0,arg1);
}

void func_8008FA94(s32 arg0,s32 arg1)
{
    func_800F4D18(character_getActiveIndex(),arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_8008FAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_8008FB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_8008FB58.s")

void activePlayer_affectCurrentHealth(s32 arg0)
{
    character_affectCurrentHealth(character_getActiveIndex(),arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_8008FBC0.s")

void func_8008FBE0(u32 arg0)
{
    func_800A1624(arg0);
}

s32 activePlayer_getCurrentHealth()
{
    return character_getCurrentHealth(character_getActiveIndex());
}

s32 activePlayer_getMaxHealth()
{
    return character_getMaxHealth(character_getActiveIndex());
}

void activePlayer_incrementCurrentHealth()
{
    activePlayer_affectCurrentHealth(0x1);
}

void func_8008FC70(s32 arg0)
{
    func_800F81A8(character_getActiveIndex(),arg0);
}

void func_8008FC9C(s32 arg0)
{
    func_800F521C(character_getActiveIndex(),arg0);
}

void func_8008FCC8(s32 arg0)
{
    func_800F52B8(character_getActiveIndex(),arg0);
}

void func_8008FCF4(s32 arg0)
{
    func_800F52E4(character_getActiveIndex(),arg0);
}

void func_8008FD20()
{
    func_800F5378(character_getActiveIndex());
}

//Get Transformation state of active character
TransformationId activePlayer_getTransformation()
{
    return character_getTransform(character_getActiveIndex());
}

//Return the bit mask for the Allow transformation value for the active character
s32 activePlayer_getTransformationBit()
{
    return character_getTransformBit(character_getActiveIndex());
}

void func_8008FD98(s32 arg0)
{
    func_800F549C(character_getActiveIndex(),arg0);
}

s32 func_8008FDC4()
{
    return func_800F55FC(character_getActiveIndex());
}

Unk80132ED0* func_8008FDEC()
{
    return func_800F56D8(character_getActiveIndex());
}

s32 func_8008FE14()
{
    return func_800F5704(character_getActiveIndex());
}

void func_8008FE3C(s32 arg0)
{
    func_800F57F0(character_getActiveIndex(),arg0);
}

void activePlayer_getCoords(f32* arg0)
{
    character_getCoords(character_getActiveIndex(),arg0);
}

void func_8008FE94(s32 arg0,f32* arg1)
{
    func_800F5A2C(character_getActiveIndex(),arg0,arg1);
}

void func_8008FEC8()
{
    func_800F58A0(character_getActiveIndex());
}

f32 func_8008FEF0()
{
    return func_800F5AE0(character_getActiveIndex());
}

void func_8008FF18()
{
    func_800F5B0C(character_getActiveIndex());
}

void func_8008FF40(f32* arg0)
{
    func_800F5B38(character_getActiveIndex(),arg0);
}

void func_8008FF6C()
{
    func_800F5C94(character_getActiveIndex());
}

void func_8008FF94()
{
    func_800F5D18(character_getActiveIndex());
}

void func_8008FFBC(f32* arg0)
{
    func_800F5D70(character_getActiveIndex(),arg0);
}

s32 func_8008FFE8()
{
    return func_800F5EF8(character_getActiveIndex());
}

f32 func_80090010()
{
    return func_800F5F24(character_getActiveIndex());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_80090038.s")

s32 func_80090080()
{
    return func_800F5FA8(character_getActiveIndex());
}

void func_800900A8()
{
    func_800F6018(character_getActiveIndex());
}

void func_800900D0(s32 arg0)
{
    func_800F63B4(character_getActiveIndex(),arg0);
}

void func_800900FC(s32 arg0)
{
    func_800F640C(character_getActiveIndex(),arg0);
}

s32 func_80090128()
{
    func_800F6438(character_getActiveIndex());
}

void func_80090150()
{
    func_800F6478(character_getActiveIndex());
}

s32 activePlayer_includedInTransformMask(s32 arg0)
{
    return character_includedInTransformMask(character_getActiveIndex(),arg0);
}

void func_800901A4()
{
    func_800F6634(character_getActiveIndex());
}

s32 func_800901CC(f32* arg0,f32 arg1)
{
    return func_800F66BC(character_getActiveIndex(),arg0,arg1);
}

s32 func_80090200()
{
	return func_800F5310();
}

void func_80090220()
{
    func_800F6C1C(character_getActiveIndex());
}

s32 func_80090248()
{
    character_isStable(character_getActiveIndex());
}

s32 func_80090270()
{
    func_800F6CC8(character_getActiveIndex());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_80090298.s")

void func_800902BC()
{
    func_800F70EC(character_getActiveIndex());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_800902E4.s")

void func_8009032C(s32 arg0)
{
    func_800F739C(character_getActiveIndex(),arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_80090358.s")

void func_8009039C(s32 arg0,s32 arg1)
{
    func_800F7700(character_getActiveIndex(),arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_800903D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_800903F8.s")

void func_80090434(s32 arg0)
{
    func_800F796C(character_getActiveIndex(),arg0);
}

void func_80090460(s32 arg0,s32 arg1)
{
    func_800F79DC(character_getActiveIndex(),arg0,arg1);
}

void func_80090494(s32 arg0,s32 arg1)
{
    func_800F7A2C(character_getActiveIndex(),arg0,arg1);
}

void func_800904C8(s32 arg0)
{
    func_800F7B9C(character_getActiveIndex(),arg0);
}

void func_800904F4(s32 arg0, Unk80132ED0* arg1)
{
    func_800F7BC8(character_getActiveIndex(),arg0,arg1);
}

void func_80090528(s32 arg0,f32 arg1)
{
    func_800F7C0C(character_getActiveIndex(),arg0,arg1);
}

void func_8009055C(s32 arg0,s32 arg1)
{
    func_800F7C58(character_getActiveIndex(),arg0,arg1);
}

void func_80090590(s32 arg0,f32* arg1)
{
    func_800F7CF4(character_getActiveIndex(),arg0,arg1);
}

void func_800905C4(s32 arg0,s32 arg1)
{
    func_800F7DE8(character_getActiveIndex(),arg0,arg1);
}

void func_800905F8(TransformationId arg0)
{
    func_800F7E64(character_getActiveIndex(),arg0);
}

void func_80090624(s32 arg0,s32 arg1)
{
    func_800F7ECC(character_getActiveIndex(),arg0,arg1);
}

void func_80090658(s32 arg0)
{
    func_800F7F98(character_getActiveIndex(),arg0);
}

void func_80090684(s32 arg0)
{
    func_800F8200(character_getActiveIndex(),arg0);
}

void func_800906B0(s32 arg0)
{
    func_800F8294(character_getActiveIndex(),arg0);
}

void func_800906DC(f32* arg0)
{
    func_800F832C(character_getActiveIndex(),arg0);
}

void func_80090708(s32 arg0)
{
    func_800F82D4(character_getActiveIndex(),arg0);
}

void func_80090734(s32 arg0,f32* arg1)
{
    func_800F8300(character_getActiveIndex(),arg0,arg1);
}

void func_80090768(void* arg0)
{
    func_800F83B8(character_getActiveIndex(),arg0);
}

void func_80090794(f32* arg0)
{
    func_800F5D9C(character_getActiveIndex(),arg0);
}

void func_800907C0(f32* arg0)
{
    func_800F8418(character_getActiveIndex(),arg0);
}

void func_800907EC(TransformationId arg0)
{
    func_800F8730(character_getActiveIndex(),arg0);
}

s32 func_80090818()
{
    return func_800F87A4(character_getActiveIndex());
}

void func_80090840(s32 arg0)
{
    func_800F8804(character_getActiveIndex(),arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E691A0/func_8009086C.s")
