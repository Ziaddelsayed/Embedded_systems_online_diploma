/*
 * main.c
 *
 * Created: 11/1/2024 1:25:44 PM
 *  Author: ziade
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


#define IO_BASE		0x20
#define IO_PORTD		*(volatile unsigned int*)(IO_BASE + 0x12)
#define IO_DDRD			*(volatile unsigned int*)(IO_BASE + 0x11)
#define EXIT_MCUCR		*(volatile unsigned int*)(IO_BASE + 0x35)
#define EXIT_MCUCSR		*(volatile unsigned int*)(IO_BASE + 0x35)	
#define EXIT_GICR		*(volatile unsigned int*)(IO_BASE + 0x3B)


int main(void)
{
	//enable output for Pins (5,6,7) in portD
	IO_DDRD |= (1<<5);
	IO_DDRD |= (1<<6);
	IO_DDRD |= (1<<7);
	
	//make EXIT for INT0 any logic change
	EXIT_MCUCR |= (1<<0);
	EXIT_MCUCR &= ~(1<<1);
	//make EXIT for INT1 rising edge
	EXIT_MCUCR |= (1<<2);
	EXIT_MCUCR |= (1<<3);
	//make EXIT for INT2 falling edge
	EXIT_MCUCSR |= (1<<6);
	
	//enable INT0,INT1 and INT2
	EXIT_GICR |= (1<<5);
	EXIT_GICR |= (1<<6);
	EXIT_GICR |= (1<<7);
	
	
	//enable global interrupt
	sei();
	
	 
    while(1)
    {
        IO_DDRD &= ~(1<<5); 
		IO_DDRD &= ~(1<<6);
		IO_DDRD &= ~(1<<7);
    }
}
void INT0_vect()
{
	IO_DDRD |= (1<<5);
	for(int i=0;i<1000;i++);
	
}
void INT1_vect()
{
	IO_DDRD |= (1<<6);
	for(int i=0;i<1000;i++);	
}
void INT2_vect()
{
	IO_DDRD |= (1<<7);
	for(int i=0;i<1000;i++);

}
