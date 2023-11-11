/*
 ============================================================================
 Name        : ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int* ab=NULL;
	int m;
	m=29;

	printf("Address of m :%p\n",&m);
	printf("Value of m :%d \n",m);
	printf("\n");
	ab=&m;
	printf("Now ab is assigned with the address of m\n");
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d \n",*ab);
	printf("\n");
	m=34;
	printf("The value of m assigned to 34 now\n");
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab: %d\n",*ab);
	printf("\n");
	printf("The pointer variable ab is assigned with the value 7 now\n");
	*ab=7;
	printf("Address of m :%p\n",&m);
	printf("Value of m :%d \n",m);
	return 0;
}
