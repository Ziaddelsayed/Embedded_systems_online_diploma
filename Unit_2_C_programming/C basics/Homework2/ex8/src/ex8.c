/*
 ============================================================================
 Name        : ex8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x,y,z;
	char choice;
	printf("Enter operator either + or - or * or/ :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&choice);
	switch(choice)
	{
	case '+':
	{
		printf("Enter two operands:");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x,&y);
		z=x+y;
		printf("x+y=%f",z);
	}
	break;
	case'-':
	{
		printf("Enter two operands:");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x,&y);
		z=x-y;
		printf("x-y=%f",z);
	}
	break;
	case'*':
	{
		printf("Enter two operands:");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&x,&y);
		z=x*y;
		printf("x*y=%f",z);
	}
	break;
	case'/':
	{
		printf("Enter two operands:");
				fflush(stdin); fflush(stdout);
				scanf("%f %f",&x,&y);
				z= x/y ;
				printf("x/y=%f",z);
	}
	break;
	default:
		printf("wrong choice");
		break;
	}
	return 0;
}
