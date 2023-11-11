/*
 ============================================================================
 Name        : ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a[2][2], b[2][2], sum[2][2];
	int r,c;

	printf("Enter the elements of 1st matrix:\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("Enter a%d%d:\n",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%f ",&a[r][c]);
		}
	}

	printf("Enter the elements of 2nd matrix:\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("Enter b%d%d:\n",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%f ",&b[r][c]);
		}
	}
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{

			sum[r][c]= a[r][c]+b[r][c];
		}

	}
	printf("The sum of matrix :\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("%2.2f\t",sum[r][c]);
		}
		printf("\r\n");
	}
	return 0;
}
