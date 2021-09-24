#include "stm32f10x.h"
#include "Timer.h"

int main ( void )
{
	MyTimer_Struct_TypeDef * MyTimer = &(MyTimer_Struct_TypeDef) {.Timer = TIM4, .ARR = MON_ARR, .PSC = MON_PSC};
	
	RCC->APB1ENR |= (0x01 << 2); // Allumer TIM4
	// RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);
	
	

	
	MyTimer->Timer = TIM4;
	MyTimer->ARR = MON_ARR;
	MyTimer->PSC = MON_PSC;
	
	// MyTimer_Base_Init(MyTimer);
	
	do
	{
	} while (1);
}
