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

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

void clock_init()
{
	//enable clock for GPIOA
	RCC_GPIOA_Clock_EN();
	//enable clock for GPIOB
	RCC_GPIOB_Clock_EN();
}
void GPIO_int()
{
	GPIO_pinConfig_t PinCfg;
	//PA1 input HighZ
	PinCfg.GPIO_pinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	PinCfg.GPIO_pinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
}
void Delay(int x)
{
	unsigned i,j;
	for(i=0 ; i<x ;i++)
		for(j=0 ; j<255 ;j++);

}
int main(void)
{

	unsigned char key_pressed;
	clock_init();
	GPIO_int();
	LCD_Init();
	Keypad_Init();

	LCD_WRITE_STRING("Hello World!");
	Delay(30);
	LCD_clear_screen();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9); /* write data on to the LED port */
		Delay(100);
		/* wait for 1 second */
	}
	LCD_clear_screen();
	Keypad_Init();
	LCD_WRITE_STRING("Keypad is ready");
	Delay(30);
	LCD_clear_screen();
	while(1)
	{

		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;

			//PA1 connected to external PUR

			/*	if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) ==0) //press
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
			 */
		}
	}
	return 0;
}




