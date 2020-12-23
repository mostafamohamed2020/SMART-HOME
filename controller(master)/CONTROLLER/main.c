/*
 * CONTROLLER.c
 * master side
 * Created: 12/18/2020 9:29:15 PM
 * Author : mostafa gomaa
 */ 

#include "BLU_TOOTH.h"

#include "SPI.h"

#include "LCD.h"

#define F_CPU 8000000

#include <util/delay.h>

int main(void)
{
	
	u_int8 rx_bluetooth_data = 0; 
	
	u_int8 to_slave_data = 0 ;
	
	u_int8 from_slave_data = 0 ;
	
	LCD_INIT();
	
	BLU_TOOTH_INIT();
	
	SPI_INIT_MASTER();
	
	SPI_MASTER_INIT_TRANSMIT();
	
	_delay_ms(1000);
	
	LCD_WRITESTRING("Smart Home Project");
	
	LCD_GOTO(2 , 4);
	
	LCD_WRITESTRING("B26_Group");
		
    /* Replace with your application code */
    while (1) 
    { 
	
		rx_bluetooth_data = RECEIVE_FROM_BLUETOOTH();
		
		LCD_CLear();
		
		while(rx_bluetooth_data == 0);
		
		to_slave_data =  (rx_bluetooth_data * 2)  ;
		
		SPI_SEND_BYTE(to_slave_data);
		 
		LCD_WRITESTRING("SENDED COMMAND : ");
		
		switch(rx_bluetooth_data)
		{
			case 'A' :
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("TOGGLE GREEN LED   ");
			break;
			
			case 'B':
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("TOGGLE YELLOW LED  ");
			break;
			
			case 'C':
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("MOTOR IN LOW SPEED   ");
			break;
			
			case 'D':
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("MEDIUM SPEED MOTOR   ");
			break;
			
			case 'E':
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("MOTOR IN HIGH SPEED  ");
			break;
			
			case 'F':
			LCD_GOTO(2 , 1);
			LCD_WRITESTRING("TURN OFF MOTOR      ");
			break;
			
			default:
			break;
		}
		
    }
	
}

