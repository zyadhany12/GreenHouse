#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include <stdint.h>
#include "../DIO/DIO_Interface.h"
#include "../../Common/Definitions.h"
#include "EXTI_Private.h"



void EXTI_Init(uint8_t InterruptNo, uint8_t SenseControl);

void EXTI_Enable(uint8_t InterruptNo);
void EXTI_Disable(uint8_t InterruptNo);

void EXTI_CallBack(uint8_t InterruptNo,void (*PF)(void));



#endif