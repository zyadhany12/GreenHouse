#ifndef _TIMER0_PRIVATE_H_
#define _TIMER0_PRIVATE_H_

#include <stdint.h>

#define TCCR0_FOC0      7
#define TCCR0_WGM00     6
#define TCCR0_WGM01     5
#define TCCR0_COM01     4
#define TCCR0_COM00     3
#define TCCR0_CS02      2
#define TCCR0_CS01      1
#define TCCR0_CS00      0



#define CTC         0
#define OverFlow    1
#define FastPWM     2
#define PWM         3


#define Timer0_OC0NinInverting      0
#define Timer0_OC0Inverting         1



#define TIMSK_OCIE0     1
#define TIMSK_TOIE0     0


#define TIFR_OCF0       1
#define TIFR_TOV0       0


#define Adc_Prescaler_0         0
#define Adc_Prescaler_1         1
#define Adc_Prescaler_8         2
#define Adc_Prescaler_64        3
#define Adc_Prescaler_256       4
#define Adc_Prescaler_1024      5
#define Adc_Prescaler_Falling   6
#define Adc_Prescaler_Rising    7



#define ClearRegister       0


#define Timer0_Disable      0
#define ClockSelectMask     0x07 


#define TIMER0_OverFlow     0
#define TIMER0_CTC          1

typedef struct 
{
    uint8_t TimerType;
    uint8_t Prescaller;
    uint8_t OverFlowValue;
    uint8_t CTCValue;
    uint8_t PWMOutputMode;
}Timer0_Config_t;



void __vector_10(void)   __attribute__((signal));
void __vector_11(void)   __attribute__((signal));








#endif