/*
 ============================================================================
 Name        : exa3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a[10][10];
	float t[10][10];
	int i,j,r,c;
	printf("Enter row and column of matrix :");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter the elements a%d%d:\r\n",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f ",&a[i][j]);
		}
	}
	printf("Entered matrix is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%2.2f\t",a[i][j]);
		}
		printf("\r\n");
	}
	printf(" Transpose of Matrix is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%2.2f\t",t[i][j]);
		}
		printf("\r\n");
	}
	return 0;
}
