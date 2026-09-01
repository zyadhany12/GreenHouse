#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include <stdint.h>
#define  ADMUX_REFS1        7
#define  ADMUX_REFS0        6
#define  ADMUX_ADLAR        5


#define  ADCSRA_ADEN        7
#define  ADCSRA_ADSC        6
#define  ADCSRA_ADATE       5
#define  ADCSRA_ADIF        4
#define  ADCSRA_ADIE        3
#define  ADCSRA_ADPS2       2
#define  ADCSRA_ADPS1       1
#define  ADCSRA_ADPS0       0


#define  SFIOR_ADTS2        7
#define  SFIOR_ADTS1        6
#define  SFIOR_ADTS0        5


#define ADC_AVREF           0
#define ADC_AVCC            1
#define ADC_Internal        2


#define Right_Adjust        0
#define Left_Adjust         1

#define Adc_Prescaler_2      1
#define Adc_Prescaler_4      2
#define Adc_Prescaler_8      3
#define Adc_Prescaler_16     4
#define Adc_Prescaler_32     5
#define Adc_Prescaler_64     6
#define Adc_Prescaler_128    7



#define Adc_ChannelMask        0x1F
#define Adc_PrescalerMask      0x07
#define Adc_ADTSMask           0xE0


#define Adc_SingleEndedChannel0       0 
#define Adc_SingleEndedChannel1       1
#define Adc_SingleEndedChannel2       2
#define Adc_SingleEndedChannel3       3
#define Adc_SingleEndedChannel4       4
#define Adc_SingleEndedChannel5       5
#define Adc_SingleEndedChannel6       6
#define Adc_SingleEndedChannel7       7


#define AutoMode        1
#define SingleMode      0


#define Enable      1
#define Disable     0

typedef struct 
{
    uint8_t Volt_Ref;
    uint8_t Adjust;
    uint8_t Prescaller;
    uint8_t InterruptState;
    uint8_t Operation_Mode;
} ADC_Config_t;




#endif