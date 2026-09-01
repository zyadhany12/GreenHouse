#ifndef _STATEMACHINE_INTERFACE_H_
#define _STATEMACHINE_INTERFACE_H_


#include "../HAL/Button/BTN_Interface.h"
#include "../HAL/Relay/RELAY_Interface.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/BTN_EXTI/BTN_EXTI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include <util/delay.h>
#include "statemachine_Config.h"
#include "statemachine_Private.h"
#include "../HAL/DHT22/DHT_Interface.h"


void App_ChangeSystemMode(void);
void WaterPump_Init();
void WaterPump_Toggle();
void WaterPump_On();
void WaterPump_Off();

void Heater_Init();
void Heater_Toggle();
void Heater_Off();
void Heater_On();

void Fan_Init();
void Fan_Toggle();
void Fan_On();
void Fan_Off();

void System_Init();
void Manual_Mode();
void Home_Screen(uint8_t Temp, uint8_t Moist);
void Automatic_Mode(Climate_t* Metrics);
void Control_Function(Climate_t Metrics);
void Configuration_Mode();
void Emergency_Function(Climate_t *Metrics);
uint8_t Check_Emergency_Limits(Climate_t *Metrics);
void StateMachine(void);







#endif