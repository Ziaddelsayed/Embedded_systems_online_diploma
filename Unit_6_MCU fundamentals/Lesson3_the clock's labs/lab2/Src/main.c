typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE      0x40010800
#define GPIOA_CRH       *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 	    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define RCC_base		0x40021000
#define RCC_APB2ENR		*(volatile uint32_t*)(RCC_base + 0x18)
#define RCC_CFGR		*(volatile uint32_t*)(RCC_base + 0x04) //RCC configure

int main(void)
{

	//make APB1 clock = 4MHz

	RCC_CFGR |= (0b100<<8) ;


	//make APB2 clock = 2MHz
	RCC_CFGR |= (0b101<<11);
	//Init clock for GPIOA

	RCC_APB2ENR |= 1<<2;
	//Init GPIO
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |=  1<<13 ;

		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR  &=  ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
