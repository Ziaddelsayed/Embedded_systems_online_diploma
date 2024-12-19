/*
 * GPIO.c
 *
 * Created: 12/17/2024 3:40:21 PM
 *  Author: Ziad El-Sayed
 */ 

#include "AVR_MemoryMap.h"

void Port_Direction(uint8_t base , uint8_t state ) //base is register port
{
	if(state==output)
	{
		(*(volatile uint8_t*)(base-1))|= 0xff; //base-1 = DDR(BASE)
		
		}else{
		(*(volatile uint8_t*)(base-1))&= 0x00; //base-1 = DDR(BASE)
	}
	

}



void Pin_Direction(uint8_t base , uint8_t bin , uint8_t state)//base is register port
{
	if(state==output)
	{
		(*(volatile uint8_t*)(base-1))|= (1<<bin); //base-1 = DDR(BASE)
	
	}else{
		(*(volatile uint8_t*)(base-1))&= ~(1<<bin); //base-1 = DDR(BASE)
	}
	
}
