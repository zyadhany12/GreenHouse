#include "statemachine_Interface.h"

Climate_t Metrics = {
    .Temp = 0,
    .Moist = 0,
    .Min_Moist = 25,
    .Min_Temp = 20,
    .Max_Temp = 40,
    .Fatal_Heat = 50,
    .Fatal_Cold = 10,
    .Fatal_Moist = 10,
};
#define CONTROL_STATE 0
#define CONFIG_STATE 1
#define EMERGENCY_STATE 2
volatile uint8_t Control_Mode = Automatic;
volatile uint8_t System_State = CONTROL_STATE;

void App_ChangeSystemMode(void)
{
    // Toggle between modes (e.g., 0 = Auto, 1 = Manual)
    Control_Mode = !Control_Mode;
    WaterPump_Off();
    Heater_Off();
    Fan_Off();
}

void WaterPump_Init()
{
    Relay_Init(WaterPump_Group, WaterPump_Pin);
}
void WaterPump_Toggle()
{
    Relay_Toggle(WaterPump_Group, WaterPump_Pin);
}
void WaterPump_On()
{
    Relay_TurnOn(WaterPump_Group, WaterPump_Pin);
}
void WaterPump_Off()
{
    Relay_TurnOff(WaterPump_Group, WaterPump_Pin);
}

void Heater_Init()
{
    Relay_Init(Heater_Group, Heater_Pin);
}
void Heater_Toggle()
{
    Relay_Toggle(Heater_Group, Heater_Pin);
}
void Heater_On()
{
    Relay_TurnOn(Heater_Group, Heater_Pin);
}
void Heater_Off()
{
    Relay_TurnOff(Heater_Group, Heater_Pin);
}

void Fan_Init()
{
    Relay_Init(Fan_Group, Fan_Pin);
}
void Fan_Toggle()
{
    Relay_Toggle(Fan_Group, Fan_Pin);
}
void Fan_On()
{
    Relay_TurnOn(Fan_Group, Fan_Pin);
}
void Fan_Off()
{
    Relay_TurnOff(Fan_Group, Fan_Pin);
}

void System_Init()
{
    BTN_Init(WaterPumpBTN_Group, WaterPumpBTN_Pin);
    BTN_Init(HeaterBTN_Group, HeaterBTN_Pin);
    BTN_Init(FanBTN_Group, FanBTN_Pin);
    BTNEXTI_Init(Button0);
    LED_Init(HeatLED_Group, HeatLED_Pin);
    LED_Init(FanLED_Group, FanLED_Pin);
    LED_Init(WaterLED_Group, WaterLED_Pin);
    WaterPump_Init();
    WaterPump_Off();
    Heater_Init();
    Heater_Off();
    Fan_Init();
    Fan_Off();
    LCD_Init(Lcd_8bitMode);
    Keypad_Init();
    BTNEXTI_SetCallBack(App_ChangeSystemMode, Button0);
}

void Manual_Mode()
{
    if (BTN_IsPressed(WaterPumpBTN_Group, WaterPumpBTN_Pin) == Pressed)
    {
        WaterPump_Toggle();
        _delay_ms(20);
        while (BTN_IsPressed(WaterPumpBTN_Group, WaterPumpBTN_Pin) == Pressed)
        {
        }
        _delay_ms(20);
    }
    else if (BTN_IsPressed(HeaterBTN_Group, HeaterBTN_Pin) == Pressed && DIO_ReadPin(Fan_Group, Fan_Pin) != High)
    {
        Heater_Toggle();
        _delay_ms(20);
        while (BTN_IsPressed(HeaterBTN_Group, HeaterBTN_Pin) == Pressed)
        {
        }
        _delay_ms(20);
    }
    else if (BTN_IsPressed(FanBTN_Group, FanBTN_Pin) == Pressed && DIO_ReadPin(Heater_Group, Heater_Pin) != High)
    {
        Fan_Toggle();
        _delay_ms(20);
        while (BTN_IsPressed(FanBTN_Group, FanBTN_Pin) == Pressed)
        {
        }
        _delay_ms(20);
    }
}

void Home_Screen(uint8_t Temp, uint8_t Moist)
{
    LCD_GotoXY(0, 0, Lcd_8bitMode);
    LCD_WriteString((uint8_t *)"Temp : ", Lcd_8bitMode);
    LCD_GotoXY(0, 8, Lcd_8bitMode);
    LCD_WriteNumber(Temp, Lcd_8bitMode);
    LCD_WriteString((uint8_t *)" C  ", Lcd_8bitMode);

    LCD_GotoXY(1, 0, Lcd_8bitMode);
    LCD_WriteString((uint8_t *)"Humid: ", Lcd_8bitMode);
    LCD_GotoXY(1, 8, Lcd_8bitMode);
    LCD_WriteNumber(Moist, Lcd_8bitMode);
    LCD_WriteString((uint8_t *)" %  ", Lcd_8bitMode); // Clear trailing characters
}

void Automatic_Mode(Climate_t *Metrics)
{
    if (Metrics->Temp <= Metrics->Min_Temp)
    {
        Fan_Off();
        Heater_On();
    }
    else if (Metrics->Temp >= Metrics->Max_Temp)
    {
        Fan_On();
        Heater_Off();
    }
    else
    {
        Fan_Off();
        Heater_Off();
    }
    if (Metrics->Moist <= Metrics->Min_Moist)
    {
        WaterPump_On();
    }
    else
    {
        WaterPump_Off();
    }
}



void Emergency_Function(Climate_t *Metrics)
{
    if (Metrics->Temp <= Metrics->Fatal_Cold)
    {
        LED_On(HeatLED_Group, HeatLED_Pin, SourceConnection);
        LED_Off(FanLED_Group, FanLED_Pin, SourceConnection);
    }
    else if (Metrics->Temp >= Metrics->Fatal_Heat)
    {
        LED_Off(HeatLED_Group, HeatLED_Pin, SourceConnection);
        LED_On(FanLED_Group, FanLED_Pin, SourceConnection);
    }
    else
    {
        LED_Off(HeatLED_Group, HeatLED_Pin, SourceConnection);
        LED_Off(FanLED_Group, FanLED_Pin, SourceConnection);
    }

    if (Metrics->Moist <= Metrics->Fatal_Moist)
    {
        LED_On(WaterLED_Group, WaterLED_Pin, SourceConnection);
    }
    else
    {
        LED_Off(WaterLED_Group, WaterLED_Pin, SourceConnection);
    }
}

uint8_t Check_Emergency_Limits(Climate_t *Metrics)
{
    if (Metrics->Temp <= Metrics->Fatal_Cold ||
        Metrics->Temp >= Metrics->Fatal_Heat ||
        Metrics->Moist <= Metrics->Fatal_Moist)
    {
        return 1; // Emergency!
    }
    return 0; // All good
}

void Configuration_Mode()
{
    static uint8_t Menu_Step = MENU_HOME;
    static uint8_t Option = 0;
    static uint16_t New_Value = 0;
    static uint8_t Menu_Drawn = 0; // Prevents LCD flickering

    // Draw the menu instantly upon entering the state
    if (Menu_Step == MENU_HOME && Menu_Drawn == 0)
    {
        LCD_Clear(Lcd_8bitMode);
        LCD_GotoXY(0, 0, Lcd_8bitMode);
        LCD_WriteString((uint8_t *)"1-Max T 2-Min T", Lcd_8bitMode);
        LCD_GotoXY(1, 0, Lcd_8bitMode);
        LCD_WriteString((uint8_t *)"3-Min Humidity", Lcd_8bitMode);
        Menu_Drawn = 1; // Mark as drawn so we don't spam the LCD
    }

    uint8_t Value = Keypad_GetButton();
    if (Value == 0xFF)
        return; // Exit quickly if nothing is pressed

    while (Keypad_GetButton() != 0xFF)
        ; // Wait for release

    switch (Menu_Step)
    {
    case MENU_HOME:
        if (Value >= '1' && Value <= '4')
        {
            Option = Value - '0';
            New_Value = 0;

            LCD_Clear(Lcd_8bitMode);
            LCD_WriteString((uint8_t *)"New Val: ", Lcd_8bitMode);

            Menu_Step = MENU_EDITING;
        }
        // Use 'C' as a BACK button to return to normal operation!
        else if (Value == 'C')
        {
            Control_Mode = Automatic;
            Menu_Drawn = 0; // Reset for next time
            LCD_Clear(Lcd_8bitMode);
        }
        break;

    case MENU_EDITING:
        if (Value >= '0' && Value <= '9')
        {
            if (New_Value < 10) // 2-digit limit
            {
                LCD_WriteData(Value, Lcd_8bitMode);
                New_Value = (New_Value * 10) + (Value - '0');
            }
        }
        else if (Value == 'C') // Cancel typing and go back to menu
        {
            Menu_Step = MENU_HOME;
            Menu_Drawn = 0; // Force it to redraw the main menu options
        }
        else if (Value == '#') // Save
        {
            if (Option == 1)
                Metrics.Max_Temp = New_Value;
            else if (Option == 2)
                Metrics.Min_Temp = New_Value;
            else if (Option == 3)
                Metrics.Min_Moist = New_Value;

            LCD_Clear(Lcd_8bitMode);
            LCD_WriteString((uint8_t *)"Saved!", Lcd_8bitMode);
            _delay_ms(1000);

            System_State = CONTROL_STATE; // Exit config entirely
            Menu_Step = MENU_HOME;        // Reset for next time
            Menu_Drawn = 0;
        }
        break;
    }
}

void StateMachine(void)
{
    static uint16_t dht_timer = 200;

    if (dht_timer >= 200)
    {
        DHT_GetData(&Metrics.Temp, &Metrics.Moist);
        dht_timer = 0;
    }

    if (Check_Emergency_Limits(&Metrics) == 1)
    {
        System_State = EMERGENCY_STATE; 
        
    }
    else if (System_State == EMERGENCY_STATE)
    {

        System_State = CONTROL_STATE;
        LED_Off(HeatLED_Group, HeatLED_Pin, SourceConnection);
        LED_Off(FanLED_Group, FanLED_Pin, SourceConnection);
        LED_Off(WaterLED_Group, WaterLED_Pin, SourceConnection);
        LCD_Clear(Lcd_8bitMode);
    }

    if (System_State == CONTROL_STATE)
    {
        uint8_t Value = Keypad_GetButton();
        if (Value == 'C')
        {
            System_State = CONFIG_STATE;
            while (Keypad_GetButton() != 0xFF)
                ; // Wait for release
        }
    }

    switch (System_State)
    {
    case CONTROL_STATE:
        Home_Screen(Metrics.Temp, Metrics.Moist);

        if (Control_Mode == Automatic)
        {
            Automatic_Mode(&Metrics);
        }
        else if (Control_Mode == Manual)
        {
            Manual_Mode();
        }
        break;

    case CONFIG_STATE:
        Configuration_Mode();

        break;

    case EMERGENCY_STATE:
        LCD_GotoXY(0, 0, Lcd_8bitMode);
        LCD_WriteString((uint8_t *)"SYSTEM EMERGENCY", Lcd_8bitMode);
        LCD_GotoXY(1,0,Lcd_8bitMode);
        LCD_WriteString("                ",Lcd_8bitMode);

        WaterPump_Off();
        Heater_Off();
        Fan_Off();

        Emergency_Function(&Metrics);
        break;
    }

    _delay_ms(10);
    dht_timer++;
}