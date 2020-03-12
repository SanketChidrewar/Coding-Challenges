/*
 * Monthly.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#include "Monthly.h"
//#include "Health_Club_Membership.h"


Monthly::Monthly():Health_Club_Membership() {
	this->age=0;
	this->cost=1000;
	this->dicount=0.0f;
}

float Monthly::calculate_cost()
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
		c = (this->getCost() + 2 * this->getAge());
		c= c * (this->dicount + 0.01);
		this->setAmountPaid(c);
		return c;
	}
}

void Monthly::Accept()
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
void Monthly::Display()
{
	this->Health_Club_Membership::Display();
	cout<<"AGE : "<<this->age;
}

int Monthly::getAge() const {
	return age;
}

void Monthly::setAge(int age) {
	if(age<20)
	{
		throw(1);
	}
	this->age = age;
}

float Monthly::getCost() const {
	return cost;
}

void Monthly::setCost(float cost) {
	this->cost = cost;
}

float Monthly::getDicount() const {
	return dicount;
}

void Monthly::setDicount(float dicount) {
	this->dicount = dicount;
}

Monthly::~Monthly() {
	// TODO Auto-generated destructor stub
}

