
#include<iostream>
#include"cylinder.h"
using namespace std;

Cylinder::Cylinder()
	{
		this->radius=0;
		this->height=0;
	}
Cylinder::Cylinder(double radius, double height)
	{
		this->radius=radius;
		this->height=height;
	}
	void Cylinder::getVolume()
	{
		cout<<"ENTER RADIUS :";
		cin>>this->radius;
		cout<<"ENTER HEIGHT :";
		cin>>this->height;
	}
	void Cylinder::printVolume()
	{
		//double result=(double)pi*radius*radius*height;
		cout<<"\nVOLUME OF CYLINDER IS :"<<pi*radius*radius*height<<endl<<endl;
	}

	int menuChoice()
	{
		int choice;
		cout<<"ENTER ANY CHOICE:"<<endl;
		cout<<"\n0.EXIT \n1.GET_VOLUME \n2.PRINT_VOLUME"<<endl;
		cout<<"ENTER YOUR CHOICE :";
		cin>>choice;
		return choice;
	}
