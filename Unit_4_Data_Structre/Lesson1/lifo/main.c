/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: ziade
 */





#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"



void main()
{
	element_type i,temp=0;
	element_type buffer2 = (element_type) malloc(5*sizeof(element_type));
	LIFO_Buf_t uart_lifo , I2c_lifo ;

	//static allocation
	LIFO_init(&uart_lifo,buffer1,5);
	//dynamic allocation
	LIFO_init(&I2c_lifo,buffer2,5);

	for(i=0;i<5;i++)
		if(LIFO_Add_item(&uart_lifo,i)== LIFO_no_error)
			printf("UART_LIFO_Add : %d\n",i);

	for(i=0;i<5;i++)
		if(LIFO_get_item(&uart_lifo,&temp)== LIFO_no_error)
			printf("UART_LIFO_Get : %d\n",temp);




}
