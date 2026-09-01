#include "ADC_Interface.h"


void ADC_Init(ADC_Config_t config)
{
    if(config.Volt_Ref == ADC_AVREF)
    {
        ClearBit(ADMUX_Reg,ADMUX_REFS1);
        ClearBit(ADMUX_Reg,ADMUX_REFS0);
    }
    else if(config.Volt_Ref == ADC_AVCC)
    {
        ClearBit(ADMUX_Reg,ADMUX_REFS1);
        SetBit(ADMUX_Reg,ADMUX_REFS0);
    }
    else if(config.Volt_Ref == ADC_Internal)
    {
        SetBit(ADMUX_Reg,ADMUX_REFS1);
        SetBit(ADMUX_Reg,ADMUX_REFS0);
    }

    if(config.Adjust == Left_Adjust)
    {
        SetBit(ADMUX_Reg,ADMUX_ADLAR);
    }
    else if(config.Adjust == Right_Adjust)
    {
        ClearBit(ADMUX_Reg,ADMUX_ADLAR);
    }

    if(config.InterruptState == Enable)
    {
        SetBit(ADCSRA_Reg,ADCSRA_ADIE);
    }
    else if(config.InterruptState == Disable)
    {
        ClearBit(ADCSRA_Reg,ADCSRA_ADIE);
    }

    if(config.Operation_Mode == AutoMode)
    {
        SetBit(ADCSRA_Reg,ADCSRA_ADATE);
    }
    else if(config.Operation_Mode == SingleMode)
    {
        ClearBit(ADCSRA_Reg, ADCSRA_ADATE);
    }

    ADCSRA_Reg=(ADCSRA_Reg&~Adc_PrescalerMask)|(config.Prescaller);
    SetBit(ADCSRA_Reg,ADCSRA_ADEN);
}

void ADC_StartConversion(uint8_t Channel)
{
    ADMUX_Reg=(ADMUX_Reg&~Adc_ChannelMask)|Channel;
    SetBit(ADCSRA_Reg,ADCSRA_ADSC);
}


uint16_t ADC_GetValue(uint8_t Channel)
{
    ADMUX_Reg=(ADMUX_Reg&~Adc_ChannelMask)|Channel;
    SetBit(ADCSRA_Reg,ADCSRA_ADSC);
    while(ReadBit(ADCSRA_Reg,ADCSRA_ADIF) != FlagUp);

    ClearFlag(ADCSRA_Reg,ADCSRA_ADIF);
    return ADCDATA_Reg;
}