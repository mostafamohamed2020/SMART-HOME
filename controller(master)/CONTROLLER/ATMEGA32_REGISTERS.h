
#ifndef ATMEGA32_REGISTERS
#define ATMEGA32_REGISTERS

#include "standard_types.h"

/*************** PORTA Registers ********************/
#define PORTA (*(volatile u_int8*) 0x3B)
#define DDRA  (*(volatile u_int8*) 0x3A)
#define PINA (*(volatile u_int8*) 0x39)

/*************** PORTB Registers ********************/
#define PORTB (*(volatile u_int8*) 0x38)
#define DDRB (*(volatile u_int8*) 0x37)
#define PINB (*(volatile u_int8*) 0x36)

/*************** PORTC Registers ********************/
#define PORTC (*(volatile u_int8*) 0x35)
#define DDRC (*(volatile u_int8*) 0x34)
#define PINC (*(volatile u_int8*) 0x33)

/*************** PORTD Registers ********************/
#define PORTD (*(volatile u_int8*) 0x32)
#define DDRD (*(volatile u_int8*) 0x31)
#define PIND (*(volatile u_int8*) 0x30)

/*************** Interrupt Registers ********************/
#define SREG (*(volatile u_int8*) 0x5F)
#define GICR (*(volatile u_int8*) 0x5B)
#define GIFR (*(volatile u_int8*) 0x5A)
#define MCUCR (*(volatile u_int8*) 0x55)
#define MCUCSR (*(volatile u_int8*) 0x54)

/*************** UART Registers ********************/
#define UDR   (*(volatile u_int8*) 0x2C)
#define UCSRA (*(volatile u_int8*) 0x2B)
#define UCSRB (*(volatile u_int8*) 0x2A)
#define UBRRL (*(volatile u_int8*) 0x29)
#define UBRRH (*(volatile u_int8*) 0x40)
#define UCSRC (*(volatile u_int8*) 0x40)

/*************** SPI Registers ********************/

/* NORMAL WAY */

#define SPCR (*(volatile u_int8*) 0x2D)
#define SPSR (*(volatile u_int8*) 0x2E)
#define SPDR (*(volatile u_int8*) 0x2F)

/** USING STRUCT **/
/*
typedef struct
{
	u_int8 SPCR;
	u_int8 SPSR;
	u_int8 SPDR;
}SPI_REGS;

#define  SPI  ((volatile SPI_REGS*)(0x2D))
*/
#endif