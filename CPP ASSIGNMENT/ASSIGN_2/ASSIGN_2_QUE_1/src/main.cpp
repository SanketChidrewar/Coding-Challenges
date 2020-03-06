/*
1 ) Write a class to find volume of a Cylinder by using following members.
	(volume of Cylinder=3.14 * radius * radius *height) ( use modular approach)
	Class having following member functions:
	Cylinder()
	Cylinder(double radius, double height)
	getVolume()
	printVolume()
	Initialize members using constructor member initializer list.*/

#include<iostream>
#include"cylinder.h"


typedef enum MENU{EXIT,GET_VOLUME,PRINT_VOLUME}MENUOP;

using namespace std;

int main()
{
	Cylinder c;

	int choice;
	while((choice=menuChoice())!=EXIT)
	{
		switch(choice)
		{
		case GET_VOLUME:
			c.getVolume();
			break;
		case PRINT_VOLUME:
			c.printVolume();
			break;
		default :
			cout<<"ENTER VALID INPUT";
		}
	}
	return 0;
}
