/*
Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a
fifty-cent toll. Mostly they do, but sometimes a car goes by without paying. The
tollbooth keeps track of the number of cars that have gone by and of the total
amount of money collected.Model this tollbooth with a class called tollBooth.
The two data items are a type unsigned int to hold the total number of cars, and a
type double to hold the total amount of money collected.
A constructor initializes all data members to 0.
A member function called payingCar( ) increments the car total and adds 0.50 to the
cash total.
Another function, called nopayCar( ) increments the car total but adds nothing to the
cash total.
Finally, a member function called PrintOnConsole( ) displays the two totals and
number of paying as well as non paying cars total.*/

#include<iostream>

using namespace std;

typedef enum {EXIT,PAYING_CARS,NON_PAYING_CARS,TOTAL_CAR_PASSED_INFO}MENUOP;


class Tollbooth
{
private:
	unsigned int no_of_cars;
	double total_money_collected;
public:
	Tollbooth()
	{
		this->no_of_cars=0;
		this->total_money_collected=0;
	}

	void payingCar()
	{
		this->no_of_cars= this->no_of_cars + 1;
		this->total_money_collected= this->total_money_collected + 0.50;
	}

	void nopayCar()
	{
		this->no_of_cars= this->no_of_cars + 1;
	}

	void PrintOnConsole()
	{
		int no_of_paying_cars = (int)((this->total_money_collected)/(0.5));
		int no_of_non_paying_cars = (this->no_of_cars)-(no_of_paying_cars) ;
		cout<<"TOTAL NO OF CARS PASSED :"<<this->no_of_cars<<endl;
		cout<<"TOTAL MONEY COLECTED    :"<<this->total_money_collected<<endl;
		cout<<"TOTAL NO OF PAYING CARS :"<<no_of_paying_cars<<endl;
		cout<<"TOTAL OF NON PAYING CARS:"<<no_of_non_paying_cars<<endl;
	}
};

int menuChoice()
{
	int choice;
	cout<<"ENTER ANY CHOICE : \n";
	cout<<"0.EXIT \n1.PAYING_CARS  \n2.NON_PAYING_CARS \n3.TOTAL_CAR_PASSED_INFO"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>choice;
	return choice;
}

int main()
{
	Tollbooth t;
	int choice;

		while((choice = menuChoice())!=EXIT)
		{
			switch(choice)
			{
			case PAYING_CARS:
				t.payingCar();
				break;
			case NON_PAYING_CARS:
				t.nopayCar();
				break;
			case TOTAL_CAR_PASSED_INFO:
				t.PrintOnConsole();
				break;
			default :
				cout<<"\nENTER VALID INPUT\n";
			}
		}
	return 0;
}
