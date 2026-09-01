#include "BTN_EXTI_Interface.h"



void BTNEXTI_Init(uint8_t BtnNumber)
{
    if (BtnNumber == Button0)
    {
        DIO_SetPinDirection(BtnINT0_Group, BtnINT0_Pin, Input);
        DIO_SetPinValue(BtnINT0_Group, BtnINT0_Pin, High);
        EXTI_Init(Interrupt0, BTN0_SenseControl);
        EXTI_Enable(Interrupt0);
        GIE_Enable();
    }
    else if (BtnNumber == Button1)
    {
        DIO_SetPinDirection(BtnINT1_Group, BtnINT1_Pin, Input);
        DIO_SetPinValue(BtnINT1_Group, BtnINT1_Pin, High);
        EXTI_Init(Interrupt1, BTN1_SenseControl);
        EXTI_Enable(Interrupt1);
        GIE_Enable();
    }
    else if (BtnNumber == Button2)
    {
        DIO_SetPinDirection(BtnINT2_Group, BtnINT2_Pin, Input);
        DIO_SetPinValue(BtnINT2_Group, BtnINT2_Pin, High);
        EXTI_Init(Interrupt2, BTN2_SenseControl);
        EXTI_Enable(Interrupt2);
        GIE_Enable();
    }
}

void BTNEXTI_SetCallBack(void (*PF)(void), uint8_t BtnNumber)
{
    if (PF != NULL)
    {
        if (BtnNumber == Button0)
        {
            // Pass it straight down to the MCAL
            EXTI_CallBack(Interrupt0, PF); 
        }
        else if (BtnNumber == Button1)
        {
            EXTI_CallBack(Interrupt1, PF);
        }
        else if (BtnNumber == Button2)
        {
            EXTI_CallBack(Interrupt2, PF);
        }
    }
}



