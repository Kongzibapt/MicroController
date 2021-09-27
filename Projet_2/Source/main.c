#include "stm32f10x.h"
#include "Timer.h"
#include "GPIO.h"
#define TIM4_ENABLE 2
#define CEN_ENABLE 8

int main ( void )
{
	MyTimer_Struct_TypeDef * MyTimer = &(MyTimer_Struct_TypeDef) {.Timer = TIM4, .ARR = MON_ARR, .PSC = MON_PSC};
	MyGPIO_Struct_TypeDef* MyGPIO_LED = &(MyGPIO_Struct_TypeDef) {.GPIO = GPIOA, .GPIO_Pin = BROCHE_LED, .GPIO_Conf = Out_Ppull};
	MyGPIO_Struct_TypeDef* MyGPIO_PWM = &(MyGPIO_Struct_TypeDef) {.GPIO = GPIOB, .GPIO_Pin = BROCHE_PWM, .GPIO_Conf = AltOut_Ppull};
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Allumer TIM4
	RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);
	
	/* MyTimer->Timer = TIM4;
	MyTimer->ARR = MON_ARR;
	MyTimer->PSC = MON_PSC;
	MyGPIO->GPIO = GPIOA;
	MyGPIO->GPIO_Pin = BROCHE_LED;
	MyGPIO->GPIO_Conf = Out_Ppull; */
	
	MyGPIO_Init(MyGPIO_LED);
	MyGPIO_Init(MyGPIO_PWM);
	MyTimer_Base_Init(MyTimer);
	MyTimer_ActiveIT(MyTimer->Timer,0);
	MyTimer_PWM(MyTimer->Timer,1);
	
	do
	{	} while (1);
}
