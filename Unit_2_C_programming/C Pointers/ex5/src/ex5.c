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

typedef struct {
    char *empname;
    int empid;
} Employee;

int main() {
    // Create an array of pointers to the structure
    Employee *employees[3];

    // Allocate memory for the structures and assign data
    for(int i = 0; i < 3; i++) {
        employees[i] = (Employee*) malloc(sizeof(Employee));
        employees[i]->empid = 1000 + i;
        if(i == 0) {
            employees[i]->empname = "Alex";
        } else if(i == 1) {
            employees[i]->empname = "Mohamed";
        } else {
            employees[i]->empname = "Ziad";
        }
    }

    // Create a pointer to the array
    Employee **p = employees;

    // Print the data
    for(int i = 0; i < 3; i++) {
        printf("Employee Name: %s\nEmployee ID: %d\n", p[i]->empname, p[i]->empid);
    }

    return 0;
}
