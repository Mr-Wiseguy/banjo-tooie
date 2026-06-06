#include "common.h"
#include "overlays/ba/physics.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/anim.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/key.h"
#include "overlays/ba/roll.h"
#include "overlays/ba/timer.h"
#include "overlays/bs/state.h"
#include "core2/anctrl.h"
#include "player.h"
#include "core2/1E6B900.h"
#include "core2/1E78BF0.h"
#include "core2/1E75710.h"
#include "core2/1E75620.h"
#include "core2/1E77A20.h"
#include "core2/1E72EA0.h"
#include "core2/1EDA900.h"

extern s32 D_80801890_bssub;
extern s32 D_808018A0_bssub;
extern s32 D_808018B0_bssub;
extern s32 D_808018C0_bssub;
extern s32 D_808018D0_bssub;
extern s32 D_808018E0_bssub;
extern s32 D_808018F0_bssub;
extern s32 D_80801900_bssub;

void func_808008D8_bssub(PlayerState*);
void func_80800000_bssub(PlayerState*);
void func_80800BD8_bssub(PlayerState*);
void func_80800AEC_bssub(void);
void func_80800B0C_bssub(void);
void _basub_entrypoint_8(PlayerState*, f32);
void func_800914FC(PlayerState*, f32, s32);
void func_80093370(PlayerState*, s32);
s32 func_800EA068(s32);

// Sets the animation update flags for the submarine state.
void func_80800000_bssub(PlayerState* arg0) {
    func_8009FFD8(arg0, 1, 3, 3, 0xF);
}

// Scales a stick value by 300.
f32 func_80800030_bssub(f32 arg0, f32 arg1) {
    return arg1 * 300.0f;
}

// Scales a negated stick value by ~428.57.
f32 func_80800048_bssub(f32 arg0, f32 arg1) {
    return -arg1 * 428.57144f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800064_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808000F0_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800254_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800634_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800768_bssub.s")

// Enters the submarine state at slot arg0, ramps various parameters (unless 0xF blocks it).
void func_80800834_bssub(PlayerState* arg0) {
    if (bakey_pressed(arg0, 2) != 0) {
        _basub_entrypoint_1(arg0);
    }
    if (bakey_pressed(arg0, 1) != 0) {
        _basub_entrypoint_8(arg0, func_8009BB94(arg0));
    }
    if (bakey_pressed(arg0, 9) != 0) {
        if (func_800EA068(0x40) != 0) {
            _basub_entrypoint_3(arg0, 0x43200000, 0x3F800000);
            return;
        }
        _basub_entrypoint_5(arg0);
    }
}

// Tears down the submarine state for slot arg0 (unless already done by 0xF).
void func_808008D8_bssub(PlayerState* arg0) {
    if (func_8009E74C(arg0, 0xF) == 0) {
        func_800947EC(arg0, 1, 0);
        func_800961AC(arg0, 1);
        func_8009BC34(arg0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_resetZones(arg0);
        func_80095A40(arg0);
        func_80095964(arg0, 0);
        func_80093360(arg0, 0);
        _basub_entrypoint_9(arg0);
        func_800910BC(arg0, 1);
        _bafpctrl_entrypoint_18(arg0, 0);
        func_8009E474(arg0);
        func_80092864(arg0, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808009B0_bssub.s")

void func_80800AEC_bssub()
{
    _basub_entrypoint_14();
}

void func_80800B0C_bssub()
{
    _baspin_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800B2C_bssub.s")

// Spin-attack timer tick; spawns a splash effect when the timer elapses.
void func_80800BD8_bssub(PlayerState* arg0) {
    _baspin_entrypoint_3();
    if (_batimer_decrement(arg0, 9) != 0) {
        func_80101180(0x2C4, 0x71, arg0->unk184);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800C1C_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800C60_bssub.s")

// Submarine death setup: in deep water spin, else play the death sequence.
void func_80800E34_bssub(PlayerState* arg0) {
    s32 temp_v0;

    func_808009B0_bssub();
    temp_v0 = func_800EA068(0x40);
    arg0->unk15C.word = temp_v0;
    if (temp_v0 != 0) {
        func_80800B2C_bssub(arg0);
        return;
    }
    _bafpctrl_entrypoint_19(arg0);
    _basudie_entrypoint_9(arg0, 0x41F00000);
    func_80800C60_bssub(arg0);
}

// Submarine death per-frame: spin tick if mid-spin, else normal death update.
void func_80800E98_bssub(PlayerState* arg0) {
    func_80800AEC_bssub();
    if (arg0->unk15C.word != 0) {
        func_80800BD8_bssub(arg0);
        return;
    }
    _basudie_entrypoint_10(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80800EE0_bssub.s")

// Getter: returns entry arg0 of the D_80801890 jump table.
s32 bssub_entrypoint_0(s32 arg0) {
    return (&D_80801890_bssub)[arg0];
}

void func_80800F70_bssub(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808008D8_bssub(arg0);
}
void func_80800F98_bssub(s32 arg0)
{
    func_808009B0_bssub();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800FC0_bssub(s32 arg0)
{
    func_80800AEC_bssub();
    func_80800254_bssub(arg0);
    _bsdrone_entrypoint_1(arg0);
}

// Getter: returns entry arg0 of the D_808018A0 jump table.
s32 bssub_entrypoint_1(s32 arg0) {
    return (&D_808018A0_bssub)[arg0];
}

void func_80801004_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_8080102C_bssub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_80801130_bssub.s")

// Per-frame swim handler; reads stick/yaw, transitions out when speed reaches 0.
void func_80801188_bssub(PlayerState* arg0) {
    s32 sp24;

    sp24 = 0;
    func_80800AEC_bssub();
    func_8080102C_bssub(arg0);
    func_80800634_bssub(arg0);
    func_80800768_bssub(arg0);
    func_80800254_bssub(arg0);
    func_80800834_bssub(arg0);
    if (arg0->unk16C == 0.0f) {
        sp24 = 0x131;
    }
    bs_setState(arg0, sp24);
}

// Getter: returns entry arg0 of the D_808018B0 jump table.
s32 bssub_entrypoint_2(s32 arg0) {
    return (&D_808018B0_bssub)[arg0];
}

void func_8080121C_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}

// Spin-attack entry setup.
void func_80801244_bssub(s32 arg0) {
    func_808009B0_bssub();
    _baspin_entrypoint_2(arg0, 0x130, 0x3FE66666, 3, 1);
}

// Spin-attack per-frame; transitions out when the spin completes.
void func_80801284_bssub(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 40.0f, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

// Getter: returns entry arg0 of the D_808018C0 jump table.
s32 bssub_entrypoint_3(s32 arg0) {
    return (&D_808018C0_bssub)[arg0];
}

void func_808012F0_bssub(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}

// Spin-attack entry setup (alternate).
void func_80801318_bssub(s32 arg0) {
    func_808009B0_bssub();
    _baspin_entrypoint_2(arg0, 0x130, 0x3FE66666, 3, 1);
}

// Spin-attack per-frame (alternate); transitions out when the spin completes.
void func_80801358_bssub(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 40.0f, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

// Getter: returns entry arg0 of the D_808018D0 jump table.
s32 bssub_entrypoint_4(s32 arg0) {
    return (&D_808018D0_bssub)[arg0];
}

void func_808013C4_bssub(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808008D8_bssub(arg0);
}

// Bounce entry setup.
void func_808013EC_bssub(s32 arg0) {
    func_808009B0_bssub();
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x12E, 0x40C00000);
}

// Bounce per-frame; transitions out when the bounce completes.
void func_80801428_bssub(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    func_800914FC(arg0, 40.0f, 0);
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

// Getter: returns entry arg0 of the D_808018E0 jump table.
s32 bssub_entrypoint_5(s32 arg0) {
    return (&D_808018E0_bssub)[arg0];
}

void func_80801490_bssub(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808008D8_bssub(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808014B8_bssub.s")

// Rest per-frame; picks the next state.
void func_80801518_bssub(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, sp1C);
}

// Getter: returns entry arg0 of the D_808018F0 jump table.
s32 bssub_entrypoint_6(s32 arg0) {
    return (&D_808018F0_bssub)[arg0];
}

void func_80801578_bssub(s32 arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/sub/func_808015A0_bssub.s")

// Per-frame swim handler (variant); transitions when speed becomes nonzero.
void func_80801618_bssub(PlayerState* arg0) {
    s32 sp24;

    sp24 = 0;
    func_80800AEC_bssub();
    func_80800634_bssub(arg0);
    func_80800768_bssub(arg0);
    func_80800254_bssub(arg0);
    func_80800834_bssub(arg0);
    if (arg0->unk16C != 0.0f) {
        sp24 = 0x12C;
    }
    bs_setState(arg0, sp24);
}

// Getter: returns entry arg0 of the D_80801900 jump table.
s32 bssub_entrypoint_7(s32 arg0) {
    return (&D_80801900_bssub)[arg0];
}
