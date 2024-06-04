#include "stm32f10x.h"                  // Device header
#include "TM1637.h"
#include "delay.h"
int broj = 9999;
int main(void)
{

	tm1637Init();
	tm1637SetBrightness(8);

	while(1)
	{
	tm1637DisplayDecimal(broj,0);
		broj--;
		delaymS(100);
		if(broj<=0)broj=9999;
	}
}
	