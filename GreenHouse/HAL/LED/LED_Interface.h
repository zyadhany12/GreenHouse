#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_Private.h"

void LED_Init(uint8_t GroupName, uint8_t PinNumber);


void LED_On(uint8_t GroupName, uint8_t PinNumber, uint8_t ConncetionType);


void LED_Off(uint8_t GroupName, uint8_t PinNumber, uint8_t ConncetionType);


void LED_Toggle(uint8_t GroupName, uint8_t PinNumber);




#endif