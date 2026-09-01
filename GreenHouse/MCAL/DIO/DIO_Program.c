#include "DIO_Interface.h"

void DIO_SetPinDirection(uint8_t GroupName, uint8_t PinNumber, uint8_t Direction)
{
    if (Direction == Output)
    {
        switch (GroupName)
        {
        case GroupA:
            SetBit(DDRA_Reg, PinNumber);
            break;
        case GroupB:
            SetBit(DDRB_Reg, PinNumber);
            break;
        case GroupC:
            SetBit(DDRC_Reg, PinNumber);
            break;
        case GroupD:
            SetBit(DDRD_Reg, PinNumber);
            break;
        default:
            break;
        }
    }
    else if (Direction == Input)
    {
        switch (GroupName)
        {
        case GroupA:
            ClearBit(DDRA_Reg, PinNumber);
            break;
        case GroupB:
            ClearBit(DDRB_Reg, PinNumber);
            break;
        case GroupC:
            ClearBit(DDRC_Reg, PinNumber);
            break;
        case GroupD:
            ClearBit(DDRD_Reg, PinNumber);
            break;
        default:
            break;
        }
    }
}

void DIO_SetGroupDirection(uint8_t GroupName, uint8_t HexValue)
{

    switch (GroupName)
    {
    case GroupA:
        DDRA_Reg = HexValue;
        break;
    case GroupB:
        DDRB_Reg = HexValue;
        break;
    case GroupC:
        DDRC_Reg = HexValue;
        break;
    case GroupD:
        DDRD_Reg = HexValue;
        break;
    default:
        break;
    }
}

void DIO_SetPinValue(uint8_t GroupName, uint8_t PinNumber, uint8_t PinValue)
{

    if (PinValue == High)
    {
        if (GroupName == GroupA)
        {
            SetBit(PORTA_Reg, PinNumber);
        }
        else if (GroupName == GroupB)
        {
            SetBit(PORTB_Reg, PinNumber);
        }
        else if (GroupName == GroupC)
        {
            SetBit(PORTC_Reg, PinNumber);
        }
        else if (GroupName == GroupD)
        {
            SetBit(PORTD_Reg, PinNumber);
        }
    }
    else if (PinValue == Low)
    {
        if (GroupName == GroupA)
        {
            ClearBit(PORTA_Reg, PinNumber);
        }
        else if (GroupName == GroupB)
        {
            ClearBit(PORTB_Reg, PinNumber);
        }
        else if (GroupName == GroupC)
        {
            ClearBit(PORTC_Reg, PinNumber);
        }
        else if (GroupName == GroupD)
        {
            ClearBit(PORTD_Reg, PinNumber);
        }
    }
}

void DIO_SetGroupValue(uint8_t GroupName, uint8_t HexValue)
{

    switch (GroupName)
    {
    case GroupA:
        PORTA_Reg = HexValue;
        break;
    case GroupB:
        PORTB_Reg = HexValue;
        break;
    case GroupC:
        PORTC_Reg = HexValue;
        break;
    case GroupD:
        PORTD_Reg = HexValue;
        break;
    default:
        break;
    }
}

uint8_t DIO_ReadPin(uint8_t GroupName, uint8_t PinNumber)
{
    uint8_t Value = 0;

    if (GroupName <= GroupD && PinNumber <= Pin7)
    {
        switch (GroupName)
        {
        case GroupA:
            Value = ReadBit(PINA_Reg, PinNumber);
            break;
        case GroupB:
            Value = ReadBit(PINB_Reg, PinNumber);
            break;
        case GroupC:
            Value = ReadBit(PINC_Reg, PinNumber);
            break;
        case GroupD:
            Value = ReadBit(PIND_Reg, PinNumber);
            break;
        default:
            break;
        }
    }
    else
    {
        Value = 0;
        return Value;
    }
    return Value;
}

void DIO_TogglePin(uint8_t GroupName, uint8_t PinNumber)
{
    if (GroupName == GroupA)
    {
        ToggleBit(PORTA_Reg, PinNumber);
    }
    else if (GroupName == GroupB)
    {
        ToggleBit(PORTB_Reg, PinNumber);
    }
    else if (GroupName == GroupC)
    {
        ToggleBit(PORTC_Reg, PinNumber);
    }
    else if (GroupName == GroupD)
    {
        ToggleBit(PORTD_Reg, PinNumber);
    }
}
