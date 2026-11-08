#include "ch/introtext.h"

typedef struct {
    /* 0x00 */ s16 numberOfLines;
    /* 0x02 */ s16 verticalOffset[10];
    /* 0x16 */ s16 textOffset[10];
    /* 0x2A */ s16 textFont[10];
    /* 0x3E */ u8 unk3E;
    /* 0x3F */ u8 unk3F;
} introTextMemory;

typedef struct {
    f32 unk0[3];
    u32 unkC;
} UNK_D_808007A0;
extern UNK_D_808007A0 D_808007A0_chintrotext[];

extern ActorData D_808007D0_chintrotext;

void func_8080051C_chintrotext(Actor*, u32);

ActorData* chintrotext_entrypoint_0(void) {
    return &D_808007D0_chintrotext;
}

void func_8080000C_chintrotext(Actor* arg0)
{
    s32 charIndex;
    char* textAddress;
    s32 charIndex2;
    introTextMemory* textMemory;

    textAddress = actor_getAdditionalMem(arg0, 0U);
    textMemory = (introTextMemory*)actor_getAdditionalMem(arg0, 1U);
    textMemory->textOffset[0] = 0;
    textMemory->numberOfLines = 1;
	textMemory->textFont[0] = 0xC26;
    charIndex = 0;
    for (charIndex = 0; textAddress[charIndex]; charIndex++)
    {
        if (textAddress[charIndex] == '#')
        {
            charIndex2 = charIndex + 1;
            while (textAddress[charIndex2]) {
                textAddress[charIndex2 - 1] = textAddress[charIndex2];
                charIndex2++;
            }
            textAddress[charIndex2 - 1] = NULL;
            //Set the font to be the pink
            textMemory->textFont[textMemory->numberOfLines - 1] = 0xC25;
        }
        if (textAddress[charIndex] == '\n')
        {
            textMemory->textOffset[textMemory->numberOfLines] = charIndex + 1;
            textMemory->textFont[textMemory->numberOfLines] = 0xC26;
            textMemory->numberOfLines++;
            textAddress[charIndex] = NULL;
            if (textMemory->numberOfLines == 0x9)
            {
                break;
            }
        }
    }
    flag_setValueTrue(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_80800130_chintrotext(s32 arg0)
{
    flag_setValueFalse(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_80800154_chintrotext(Actor* arg0)
{
    introTextMemory* sp3C;
    s32 sp38;
    s32 temp_a2;
    UNK_D_808007A0* new_var;
    s32 var_v1;
    s32 sp28;
    sp3C = (introTextMemory*)actor_getAdditionalMem(arg0, 1U);
    sp38 = timer_reachedZero(&arg0->unk58);
    new_var = &D_808007A0_chintrotext[sp3C->unk3F];
    temp_a2 = (*new_var).unkC;
    switch (arg0->unk70_10)
    {
    case 1:
        sp3C = (introTextMemory*)actor_getAdditionalMem(arg0, 1U);
        switch (sp3C->unk3E)
        {
        case 0:
            sp28 = 0xE4 - (sp3C->numberOfLines * temp_a2);
            sp28 >>= 1;
            sp28 += 2.5f * temp_a2;
            break;

        case 1:
            sp28 = 0x72 - (sp3C->numberOfLines * temp_a2);
            sp28 >>= 1;
            break;

        case 2:
            sp28 = 0xE4 - (sp3C->numberOfLines * temp_a2);
            sp28 >>= 1;
            break;

        default:
            sp28 = sp28;
        }

        for (var_v1 = 0; var_v1 < sp3C->numberOfLines; var_v1++)
        {
            sp3C->verticalOffset[var_v1] = (var_v1 * temp_a2) + sp28;
        }

        func_8080051C_chintrotext(arg0, 2);
        return;

    case 2:
        flag_setValueTrue(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
        if (func_800C954C() == 0)
        {
            func_8080051C_chintrotext(arg0, 3);
            return;
        }
    default:
        return;
    case 3:
        flag_setValueTrue(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
        _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0, D_808007A0_chintrotext[sp3C->unk3F].unk0[0], 255.0f, 0.0f));
        if (sp38 != 0)
        {
            func_8080051C_chintrotext(arg0, 4);
            return;
        }
        break;

    case 4:
        flag_setValueTrue(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
        if (sp38 != 0)
        {
            func_8080051C_chintrotext(arg0, 5);
            return;
        }
        break;

    case 5:
        _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0, new_var->unk0[2], 0.0f, 255.0f));
        if (sp38 != 0)
        {
            actor_mark_delete(arg0);
        }
        break;
    }
}

void func_808003EC_chintrotext(Actor* arg0, GraphicsBuffers* arg1)
{
    f32 fontScale;
    introTextMemory* textMemory;
    s32 var_s1;

    textMemory = (introTextMemory*)actor_getAdditionalMem(arg0, 1U);
    if (((s32)(arg0->unk70_10) >= 3) && (func_800A819C() != 0))
    {
        _fxkern_entrypoint_2();
        graphics_setTextAlpha(_subaddiefade_entrypoint_0(arg0));

        for (var_s1 = 0; var_s1 < textMemory->numberOfLines; var_s1++)
        {
            //Set Font color to be drawn
            graphics_setTextPattern(textMemory->textFont[var_s1]);
            //If the text color is a specifically pink
            if (textMemory->textFont[var_s1] == 0xC25)
            {
                fontScale = 0.75f;
            }
            else
            {
                fontScale = 1.0f;
            }
            //Set Font Scale to draw
            _fxkern_entrypoint_3(fontScale);
            _fxkern_entrypoint_1(arg1, textMemory->verticalOffset[var_s1], func_800E71B8((char*)actor_getAdditionalMem(arg0, 0U) + textMemory->textOffset[var_s1]));
        }
    }
}

void func_8080051C_chintrotext(Actor* arg0, u32 arg1)
{
    introTextMemory* sp24;

    sp24 = (introTextMemory*)actor_getAdditionalMem(arg0, 1U);
    func_80101FDC(arg0, arg1);
    switch (arg1)
    {
    case 2:
        _subaddiefade_entrypoint_1(arg0, 0);
        flag_setValueTrue(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
        return;
    case 3:
        arg0->unk58 = D_808007A0_chintrotext[sp24->unk3F].unk0[0];
        return;
    case 4:
        arg0->unk58 = D_808007A0_chintrotext[sp24->unk3F].unk0[1];
        return;
    case 5:
        flag_setValueFalse(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
        arg0->unk58 = D_808007A0_chintrotext[sp24->unk3F].unk0[2];
        return;
    }
}

void chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (func_800A9C98() == 0)
    {
        _chbaddiesetup_entrypoint_4(&_chintrotext_entrypoint_3, arg0, arg1, arg3, arg2);
    }
}

s32 chintrotext_entrypoint_2(s32 arg0)
{
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    temp_v0 = _gcintrotext_entrypoint_2(-1, &sp24, &sp20);
    if ((temp_v0 != -1) && ((arg0 != 0) || (temp_v0 > 0)))
    {
        chintrotext_entrypoint_1(sp24, sp20, 0, 0);
        return 1;
    }
    return 0;
}

void chintrotext_entrypoint_3(u32 arg0, s16 arg1, s32 arg2, s32 arg3)
{
    f32 sp2C[3];
    Actor* temp_v0;
    introTextMemory* temp_v0_2;
    char* temp_v0_3;

    ml_vec3f_clear(sp2C);
    temp_v0 = func_80108474(0x3B0U, sp2C, 0);
    if (temp_v0 != NULL)
    {
        temp_v0_2 = (introTextMemory*)actor_getAdditionalMem(temp_v0, 1U);
        temp_v0_3 = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(NULL, arg0), arg1);
        func_80100074(temp_v0, 0U, string_length(temp_v0_3) + 1);
        string_copy(actor_getAdditionalMem(temp_v0, 0U), temp_v0_3);
        _gldbstring_entrypoint_2(arg0);
        temp_v0_2->unk3E = arg2;
        temp_v0_2->unk3F = arg3;
    }
}
