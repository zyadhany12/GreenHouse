#include "RELAY_Interface.h"



void Relay_Init(uint8_t Group, uint8_t Pin)
{
    DIO_SetPinDirection(Group, Pin, Output);
    DIO_SetPinValue(Group, Pin, Low);
}

void Relay_TurnOn(uint8_t Group, uint8_t Pin)
{
    DIO_SetPinValue(Group, Pin, High);
}

void Relay_TurnOff(uint8_t Group, uint8_t Pin)
{
    DIO_SetPinValue(Group, Pin, Low);
}

void Relay_Toggle(uint8_t Group, uint8_t Pin)
{
    DIO_TogglePin(Group, Pin);
}




/*

void WaterPump_Init()
{
    DIO_SetPinDirection(WaterPump_Group, WaterPump_Pin, Output);
}
void WaterPump_On()
{
    DIO_SetPinValue(WaterPump_Group, WaterPump_Pin, High);
}
void WaterPump_Off()
{
    DIO_SetPinValue(WaterPump_Group, WaterPump_Pin, Low);
}
void WaterPump_Toggle()
{
    DIO_TogglePin(WaterPump_Group, WaterPump_Pin);
}






void Heater_Init()
{
    DIO_SetPinDirection(Heater_Group, Heater_Pin, Output);
}
void Heater_On()
{
    DIO_SetPinValue(Heater_Group, Heater_Pin, High);
}
void Heater_Off()
{
    DIO_SetPinValue(Heater_Group, Heater_Pin, Low);
}
void Heater_Toggle()
{
    DIO_TogglePin(Heater_Group, Heater_Pin);
}






void Fan_Init()
{
    DIO_SetPinDirection(Fan_Group, Fan_Pin, Output);
}
void Fan_On()
{
    DIO_SetPinValue(Fan_Group, Fan_Pin, High);
}
void Fan_Off()
{
    DIO_SetPinValue(Fan_Group, Fan_Pin, Low);
}
void Fan_Toggle()
{
    DIO_TogglePin(Fan_Group, Fan_Pin);
}


*/