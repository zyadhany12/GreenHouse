#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_


#include "../DIO/DIO_Interface.h"
#include "../../Common/Definitions.h"
#include "ADC_Private.h"


void ADC_Init(ADC_Config_t Config);

void ADC_StartConversion(uint8_t Channel);

uint16_t ADC_GetValue(uint8_t Channel);








#endif