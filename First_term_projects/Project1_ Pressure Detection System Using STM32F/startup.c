//startup.c
//Eng.Ziad


#include <stdint.h>

static unsigned long stack_top[256];
void(* const g_p_fn_Vectors[])() __attribute__ ((section(".vectors")));
extern int main();
void Reset_Handler(void);
void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler()		__attribute__((weak,alias("Default_Handler")));;
void Bus_Handler() 			__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler() 	__attribute__((weak,alias("Default_Handler")));;


void(* const g_p_fn_Vectors[])() __attribute__ ((section(".vectors"))) =
{
    (void (*)())    ((unsigned long)stack_top + sizeof(stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_fault_Handler
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(void)
{
    // Copy data from ROM to RAM
    unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
    unsigned char* P_src = (unsigned char*)&_E_text;
    unsigned char* P_dst = (unsigned char*)&_S_DATA;
    for (int i = 0; i < DATA_size; i++)
    {
        *((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
    }

    // Initialize the .bss with zero
    unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
    P_dst = (unsigned char*)&_S_bss;
    for (int i = 0; i < bss_size; i++)
    {
        *((unsigned char*)P_dst++) = (unsigned char)0;
    }

    // Jump to main()
    main();
}