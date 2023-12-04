/*
 * CA.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ziade
 */

#include "CA.h"

extern void (*CA_state)();

unsigned int CA_speed=0;
unsigned int CA_distance=0;
unsigned int CA_threshold=50;


void US_Distance_Set(int d)
{
	CA_distance = d ;
	if(CA_distance<=CA_threshold)
		{
		CA_state = STATE(CA_waiting);
		}
	else{
			CA_state = STATE(CA_driving);
		}

	printf("US---------distance=%d--->CA\n",CA_distance);
}

STATE_define(CA_waiting)
{
	//state action
	CA_state_id= CA_waiting;
	printf("CA_waiting state : distance=%d  speed= %d\n",CA_distance,CA_speed);

	CA_speed=0;
	DC_Motor_Set(CA_speed);


}

STATE_define(CA_driving)
{
	//state action
	CA_state_id = CA_driving;
	printf("CA_driving state : distance=%d  speed= %d\n",CA_distance,CA_speed);

	CA_speed=30;
	DC_Motor_Set(CA_speed);

}
