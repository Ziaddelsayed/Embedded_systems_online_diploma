/*
 * main.c
 *
 *  Created on: Oct 13, 2024
 *      Author: ziad
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "fifo.h"

#define DPRINTF(...)		{fflush(stdout);\
							fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);\
							fflush(stdin);}


int main() {
    struct Sstudent students_buffer[MAX_LENGTH];  // Buffer for students
    FIFO_Buf_t student_fifo;                       // FIFO buffer for students

    // Initialize the FIFO
    if (FIFO_init(&student_fifo, students_buffer, MAX_LENGTH) != FIFO_no_error) {
        printf("FIFO initialization failed.\n");
        return -1;
    }

    int choice, roll;
    char fname[50];
    char file_name[100];

    while (1) {
        DPRINTF("\nChoose the task that you want to perform:\n");
        DPRINTF("1. Add the student details manually\n");
        DPRINTF("2. Add the student details from text file\n");
        DPRINTF("3. Find the student details by roll number\n");
        DPRINTF("4. Find the student details by first name\n");
        DPRINTF("5. Find the student details by course ID\n");
        DPRINTF("6. Find the total number of students\n");
        DPRINTF("7. Delete the student details by the roll number\n");
        DPRINTF("8. Update the student details by the roll number\n");
        DPRINTF("9. Show all information\n");
        DPRINTF("10. Exit\n");
        DPRINTF("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student_manully(&student_fifo);  // Function to add a student manually
                break;
            case 2:
                DPRINTF("Enter the file name: ");
                scanf("%s", file_name);
                add_student_file(&student_fifo, file_name);  // Function to add students from a file
                break;
            case 3:
                DPRINTF("Enter the roll number to find: ");
                scanf("%d", &roll);
                find_rl(&student_fifo, roll);  // Function to find a student by roll number
                break;
            case 4:
                DPRINTF("Enter the first name to find: ");
                scanf("%s", fname);
                find_fn(&student_fifo, fname);  // Function to find a student by first name
                break;
            case 5:
                DPRINTF("Enter the course ID to find: ");
                scanf("%d", &roll);  // Reusing roll for course ID input
                find_c(&student_fifo, roll);  // Function to find students by course ID
                break;
            case 6:
                tot_s(&student_fifo);  // Function to display total number of students
                break;
            case 7:
                DPRINTF("Enter the roll number to delete: ");
                scanf("%d", &roll);
                del_s(&student_fifo, roll);  // Function to delete a student by roll number
                break;
            case 8:
                DPRINTF("Enter the roll number to update: ");
                scanf("%d", &roll);
                up_s(&student_fifo, roll);  // Function to update a student's details
                break;
            case 9:
                show_s(&student_fifo);  // Function to show all student information
                break;
            case 10:
                DPRINTF("Exiting the program.\n");
                return 0;  // Exit the program
            default:
                DPRINTF("Invalid choice. Please enter a number between 1 and 10.\n");
                break;
        }
    }

    return 0;  // Return success
}
