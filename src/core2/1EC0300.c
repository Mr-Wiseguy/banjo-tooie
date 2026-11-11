#include "core2/1EC0300.h"

//strcat
void string_concat(char* dst, char* src) {
    while (*(dst) != '\0') {
        dst++;
    }
    while (*(src) != '\0') {
        *(dst++) = *(src++);
    }
    *(dst) = '\0';
}

//strcatc
void string_concatChar(char* dst, char src) 
{
    while (*(dst) != '\0') 
	{
        dst++;
    }
    *(dst++) = src;
    *(dst) = '\0';
}

void func_800E6A90(char* arg0, char* arg1)
{

	while (*arg1 != '\0')
	{
		func_800E6AFC(arg0, *(arg1++));
		string_concat(arg0, " ");
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E6AFC.s")

s32 func_800E6B7C(s32 arg0, f32 arg1)
{
	s32 returnValue;
	if (arg1 < 0.0f)
	{
		returnValue = -1;
	}
	else
	{
		returnValue = 1;
	}
	return returnValue;
}

void func_800E6BAC(char* arg0, f32 arg1)
{
	s32 temp_f4_2;
	char* sp38;
	switch (func_800E6B7C(&sp38, arg1))
	{
		case 0:
			string_concat(arg0, sp38);
			return;
		case -1:
			string_concat(arg0, "-");
			arg1 = -arg1;
		case 1:
			string_IToA(arg0, (s32)arg1);
			string_concat(arg0, ".");
			temp_f4_2 = ((arg1 - (s32)arg1) * 100.0f);
			if (temp_f4_2 < 0xA)
			{
				string_concat(arg0, "0");
			}
			string_IToA(arg0, temp_f4_2);
			return;
	}
}

void func_800E6CA8(char* arg0, f32 arg1, s32 arg2)
{
	char* sp44;

	switch (func_800E6B7C(&sp44, arg1))
	{
	case 0:
		string_concat(arg0, sp44);
		return;
	case -1:
		string_concat(arg0, "-");
		arg1 = -arg1;
	case 1:
		string_IToA(arg0, arg1);
		if (arg2 != 0)
		{
			string_concat(arg0, ".");
			while (arg2--)
			{
				arg1 -= (s32)arg1;
				arg1 *= 10.0f;
				string_IToA(arg0, arg1);
			}
		}
	}
}

void string_IToA(char* dst, s32 value)
{
	string_IToAPrefix(dst, value, 0, 0);
}

void string_IToAPrefix(char* dst, s32 value, char prefix, s32 arg3)
{
	s32 powerOf10;

	while (*dst != '\0')
	{
		dst++;
	}
	if (value < 0)
	{
		*dst = '-';
		dst++;
		value = -value;
	}
	else if (prefix != '\0')
	{
		*dst = prefix;
		dst++;
	}
	//Start at a billion
	powerOf10 = 1000000000;
	//Divide by 10 until we get a multiple of 10 with the same number of digits as value
	while (value < powerOf10)
	{
		powerOf10 = powerOf10 / 10;
	}
	if (powerOf10 == 0)
	{
		*dst = '0';
		dst++;
	}
	else
	{
		for (powerOf10; powerOf10 > 0; powerOf10 /= 10)
		{
			if (arg3 != 0)
			{
				*dst = (value / powerOf10) + 0x10;
				dst++;
			}
			else
			{
				//convert value to the ascii
				*dst = (value / powerOf10) + '0';
				dst++;
			}
			//Remove the highest digit
			value %= powerOf10;
		}
	}
	*dst = '\0';
}

void func_800E6F7C(char* arg0, u32 arg1)
{
	s32 temp_t0;
	s32 var_v1;

	while (*arg0 != '\0')
	{
		arg0++;
	}
	*arg0 = '0';
	arg0++;
	*arg0 = 'x';
	arg0++;
	for (var_v1 = 7; var_v1 >= 0; var_v1--)
	{
		temp_t0 = (arg1 >> var_v1 * 4) & 0xF;
		if ((temp_t0 < 0xA) & 0xFF)
		{
			*arg0 = temp_t0 + '0';
		}
		else
		{
			*arg0 = temp_t0 + 'W';
		}
		arg0++;
	}
	*arg0 = '\0';
}

void func_800E6FEC(char* arg0, u32 arg1)
{
	s32 temp_t0;
	s32 var_v1;

	while (*arg0 != '\0')
	{
		arg0++;
	}
	*arg0 = '0';
	arg0++;
	*arg0 = '.';
	arg0++;
	for (var_v1 = 7; var_v1 >= 0; var_v1--)
	{
		temp_t0 = (arg1 >> var_v1 * 4) & 0xF;
		if ((temp_t0 < 0xA) & 0xFF)
		{
			*arg0 = temp_t0 + '0';
		}
		else
		{
			*arg0 = temp_t0 + '7';
		}
		arg0++;
	}
	*arg0 = '\0';
}

void func_800E705C(char* arg0, char arg1)
{
	s32 temp_t0;
	s32 var_v1;

	while (*arg0 != '\0')
	{
		arg0++;
	}
	*arg0 = '0';
	arg0++;
	*arg0 = 'x';
	arg0++;
	for (var_v1 = 1; var_v1 >= 0; var_v1--)
	{
		temp_t0 = (arg1 >> var_v1 * 4) & 0xF;
		if ((temp_t0 < 0xA) & 0xFF)
		{
			*arg0 = temp_t0 + '0';
		}
		else
		{
			*arg0 = temp_t0 + '7';
		}
		arg0++;
	}
	*arg0 = '\0';
}

//string compare
s32 string_compare(const char* str1, const char* str2) 
{
    while (*str1 && *str2 && *str1 == *str2) 
	{
        str1++;
        str2++;
    }

    if (*str1 == *str2)
        return 0;
    else if (*str1 == '\0' || *str1 < *str2)
        return -1;
    else
        return 1;
}

//string copy
void string_copy(char* dst, char* src) 
{
    while (*(src) != '\0') 
	{
        *(dst++) = *(src++);
    }
    *(dst) = 0;
}

//string length
s32 string_length(char* str) 
{
    char v0;
    s32 len;

    len = 0;
    v0 = *(str++);
    while (v0 != '\0') {
        len++;
        v0 = *(str++);
    }
    return len;
}

char* func_800E71B8(char* arg0)
{
	if (_gldialog_entrypoint_1() != 0)
	{
		return arg0 += 2;
	}
	return arg0;
}

//strcmptok
s32 func_800E71EC(char *str1, char* str2, char* str3)
{

    while (*str2 == *str3) 
	{
        str2++;
        str3++;
        if ((*str2 == '\0' || *str2 == *str1) && (*str3 == '\0' || *str3 == *str1)){
            return 1;
        }
    }
    return 0;
}

//strtok
char* string_afterToken(char* str, const char* delim) 
{
    while (*delim != '\0' && *delim != *str) {
        delim++;
    }
    if (*delim == *str) {
        delim++;
    }
    return delim;
}


//strcpyToTok
void string_copyToToken(char* delim, char* target, char* str) 
{
	//Copy str into target until we reach end terminator or the delimiter
    while ((*str != '\0') && (*str != *delim))
	{
        *target = *str;
		str++;
		target++;
    }
    *target = '\0';
}

//strtoupper
void string_toUpper(char* str) {
    char* ret = str;
    while (*ret != '\0') 
	{
        if ((*ret >= 'a') && (*ret <= 'z'))
		{
            *ret -= 0x20;
        }
        ret++;
    }
    str = ret;
}
//strtolower
void string_toLower(char* str)
{
	char* ret = str;
	while (*ret != '\0')
	{
		if ((*ret >= 'A') && (*ret <= 'Z'))
		{
			*ret += 0x20;
		}
		ret++;
	}
	str = ret;
}

//int to binary string
void string_intToBinary(char* dst, s32 value)
{
	s32 var_s0;
	s32 var_v0;

	for (var_s0 = 31; var_s0 >= 0; var_s0--)
	{
		if ((1 << var_s0) & value)
		{
			var_v0 = '1';
		}
		else
		{
			var_v0 = '0';
		}
		string_concatChar(dst, var_v0);
	}
}

//string set null
void string_setNull(char* str)
{
	*str = '\0';
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E73DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC0300/func_800E7480.s")
