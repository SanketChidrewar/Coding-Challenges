/*
 * manager.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
#include "manager.h"
using namespace std;

manager::manager()
{
	this->bonus=0;
}
manager::manager(int id,float sal,float bonus)
{
	this->set_Id(id);
	this->set_Sal(sal);
	this->bonus=bonus;
}


int manager::get_Bonus()
{
	return this->bonus;
}
void manager::set_Bonus(float bonus)
{
	this->bonus=bonus;
}
void manager::display()
{
	this->employee::display();
	cout<<"MANAGER BONUS IS: "<<this->bonus<<endl;
}
void manager::accept()
{
	this->employee::accept();
	cout<<"ENTER MANAGER BONUS :";
	cin>>this->bonus;
}

void manager::display_Manager()
{
	cout<<"MANAGER BONUS IS: "<<this->bonus;
}
void manager::accept_Manager()
{
	cout<<"ENTER MANAGER BONUS :";
	cin>>this->bonus;
}


manager::~manager() {
	// TODO Auto-generated destructor stub
}

