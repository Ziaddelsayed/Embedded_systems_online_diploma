/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ziad El-Sayed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "STM32F103xx.h"
#include "STM32F103C6_GPIO_driver.h"


void clock_init()
{
	//enable clock for GPIOA
	RCC_GPIOA_Clock_EN();
	//enable clock for GPIOB
	RCC_GPIOB_Clock_EN();
}
void GPIO_int()
{
	GPIO_pinConfig_t pincfg ;
	//PA1 input HighZ
	pincfg.GPIO_pinNumber = GPIO_PIN_1 ;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &pincfg);


	//PB1 output push pull mode
	pincfg.GPIO_pinNumber = GPIO_PIN_1 ;
	pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pincfg);

	//PA13 input HighZ
	pincfg.GPIO_pinNumber = GPIO_PIN_13 ;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &pincfg);

	//PB13 output push pull mode
	pincfg.GPIO_pinNumber = GPIO_PIN_13 ;
	pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pincfg);

}
void Delay(int x)
{
	unsigned i,j;
	for(i=0 ; i<x ;i++)
		for(j=0 ; j<255 ;j++);

}
int main(void)
{
	clock_init();
	GPIO_int();

	while(1)
	{
		//PA1 connected to external PUR

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) ==0) //press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) ==0);//single press
		}
		//PA13 connected to external PDR
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)==1) //press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13); ; //multi press

		}
		Delay(1);

	}

	return 0;

}
