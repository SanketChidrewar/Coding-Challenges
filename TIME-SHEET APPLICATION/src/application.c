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
	char status[20];

}Entry;

typedef enum{EXIT,REGISTER_STAFF,STAFF,ADMIN}MENUOPERATION_MAIN_MENU;
typedef enum{LIST_COURSES=1,MODULES_PER_COURSES,MODULES_PER_CATEGORY,WORK_ENTRY,LIST_PENDING_ENTRIE,LIST_APPROVED_ENTRIE}MENUOPERATIONS_STAFF_SUB_MENU;
typedef enum{ADD_COURSE=2,LIST_ALL_MODULES,FIND_MODULES_BY_COURSE_AND_NAME,EDIT_MODULE,DELETE_MODULE,LIST_PENDING_ENTRIES,LIST_APPROVED_ENTRIES,APPROVED_ENTRIES,ADD_MODULE}MENUOPERATION_ADMIN_SUB_MENU;

int MAIN_MENU()
{

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

void copy_module_to_array(Module *Array, Module *m)
{
	Array->id = m->id;
	strcpy(Array->name,m->name);
	strcpy(Array->course,m->course);
	Array->duration = m->duration;
}


void display_array_element(Module *mArray,int count)
{
			for(int i=0;i<count;i++)
			{
			printf("\n%5d%15s%15s%5d",mArray[i].id,mArray[i].name,mArray[i].course,mArray[i].duration);
			}

}

int compar_by_name(const void *n1, const void *n2)
{
	Module *name1 = (Module*)n1;
	Module *name2 = (Module*)n2;
	return strcmp(name1->name,name2->name);
}

int compar_by_duration(const void *n1, const void *n2)
{
	Module *name1 = (Module*)n1;
	Module *name2 = (Module*)n2;

	if(name1->duration > name2->duration)
		return 1;
	else if(name1->duration < name2->duration)
		return -1;
	else
		return 0;
}

void to_find_modules_per_course()
{
	FILE *fp;
	Module m;
	char course_name[30];
	int count=0;
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
								//printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
							count++;
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}
				fclose(fp);

	Module mArray[count];
	int len=0;

	fp = fopen("modules.dat","rb+");
	if(fp != NULL)
	{
			rewind(fp);
			while((fread(&m,sizeof(Module),1,fp)))
			{
				if(strcasestr(m.course,course_name)!=NULL)
				{
						if(len<=count)
						{
							copy_module_to_array(&mArray[len],&m);
							len++;
						}
				}
			}
		}
		else
		{
			printf("\n###ERROR STORING STAFF RECORD###\n");
		}
		fclose(fp);
		printf("\nARRAY ELEMENTS BEFORE SORTING ARE :\n");
		display_array_element(mArray,count);
		printf("\nARRAY ELEMENTS AFTER SORTING ARE :\n");
		qsort(mArray,count,sizeof(Module), compar_by_name);
		display_array_element(mArray,count);
}
void to_find_modules_per_category()
{
	FILE *fp;
	Module m;
	char course_name[30];
	int count=0;
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
								//printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
							count++;
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}
				fclose(fp);

	Module mArray[count];
	int len=0;

	fp = fopen("modules.dat","rb+");
	if(fp != NULL)
	{
			rewind(fp);
			while((fread(&m,sizeof(Module),1,fp)))
			{
				if(strcasestr(m.course,course_name)!=NULL)
				{
						if(len<=count)
						{
							copy_module_to_array(&mArray[len],&m);
							len++;
						}
				}
			}
		}
		else
		{
			printf("\n###ERROR STORING STAFF RECORD###\n");
		}
		fclose(fp);
		printf("\nARRAY ELEMENTS BEFORE SORTING ARE :\n");
		display_array_element(mArray,count);
		printf("\nARRAY ELEMENTS AFTER SORTING ARE :\n");
		qsort(mArray,count,sizeof(Module), compar_by_duration);
		display_array_element(mArray,count);

}

void write_work_entry_to_file()
{

	FILE *fp;
	Entry e;
	Entry e1;
	char status[20]="pending";
	fp=fopen("entries.dat","wb+");
	if(fp == NULL)
	{
		printf("\n###ERROR CREATING WORK_ENTRY FILE###");
	}
	else
	{
		printf("\nENTER Work Entry DETAILS :\n");
		printf("Enter ENTRY id : ");
		scanf("%d",&e.id);
		printf("Enter STAFF_id : ");
		scanf("%d",&e.staff_id);
		printf("Enter MODULE_id : ");
		scanf("%d",&e.module_id);
		printf("Enter WORK_DATE IN (DD MM YYYY): ");
		scanf("%d %d %d",&e.work_date.day,&e.work_date.month,&e.work_date.year);
		printf("Enter START TIME in (hr min dec) ");
		scanf("%d %d %d",&e.start_time.hours,&e.start_time.mins,&e.start_time.seconds);
		printf("ENTER DURATION OF COURSE :");
		scanf("%d",&e.duration);
		strcpy(e.status,status);
		fseek(fp, 0, SEEK_END);
		//printf("hello");
		if(fwrite(&e,sizeof(Entry),1,fp)!=0)
				{
					printf("\nWORK ENTRY RECORD SUCCESSFULLY SAVED IN ENTRY FILE\n");
					//rewind(fp);
					//fread(&e1,sizeof(Entry),1,fp);
					//printf("\nENTERD WORK ENTRY DETAILS IS :\n%d\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n%d\n%s\n",e1.id,e1.staff_id,e1.module_id,e1.work_date.day,e1.work_date.month,e1.work_date.year,e1.start_time.hours,e1.start_time.mins,e1.start_time.seconds,e1.duration,e1.status);
				}
		fclose(fp);
	}
}

void delete_specific_module()
{
	FILE *fp;
	Module m;
	int count=0;
	char course_name[30];
			fp = fopen("modules.dat","rb+");
			if(fp != NULL)
			{
					rewind(fp);
					printf("\nENTER MODULE NAME :");
					getchar();
					scanf("%[^\n]s",course_name);
					while((fread(&m,sizeof(Module),1,fp)))
					{
						if(!(strcasestr(m.name,course_name)!=NULL))
						{
								//printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
								count++;
								printf("%d",count);
						}
					}
				}
				else
				{
					printf("\n###ERROR STORING STAFF RECORD###\n");
				}
				fclose(fp);

	Module ARRAY_MODULE[count];
	//printf("%d\n%s,%s,%d",ARRAY_MODULE[0].id,ARRAY_MODULE[0].name,ARRAY_MODULE[0].course,ARRAY_MODULE[0].duration);
	int len =0;

			fp = fopen("modules.dat","rb+");
				if(fp != NULL)
				{
						rewind(fp);
						while((fread(&m,sizeof(Module),1,fp)))
						{
							if(!(strcasestr(m.name,course_name)!=NULL))
							{

											copy_module_to_array(&ARRAY_MODULE[len],&m);
											len++;
							}
						}
					}
					else
					{
						printf("\n###ERROR IN COPYING MODULE FROM ARRAY###\n");
					}
					fclose(fp);

	//printf("%d\n%s,%s,%d",ARRAY_MODULE[0].id,ARRAY_MODULE[0].name,ARRAY_MODULE[0].course,ARRAY_MODULE[0].duration);


			//code for rewriting array file to file

					fp=fopen("modules.dat","wb");
					Module m5;
					if(fp == NULL)
					{
						printf("\n###ERROR CREATING MODULE FILE###");
					}
					else
					{
						for(int i=0;i<count;i++)
						{
							m5.id= ARRAY_MODULE[i].id;
							strcpy(&m5.name,&ARRAY_MODULE[i].name);
							strcpy(&m5.course,&ARRAY_MODULE[i].course);
							m5.duration= ARRAY_MODULE[i].duration;

						fwrite(&m5,sizeof(Module),1,fp);
						}
						printf("\nMODULE RECORD SUCCESSFULLY SUCCESSFULLY DELETED FROM MODULE FILE\n");
					fclose(fp);
					}



}


void list_pending_entries()
{
	FILE *fp;
	Entry e1;
		char status[30]="pending";
				fp = fopen("entries.dat","rb+");
				if(fp != NULL)
				{
						rewind(fp);
						while((fread(&e1,sizeof(Entry),1,fp)))
						{
							if(strcasestr(e1.status,status)!=NULL)
							{
								printf("\nENTERD WORK ENTRY DETAILS IS :\n%d\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n%d\n%s\n",e1.id,e1.staff_id,e1.module_id,e1.work_date.day,e1.work_date.month,e1.work_date.year,e1.start_time.hours,e1.start_time.mins,e1.start_time.seconds,e1.duration,e1.status);

							}
						}
					}
					else
					{
						printf("\n###ERROR STORING STAFF RECORD###\n");
					}
					fclose(fp);

}

void list_approved_entries()
{
	FILE *fp;
	Entry e1;
		char status[30]="approved";
				fp = fopen("entries.dat","rb+");
				if(fp != NULL)
				{
						rewind(fp);
						while((fread(&e1,sizeof(Entry),1,fp)))
						{
							if(strcasestr(e1.status,status)!=NULL)
							{
								printf("\nENTERD WORK ENTRY DETAILS IS :\n%d\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n%d\n%s\n",e1.id,e1.staff_id,e1.module_id,e1.work_date.day,e1.work_date.month,e1.work_date.year,e1.start_time.hours,e1.start_time.mins,e1.start_time.seconds,e1.duration,e1.status);

							}
						}
					}
					else
					{
						printf("\n###ERROR STORING STAFF RECORD###\n");
					}
					fclose(fp);
}

void approve_entry()
{
	FILE *fp;
	Entry e1;
	int id;
	char status[20]="approved";
	fp = fopen("entries.dat","rb+");
				if(fp != NULL)
				{
						printf("ENTER id you want to approve : ");
						scanf("%d",&id);
						rewind(fp);
						while((fread(&e1,sizeof(Entry),1,fp)))
						{
							if(e1.id == id)
							{
								printf("\nENTERD WORK ENTRY DETAILS IS :\n%d\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n%d\n%s\n",e1.id,e1.staff_id,e1.module_id,e1.work_date.day,e1.work_date.month,e1.work_date.year,e1.start_time.hours,e1.start_time.mins,e1.start_time.seconds,e1.duration,e1.status);
								printf("THIS ABOVE RECORD IS APPROVED : ");
								strcpy(e1.status,status);
								fwrite(&e1,sizeof(Entry),1,fp);
								printf("\nENTERD WORK ENTRY DETAILS IS :\n%d\n%d\n%d\n%d/%d/%d\n%d:%d:%d\n%d\n%s\n",e1.id,e1.staff_id,e1.module_id,e1.work_date.day,e1.work_date.month,e1.work_date.year,e1.start_time.hours,e1.start_time.mins,e1.start_time.seconds,e1.duration,e1.status);
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
	printf("5.EDIT_MODULE\n6.DELETE_MODULE\n7.LIST_PENDING_ENTRIES\n8.LIST_APPROVED_ENTRIES\n9.APPROVE_ENTRIES\n10.ADD_MODULE\n");
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
			//fseek(fp, 0, SEEK_END);
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

void edit_module()
{

	FILE *fp;
		Module m;
		int id;
		int duration;
				fp = fopen("modules.dat","rb+");
				if(fp != NULL)
				{
						rewind(fp);
						printf("\nENTER id :");
						scanf("%d",&id);
						while((fread(&m,sizeof(Module),1,fp)))
						{
							if(m.id == id)
							{
								printf("MODULE BEFORE EDITING");
								printf("\n%d\n%s\n%s\n%d\n",m.id,m.name,m.course,m.duration);
								printf("ENTER duration of module");
								scanf("%d",&duration);
								m.duration = duration;
								printf("duration of module is successfully updated");
								printf("MODULE AFTER EDITING");
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

					fwrite(&m1,sizeof(Module),1,fp);
					printf("\nMODULE RECORD SUCCESSFULLY SAVED IN MODULE FILE\n");
					//rewind(fp);
					//fread(&m2,sizeof(Module),1,fp);
					//printf("\nENTERD MODULE DETAILS :\n%d\n%s\n%s\n%d\n",m2.id,m2.name,m2.course,m2.duration);
		fclose(fp);
	}

}


int main()
{
	int main_menu_choice;
	int staff_sub_menu_choice;
	int admin_sub_menu_choice;

	int staff_id;
	printf("\nStudent Name : SANKET CHIDREWAR\n");
	printf("Roll Number  : 36009\n");
	printf("Center Name   : Sunbeam\n");
	printf("Course Name  : PG-DAC 2020\n");
	printf("Group Name   : _____D-2____\n");
	printf("MISSION STATEMENT : I WILL NEVER QUIT\n");

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
					to_find_modules_per_category();
					break;
				case WORK_ENTRY:
					write_work_entry_to_file();
					break;
				case LIST_PENDING_ENTRIE:
					list_pending_entries();
					break;
				case LIST_APPROVED_ENTRIE:
					list_approved_entries();

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
					edit_module();
					break;
				case DELETE_MODULE:
					delete_specific_module();
					break;
				case LIST_PENDING_ENTRIES:
					list_pending_entries();
					break;
				case LIST_APPROVED_ENTRIES:
					list_approved_entries();
					break;
				case APPROVED_ENTRIES:
					approve_entry();
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
