#ifndef TIMER_H
	#define TIMER_H
	#include "stm32f10x.h"

	#define MON_ARR 0x1111
	#define MON_PSC 0x202E
	
	typedef struct
	{
		TIM_TypeDef * Timer ; // TIM1 à TIM4
		unsigned short ARR ;
		unsigned short PSC ;
	} MyTimer_Struct_TypeDef;
	
	void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;

	#define MyTimer_Base_Start ( Timer ) ( . . . )
	#define MyTimer_Base_Stop ( Timer ) ( . . . )
#endif
