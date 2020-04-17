/*
 * preference.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include "preference.h"
#include<cstring>
#include<iostream>
using namespace std;

preference::preference() {

	this->id=0;
	this->pref_no=0;
	strcpy(this->center_id," ");
	strcpy(this->course_name," ");
}

preference::preference(int id, int pref_no, char* course_name, char* center_id)
{
	this->id=id;
	this->pref_no=pref_no;
	strcpy(this->center_id,center_id);
	strcpy(this->course_name,course_name);
}

const char* preference::getCenterId() const {
	return center_id;
}

void preference::setCenterId(char* center_id)
{
	strcpy(this->center_id,center_id);
}


const char* preference::getCourseName() const {
	return course_name;
}

void preference::setCourseName(char* course_name)
{
	strcpy(this->course_name,course_name);
}


int preference::getId() const {
	return id;
}

void preference::setId(int id) {
	this->id = id;
}

int preference::getPrefNo() const {
	return pref_no;
}

void preference::setPrefNo(int prefNo) {
	pref_no = prefNo;
}

void preference::display_pref(){

	cout<<this->id<<"  "<<this->pref_no<<"  "<<this->course_name<<"  "<<this->center_id<<endl;
}


preference::~preference() {
	// TODO Auto-generated destructor stub
}

