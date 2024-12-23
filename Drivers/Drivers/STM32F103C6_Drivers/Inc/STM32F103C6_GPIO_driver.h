/*
 * STM32F103C6_GPIO_driver.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Ziad El-Sayed
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//----------------------------
//Includes
//----------------------------
#include "STM32F103xx.h"



//----------------------------
//User type definitions (structures)
//----------------------------
typedef struct{
	uint16_t GPIO_pinNumber;		//Specifies the GPIO pins to be configured.
									//This parameter must be set on @ref GPIO_PINS_define.

	uint8_t GPIO_MODE;				//Specifies the operating mode for selected pin.
									//This parameter can be a value of  @ref GPIO_MODE_define.

	uint8_t GPIO_Output_Speed;   	//Specifies speed for selected pin.
									//This parameter can be a value of  @ref GPIO_SPEED_define.
}GPIO_pinConfig_t;

//----------------------------
//Macros Configuration References
//----------------------------

//@ref GPIO_PINS_define
#define GPIO_PIN_0									((uint16_t)0x0001)/*select pin 0     1<<0*/
#define GPIO_PIN_1									((uint16_t)0x0002)/*select pin 1     1<<1*/
#define GPIO_PIN_2									((uint16_t)0x0004)/*select pin 2     1<<2*/
#define GPIO_PIN_3									((uint16_t)0x0008)/*select pin 3     1<<3*/
#define GPIO_PIN_4									((uint16_t)0x0010)/*select pin 4     1<<4*/
#define GPIO_PIN_5									((uint16_t)0x0020)/*select pin 5     1<<5*/
#define GPIO_PIN_6									((uint16_t)0x0040)/*select pin 6     1<<6*/
#define GPIO_PIN_7									((uint16_t)0x0080)/*select pin 7     1<<7*/
#define GPIO_PIN_8									((uint16_t)0x0100)/*select pin 8     1<<8*/
#define GPIO_PIN_9									((uint16_t)0x0200)/*select pin 9     1<<9*/
#define GPIO_PIN_10									((uint16_t)0x0400)/*select pin 10    1<<10*/
#define GPIO_PIN_11									((uint16_t)0x0800)/*select pin 11    1<<11*/
#define GPIO_PIN_12									((uint16_t)0x1000)/*select pin 12    1<<12*/
#define GPIO_PIN_13									((uint16_t)0x2000)/*select pin 13    1<<13*/
#define GPIO_PIN_14									((uint16_t)0x4000)/*select pin 14    1<<14*/
#define GPIO_PIN_15								    ((uint16_t)0x8000)/*select pin 15    1<<15*/
#define GPIO_PIN_All								((uint16_t)0xFFFF)/*select all pins */
#define GPIO_PIN_Mask								 0x0000FFFFu/*pins mask for assert test*/



//@ref GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function Input
#define GPIO_MODE_Analog								0x00000000u//Analog mode
#define GPIO_MODE_INPUT_FLO								0x00000001u//Floating input
#define GPIO_MODE_INPUT_PU								0x00000002u//Input with pull-up
#define GPIO_MODE_INPUT_PD								0x00000003u//Input with pull-down
#define GPIO_MODE_OUTPUT_PP								0x00000004u//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD								0x00000005u//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP							0x00000006u//Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD							0x00000007u//Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT								0x00000008u//Alternate function Input

//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M									0x00000001u//Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M									0x00000002u//Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M									0x00000003u//Output mode, max speed 50 MHz.

//@ref GPIO_PIN_State
#define GPIO_PIN_RESET									0
#define GPIO_PIN_SET									1


//@ref GPIO_RETURN_LOCK
#define  GPIO_RETURN_LOCK_Error							0
#define  GPIO_RETURN_LOCK_Enabled						1






/*
 * =================================================================================================
 	 	 	 	 	 	 	 * APIs Supported by "MCAL GPIO DRIVER" *
 * =================================================================================================
 */
void MCAL_GPIO_Init (GPIO_t* GPIOx,GPIO_pinConfig_t* pinconfig);
void MCAL_GPIO_DeInit (GPIO_t* GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_t* GPIOx,uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_t* GPIOx);

void MCAL_GPIO_WritePin (GPIO_t* GPIOx,uint16_t PinNumber,uint8_t Value);
void MCAL_GPIO_WritePort (GPIO_t* GPIOx,uint16_t Value);

void MCAL_GPIO_TogglePin (GPIO_t* GPIOx,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin (GPIO_t* GPIOx,uint16_t PinNumber);



#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
