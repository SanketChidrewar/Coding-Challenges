/*
 * Student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include "Student.h"
#include<cstring>
#include<iostream>

using namespace std;


Student::Student() {
	// TODO Auto-generated constructor stub
	this->rollNumber=0;
	strcpy(this->name," ");
	this->marks =0;
}

Student::Student(int rn,char* name,int marks)
{
	this->rollNumber = rn;
	strcpy(this->name,name);
	this->marks = marks;
}

void Student::display_student()
{
	cout<<this->rollNumber<< " "<<this->name<<" "<<this->marks<<endl;
}

int Student::getMarks() const {
	return marks;
}

void Student::setMarks(int marks) {
	this->marks = marks;
}

const char* Student::getName() const {
	return name;
}

void Student::setName(char* name) {
	strcpy(this->name,name);
}

int Student::getRollNumber() const {
	return rollNumber;
}

void Student::setRollNumber(int rollNumber) {
	this->rollNumber = rollNumber;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}
