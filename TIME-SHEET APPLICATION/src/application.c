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
typedef enum{LIST_COURSES=1,MODULES_PER_COURSES,MODULES_PER_CATEGORY,WORK_ENTRY,LIST_PENDING_ENTRIE,LIST_APPROVED_ENTRIE}MENUOPERATIONS_STAFF_SUB_MENU;
typedef enum{ADD_COURSE=2,LIST_ALL_MODULES,FIND_MODULES_BY_COURSE_AND_NAME,EDIT_MODULE,DELETE_MODULE,LIST_PENDING_ENTRIES,LIST_APPROVED_ENTRIES,APPROVED_ENTRIES,ADD_MODULE}MENUOPERATION_ADMIN_SUB_MENU;

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
	Staff s1;
	//Staff s2;

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

void display_courses_from_file()
{
	FILE *fp;
		fp = fopen("courses.txt","r+");///home/sunbeam/SUNBEAM ASSIGNMENT/Assignment 8/moviedata.txt
		if(fp==NULL)
		{
			printf("###ERROR WHILE OPENING FILE ###\n");
			exit(1);
		}
		else
		{
			char buffer[20];

			printf("\nLIST OF COURSES IN FILE ARE :\n");
			while(fgets(buffer,20,fp)!=NULL)
				{
					printf("%s",buffer);
				}
			fclose(fp);
		}
}

void to_find_modules_per_course(
{
	FILE *fp;
	Module m;
	char course_name[30];
			fp = fopen("modules.dat","rb+");
			if(fp != NULL)
			{
					rewind(fp);
					printf("\nENTER COURSE NAME :");
					getchar();
					scanf("%[^\n]s",course_name);
					while((fread(&m,sizeof(Module),1,fp)))
					{
						if(strcasestr(m.course,course_name)!=NULL)
						{
								printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}


				fclose(fp);

}



int admin_Sub_Menu()
{
	int choice;
	printf("\n0.EXIT\n1.LIST_COURSES\n2.ADD_COURSE\n3.LIST_ALL_MODULES\n4.FIND_MODULES_BY_COURSE_AND_NAME\n");
	printf("5.EDIT_MODULE\n6.DELETE_MODULE\n7.LIST_PENDING_ENTRIES\n8.LIST_APPROVED_ENTRIES\n9.APPROVED_ENTRIES\n10.ADD_MODULE\n");
	printf("ENTER OPTION : ");
	scanf("%d",&choice);
	return choice;
}

void add_courses_to_file()
{
		FILE *fp;
		fp = fopen("courses.txt","a+");///home/sunbeam/SUNBEAM ASSIGNMENT/Assignment 8/moviedata.txt
		if(fp==NULL)
		{
			printf("###ERROR WHILE OPENING FILE ###\n");
			exit(1);
		}
		else
		{
			fseek(fp, 0, SEEK_END);
			char buffer[20];
			printf("ENTER COURSE NAME : ");
			scanf("%s",buffer);
		if(fputs(buffer,fp)!=EOF)
			{
				printf("\nCOURSE IS SUCCESSFULLY ADDED TO COURSE FILE\n");
			}
		fclose(fp);
		}
}

void display_all_modules()
{
	FILE *fp;
	Module m;
		fp = fopen("modules.dat","rb+");
		if(fp != NULL)
		{
				rewind(fp);
				printf("\nENTERD STAFF DETAILS :");
				while((fread(&m,sizeof(Module),1,fp)))
				{
				printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
				}
			}
			else
			{
				printf("\n###ERROR STORING STAFF RECORD###\n");
			}


			fclose(fp);


}

void find_module_by_course_and_name_from_module_file()
{
	int choice;
	printf("\nENTER\n1.FIND_BY_COURSE\n2.FIND_BY_MODULE_NAME\n ");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		find_module_by_course();
		break;
	case 2:
		find_module_by_module_name();
		break;
	default:
		printf("\n###ENTER VALID OPTION###");
	}

}
void find_module_by_course()
{
	FILE *fp;
	Module m;
	char course_name[30];
			fp = fopen("modules.dat","rb+");
			if(fp != NULL)
			{
					rewind(fp);
					printf("\nENTER COURSE NAME :");
					getchar();
					scanf("%[^\n]s",course_name);
					while((fread(&m,sizeof(Module),1,fp)))
					{
						if(strcasestr(m.course,course_name)!=NULL)
						{
								printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}


				fclose(fp);

}

void find_module_by_module_name()
{

	FILE *fp;
	Module m;
	char module_name[30];
			fp = fopen("modules.dat","rb+");
			if(fp != NULL)
			{
					rewind(fp);
					printf("\nENTER MODULE NAME :");
					getchar();
					scanf("%[^\n]s",module_name);
					while((fread(&m,sizeof(Module),1,fp)))
					{
						if(strcasestr(m.name,module_name)!=NULL)
						{
								printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}
				fclose(fp);
}

void add_module_to_module_file()
{
	FILE *fp;
	Module m1;
	//Module m2;
	fp=fopen("modules.dat","ab+");
	if(fp == NULL)
	{
		printf("\n###ERROR CREATING MODULE FILE###");
	}
	else
	{
		printf("\nENTER MODULE DETAILS :\n");
		printf("Enter Module id : ");
		scanf("%d",&m1.id);
		printf("Enter Module Name : ");
		getchar();
		scanf("%[^\n]s",m1.name);
		printf("Enter Module Course Name :");
		getchar();
		scanf("%[^\n]s",m1.course);
		printf("Enter Duration (in hours) :");
		scanf("%d",&m1.duration);
		fseek(fp, 0, SEEK_END);

		if(fwrite(&m1,sizeof(Module),1,fp)!=0)
				{
					printf("\nMODULE RECORD SUCCESSFULLY SAVED IN MODULE FILE\n");
					//rewind(fp);
					//fread(&m2,sizeof(Module),1,fp);
					//printf("\nENTERD MODULE DETAILS :\n%d\n%s\n%s\n%d\n",m2.id,m2.name,m2.course,m2.duration);
				}
		fclose(fp);
	}

}


int main()
{
	int main_menu_choice;
	int staff_sub_menu_choice;
	int admin_sub_menu_choice;

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
					display_courses_from_file();
					break;
				case MODULES_PER_COURSES:
					to_find_modules_per_course();
					break;
				case MODULES_PER_CATEGORY:
					break;
				case WORK_ENTRY:
					break;
				case LIST_PENDING_ENTRIE:
					break;
				case LIST_APPROVED_ENTRIE:
					break;
				default:
					printf("\nENTER VALID OPTION :\n");
				}
			}
			break;
		case ADMIN:
			while((admin_sub_menu_choice = admin_Sub_Menu())!=EXIT)
			{
				switch(admin_sub_menu_choice)
				{
				case LIST_COURSES:
					display_courses_from_file();
					break;
				case ADD_COURSE:
					add_courses_to_file();
					break;
				case LIST_ALL_MODULES:
					display_all_modules();
					break;
				case FIND_MODULES_BY_COURSE_AND_NAME:
					find_module_by_course_and_name_from_module_file();
					break;
				case EDIT_MODULE:
					break;
				case DELETE_MODULE:
					break;
				case LIST_PENDING_ENTRIES:
					break;
				case LIST_APPROVED_ENTRIES:
					break;
				case APPROVED_ENTRIES:
					break;
				case ADD_MODULE:
					add_module_to_module_file();
					break;
				default :
					printf("\n#ENTER VALID OPTION#\n");

				}

			}



			break;
		default:
			printf("ENTER VALID OPTION");
		}
	}

	return 0;

}
