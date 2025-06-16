#ifndef __GC_NEWOPTION_H__
#define __GC_NEWOPTION_H__

typedef struct {
	u8 data[0x260];
} OptionState;

int gcnewoption_entrypoint_2(void);
int _gcnewoption_entrypoint_2(void);

void gcnewoption_entrypoint_7(OptionState* a0);
void _gcnewoption_entrypoint_7(OptionState* a0);

#endif
