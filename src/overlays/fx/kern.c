#include "fx/kern.h"

typedef struct FxKernEntry {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s8 unk3;
} FxKernEntry;

extern FxKernEntry D_80800420_fxkern[];

extern f32 B_80800480_fxkern;
extern f32 B_80800488_fxkern[][2];

s32 func_80800084_fxkern(char*);
void func_80800224_fxkern(GraphicsBuffers*, s32, s32, char*, s32);

void func_80800000_fxkern(u8 arg0, u8 arg1, s32* arg2, s32* arg3)
{
    s32 index = 0;
    *arg3 = 0;
    *arg2 = 0;

    while (D_80800420_fxkern[index].unk0 != 0)
    {
        if (arg0 == D_80800420_fxkern[index].unk1 && (arg1 == D_80800420_fxkern[index].unk0 || D_80800420_fxkern[index].unk0 == 0x2A))
        {
            *arg2 = D_80800420_fxkern[index].unk2;
            *arg3 = D_80800420_fxkern[index].unk3;
            return;
        }
        index++;
    }
}

s32 func_80800084_fxkern(char* textToShow)
{

    s32 index;
    s32 sp58;
    s32 sp54;
    B_80800488_fxkern[0][0] = 0.0f;
    B_80800488_fxkern[0][1] = 0.0f;

    index = 1;
    while (textToShow[index] != 0 && index < 0x40)
    {
        B_80800488_fxkern[index][0] = B_80800488_fxkern[index - 1][0];
        B_80800488_fxkern[index][0] += B_80800480_fxkern * (f32)(func_800D36C4(1, textToShow[index - 1]) / 2);
        B_80800488_fxkern[index][0] += B_80800480_fxkern * (f32)(func_800D36C4(1, textToShow[index]) / 2);
        B_80800488_fxkern[index][0] += B_80800480_fxkern * -4.0f;
        func_80800000_fxkern(textToShow[index], textToShow[index - 1], &sp58, &sp54);
        B_80800488_fxkern[index][0] = (B_80800488_fxkern[index][0] + (B_80800480_fxkern * sp58));
        B_80800488_fxkern[index][1] = (sp54 * B_80800480_fxkern);
        index++;
    }

    return index - 1;
}

void func_80800224_fxkern(GraphicsBuffers* arg0, s32 leftOffset, s32 verticalOffset, char* TextToShow, s32 arg4)
{
    func_800B8C98(1);
    func_800B7F14(arg0);
    for (; 0 <= arg4; arg4--)
    {
        func_800B8DEC(arg0, (B_80800488_fxkern[arg4][0] + leftOffset), B_80800488_fxkern[arg4][1] + verticalOffset, TextToShow[arg4]);
    }
    func_800B811C(arg0);
}

void fxkern_entrypoint_0(GraphicsBuffers** arg0, u32 leftOffset, u32 offsetFromBottom, char* textToShow)
{
    func_80800224_fxkern(arg0, leftOffset, offsetFromBottom, textToShow, func_80800084_fxkern(textToShow));
}

void fxkern_entrypoint_1(GraphicsBuffers* arg0, u32 offsetFromTop, char* TextToShow) {
    s32 temp_v0;

    temp_v0 = func_80800084_fxkern(TextToShow);
    func_80800224_fxkern(arg0, ((304.0f - B_80800488_fxkern[temp_v0][0]) / 2), offsetFromTop, TextToShow, temp_v0);
}

void fxkern_entrypoint_2(void)
{
    func_800B8C50();
    B_80800480_fxkern = 1.0f;
}

void fxkern_entrypoint_3(f32 arg0) 
{
    func_800B8CF0(arg0);
    B_80800480_fxkern = arg0;
}