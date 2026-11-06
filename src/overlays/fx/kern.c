#include "fx/kern.h"

typedef struct FxKernEntry {
    char startChar;
    char endChar;
    s8 adjustX;
    s8 adjustY;
} FxKernEntry;

FxKernEntry D_kern_charPairAdjust[] = 
{
    {'A','V',0xFD,0x00},
    {'W','A',0xFD,0x00},
    {'V','A',0xFD,0x00},
    {'Y','A',0xFE,0x00},
    {'M','O',0xFF,0x00},
    {'D','A',0xFF,0x00},
    {'R','O',0xFE,0x00},
    {'T','A',0xFE,0x00},
    {'S','T',0xFF,0x00},
    {'A','M',0xFF,0x00},
    {'C','O',0xFF,0x00},
    {'O','V',0xFF,0x00},
    {'L','O',0xFF,0x00},
    {'M','U',0xFF,0x00},
    {'U','M',0xFF,0x00},
    {'M','A',0xFE,0x00},
    {'M','0',0xFF,0x00},
    {'H','I',0x01,0x00},
    {'I','P',0x01,0x00},
    {'E','E',0x00,0x01},
    {'Z','E',0x00,0xFF},
    {'*','S',0x01,0x00},
    {'*','\'',0x03,0x00}
};

f32 B_textScale;
f32 B_textPosBuffer[0x41][2];

s32 fxkern_populateTextPosBuffer(char*);
void fxkern_drawChars(GraphicsBuffers*, s32, s32, char*, s32);

void fxkern_GetManualKernAdjustments(char start, char end, s32* arg2, s32* arg3)
{
    s32 index = 0;
    *arg3 = 0;
    *arg2 = 0;

    //Look through the array for character pairs that have a manual kerning adjustment
    while (D_kern_charPairAdjust[index].startChar != 0)
    {
        if (start == D_kern_charPairAdjust[index].endChar && (end == D_kern_charPairAdjust[index].startChar || D_kern_charPairAdjust[index].startChar == '*'))
        {
            *arg2 = D_kern_charPairAdjust[index].adjustX;
            *arg3 = D_kern_charPairAdjust[index].adjustY;
            return;
        }
        index++;
    }
}

//Returns the index of the end of the string after filling out the textPosBuffer
s32 fxkern_populateTextPosBuffer(char* textToShow)
{

    s32 index;
    s32 kernAdjustX;
    s32 kernAdjustY;
    B_textPosBuffer[0][0] = 0.0f;
    B_textPosBuffer[0][1] = 0.0f;

    index = 1;
    //Cycle through char in string
    while (textToShow[index] != '\0' && index < 0x40)
    {
        //Set the current character to the X of the previous character
        B_textPosBuffer[index][0] = B_textPosBuffer[index - 1][0];
        //Shift the character over by half the width of the previous character
        B_textPosBuffer[index][0] += B_textScale * (f32)(func_800D36C4(1, textToShow[index - 1]) / 2);
        //Shift the character over by half the width of the current character
        B_textPosBuffer[index][0] += B_textScale * (f32)(func_800D36C4(1, textToShow[index]) / 2);
        //Remove some position from text
        B_textPosBuffer[index][0] += B_textScale * -4.0f;
        fxkern_GetManualKernAdjustments(textToShow[index], textToShow[index - 1], &kernAdjustX, &kernAdjustY);
        B_textPosBuffer[index][0] = (B_textPosBuffer[index][0] + (B_textScale * kernAdjustX));
        B_textPosBuffer[index][1] = (kernAdjustY * B_textScale);
        index++;
    }

    return index - 1;
}

void fxkern_drawChars(GraphicsBuffers* arg0, s32 leftOffset, s32 verticalOffset, char* TextToShow, s32 arg4)
{
    graphics_setTextFont(1);
    func_800B7F14(arg0);
    for (; 0 <= arg4; arg4--)
    {
        graphics_drawChar(arg0, (B_textPosBuffer[arg4][0] + leftOffset), B_textPosBuffer[arg4][1] + verticalOffset, TextToShow[arg4]);
    }
    func_800B811C(arg0);
}

void fxkern_entrypoint_0(GraphicsBuffers* arg0, u32 leftOffset, u32 offsetFromBottom, char* textToShow)
{
    fxkern_drawChars(arg0, leftOffset, offsetFromBottom, textToShow, fxkern_populateTextPosBuffer(textToShow));
}

void fxkern_entrypoint_1(GraphicsBuffers* arg0, u32 offsetFromTop, char* TextToShow) {
    s32 temp_v0;

    temp_v0 = fxkern_populateTextPosBuffer(TextToShow);
    fxkern_drawChars(arg0, ((304.0f - B_textPosBuffer[temp_v0][0]) / 2), offsetFromTop, TextToShow, temp_v0);
}

void fxkern_entrypoint_2(void)
{
    graphics_resetTextParams();
    B_textScale = 1.0f;
}

void fxkern_entrypoint_3(f32 arg0) 
{
    graphics_setTextScale(arg0);
    B_textScale = arg0;
}