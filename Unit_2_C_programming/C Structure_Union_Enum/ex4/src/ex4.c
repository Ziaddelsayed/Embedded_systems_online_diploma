/*
 ============================================================================
 Name        : ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sstudent{
	char name[50];
	int roll;
	float marks;

};

int main(void) {
	struct Sstudent S[10];
	int i;
	printf("Enter the information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("For roll number %d\n",i+1);
		printf("Enter name:\n");
		fflush(stdin);fflush(stdout);
		scanf("%s",&S[i].name);
		printf("Enter marks:\n");
		fflush(stdin);fflush(stdout);
		scanf("%f",&S[i].marks);

	}
	printf("Displaying information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("Information for roll number %d:\n",i+1);
		printf("Name:%s\n",S[i].name);
		printf("Marks:%.1f\n",S[i].marks);
	}
	return 0;
}
