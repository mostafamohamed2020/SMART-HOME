/*
 * GccApplication1.c
 * slave side
 * Created: 12/19/2020 2:05:13 AM
 * Author : mostafa gomaa
 */ 

#include "SPI.h"

#include "LED.h"

#include "DIO.h"

#include "MOTOR.h"

#include "APPLIANCES_LIST.h"

#define F_CPU 8000000

#include <util/delay.h>

int main(void)
{
    u_int8 rx_data = 0 ;
	
	u_int8 tx_data = 0 ; 
	
	LED_INIT(DIO_PORTC , DIO_PIN0);
	
	LED_INIT(DIO_PORTC , DIO_PIN1);
	
	MOTOR_INIT();
	
	SPI_INIT_SLAVE();
	
    while (1) 
    {
		
		rx_data = SPI_RECEIVE_BYTE(tx_data);
		
		while(rx_data == 0);
		
		switch(rx_data)
		{
			case TOGGLE_GREEN_LED :
			 LED_TOGGLE(DIO_PORTC , DIO_PIN0 );
			break;
			
			case TOGGLE_YELLOW_LED:
			 LED_TOGGLE(DIO_PORTC , DIO_PIN1 );
			break;
			
			case TURN_ON_LOW_SPEED_MOTOR:
			 APPLY_LOW_SPEED();
			break;
			
			case TURN_ON_MIDIUM_SPEED_MOTOR:
			 APPLY_MIDIUM_SPEED();
			break;
			
			case TURN_ON_HIGH_SPEED_MOTOR:
			 APPLY_HIGH_SPEED();
			break;
			
			case TURN_FF_MOTOR:
			 TURN_OFF_MOTOR();
			break;
			
			default:
			break;
		}
	
    }
	
}

