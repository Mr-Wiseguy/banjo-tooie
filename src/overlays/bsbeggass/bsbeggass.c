#include <ultra64.h>
#include "common.h"

typedef enum asset_e {
    ASSET_2B_ANIM_BSEGGASS = 0x2B
} AssetId;

typedef enum ba_physics_type_e {
    BA_PHYSICS_NONE,
    BA_PHYSICS_UNK1,
    BA_PHYSICS_NORMAL,
    BA_PHYSICS_LOCKED_ROTATION,
    BA_PHYSICS_UNK4, 
    BA_PHYSICS_INVERTED_YAW,
    BA_PHYSICS_AIRBORN,
    BA_PHYSICS_FREEZE,
    BA_PHYSICS_UNK8,
    BA_PHYSICS_NO_GRAVITY,
    BA_PHYSICS_CLIMB,
    BA_PHYSICS_TRANSFORM,
    BA_PHYSICS_GOTO,
    BA_PHYSICS_END
} BaPhysicsType;

typedef enum baanim_update_type_e {
    BAANIM_UPDATE_0_NONE,
    BAANIM_UPDATE_1_NORMAL,
    BAANIM_UPDATE_2_SCALE_HORZ,
    BAANIM_UPDATE_3_SCALE_VERT
} BaAnimUpdateType;

typedef enum yaw_state_e{
    YAW_STATE_0_NONE,
    YAW_STATE_1_DEFAULT,
    YAW_STATE_2_UNBOUNDED,
    YAW_STATE_3_BOUNDED
} YawState;

// This might be the struct that contains the player's state, but that needs to be confirmed.
struct UnkEggAss {
    u8 pad0[0x15C];
    s32 unk15C;
    s32 unk160;
    s32 unk164;
};

// TODO rename these symbols
#define baanim_playForDuration_onceSmooth func_8008CDB8
#define yaw_setVelocityBounded func_8009C99C
#define baphysics_set_target_horizontal_velocity func_8009B9B0

void baanim_playForDuration_onceSmooth(struct UnkEggAss* thisx, AssetId anim_id, f32 duration);
void func_8009FFD8(struct UnkEggAss* thisx, BaAnimUpdateType anim_update_type, YawState yaw_state, s32 arg2, BaPhysicsType arg3);
void yaw_setVelocityBounded(struct UnkEggAss* thisx, f32 arg0, f32 arg1);
void baphysics_set_target_horizontal_velocity(struct UnkEggAss* thisx, f32);
void func_800A0CDC(struct UnkEggAss* thisx, s32 arg1);
s32 func_80094510(struct UnkEggAss* thisx);
void func_80098140(struct UnkEggAss* thisx, s32, s32);

void bsbeggass_entrypoint_0(struct UnkEggAss* arg0){
    baanim_playForDuration_onceSmooth(arg0, ASSET_2B_ANIM_BSEGGASS, 1.0f);
    func_8009FFD8(arg0, BAANIM_UPDATE_1_NORMAL, YAW_STATE_3_BOUNDED, 1, BA_PHYSICS_LOCKED_ROTATION);
    yaw_setVelocityBounded(arg0, 350.0f, 14.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A0CDC(arg0, 1);
    arg0->unk15C = arg0->unk160 = 1;
    arg0->unk164 = func_80094510(arg0);
    func_80098140(arg0,5,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bsbeggass/bsbeggass/bsbeggass_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bsbeggass/bsbeggass/bsbeggass_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bsbeggass/bsbeggass/bsbeggass_entrypoint_3.s")
