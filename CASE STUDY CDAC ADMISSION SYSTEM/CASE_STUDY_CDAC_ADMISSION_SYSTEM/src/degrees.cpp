/*
 * degrees.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "degrees.h"

degrees::degrees() {
	// TODO Auto-generated constructor stub
	this->degree = " ";

}
degrees::degrees(string degree)
{
	this->degree = degree;

}
void degrees::display_degrees()
{
	cout<<this->degree<<endl;
}

const string& degrees::getDegree() const {
	return degree;
}

void degrees::setDegree(const string& degree) {
	this->degree = degree;
}

degrees::~degrees() {
	// TODO Auto-generated destructor stub
}

