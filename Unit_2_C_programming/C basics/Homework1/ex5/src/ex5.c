/*
 ============================================================================
 Name        : ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char G;
	printf("Enter a character:");
	fflush(stdin); fflush(stdout);
	scanf("%c",&G);
	printf("the ASCII value is %d",G);
	return 0;
}