#include <ultra64.h>
#include "memory.h"
#include "core2/1E29B60.h"
#include "core2/1EB3750.h"

void _gldbDll_entrypoint_1(void);
void _gldbDll_entrypoint_2(void);
s32 _glgamedata_entrypoint_3(u8*, s32, s32*, u32*);

// .data
u32 D_8011B990 = 0;
s32 D_8011B994 = 0x6C9;

// .bss
u8* D_8012C770[3];
u8 D_8012C780[12];
u8 D_8012C78C[6];

void func_800DA544(s32);
void func_800DA524(s32);

// length of D_8012C770[0]
#define D_8012C770_0_LENGTH (1408 / 8)
// length of D_8012C770[1]
#define D_8012C770_1_LENGTH (176 / 8)
// length of D_8012C770[2]
#define D_8012C770_2_LENGTH (256 / 8)

// Returns a single bit from a byte array
s32 bitfield_get_bit(u8 *array, s32 index) {
    s32 ret;
    if (array[index / 8] & (1 << (index & 7))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

// Extracts an integer of the given number of bits from a byte array at the starting bit index
s32 bitfield_get_n_bits(u8 *array, s32 startIndex, s32 length) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < length; i++) {
        ret |= (bitfield_get_bit(array, startIndex + i) << i);
    }
    return ret;
}

// Sets or clears a single bit in a byte array
void bitfield_set_bit(u8 *array, s32 index, s32 set) {
    if (set) {
        array[index / 8] |=  (1 << (index & 7));
    } else {
        array[index / 8] &= ~(1 << (index & 7));
    }
}

// Sets or clears a range of bits in a byte array
void bitfield_set_n_bits(u8 *array, s32 startIndex, s32 set, s32 length) {
    s32 i;

    for (i = 0; i < length; i++) {
        bitfield_set_bit(array, startIndex + i, (1 << i) & set);
    }
}

void func_800D9FFC(void) {
    s32 i;
    s32 sp28[1];
    sp28[0] = D_8011B994;
    for (i = 0; i < ARRLEN(sp28); i++) {
        func_800DA524(sp28[i]);
    }
}

void func_800DA048(void) {
    D_8011B990 = 0;
}

void func_800DA054(s32 arg0, s32 length) {
    if (D_8012C770[arg0] == NULL) {
        D_8012C770[arg0] = heap_alloc_sided(length, 0);
    }
    rare_memset(D_8012C770[arg0], 0, length);
}

void func_800DA0B4(void) {
    func_800DA054(0, D_8012C770_0_LENGTH);
}

void func_800DA0D8(void) {
    func_800DA054(1, D_8012C770_1_LENGTH);
    _gldbDll_entrypoint_2();
}

void func_800DA104(void) {
    func_800DA054(2, D_8012C770_2_LENGTH);
    _gldbDll_entrypoint_1();
}

void func_800DA130(void) {
    if (func_8001210C(0x3FF) == 0x3FF) {
        _gldbDll_entrypoint_2();
    }
    else if (func_8001210C(0x7FF) == 0x7FF) {
        // Unreachable? If the 0x3FF check fails, then the 0x7FF check will fail too. 
        _gldbDll_entrypoint_1();
    }
}

void func_800DA188(void) {
    s32 i;
    
    for (i = 0; i < ARRLEN(D_8012C770); i++) {
        if (D_8012C770[i] != NULL) {
            heap_free(D_8012C770[i]);
            D_8012C770[i] = NULL;
        }
    }
}

void func_800DA1E0(void) {
    s32 i;
    
    for (i = 0; i < ARRLEN(D_8012C770); i++) {
        if (D_8012C770[i] != NULL) {
            D_8012C770[i] = defrag(D_8012C770[i]);
        }
    }
}

void func_800DA238(void) {
    s32 i;
    
    for (i = 0; i < ARRLEN(D_8012C780); i++) {
        D_8012C780[i] = 0;
    }
}

void func_800DA268(void) {
    s32 i;
    
    for (i = 0; i < ARRLEN(D_8012C78C); i++) {
        D_8012C78C[i] = 0;
    }
}

s32 func_800DA298(s32 index) {
    if ((index >= 0) && (index < 32)) {
        return ((1 << index) & D_8011B990) ? 1 : 0;
    }
    if ((index > 40) && (index < 1445)) {
        return bitfield_get_bit(D_8012C770[0], index - 40);
    }
    if ((index > 1600) && (index < 1773)) {
        return bitfield_get_bit(D_8012C770[1], index - 1600);
    }
    if ((index > 2500) && (index < 2756)) {
        return bitfield_get_bit(D_8012C770[2], index - 2500);
    }
    if ((index > 3000) && (index < 3094)) {
        return bitfield_get_bit(D_8012C780, index - 3000);
    }
    if ((index > 3400) && (index < 3445)) {
        return bitfield_get_bit(D_8012C78C, index - 3400);
    }
    return 0;
}

void func_800DA3B8(s32 index, s32 set) {
    if ((index >= 0) && (index < 32)) {
        if (set != 0) {
            D_8011B990 |= 1 << index;
        }
        else {
            D_8011B990 &= ~(1 << index);
        }
    }
    else if ((index > 40) && (index < 1445)) {
        bitfield_set_bit(D_8012C770[0], index - 40, set);
    }
    else if ((index > 1600) && (index < 1773)) {
        bitfield_set_bit(D_8012C770[1], index - 1600, set);
    }
    else if ((index > 2500) && (index < 2756)) {
        bitfield_set_bit(D_8012C770[2], index - 2500, set);
    }
    else if ((index > 3000) && (index < 3094)) {
        if (bitfield_get_bit(D_8012C780, index - 3000) != set) {
            func_800DA544(3412);
        }
        bitfield_set_bit(D_8012C780, index - 3000, set);
    }
    else if ((index > 3400) && (index < 3445)) {
        bitfield_set_bit(D_8012C78C, index - 3400, set);
    }
}

void func_800DA524(s32 index) {
    func_800DA3B8(index, 0);
}

void func_800DA544(s32 index) {
    func_800DA3B8(index, 1);
}

s32 func_800DA564(s32 startIndex, s32 length) {
    if ((startIndex >= 0) && (startIndex < 32)) {
        s32 ret = 0;
        s32 i;

        for (i = 0; i < length; i++) {
            ret |= ((D_8011B990 & (1 << (startIndex + i))) ? 1 : 0) << i;
        }
        return ret;
    }
    else if ((startIndex > 40) && (startIndex < 1445)) {
        return bitfield_get_n_bits(D_8012C770[0], startIndex - 40, length);
    }
    else if ((startIndex > 1600) && (startIndex < 1773)) {
        return bitfield_get_n_bits(D_8012C770[1], startIndex - 1600, length);
    }
    else if ((startIndex > 2500) && (startIndex < 2756)) {
        return bitfield_get_n_bits(D_8012C770[2], startIndex - 2500, length);
    }
    else if ((startIndex > 3000) && (startIndex < 3094)) {
        return bitfield_get_n_bits(D_8012C780, startIndex - 3000, length);
    }
    else if ((startIndex > 3400) && (startIndex < 3445)) {
        return bitfield_get_n_bits(D_8012C78C, startIndex - 3400, length);
    }
    else {
        return 0;
    }
}

void func_800DA7A8(s32 startIndex, s32 set, s32 length) {
    if ((startIndex >= 0) && (startIndex < 32)) {
        s32 i = 0;
        for (i = 0; i < length; i++) {
            func_800DA3B8(startIndex + i, (1 << i) & set);
        }
    } else if ((startIndex > 40) && (startIndex < 1445)) {
        bitfield_set_n_bits(D_8012C770[0], startIndex - 40, set, length);
    }
    else if ((startIndex > 1600) && (startIndex < 1773)) {
        bitfield_set_n_bits(D_8012C770[1], startIndex - 1600, set, length);
    }
    else if ((startIndex > 2500) && (startIndex < 2756)) {
        bitfield_set_n_bits(D_8012C770[2], startIndex - 2500, set, length);
    }
    else if ((startIndex > 3000) && (startIndex < 3094)) {
        if (bitfield_get_n_bits(D_8012C780, startIndex - 3000, length) != set) {
            func_800DA544(0xD54);
        }
        bitfield_set_n_bits(D_8012C780, startIndex - 3000, set, length);
    }
    else if ((startIndex > 3400) && (startIndex < 3445)) {
        bitfield_set_n_bits(D_8012C78C, startIndex - 3400, set, length);
    }
}

s32 func_800DA944(s32 startIndex, s32 length) {
    s32 ret = func_800DA564(startIndex, length) + 1;
    func_800DA7A8(startIndex, ret, length);
    return ret;
}

s32 func_800DA980(s32 startIndex, s32 length) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < length; i++) {
        ret += func_800DA298(i + startIndex);
    }

    return ret;
}

s32 func_800DA9E4(s32 index, s32 set) {
    s32 ret = func_800DA298(index);
    func_800DA3B8(index, set);
    return ret;
}

s32 func_800DAA1C(void) {
    return D_8011B990;
}

void func_800DAA28(s32 val) {
    D_8011B990 = val;
}

typedef struct {
    s32 num_bits;
    u32 unk4[];
} BitFieldBuffer;

BitFieldBuffer* func_800DAA34(s32 num_bits) {
    BitFieldBuffer* ret = heap_alloc(((num_bits + 31) >> 5) * sizeof(u32) + sizeof(BitFieldBuffer));
    ret->num_bits = num_bits;
}

void func_800DAA6C(BitFieldBuffer* bitfield) {
    heap_free(bitfield);
}

void func_800DAA8C(BitFieldBuffer* bitfield, s32 arg1, s32 length) {
    s32 i;

    bitfield->num_bits = arg1;
    for (i = 1; i < length; i++) {
        bitfield->unk4[i - 1] = 0;
    }
}

void func_800DAAF8(BitFieldBuffer* bitfield, s32 index, s32 set) {
    if (set) {
        bitfield->unk4[index >> 5] |= 1 << (index & 0x1F);
    }
    else {
        bitfield->unk4[index >> 5] -= (bitfield->unk4[index >> 5] & (1 << (index & 0x1F)));
    }
}

s32 func_800DAB54(BitFieldBuffer* bitfield, s32 index) {
    return (bitfield->unk4[index >> 5] & (1 << (index & 0x1F))) ? 1 : 0;
}

void func_800DAB8C(BitFieldBuffer* bitfield, s32 set) {
    s32 i;
    for (i = 0; i < bitfield->num_bits; i++) {
        func_800DAAF8(bitfield, i, set);
    }
}

void func_800DABF0(s32* arg0, u8** arg1) {
    *arg0 = ARRLEN(D_8012C780);
    *arg1 = D_8012C780;
}

s32 func_800DAC08(void) {
    return D_8012C770_0_LENGTH;
}

void func_800DAC10(u8* src, s32 length) {
    s32 length_clamped;
    length_clamped = MIN(D_8012C770_0_LENGTH, length);
    rare_memcpy(D_8012C770[0], src, length_clamped);
}

void func_800DAC50(u8* dst) {
    rare_memcpy(dst, D_8012C770[0], D_8012C770_0_LENGTH);
}

s32 func_800DAC78(u8* arg0, s32 arg1) {
    s32 sp1C;
    u32 sp18;
    if (_glgamedata_entrypoint_3(arg0, 6, &sp1C, &sp18)) {
        return bitfield_get_bit(arg0 + sp1C, arg1 - 0x28);
    }
    else {
        return -1;
    }
}
