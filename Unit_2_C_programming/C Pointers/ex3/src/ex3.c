/*
 ============================================================================
 Name        : ex3.c
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
	char *pr=NULL;
	int i;
	char str[100];
	printf("Input a string:\n");
	fflush(stdin);fflush(stdout);
	gets(str);
	pr=&str[strlen(str)-1];
	printf("Reverse of the string is:\n");
	for(i=0;i<strlen(str);i++)
	{
		printf("%c",*pr);
		pr--;
	}
	return 0;
}
