/*
 * STM32F103xx.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Ziad El-Sayed
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

//----------------------------
//Includes
//----------------------------
#include "stdlib.h"
#include <stdint.h>

//----------------------------
//Base addresses for Memories
//----------------------------
#define Flash_Memory_BASE							0x08000000UL
#define System_Memory_BASE							0x1FFFF000UL
#define SRAM_Memory_BASE							0x20000000UL
#define Peripherals_BASE							0x40000000UL
#define Cortex_M3_Internal_Peripherals				0xE0000000UL

//----------------------------
//Base addresses for AHB BUS Peripherals
//----------------------------

//RCC
#define RCC_BASE 									0x40021000UL


//----------------------------
//Base addresses for ABP1 BUS Peripherals
//----------------------------






//----------------------------
//Base addresses for ABP2 BUS Peripherals
//----------------------------

//GPIO
//A & B are fully included in LQFP48 package
#define GPIOA_BASE 									0x40010800UL
#define GPIOB_BASE 							    	0x40010C00UL

//C & D are partial included in LQFP48 package
#define GPIOC_BASE 									0x40011000UL
#define GPIOD_BASE 									0x40011400UL

//E,F&G are not included in LQFP48 package

//EXIT
#define EXIT_BASE 									0x40010400UL

//AFIO
#define AFIO_BASE 									0x40010000UL


//==========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_t;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_t;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:EXIT
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXIT_t;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	 	 	 uint32_t RESERVED0; //0x18
	volatile uint32_t MAPR2;	 //0xc1

}AFIO_t;


//==========================================================================================


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define	GPIOA							((GPIO_t *)GPIOA_BASE)
#define	GPIOB							((GPIO_t *)GPIOB_BASE)
#define	GPIOC							((GPIO_t *)GPIOC_BASE)
#define	GPIOD							((GPIO_t *)GPIOD_BASE)

#define RCC								((RCC_t *)RCC_BASE)

#define EXIT							((EXIT_t *)EXIT_BASE)

#define AFIO							((AFIO_t *)AFIO_BASE)



//==========================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_AFIO_Clock_EN()				(RCC->APB2ENR |= 1<<0)
#define RCC_GPIOA_Clock_EN()			(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_Clock_EN()			(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_Clock_EN()			(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_Clock_EN()			(RCC->APB2ENR |= 1<<5)



//-*-*-*-*-*-*-*-*-*-*-*
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103XX_H_ */