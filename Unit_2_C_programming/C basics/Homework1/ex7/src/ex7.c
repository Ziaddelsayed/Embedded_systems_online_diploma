/*
 ============================================================================
 Name        : ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a,b;
	printf("Enter the value of a & b :");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&a,&b);
	a= a+b;
	b= a-b;
	a= a-b;
	printf("After swapping, value of a  is :%d\n",a);
	printf("After swapping, value of b  is :%d",b);

	return 0;
}
