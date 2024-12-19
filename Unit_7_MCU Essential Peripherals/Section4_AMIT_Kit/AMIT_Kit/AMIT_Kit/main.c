/*
 * AMIT_Kit.c
 *
 * Created: 12/17/2024 3:33:52 PM
 * Author : Ziad El-Sayed
 */ 

#include <avr/io.h>
#include "LCD/LCD.h"
#include "GPIO/AVR_MemoryMap.h"



int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	LCD_WRITE_STRING("Learn-in-depth");
    while (1) 
    {
    }
}

