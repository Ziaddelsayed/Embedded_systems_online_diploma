/*
 * task1.c
 *
 * Created: 11/4/2024 2:40:06 PM
 * Author : ziade
 */ 
#include "util/delay.h"
#define F_CPU 1000000UL
#define DDRA	 *((volatile unsigned char*)(0x3A))
#define PORTA    *((volatile unsigned char*)(0x3B))


int main(void)
{
	unsigned int i,j;
	DDRA = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		i=0;
		j=7;
		for(i=0 ; i<8 ;i++)
		{
			PORTA |= (1<<i);
			_delay_ms(500);
			
		
		}
		
		for(j=7 ; j>=0 ;j--)
		{
			PORTA &= ~(1<<j);
			_delay_ms(500);
			
		}
		
	
    }
}

