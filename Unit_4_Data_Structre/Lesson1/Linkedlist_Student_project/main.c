
/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: ziade
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)		{fflush(stdout);\
							fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);\
							fflush(stdin);}

//effective data
typedef struct Sdata
{
	int ID ;
	char name[40];
	float  height ;
}Sdata_t;

//linked list
 struct SStudent
 {
 	Sdata_t student;
 	struct SStudent* PNextStudent ;

 };

 struct SStudent* gpFirstStudent = NULL ;

void AddStudent()
{
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text[40];
	//check list is empty == yes
	if(gpFirstStudent == NULL)
	{
		//create record
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		//assign it to gpFirstStudent
		gpFirstStudent = pNewStudent ;
	}
	//check list is empty == NO
	else
	{
		//navigate until reach  the last record
		pLastStudent = gpFirstStudent ;
		while(pLastStudent->PNextStudent)
			{
				pLastStudent= pLastStudent->PNextStudent;
			}
		//create record
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent=pNewStudent;
	}

	//fill new record


	DPRINTF("\n Enter the ID:");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter Student full Name :");
	gets(pNewStudent->student.name);


	DPRINTF("\n Enter the Height:");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);



	//set the next pointer (new_student) null
	pNewStudent->PNextStudent=NULL;

}

int delete_student ()
{
	char temp_text[40];
	unsigned int selected_id;

	// get the selected ID
	DPRINTF("\n Enter the Student ID to be deleted:\n");
	gets(temp_text);
	selected_id = atoi(temp_text);
	// list is not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;
		//loop on all records
		while(pSelectedStudent)
		{

			//compare each node with the selected ID
			if(pSelectedStudent->student.ID == selected_id)
			{
				if (pPreviousStudent)// the first isn't selected ID
				{
					pPreviousStudent->PNextStudent=pSelectedStudent->PNextStudent;

				}
				else // 1st student==ID
				{
					gpFirstStudent = pSelectedStudent->PNextStudent ;

				}
				free(pSelectedStudent);
				return 1;

			}
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}



	}
	DPRINTF("\n can't find student ID:\n");

		return 0 ;

}

void view_students()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int count=0;
	if(gpFirstStudent==NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n record number %d",count+1);
			DPRINTF("\n \t ID:%d",pCurrentStudent->student.ID);
			DPRINTF("\n \t ID:%s",pCurrentStudent->student.name);
			DPRINTF("\n \t ID:%.2f",pCurrentStudent->student.height);
			pCurrentStudent=pCurrentStudent->PNextStudent;
			count++;
		}
	}

}

void DeleteAll()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	if(gpFirstStudent==NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent =pCurrentStudent ;
			pCurrentStudent=pCurrentStudent->PNextStudent;
			free(pTempStudent);

		}
		gpFirstStudent=NULL;
	}
}
void GetNth()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int count=0;
	unsigned int selected_index;
	char temp_text[40];
	if(gpFirstStudent==NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		DPRINTF("\n Student index: ");
		gets(temp_text);
		selected_index = atoi(temp_text);

		while(pCurrentStudent)
		{
			if(selected_index==count)
			{
				DPRINTF("\n record number %d",count+1);
				DPRINTF("\n \t ID:%d",pCurrentStudent->student.ID);
				DPRINTF("\n \t ID:%s",pCurrentStudent->student.name);
				DPRINTF("\n \t ID:%.2f",pCurrentStudent->student.height);
				break;
			}
			else{
				pCurrentStudent=pCurrentStudent->PNextStudent;
				count++;
			}
		}
		printf("\nWrong choice");

	}
}

void GetCount()
{
	struct SStudent* pHead =gpFirstStudent ;
	int count=0;
	while(pHead)
	{
		count++;
		pHead=pHead->PNextStudent;
	}
	printf("\n the Length of the linked list is :%d",count);

}
void GetMid()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int temp,count1=0,count=0;
	while(pCurrentStudent)
	{
		count1++;
		pCurrentStudent=pCurrentStudent->PNextStudent;
	}
	temp=count1/2 ;
	pCurrentStudent =gpFirstStudent ;

	while(pCurrentStudent)
	{

		if(temp==count)
		{
			DPRINTF("\n record number %d",count+1);
			DPRINTF("\n \t ID:%d",pCurrentStudent->student.ID);
			DPRINTF("\n \t ID:%s",pCurrentStudent->student.name);
			DPRINTF("\n \t ID:%.2f",pCurrentStudent->student.height);
			break;
		}
		else{
			pCurrentStudent=pCurrentStudent->PNextStudent;
			count++;
		}
	}


}

int main ()
{
	char temp_text[40];
	while(1)
	{
		DPRINTF("\n==============");
		DPRINTF("\n\t Choose one of the following options\n");
		DPRINTF("\n 1:AddStudent");
		DPRINTF("\n 2:delete_student");
		DPRINTF("\n 3:view_students");
		DPRINTF("\n 4:DeleteAll");
		DPRINTF("\n 5:Show the student of index");
		DPRINTF("\n 6:Show the numbers of students");
		DPRINTF("\n 7:Show the middle student");
		DPRINTF("\n Enter an option number:");

		gets(temp_text);
		DPRINTF("\n==================");
		switch(atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			GetCount();
			break;
		case 7:
			GetMid();
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}
	}

}




