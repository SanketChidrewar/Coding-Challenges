/*
 * salesman.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
#include "salesman.h"

using namespace std;

salesman::salesman()
{
	this->comm=0.0f;
}
salesman::salesman(int id,float sal,float comm)
{
	this->set_Id(id);
	this->set_Sal(sal);
	this->comm=comm;
}

int salesman::get_Comm()
{
	return this->get_Comm();
}
void salesman::set_Comm(float comm)
{
	this->comm=comm;
}

void salesman::display()
{
	this->employee::display();
	cout<<"SALESMAN COMMISSION :"<<this->comm<<endl;
}
void salesman::accept()
{
	this->employee::accept();
	cout<<"ENTER SALESMAN COMMISSION : ";
	cin>>this->comm;
}

void salesman::display_Salesman()
{
	cout<<"SALESMAN COMMISSION :"<<this->comm<<endl;
}
void salesman::accept_Salesman()
{
	cout<<"\nENTER SALESMAN COMMISSION : ";
	cin>>this->comm;
}

salesman::~salesman() {
	// TODO Auto-generated destructor stub
}

