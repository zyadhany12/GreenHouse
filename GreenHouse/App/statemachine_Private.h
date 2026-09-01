#ifndef _STATEMACHINE_PRIVATE_H_
#define _STATEMACHINE_PRIVATE_H_

#define Automatic      0
#define Manual         1





typedef struct {
    uint8_t Temp;
    uint8_t Moist;
    uint8_t Max_Temp;
    uint8_t Min_Temp;
    uint8_t Min_Moist;
    uint8_t Fatal_Cold;
    uint8_t Fatal_Heat;
    uint8_t Fatal_Moist;
} Climate_t;





#endif