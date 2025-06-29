#include "core1/mlmtx.h"

MtxF D_8007B4F0[0x1F]; // mtx_buffer
MtxF* s_mtx_stack;

f32 func_800137F4(f32); // sinf
f32 func_80013788(void); // cosf?

/**
 * @brief copies the top of the matrix stack to the destination address
 * 
 * @param dst 
 */
void mlMtxGet(MtxF *dst) {
    s32 row, col;

    for(row = 0; row < 4; row++){
        for(col = 0; col < 4; col++){
            dst->m[0][0] = s_mtx_stack->m[row][col];
            // TODO figure out how to avoid this pointer arithmetic.
            dst = (MtxF*)&dst->m[0][1];
        }
    }
}

MtxF *mlMtx_get_stack_pointer(void){
    return s_mtx_stack;
}

MtxF *func_80018BB4(void){
    return s_mtx_stack - 1;
}

s32 func_80018BC4(void) {
    f32 temp_f0;
    s32 var_v1;

    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        temp_f0 = s_mtx_stack->m[3][var_v1];
        if ((temp_f0 > 32767.0f) || (temp_f0 < -32768.0f)) {
            return 1;
        }
    }
    return 0;
}

void mlMtxApply(Mtx *mPtr){
    guMtxF2L(s_mtx_stack->m, mPtr);
}

void func_80018C50(MtxF *arg0) {
    s32 row;
    s32 col;
    s32 i;
    f32 sum;
    f32 prod[4][4];

    for(row = 0; row < 4; row++) {
        for(col = 0; col < 4; col++) {
            sum = 0.0f;
            for(i = 0; i < 4; i++) {
                sum += arg0->m[row][i] * s_mtx_stack->m[i][col];
            }
            prod[row][col] = sum;
        }
    }

    for(row = 0; row < 4; row++){
        for(col = 0; col < 4; col++){
            s_mtx_stack->m[row][col] = prod[row][col];
        }
    }
}

void mlMtxPop(void){
    s_mtx_stack--; 
}

/**
 * @brief pushes a copy of the current matrix on the top matrix stack to the top of
 * the matrix stack.
 * 
 */
void mlMtx_push_duplicate(void) {
    s32 i, j;
    f32 *var_a3;
    f32 *var_a2;

    var_a2 = &(s_mtx_stack + 1)->m[0][0];
    var_a3 = &s_mtx_stack->m[0][0];
    for(i = 0; i < 16; i++) {
        var_a2[i] = var_a3[i];
    }
    s_mtx_stack++;
}

/**
 * @brief Pushes a translation matrix to the top of the matrix stack.
 * 
 * @param x 
 * @param y 
 * @param z 
 */
void mlMtx_push_translation(f32 x, f32 y, f32 z) {
    f32 * var_v0 = &(++s_mtx_stack)->m[0][0];
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = x; *(var_v0++) = y; *(var_v0++) = z; *(var_v0++) = 1.0f;
}

void mlMtx_set_translation(f32 x, f32 y, f32 z) {
    f32 * var_v0 = &(s_mtx_stack = &D_8007B4F0[0])->m[0][0];
    *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = 0.0f; *(var_v0++) = 0.0f; *(var_v0++) = 1.0f; *(var_v0++) = 0.0f;
    *(var_v0++) = x; *(var_v0++) = y; *(var_v0++) = z; *(var_v0++) = 1.0f;
}

void mlMtxSet(MtxF* arg0) {
    s32 i, j;
    MtxF *v0;
    
    v0 = s_mtx_stack = D_8007B4F0;
    for(i = 0; i < 4*4; i+=4){
        for(j = 0; j < 4; j++){
            v0->m[0][0] = arg0->m[0][0];
            // TODO figure out how to avoid this pointer arithmetic.
            v0 = (MtxF*)(&v0->m[0][1]);
            arg0 = (MtxF*)(&arg0->m[0][1]); 
        }
    }
}

/**
 * @brief Multiplies the following X-axis rotation matrix into the matrix stack:
 * [      1            0            0      ]
 * [      0       cos(angle)   sin(angle)  ]
 * [      0      -sin(angle)   cos(angle)  ]
 *
 * @param angle
 */
void mlMtxRotPitch(f32 angle) {
    f32 cosval;
    f32 sinval;
    f32 var_f10;
    f32 var_f18;
    f32 (*row1)[4];
    f32 (*row2)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row1 = &s_mtx_stack->m[1];
        row2 = &s_mtx_stack->m[2];
        for (i = 0; i < 3; i++) {
            var_f18 = (*row1)[i];
            var_f10 = (*row2)[i];
            (*row1)[i] = var_f18*cosval + var_f10*sinval;
            (*row2)[i] = var_f10*cosval - var_f18*sinval;
        }
    }
}

/**
 * @brief Multiplies the following Y-axis rotation matrix into the matrix stack:
 * [  cos(angle)       0      -sin(angle)  ]
 * [      0            1            0      ]
 * [  sin(angle)       0       cos(angle)  ]
 *
 * @param angle
 */
void mlMtxRotYaw(f32 angle) {
    f32 cosval;
    f32 sinval;
    f32 var_f10;
    f32 var_f18;
    f32 (*row0)[4];
    f32 (*row2)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row0 = &s_mtx_stack->m[0];
        row2 = &s_mtx_stack->m[2];
        for(i = 0; i < 3; i++){
            var_f18 = (*row0)[i];
            var_f10 = (*row2)[i];
            (*row0)[i] = var_f18*cosval - var_f10*sinval;
            (*row2)[i] = var_f10*cosval + var_f18*sinval;
        }
    }
}


/**
 * @brief Multiplies the following Z-axis rotation matrix into the matrix stack:
 * [  cos(angle)   sin(angle)       0      ]
 * [ -sin(angle)   cos(angle)       0      ]
 * [      0            0            1      ]
 *
 * @param angle
 */
void mlMtxRotRoll(f32 angle) {
    f32 cosval;
    f32 sinval;
    f32 var_f10;
    f32 var_f18;
    f32 (*row0)[4];
    f32 (*row1)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row0 = &s_mtx_stack->m[0];
        row1 = &s_mtx_stack->m[1];
        for(i = 0; i < 3; i++){
            var_f18 = (*row0)[i];
            var_f10 = (*row1)[i];
            (*row0)[i] = var_f18*cosval + var_f10*sinval;
            (*row1)[i] = var_f10*cosval - var_f18*sinval;
        }
    }
}

void mlMtxRotatePYR(f32 pitch, f32 yaw, f32 roll){
    mlMtxRotYaw(yaw);
    mlMtxRotPitch(pitch);
    mlMtxRotRoll(roll);
}

void mlMtxScale(f32 scale){
    int i;
    for(i = 0; i < 3; i++){
        s_mtx_stack->m[0][i] *= scale;
        s_mtx_stack->m[1][i] *= scale;
        s_mtx_stack->m[2][i] *= scale;
    }
}

void func_800191F8(f32 x, f32 y, f32 z){
    s_mtx_stack->m[3][0] = x;
    s_mtx_stack->m[3][1] = y;
    s_mtx_stack->m[3][2] = z;
}

void func_80019224(f32 arg0[3], f32 arg1[3]) {
    s32 i;
    f32 sp0[3];

    sp0[0] = arg1[0];
    sp0[1] = arg1[1];
    sp0[2] = arg1[2];
    
    for(i = 0; i < 3; i++){
        arg0[i] = sp0[0]*s_mtx_stack->m[0][i] 
                + sp0[1]*s_mtx_stack->m[1][i] 
                + sp0[2]*s_mtx_stack->m[2][i] 
                + s_mtx_stack->m[3][i];
    }
}

void func_800192FC(f32 arg0[3], f32 arg1[3]) {
    s32 i;
    f32 sp0[3];

    sp0[0] = arg1[0];
    sp0[1] = arg1[1];
    sp0[2] = arg1[2];
    
    for(i = 0; i < 3; i++){
        arg0[i] = sp0[0]*s_mtx_stack->m[i][0] 
                + sp0[1]*s_mtx_stack->m[i][1] 
                + sp0[2]*s_mtx_stack->m[i][2];
    }
}

void func_800193C4(f32 arg0[3], f32 arg1[3]) {
    s32 i;
    
    for(i = 0; i < 3; i++){
        arg0[i] = arg1[0]*s_mtx_stack->m[0][i] 
                + arg1[1]*s_mtx_stack->m[1][i] 
                + arg1[2]*s_mtx_stack->m[2][i] 
                + s_mtx_stack->m[3][i];
    }
}

void func_80019480(f32 arg0[3], f32 x, f32 y, f32 z) {
    s32 var_v1;

    for(var_v1 = 0; var_v1 < 3; var_v1++){
        arg0[var_v1] = 
            x * s_mtx_stack->m[0][var_v1] + 
            y * s_mtx_stack->m[1][var_v1] +
            z * s_mtx_stack->m[2][var_v1] +
                s_mtx_stack->m[3][var_v1];
    }
}

void func_8001953C(s32 arg0[3], s32 arg1[3], s32 arg2[3], s32 arg3[3]) {
	s32 var_t0;
	s32 j;
    f32 sp48[8][3];
    f32 *ptr = sp48[0];

    for(var_t0 = 0; var_t0 < 8; var_t0++) {
        ptr[0] = (var_t0 & 1) ? arg3[0] : arg2[0];
        ptr[1] = (var_t0 & 2) ? arg3[1] : arg2[1];
        ptr[2] = (var_t0 & 4) ? arg3[2] : arg2[2];
        ptr+=3;
    }

    for(var_t0 = 0; var_t0 < 8; var_t0++) {
        func_80019224(sp48[var_t0], sp48[var_t0]);
    }

    for(var_t0 = 0; var_t0< 3; var_t0++) {
        arg0[var_t0] = arg1[var_t0] = sp48[0][var_t0];
    }

    for(var_t0 = 1; var_t0 < 8; var_t0++) {
        for(j = 0; j < 3; j++){
            if(sp48[var_t0][j] < arg0[j]){
                arg0[j] = sp48[var_t0][j];
            } else if (arg1[j] < sp48[var_t0][j]){
                arg1[j] = sp48[var_t0][j];
            }
        }
    }
}

void func_80019750(f32 arg0[3], f32 rotation[3], f32 scale, f32 arg3[3]) {
    if(arg0 != NULL) {
        mlMtxTranslate(arg0[0], arg0[1], arg0[2]);
    }

    if(rotation != NULL) {
        mlMtxRotYaw(rotation[1]);  
        mlMtxRotPitch(rotation[0]);
        mlMtxRotRoll(rotation[2]);
    }

    if(scale != 1.0f) {
        mlMtxScale_xyz(scale, scale, scale);
    }

    if(arg3 != NULL) {
        mlMtxTranslate(-arg3[0], -arg3[1], -arg3[2]);
    }
}

void func_8001980C(f32 position[3], f32 rotation[3], f32 scale, f32 arg3[3]) {
    if(arg3 != NULL) {
        mlMtxTranslate(arg3[0], arg3[1], arg3[2]);
    }
    
    if(scale != 1.0f) {
        mlMtxScale_xyz(1.0f/scale, 1.0f/scale, 1.0f/scale);
    }

    if(rotation != NULL) {
        mlMtxRotRoll(-rotation[2]);
        mlMtxRotPitch(-rotation[0]);
        mlMtxRotYaw(-rotation[1]);  
    }

    if(position != NULL) {
        mlMtxTranslate(-position[0], -position[1], -position[2]);
    }
}

void func_800198D4(f32 position[3], f32 rotation[3]) {
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);   
}

void func_80019924(f32 position[3], f32 rotation[3]) {
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

void func_80019994(f32 position[3], f32 rotation[3]) {
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);    
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

void func_80019A10(f32 position[3], f32 rotation[3]) {
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}
