
#ifndef _BTN_EXTI_INTERFACE_H_
#define _BTN_EXTI_INTERFACE_H_


#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../Common/Definitions.h"
#include "BTN_EXTI_Private.h"



void BTNEXTI_Init(uint8_t BtnNumber);


void BTNEXTI_SetCallBack(void(*PF)(void), uint8_t BtnNumber);










#endif
