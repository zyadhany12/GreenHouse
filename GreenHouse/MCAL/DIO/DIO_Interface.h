#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../../Common/Registers.h"
#include "DIO_Private.h"
#include "../../Common/BitMath.h"


void DIO_SetPinDirection(uint8_t GroupName, uint8_t PinNumber, uint8_t Direction); // if(1) => output // if(0) => Input

void DIO_SetGroupDirection(uint8_t GroupName, uint8_t HexValue);

void DIO_SetPinValue(uint8_t GroupName, uint8_t PinNumber, uint8_t PinValue);

void DIO_SetGroupValue(uint8_t GroupName, uint8_t HexValue);

uint8_t DIO_ReadPin(uint8_t GroupName, uint8_t PinNumber);

void DIO_TogglePin(uint8_t GroupName, uint8_t PinNumber);









#endif