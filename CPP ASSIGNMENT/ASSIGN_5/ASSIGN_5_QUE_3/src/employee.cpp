/*
 * employee.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
#include "employee.h"
using  namespace std;


employee::employee() {

	this->id=0;
	this->sal=0.0f;
}
employee::employee(int id,float sal)
{
	this->id=id;
	this->sal=sal;
}


int employee::get_Id() const
{
	return this->id;
}
void employee::set_Id(int id)
{
	this->id =id;
}

float employee::get_Sal() const
{
	return this->sal;
}
void employee::set_Sal(float sal)
{
	this->sal=sal;
}

void employee::display()
{
	cout<<"\nEMPLOYEE ID :"<<this->id<<endl;
	cout<<"EMPLOYEE SALARY :"<<this->sal<<endl;
}
void employee::accept()
{
	cout<<"ENTER EMPLOYEE ID :";
	cin>>this->id;
	cout<<"ENTER EMPLOYEE SALARY :";
	cin>>this->sal;
}


employee::~employee() {
	// TODO Auto-generated destructor stub
}

