/*
 * MOTOR.h
 *
 * Created: 12/20/2020 1:05:26 AM
 *  Author: mostafa gomaa
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO.h"

#include "TIMER0.h"

void MOTOR_INIT(void);

void TURN_CLOCK_DIR(void);

void TURN_ANTI_CLOCK_DIR(void);

void TURN_OFF_MOTOR(void);

void APPLY_LOW_SPEED(void);

void APPLY_MIDIUM_SPEED(void);

void APPLY_HIGH_SPEED(void);

#endif /* MOTOR_H_ */