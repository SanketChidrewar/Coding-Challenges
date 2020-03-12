/*
 * Annual.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#include "Annual.h"

Annual::Annual():Health_Club_Membership() {
	this->age=0;
	this->cost=12000;
	this->dicount=0.15f;
}

float Annual::calculate_cost()
{
	float c;
	if(this->getIsCustOld() == 0)
	{
		c = (this->getCost() + 2 * this->getAge());
		this->setAmountPaid(c);
		return c;

	}
	else
	{
		c = (this->getCost() + 24 * this->getAge());
		c= c * (this->dicount + 0.01);
		this->setAmountPaid(c);
		return c;
	}

}

void Annual::Accept()
{
	int age;
	this->Health_Club_Membership::Accept();
	try
	{
		cout<<"ENTER AGE :";
		cin>>age;
		setAge(age);
	}
	catch(int i)
	{
		cerr<<"AGE MUST BE > 20 "<<endl;
		exit(2);
	}
}
void Annual::Display()
{
	this->Health_Club_Membership::Display();
	cout<<"AGE : "<<this->age;
}

int Annual::getAge() const {
	return age;
}

void Annual::setAge(int age) {
	if(age<20)
	{
		throw(1);
	}
	this->age = age;
}

float Annual::getCost() const {
	return cost;
}

void Annual::setCost(float cost) {
	this->cost = cost;
}

float Annual::getDicount() const {
	return dicount;
}

void Annual::setDicount(float dicount) {
	this->dicount = dicount;
}


Annual::~Annual() {
	// TODO Auto-generated destructor stub
}

