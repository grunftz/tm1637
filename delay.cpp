#include "delay.h"
//-------------------------VARS-------------------------------------------
int ticks,i;								// smart count
//-------------------------END VARS---------------------------------------
//------------------------PROTOTYPES && other sutff-----------------------
extern "C" {void TIM3_IRQHandler();} 

//---------------------END PROTPTYPs--------------------------------------

//-------------------------TIMER STUFF-------------------------------------------
void timer_init(){
	RCC->APB1ENR |=RCC_APB1ENR_TIM3EN;  //timer 3 enable GP Timer
	TIM3->PSC = 0; 						          //prescaller
	TIM3->ARR =72; 					          	//1MHz freq  period 1uS
	TIM3->CR1|=TIM_CR1_URS;				      //interrupt on overflow
	TIM3->DIER |=TIM_DIER_UIE;			    //Update interupt enabled
	TIM3->EGR |=TIM_EGR_UG;				      //update generation
	NVIC_EnableIRQ(TIM3_IRQn);		   		//enable TIM3 interupt number 30
}	
		
//----------------------------------END TIMERS----------------------------------
//timer3 interrupt
void TIM3_IRQHandler(void)
{
	TIM3->SR &=~ TIM_SR_UIF;     //clear UIF
	ticks++;
}
//us delay
void delayuS(int us)
{
	TIM3->CR1 |=TIM_CR1_CEN;      //enable counter now we use CPU
	ticks=0;
	while(ticks<us);
	TIM3->CR1 &=~TIM_CR1_CEN;    //disable counter	free CPU
	
}
//ms delay
void delaymS(int ms)
{
	delayuS(ms*1000);
}

