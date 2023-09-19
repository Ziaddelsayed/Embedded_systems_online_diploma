/*
 ============================================================================
 Name        : lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
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
