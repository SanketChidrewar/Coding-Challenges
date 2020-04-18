/*
 * Center.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "Center.h"
#include<cstring>
#include<iostream>
using namespace std;

Center::Center() {
	// TODO Auto-generated constructor stub

	this->id = " ";
	this->name = " ";
	this->address = " ";
	this->coordinator = " ";
	this->password = " ";

	this->course = {};

}
Center::Center(string id, string name, string address, string coordinator, string password, vector<courses> course)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->coordinator = coordinator;
	this->password = password;

	this->course = course;
}

const vector<courses>& Center::getCourses() const {
	return course;
}
void Center::setCourses(const vector<courses>& course) {
	this->course = course;
}

void Center::display_Center_with_courses()
{
	cout<<endl<<this->id<<","<<this->name<<","<<this->address<<","<<this->coordinator<<","<<this->password<<endl;
	cout<<"\n - COURSES UNDER THIS CENTER ARE :"<<endl;
	for(unsigned int i=0;i<this->course.size();i++)
	{
		cout<<"\t";
		this->course[i].display_courses();
	}
}

void Center::add_courses_in_center(courses c)
{
	this->course.push_back(c);
}

const string& Center::getAddress() const {
	return address;
}

void Center::setAddress(const string& address) {
	this->address = address;
}

const string& Center::getCoordinator() const {
	return coordinator;
}

void Center::setCoordinator(const string& coordinator) {
	this->coordinator = coordinator;
}

const vector<courses>& Center::getCourse() const {
	return course;
}

void Center::setCourse(const vector<courses>& course) {
	this->course = course;
}

const string& Center::getId() const {
	return id;
}

void Center::setId(const string& id) {
	this->id = id;
}

const string& Center::getName() const {
	return name;
}

void Center::setName(const string& name) {
	this->name = name;
}

const string& Center::getPassword() const {
	return password;
}

void Center::setPassword(const string& password) {
	this->password = password;
}

Center::~Center() {
	// TODO Auto-generated destructor stub
}

