/*
 ============================================================================
 Name        : ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,temp;
	printf("Enter the value of a :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter the value of b :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	temp=a;
	printf("After swapping, value of a =%f\n",a=b);
	printf("After swapping, value of b =%f",b=temp);
	return 0;
}
