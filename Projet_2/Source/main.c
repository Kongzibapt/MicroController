#include "stm32f10x.h"
#include "Timer.h"
#include "GPIO.h"
#define TIM4_ENABLE 2
#define BROCHE_LED 5
#define CEN_ENABLE 8

int main ( void )
{
	MyTimer_Struct_TypeDef * MyTimer = &(MyTimer_Struct_TypeDef) {.Timer = TIM4, .ARR = MON_ARR, .PSC = MON_PSC};
	MyGPIO_Struct_TypeDef* MyGPIO = &(MyGPIO_Struct_TypeDef) {.GPIO = GPIOA, .GPIO_Pin = BROCHE_LED, .GPIO_Conf = Out_Ppull};
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Allumer TIM4
	RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);
	
	MyGPIO_Init(MyGPIO);
	MyTimer_Base_Init(MyTimer);
	
	do
	{
	} while (1);
}
