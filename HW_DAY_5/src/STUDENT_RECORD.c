/*
 * STUDENT_RECORD.c
 *
 *  Created on: 17-Feb-2020
 *      Author: sunbeam
 */
//Accept five student record from cmd & display it in sorted form by name,rollNo & marks.

//input
//"sanket,20,90" "sarang,45,66" "vaibhav,15,70" "rudra,25,78" "ram,79,89"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[20];
	int RollNo;
	float marks;
}STUDENT_RECORD;

void Store_Record(char **argv, STUDENT_RECORD *record)
{
	//printf("hello1\n");
	//printf("%s\n",argv[2]);
	char *ptr = strtok(*argv,",");
	//printf("hello2\n");
	//printf("%s\n",ptr);
		strcpy(record->name,ptr);
		ptr = strtok(NULL,",");
	record->RollNo = atoi(ptr);
		ptr = strtok(NULL,",");
	record->marks = atof(ptr);
	//printf("hello\n");
}

int compar_by_name(const void *n1, const void *n2)
{
	STUDENT_RECORD *name1 = (STUDENT_RECORD*)n1;
	STUDENT_RECORD *name2 = (STUDENT_RECORD*)n2;

	return strcmp(name1->name,name2->name);
}

int compar_by_rollNo(const void *n1, const void *n2)
{
	STUDENT_RECORD *name1 = (STUDENT_RECORD*)n1;
	STUDENT_RECORD *name2 = (STUDENT_RECORD*)n2;

	if(name1->RollNo > name2->RollNo)
		return 1;
	else if(name1->RollNo < name2->RollNo)
		return -1;
	else
		return 0;
}

int compar_by_marks(const void *n1, const void *n2)
{
	STUDENT_RECORD *name1 = (STUDENT_RECORD*)n1;
	STUDENT_RECORD *name2 = (STUDENT_RECORD*)n2;

	if(name1->marks > name2->marks)
		return 1;
	else if(name1->marks < name2->marks)
		return -1;
	else
		return 0;}



void print_record(STUDENT_RECORD *record)
{
	for(int i=0;i<5;i++)
	{
		printf("%-20s%-5d%-5.2f\n",record[i].name,record[i].RollNo,record[i].marks);
	}
}

int main( int argc, char *argv[])
{
	STUDENT_RECORD record[5] = {};

	for(int i=1;i<6;i++)
	{
		//printf("hii\n");
		Store_Record(&argv[i],&record[i-1]);
	}

	qsort(record,5,sizeof(STUDENT_RECORD), compar_by_name);
	printf("\n####RECORD SORTED BY NAME####\n");
	print_record(record);


	qsort(record,5,sizeof(STUDENT_RECORD), compar_by_rollNo);
	printf("\n####RECORD SORTED BY ROLLNO####\n");
	print_record(record);

	qsort(record,5,sizeof(STUDENT_RECORD), compar_by_marks);
	printf("\n####RECORD SORTED BY MARKS####\n");
	print_record(record);

	//void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
	return 0;
}

