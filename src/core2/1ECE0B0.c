#include "core2/1ECE0B0.h"

extern PlayerState* D_80135490[];
extern u8 D_801354DA;

extern u32 D_801354DC;
extern u8 D_801354F8;
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;

extern f32 D_8013550C;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F47C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F482C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F48BC.s")

void func_800F4924(s32 arg0,s32 a1)
{
    func_800A17A8(D_80135490[arg0],a1);
}

void func_800F4950(s32 arg0)
{
    _baattach_entrypoint_2(D_80135490[arg0]);
}

void func_800F497C(s32 arg0)
{
    _badrone_entrypoint_5(D_80135490[arg0]);
}

void func_800F49A8(s32 arg0)
{
    _badrone_entrypoint_10(D_80135490[arg0]);
}

void func_800F49D4(s32 arg0,void* arg1,s32 arg2)
{
    _badrone_entrypoint_11(D_80135490[arg0],arg1,arg2);
}

void func_800F4A00(s32 arg0)
{
    _badrone_entrypoint_12(D_80135490[arg0]);
}

void func_800F4A2C(s32 arg0)
{
    _badrone_entrypoint_13(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4AC0.s")

void func_800F4AF4(s32 arg0)
{
    func_800A4DA4(D_80135490[arg0]);
}

void func_800F4B20(s32 arg0)
{
    func_800A4E30(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4B4C.s")

s32 func_800F4B8C(u32 a0, u32 a1, s32 a2)
{
    return func_800F3930(D_80135490[a0],a1,a2);
}

s32 func_800F4BB8(u32 arg0, u32 arg1, s32 arg2)
{
    return func_800F3A78(D_80135490[arg0],arg1,arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4C24.s")

void func_800F4CC0(s32 arg0)
{
    func_80091E6C(D_80135490[arg0]);
}

void func_800F4CEC(s32 arg0,u32 arg1)
{
    func_80091E48(D_80135490[arg0],arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4E5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4F34.s")

void func_800F4F98(s32 arg0)
{
    _baattach_entrypoint_5(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F4FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F50D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F51A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F51CC.s")

void func_800F51F0(s32 arg0)
{
    func_80093504(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F521C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5268.s")

void func_800F52B8(s32 arg0)
{
    func_8008EF3C(D_80135490[arg0]);
}

void func_800F52E4(s32 arg0)
{
    func_8008F4F0(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5310.s")

AnimCtrl* func_800F5378(s32 arg0)
{
    return baanim_getAnimCtrlPtr(D_80135490[arg0]);
}

void func_800F53A4(s32 arg0)
{
    func_8008E938(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F53D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F53E4.s")

s32 func_800F5410(s32 arg0)
{
    return func_800A3274(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F543C.s")

void func_800F5470(s32 arg0)
{
    func_80098590(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F549C.s")

//Get Which Character is in Control
u32 func_800F54E4(void) 
{
	return D_801354DC;
}

s32 func_800F54F0(s32 arg0)
{
    return bakey_getControllerIndex(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F551C.s")

void func_800F554C(s32 arg0)
{
    func_80092BDC(D_80135490[arg0]);
}

s32 func_800F5578(s32 arg0)
{
    return func_800A1718(D_80135490[arg0]);
}

void func_800F55A4(s32 arg0)
{
    func_800A1760(D_80135490[arg0]);
}

void func_800F55D0(s32 arg0)
{
    func_800965D4(D_80135490[arg0]);
}

void func_800F55FC(s32 arg0)
{
    func_80096628(D_80135490[arg0]);
}

void func_800F5628(s32 arg0)
{
    func_80096364(D_80135490[arg0]);
}

void func_800F5654(s32 arg0)
{
    func_80096670(D_80135490[arg0]);
}

void func_800F5680(s32 arg0)
{
    func_800963C0(D_80135490[arg0]);
}

void func_800F56AC(s32 arg0)
{
    func_80096694(D_80135490[arg0]);
}

Unk80132ED0* func_800F56D8(s32 arg0)
{
    return _bahold_entrypoint_5(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5754.s")

void func_800F5794(s32 arg0)
{
    func_800F3B3C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F57C0.s")

void func_800F57F0(s32 arg0)
{
    func_800F3B90(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F581C.s")

void func_800F586C(s32 arg0)
{
    func_80098B5C(D_80135490[arg0]);
}

s32 func_800F5898(void) 
{
	return 8;
}

void func_800F58A0(s32 arg0)
{
    _bswalk_entrypoint_0(D_80135490[arg0]);
}

void func_800F58CC(s32 arg0)
{
    func_80096394(D_80135490[arg0]);
}

void func_800F58F8(s32 arg0)
{
    func_800A3354(D_80135490[arg0]);
}

void func_800F5924(s32 arg0)
{
    func_800A3360(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5950.s")

void func_800F59D4(s32 arg0)
{
    _bapackctrl_entrypoint_1(D_80135490[arg0]);
}

void func_800F5A00(s32 arg0,f32* a1)
{
    func_800F3BB0(D_80135490[arg0],a1);
}

void func_800F5A2C(s32 arg0)
{
    func_800F3BD0(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5AD0.s")

void func_800F5AE0(s32 arg0)
{
    func_8009BFCC(D_80135490[arg0]);
}

void func_800F5B0C(s32 arg0)
{
    func_8009CC68(D_80135490[arg0]);
}

void func_800F5B38(s32 arg0)
{
    func_800F3E84(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5B64.s")

void func_800F5BC4(s32 arg0)
{
    func_80092B8C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5C44.s")

void func_800F5C94(s32 arg0)
{
    func_800F3ED0(D_80135490[arg0]);
}

void func_800F5CC0(s32 arg0)
{
    bastick_getAngle(D_80135490[arg0]);
}

void func_800F5CEC(s32 arg0)
{
    bastick_distance(D_80135490[arg0]);
}

void func_800F5D18(s32 arg0)
{
    func_800F40EC(D_80135490[arg0]);
}

void func_800F5D44(s32 arg0,f32* arg1)
{
    func_800A33CC(D_80135490[arg0],arg1);
}

void func_800F5D70(s32 arg0)
{
    func_8009BB24(D_80135490[arg0]);
}

void func_800F5D9C(s32 arg0)
{
    func_800F4200(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5DC8.s")

void func_800F5E24(s32 arg0)
{
    func_800966BC(D_80135490[arg0]);
}

void func_800F5E50(s32 arg0)
{
    func_800966E0(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5E7C.s")

void func_800F5ECC(s32 arg0)
{
    func_800A4C68(D_80135490[arg0]);
}

void func_800F5EF8(s32 arg0)
{
    func_800A4C88(D_80135490[arg0]);
}

f32 func_800F5F24(u32 arg0)
{
    return yaw_get(D_80135490[arg0]);
}

f32 func_800F5F50(s32 arg0)
{
    return yaw_getIdeal(D_80135490[arg0]);
}

void func_800F5F7C(s32 arg0)
{
    func_8009C150(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F5FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F604C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F608C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F61E4.s")

void func_800F6204()
{
    func_800F6140();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6308.s")

void func_800F6388(s32 arg0,s32 arg1)
{
    func_8008F788(D_80135490[arg0],arg1);
}

void func_800F63B4(s32 arg0)
{
    func_8008F7B4(D_80135490[arg0]);
}

void func_800F63E0(s32 arg0,u32 arg1)
{
    func_8008F854(D_80135490[arg0],arg1);
}

void func_800F640C(s32 arg0)
{
    func_8008F828(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6438.s")

void func_800F6478(s32 arg0)
{
    func_800F424C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F64A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F64DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F651C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F65D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6604.s")

s32 func_800F6634(s32 arg0) 
{
	return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6640.s")

void func_800F6690(s32 arg0)
{
    func_80092EB0(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F66BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F67EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F682C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F68B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F690C.s")

void func_800F693C(s32 arg0)
{
    func_8008DD70(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F69E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6AA4.s")

u8 func_800F6B34(void) {
	return D_801354DA;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6C1C.s")

void func_800F6C5C(s32 arg0)
{
    player_isStable(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6CC8.s")

void func_800F6D24(s32 arg0)
{
    func_8008E124(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6DA0.s")

void func_800F6DE0()
{
    _bsbabykaz_entrypoint_14();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6E40.s")

void func_800F6E80(s32 arg0)
{
    func_800A336C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F6F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F70BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F70EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F711C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7180.s")

void func_800F71D4(s32 arg0)
{
    func_8008E37C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F72DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F732C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F739C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F73C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F759C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F76B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F77E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7874.s")

void func_800F78C8(s32 arg0,s32 arg1)
{
    func_800F7C58(arg0,0x17,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F78EC.s")

void func_800F796C(s32 arg0,s32 arg1)
{
    func_800F798C(arg0,arg1,0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F798C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F79DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7B1C.s")

void func_800F7B9C(s32 arg0,u32 a1)
{
    func_8009E7C8(D_80135490[arg0],a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F7F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8088.s")

void func_800F80D8(u32 arg0) {
	D_801354DC = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F80E4.s")

void func_800F8128(s32 arg0)
{
    func_800F80D8(arg0);
    func_800A91A8(arg0);
}
void func_800F8150(s32 arg0)
{
    func_80093370(D_80135490[arg0]);
}

void func_800F817C(s32 arg0)
{
    func_8009337C(D_80135490[arg0]);
}

void func_800F81A8(s32 arg0)
{
    func_800A1870(D_80135490[arg0]);
}

void func_800F81D4(s32 arg0)
{
    _bafpctrl_entrypoint_12(D_80135490[arg0]);
}

void func_800F8200(s32 arg0)
{
    func_800F4524(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F822C.s")

void func_800F8268(s32 arg0,s32 a1, s32 a2)
{
    func_800A38F0(D_80135490[arg0],a1,a2);
}

void func_800F8294(s32 arg0,f32* a1)
{
    func_800F452C(D_80135490[arg0],a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F82C0.s")

void func_800F82D4(s32 arg0,s32 arg1)
{
    func_800F457C(D_80135490[arg0],arg1);
}

void func_800F8300(s32 arg0)
{
    func_800F45B0(D_80135490[arg0]);
}

void func_800F832C(s32 arg0,f32* a1)
{
    func_800F45E0(D_80135490[arg0],a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8358.s")

void func_800F838C(s32 arg0)
{
    func_8008F748(D_80135490[arg0]);
}

void func_800F83B8(s32 arg0)
{
    func_800A3514(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F83E4.s")

void func_800F8418(s32 arg0)
{
    func_800F4648(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F849C.s")

void func_800F84D0(s32 arg0)
{
    func_8009659C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F84FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F86C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F86D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F87A4.s")

void func_800F8804(s32 arg0)
{
    func_8009CD70(D_80135490[arg0]);
}

void func_800F8830(s32 arg0)
{
    func_8009E7C8(arg0,0x99);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8850.s")

void func_800F8874(s32 arg0)
{
    func_8009224C(D_80135490[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F88A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F89BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F89E4.s")

f32 func_800F8A50(void)
{
	return D_8013550C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8B38.s")

s32 func_800F8B64(void) {
	return (s32)D_801354F9;
}

u8 func_800F8B70(void) {
	return D_801354FC;
}

u8 func_800F8B7C(void)
{
	return D_801354FD;
}

u8 func_800F8B88(void) {
	return D_801354F8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8E78.s")

void func_800F8EBC(s32 a0)
{
    func_800F8E78(func_800F5410(a0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F90EC.s")

void func_800F90F8(s32 arg0) {
	D_801354F9 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F911C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F91EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F929C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F92CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F93C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F99E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F99FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9AAC.s")

void func_800F9ADC()
{
    func_800F9488(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9B54.s")

void func_800F9BA4()
{
    func_800D9240(0x11);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9BC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F9C6C.s")
