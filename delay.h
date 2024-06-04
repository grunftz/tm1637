#ifndef __delay__H__
#define __delay__H__
#include "stm32f10x.h"                  // Device header
void timer_init();
void delaymS(int ms);
void delayuS(int us);
#endif
