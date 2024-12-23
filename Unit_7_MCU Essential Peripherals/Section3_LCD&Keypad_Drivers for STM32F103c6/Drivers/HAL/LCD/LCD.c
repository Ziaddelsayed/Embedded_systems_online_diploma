/*
 * LCD.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Ziad El-Sayed
 */
#include "LCD.h"

void ms_wait(int x)
{
	unsigned i,j;
	for(i=0 ; i<x ;i++)
		for(j=0 ; j<255 ;j++);

}
void LCD_GPIO_Init()
{

	//EN_SWITCH , RS_SWITCH and RW_SWITCH Output
	PinCfg.GPIO_pinNumber = EN_SWITCH ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = RS_SWITCH ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = RW_SWITCH ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


	//Data Pins are Output push pull wit 10M Speed
	PinCfg.GPIO_pinNumber = GPIO_PIN_0 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_2 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_3 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_4 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_5 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_6 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_7 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


	//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);

}

void LCD_Init()
{
	ms_wait(20);
	LCD_GPIO_Init();
	ms_wait(15);

	LCD_clear_screen();

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);


}

void LCD_WRITE_COMMAND(unsigned char command)
{

	MCAL_GPIO_WritePort(LCD_PORT, command);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);

	ms_wait(1);
	LCD_Kick();

}



void LCD_WRITE_CHAR(unsigned char character)
{

	MCAL_GPIO_WritePort(LCD_PORT, character);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_SET);

	ms_wait(1);
	LCD_Kick();

}


void LCD_WRITE_STRING(char* string)
{
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}


}


void LCD_check_lcd_isbusy(void)
{
	//to check busy , Data Pins are Input.
	PinCfg.GPIO_pinNumber = GPIO_PIN_0 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


	PinCfg.GPIO_pinNumber = GPIO_PIN_2 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_3 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


	PinCfg.GPIO_pinNumber = GPIO_PIN_4 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_5 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_6 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_7 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	//	LCD_PORT |= (1 << RW_SWITCH);
	//	LCD_PORT &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);

	//	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	LCD_Kick();

	//	LCD_PORT &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);


}




void LCD_Kick(void)
{
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_SET);
	ms_wait(50);
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_RESET);

}




void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);

}



void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}

}


