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

int main(void) {
	float x;
	printf("Enter a number:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x);
	if(x>0)
	{
		printf("%f is positive",x);
	}
	else if (x<0)
	{
		printf("%f is negative",x);
	}
	else
	{
		printf("you entered zero");
	}
	return 0;
}
