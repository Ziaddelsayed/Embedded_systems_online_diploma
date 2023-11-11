/*
 ============================================================================
 Name        : ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int arr[5],*pr,i;
	printf("Input 5 number of elements in the array:\n");
	for(i=0;i<5;i++)
	{
		printf("element - %d:\n",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);

	}
	pr=&arr[4];
	printf("The elements of array in reverse order are :\n");
	for(i=5;i>0;i--)
	{
		printf("element - %d : %d\n",i,*pr);
		pr--;
	}

	return 0;
}
