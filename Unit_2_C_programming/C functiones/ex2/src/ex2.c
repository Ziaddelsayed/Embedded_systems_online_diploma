/*
 ============================================================================
 Name        : ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int factorial(int n);
int main(void) {
	int n;
	printf("Enter a positive integer:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("factorial of %d is %d",n,factorial(n));
	return 0;
}
int factorial(int n){
	if(n!=1)
		return n*factorial(n-1);

}
