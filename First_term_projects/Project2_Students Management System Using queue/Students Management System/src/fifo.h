/*
 * fifo.h
 *
 *  Created on: Oct 13, 2024
 *      Author: ziade
 */



#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include "stdint.h"
#include "string.h"


#define MAX_LENGTH 50



typedef struct  Sdata{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
	int num_courses;

}Sdata_t;

struct Sstudent{
	Sdata_t student;

};
//FIFO data types
typedef struct {
	unsigned int length;
	unsigned int count;
	struct Sstudent* base;
	struct Sstudent* head;
	struct Sstudent* tail;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Buf_Status;

//FIFO APIs
FIFO_Buf_Status	 FIFO_init(FIFO_Buf_t* fifo,struct Sstudent* buff,uint32_t length);
FIFO_Buf_Status	 FIFO_enqueue(FIFO_Buf_t* fifo,struct Sstudent* item);
FIFO_Buf_Status	 FIFO_dequeue(FIFO_Buf_t* fifo,	struct Sstudent* item);
FIFO_Buf_Status	 FIFO_IS_FULL(FIFO_Buf_t* fifo);


void add_student_file(FIFO_Buf_t* fifo, const char* file_name);
void add_student_manully(FIFO_Buf_t* fifo);
void find_rl(FIFO_Buf_t* fifo,int roll);
void find_fn(FIFO_Buf_t* fifo, char* fnam);
void find_c(FIFO_Buf_t* fifo, int course_id);
void tot_s(FIFO_Buf_t* fifo);
void del_s(FIFO_Buf_t* fifo, int roll);
void up_s(FIFO_Buf_t* fifo, int roll);
void show_s(FIFO_Buf_t* fifo);



#endif /* FIFO_H_ */

