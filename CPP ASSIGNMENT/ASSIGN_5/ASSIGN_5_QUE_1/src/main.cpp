

#include<iostream>
#include"date.h"
#include "person.h"
#include"employee.h"

using namespace std;

int main()
{
	//cout<<"\nCREATING EMPLOYEE DATA :\n";
	date d1(3,3,1998);
	employee e(100,50000,"E&TC",d1);
	cout<<"\nEMPLOYEE DATA IS :\n";
	e.display();

	//cout<<"CREATING PERSON DATA :";
	date d2(03,03,1998);
	person p("SANKET","ACE AUGUSTA",d2);
	cout<<"\nPERSONS DATA IS :\n";
	p.display();

	return 0;
}



