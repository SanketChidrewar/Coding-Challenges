/*
 * Student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: sunbeam
 */

#include "Student.h"
#include "preference.h"

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

Student::Student() {
	// TODO Auto-generated constructor stub
	this->id=0;
	strcpy(this->name," ");
	this->rank_a=0;
	this->rank_b=0;
	this->rank_c=0;
	strcpy(this->degree," ");
	this->degree_marks=0;
	strcpy(this->course_name," ");
	strcpy(this->center_id," ");
	this->payment=0;
	this->reported=0;
	strcpy(this->prn," ");
	this->preferences = {};
}

Student::Student(int id, char* name, int rank_a, int rank_b, int rank_c, char* degree, double degree_marks, char* course_name, char* center_id, double payment, int reported, char* prn, vector<preference> preferences)
{
	this->id=id;
	strcpy(this->name,name);
	this->rank_a=rank_a;
	this->rank_b=rank_b;
	this->rank_c=rank_c;
	strcpy(this->degree,degree);
	this->degree_marks=degree_marks;
	strcpy(this->course_name,course_name);
	strcpy(this->center_id,center_id);
	this->payment=0;
	this->reported=0;
	strcpy(this->prn,prn);

	this->preferences = preferences;
}

int Student::getId() const {
	return id;
}
void Student::setId(int id) {
	this->id = id;
}

const char* Student::getName() const {
	return name;
}
void Student::setName(char* name) {
	strcpy(this->name,name);
}

int Student::getRankA() const {
	return rank_a;
}
void Student::setRankA(int rankA) {
	rank_a = rankA;
}

int Student::getRankB() const {
	return rank_b;
}
void Student::setRankB(int rankB) {
	rank_b = rankB;
}

int Student::getRankC() const {
	return rank_c;
}
void Student::setRankC(int rankC) {
	rank_c = rankC;
}

const char* Student::getDegree() const {
	return degree;
}
void Student::setDegree(char* degree) {
	strcpy(this->degree,degree);
}

double Student::getDegreeMarks() const {
	return degree_marks;
}
void Student::setDegreeMarks(double degreeMarks) {
	degree_marks = degreeMarks;
}

const char* Student::getCourseName() const {
	return course_name;
}
void Student::setCourseName(char* course_name) {
	strcpy(this->course_name,course_name);
}

const char* Student::getCenterId() const {
	return center_id;
}
void Student::setCenterId(char* center_id) {
	strcpy(this->center_id,center_id);
}

double Student::getPayment() const {
	return payment;
}
void Student::setPayment(double payment) {
	this->payment = payment;
}

int Student::getReported() const {
	return reported;
}
void Student::setReported(int reported) {
	this->reported = reported;
}

const char* Student::getPrn() const {
	return prn;
}
void Student::setPrn(char* prn) {
	strcpy(this->prn,prn);
}

const vector<preference>& Student::getPreferences() const {
	return preferences;
}
void Student::setPreferences(const vector<preference>& preferences) {
	this->preferences = preferences;
}

void Student::add_preferences(preference p)
{
	this->preferences.push_back(p);
}

void Student::display_stud()
{
	cout<<endl<<this->id<<" "<<this->name<<" "<<this->rank_a<<" "<<this->rank_b<<" "<<this->rank_c<<" "<<this->degree;
	cout<<" "<<this->degree_marks<<" "<<this->course_name<<" "<<this->center_id<<" "<<this->payment;
	cout<<" "<<this->reported<<" "<<this->prn<<endl;

	for(unsigned int i=0;i<preferences.size();i++)
	{
		preferences[i].display_pref();
	}
	cout<<endl<<endl;
}


Student::~Student() {
	// TODO Auto-generated destructor stub
}

