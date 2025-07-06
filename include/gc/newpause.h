#ifndef __GC_NEWPAUSE_H__
#define __GC_NEWPAUSE_H__
#include "common.h"
#include "memory.h"
#include "gc/newoption.h"

typedef struct {
	u8 PageIndex; //0x0
	u8 SubPage; //0x1
	u8 unk2;
	s8 unk3;
	u8 unk4;
	u8 LastOptionSelected;//0x5
	s8 HeaderAndButtonOffset; //0x6
	s8 CanExitPage; //0x7
	f32 unk8;
	u8 unkC; //0xC
	s8 ActivePauseMenuVariant;//0xD
	u8 unkE;
	s8 SoundEffectTimerPageOpen;
	u8 unk10;
	u8 unk11;
	u8 unk12;
	s8 unk13;
	u32* textPointer;//0x14
	s16 pageTitleOffset; //0x18
	u8 MovePageHeaderTrigger; //0x1A
	u8 DrawPageHeader; //0x1B
	u8 ShowBButton;//0x1C
	u8 JoystickIndicator;//0x1D
	u8 CanMoveLeft;//0x1E
	u8 CanMoveRight;//0x1F
	u8 MoveLeftJoystickTrigger;//0x20
	u8 MoveRightJoystickTrigger; //0x21
	u8 MoveBButtonTrigger; //0x22
	s8 unk23;
	s16 LeftJoystickPos; //0x24
	s16 RightJoystickPos; //0x26
	s16 B_Button_Pos; //0x28
	s16 GameOverTransparency; //0x2A
	s16 GameOverFadingIn; //0x2C
	u16 unk2E;
	OptionState optionState;
} PauseState;

typedef struct {
	s16 ItemID;
	u8 uiPosition;
	u8 AbilityID;
} InventoryDisplay;

typedef struct {
	s16 unk1;
	s16 SubPage;
} TotalsFlags;

typedef struct {
	s16 itemType;
	s16 itemIcon;
	s16 uiPosition;
} ItemCountDisplay;

typedef struct {
	s8 SubPageToShow;
	u8 AbilityId;
} AbilityTracking;

typedef struct {
	s32 x;
	s32 y;
} Coords2D;

typedef struct {
	u16 Icon; //0x0
	u8 Text; //0x2
	u8 Function; //0x3
	u8 SubOption; //0x4
	u8 AreYouSure; //0x5
} Option;

//Information about a given pause menu state, how many options there are
typedef struct {
	s16 unk1;
	s8 unk3;
	u8 Size;
	Option* options;
} PauseOption;

typedef struct {
	s8 a1, a2, a3, a4;
} MemorySetupStruct;

// most likely xyz coords
typedef struct unk80802190 {
	s16 unk0;
	s16 unk2;
	s16 unk4;
} unk80802190;

extern PauseOption D_80802070_gcnewpause[];
extern void* D_808021CC_gcnewpause;
extern void* D_808021E4_gcnewpause;

extern TotalsFlags D_808020A8_gcnewpause[];
extern InventoryDisplay D_808020D8_gcnewpause[];
extern s8 D_80802124_gcnewpause[];
extern s8 D_80802125_gcnewpause;
extern MemorySetupStruct D_80802126_gcnewpause[];
extern s8 D_8080212E_gcnewpause;
extern ItemCountDisplay D_80802130_gcnewpause[];
extern AbilityTracking D_8080215C_gcnewpause[];
extern unk80802190 D_80802190_gcnewpause[6];
extern u8 D_808021B4_gcnewpause[12];
extern void* D_808021C0_gcnewpause;
extern u8 D_8012762D;
extern s8 D_80802072_gcnewpause;

PauseState* gcnewpause_entrypoint_0(u32 arg0);
PauseState* _gcnewpause_entrypoint_0(u32 arg0);
void gcnewpause_entrypoint_1(PauseState* a0);
void _gcnewpause_entrypoint_1(PauseState* a0);
u32 gcnewpause_entrypoint_2(PauseState* a0);
u32 _gcnewpause_entrypoint_2(PauseState* a0);
void gcnewpause_entrypoint_3(u32 arg0, PauseState* pauseMenu);
void _gcnewpause_entrypoint_3(u32 arg0, PauseState* pauseMenu);
void gcnewpause_entrypoint_4(u32 arg0, OptionState* arg1, u32 arg2, u32 arg3);
void _gcnewpause_entrypoint_4(u32 arg0, OptionState* arg1, u32 arg2, u32 arg3);

void func_80800534_gcnewpause(PauseState* a0, u32 a1);
void func_80800A08_gcnewpause(PauseState*);
void func_80800C54_gcnewpause(PauseState* arg0, OptionState* arg1);
void func_80800CE4_gcnewpause(PauseState* pauseMenu, u32 arg1, s32 selectedOption);
void func_80800DE0_gcnewpause(f32 a0);
void func_80800E10_gcnewpause(PauseState* a0, u32 a1);
s32 func_80800EA8_gcnewpause(PauseState* arg1, u32);
s32 func_80800F2C_gcnewpause(PauseState* arg1, u32 arg2, u32 arg3);
s32 func_80800FA8_gcnewpause(u32);
s32 func_8080105C_gcnewpause(s32 a0, s32 a1, u32 a2, u32 a3);
u32 func_808011BC_gcnewpause(void);
u8 func_80801248_gcnewpause(s16* a0, u8* a1, u32 a2);

void func_808012CC_gcnewpause(PauseState* a0, u32* a1);
u8 func_80801330_gcnewpause(PauseState* a0, u32 a1, u32 a2);
void func_8080136C_gcnewpause(PauseState* pauseMenu);
void func_80801410_gcnewpause(PauseState* pauseMenu, s32 arg1);
void func_8080152C_gcnewpause(PauseState* pauseMenu);
void func_80801580_gcnewpause(PauseState* pauseMenu);
void func_808015F8_gcnewpause(PauseState* pauseMenu, u32 a1);
void func_8080162C_gcnewpause(PauseState* a0, u32 a1);
void func_80801660_gcnewpause(PauseState* pauseMenu);
s32 func_808016A4_gcnewpause(s32 a0);
s32 func_808016F0_gcnewpause(s32 a0);
s32 func_80801718_gcnewpause(s32, s32);
void func_808017C8_gcnewpause(PauseState* pauseMenu, u32 arg1);
s32 func_80801844_gcnewpause(u32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5);
s32 func_8080190C_gcnewpause(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4);
s32 func_808019A4_gcnewpause(u32 arg0, u32 arg1);
s32 func_80801AF8_gcnewpause(u32 arg0);
u32 func_80801BF0_gcnewpause(u32 a0);
s32 func_80801C3C_gcnewpause(s32 a0);
void func_80801CCC_gcnewpause(PauseState* a0);
void func_80801CDC_gcnewpause(PauseState* a0);
void func_80801DA0_gcnewpause(PauseState* pauseMenu, u32 a1);
void func_80801E08_gcnewpause(PauseState* a0, OptionState* a1);
s32 func_80801E80_gcnewpause(s32 a0, s32 a1);
s32 func_80801EF0_gcnewpause(s32 a0);

u32 func_80801F18_gcnewpause(u32 a0);



#endif
