/*
 * Center.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "Center.h"
#include "AdmissionSystem.h"

#include<cstring>
#include<map>
#include<iostream>
using namespace std;

Center::Center() {
	// TODO Auto-generated constructor stub

	this->id = " ";
	this->name = " ";
	this->address = " ";
	this->coordinator = " ";
	this->password = " ";

	this->center_id_courses = {};

}
Center::Center(string id, string name, string address, string coordinator, string password, multimap<string,int> center_id_courses)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->coordinator = coordinator;
	this->password = password;

	this->center_id_courses = center_id_courses;
}

//const vector<courses>& Center::getCourses() const {
//	return course;
//}
//void Center::setCourses(const vector<courses>& course) {
//	this->course = course;
//}

void Center::display_Center_with_courses(AdmissionSystem& a)
{
	cout<<endl<<this->id<<","<<this->name<<","<<this->address<<","<<this->coordinator<<","<<this->password<<endl;
	cout<<"\n - COURSES UNDER THIS CENTER ARE :"<<endl;
	multimap<string,int>::iterator it = this->center_id_courses.begin();
	while(it!=this->center_id_courses.end())
	{
		cout<<"\t";
		a.course[it->second].display_courses();
		it++;
	}
}

void Center::add_courses_to_respective_centers(string s, int k)
{
	//this->center_id_courses[s] = k;
	this->center_id_courses.insert(pair<string,int> (s,k));
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

const multimap<string, int>& Center::getCenterIdCourses() const {
	return center_id_courses;
}

void Center::setCenterIdCourses(const multimap<string, int>& centerIdCourses) {
	center_id_courses = centerIdCourses;
}

void Center::setPassword(const string& password) {
	this->password = password;
}

Center::~Center() {
	// TODO Auto-generated destructor stub
}

