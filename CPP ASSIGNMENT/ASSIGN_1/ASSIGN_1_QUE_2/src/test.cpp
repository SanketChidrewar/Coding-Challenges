
/*Write a menu driven program for Date in a C++ language.
Declare a structure Date having data members day, month, year. Implement the
following member functions.
void InitDate();
void PrintDateOnConsole();
void AcceptDateFromConsole();
bool IsLeapYear();*/

#include<iostream>

using namespace std;

typedef enum {EXIT,ACCEPT_DATE_FROM_CONSOLE,PRINT_DATE_ON_CONSOLE,IS_LEAP_YEAR}MENUOP;


typedef struct
{
	int day;
	int month;
	int year;

}DATE;

int menuChoice()
{
	int choice;
	cout<<"ENTER ANY CHOICE : \n";
	cout<<"0.EXIT \n1.ACCEPT_DATE_FROM_CONSOLE  \n2.PRINT_DATE_ON_CONSOLE \n3.IS_LEAP_YEAR"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
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
	cout<<"\n\nDATE :"<<ptDate->day<<"-"<<ptDate->month<<"-"<<ptDate->year<<"\n"<<endl;
	//printf("\nDATE : %d-%d-%d\n\n",ptDate->day,ptDate->month,ptDate->year);
}

void AcceptDateFromConsole(DATE* ptDate)
{
	cout<<"\nENTER DAY";
	cin>>ptDate->day;
	cout<<"\nENTER MONTH";
	cin>>ptDate->month;
	cout<<"\nENTER YEAR";
	cin>>ptDate->year;
}

bool isLeapYear(DATE *dptr)
{

	if(dptr->year%400 == 0)
	{
		return 1 ;
	}
	else if(dptr->year%4 == 0 && dptr->year%100 !=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


int main()
{
	DATE d;
	InitDate(&d);
	bool is_leap;
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
		case IS_LEAP_YEAR:
			is_leap = isLeapYear(&d);
			if(is_leap == 1)
			{
				cout<<"\n\nLEAP YEAR\n\n"<<endl;
			}
			else
				cout<<"\n\n NOT A LEAP YEAR\n\n"<<endl;
			break;
		default :
			cout<<"\nENTER VALID INPUT\n";
		}
	}

	return 0;
}
