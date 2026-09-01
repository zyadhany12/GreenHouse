#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>


#define PORTA_Reg    *((volatile uint8_t*) 0x3B)
#define DDRA_Reg     *((volatile uint8_t*) 0x3A)
#define PINA_Reg     *((volatile uint8_t*) 0x39)

#define PORTB_Reg    *((volatile uint8_t*) 0x38)
#define DDRB_Reg     *((volatile uint8_t*) 0x37)
#define PINB_Reg     *((volatile uint8_t*) 0x36)

#define PORTC_Reg    *((volatile uint8_t*) 0x35)
#define DDRC_Reg     *((volatile uint8_t*) 0x34)
#define PINC_Reg     *((volatile uint8_t*) 0x33)

#define PORTD_Reg    *((volatile uint8_t*) 0x32)
#define DDRD_Reg     *((volatile uint8_t*) 0x31)
#define PIND_Reg     *((volatile uint8_t*) 0x30)

#define ADMUX_Reg        *((volatile uint8_t*) 0x27)
#define ADCSRA_Reg       *((volatile uint8_t*) 0x26)
#define ADCH_Reg         *((volatile uint8_t*) 0x25)
#define ADCL_Reg         *((volatile uint8_t*) 0x24)
#define ADCDATA_Reg      *((volatile uint16_t*)0x24)
#define SFIOR_Reg        *((volatile uint8_t*) 0x50) 


#define MCUCR_Reg        *((volatile uint8_t*) 0x55)
#define MCUCSR_Reg       *((volatile uint8_t*) 0x54)
#define GIFR_Reg         *((volatile uint8_t*) 0x5A)
#define GICR_Reg         *((volatile uint8_t*) 0X5B)


#define TCCR0_Reg        *((volatile uint8_t*) 0x53)
#define TCNT0_Reg        *((volatile uint8_t*) 0x54)
#define OCR0_Reg         *((volatile uint8_t*) 0x5C)
#define TIMSK_Reg        *((volatile uint8_t*) 0x59)
#define TIFR_Reg         *((volatile uint8_t*) 0x58)
#define SREG_Reg         *((volatile uint8_t*) 0x5F)



#endif