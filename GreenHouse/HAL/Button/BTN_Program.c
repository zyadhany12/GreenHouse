#include "BTN_Interface.h"






void BTN_Init(uint8_t GroupName,uint8_t PinNumber)
{
    DIO_SetPinDirection(GroupName,PinNumber,Input);
    DIO_SetPinValue(GroupName,PinNumber,High);
}


uint8_t BTN_IsPressed(uint8_t GroupName, uint8_t PinNumber)
{
    uint8_t BTN_Value = 0xFF;
    BTN_Value = DIO_ReadPin(GroupName, PinNumber);
    return BTN_Value;
}
