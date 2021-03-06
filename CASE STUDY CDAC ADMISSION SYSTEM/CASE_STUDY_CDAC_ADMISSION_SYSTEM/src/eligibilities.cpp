/*
 * eligibilities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "eligibilities.h"

eligibilities::eligibilities() {
	// TODO Auto-generated constructor stub
	this->course_name = " ";
	this->degree = " ";
	this->min_per = 0.0;

}
eligibilities::eligibilities(string course_name,string degree,double min_per)
{
	this->course_name = course_name;
	this->degree = degree;
	this->min_per = min_per;
}


const string& eligibilities::getCourseName() const {
	return course_name;
}

void eligibilities::setCourseName(const string& courseName) {
	course_name = courseName;
}

const string& eligibilities::getDegree() const {
	return degree;
}

void eligibilities::setDegree(const string& degree) {
	this->degree = degree;
}

double eligibilities::getMinPer() const {
	return min_per;
}

void eligibilities::setMinPer(double minPer) {
	min_per = minPer;
}

void eligibilities::display_eligibilities()
{
	cout<<this->course_name<<","<<this->degree<<","<<this->min_per<<endl;
}


eligibilities::~eligibilities() {
	// TODO Auto-generated destructor stub
}

