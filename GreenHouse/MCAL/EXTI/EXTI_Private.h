#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#include <avr/interrupt.h>

#define MCUCR_ISC00     0
#define MCUCR_ISC01     1
#define MCUCR_ISC10     2
#define MCUCR_ISC11     3


#define MCUCSR_ISC2     6

#define GICR_INT1       7
#define GICR_INT0       6
#define GICR_INT2       5


#define GIFR_INTF1      7
#define GIFR_INTF0      6
#define GIFR_INTF2      5

#define Interrupt1      1
#define Interrupt0      0
#define Interrupt2      2


#define FallingEdge     2
#define RisingEdge      3
#define AnyChange       1
#define LowLevel        0


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));






#endif