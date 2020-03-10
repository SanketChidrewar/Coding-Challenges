/*
 * tapes.cpp
 *
 *  Created on: 10-Mar-2020
 *      Author: sunbeam
 */

#include "tapes.h"
#include"product.h"
#include<iostream>
using namespace std;

tapes::tapes():product() {
	this->duration=0;
}

tapes::tapes(int duration,int price):product(price)
{
	this->duration=duration;
}

int tapes::getDuration() const {
	return duration;
}

void tapes::setDuration(int duration) {
	this->duration = duration;
}

void tapes::accept()
{
	cout<<"ENTER DURATION :";
	cin>>this->duration;
	this->product::accept();


}
void tapes::display()
{
	this->product::display();
	cout<<"DURATION :"<<this->duration<<endl;
}

int tapes::calc_discount()
{
	return this->getPrice() * 0.05;
}

tapes::~tapes() {
	// TODO Auto-generated destructor stub
}

