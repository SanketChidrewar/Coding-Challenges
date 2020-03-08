/*
 * employee.cpp
 *
 *  Created on: 08-Mar-2020
 *      Author: sunbeam
 */

#include "employee.h"
#include<iostream>
#include<cstring>
using namespace std;

employee::employee():joining()
{
	this->id=0;
	this->sal=0;
	strcpy(this->dept,"E&TC");
}
employee::employee(int id,float sal,char * dept,date& joining)
{
	this->id = id;
	this->sal=sal;
	strcpy(this->dept,dept);
	this->joining  = joining;
}

const char* employee::get_Dept() const
{
	return dept;
}
void employee::set_Dept(char * dept)
{
	strcpy(this->dept,dept);
}

int employee::get_Id() const
{
	return id;
}
void employee::set_Id(int id)
{
	this->id = id;
}

const date& employee::get_Joining() const
{
	return joining;
}
void employee::set_Joining(const date& joining)
{
	this->joining = joining;
}

float employee::get_Sal() const
{
	return sal;
}
void employee::set_Sal(float sal)
{
	this->sal = sal;
}


void employee::display()
{
	cout<<"\nID :"<<this->id;
	cout<<"\nSALARY :"<<this->sal;
	cout<<"\nDEPT :"<<this->dept;
	this->joining.display();


}
void employee::accept()
{
	cout<<"ENTER EMPLOYEE ID :";
	cin>>this->id;
	cout<<"ENTER SALARY :";
	cin>>this->sal;
	cout<<"ENTER DEPARTMENT :";
	cin.get(this->dept,24);
	this->joining.accept();

}

employee::~employee() {
	// TODO Auto-generated destructor stub
}

