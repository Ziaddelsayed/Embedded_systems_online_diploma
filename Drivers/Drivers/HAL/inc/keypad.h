/*
 * keypad.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Ziad El-Sayed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32F103xx.h"
#include "STM32F103C6_GPIO_driver.h"


#define KEYPAD_PORT GPIOB


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


void Keypad_Init();
char Keypad_getkey();

GPIO_pinConfig_t PinCfg ;

#endif /*KEYPAD_H_ */
