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
#include <math.h>

#define PI 3.142
#define area(r) (PI*r*r)

int main(void) {
	int radius;
	float area;
	printf("Enter the raduis:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&radius);
	area=area(radius);
	printf("Area=%.2f",area);
	return 0;
}
