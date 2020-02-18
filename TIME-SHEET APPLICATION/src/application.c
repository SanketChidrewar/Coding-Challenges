/*
 * application.c
 *
 *  Created on: 18-Feb-2020
 *      Author: sunbeam
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int id;
	char name[50];
	char email[50];
	char mobile[20];
}Staff;

typedef struct
{
	int id;
	char name[20];
	char course[20];
	int duration;
}Module;

typedef struct
{
	int day;
	int month;
	int year;
}Date;

typedef struct
{
	int hours;
	int mins;
	int seconds;
}Time;

typedef struct
{
	int id;
	int staff_id;
	int module_id;
	Date work_date;
	Time start_time;
	int duration;

}Entry;

typedef enum{EXIT,REGISTER_STAFF,STAFF,ADMIN}MENUOPERATION_MAIN_MENU;
typedef enum{LIST_COURSES=1,MODULES_PER_COURSES,MODULES_PER_CATEGORY,WORK_ENTRY,LIST_PENDING_ENTRIES,LIST_APPROVED_ENTRIES}MENUOPERATIONS_STAFF_SUB_MENU;

int MAIN_MENU()
{
	printf("\nStudent Name : SANKET CHIDREWAR\n");
	printf("Roll Number  : 36009\n");
	printf("Center Name   : Sunbeam\n");
	printf("Course Name  : PG-DAC 2020\n");
	printf("Group Name   : ___________\n");
	printf("MISSION STATEMENT : I WILL NEVER QUIT\n");

	int choice;

	printf("\nMain menu\n0.EXIT\n1.Register staff\n2.Staff\n3.Admin");
	printf("\nENTER OPTION : ");
	scanf("%d",&choice);
	//printf("choice : %d",choice);
	return choice;
}

void take_new_staff_details()
{
	FILE *fp;
	Staff s1,s2;

	fp = fopen("staff.dat","rb+");
	if(fp != NULL)
	{
		printf("ENTER staff id : ");
		scanf("%d",&s1.id);
		fflush(stdin);
		printf("ENTER staff name : ");
		getchar();
		scanf("%[^\n]s",s1.name);
		printf("ENTER staff emaid id :");
		getchar();
		scanf("%[^\n]s",s1.email);
		printf("ENTER staff mobile number :");
		getchar();
		scanf("%[^\n]s",s1.mobile);

		//size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
		if(fwrite(&s1,sizeof(Staff),1,fp)!=0)
		{
			printf("\nSTAFF RECORD SUCCESSFULLY SAVED IN STAFF FILE\n");
			//rewind(fp);
			//fread(&s2,sizeof(Staff),1,fp);
			//printf("\nENTERD STAFF DETAILS :\n%d\n%s\n%s\n%s\n",s2.id,s2.name,s2.email,s2.mobile);

		}
		else
		{
			printf("\n###ERROR STORING STAFF RECORD###\n");
		}


		fclose(fp);
	}
	else
	{
		printf("###ERROR OPENING STAFF FILE###");
	}
}


int staff_Sub_Menu()
{
	int choice;
	printf("\n0.EXIT\n1.LIST_COURSES\n2.MODULES_PER_COURSES\n3.MODULES_PER_CATEGORY\n4.WORK_ENTRY\n5.LIST_PENDING_ENTRIES\n6.LIST_APPROVED_ENTRIES\n");
	printf("ENTER OPTION : ");
	scanf("%d",&choice);
	return choice ;
}

void display_courses()
{
	FILE *fp;
		fp = fopen("courses.txt","r+");///home/sunbeam/SUNBEAM ASSIGNMENT/Assignment 8/moviedata.txt
		if(fp==NULL)
		{
			printf("###ERROR WHILE OPENING FILE ###\n");
			exit(1);
		}
		char buffer[100];

		while(fgets(buffer,100,fp)!=NULL)
		{

		}

}



int main()
{
	int main_menu_choice;
	int staff_sub_menu_choice;
	int staff_id;

	while((main_menu_choice = MAIN_MENU())!=EXIT)
	{
		switch(main_menu_choice)
		{
		case REGISTER_STAFF:
			take_new_staff_details();
			break;
		case STAFF:
			printf("ENTER STAFF ID : ");
			scanf("%d",&staff_id);
			while((staff_sub_menu_choice = staff_Sub_Menu())!=EXIT)
			{
				switch(staff_sub_menu_choice)
				{
				case LIST_COURSES:
					display_courses();
					break;
				case MODULES_PER_COURSES:
					break;
				case MODULES_PER_CATEGORY:
					break;
				case WORK_ENTRY:
					break;
				case LIST_PENDING_ENTRIES:
					break;
				case LIST_APPROVED_ENTRIES:
					break;
				default:
					printf("\nENTER VALID OPTION :\n");
				}
			}
			break;
		case ADMIN:
			break;
		default:
			printf("ENTER VALID OPTION");
		}
	}

	return 0;

}
