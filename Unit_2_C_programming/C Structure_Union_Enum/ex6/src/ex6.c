/*
 ============================================================================
 Name        : ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
union job{   //defining union
	         char name[32];
	         float salary;
	         int worker_no;
}u;
struct job1{
    char name[32];
    float salary;
    int worker_no;
}s;
int main(void) {
	printf("union size=%d\n",sizeof(u));
	printf("structure size=%d",sizeof(s));
	return 0;
}
