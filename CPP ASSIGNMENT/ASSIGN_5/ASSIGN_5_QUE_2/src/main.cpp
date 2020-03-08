

#include<iostream>
#include"date.h"
#include "person.h"
#include"employee.h"

using namespace std;

int main()
{
	//cout<<"\nCREATING EMPLOYEE DATA :\n";
	date d1(3,3,1998);
	date d2(18,02,2020);
	employee e("SANKET CHIDREWAR","ACE AUGUSTA",d1,100,50000,"E&TC",d2);
	cout<<"\nEMPLOYEE DATA IS :\n";
	e.display();

/*	//cout<<"CREATING PERSON DATA :";
	date d3(03,03,1998);
	person p("SANKET","ACE AUGUSTA",d3);
	cout<<"\nPERSONS DATA IS :\n";
	p.display();*/

	return 0;
}



