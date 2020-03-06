
/*
Write a menu driven program for Date in a C++ language.
Declare a class Date having data members day, month, year. Implement the following
member functions.
Date();
Date(int day, int month, int year);
void PrintDateOnConsole();
void AcceptDateFromConsole();
bool IsLeapYear();*/

#include<iostream>

using namespace std;

typedef enum {EXIT,ACCEPT_DATE_FROM_CONSOLE,PRINT_DATE_ON_CONSOLE,IS_LEAP_YEAR}MENUOP;


class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date()
	{
		this->day=01;
		this->month=01;
		this->year=2001;
	}

	Date(int day,int month,int year)
	{
		this->day=day;
		this->month=month;
		this->year=year;
	}

	void PrintDateOnConsole()
	{
		cout<<"\n\nDATE :"<<this->day<<"-"<<this->month<<"-"<<this->year<<"\n"<<endl;
		//cout<<"\n\nDATE :"<<this->day<<this->month<<this->year<<"\n"<<endl;

		//printf("\nDATE : %d-%d-%d\n\n",ptDate->day,ptDate->month,ptDate->year);
	}

	void AcceptDateFromConsole()
	{
		cout<<"\nENTER DATE";
		cin>>this->day>>this->month>>this->year;
		/*cout<<"\nENTER MONTH";
		cin>>this->month;
		cout<<"\nENTER YEAR";
		cin>>this->year;*/
	}

	bool isLeapYear()
	{

		if(this->year%400 == 0)
		{
			return 1 ;
		}
		else if(this->year%4 == 0 && this->year%100 !=0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

int menuChoice()
{
	int choice;
	cout<<"ENTER ANY CHOICE : \n";
	cout<<"0.EXIT \n1.ACCEPT_DATE_FROM_CONSOLE  \n2.PRINT_DATE_ON_CONSOLE \n3.IS_LEAP_YEAR"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
}


int main()
{
	Date d;
	bool is_leap;
	int choice;

	while((choice = menuChoice())!=EXIT)
	{
		switch(choice)
		{
		case ACCEPT_DATE_FROM_CONSOLE:
			d.AcceptDateFromConsole();
			break;
		case PRINT_DATE_ON_CONSOLE:
			d.PrintDateOnConsole();
			break;
		case IS_LEAP_YEAR:
			is_leap = d.isLeapYear();
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

