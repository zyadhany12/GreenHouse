#include "Keypad_Interface.h"

uint8_t KeypadValue[4][3] =
    {
        {'7', '8', '9'},
        {'4', '5', '6'},
        {'1', '2', '3'},
        {'#', '0', 'C'},
};

void Keypad_Init()
{
    // Set Direction for the Buttons
    DIO_SetPinDirection(Col0_Group, Col0_Pin, Input);
    DIO_SetPinDirection(Col1_Group, Col1_Pin, Input);
    DIO_SetPinDirection(Col2_Group, Col2_Pin, Input);
    // Enable Internal Pull up for the Buttons
    DIO_SetPinValue(Col0_Group, Col0_Pin, High);
    DIO_SetPinValue(Col1_Group, Col1_Pin, High);
    DIO_SetPinValue(Col2_Group, Col2_Pin, High);

    DIO_SetPinDirection(Row0_Group, Row0_Pin, Output);
    DIO_SetPinDirection(Row1_Group, Row1_Pin, Output);
    DIO_SetPinDirection(Row2_Group, Row2_Pin, Output);
    DIO_SetPinDirection(Row3_Group, Row3_Pin, Output);

    DIO_SetPinValue(Row0_Group, Row0_Pin, High);
    DIO_SetPinValue(Row1_Group, Row1_Pin, High);
    DIO_SetPinValue(Row2_Group, Row2_Pin, High);
    DIO_SetPinValue(Row3_Group, Row3_Pin, High);
}




uint8_t Keypad_GetButton()
{
    uint8_t KPD_Value = 0xFF;
    uint8_t Result = 0;

    // 1. Map your hardware macros to arrays
    uint8_t RowGroups[4] = {Row0_Group, Row1_Group, Row2_Group, Row3_Group};
    uint8_t RowPins[4]   = {Row0_Pin, Row1_Pin, Row2_Pin, Row3_Pin};
    
    uint8_t ColGroups[3] = {Col0_Group, Col1_Group, Col2_Group};
    uint8_t ColPins[3]   = {Col0_Pin, Col1_Pin, Col2_Pin};

    for (uint8_t i = 0; i < 4; i++)
    {
        // 2. Activate current row using the array mapping
        DIO_SetPinValue(RowGroups[i], RowPins[i], Low);
        
        for (uint8_t j = 0; j < 3; j++)
        {
            // 3. Read current column using the array mapping
            Result = DIO_ReadPin(ColGroups[j], ColPins[j]);
            
            if (Result == Low) // Assuming Pressed means Low due to Pull-ups
            {
                KPD_Value = KeypadValue[i][j];
                
                // 4. Wait for release
                while (DIO_ReadPin(ColGroups[j], ColPins[j]) == Low);
                _delay_ms(50); // Debounce
                
                // 5. Deactivate row before safely returning
                DIO_SetPinValue(RowGroups[i], RowPins[i], High);
                return KPD_Value;
            }
        }
        // Deactivate row before moving to the next one
        DIO_SetPinValue(RowGroups[i], RowPins[i], High);
    }
    return KPD_Value;
}