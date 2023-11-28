
//Eng.Ziad


#define SYSCTL_RCGC2_R		(*((volatile unsigned long*)0x400FE108)) 
#define GPIO_PORTF_DIR_R	(*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R	(*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R	(*((volatile unsigned long*)0x400253FC))
#define PIN_SET				(1<<3)


int main()
{
	volatile unsigned long delay;

	SYSCTL_RCGC2_R |= 0x20;

	//to make sure GPIO is up and running

	for(delay=0;delay<200;delay++);


	GPIO_PORTF_DIR_R |= PIN_SET ;	//Dir is output for pin 3 port F
	
	GPIO_PORTF_DEN_R |= PIN_SET ;

	while(1)
	{
		GPIO_PORTF_DATA_R |= PIN_SET ;

		for(delay=0;delay<200000;delay++);

		GPIO_PORTF_DATA_R &= ~(PIN_SET) ;	

		for(delay=0;delay<200000;delay++);	

	}


	return 0;

}
