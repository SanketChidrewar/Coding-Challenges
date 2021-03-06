/*
 * courses.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "courses.h"
#include<cstring>
#include<iostream>
using namespace std;

courses::courses() {
	// TODO Auto-generated constructor stub
	this->id=0;
	this->fees=0;
	this->name = " ";
	this->section = " ";
}
courses::courses(int id, string name, double fees, string section)
{
	this->id=id;
	this->fees=fees;
	this->name = name;
	this->section = section;
}


void courses::display_courses()
{
	cout<<this->id<<","<<this->name<<","<<this->fees<<","<<this->section<<endl;
}

double courses::getFees() const {
	return fees;
}

void courses::setFees(double fees) {
	this->fees = fees;
}

int courses::getId() const {
	return id;
}

void courses::setId(int id) {
	this->id = id;
}

const string& courses::getName() const {
	return name;
}

const string& courses::getSection() const {
	return section;
}

void courses::setSection(const string& section) {
	this->section = section;
}

void courses::setName(const string& name) {
	this->name = name;
}

courses::~courses() {
	// TODO Auto-generated destructor stub
}

