#ifndef __CORE1_CRC__
#define __CORE1_CRC__

#include "common.h"

void init_crc_check(void);
void set_crc_entry(s32);
s32 advance_crc_check(void);
void do_crc_check(void);

#endif
