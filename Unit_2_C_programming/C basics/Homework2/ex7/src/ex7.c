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
	int x,i,f=1;
	printf("Enter an integer:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if(x<0)
	{
		printf("Error! factorial of negative number doesn't exist ");
	}
	else if(x>0)
	{
		for(i=1;i<=x;i++)
		{
			f=i*f;
		}
		printf("factorial=%d",f);
	}
	else
	{
		printf("factorial=1");
	}


	return 0;
}
