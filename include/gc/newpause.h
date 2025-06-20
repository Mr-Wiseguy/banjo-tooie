#ifndef __GC_NEWPAUSE_H__
#define __GC_NEWPAUSE_H__
#include "common.h"
#include "memory.h"
#include "gc/newoption.h"

typedef struct {
	u8 PageIndex; //0x0
	u8 SubPage; //0x1
	s8 unk2;
	s8 unk3;
	s8 unk4;
	u8 LastOptionSelected;//0x5
	s8 HeaderAndButtonOffset; //0x6
	s8 CanExitPage;
	f32 unk8;
	s8 unkC; //0xC
	s8 ActivePauseMenuVariant;//0xD
	u8 unkE;
	s8 unkF;
	u8 unk10;
	s8 unk11;
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
	u16 unk1;
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

extern TotalsFlags D_808020A8_gcnewpause[];
extern InventoryDisplay D_808020D8_gcnewpause[];
extern ItemCountDisplay D_80802130_gcnewpause[];
extern AbilityTracking D_8080215C_gcnewpause[];
void gcnewpause_entrypoint_0(void);
void func_80800534_gcnewpause(PauseState* a0, u32 a1);
void func_80800E10_gcnewpause(PauseState* a0, u32 a1);
void func_8080105C_gcnewpause(u32 a0, u32 a1, u32 a2, u32 a3);
u8 func_80801248_gcnewpause(s16* a0, u8* a1, u32 a2, PauseState* a3);
void func_808012CC_gcnewpause(PauseState* a0, u32* a1);
u8 func_80801330_gcnewpause(PauseState* a0, u32 a1, u32 a2);
void func_8080162C_gcnewpause(PauseState* a0, u32 a1);
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
void func_80801E08_gcnewpause(PauseState* a0, OptionState* a1);
s32 func_80801E80_gcnewpause(s32 a0, s32 a1);
s32 func_80801EF0_gcnewpause(s32 a0);

u32 func_80801F18_gcnewpause(u32 a0);



#endif
