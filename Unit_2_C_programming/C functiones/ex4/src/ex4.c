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

int power(int base,int e){
	if(e!=0)
	{
		return (base*power(base,e-1));
	}
	else
		return 1;
}

int main(void) {
	int base,e;
	printf("Enter base no:\n Enter power no(positive integer): ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&base,&e);
	printf("%d^%d=%d",base,e,power(base,e));
	return 0;
}
