#include "core2/1ECE0B0.h"
extern Unk80135490 D_80135490;
extern u8 D_801354DA;
extern Vector* D_801354F0;
extern u32 D_801354DC;
extern unkStructD_801354F8 D_801354F8;
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;
extern f32 D_80135500[3];
extern s8 D_801354B0;
extern f32 D_80135510[3];
extern u8 D_801354FA;
extern s32 D_8013551C;
extern unkStructD_80135520 D_80135520;
extern u8 D_8012762C;
extern f32 D_8013550C;
extern u8 D_801354B8[];
extern u8 D_801354D9;
extern u8 D_80135521;
extern u8 D_80135522;
extern u8 D_80135498;

//Call a function on all active players
void func_800F47C0(void (*arg0)(PlayerState*))
{
    PlayerState* temp_a0;
    s32 index;

    for (index = 0; index < 0x8; index++)
    {
        if (D_80135490.unk0[index] != NULL && D_80135490.unk0[index]->unk17C)
            arg0(D_80135490.unk0[index]);
    }
}

void transformation_destroy(TransformationId arg0)
{
    s32 index;

    for (index = 0; index < 8; index++)
    {
        if (D_80135490.unk0[index] != NULL)
        {
            if (arg0 == 0 || player_getTransformation(D_80135490.unk0[index]) == arg0)
            {
                player_destroy(D_80135490.unk0[index]);
                func_800A91F4(index);
                D_80135490.unk0[index] = NULL;
            }
        }
    }
}

void func_800F48BC(s32 arg0, f32* arg1)
{
    f32 sp2C[3];
    f32 sp20[3];
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_800F4200(sp1C, sp2C);
    func_800EFA20(sp20, arg1, time_getDelta());
    ml_vec3f_add(sp2C, sp20);
    func_800F4648(sp1C, sp2C);
}

void character_affectCurrentHealth(s32 charIndex,s32 a1)
{
    player_affectCurrentHealth(D_80135490.unk0[charIndex],a1);
}

void func_800F4950(s32 arg0)
{
    _baattach_entrypoint_2(D_80135490.unk0[arg0]);
}

void func_800F497C(s32 arg0)
{
    _badrone_entrypoint_5(D_80135490.unk0[arg0]);
}

void func_800F49A8(s32 arg0,s32 arg1)
{
    _badrone_entrypoint_10(D_80135490.unk0[arg0], arg1);
}

void func_800F49D4(s32 arg0,void* arg1,s32 arg2)
{
    _badrone_entrypoint_11(D_80135490.unk0[arg0],arg1,arg2);
}

void func_800F4A00(s32 arg0, s32 arg1)
{
    _badrone_entrypoint_12(D_80135490.unk0[arg0],arg1);
}

void func_800F4A2C(s32 arg0,f32* arg1)
{
    _badrone_entrypoint_13(D_80135490.unk0[arg0],arg1);
}


void func_800F4A58(s32 arg0, s32 arg1, f32 arg2) {
    _badrone_entrypoint_14(D_80135490.unk0[arg0], arg1, arg2);
}

void func_800F4A8C(s32 arg0, s32 arg1, f32 arg2) {
    _badrone_entrypoint_15(D_80135490.unk0[arg0], arg1, arg2);
}

void func_800F4AC0(s32 arg0, s32 arg1, f32 arg2) {
    _badrone_entrypoint_16(D_80135490.unk0[arg0], arg1, arg2);
}

void func_800F4AF4(s32 arg0,s32 arg1)
{
    func_800A4DA4(D_80135490.unk0[arg0],arg1);
}

void func_800F4B20(s32 arg0)
{
    func_800A4E30(D_80135490.unk0[arg0]);
}

s32 func_800F4B4C(s32 arg0) {
    s32 var_v1;

    if (func_8009E674(D_80135490.unk0[arg0], 0x200000) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800F4B8C(u32 a0, u32 a1, s32 a2)
{
    return func_800F3930(D_80135490.unk0[a0],a1,a2);
}

s32 func_800F4BB8(u32 arg0, u32 arg1, s32 arg2)
{
    return func_800F3A78(D_80135490.unk0[arg0],arg1,arg2);
}

s32 func_800F4BE4(s32 arg0) {
    s32 var_v1;

    if (func_8009E674(D_80135490.unk0[arg0], 0x20000) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800F4C24(s32 arg0) {
    PlayerState* sp1C;
    s32 temp_v0;

    sp1C = D_80135490.unk0[arg0];
    if (func_800F6D24(arg0) != 0) {
        return 0;
    }
    if (func_800F68B8(arg0) != 0) {
        return 0;
    }
    if (func_800F6CC8((u32) arg0) != 0) {
        return 0;
    }
    temp_v0 = bs_getCurrentState(sp1C);
    if ((temp_v0 == 0xED) || (temp_v0 == 0x157)) {
        return 0;
    }
    return 1;
}

void func_800F4CC0(s32 arg0)
{
    func_80091E6C(D_80135490.unk0[arg0]);
}

void func_800F4CEC(s32 arg0,u32 arg1)
{
    func_80091E48(D_80135490.unk0[arg0],arg1);
}

void func_800F4D18(s32 arg0, s32 arg1, s32 arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009F678(sp1C, arg1, arg2, player_getSpeedModifier(sp1C) * 1000.0f);
}

void func_800F4D74(s32 arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp34[3];
    f32 sp28[3];
    PlayerState* sp24;

    sp24 = D_80135490.unk0[arg0];
    ml_vec3f_assign_value(sp34, arg1->pos.x - arg2, arg1->pos.y - arg3, arg1->pos.z - arg4);
    ml_vec3f_assign_value(sp28, arg1->pos.x + arg2, arg1->pos.y + arg3, arg1->pos.z + arg4);
    func_8009F678(sp24, sp34, sp28, player_getSpeedModifier(sp24) * 1000.0f);
}

void func_800F4E5C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    PlayerState* sp24;

    sp24 = D_80135490.unk0[arg0];
    func_8009F440(sp24, arg1, arg2, arg3, arg4, player_getSpeedModifier(sp24) * 1000.0f);
}

void func_800F4EC8(s32 arg0, s32 arg1, s32 arg2, volatile s32 arg3, f32 arg4) {
    PlayerState* sp24;

    sp24 = D_80135490.unk0[arg0];
    func_8009F860(sp24, arg1, arg2, arg3, arg4, player_getSpeedModifier(sp24) * 1000.0f);
}

void func_800F4F34(s32 arg0, f32* arg1, f32 arg2, f32 arg3) {
    PlayerState* sp24;

    sp24 = D_80135490.unk0[arg0];
    func_8009FA20(sp24, arg1, arg2, arg3, player_getSpeedModifier(sp24) * 1000.0f);
}

void func_800F4F98(s32 arg0)
{
    _baattach_entrypoint_5(D_80135490.unk0[arg0]);
}

void func_800F4FC4(void) {
    s32 temp_v0;

    temp_v0 = _character_findCharOfTransform(TRANSFORM_11_CLOCKWORK);
    if (temp_v0 != -1) {
        func_800F7B9C(temp_v0, 0x1FU);
    }
    event_sendToActorsOfType(PROP_15E_CLOCKWORK_EGG, 0x2C, 0);
}


void func_800F5008(s32 arg0) 
{
    s32 temp;
    PlayerState* playerState;
    s32 count;
    s32 i;

    for (i = 0, count = 0; i < 8; i++) {
        playerState = D_80135490.unk0[i];
        if (playerState != NULL && playerState->unk17C != 0) {
            // yummy fake ^0
            if ((func_80092258(playerState)^0) == 0xFF) {
                func_80098BA8(playerState, arg0);
            } 
            else 
            {
                D_80135490.unk28[count] = playerState;
                count++;
            }
        }
    }
    D_80135490.unk48 = count;
}


void func_800F50D0(s32 arg0) {
    s32 pad[2];
    s32 var_s0;
    f32 sp38;

    if (D_80135490.unk48 != 0)
    {
        func_800CA7E4(func_800A8984(func_800A89F8()), &sp38);
        _bainvisible_entrypoint_9(D_80135490.unk28, D_80135490.unk48, &sp38);
        for (var_s0 = 0; var_s0 < D_80135490.unk48; var_s0++)
        {
            func_80098BA8(D_80135490.unk28[var_s0], arg0);
        }
    }
}

void func_800F5184(void) {
    func_800F47C0(func_80093528);
}

void func_800F51A8(void) {
    func_800F47C0(func_80093584);
}

void func_800F51CC(void) {
    func_800F47C0(func_80098BE0);
}

void func_800F51F0(s32 arg0, s32 arg1, s32 arg2)
{
    func_80093504(D_80135490.unk0[arg0], arg1, arg2);
}

void func_800F521C(s32 arg0, s32 arg1) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    bs_setState(sp1C, _badata_entrypoint_35(sp1C));
    func_800F457C(sp1C, arg1);
}

s32 func_800F5268(s32 arg0) {
    if (_bafpctrl_entrypoint_4(D_80135490.unk0[arg0]) != 3) {
        return 0;
    }
    if (_bafpctrl_entrypoint_5 != NULL) {
        return 2;
    }
    return 1;
}

void func_800F52B8(s32 arg0,s32 arg1)
{
    func_8008EF3C(D_80135490.unk0[arg0],arg1);
}

void func_800F52E4(s32 arg0)
{
    func_8008F4F0(D_80135490.unk0[arg0]);
}

s32 func_800F5310(void) {
    int index;
    s32 count;
    count = 0;
    for (index = 0; index < 8; index++) 
    {
        if (D_80135490.unk0[index] != NULL)
        {
            count++;
        }
    }
    return count;
}

AnimCtrl* func_800F5378(s32 arg0)
{
    return baanim_getAnimCtrlPtr(D_80135490.unk0[arg0]);
}

void func_800F53A4(s32 arg0)
{
    func_8008E938(D_80135490.unk0[arg0]);
}

PlayerState* character_getPlayerState(s32 arg0) {
    return D_80135490.unk0[arg0];
}

PlayerState* character_getPlayerStateBounded(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 8)) {
        return D_80135490.unk0[arg0];
    }
    return NULL;
}

TransformationId character_getTransform(s32 arg0)
{
    return player_getTransformation(D_80135490.unk0[arg0]);
}

s32 character_getTransformBit(s32 arg0)
{
    return 1 << (player_getTransformation(D_80135490.unk0[arg0]) + 0x1F);
}

void func_800F5470(s32 arg0,f32* arg1)
{
    func_80098590(D_80135490.unk0[arg0],arg1);
}

f32 func_800F549C(s32 arg0, s32 arg1) {
    PlayerState* temp_a2;

    temp_a2 = D_80135490.unk0[arg0];
    if (temp_a2 != NULL) {
        return bastatetimer_get(temp_a2, arg1);
    }
    return 0.0f;
}

//Get Which Character is in Control
u32 character_getActiveIndex(void) 
{
	return D_801354DC;
}

s32 character_getControllerIndex(s32 arg0)
{
    return bakey_getControllerIndex(D_80135490.unk0[arg0]);
}

void func_800F551C(s32 arg0, f32* arg1, f32* arg2, f32* arg3) {
    func_800A3148(D_80135490.unk0[arg0], arg1, arg2, arg3);
}

void func_800F554C(s32 arg0)
{
    func_80092BDC(D_80135490.unk0[arg0]);
}

s32 character_getCurrentHealth(s32 arg0)
{
    return player_getCurrentHealth(D_80135490.unk0[arg0]);
}

s32 character_getMaxHealth(s32 arg0)
{
    return player_getMaxHealth(D_80135490.unk0[arg0]);
}

Unk80132ED0* func_800F55D0(s32 arg0)
{
    return func_800965D4(D_80135490.unk0[arg0]);
}

s32 func_800F55FC(s32 arg0)
{
    return func_80096628(D_80135490.unk0[arg0]);
}

f32 character_getGroundHeight(s32 arg0)
{
    return player_getGroundHeight(D_80135490.unk0[arg0]);
}

void func_800F5654(s32 arg0)
{
    func_80096670(D_80135490.unk0[arg0]);
}

void func_800F5680(s32 arg0,f32 arg1[3])
{
    func_800963C0(D_80135490.unk0[arg0],arg1);
}

s32 func_800F56AC(s32 arg0)
{
    return func_80096694(D_80135490.unk0[arg0]);
}

Unk80132ED0* func_800F56D8(s32 arg0)
{
    return _bahold_entrypoint_5(D_80135490.unk0[arg0]);
}

u32 func_800F5704(s32 arg0) {
    Unk80132ED0* temp;

    temp = _bahold_entrypoint_5(D_80135490.unk0[arg0]);
    if (temp != NULL) {
        return func_80106790(temp)->unk6C_9;
    }
    return 0;
}

u32 func_800F5754(s32 arg0) {
    Unk80132ED0* temp;

    temp = _bahold_entrypoint_5(D_80135490.unk0[arg0]);
    if (temp != NULL) {
        return temp->unk24_22;
    }
    return 0;
}

void func_800F5794(s32 arg0)
{
    func_800F3B3C(D_80135490.unk0[arg0]);
}

void func_800F57C0(s32 arg0) {
    s32 sp18[2];

    func_8008E9B8(D_80135490.unk0[arg0], sp18);
}

void func_800F57F0(s32 arg0, f32* arg1)
{
    func_800F3B90(D_80135490.unk0[arg0],arg1);
}

s32 func_800F581C(s32 arg0) {
    PlayerState* sp1C;
    s32 var_v1;
    sp1C = D_80135490.unk0[arg0];
    if (func_8009650C(sp1C) != 0) {
        var_v1 = func_80096434(sp1C);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800F586C(s32 arg0,f32* arg1, f32* arg2)
{
    func_80098B5C(D_80135490.unk0[arg0],arg1,arg2);
}

s32 character_getMaxCharacters(void) 
{
	return 8;
}

void func_800F58A0(s32 arg0)
{
    _bswalk_entrypoint_0(D_80135490.unk0[arg0]);
}

void func_800F58CC(s32 arg0,f32* arg1)
{
    func_80096394(D_80135490.unk0[arg0],arg1);
}

s32 func_800F58F8(s32 arg0)
{
    return func_800A3354(D_80135490.unk0[arg0]);
}

s32 func_800F5924(s32 arg0)
{
    return func_800A3360(D_80135490.unk0[arg0]);
}

void func_800F5950(s32 arg0, f32* arg1, f32* arg2, f32* arg3) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    func_800A3148(D_80135490.unk0[arg0], &sp24, &sp20, &sp1C);
    *arg1 = (sp1C * 0.5f) + sp20;
    *arg2 = sp20 - (sp1C * 0.5f);
    *arg3 = sp24;
}

void func_800F59D4(s32 arg0)
{
    _bapackctrl_entrypoint_1(D_80135490.unk0[arg0]);
}

void character_getCoords(s32 charIdx,f32* a1)
{
    player_getCoords_Dupe(D_80135490.unk0[charIdx],a1);
}

void func_800F5A2C(s32 charIdx, s32 arg1, f32* arg2)
{
    func_800F3BD0(D_80135490.unk0[charIdx], arg1, arg2);
}

void character_getCoords3s(s32 charIdx, s32* arg1) {
    f32 sp1C[3];

    player_getCoords_Dupe(D_80135490.unk0[charIdx], sp1C);
    arg1[0] = (s32)sp1C[0];
    arg1[1] = (s32)sp1C[1];
    arg1[2] = (s32)sp1C[2];
}

f32 func_800F5AD0(s32 arg0) {
    return 4.0f;
}

f32 func_800F5AE0(s32 arg0)
{
    return func_8009BFCC(D_80135490.unk0[arg0]);
}

s32 func_800F5B0C(s32 arg0)
{
    return func_8009CC68(D_80135490.unk0[arg0]);
}

void func_800F5B38(s32 arg0, f32* arg1)
{
    func_800F3E84(D_80135490.unk0[arg0], arg1);
}

f32 func_800F5B64(s32 arg0, f32* arg1) {
    f32 sp24;
    f32 sp20;
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_80095870(sp1C, &sp20, &sp24);
    player_getCoords(sp1C, arg1);
    arg1[1] += sp20;
    return sp24;
}

void func_800F5BC4(s32 arg0,f32* arg1)
{
    func_80092B8C(D_80135490.unk0[arg0],arg1);
}



f32 func_800F5BF0(s32 arg0, f32* arg1) {
    f32 sp2C;
    f32 sp20[3];
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    sp2C = func_80092B8C(sp1C, arg1);
    player_getCoords(sp1C, sp20);
    ml_vec3f_add(arg1, sp20);
    return sp2C;
}

f32 func_800F5C44(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    if (player_getTransformation(sp1C) != TRANSFORM_2_SNOWBALL) {
        return 0.0f;
    }
    return _basnowball_entrypoint_4(sp1C);
}

void func_800F5C94(s32 arg0)
{
    func_800F3ED0(D_80135490.unk0[arg0]);
}

void func_800F5CC0(s32 arg0)
{
    bastick_getAngle(D_80135490.unk0[arg0]);
}

void func_800F5CEC(s32 arg0)
{
    bastick_distance(D_80135490.unk0[arg0]);
}

s32 func_800F5D18(s32 arg0)
{
    return func_800F40EC(D_80135490.unk0[arg0]);
}

void func_800F5D44(s32 arg0, f32* arg1) 
{
    func_800A33CC(D_80135490.unk0[arg0],arg1);
}

void func_800F5D70(s32 arg0, f32* arg1)
{
    func_8009BB24(D_80135490.unk0[arg0],arg1);
}

void func_800F5D9C(s32 arg0, f32* arg1)
{
    func_800F4200(D_80135490.unk0[arg0],arg1);
}

void func_800F5DC8(s32 arg0, Vec3f* arg1) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    arg1->pos.x = func_8009BFD8(sp1C);
    arg1->pos.y = yaw_getIdeal(sp1C);
    arg1->pos.z = baroll_getIdeal(sp1C);
}

void func_800F5E24(s32 arg0)
{
    func_800966BC(D_80135490.unk0[arg0]);
}

void func_800F5E50(s32 arg0)
{
    func_800966E0(D_80135490.unk0[arg0]);
}

void func_800F5E7C(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    if (func_80096544(sp1C) != 0) {
        player_getWaterHeight(sp1C);
        return;
    }
    player_getCoordVertical(sp1C);
}

void func_800F5ECC(s32 arg0)
{
    func_800A4C68(D_80135490.unk0[arg0]);
}

s32 func_800F5EF8(s32 arg0)
{
    return func_800A4C88(D_80135490.unk0[arg0]);
}

f32 func_800F5F24(u32 arg0)
{
    return yaw_get(D_80135490.unk0[arg0]);
}

f32 func_800F5F50(s32 arg0)
{
    return yaw_getIdeal(D_80135490.unk0[arg0]);
}

f32 func_800F5F7C(s32 charIndex)
{
    return player_getCoordVertical(D_80135490.unk0[charIndex]);
}

s32 func_800F5FA8(s32 arg0) {
    bakey_setState(D_80135490.unk0[arg0], BUTTON_B, 2);
    return 1;
}

s32 func_800F5FE0(s32 arg0) {
    bakey_setState(D_80135490.unk0[arg0], BUTTON_B, 0);
    return 1;
}

void func_800F6018(s32 arg0) {
    bakey_setState(D_80135490.unk0[arg0], BUTTON_A, 2);
}

void func_800F604C(PlayerState* arg0, s32 arg1) {
    func_8009EAD0(arg1);
    bs_setState(arg0, _badata_entrypoint_35(arg0));
    func_8009EAD0(1);
}

#ifndef NON_MATCHING 
// When I add this to my .c, the rom differs. Not entirely sure why. I updated my context file as well.
// Likely a jump table issue.

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F608C.s")
#else
void func_800F608C(s32 arg0, s32 arg1) {
    PlayerState* refPlayer = D_80135490.unk0[arg0];
    switch (arg1) {
        case 1:
            bs_setState(refPlayer, _badata_entrypoint_35(refPlayer));
            break;
        case 2:
            func_800F604C(refPlayer, 4);
            break;
        case 3:
            func_800F604C(refPlayer, 3);
            break;
        case 4:
            func_800F604C(refPlayer, 2);
            break;
        case 5:
            func_800F604C(refPlayer, 5);
            break;
    }
}
#endif


s32 func_800F6140(s32 arg0) {
    s32 i = 0;
    s32 temp;

    for(i=0;i<8;i++) 
    {
        if (D_80135490.unk0[i] == NULL) 
        {
            temp = func_800A907C(i, arg0, -1);
            func_800A9768(temp);
            func_800A93F8(i);
            func_800A93E4(i);
            D_80135490.unk0[i] = func_800F43A8(i);
            D_80135490.unk20[i] = 0;
            bakey_setControllerIndex(D_80135490.unk0[i], temp);
            return i;
        }
    } 
    return 0;
}

s32 func_800F61E4(void) {
    func_800F6140(-1);
}

void func_800F6204(s32 arg0) {
    func_800F6140(arg0);
}

s32 character_createNew(s32 arg0) {
    f32 sp3C[3];
    s32 i;

    for(i = 0;i<8;i++)
    {
        PlayerState* newPlayer;
        PlayerState* refPlayer;
        s32 temp;
        if (D_80135490.unk0[i] == NULL)
        {
            refPlayer = D_80135490.unk0[arg0];
            temp = func_800A907C(i, bakey_getControllerIndex(refPlayer), -1);
            newPlayer = func_800F43A8(i);
            D_80135490.unk0[i] = newPlayer;
            bakey_setControllerIndex(newPlayer, temp);
            player_getCoords_Dupe(refPlayer, sp3C);
            func_800F452C(newPlayer, sp3C);
            yaw_setIdeal(newPlayer, yaw_getIdeal(refPlayer));
            yaw_applyIdeal(newPlayer);
            func_800A92A8(2, 2);
            return i;
        }
    }
    return 0;
}

PlayerState* func_800F6308(s32 arg0, s32 arg1, f32* arg2) 
{
    PlayerState* newPlayer;

    func_800A907C(arg0, arg1, func_800A8FDC());
    newPlayer = func_800F43A8(arg0);
    D_80135490.unk0[arg0] = newPlayer;
    bakey_setControllerIndex(newPlayer, arg1);
    func_800F452C(newPlayer, arg2);
    func_800A92A8(2, 2);
    return newPlayer;
}

void func_800F6388(s32 arg0, s32 arg1)
{
    func_8008F788(D_80135490.unk0[arg0],arg1);
}

void func_800F63B4(s32 arg0)
{
    func_8008F7B4(D_80135490.unk0[arg0]);
}

void func_800F63E0(s32 arg0, u32 arg1)
{
    func_8008F854(D_80135490.unk0[arg0],arg1);
}

void func_800F640C(s32 arg0)
{
    func_8008F828(D_80135490.unk0[arg0]);
}

s32 func_800F6438(u32 arg0) {
    if (D_80135490.unk0[arg0] == NULL) {
        return 0;
    }

    return func_800F4244(D_80135490.unk0[arg0]);
}

s32 func_800F6478(s32 arg0)
{
    return func_800F424C(D_80135490.unk0[arg0]);
}

//Tranformation Type is a bitfield so you can check multiple transformations at once
s32 character_includedInTransformMask(s32 characterIndex, AllowedTransformation transformationType)
{
    return character_getTransformBit(characterIndex) & transformationType ? 1 : 0;
}

void func_800F64DC(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009CA70(sp1C, bs_getCurrentState(sp1C), 0x400000);
}

s32 func_800F651C(u32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    if (baphysics_get_target_horizontal_velocity(sp1C) == 0.0f) {
        return 1;
    }
    if (bs_getCurrentState(sp1C) == BS_STATE_1_IDLE) {
        return 1;
    }
    return func_8009E674(sp1C, 0x1000);
}

s32 func_800F6590(s32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    return func_8009CBDC(sp1C, bs_getCurrentState(sp1C)) == 0xA;
}

s32 func_800F65D0(s32 arg0) {
    s32 var_v0;

    if (D_8012762C == 0x1B) {
        var_v0 = 1;
    } else {
        var_v0 = arg0 == D_801354DC;
    }
    return var_v0;
}

s32 func_800F6604(s32 arg0) {
    return _bacough_entrypoint_1(D_80135490.unk0[arg0]) == 2;
}

s32 func_800F6634(s32 arg0) 
{
	return 0;
}

int func_800F6640(s32 arg0) {
    PlayerState* temp_a0;

    temp_a0 = D_80135490.unk0[arg0];
    return func_80092EA4(temp_a0) != 0 && func_80091E80(temp_a0, 1) != 0;
}

s32 func_800F6690(s32 charIndex)
{
    return func_80092EB0(D_80135490.unk0[charIndex]);
}

s32 func_800F66BC(s32 charIndex, f32* arg1, f32 arg2) {
    return func_8008DAE8(D_80135490.unk0[charIndex], arg1, arg2);
}

s32 func_800F66F0(u32 charIndex) {
    return bs_getCurrentState(D_80135490.unk0[charIndex]) == 0x6F;
}

int func_800F6720(s32 arg0) {
    PlayerState* temp_a0;

    temp_a0 = D_80135490.unk0[arg0];
    return func_8009E71C(temp_a0, 9) != 0 || func_8008DE74(temp_a0) != 0;
}

int func_800F6774(u32 arg0) {
    return func_800F6D24(arg0) == 0 &&
        func_800F8088(arg0) == 0 &&
        func_800F68B8(arg0) == 0 &&
        func_800F6CC8(arg0) == 0 &&
        func_800A8264() == 0;
}

void func_800F67EC(s32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009CA70(sp1C, bs_getCurrentState(sp1C), 0x200);
}

s32 func_800F682C(s32 arg0) {
    if (func_800F6D24(arg0) != 0) {
        return 0;
    }
    if (func_800F6478(arg0) == 0) {
        return 0;
    }
    if (func_8009BD44(D_80135490.unk0[arg0]) == 3) {
        return 0;
    }
    if (func_800F6C1C(arg0) == 0) {
        return 0;
    }
    return 1;
}

s32 func_800F68B8(s32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    if (func_8009E674(sp1C, 8) != 0) {
        return _badrone_entrypoint_3(sp1C) == 1;
    }
    return 0;
}

s32 func_800F690C(s32 arg0) {
    return baflag_isTrue(D_80135490.unk0[arg0], BA_FLAG_17_FIRST_PERSON_VIEW);
}

s32 func_800F693C(s32 arg0)
{
    return func_8008DD70(D_80135490.unk0[arg0]);
}

int func_800F6968(s32 arg0) {
    PlayerState* temp_a0;
    s32 pad;
    f32 sp1C;

    temp_a0 = D_80135490.unk0[arg0];
    sp1C = player_getWaterHeight(temp_a0);
    return ((sp1C - player_getCoordVertical(temp_a0)) > 4.0f) != 0 && (func_800966BC(temp_a0) & 0x2000) != 0;
}

int func_800F69E8(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return (player_isStable(sp1C) != 0) && (func_8009659C(sp1C, 0x2000) != 0);
}

s32 func_800F6A38(s32 arg0) {
    PlayerState* sp1C;
    s32 var_v1;

    sp1C = D_80135490.unk0[arg0];
    if (player_inWater(sp1C) == 0) {
        return 0;
    }
    if ((func_800966BC(sp1C) & 0x22000) == 0x22000) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

int func_800F6AA4(s32 charIndex) {
    BanjoStateId temp_v0;

    temp_v0 = bs_getCurrentState(D_80135490.unk0[charIndex]);
    return temp_v0 == BS_STATE_1B_WONDERWING_IDLE || temp_v0 == BS_STATE_1C_WONDERWING_WALK || temp_v0 == BS_STATE_1D_WONDERWING_JUMP || temp_v0 == BS_STATE_1E_WONDERWING_EXIT || temp_v0 == BS_STATE_1A_WONDERWING_START || temp_v0 == 0xA4 || temp_v0 == 0xA5;
}

u8 func_800F6B34(void) {
	return D_801354DA;
}

s32 func_800F6B40(s32 arg0) {
    if (func_800F690C(arg0) != 0) {
        return 1;
    }
    return _ncba1p_entrypoint_10(func_800A4CA8(D_80135490.unk0[arg0])) == 3;
}

int func_800F6B94(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return (player_getTransformation(sp1C) == TRANSFORM_2_SNOWBALL) && (player_getCurrentHealth(sp1C) >= 5);
}

s32 character_existsAtIndex(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 8) && (D_80135490.unk0[arg0] != NULL)) {
        return 1;
    }
    return 0;
}

s32 func_800F6C1C(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return func_8009CB44(sp1C, bs_getCurrentState(sp1C)) != 0;
}

s32 character_isStable(s32 arg0)
{
    return player_isStable(D_80135490.unk0[arg0]);
}

s32 func_800F6C88(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return func_8009CBDC(sp1C, bs_getCurrentState(sp1C)) == 2;
}

s32 func_800F6CC8(u32 arg0) {
    if (func_8009E674(D_80135490.unk0[arg0], 4) != 0) {
        return 1;
    }
    if (func_800F8B64() != 0) {
        return 1;
    }
    return 0;
}

s32 func_800F6D24(s32 arg0)
{
    return func_8008E124(D_80135490.unk0[arg0]);
}

int func_800F6D50(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return (func_8008E124(sp1C) != 0) && (func_8009E674(sp1C, 0x10) != 0);
}

s32 func_800F6DA0(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return func_8009CBDC(sp1C, bs_getCurrentState(sp1C)) == 0x12;
}

s32 func_800F6DE0(f32* arg0)
{
    return _bsbabykaz_entrypoint_14(arg0);
}

void func_800F6E00(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009CA70(sp1C, bs_getCurrentState(sp1C), 0x100000);
}

s32 func_800F6E40(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return func_8009CBDC(sp1C, bs_getCurrentState(sp1C)) == 0x13;
}

void func_800F6E80(s32 arg0)
{
    func_800A336C(D_80135490.unk0[arg0]);
}

s32 func_800F6EAC(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    if (func_8009E674(sp1C, 8) != 0) {
        return _badrone_entrypoint_3(sp1C) == 9;
    }
    return 0;
}

s32 func_800F6F00(s32 arg0) {
    f32 sp2C[3];
    f32 sp20[3];
    PlayerState* sp1C;
    f32* sp18;

    sp1C = D_80135490.unk0[arg0];
    if (_badata_entrypoint_14(sp1C) == 0) {
        return 1;
    }
    sp18 = sp2C;
    func_800F58CC(arg0, sp2C);
    if (*sp18 != 0.0f || sp2C[2] != 0.0f) {
        return 0;
    }
    if (character_isStable(arg0) == 0) {
        return 0;
    }
    func_800F5D70(arg0, sp20);
    if (func_800F55FC(arg0) & 0x8000) {
        if (sp20[1] < 0.0f && sp20[1] >= -1.0f) {
            return 1;
        }
        return 0;
    }
    if (sp20[1] != -1.0f) {
        return 0;
    }
    return 1;
}

s32 func_800F7018(s32 arg0) {
    PlayerState* sp1C;
    PlayerState* temp_a0;
    sp1C = D_80135490.unk0[arg0];
    return func_8009CBDC(sp1C, bs_getCurrentState(sp1C)) == 8;
}

s32 func_800F7058(s32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    if (func_8009E674(sp1C, 0x80) != 0) {
        return _bashoes_entrypoint_1(sp1C) == SHOETYPE_TURBO_TRAINER ? 2 : 1;
    }
    return 0;
}

s32 func_800F70BC(u32 arg0) {
    return func_8009E71C(D_80135490.unk0[arg0], 0xE);
}

s32 func_800F70EC(s32 arg0) {
    return func_8009BD44(D_80135490.unk0[arg0]) != 3;
}

s32 func_800F711C(s32 arg0) {
    return func_8009E674(D_80135490.unk0[arg0], 8) == 0;
}

s32 func_800F7150(s32 arg0) {
    return func_80094510(D_80135490.unk0[arg0]) == 7;
}

s32 func_800F7180(s32 arg0) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    if (func_8009E674(sp1C, 8) != 0) {
        return _badrone_entrypoint_3(sp1C) == 0xE;
    }
    return 0;
}

s32 func_800F71D4(u32 arg0)
{
    return func_8008E37C(D_80135490.unk0[arg0]);
}

s32 func_800F7200(s32 arg0, f32* arg1, f32 arg2, s32 arg3, s32 arg4) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    if ((arg2 < 0.0f) || (func_8008DDEC(sp1C, arg1, arg2) != 0)) {
        return func_8008F568(sp1C, arg3, arg4);
    }
    return 0;
}

s32 func_800F7270(s32 arg0, f32* arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    if (func_8008DEA4(D_80135490.unk0[arg0], arg1, arg3) != 0) {
        return func_800F7200(arg0, arg1, arg2, arg4, arg5);
    }
    return 0;
}


int func_800F72DC(u32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return (func_8009640C(sp1C) != 0) || (baflag_isTrue(sp1C, 0x26) != 0);
}

//Delete Clockwork
void func_800F732C(void) {
    D_801354DA = 1;
    transformation_destroy(TRANSFORM_11_CLOCKWORK);
    transformation_destroy(0);
    D_801354DA = 0;
}

void func_800F7364(s32 arg0) {
    if (D_80135490.unk0[arg0] != NULL) {
        func_80092AA4(D_80135490.unk0[arg0]);
    }
}

void func_800F739C(s32 arg0, s32 arg1) {
    func_800C7074(arg1, 1);
}

void _basetup_entrypoint_2(PlayerState*);

s32 func_800F73C4(s32 arg0) {
    s32 i;
    s32 count;
    s32 a;
    s32 b;
    s32 controller;
    s32 pad;

    D_80135490.unk4A = 0;
    D_80135490.unk49 = 0;
    for (i = 0; i < 8; i++) {
        D_80135490.unk0[i] = NULL;
        D_80135490.unk20[i] = 0;
    }
    D_80135490.unk52 = -1;
    D_80135490.unk50 = D_80135490.unk52;
    func_800F80D8(0);
    if (func_800DB9B0() == 0 && _glcutDll_entrypoint_1() == 0 && func_800F99E8() == 0) {
        for (i = 0; i < arg0; i++) {
            func_800F61E4();
        }
    }
    func_800F8B94();
    count = 0;
    for (i = 0; i < character_getMaxCharacters(); i++) {
        if (character_existsAtIndex(i) != 0) {
            count++;
        }
    }
    if (count == 0) {
        func_800F7E64(func_800F61E4(), 4);
    }
    if (bs_getSplitStatus() == SPLIT_STATE_SPLIT) {
        a = _character_findCharOfTransform(TRANSFORM_A_BANJO);
        b = _character_findCharOfTransform(TRANSFORM_B_KAZOOIE);
        if (a != -1 && b != -1) {
            if (func_800F65D0(b) != 0) {
                controller = b;
            } else if (func_800F65D0(a) != 0) {
                controller = a;
            } else {
                controller = _character_findCharOfTransform(TRANSFORM_11_CLOCKWORK);
            }
            func_800F8128(controller);
        }
    }

    for (i = 0; i < 8; i++) {
        if (D_80135490.unk0[i] != NULL) {
            _basetup_entrypoint_2(D_80135490.unk0[i]);
        }
    }
}

void func_800F759C(s32 arg0) {
    if (D_801354D9 != 0) {
        func_800F82C0(arg0);
        return;
    }
    func_80101238(0xB5, arg0);
    player_destroy(D_80135490.unk0[arg0]);
    func_800A91F4(arg0);
    D_80135490.unk0[arg0] = NULL;
	D_80135490.unk20[arg0] = 0;
}

void func_800F7620(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    _bamotor_entrypoint_1(D_80135490.unk0[arg0], arg1, arg2, arg3);
}

void func_800F7664(u32 arg0, s32 arg1, s32 arg2) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, (s32) arg1);
    func_8009AD2C(sp1C, (s32) arg2);
    func_8009E7C8(sp1C, 0x7D);
}

s32 func_800F76B0(s32 arg0, s32 arg1, Unk80132ED0* arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg1);
    func_8009AD14(sp1C, arg2);
    return func_8009E7C8(sp1C, 0x24) == 2;
}

s32 func_800F7700(u32 arg0, s32 arg1, f32* arg2) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg1);
    func_8009AD44(sp1C, arg2);
    return func_8009E7C8(sp1C, 0x23) == 2;
}

s32 func_800F7750(s32 arg0, f32* arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 sp24;
    PlayerState* temp_s0;

    temp_s0 = D_80135490.unk0[arg0];
    if (arg4 != 0) {
        sp24 = 0x98;
    } else {
        sp24 = 0x2D;
    }
    func_8009ACF4(temp_s0, arg2);
    func_8009AD04(temp_s0, arg3);
    func_8009AD20(temp_s0, 0xE);
    func_8009AD44(temp_s0, arg1);
    return func_8009E7C8(temp_s0, sp24) == 2;
}

void func_800F77E8(u32 arg0, f32* arg1) {
    func_800F7750(arg0, arg1, 840.0f, -1500.0f, 0);
}

void func_800F7814(s32 arg0, s32 arg1) {
    func_800F7750(arg0, arg1, 840.0f, -1500.0f, 1);
}


void func_800F7844(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    func_800F7750(arg0, arg1, arg2, arg3, 0);
}

s32 func_800F7874(s32 arg0, Unk80132ED0* arg1, f32* arg2) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009AD44(sp1C, arg2);
    func_8009AD14(sp1C, arg1);
    return func_8009E7C8(sp1C, 0x66) == 2;
}

void func_800F78C8(s32 arg0,s32 arg1)
{
    func_800F7C58(arg0,0x17,arg1);
}

s32 func_800F78EC(s32 arg0, f32* arg1, f32 arg2, f32 arg3) {
    PlayerState* temp_s0;

    temp_s0 = D_80135490.unk0[arg0];
    func_8009ACF4(temp_s0, arg2);
    func_8009AD04(temp_s0, arg3);
    func_8009AD20(temp_s0, 0xE);
    func_8009AD44(temp_s0, arg1);
    return func_8009E7C8(temp_s0, 0x68) == 2;
}

void func_800F796C(s32 arg0,s32 arg1)
{
    func_800F798C(arg0,arg1,0x1);
}

s32 func_800F798C(s32 arg0, s32 arg1, s32 arg2) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg1);
    func_8009AD2C(sp1C, arg2);
    return func_8009E7C8(sp1C, 0x1F) == 2;
}

s32 func_800F79DC(s32 arg0, s32 arg1, Unk80132ED0* arg2) {
    PlayerState* sp1C;
    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg1);
    func_8009AD14(sp1C, arg2);
    return func_8009E7C8(sp1C, 0x21) == 2;
}


s32 func_800F7A2C(s32 arg0, s32 arg1, f32* arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg1);
    func_8009AD44(sp1C, arg2);
    return func_8009E7C8(sp1C, 0x20) == 2;
}

s32 func_800F7A7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32* arg4) {
    PlayerState* temp_s0;

    temp_s0 = D_80135490.unk0[arg0];
    func_8009AD38(temp_s0, arg1);
    func_8009AD20(temp_s0, arg2);
    func_8009AD2C(temp_s0, arg3);
    func_8009AD44(temp_s0, arg4);
    return func_8009E7C8(temp_s0, 0x4E) == 2;
}

void func_800F7AF4(s32 arg0, s32 arg1) {
    func_800F7B1C(arg0, arg1, 840.0f, -1500.0f);
}

s32 func_800F7B1C(s32 arg0, f32* arg1, f32 arg2, f32 arg3) {
    PlayerState* temp_s0;

    temp_s0 = D_80135490.unk0[arg0];
    func_8009ACF4(temp_s0, arg2);
    func_8009AD04(temp_s0, arg3);
    func_8009AD20(temp_s0, 0x10);
    func_8009AD44(temp_s0, arg1);
    return func_8009E7C8(temp_s0, 0x2E) == 2;
}

s32 func_800F7B9C(s32 arg0,u32 a1)
{
    return func_8009E7C8(D_80135490.unk0[arg0],a1);
}


void func_800F7BC8(s32 arg0, s32 arg1, Unk80132ED0* arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD14(sp1C, arg2);
    func_8009E7C8(sp1C, arg1);
}

void func_800F7C0C(s32 arg0, s32 arg1, f32 arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009ACF4(sp1C, arg2);
    func_8009E7C8(sp1C, arg1);
}

s32 func_800F7C58(s32 arg0, s32 arg1, s32 arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];

    func_8009AD20(sp1C, arg2);
    return func_8009E7C8(sp1C, arg1);
}

void func_800F7C9C(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg2);
    func_8009AD2C(sp1C, arg3);
    func_8009E7C8(sp1C, arg1);
}

void func_800F7CF4(s32 arg0, s32 arg1, f32* arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD44(sp1C, arg2);
    func_8009E7C8(sp1C, arg1);
}

void func_800F7D38(s32 arg0, s32 arg1, f32* arg2, f32 arg3) {
    PlayerState* sp1C;
    PlayerState* temp_a0;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD44(sp1C, arg2);
    func_8009ACF4(sp1C, arg3);
    func_8009E7C8(sp1C, arg1);
}

void func_800F7D90(s32 arg0, s32 arg1, f32* arg2, s32 arg3) {
    PlayerState* sp1C;
    
    sp1C = D_80135490.unk0[arg0];
    func_8009AD44(sp1C, arg2);
    func_8009AD20(sp1C, arg3);
    func_8009E7C8(sp1C, arg1);
}

s32 func_800F7DE8(s32 arg0, Unk80132ED0* arg1, s32 arg2) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_8009AD20(sp1C, arg2);
    func_8009AD14(sp1C, arg1);
    return func_8009E7C8(sp1C, 0x48) == 2;
}

s32 func_800F7E3C(s32 arg0, s32 arg1) {
    return func_800F7C58(arg0, 0x84, arg1) == 2;
}

void func_800F7E64(s32 arg0, TransformationId arg1) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    player_setTransformation(sp1C, arg1);
    func_80092778(sp1C);
}

void func_800F7E9C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800A4E74(D_80135490.unk0[arg0]);
    }
}

void func_800F7ECC(s32 arg0, s32 arg1, f32 arg2) {
    bastatetimer_set(D_80135490.unk0[arg0], arg1, arg2);
}



s32 func_800F7F00(s32 arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    return func_80098778(sp1C, arg1, arg2, arg3, arg4, arg5, arg6);
}


void func_800F7F50(u32 arg0, f32* arg1, f32* arg2, f32 arg3, s32 arg4, s32 arg5) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    func_80098730(sp1C, arg1, arg2, arg3, arg4, arg5);
}

void func_800F7F98(u32 arg0, s32 arg1) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    if (arg1 != 0) {
        bakey_func_80091C14(sp1C, 1);
        bastick_func_8009F18C(sp1C, 1);
    } else {
        bakey_func_80091C14(sp1C, 0);
        bastick_func_8009F18C(sp1C, 0);
    }
}

int func_800F8004(s32 arg0) {
    s32 sp24;
    PlayerState* temp_s0;
    s32 var_a1_2;

    temp_s0 = D_80135490.unk0[arg0];
    sp24 = bakey_getBitfield(temp_s0) != 0 || bakey_func_80091964(temp_s0) != 0;
    var_a1_2 = bastick_func_8009F1A4(temp_s0) != 0 ||  bastick_func_8009EEF8(temp_s0) != 0;
    return sp24 != 0 && var_a1_2 != 0;
}

int func_800F8088(s32 arg0) {
    s32 sp24;
    s32 temp_v1;
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    sp24 = bakey_getBitfield(sp1C);
    temp_v1 = bastick_func_8009F1A4(sp1C);
    return sp24 != 0 && temp_v1 != 0;
}

void func_800F80D8(u32 arg0) {
	D_801354DC = arg0;
}

void func_800F80E4(s32 arg0, u32 arg1) {
    PlayerState* sp1C;
    s32 var_a2;

    sp1C = D_80135490.unk0[arg0];
    if (arg1 != 0) {
        var_a2 = 0;
    } else {
        var_a2 = 1;
    }
    func_800947EC(sp1C, 1, var_a2);
}

void func_800F8128(s32 arg0)
{
    func_800F80D8(arg0);
    func_800A91A8(arg0);
}
void func_800F8150(s32 arg0, s32 arg1)
{
    func_80093370(D_80135490.unk0[arg0], arg1);
}

void func_800F817C(s32 arg0, s32 arg1)
{
    func_8009337C(D_80135490.unk0[arg0], arg1);
}

void func_800F81A8(s32 arg0)
{
    player_setCurrentHealth(D_80135490.unk0[arg0]);
}

void func_800F81D4(s32 arg0)
{
    _bafpctrl_entrypoint_12(D_80135490.unk0[arg0]);
}

void func_800F8200(s32 arg0)
{
    func_800F4524(D_80135490.unk0[arg0]);
}

void func_800F822C(s32 arg0, f32 arg1, f32 arg2) {
    _bahold_entrypoint_7(D_80135490.unk0[arg0], arg1, arg2);
}

void func_800F8268(s32 arg0,s32 a1, s32 a2)
{
    func_800A38F0(D_80135490.unk0[arg0],a1,a2);
}

void func_800F8294(s32 arg0,f32* a1)
{
    func_800F452C(D_80135490.unk0[arg0],a1);
}
void func_800F82C0(s32 arg0) {
	D_80135490.unk20[arg0] = 1;
}


void func_800F82D4(s32 arg0,s32 arg1)
{
    func_800F457C(D_80135490.unk0[arg0],arg1);
}

void func_800F8300(s32 arg0, s32 arg1, f32* arg2)
{
    func_800F45B0(D_80135490.unk0[arg0],arg1,arg2);
}

void func_800F832C(s32 arg0,f32* a1)
{
    func_800F45E0(D_80135490.unk0[arg0],a1);
}

void func_800F8358(s32 arg0, s32 arg1) {
    _baduo_entrypoint_7(D_80135490.unk0[arg0], 3);
}

void func_800F838C(s32 arg0)
{
    func_8008F748(D_80135490.unk0[arg0]);
}

void func_800F83B8(s32 arg0)
{
    func_800A3514(D_80135490.unk0[arg0]);
}

void func_800F83E4(s32 arg0, f32 arg1) {
    baphysics_set_vertical_velocity(D_80135490.unk0[arg0], arg1);
}

void func_800F8418(s32 arg0, f32* arg1)
{
    func_800F4648(D_80135490.unk0[arg0],arg1);
}

void func_800F8444(s32 arg0, f32* arg1) {
    PlayerState* temp = D_80135490.unk0[arg0];
    func_8009BF5C(temp, arg1[0]);
    yaw_setIdeal(temp, arg1[1]);
    baroll_setIdeal(temp, arg1[2]);
}

void func_800F849C(s32 arg0, f32 arg1) {
    func_8009BD18(D_80135490.unk0[arg0], arg1);
}

void func_800F84D0(s32 arg0,s32 arg1)
{
    func_8009659C(D_80135490.unk0[arg0],arg1);
}

void func_800F84FC(void) {
    f32 out1; // sp6C
    f32 out2; // sp68
    f32 out3; // sp64
    f32 buf1[3]; // sp58
    s32 j;
    s32 i;
    s32 result;
    s32 newTransform;
    s32 k;

    for (i = 0; i < 8; i++) {
        if (D_80135490.unk0[i] == NULL) {
            continue;
        }
        if (func_800F5924(i) == 0) {
            continue;
        }
        character_getCoords(i, buf1);
        func_800F5950(i, &out1, &out2, &out3);
        for (j = 0; j < 8; j++) {
            if (D_80135490.unk0[j] == NULL) {
                continue;
            }
            if (i == j) {
                continue;
            }
            if (func_800F58F8(j) == 0) {
                continue;
            }
            func_800F4EC8(j, (s32) buf1, *(s32*) &out1, *(s32*) &out2, out3);
        }
    }

    D_80135490.unk49 = 1;

    //Loop through all of the active characters and trigger their update functions
    for (k = 0; k < 8; k++) 
    {
        if (D_80135490.unk0[k] != NULL) 
        {
            func_800F468C(D_80135490.unk0[k]);
        }
    }

    D_80135490.unk49 = 0;
    func_800F9198();

    result = character_getActiveIndex();
    newTransform = character_getTransform(result);
    if (D_80135490.unk50 != -1
        && (result != D_80135490.unk50 || newTransform != D_80135490.unk52)
        && func_800D5240() == 0) {
        func_800A1658(newTransform);
    }

    for (k = 0; k < 8; k++) {
        if (D_80135490.unk20[k] != 0) {
            func_800F759C(k);
        }
    }

    D_80135490.unk50 = result;
    D_80135490.unk52 = newTransform;
}

void func_800F86C4(s32 arg0, s32 arg1) {
    D_80135490.unk50 = arg0;
    D_80135490.unk52 = arg1;
}

void func_800F86D8(void) {
    PlayerState* temp;
    PlayerState** ptr;
    PlayerState** end;

    ptr = D_80135490.unk0; end = (PlayerState**) &D_801354B0;
    do {
        if (*ptr != NULL) {
            *ptr = (temp = func_800F46D8(*ptr));
        }
        ptr++;
    } while (ptr != end);
}

s32 func_800F8730(s32 arg0, s32 arg1) {
    PlayerState* sp1C;
    s32 sp18;

    sp1C = D_80135490.unk0[arg0];
    func_800A3538(sp1C,arg1);
    sp18 = func_8009E7C8(sp1C, 0xA) == 2;
    if ((sp18 != 0) && (character_getTransform(arg0) != arg1)) {
        _surestart_entrypoint_0(arg1);
    }
    return sp18;
}

s32 func_800F87A4(s32 arg0) {
    PlayerState* sp1C;

    sp1C = D_80135490.unk0[arg0];
    if ((func_800F56D8(arg0) != NULL) && (func_8009E674(sp1C, 0x400) != 0)) {
        return func_8009E7C8(sp1C, 0x16) == 2;
    }
    return 0;
}

void func_800F8804(s32 arg0,f32* arg1)
{
    func_8009CD70(D_80135490.unk0[arg0],arg1);
}

void func_800F8830(s32 arg0)
{
    func_8009E7C8(arg0,0x99);
}

void func_800F8850(void) {
    func_800F47C0((void (*)(PlayerState*)) func_800F8830);
}

void func_800F8874(s32 arg0)
{
    func_8009224C(D_80135490.unk0[arg0]);
}

unkStruct800F88A0* func_800F88A0(s32 arg0) {
    unkStruct800F88A0* sp1C;
    unkStruct800F88A0* temp_v0;

    sp1C = vector_begin(D_801354F0);
    temp_v0 = vector_end(D_801354F0);
    while (sp1C < temp_v0) 
    {
        if (arg0 == sp1C->unk0) 
        {
            return sp1C;
        }

        sp1C++;
    }

    return NULL;
}

s32 func_800F8914(unkStruct800F88A0* arg0, s32 arg1)
{
    s32 temp;
    character_getCoords(arg1, arg0->unk24);
    func_800F5B38(arg1, arg0->unk30);
    _plcamera_entrypoint_14(arg1, arg0->unk4, arg0->unk10);
    arg0->unk2 = func_800F9214(arg1);
    arg0->unk0 = character_getTransform(arg1);
    arg0->unk1 = func_800F65D0(arg1);
    arg0->unk22 = map_getCurrent();
    arg0->unk21 = func_800EA090();
    arg0->unk20 = 2;
    arg0->unk1D = func_800F58F8(arg1);
    temp = func_800F5924(arg1);
    arg0->unk1C = temp;
    return temp;
}

s32 func_800F89BC(void) {
    if (D_801354F8.splitStatus == 2) {
        return 0xB;
    }
    return 1;
}

s32 func_800F89E4(s32 arg0, f32* arg1) {
    s32 sp1C;

    if (arg0 == 0xA) {
        ml_vec3f_copy(arg1, &D_80135500);
        sp1C = D_8013551C;
    } else if (arg0 == 0xB) {
        ml_vec3f_copy(arg1, &D_80135510);
        sp1C = D_8013551C;
    }
    return sp1C;
}


f32 func_800F8A50(void)
{
	return D_8013550C;
}

MapId func_800F8A5C(s32 arg0) {
    return func_800F88A0(arg0)->unk22;
}

u8 func_800F8A80(s32 arg0) {
    return *(s16*)&func_800F88A0(arg0)->unk20;
}

u8 func_800F8AA4(void) {
    UnkStruct800F8AA4* sp1C;
    UnkStruct800F8AA4* var_v1;
    u32 temp_v0;

    sp1C = vector_begin(D_801354F0);
    temp_v0 = vector_end(D_801354F0);
    var_v1 = sp1C;
    if ((u32)var_v1 < temp_v0) {
        do {
            if (var_v1->unk1 != 0) {
                return var_v1->unk0;
            }
            var_v1++;
        } while ((u32)var_v1 < temp_v0);
    }
    return 0;
}

void func_800F8B0C(s32 arg0, s32 arg1) {
    u8* v0;

    v0 = func_800F88A0(arg0);
    ml_vec3f_copy(arg1, v0 + 0x24);
}

void func_800F8B38(s32 arg0, s32 arg1) {
    u8* v0;

    v0 = func_800F88A0(arg0);
    ml_vec3f_copy(arg1, v0 + 0x30);
}

s32 func_800F8B64(void) {
    return (s32)D_801354F8.unk1;
}

u8 func_800F8B70(void) {
    return D_801354F8.unk4;
}

u8 func_800F8B7C(void) {
    return D_801354F8.unk5;
}

SPLITUP_STATUS bs_getSplitStatus(void) {
    return D_801354F8.splitStatus;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECE0B0/func_800F8B94.s")

void func_800F8D50(s32 arg0, s32 arg1) {
    func_800F8D80(arg0, func_800F88A0(arg1));
}

void func_800F8D80(s32 arg0, unkStruct800F88A0* arg1) {
    _plcamera_entrypoint_12(arg0, arg1->unk4, arg1->unk10);
}

s32 func_800F8DA8(s32 arg0) {
    s32 var_v1;

    if (func_800F88A0(arg0) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800F8DD8(void) {
    func_800F9A24();
    vector_free(D_801354F0);
    D_801354F0 = NULL;
}


void func_800F8E08(void) {
    D_801354F0 = vector_new(0x3C, 2);
    D_801354F8.unk1 = 0;
    D_801354F8.unk4 = 0;
    D_801354F8.unk5 = 0;
    D_801354F8.splitStatus = 0;
    func_800F911C(1);
    ml_vec3f_clear(&D_80135500);
    ml_vec3f_clear(&D_80135510);
    D_8013551C = 0;
    func_800F9A44();
}

void func_800F8E78(s32 arg0) {
    void* temp_v0;

    temp_v0 = func_800F88A0(arg0);
    if (temp_v0 != 0) {
        vector_erase(D_801354F0, vector_index_of(D_801354F0, temp_v0));
    }
}

void func_800F8EBC(s32 a0)
{
    func_800F8E78(character_getTransform(a0));
}

void func_800F8EE4(s32 arg0) {
    void* temp_v0;

    temp_v0 = func_800F88A0(character_getTransform(arg0));
    if (temp_v0 != NULL) {
        func_800F8914(temp_v0, arg0);
        return;
    }
    func_800F8914(vector_push_back(&D_801354F0), arg0);
}


void func_800F8F3C(void) {
    void* temp_v0;
    unkStruct800F8F3C* temp_s2;
    unkStruct800F8F3C* s0;

    if (D_801354F8.splitStatus == 2 && D_801354F0 != 0) {
        temp_s2 = vector_begin(D_801354F0);
        temp_v0 = vector_end(D_801354F0);
        s0 = temp_s2;
        if ((u32)temp_s2 < (u32)temp_v0) {
            do {
                if (s0->unk0 == 0xA) {
                    ml_vec3f_copy((u8*)s0 + 0x24, &D_80135500);
                    s0->unk22 = (s16)D_801354F8.unk24;
                    ml_vec3f_assign_value((u8*)s0 + 0x30, 0.0f, D_801354F8.unk14, 0.0f);
                } else if (s0->unk0 == 0xB) {
                    ml_vec3f_copy((u8*)s0 + 0x24, &D_80135510);
                    s0->unk22 = (s16)D_801354F8.unk24;
                    ml_vec3f_assign_value((u8*)s0 + 0x30, 0.0f, D_801354F8.unk14, 0.0f);
                }
                s0 = (unkStruct800F8F3C*)((u8*)s0 + 0x3C);
            } while ((u32)s0 < (u32)temp_v0);
        }
    }
}

void func_800F9070(s32 arg0, s32 arg1) {
    unkStruct800F88A0* result = func_800F88A0(arg0);
    result->unk1 = arg1;
}

void func_800F9098(s32 arg0, f32* arg1) {
    if (arg0 == 0xA) {
        ml_vec3f_copy(&D_80135500, arg1);
    } else if (arg0 == 0xB) {
        ml_vec3f_copy(&D_80135510, arg1);
    }
    D_8013551C = map_getCurrent();
}

void func_800F90EC(f32 arg0) {
    D_8013550C = arg0;
}

void func_800F90F8(s32 arg0) {
    D_801354F8.unk1 = arg0;
}

void func_800F9104(s32 arg0) {
    D_801354FC = arg0;
}

void func_800F9110(s32 arg0) {
    D_801354FD = arg0;
}

void func_800F911C(s32 arg0) {
    if (D_801354F8.splitStatus == 3) {
        func_800CF840(0);
    }
    if ((u8) (D_801354F8.splitStatus = arg0) == 3) {
        func_800CF840(1);
    }
}

void func_800F9178(void) {
    D_801354FA = 0;
}

s32 func_800F9184(void) {
    return D_801354FA == 0;
}

void func_800F9198(void) {
    if (D_801354FA == 0) {
        func_800F90F8(0);
        func_800F9104(0);
        func_800F9110(0);
        D_801354FA = 1;
    }
    func_800F9C6C();
}


void func_800F91EC(void) {
    D_801354F0 = vector_defrag(D_801354F0);
}

s32 func_800F9214(s32 arg0) {
    if (func_800F6720(arg0) != 0) {
        return 2;
    }
    return 1;
}

void func_800F9240(f32* arg0, s32 arg1) {
    f32 buf[3];
    character_getCoords(arg1, buf);
    buf[0] += 200.0f;
    ml_vec3f_assign_value(arg0, buf[0], buf[1], buf[2] + 200.0f);
}


TransformationId func_800F929C(void) {
    if (bs_getSplitStatus() == SPLIT_STATE_SPLIT) {
        return TRANSFORM_B_KAZOOIE;
    }
    return TRANSFORM_1_BK;
}

void func_800F92CC(u32* arg0, enum transform_e* arg1, s32* arg2, s32* arg3) {
    enum transform_e temp_v0_2;
    u32 temp_v0;

    temp_v0 = character_getActiveIndex();
    *arg0 = temp_v0;
    temp_v0_2 = character_getTransform((s32) temp_v0);
    *arg1 = temp_v0_2;
    switch (temp_v0_2) {
    case TRANSFORM_A_BANJO:
        *arg3 = 0xB;
        break;
    case TRANSFORM_B_KAZOOIE:
        *arg3 = 0xA;
        break;
    }
    *arg2 = _character_findCharOfTransform(*arg3);
}

void func_800F9354(u32* arg0, enum transform_e* arg1, s32* arg2) {
    enum transform_e temp_v0_2;
    u32 temp_v0;

    temp_v0 = character_getActiveIndex();
    *arg0 = temp_v0;
    temp_v0_2 = character_getTransform((s32) temp_v0);
    *arg1 = temp_v0_2;
    switch (temp_v0_2) {
    case TRANSFORM_A_BANJO:
        *arg2 = 0xB;
        return;
    case TRANSFORM_B_KAZOOIE:
        *arg2 = 0xA;
        return;
    }
}

void func_800F93C4(s32* arg0, s32* arg1) {
    s32 temp = character_getActiveIndex();
    *arg0 = temp;
    *arg1 = character_getTransform(temp);
}

void func_800F9400(s32 arg0) {
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xC);
        return;
    }
    func_800C964C(0xE);
}


void func_800F9444(s32 arg0) {
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xD);
        return;
    }
    func_800C964C(0xF);
}

int func_800F9488(s32 arg0) {
    enum transform_e sp5C;
    s32 sp58;
    enum transform_e sp54;
    s32 sp50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    switch (D_80135520.unk0) 
    {
    case 3: 
        if (arg0 == 1) {
            func_800F92CC((u32* ) &sp58, &sp5C, &sp50, &sp54);
            func_800F82D4(sp58, 0);
            func_800F8268(sp58, 1, 1);
        }
        break;
    case 6: 
        if (arg0 == 1) {
            func_800F9354((u32* ) &sp58, &sp5C, &sp54);
            func_800F8EBC(sp58);
            func_800F8268(sp58, 1, 1);
            func_800F82D4(sp58, 0);
        }
        break;
    case 9: 
        if (arg0 == 1) {
            func_800F93C4(&sp58, &sp5C);
            func_800F8EBC(sp58);
            func_800F8268(sp58, 1, 1);
            func_800F82D4(sp58, 0);
        }
        break;
    case 15:
        if (arg0 == 1) {
            func_800F93C4(&sp58, &sp5C);
            func_800F8E78(0xA);
        }
        break;
    }
    D_80135520.unk0 = (u8) arg0;
    switch (D_80135520.unk0) 
    {
    case 2: 
        func_800F92CC((u32* ) &sp58, &sp5C, &sp50, &sp54);
        func_800F82D4(sp58, 2);
        func_800F8268(sp58, 0, 1);
        func_800F9444(sp5C);
        return;
    case 3: 
        func_800F92CC((u32* ) &sp58, &sp5C, &sp50, &sp54);
        func_800F8128(sp50);
        func_800F8EE4(sp58);
        func_800F8EBC(sp50);
        func_800F9400(sp54);
        return;
    case 4: 
        func_800F9354((u32* ) &sp58, &sp5C, &sp54);
        func_800F82D4(sp58, 2);
        func_800F9444(sp5C);
        return;
    case 5: 
        func_800F9354((u32* ) &sp58, &sp5C, &sp54);
        func_800F9070(sp54, 1);
        func_800F8268(sp58, 0, 1);
        func_800F8EE4(sp58);
        func_800F9070(sp5C, 0);
        func_800A7990(func_800F8A5C(sp54), 0, 0);
        return;
    case 6: 
        func_800F9354((u32* ) &sp58, &sp5C, &sp54);
        func_800F82D4(sp58, 2);
        func_800F9400(sp5C);
        return;
    case 7: 
        func_800F9444(func_800F929C());
        return;
    case 8: 
        sp54 = func_800F929C();
        func_800F9070(sp54, 1);
        if (func_800DB9B0() == 0) {
            func_800A7990(func_800F8A5C(sp54), 0, 0);
            return;
        }
    default:
        return;
    case 9: 
        func_800F93C4(&sp58, &sp5C);
        func_800F82D4(sp58, 2);
        func_800F9400(sp5C);
        return;
    case 10:
        func_800F93C4(&sp58, &sp5C);
        sp50 = _character_findCharOfTransform(TRANSFORM_11_CLOCKWORK);
        func_800F8128(sp58);
        func_800F759C(sp50);
        func_800F8268(sp58, 1, 1);
        return;
    case 11:
        sp50 = (s32) D_80135522;
        sp58 = (s32) D_80135521;
        func_800F8128(sp50);
        func_800F759C(sp58);
        func_800F8268(sp50, 1, 1);
        return;
    case 13:
        func_800F93C4(&sp58, &sp5C);
        func_800F82D4(sp58, 2);
        func_800F9444(TRANSFORM_B_KAZOOIE);
        return;
    case 14:
        func_800F9070(TRANSFORM_A_BANJO, 1);
        func_800A7990(func_800F8A5C(TRANSFORM_A_BANJO), 0, 0);
        return;
    case 15:
        func_800F93C4(&sp58, &sp5C);
        sp50 = character_createNew(sp58);
        func_800F7E64(sp50, TRANSFORM_B_KAZOOIE);
        func_800F608C(sp50, 1);
        func_800F9240(sp44, sp58);
        func_800F7CF4(sp50, 0x50, sp44);
        func_800F9400(TRANSFORM_A_BANJO);
        return;
    case 16:
        sp58 = _character_findCharOfTransform(TRANSFORM_B_KAZOOIE);
        sp50 = _character_findCharOfTransform(TRANSFORM_A_BANJO);
        character_getCoords(sp58, sp20);
        character_getCoords(sp50, sp2C);
        if (ml_vec3f_distance_sq(sp20, sp2C) < 48400.0f) {
            ml_vec3f_copy(sp38, sp20);
        } else {
            func_800F9240(sp38, sp50);
        }
        func_800F7CF4(sp58, 0x50, sp38);
        func_800F8128(sp50);
        func_800F8EBC(sp50);
        func_800F8268(sp50, 1, 1);
        return;
    case 17:
        sp58 = _character_findCharOfTransform(TRANSFORM_B_KAZOOIE);
        sp50 = _character_findCharOfTransform(TRANSFORM_A_BANJO);
        func_800F759C(sp58);
        func_800D5234(0);
        func_800A16BC(0);
        func_800F8128(sp50);
        func_800F8EBC(sp50);
        func_800F7B9C(sp50, 0x60U);
        func_800F8268(sp50, 1, 1);
        break;
    }
}



s32 func_800F99E8(void) {
    return D_80135520.unk0 != 1;
}

s32 func_800F99FC(void) {
    if (D_80135520.unk0 == 0xE) {
        return 1;
    }
    return 0;
}

s32 func_800F9A24(void) {
    func_800F9488(0);
}

void func_800F9A44(void) {
    D_80135520.unk0 = 0;
    func_800F9488(1);
}


void func_800F9A6C(void) {
    if (_character_soloCharactersExist() != 0) {
        func_800F9488(2);
        return;
    }
    func_800F9488(4);
}


extern unkStructD_80135520 D_80135520;

void func_800F9AAC(s32 arg0, s32 arg1) {
    D_80135520.unk1 = arg0;
    D_80135520.unk2 = arg1;
    func_800F9488(0xB);
}

void func_800F9ADC()
{
    func_800F9488(0xC);
}

void func_800F9AFC(void) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    func_800F93C4(&sp20, &sp24);
    sp1C = _character_findCharOfTransform(func_800F929C());
    func_800F8128(sp1C);
    func_800F8EBC(sp1C);
    func_800F8268(sp1C, 1, 1);
}

void func_800F9B54(void) {
    u32 sp1C;
    s32 sp18;

    sp1C = character_getActiveIndex();
    sp18 = _character_findCharOfTransform(TRANSFORM_11_CLOCKWORK);
    func_800F8128((s32) sp1C);
    func_800F8268((s32) sp1C, 1, 1);
    func_800F82C0(sp18);
}


void func_800F9BA4()
{
    func_800D9240(0x11);
}

void func_800F9BC4(void) {
    if (bs_getSplitStatus() != SPLIT_STATE_TALON_TORPEDO) {
        return;
    }
    if (func_800DB9B0() != 0) {
        return;
    }
    switch (D_80135520.unk0) {
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            break;
        default:
            func_800BEAF4();
            func_800F9488(0x12);
            break;
    }
}

void func_800F9C38(void) {
    if (bs_getSplitStatus() == SPLIT_STATE_TALON_TORPEDO) {
        func_800F9488(0x13);
    }
}

void func_800F9C6C(void) {
    s32 temp;
    s32 sp18;

    switch (D_80135520.unk0) {
    case 2:
        if (func_800C9510() == 0) {
            func_800F9488(3);
            return;
        }
    default:
        return;
    case 3:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
            return;
        }
        break;
    case 4:
        if (func_800C9510() == 0) {
            func_800F9488(5);
            return;
        }
        break;
    case 5:
        func_800F9488(6);
        return;
    case 6:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
            return;
        }
        break;
    case 7:
        if (func_800C9510() == 0) {
            func_800F9488(8);
            return;
        }
        break;
    case 8:
        func_800F9488(9);
        return;
    case 9:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
            return;
        }
        break;
    case 10:
        func_800F9488(1);
        return;
    case 11:
        func_800F9488(1);
        return;
    case 12:
        if (_character_findCharOfTransform(func_800F929C()) == -1) {
            func_800F9488(7);
            return;
        }
        func_800F9488(0xA);
        return;
    case 13:
        if (func_800C9510() == 0) {
            func_800F9488(0xE);
            return;
        }
        break;
    case 14:
        func_800F9488(0xF);
        return;
    case 15:
        if (func_800C95D4() != 0) {
            func_800F9488(1);
            return;
        }
        break;
    case 16:
        func_800F9488(1);
        return;
    case 17:
        func_800F9488(1);
        return;
    case 18:
        sp18 = func_800F8A5C(0xA);
        if (map_getCurrent() == sp18) {
            func_800F9488(0x10);
            return;
        }
        func_800F9488(0xD);
        return;
    case 19:
        sp18 = func_800F8A5C(0xA);
        if (map_getCurrent() == sp18) 
        {
            func_800F9488(0x11);
        }
        break;
    }
}
