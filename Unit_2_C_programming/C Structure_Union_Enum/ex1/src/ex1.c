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

struct Sstudent{
	char name[50];
	int roll;
	float marks;
};
int main(void) {
	struct Sstudent s;
	printf("Enter informations of students: \n");
	printf("Enter name:\n");
	fflush(stdin);fflush(stdout);
	scanf("%s",&s.name);
	printf("Enter roll number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s.roll);
	printf("Enter marks:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s.marks);
	printf("Displaying informations:\n");
	printf("Name:%s\n",s.name);
	printf("Roll:%d\n",s.roll);
	printf("Marks:%.2f\n",s.marks);

	return 0;
}
