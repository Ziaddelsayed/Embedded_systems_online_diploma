/*
 ============================================================================
 Name        : Lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void pattern(){
	printf("The pattern of 9 =\r\n");
}

int main(void) {
	pattern();
	int i=0,j=0;
	for(i;i<=9;i++)
	{
		for(j;j<=9;j++)
		{

			printf("%d",j);
		}
		j=i+1;
		printf("\n");
	}
	return 0;
}
