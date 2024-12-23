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
#include "keypad.h"
#include "LCD.h"
#include "STM32F103C6_EXTI_driver.h"



unsigned int IRQ_flag;
void clock_init()
{
	//enable clock for GPIOA
	RCC_GPIOA_Clock_EN();
	//enable clock for GPIOB
	RCC_GPIOB_Clock_EN();
	//enable clock for AFIO
	RCC_AFIO_Clock_EN();

}

void Delay(int x)
{
	unsigned i,j;
	for(i=0 ; i<x ;i++)
		for(j=0 ; j<255 ;j++);

}
void EXTI9_CallBack(void)
{
	IRQ_flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 is happened _|--");
	Delay(1000);
	LCD_clear_screen();


}
int main(void)
{
	clock_init();
	LCD_Init();
	LCD_clear_screen();

	EXTI_PinConfig_t EXTI_cfg ;
	EXTI_cfg.EXTI_PIN=EXTI9PB9;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_RISING ;
	EXTI_cfg.P_IRQ_CallBack = EXTI9_CallBack;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable ;
	MCAL_EXTI_Init(&EXTI_cfg);

	while(1)
	{
		if(IRQ_flag)
		{
			LCD_clear_screen();
			IRQ_flag=0;

		}
	}






	return 0;
}




