#ifndef __CORE2_1EC0300_H__
#define __CORE2_1EC0300_H__

#include "common.h"
#include "gl/dialog.h"

void string_concat(char*, char*);
void string_concatChar(char*, char);
void func_800E6A90(char*, char*);
void func_800E6AFC(char*, char);
s32 func_800E6B7C(s32, f32);
void string_IToA(char*, s32);
void string_IToAPrefix(char*, s32, char, s32);
//strcmp
s32 string_compare(const char* str1, const char* str2);
//Copy Text
void string_copy(char* target, char* source);
//Get Text Length
s32 string_length(char*);
char* func_800E71B8(char*);
s32 func_800E71EC(char*, char*, char*);
char* string_afterToken(char*, const char*);
void string_copyToToken(char*, char*, char*);
void string_toUpper(char* str);
void string_toLower(char* str);
void string_intToBinary(char*, s32);
void string_setNull(char*);
#endif
