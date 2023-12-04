/*
 * main.c
 *
 *  Created on: Dec 3, 2023
 *      Author: ziade
 */
#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"

void setup()
{
	//init all drivers
	//init IRQ ...
	//init Hall US_driver DC_driver
	US_init();
	DC_init();
//set states pointer for each block
	CA_state=STATE(CA_waiting);
	US_state=STATE(US_busy);
	DC_state=STATE(DC_idle);

}
void main ()
{
	volatile int d;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();

		for(d=0;d<1000;d++);

	}

}


