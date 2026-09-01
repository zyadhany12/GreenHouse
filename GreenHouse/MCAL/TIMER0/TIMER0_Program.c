#include "TIMER0_Interface.h"

static uint8_t StaticPWMOutputMode = 0;
static void (*Timer0_OVFCallBack)(void) = NULL;
static void (*Timer0_CTCCallBack)(void) = NULL;

void TIMER0_Init(Timer0_Config_t config)
{
    if (config.TimerType == OverFlow)
    {
        ClearBit(TCCR0_Reg, TCCR0_WGM00);
        ClearBit(TCCR0_Reg, TCCR0_WGM01);
        TCNT0_Reg = config.OverFlowValue;
        SetBit(TIMSK_Reg, TIMSK_TOIE0);
    }
    else if (config.TimerType == CTC)
    {
        ClearBit(TCCR0_Reg, TCCR0_WGM00);
        SetBit(TCCR0_Reg, TCCR0_WGM01);
        OCR0_Reg = config.CTCValue;
        SetBit(TIMSK_Reg, TIMSK_OCIE0);
    }
    else if (config.TimerType == FastPWM)
    {
        SetBit(TCCR0_Reg, TCCR0_WGM00);
        SetBit(TCCR0_Reg, TCCR0_WGM01);
        if (config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg, TCCR0_COM00);
            SetBit(TCCR0_Reg, TCCR0_COM01);
            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }
        else if (config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg, TCCR0_COM00);
            SetBit(TCCR0_Reg, TCCR0_COM01);
            StaticPWMOutputMode = Timer0_OC0Inverting;
        }
        OCR0_Reg = ClearRegister;
    }
    else if (config.TimerType == PWM)
    {
        SetBit(TCCR0_Reg, TCCR0_WGM00);
        ClearBit(TCCR0_Reg, TCCR0_WGM01);
        if (config.PWMOutputMode == Timer0_OC0NinInverting)
        {
            ClearBit(TCCR0_Reg, TCCR0_COM00);
            SetBit(TCCR0_Reg, TCCR0_COM01);
            StaticPWMOutputMode = Timer0_OC0NinInverting;
        }
        else if (config.PWMOutputMode == Timer0_OC0Inverting)
        {
            SetBit(TCCR0_Reg, TCCR0_COM00);
            SetBit(TCCR0_Reg, TCCR0_COM01);
            StaticPWMOutputMode = Timer0_OC0Inverting;
        }
        OCR0_Reg = ClearRegister;
    }
}

void TIMER0_Start(uint8_t ClockSelectValue)
{
    if (ClockSelectValue != Timer0_Disable)
    {
        TCCR0_Reg = (TCCR0_Reg & ~ClockSelectMask) | ClockSelectValue;
    }
}
void TIMER0_Stop(void)
{
    TCCR0_Reg = (TCCR0_Reg & ~ClockSelectMask) | Timer0_Disable;
}

void TIMER0_CallBack(uint8_t TimerInterruptType, void (*PF)(void))
{
    if (PF != NULL)
    {
        if (TimerInterruptType == TIMER0_OverFlow)
        {
            Timer0_OVFCallBack = PF;
        }
        else if (TimerInterruptType == TIMER0_CTC)
        {
            Timer0_CTCCallBack = PF;
        }
    }
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (Timer0_CTCCallBack != NULL)
    {
        Timer0_CTCCallBack();
    }
}
// OverFlow
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (Timer0_OVFCallBack != NULL)
    {
        Timer0_OVFCallBack();
    }
}
