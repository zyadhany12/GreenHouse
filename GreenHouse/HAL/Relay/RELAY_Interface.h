#ifndef _RELAY_INTERFACE_H_
#define _RELAY_INTERFACE_H_


#include "RELAY_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/BitMath.h"
#include "../../Common/Definitions.h"
#include "../../Common/Registers.h"



void Relay_Init(uint8_t Group, uint8_t Pin);
void Relay_TurnOn(uint8_t Group, uint8_t Pin);
void Relay_TurnOff(uint8_t Group, uint8_t Pin);
void Relay_Toggle(uint8_t Group, uint8_t Pin);



/*

void WaterPump_Init);
void WaterPump_On();
void WaterPump_Off();
void WaterPump_Toggle();



void Heater_Init();
void Heater_On();
void Heater_Off();
void Heater_Toggle();


void Fan_Init();
void Fan_On();
void Fan_Off();
void Fan_Toggle();

*/


#endif