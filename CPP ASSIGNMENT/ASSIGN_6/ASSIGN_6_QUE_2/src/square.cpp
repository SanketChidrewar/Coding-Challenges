/*
 * square.cpp
 *
 *  Created on: 10-Mar-2020
 *      Author: sunbeam
 */

#include "square.h"
#include<iostream>
using namespace std;


square::square() {
this->side=0;
}

square::square(float side)
{
	this->side = side;
}
float square::get_side()
{
	return this->side;
}
void square::set_side(float side)
{
	this->side=side;
}
void square::accept()
{
	cout<<"ENTER side OF square :";
	cin>>this->side;
}
void square::display()
{
	cout<<"side OF square IS :"<<this->side;
}
float square::calc_area()
{
	return this->side*this->side;
}
float square::calc_peri()
{
	return 4*this->side;
}

square::~square() {
	// TODO Auto-generated destructor stub
}

