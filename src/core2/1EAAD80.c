#include "core2/1EAAD80.h"

typedef struct {
    s16 unk0[];
}Inventory;
typedef struct {
    Inventory* inventory;
    s32 unk4;
}UNKD_8012B250;

extern UNKD_8012B250 D_8012B250;
extern s16 D_8011AE50[][2];
extern s16 D_8011AF50[][2];

//Make the code for inventory_getValue the starting values for the inventory
void inventory_init()
{
    s32 index;
    for (index = 0; index < 0x15; index++)
    {
        D_8012B250.inventory->unk0[index] = ((s16*)&inventory_getValue)[index * 0x4];
    }
}

void inventory_setup(void)
{
    D_8012B250.unk4 = 0;
    D_8012B250.inventory = heap_alloc_sided(0x2A, D_8012B250.unk4);
    inventory_init();
}

void func_800D154C(void)
{
    Inventory* sp1C;

    if (func_8001210C(0x3FF) == 0x1FF)
    {
        sp1C = D_8012B250.inventory;
        D_8012B250.unk4++;
        if (D_8012B250.unk4 == 3)
        {
            D_8012B250.unk4 = 0;
        }
        D_8012B250.inventory = heap_alloc_sided(0x2A, D_8012B250.unk4);
        rare_memcpy(D_8012B250.inventory, sp1C, 0x2A);
        heap_free(sp1C);
    }
}

void inventory_defrag(void) 
{
    if (D_8012B250.inventory != 0)
    {
        D_8012B250.inventory = defrag(D_8012B250.inventory);
    }
}

void inventory_free(void)
{
    heap_free(D_8012B250.inventory);
    D_8012B250.inventory = NULL;
}


void func_800D162C(void)
{
    s32 index;
    for (index = 0; index < 0x15; index++)
    {
        func_800D2770(D_8011AF50[index][0], D_8012B250.inventory->unk0[index] ^ ((s16*)&inventory_getValue)[index * 0x4]);
    }
}

s32 inventory_getIndex(s32 arg0)
{
    return arg0 - 0x40;
}


void inventory_setValue(s32 inventoryIndex, s32 newValue)
{
    if (D_8011AF50[inventoryIndex][1] == -2)
    {
        D_8012B250.inventory->unk0[inventoryIndex] = ((s16*)&inventory_getValue)[inventoryIndex * 4] ^ 0x3E7;
        return;
    }
    if (newValue < 0)
    {
        newValue = 0;
    }
    if ((D_8011AF50[inventoryIndex][1] >= 0) && D_8011AF50[inventoryIndex][1] < newValue)
    {
        newValue = D_8011AF50[inventoryIndex][1];
    }
    D_8012B250.inventory->unk0[inventoryIndex] = ((s16*)&inventory_getValue)[inventoryIndex * 4] ^ newValue;
}

void inventory_addValue(s32 inventoryId, s32 amountToAdd)
{
    s32 inventoryIndex;

    inventoryIndex = inventory_getIndex(inventoryId);
    inventory_setValue(inventoryIndex, (D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4]) + amountToAdd);
    func_800D24E8(D_8011AF50[inventoryIndex][0], D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4], 0);
}

void inventory_decrementValue(s32 inventoryId)
{
    inventory_addValue(inventoryId, -1);
}

void inventory_showValue(s32 inventoryId)
{
    inventory_addValue(inventoryId,0);
}

void inventory_incrementValue(s32 inventoryId)
{
    inventory_addValue(inventoryId,1);
}

void func_800D1864(u32 inventoryId, u32 valueToSet, u32 arg2)
{
    s32 inventoryIndex;

    inventoryIndex = inventory_getIndex(inventoryId);
    inventory_setValue(inventoryIndex, valueToSet);
    if (arg2 != 0)
    {
        func_800D2498(D_8011AF50[inventoryIndex][0], D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4], D_8011AF50[inventoryIndex][1]);
        return;
    }
    func_800D2770(D_8011AF50[inventoryIndex][0], D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4]);
}

void func_800D192C(s32 inventoryId, u32 arg1)
{
    func_800D1864(inventoryId, inventory_getValue(inventoryId), arg1);
}

void func_800D1960(s32 inventoryId, s32 arg1, s32 arg2)
{
    s32 inventoryIndex;
    u32 valueToSet;

    inventoryIndex = inventory_getIndex(inventoryId);
    if ((arg1 <= 0) && (arg1 != -2))
    {
        arg1 = 1;
    }
    D_8011AF50[inventoryIndex][1] = arg1;
    if (arg2 != 0)
    {
        valueToSet = func_800D1A6C(inventoryId);
    }
    else
    {
        valueToSet = D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4];
    }
    inventory_setValue(inventoryIndex, (s32)valueToSet);
}

s32 inventory_getValue(s32 inventoryId)
{
    s32 inventoryIndex;

    inventoryIndex = inventory_getIndex(inventoryId);
    if (D_8011AF50[inventoryIndex][1] == -2)
    {
        return 0x3E7;
    }
    return D_8012B250.inventory->unk0[inventoryIndex] ^ ((s16*)&inventory_getValue)[inventoryIndex * 4];
}


u32 func_800D1A6C(u32 inventoryId)
{
    s32 inventoryIndex;

    inventoryIndex = inventory_getIndex(inventoryId);
    switch (D_8011AF50[inventoryIndex][1])
    {
    case -1:
        return 0x32U;

    case -2:
        return 0x3E7U;
    default:
        break;
    }
    return D_8011AF50[inventoryIndex][1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1ACC.s")

s32 func_800D1B34(s32 arg0)
{
    switch (arg0)
    {
    case 0x29F:
        return 0x48;
    case 0x523:
        return 0x54;
    case 0x1D9:
        return 0x4F;
    case 0x3CA:
        return 0x4B;
    case 0x3CB:
        return 0x4C;
    case 0x40D:
    case 0x481:
        return 0x50;
    case 0x4E2:
        return 0x4D;
    case 0x4E3:
        return 0x4A;
    case 0x4E4:
        return 0x4E;
    case 0x4BA:
    case 0x4D7:
        return 0x51;
    case 0x515:
    case 0x516:
        return 0x52;
    case 0x4B7:
        return 0x49;
    default:
        return 0;
    }
}

s32 inventory_hasZeroItems(s32 inventoryId)
{
    return inventory_getValue(inventoryId) == 0;
}

s32 func_800D1C5C(u32 arg0)
{
    return D_8011AE50[arg0][0];
}

s32 func_800D1C70() 
{
    return 0x2A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1F34.s")
