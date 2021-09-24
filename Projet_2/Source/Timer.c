#include "stm32f10x.h"
#include "Timer.h"
#include "GPIO.h"
#define BROCHE_LED (5)
#define OUT_PUSHPULL_2MHZ (0x2)

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
	Timer->Timer->CR1 |= TIM_CR1_CEN;
	Timer->Timer->DIER = TIM_DIER_UIE; // Vers pending
	NVIC->ISER[0] |= NVIC_ISER_SETENA_30;
}



void TIM4_IRQHandler(void) {
	MyGPIO_Toggle(GPIOA, BROCHE_LED);
	TIM4->SR &= ~(TIM_SR_UIF);
}
