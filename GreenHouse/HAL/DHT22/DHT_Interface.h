#ifndef _DHT_INTERFACE_H_
#define _DHT_INTERFACE_H_


#include "DHT_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/BitMath.h"
#include "../../Common/Definitions.h"
#include "../../Common/Registers.h"
#include <util/delay.h>




void DHT_Start();

uint8_t DHT_Response();


uint8_t DHT_ReadByte(void);

uint8_t DHT_GetData(uint8_t* Temperature, uint8_t* Humidity);






#endif