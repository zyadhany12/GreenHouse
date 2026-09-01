#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_


#include "Keypad_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/Definitions.h"
#include <util/delay.h>



void Keypad_Init();

uint8_t Keypad_GetButton();







#endif