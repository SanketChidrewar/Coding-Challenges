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
	this->name = " ";
	this->rank_a=0;
	this->rank_b=0;
	this->rank_c=0;
	this->degree = " ";
	this->degree_marks=0;
	this->allocated_pref=0;
	this->course_name = " ";
	this->center_id = " ";
	this->payment=0;
	this->reported=0;
	this->prn = " ";
	this->preferences = {};
}

Student::Student(int id, string name, int rank_a, int rank_b, int rank_c, string degree, double degree_marks, int allocated_pref, string course_name, string center_id, double payment, int reported, string prn, vector<preference> preferences)
{
	this->id=id;
	this->name = name;
	this->rank_a=rank_a;
	this->rank_b=rank_b;
	this->rank_c=rank_c;
	this->degree = degree;
	this->degree_marks=degree_marks;
	this->allocated_pref= allocated_pref;
	this->course_name = course_name;
	this->center_id = center_id;
	this->payment=0;
	this->reported=0;
	this->prn = prn;

	this->preferences = preferences;
}

int Student::getId() const {
	return id;
}
void Student::setId(int id) {
	this->id = id;
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

double Student::getDegreeMarks() const {
	return degree_marks;
}
void Student::setDegreeMarks(double degreeMarks) {
	degree_marks = degreeMarks;
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
	cout<<endl<<this->id<<","<<this->name<<","<<this->rank_a<<","<<this->rank_b<<","<<this->rank_c<<","<<this->degree;
	cout<<","<<this->degree_marks<<","<<this->allocated_pref<<","<<this->course_name<<","<<this->center_id<<","<<this->payment;
	cout<<","<<this->reported<<","<<this->prn<<endl;

	cout<<"\n - PREFERENCES OF STUDENTS ARE :"<<endl;
	for(unsigned int i=0;i<preferences.size();i++)
	{
		cout<<"\t";
		preferences[i].display_pref();
	}
	cout<<endl<<endl;
}

void Student::display_only_stud()
{
	cout<<endl<<this->id<<","<<this->name<<","<<this->rank_a<<","<<this->rank_b<<","<<this->rank_c<<","<<this->degree;
	cout<<","<<this->degree_marks<<","<<this->allocated_pref<<","<<this->course_name<<","<<this->center_id<<","<<this->payment;
	cout<<","<<this->reported<<","<<this->prn<<endl;
}


int Student::getAllocatedPref() const {
	return allocated_pref;
}

const string& Student::getCenterId() const {
	return center_id;
}

void Student::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& Student::getCourseName() const {
	return course_name;
}

void Student::setCourseName(const string& courseName) {
	course_name = courseName;
}

const string& Student::getDegree() const {
	return degree;
}

void Student::setDegree(const string& degree) {
	this->degree = degree;
}

const string& Student::getName() const {
	return name;
}

void Student::setName(const string& name) {
	this->name = name;
}

const string& Student::getPrn() const {
	return prn;
}

void Student::setPrn(const string& prn) {
	this->prn = prn;
}

void Student::setAllocatedPref(int allocatedPref) {
	allocated_pref = allocatedPref;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

