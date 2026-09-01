#ifndef _TIMER0_INTERFACE_H_
#define _TIMER0_INTERFACE_H_


#include "TIMER0_Private.h"
#include "../DIO/DIO_Interface.h"
#include "../../Common/Definitions.h"

void TIMER0_Init(Timer0_Config_t config);

void TIMER0_Start(uint8_t ClockSelectValue);


void TIMER0_Stop(void);

void TIMER0_CallBack(uint8_t TimerInterruptType, void (*PF)(void));










#endif