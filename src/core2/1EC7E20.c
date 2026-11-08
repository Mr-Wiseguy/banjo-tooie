#include "common.h"
#include "core2/1EC7E20.h"

extern void (*D_80123590[])(void *);
extern Vector *D_80127EF8;
extern u8 D_80135483;

void func_800EE530(unkStruct800EE530* arg0) {
    arg0->unk2C = defrag(arg0->unk2C);
}

void func_800EE55C(unkStruct800EE530 *arg0) {
    s32 sp1C;
    s32 temp_a0;
    s32 new_var;
    s32 temp_v0;
    new_var = arg0->unk24; sp1C = (arg0->unk2C - new_var) >> 2;
    arg0->unk24 = defrag(new_var);
    arg0 = arg0;
    arg0->unk2C = arg0->unk24 + (sp1C << 2);
}

void func_800EE5AC(unkStruct800EE530* arg0) {
    arg0->unk24 = defrag(arg0->unk24);
}

s32 func_800EE5D8(s32 arg0) 
{
    s32 var_a3;
    unkStruct800EE530 *var_s0;
    u32 temp_s2;

    var_a3 = defrag(arg0);
    if (D_80127EF8 != 0 && var_a3 != arg0) 
    {
        temp_s2 = (void*)vector_end(D_80127EF8);
        for (var_s0 = vector_begin(D_80127EF8); (s32)var_s0 < temp_s2; var_s0++)
        {
            if (var_s0->unk0 == arg0)
            {
                var_s0->unk0 = var_a3;
            }
        }
    }

    return var_a3;
}

void func_800EE670(void) 
{
    u32 temp_s2;
    unkStruct800EE530 *var_s0;

    if (D_80127EF8 != 0) 
    {
        temp_s2 = (void*)vector_end(D_80127EF8);
        for (var_s0 = vector_begin(D_80127EF8); (s32)var_s0 < temp_s2; var_s0++)
        {

            if (D_80123590[var_s0->unk6] != NULL) 
            {
                //This function has been func_800EE530 everytime I have seen it called
                D_80123590[var_s0->unk6](&var_s0->unk8);
            }
        }

        D_80127EF8 = vector_defrag(D_80127EF8);
    }
}

void func_800EE718(void) {
    if (D_80135483 != 0) {
        _idbounce_entrypoint_6();
    }
}

void func_800EE748(void) {
    if (D_80135483 != 0) {
        _idbounce_entrypoint_7();
    }
}
