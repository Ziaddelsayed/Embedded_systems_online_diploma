//startup.c
//Eng.Ziad

#include <stdint.h>
extern int main(void);

void Reset_Handler(void);
void Default_handler();


//to make it easy to overrid & all have the same handler to minimize the size

void NMI_Handler() __attribute__ ((weak,alias("Default_handler")));;
void H_fault_Handler() __attribute__ ((weak,alias("Default_handler")));;


//booking 1024 bytes located by .bss through unintialized array of int 256 elements (256*4=1024)



static unsigned long Stack_top[256] ; //static to make the scope for this file only


void  (*const   g_P_fn_Vectors[])()  __attribute__((section(".Vectors"))) =
{
	(void (*)())		((unsigned long)Stack_top + sizeof(Stack_top)),
	 &Reset_Handler,
	 &NMI_Handler,
	 &H_fault_Handler
};
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;

void Reset_Handler (void)
{
	volatile int i;
	//copy data from ROM to RAM
	unsigned int DATA_size =(unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;

	for(i=0;i<DATA_size; i++)
	{
		*((unsigned char*)P_dst++)= *((unsigned char*)P_src++);

	}

	// initialize the .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(i=0 ; i<bss_size ; i++)
	{
		*((unsigned char*)P_dst++)=(unsigned char)0;
	}

	// jump to main

	main();
}
void Default_handler()
{
	Reset_Handler();
}