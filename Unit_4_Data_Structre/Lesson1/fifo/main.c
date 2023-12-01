/*
 * main.c
 *
 *  Created on: Nov 30, 2023
 *      Author: ziade
 */
#include "fifo.h"

void main()
{
	element_type i,temp=0;
	FIFO_Buf_t FIFO_UART ;


	if(FIFO_init(&FIFO_UART,buffer1,5) == FIFO_no_error)
		printf("FIFO init ==== Done \n");

	for(i=0;i<7;i++)
	{

	   printf("FIFO Enqueue (%x)\n",i);

	   if(FIFO_enqueue(&FIFO_UART,i) == FIFO_no_error)
		printf("\t FIFO Enqueue-----Done\n");
	  else
		  printf("\t FIFO Enqueue-----Fail\n");

	}

	FIFO_print(&FIFO_UART);

	if(FIFO_dequeue(&FIFO_UART,&temp) == FIFO_no_error)
		printf("\t FIFO dequeue %x-----Done\n",temp);


	if(FIFO_dequeue(&FIFO_UART,&temp) == FIFO_no_error)
		printf("\t FIFO dequeue %x-----Done",temp);

	FIFO_print(&FIFO_UART);
}

