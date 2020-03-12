
#include<iostream>
#include"Date.h"
#include "Health_Club_Membership.h"
#include "Monthly.h"
#include "Semester.h"
#include "Annual.h"

using namespace std;

typedef enum{EXIT,MONTHLY,SEMESTER,ANNUAL}MEMBERSHIP;

int menuchoice()
{
	int ch;
	cout<<"====WELCOME TO HEALTH CLUB MEMBERSHIP==="<<endl;
	cout<<"ENTER :"<<endl;
	cout<<"1.MONTHLY MEMBERSHIP \n2.SEMESTER MEMBERSHIP \n3.ANNUAL MEMBERSHIP :"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>ch;
	getchar();
	return ch;
}

int main()
{
	int size;
	cout<<"ENTER NUMBER OF CUSTOMER :";
	cin>>size;

	Health_Club_Membership* h[size];

	for(int i=0;i<size;i++)
	{
		int choice =0;
		choice = menuchoice();

				switch(choice)
				{
				case MONTHLY:
					h[i]  = new Monthly;
					h[i]->Accept();

					break;
				case SEMESTER:
					h[i]  = new Semester;
					h[i]->Accept();

					break;
				case ANNUAL:
					h[i]  = new Annual;
					h[i]->Accept();

					break;
				default:
					cerr<<"ENTER VALID OPTION :<<endl";
					exit(2);
				}
			//h[i]->calculate_cost();
	}

	cout<<"=====CUSTOMERS DETAILS ARE ======="<<endl;
	float total_collection=0;
	for(int i=0;i<size;i++)
	{
		cout<<"\n\n";
		h[i]->Display();
		total_collection = total_collection +  h[i]->calculate_cost();
	}
	cout<<"\nTOTAL COLLECTION OF DAY : "<<total_collection;

	//cout<<"HII";
	return 0;
}

/*	Monthly m;
	m.Accept();
	m.Display();*/

/*	Date d(03,03,1998);
	d.Display();*/

/*
	Date d(03,03,1998);
	Health_Club_Membership h("SANKET",1,d,2000);
	h.Display();
*/
