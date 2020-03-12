/*
 * Semester.cpp
 *
 *  Created on: 11-Mar-2020
 *      Author: sunbeam
 */

#include "Semester.h"

Semester::Semester():Health_Club_Membership() {
	this->age=0;
	this->cost=6000;
	this->dicount=0.06f;
}

float Semester::calculate_cost()
{
	float c;
	if(this->getIsCustOld() == 0)
	{
		c = (this->getCost() + 12 * this->getAge());
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

void Semester::Accept()
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
void Semester::Display()
{
	this->Health_Club_Membership::Display();
	cout<<"AGE : "<<this->age;
}

int Semester::getAge() const {
	return age;
}

void Semester::setAge(int age) {
	if(age<20)
	{
		throw(1);
	}
	this->age = age;
}

float Semester::getCost() const {
	return cost;
}

void Semester::setCost(float cost) {
	this->cost = cost;
}

float Semester::getDicount() const {
	return dicount;
}

void Semester::setDicount(float dicount) {
	this->dicount = dicount;
}


Semester::~Semester() {
	// TODO Auto-generated destructor stub
}

