/*
 * Course.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "Course.h"

Course::Course() {
	// TODO Auto-generated constructor stub
	this->id = 0;
	this->name =" ";
	this->fees = 0.0;
	this->ccat_section = " ";
	this->eligible = {};
	this->centers_of_respective_courses = {};

}
Course::Course(int& id, string& name, double& fees, string& ccat_section, vector<eligibilities> eligible,multimap<int,int> centers_of_respective_courses)
{
	this->id = id;
	this->name =name;
	this->fees = fees;
	this->ccat_section = ccat_section;
	this->eligible = eligible;
	this->centers_of_respective_courses = centers_of_respective_courses;
}


const string& Course::getCcatSection() const {
	return ccat_section;
}

void Course::setCcatSection(const string& ccatSection) {
	ccat_section = ccatSection;
}

const vector<eligibilities>& Course::getEligible() const {
	return eligible;
}

void Course::setEligible(const vector<eligibilities>& eligible) {
	this->eligible = eligible;
}

double Course::getFees() const {
	return fees;
}

void Course::setFees(double fees) {
	this->fees = fees;
}

int Course::getId() const {
	return id;
}

void Course::setId(int id) {
	this->id = id;
}

const string& Course::getName() const {
	return name;
}

void Course::setName(const string& name) {
	this->name = name;
}

void Course::display_Course_with_eligibilities_and_centers(AdmissionSystem& a)
{
	cout<<this->id<<","<<this->name<<","<<this->fees<<","<<this->ccat_section<<endl;

	cout<<"  - ELIGIBILITIES FOR THIS COURSE :"<<endl;
	for(unsigned i=0;i<this->eligible.size();i++)
	{
		cout<<"\t";
		this->eligible[i].display_eligibilities();
	}

	cout<<"  - CENTERS AVAILABLE FOR THIS COURSE :"<<endl;
	multimap<int,int>::iterator it = this->centers_of_respective_courses.begin();
	while(it != this->centers_of_respective_courses.end())
	{
		cout<<"\t";
		a.center[it->second].display_centers();

		it++;
	}
	cout<<endl<<endl;
}
void Course::display_Course_with_eligibilities()
{
	cout<<this->id<<","<<this->name<<","<<this->fees<<","<<this->ccat_section<<endl;

	cout<<"  - ELIGIBILITIES FOR THIS COURSE :"<<endl;
	for(unsigned i=0;i<this->eligible.size();i++)
	{
		cout<<"\t";
		this->eligible[i].display_eligibilities();
	}
}


void Course::display_Course_with_centers(AdmissionSystem& a)
{
	cout<<this->id<<","<<this->name<<","<<this->fees<<","<<this->ccat_section<<endl;

	cout<<"  - CENTERS AVAILABLE FOR THIS COURSE :"<<endl;
	multimap<int,int>::iterator it = this->centers_of_respective_courses.begin();
	while(it != this->centers_of_respective_courses.end())
	{
		cout<<"\t";
		a.center[it->second].display_centers();

		it++;
	}
	cout<<endl<<endl;
}

void Course::add_eligibilities(eligibilities& e)
{
	this->eligible.push_back(e);
}
void Course::add_centers(int id, int pos)
{
	this->centers_of_respective_courses.insert(pair<int,int> (id,pos));
}

const multimap<int, int>& Course::getCentersOfRespectiveCourses() const {
	return centers_of_respective_courses;
}

void Course::setCentersOfRespectiveCourses(
		const multimap<int, int>& centersOfRespectiveCourses) {
	centers_of_respective_courses = centersOfRespectiveCourses;
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}

