#include <ultra64.h>


extern u8 D_80127642;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A718C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A71E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A72A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A73F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A759C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A76F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A791C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A794C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A79D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7AD4.s")

//Set Warp Bit To On
void func_800A7B18(u32 warpVal)
{
    D_80127642 = warpVal;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A7FB4.s")

extern s16 D_80127632;
extern s16 D_80127634;
extern s16 D_80127636;
extern f32 D_80127638;
extern s16 D_80127640;
extern u8 D_80127642;
extern u8 D_8012764C;
extern s32 D_80127650;

void func_8001B84C(void);
void func_8001B840(void);
void defragment_overlays(void);
void func_8001B518(s32);
void func_801015C8(void);
void func_80017840(void);
void func_800D8674(void);
void func_8008BA5C(void);
void func_800B5A6C(void);
void func_800A5654(void);
void func_800DF874(void);
void func_800A95C4(void);
void func_800F86D8(void);
void func_800F91EC(void);
void func_800B562C(void);
void func_800BF58C(void);
void func_800BD600(void);
void func_800CCFEC(void);
void func_800A5D6C(void);
void func_800B5E3C(void);
void func_800DA1E0(void);
void func_800D15CC(void);
void func_8010E030(void);
void func_800C075C(void);
void func_800C08C0(void);
void func_801005B8(void);
void func_800D6D68(void);
void func_80100E54(void);
void func_800BFFF4(void);
void func_800C9074(void);
void func_800DBB64(void);
void func_800E8B3C(void);
void func_800A86D8(void);
void func_800EE670(void);
void func_800ABA20(void);
void func_800FA608(void);
void func_800E8A20(void);
void func_800A9D00(void);
void func_800C9484(void);
void func_800B4380(void);
void func_800EB7A8(void);
void func_800D88C0(void);
void func_800FFE08(void);
void func_8001B858(void);

// do_tidy
void func_800A7FD4(void) {
    D_80127650 = 1;
    func_8001B84C();
    func_8001B840();
    defragment_overlays();
    func_8001B518(0);
    func_801015C8();
    func_80017840();
    func_800D8674();
    func_8008BA5C();
    func_800B5A6C();
    func_800A5654();
    func_800DF874();
    func_800A95C4();
    func_800F86D8();
    func_800F91EC();
    func_800B562C();
    func_800BF58C();
    func_800BD600();
    func_800CCFEC();
    func_800A5D6C();
    func_800B5E3C();
    func_800DA1E0();
    func_800D15CC();
    func_8010E030();
    func_800C075C();
    if (D_80127632 == 4) {
        func_800C08C0();
    }
    func_801005B8();
    func_800D6D68();
    func_80100E54();
    func_800BFFF4();
    func_800C9074();
    func_800DBB64();
    func_800E8B3C();
    func_800A86D8();
    func_800EE670();
    func_800ABA20();
    func_800FA608();
    func_800E8A20();
    func_800A9D00();
    func_800C9484();
    func_800B4380();
    func_800EB7A8();
    func_800D88C0();
    func_800FFE08();
    func_8001B858();
}

void func_800A8168(void) {
    D_80127634 = 1;
}

s16 func_800A8178(void) {
    return D_80127634;
}

s16 func_800A8184(void) {
    return D_80127632;
}

u8 func_800A8190(void) {
    return D_8012764C;
}

int func_800A819C(void) {
    return D_80127632 == 3 ||  D_80127632 == 5;
}

int func_800A81C4(void) {
    s32 a, b;
    if (D_80127640 == 0) {
        return 0;
    }
    a = _gcsectionDll_entrypoint_4(D_80127640);
    b = _gcsectionDll_entrypoint_4(func_800EA05C());
    return b != a && D_80127636 == 0;
}

void func_800A8230(void) {
    D_80127636 = 1;
}

void func_800A8240(void) {
    D_80127636 = 0;
}

s16 func_800A824C(void) {
    return D_80127636;
}

f32 func_800A8258(void) {
    return D_80127638;
}

int func_800A8264(void) {
    return D_80127642 != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A84EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A85A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A861C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A86D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A877C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A87FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A88C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A89A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A89BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A89F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8BA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E80A70/func_800A8D00.s")
