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

struct SNum{
	float R_num;
	float I_num;
};

struct SNum addnum(struct SNum A,struct SNum B)
{
	struct SNum C;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&A.R_num,&A.I_num);
	printf("For 2nd complex number\n");
	printf("Enter real and imaginary respectively:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&B.R_num,&B.I_num);
	C.R_num=A.R_num+B.R_num;
	C.I_num=A.I_num+B.I_num;
	return C;
	}
int main(void) {
    struct SNum X,Y,Z;

    Z=addnum(X,Y);
    printf("sum=%.1f+j%.1f",Z.R_num,Z.I_num);
	return 0;
}
