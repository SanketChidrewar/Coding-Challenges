

/*Write a menu driven program for Date in a C language.
Declare a structure Date having data members day, month, year. Implement the
following functions.
void InitDate(struct Date* ptDate);
void PrintDateOnConsole(struct Date* ptDate);
void AcceptDateFromConsole(struct Date* ptDate);*/

#include<stdio.h>

typedef enum {EXIT,ACCEPT_DATE_FROM_CONSOLE,PRINT_DATE_ON_CONSOLE}MENUOP;

typedef struct
{
	int day;
	int month;
	int year;

}DATE;

int menuChoice()
{
	int choice;
	printf("ENTER ANY CHOICE : \n");
	printf("0.EXIT \n1.ACCEPT_DATE_FROM_CONSOLE  \n2.PRINT_DATE_ON_CONSOLE");
	printf("ENTER YOUR CHOICE :");
	scanf("%d",&choice);
	return choice;
}

void InitDate(DATE* ptDate)
{
	ptDate->day = 01;
	ptDate->month = 01;
	ptDate->year = 2001;
}

void PrintDateOnConsole(DATE* ptDate)
{
	//cout<<"DD-MM-YYYY"<<ptDate->day<<"-"<<ptDate->month<<"-"<<ptDate->year<<endl;
	printf("\nDATE : %d-%d-%d\n\n",ptDate->day,ptDate->month,ptDate->year);
}

void AcceptDateFromConsole(DATE* ptDate)
{
	printf("ENTER DATE IN (DD MM YYYY) FORMAT :");
	scanf("%d %d %d",&ptDate->day,&ptDate->month,&ptDate->year);
}

int main()
{
	DATE d;
	InitDate(&d);
	int choice;

	while((choice = menuChoice())!=EXIT)
	{
		switch(choice)
		{
		case ACCEPT_DATE_FROM_CONSOLE:
			AcceptDateFromConsole(&d);
			break;
		case PRINT_DATE_ON_CONSOLE:
			PrintDateOnConsole(&d);
			break;
		}
	}

	return 0;
}
