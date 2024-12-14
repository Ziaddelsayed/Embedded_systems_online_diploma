/*
 * LCD.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Ziad El-Sayed
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include "STM32F103xx.h"
#include "STM32F103C6_GPIO_driver.h"

#define LCD_PORT GPIOA
#define RS_SWITCH GPIO_PIN_8
#define RW_SWITCH GPIO_PIN_9
#define EN_SWITCH GPIO_PIN_10




#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

GPIO_pinConfig_t PinCfg ;
void LCD_GPIO_Init();
void LCD_Init();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_check_lcd_isbusy(void);
void LCD_Kick(void);
void LCD_clear_screen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);


#endif /* INC_LCD_H_ */