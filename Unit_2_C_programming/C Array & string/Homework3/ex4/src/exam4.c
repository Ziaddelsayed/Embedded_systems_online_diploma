/*
 ============================================================================
 Name        : exam4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a[100],i,b,c,j;
	printf("Enter the number of elements:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		a[i]=i+1;
		printf("%d\t",a[i]);

	}
	printf("\n");
	printf("Enter the element to be inserted:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&c);

	printf("Enter the location:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&j);
	// to create location in the array
	for(i=b;i>=j;i--)
	{
		a[i]=a[i-1];
	}
	a[j-1]=c;
	//to display the array
	for(i=0;i<=b;i++)
	{

		printf("%d\t",a[i]);

	}
	return 0;
}
