/*
 * AVR_MemoryMap.h
 *
 * Created: 12/17/2024 3:40:52 PM
 *  Author: Ziad El-Sayed
 */ 

#include "stdint.h"

#ifndef AVR_MEMORYMAP_H_
#define AVR_MEMORYMAP_H_

#define PORTA				(*(volatile unsigned char*)(0x3B))
#define PORTB				(*(volatile unsigned char*)(0x38))
#define PORTC				(*(volatile unsigned char*)(0x35))
#define PORTD				(*(volatile unsigned char*)(0x32))


#define DDRA				(*(volatile unsigned char*)(0x3A))
#define DDRB				(*(volatile unsigned char*)(0x37))
#define DDRC				(*(volatile unsigned char*)(0x34))
#define DDRD				(*(volatile unsigned char*)(0x31))


#define PINA				(*(volatile unsigned char*)(0x39))
#define PINB				(*(volatile unsigned char*)(0x36))
#define PINC				(*(volatile unsigned char*)(0x33))
#define PIND				(*(volatile unsigned char*)(0x30))


//base addresses 
#define portA  0x3B
#define portB  0x38

#define output 1
#define input  0

void Port_Direction(uint8_t base , uint8_t state ); //base is register port
void Pin_Direction(uint8_t base , uint8_t bin , uint8_t state);//base is register port







#endif /* AVR_MEMORYMAP_H_ */