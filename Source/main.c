#include "stm32f10x.h"
#include "stdio.h"
#include <stdlib.h>
#include "GPIO.h"
#define BROCHE_LED (5)
#define BITS_PAR_BROCHE (4)
#define OUT_PUSHPULL_2MHZ (0x2)
#define BROCHE_BOUTON (13)

int LireValeur(int numBroche , GPIO_TypeDef* gpio) {
	return (gpio->IDR & (0x1 << numBroche));
}

void EcrireValeur(int numBroche, GPIO_TypeDef* gpio, int valeur) {
	if (valeur) {
		gpio->ODR |= 1<<numBroche;
	} else {
		gpio->ODR &= ~(1<<numBroche);
	}
}

int main ( void )
{
	RCC->APB2ENR |= (0x01 << 2)|(0x01 << 3)|(0x01 << 4);
	
	 
	 MyGPIO_Struct_TypeDef  * MyGPIO = &(MyGPIO_Struct_TypeDef) {.GPIO = GPIOA, .GPIO_Pin = BROCHE_LED, .GPIO_Conf = Out_Ppull};
	// MyGPIO = malloc(sizeof(MyGPIO_Struct_TypeDef));
	 // MyGPIO.GPIO = GPIOA;
	
	 // MyGPIO.GPIO_Pin = BROCHE_LED;
	 // MyGPIO.GPIO_Conf = Out_Ppull;
	
	 MyGPIO_Init(MyGPIO);
	
	// MyGPIO->GPIO->CRL &= ~(0xF<<((MyGPIO->GPIO_Pin)*BITS_PAR_BROCHE)); //  
	// MyGPIO->GPIO->CRL |= (MyGPIO->GPIO_Conf<<((MyGPIO->GPIO_Pin)*BITS_PAR_BROCHE));
	
	// GPIOA->CRL &= ~(0xF<<(BROCHE_LED*BITS_PAR_BROCHE)); // On met tous les bits de la broche 5 à 0 
	// GPIOA->CRL |= (OUT_PUSHPULL_2MHZ<<(BROCHE_LED*BITS_PAR_BROCHE)); // On met la valeur 2 pour la broche 5
	
	 
	 
	do
	{
		if (!MyGPIO_Read(GPIOC, BROCHE_BOUTON)) {
			MyGPIO_Set(MyGPIO->GPIO, MyGPIO->GPIO_Pin);
		} else {
			MyGPIO_Reset(MyGPIO->GPIO, MyGPIO->GPIO_Pin);
		} 
	} while (1);
}
