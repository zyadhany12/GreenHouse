#ifndef _BTN_INTERFACE_H_
#define _BTN_INTERFACE_H_


#include "BTN_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/Definitions.h"




void BTN_Init(uint8_t GroupName, uint8_t PinNumber);

uint8_t BTN_IsPressed(uint8_t GroupName, uint8_t PinNumber);















#endif