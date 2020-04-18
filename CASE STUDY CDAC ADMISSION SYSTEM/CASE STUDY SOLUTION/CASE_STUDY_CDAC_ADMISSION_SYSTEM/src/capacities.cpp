/*
 * capacities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "capacities.h"

capacities::capacities() {
	// TODO Auto-generated constructor stub
	this->center_id = " ";
	this->course_name = " ";
	this->capacity = 0 ;
	this->filled_capacity = 0;

}
capacities::capacities(string center_id, string course_name, int capacity, int filled_capacity)
{
	this->center_id = center_id;
	this->course_name = course_name;
	this->capacity = capacity ;
	this->filled_capacity = filled_capacity;

}
void capacities::display_capacities()
{
	cout<<this->center_id<<","<<this->course_name<<","<<this->capacity<<","<<this->filled_capacity<<endl;
}

int capacities::getCapacity() const {
	return capacity;
}

void capacities::setCapacity(int capacity) {
	this->capacity = capacity;
}

const string& capacities::getCenterId() const {
	return center_id;
}

void capacities::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& capacities::getCourseName() const {
	return course_name;
}

void capacities::setCourseName(const string& courseName) {
	course_name = courseName;
}

int capacities::getFilledCapacity() const {
	return filled_capacity;
}

void capacities::setFilledCapacity(int filledCapacity) {
	filled_capacity = filledCapacity;
}

capacities::~capacities() {
	// TODO Auto-generated destructor stub
}

