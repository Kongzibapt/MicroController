#include "stm32f10x.h"
#include "Timer.h"
#include "GPIO.h"
#define TIM4_ENABLE 2
#define CEN_ENABLE 8

int main ( void )
{
	MyTimer_Struct_TypeDef * MyTimer = &(MyTimer_Struct_TypeDef) {.Timer = TIM4, .ARR = MON_ARR, .PSC = MON_PSC};
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Allumer TIM4
	
	TIM4->DIER = TIM_DIER_UIE; // Vers pending
	
	//|= NVIC_SetPendingIRQ
	NVIC->ISER[0] |= NVIC_ISER_SETENA_30;
	MyTimer_Base_Init(MyTimer);
	
	do
	{
	} while (1);
}
