#include "EXTI_Interface.h"

static void (*EXTI0ISR_Handler)(void) = NULL;
static void (*EXTI1ISR_Handler)(void) = NULL;
static void (*EXTI2ISR_Handler)(void) = NULL;
void EXTI_Init(uint8_t InterruptNo, uint8_t SenseControl)
{
    if (InterruptNo == Interrupt0)
    {
        if (SenseControl == FallingEdge)
        {
            ClearBit(MCUCR_Reg, MCUCR_ISC00);
            SetBit(MCUCR_Reg, MCUCR_ISC01);
        }
        else if (SenseControl == RisingEdge)
        {
            SetBit(MCUCR_Reg, MCUCR_ISC00);
            SetBit(MCUCR_Reg, MCUCR_ISC01);
        }
        else if (SenseControl == AnyChange)
        {
            SetBit(MCUCR_Reg, MCUCR_ISC00);
            ClearBit(MCUCR_Reg, MCUCR_ISC01);
        }
        else if (SenseControl == LowLevel)
        {
            ClearBit(MCUCR_Reg, MCUCR_ISC00);
            ClearBit(MCUCR_Reg, MCUCR_ISC01);
        }
    }
    else if (InterruptNo == Interrupt1)
    {
        if (SenseControl == FallingEdge)
        {
            ClearBit(MCUCR_Reg, MCUCR_ISC10);
            SetBit(MCUCR_Reg, MCUCR_ISC11);
        }
        else if (SenseControl == RisingEdge)
        {
            SetBit(MCUCR_Reg, MCUCR_ISC10);
            SetBit(MCUCR_Reg, MCUCR_ISC11);
        }
        else if (SenseControl == AnyChange)
        {
            SetBit(MCUCR_Reg, MCUCR_ISC10);
            ClearBit(MCUCR_Reg, MCUCR_ISC11);
        }
        else if (SenseControl == LowLevel)
        {
            ClearBit(MCUCR_Reg, MCUCR_ISC10);
            ClearBit(MCUCR_Reg, MCUCR_ISC11);
        }
    }
    else if (InterruptNo == Interrupt2)
    {
        if (SenseControl == FallingEdge)
        {
            ClearBit(MCUCSR_Reg, MCUCSR_ISC2);
        }
        else if (SenseControl == RisingEdge)
        {
            SetBit(MCUCSR_Reg, MCUCSR_ISC2);
        }
    }
}

void EXTI_Enable(uint8_t InterruptNo)
{
    if (InterruptNo == Interrupt0)
    {
        SetBit(GICR_Reg, GICR_INT0);
    }
    else if (InterruptNo == Interrupt1)
    {
        SetBit(GICR_Reg, GICR_INT1);
    }
    else if (InterruptNo == Interrupt2)
    {
        SetBit(GICR_Reg, GICR_INT2);
    }
}

void EXTI_Disable(uint8_t InterruptNo)
{
    if (InterruptNo == Interrupt0)
    {
        ClearBit(GICR_Reg, GICR_INT0);
    }
    else if (InterruptNo == Interrupt1)
    {
        ClearBit(GICR_Reg, GICR_INT1);
    }
    else if (InterruptNo == Interrupt2)
    {
        ClearBit(GICR_Reg, GICR_INT2);
    }
}

void EXTI_CallBack(uint8_t InterruptNo, void (*PF)(void))
{
    if (PF != NULL)
    {
        if (InterruptNo == Interrupt0)
        {
            EXTI0ISR_Handler = PF;
        }
        else if (InterruptNo == Interrupt1)
        {
            EXTI1ISR_Handler = PF;
        }
        else if (InterruptNo == Interrupt2)
        {
            EXTI2ISR_Handler = PF;
        }
    }
}

void __vector_1(void)
{
    if (EXTI0ISR_Handler != NULL)
    {
        EXTI0ISR_Handler();
    }
}
void __vector_2(void)
{
    if (EXTI1ISR_Handler != NULL)
    {
        EXTI1ISR_Handler();
    }
}
void __vector_3(void)
{
    if (EXTI2ISR_Handler != NULL)
    {
        EXTI2ISR_Handler();
    }
}