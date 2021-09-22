#include "stm32f10x.h"
#include "Timer.h"

int main ( void )
{
	RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);

	MyTimer_Struct_TypeDef * MyTimer;
	MyTimer->Timer = TIM4;
	MyTimer->ARR = MON_ARR;
	MyTimer->PSC = MON_PSC;
	
	MyTimer_Base_Init(MyTimer);
	 
	do
	{
	} while (1);
}
