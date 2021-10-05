#ifndef ADC_H
#define ADC_H
#include "stm32f10x.h"


float Init_ADC_Single_Conv(ADC_TypeDef * ADC, u16 Duree_Ech_us);

#endif