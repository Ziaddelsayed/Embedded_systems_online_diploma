/*
 * keypad.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Ziad El-Sayed
 */
#include "keypad.h"

int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns


void Keypad_Init()
{

	PinCfg.GPIO_pinNumber = R0 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = R1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = R2 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = R3 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = C0 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = C1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = C2 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_pinNumber = C3 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}
char Keypad_getkey()
{

	int i,j;
	for(i=0 ; i<4 ; i++)
	{
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);

		for(j=0 ; j<4 ; j++)
		{

			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j])==0)
					;
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}

			}
		}
	}
	return 'A';

}


