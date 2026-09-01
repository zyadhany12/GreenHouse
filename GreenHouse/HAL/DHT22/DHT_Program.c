#include "DHT_Interface.h"

void DHT_Start()
{
    DIO_SetPinDirection(DHT_Group, DHT_Pin, Output);
    DIO_SetPinValue(DHT_Group, DHT_Pin, Low);

    _delay_ms(10); 

    DIO_SetPinValue(DHT_Group, DHT_Pin, High);
    _delay_us(40); 

    DIO_SetPinDirection(DHT_Group, DHT_Pin, Input);
}

uint8_t DHT_Response()
{
    uint8_t response = 0;

    _delay_us(40);

    if (DIO_ReadPin( DHT_Group,  DHT_Pin) == Low)
    {
        _delay_us(80);

        if (DIO_ReadPin( DHT_Group,  DHT_Pin) == High)
        {
            response = 1;
        }
    }

    while ( DIO_ReadPin( DHT_Group,  DHT_Pin) == High);

    return response;
}

uint8_t DHT_ReadByte(void)
{
    uint8_t dataByte = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        while ( DIO_ReadPin( DHT_Group,  DHT_Pin) == Low);

        _delay_us(40);

        dataByte = dataByte << 1;

        if ( DIO_ReadPin( DHT_Group,  DHT_Pin) == High)
        {
            dataByte = dataByte | 1; 

            while ( DIO_ReadPin( DHT_Group,  DHT_Pin) == High);
        }
    }

    return dataByte;
} 


uint8_t DHT_GetData(uint8_t* Temperature, uint8_t* Humidity)
{
    uint8_t data[5];


    DHT_Start();
    if (DHT_Response() == 0)
    {
        return 0; 
    }
    for (uint8_t i = 0; i < 5; i++)
    {
        data[i] = DHT_ReadByte();
    }
    uint8_t calculatedSum = (uint8_t)(data[0] + data[1] + data[2] + data[3]);
    
    if (data[4] != calculatedSum)
    {
        return 0; 
    }

    uint16_t rawHumid = (data[0] << 8) | data[1];
    uint16_t rawTemp = (data[2] << 8) | data[3];

    *Humidity = (float)rawHumid / 10.0;
    *Temperature = (float)rawTemp / 10.0;

}