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

struct SDistance{
	int feet;
	float inch;
};
int main(void) {
	struct SDistance x,y,sum;
	printf("Enter information for 1st distance:\n");
	printf("Enter in feet:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x.feet);
	printf("Enter in inch:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.inch);
	printf("Enter information for 2nd distance:\n");
	printf("Enter in feet:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y.feet);
	printf("Enter in inch:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&y.inch);
    sum.feet=x.feet+y.feet;
    sum.inch=x.inch+y.inch;
    if(sum.inch>12)
    {
    	sum.inch-=12;
    	++sum.feet;
    }
    printf("Sum of distance=%d'-%.2f'' ",sum.feet,sum.inch);
	return 0;
}
