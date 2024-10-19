/*
 * fifo.c
 *
 *  Created on: Oct 13, 2024
 *      Author: ziade
 */



#include "fifo.h"
#define DPRINTF(...)		{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

//FIFO APIs
FIFO_Buf_Status	 FIFO_init(FIFO_Buf_t* fifo,struct Sstudent* buff,uint32_t length)
{
	if(buff==NULL)
		return FIFO_Null;

	fifo->base = buff ;
	fifo->head = buff ;
	fifo->tail = buff ;
	fifo->length = length ;
	fifo->count = 0 ;

	return FIFO_no_error;

}
FIFO_Buf_Status	 FIFO_enqueue(FIFO_Buf_t* fifo,struct Sstudent* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if(FIFO_IS_FULL(fifo)== FIFO_full)
		return FIFO_full;

	*(fifo->head) = *item; // Dereference item to copy the struct
	fifo->count++ ;

	//circler fifo
	if(fifo->head == (fifo->base + (fifo->length - 1)))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;

}
FIFO_Buf_Status	 FIFO_dequeue(FIFO_Buf_t* fifo,	struct Sstudent* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	//check fifo
	if(fifo->count == 0)
		return FIFO_empty;

	*item = *(fifo->tail);
	fifo->count-- ;

	//circler fifo
	if(fifo->tail == (fifo->base + (fifo->length - 1)))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;


}
FIFO_Buf_Status	 FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if(fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;

}

void add_student_manully(FIFO_Buf_t*fifo)
{
	struct Sstudent new_student;
	DPRINTF("Enter the first name:");
	scanf("%s",new_student.student.fname);
	DPRINTF("Enter the last name:");
	scanf("%s",new_student.student.lname);
	DPRINTF("Enter the roll number:");
	scanf("%d",&new_student.student.roll);
	DPRINTF("Enter the GPA:");
	scanf("%f",&new_student.student.GPA);
	DPRINTF("Enter the number of courses:");
	scanf("%d",&new_student.student.num_courses);
	for(int i=0;new_student.student.num_courses<10;i++)
	{
		DPRINTF("Enter Course ID:%d",i+1);
		scanf("%d",new_student.student.cid[i]);
	}

	if (FIFO_enqueue(fifo, &new_student)==FIFO_no_error){
		DPRINTF("[INFO]Student added successfully!\n");
	}else{
		DPRINTF("[INFO]Error: the Fifo is Full\n");
	}
}

void add_student_file(FIFO_Buf_t* fifo, const char* file_name)
{
	FILE* file= fopen(file_name,"r");
	if(!file)
	{
		DPRINTF("[INFO] Error: could not open the file \n");
		return;
	}

	char line[256];
	while(fgets(line,sizeof(line),file))
	{
		struct Sstudent new_student;
		int courses[10];
		// Parse the student details from the file (assumes specific formatting)
		int num_courses= sscanf(line, "%d %s %s %d %d %d",
				&new_student.student.roll,
				new_student.student.fname,
				new_student.student.lname,
				&courses[0], &courses[1], &courses[2]);

		if (num_courses >= 4) {
			new_student.student.num_courses = num_courses - 3;  // First three are roll, fname, lname
			// Store the course IDs
			for (int i = 0; i < new_student.student.num_courses; i++) {
				new_student.student.cid[i] = courses[i];
			}
			// Add student to FIFO
			if (FIFO_enqueue(fifo, &new_student) == FIFO_no_error) {
				DPRINTF("[INFO]Student %s %s added from file.\n", new_student.student.fname, new_student.student.lname);
			} else {
				DPRINTF("[INFO]Error: FIFO is full, cannot add more students.\n");
				break;
			}
		} else {
			DPRINTF("[INFO]Error: Invalid data format in file.\n");
		}
	}

	fclose(file);


}

// Function to find student by roll number
void find_rl(FIFO_Buf_t* fifo, int roll) {
	struct Sstudent* temp = fifo->base;
	int found = 0;
	for (unsigned int i = 0; i < fifo->count; i++) {
		if (temp->student.roll == roll) {
			DPRINTF("Found Student: %s %s, Roll: %d, GPA: %.2f, Courses: ",
					temp->student.fname, temp->student.lname,
					temp->student.roll, temp->student.GPA);
			for (int j = 0; j < temp->student.num_courses; j++) {
				DPRINTF("%d ", temp->student.cid[j]);
			}
			DPRINTF("\n");
			found = 1;
			break;  // Exit the loop once the student is found
		}else{
			temp++;
		}
	}
	if (!found) {
		DPRINTF("[INFO]No student found with roll number: %d\n", roll);
	}
}

void find_fn(FIFO_Buf_t* fifo, char* fname)
{
	struct Sstudent* temp =fifo->base;
	int found=0;
	for(int i=0;i<fifo->count;i++)
	{
		if(strcmp(temp->student.fname,fname)==0)
		{
			DPRINTF("[INFO]Found Student: %s %s, Roll: %d, GPA: %.2f, Courses: ",
					temp->student.fname, temp->student.lname,
					temp->student.roll, temp->student.GPA);
			for (int j = 0; j < temp->student.num_courses; j++) {
				DPRINTF("%d ", temp->student.cid[j]);

			}
			DPRINTF("\n");
			found = 1;
			break;  // Exit the loop once the student is found

		}
		else{
			temp++;
		}
	}
	if (!found) {
		DPRINTF("[INFO]No student found with first name: %s\n", fname);
	}


}

void find_c(FIFO_Buf_t* fifo, int course_id)
{
	struct Sstudent* temp = fifo->base;
	int found = 0; // Flag to check if any student is found
	DPRINTF("Searching for students enrolled in course ID: %d\n", course_id);

	for (unsigned int i = 0; i < fifo->count; i++) {
		for (int j = 0; j < temp->student.num_courses; j++) {
			if (temp->student.cid[j] == course_id) {
				found = 1; // Set flag to true if a student is found
				// Print the details of the student
				DPRINTF("Student Details:\n");
				DPRINTF("Roll Number: %d\n", temp->student.roll);
				DPRINTF("First Name: %s\n", temp->student.fname);
				DPRINTF("Last Name: %s\n", temp->student.lname);
				DPRINTF("GPA: %.2f\n", temp->student.GPA);
				DPRINTF("Course ID: ");
				for (int k = 0; k < temp->student.num_courses; k++) {
					DPRINTF("%d ", temp->student.cid[k]);
				}
				DPRINTF("\n----------------------\n");
				break;  // Exit inner loop once a match is found
			}
		}
		temp++;
	}

	if (!found) {
		DPRINTF("No students found enrolled in course ID: %d.\n", course_id);
	}
}
void tot_s(FIFO_Buf_t* fifo)
{

	DPRINTF("Total number of students: %d\n",fifo->count);

}
void del_s(FIFO_Buf_t* fifo, int roll) {
	struct Sstudent* temp = fifo->base; // Start from the base of the FIFO
	int found = 0; // Flag to check if the student is found

	// Loop through the FIFO to find the student by roll number
	for (unsigned int i = 0; i < fifo->count; i++) {
		if (temp->student.roll == roll) {
			found = 1; // Student found
			DPRINTF("[INFO] Found Student: %s %s, Roll: %d, GPA: %.2f\n",
					temp->student.fname, temp->student.lname,
					temp->student.roll, temp->student.GPA);
			break; // Exit the loop once the student is found
		}
		temp++; // Move to the next student
	}

	if (!found) {
		DPRINTF("[INFO] No student found with roll number: %d\n", roll);
		return; // Exit if no student was found
	}

	// Shift elements to maintain FIFO structure after deletion
	// Shift elements to maintain FIFO structure after deletion
	struct Sstudent* student_to_delete = temp; // Pointer to the student to delete
	for (unsigned int i = 0; i < fifo->count - 1; i++) {
	    if (student_to_delete + 1 < fifo->base + fifo->length) {
	        *student_to_delete = *(student_to_delete + 1); // Copy the next student to the current position
	    }
	    student_to_delete++;
	}

	// Update tail pointer if necessary
	if (fifo->tail == temp) {
	    fifo->tail++; // Move tail to the next position
	    if (fifo->tail == fifo->base + fifo->length) {
	        fifo->tail = fifo->base; // Wrap around
	    }
}
}
void up_s(FIFO_Buf_t* fifo, int roll) {
	struct Sstudent* temp = fifo->base; // Start from the base of the FIFO
	int found = 0; // Flag to check if the student is found

	// Loop through the FIFO to find the student by roll number
	for (unsigned int i = 0; i < fifo->count; i++) {
		if (temp->student.roll == roll) {
			found = 1; // Student found
			DPRINTF("Updating details for roll number %d\n", roll);

			int choice;
			DPRINTF("What would you like to update?\n");
			DPRINTF("1. Roll Number\n");
			DPRINTF("2. First Name\n");
			DPRINTF("3. Last Name\n");
			DPRINTF("4. Course ID\n");
			DPRINTF("Enter your choice (1-4): ");
			scanf("%d", &choice);

			switch (choice) {
			case 1: {
				int new_roll;
				DPRINTF("Enter new roll number: ");
				scanf("%d", &new_roll);
				temp->student.roll = new_roll; // Update roll number
				DPRINTF("Roll number updated to %d.\n", new_roll);
				break;
			}
			case 2: {
				char new_fname[50];
				DPRINTF("Enter new first name: ");
				scanf("%s", new_fname);
				strcpy(temp->student.fname, new_fname); // Update first name
				DPRINTF("First name updated to %s.\n", new_fname);
				break;
			}
			case 3: {
				char new_lname[50];
				DPRINTF("Enter new last name: ");
				scanf("%s", new_lname);
				strcpy(temp->student.lname, new_lname); // Update last name
				DPRINTF("Last name updated to %s.\n", new_lname);
				break;
			}
			case 4: {
				int new_cid;
				DPRINTF("Enter new course ID: ");
				scanf("%d", &new_cid);
				// Assuming that you want to update the first course ID
				// Adjust this if you want to update all course IDs or a specific one
				temp->student.cid[0] = new_cid;
				DPRINTF("Course ID updated to %d.\n", new_cid);
				break;
			}
			default:
				DPRINTF("Invalid choice. Please choose between 1 and 4.\n");
				break;
			}
			break; // Exit the loop after updating the student
		}
		temp++; // Move to the next student
	}

	if (!found) {
		DPRINTF("Student with roll number %d not found.\n", roll);
	}
}
void show_s(FIFO_Buf_t* fifo)
{
	struct Sstudent* temp= fifo->base;
	if(fifo->count == 0)
	{
		printf("[INFO]fifo is empyt\n");
	}
	else{
		for(int i=0; i<fifo->count;i++)
		{
			DPRINTF("Student %d: %s %s , ID=%.2f ,CID:",
					i+1,temp->student.fname,temp->student.lname,temp->student.GPA);
			for(int j=0;j<temp->student.num_courses;j++)
			{
				DPRINTF("%d",temp->student.cid[j]);

			}
			DPRINTF("\n");
			temp++;
		}
	}


}


