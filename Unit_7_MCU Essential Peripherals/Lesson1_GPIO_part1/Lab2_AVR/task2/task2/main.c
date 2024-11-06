#include "util/delay.h"
#define F_CPU 1000000UL
#define DDRA    *((volatile unsigned char*)(0x3A))
#define PORTA   *((volatile unsigned char*)(0x3B))
#define PINA    *((volatile unsigned char*)(0x39))

#define DDRC    *((volatile unsigned char*)(0x34))
#define PORTC   *((volatile unsigned char*)(0x35))
#define PINC    *((volatile unsigned char*)(0x33))

int main(void)
{
	unsigned char flag = 0;
	DDRA = 0xff;            // Set PORTA as output
	DDRC &= ~(1 << 0);      // Set PORTC pin 0 as input
	PORTC |= (1 << 0);      // Enable pull-up resistor on PORTC pin 0

	while (1)
	{
		// Check if the button is pressed
		if (((PINC >> 0) & 1) == 0)
		{
			_delay_ms(50);  

			// Check again to confirm button press
			if (((PINC >> 0) & 1) == 0)
			{
				// Increment flag and turn on the next LED
				PORTA |= (1 << flag);
				flag++;

				// Wait for the button to be released
				while (((PINC >> 0) & 1) == 0);
				
				_delay_ms(50);  

				// If all LEDs are on, reset flag and PORTA
				if (flag > 7)
				{
					flag = 0;
					PORTA = 0x00;
				}
			}
		}
	}

	return 0;
}