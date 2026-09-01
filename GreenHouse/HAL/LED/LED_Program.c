#include "LED_Interface.h"



void LED_Init(uint8_t GroupName, uint8_t PinNumber)
{
    DIO_SetPinDirection(GroupName,PinNumber,Output);
}



void LED_On(uint8_t GroupName, uint8_t PinNumber, uint8_t ConncetionType)
{
    if(ConncetionType == SourceConnection)
    {
        DIO_SetPinValue(GroupName,PinNumber,High);
    }
    else if(ConncetionType == SinkConnection)
    {
        DIO_SetPinValue(GroupName,PinNumber,Low);
    }
}




void LED_Off(uint8_t GroupName, uint8_t PinNumber, uint8_t ConncetionType)
{
    if(ConncetionType == SourceConnection)
    {
        DIO_SetPinValue(GroupName,PinNumber,Low);
    }
    else if(ConncetionType == SinkConnection)
    {
        DIO_SetPinValue(GroupName,PinNumber,High);
    }
}


void LED_Toggle(uint8_t GroupName, uint8_t PinNumber)
{
    DIO_TogglePin(GroupName,PinNumber);
}