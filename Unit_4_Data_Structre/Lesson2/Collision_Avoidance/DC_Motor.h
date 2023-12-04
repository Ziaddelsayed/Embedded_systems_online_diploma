/*
 * DC_Motor.h
 *
 *  Created on: Dec 3, 2023
 *      Author: ziade
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

//states
enum{
	DC_idle,
	DC_busy
}DC_state_id;


//prototypes
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//global pointer to fun
void (*DC_state)();



#endif /* DC_MOTOR_H_ */
