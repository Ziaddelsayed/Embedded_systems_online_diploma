/*
 * DC_Motor.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ziade
 */


#include "DC_Motor.h"

extern void (*DC_state)();
unsigned int speed;

void DC_init()
{
	//init DC_Motor & call  drivers
	printf("DC_Motor-----init \n");
}
void DC_Motor_Set(int s)
{
	speed=s;
	DC_state=STATE(DC_busy);
	printf("CA---------->DC\n");
}



STATE_define(DC_idle)
{
	//state action
	DC_state_id=DC_idle;

	printf("DC_idle state : speed=%d\n",speed);

}
STATE_define(DC_busy)
{
	//state action
	DC_state_id=DC_busy;
	DC_state=STATE(DC_idle);
	printf("DC_busy state : speed=%d\n",speed);

}
