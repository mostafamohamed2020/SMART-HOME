/*
 * BLU_TOOTH.h
 *
 * Created: 12/19/2020 6:11:56 PM
 *  Author: mostafa gomaa
 */ 


#ifndef BLU_TOOTH_H_
#define BLU_TOOTH_H_

#include "UART.h"

void BLU_TOOTH_INIT(void);

void SEND_TO_BLUETOOTH(u_int8 data);

u_int8 RECEIVE_FROM_BLUETOOTH(void);

void SEND_INT_TO_BLUETOOTH(s_int32 data);



#endif /* BLU_TOOTH_H_ */