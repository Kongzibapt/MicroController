#include "stm32f10x.h"
#include "Timer.h"
#include "GPIO.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
	Timer->Timer->CR1 |= TIM_CR1_CEN;
}

void TIM4_IRQHandler(void) {
	
}
