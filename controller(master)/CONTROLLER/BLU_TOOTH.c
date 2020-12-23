/*
 * BLU_TOOTH.c
 *
 * Created: 12/19/2020 6:11:15 PM
 *  Author: mostafa gomaa
 */ 

#include "BLU_TOOTH.h"

void BLU_TOOTH_INIT(void)
{
	UART_INIT();
}

void SEND_TO_BLUETOOTH(u_int8 data)
{
	UART_SEND_BYTE(data);
}

u_int8 RECEIVE_FROM_BLUETOOTH(void)
{
	u_int8 rx_data = 0;
	
	rx_data = UART_RECEIVE_BYTE();
	
	return rx_data ; 
}

void SEND_INT_TO_BLUETOOTH(s_int32 num)
{
	u_int8 i = 0, k ;
	
	u_int8 number[10];
	
	/* In case of negative numbers */
	if(num < 0)
	{
		num *= -1;
		while(num > 0)
		{
			number[i] = (num % 10) + 48;  //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		number[i] = '-'; // storing the negative sign
		
		for(k = i+1 ; k > 0 ; k--)
		{
			SEND_TO_BLUETOOTH(number[k - 1]); //Display each number
		}
	}
	/* Zero case */
	else if(num == 0)
	{
		SEND_TO_BLUETOOTH('0');
	}
	
	/* In case of positive numbers */
	else if(num > 0)
	{
		while(num > 0)
		{
			number[i] = (num % 10) + 48; //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		
		for(k = i ; k > 0 ; k--)
		{
			SEND_TO_BLUETOOTH(number[k-1]); //Display each number
		}
	}
}
