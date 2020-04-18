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
	this->center = {};

}
Course::Course(int& id, string& name, double& fees, string& ccat_section, vector<eligibilities> eligible,vector<centers> center)
{
	this->id = id;
	this->name =name;
	this->fees = fees;
	this->ccat_section = ccat_section;
	this->eligible = eligible;
	this->center = center;
}


const string& Course::getCcatSection() const {
	return ccat_section;
}

void Course::setCcatSection(const string& ccatSection) {
	ccat_section = ccatSection;
}

const vector<centers>& Course::getCenter() const {
	return center;
}

void Course::setCenter(const vector<centers>& center) {
	this->center = center;
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

void Course::display_Course_with_eligibilities_and_centers()
{
	cout<<this->id<<","<<this->name<<","<<this->fees<<","<<this->ccat_section<<endl;

	cout<<"  - ELIGIBILITIES FOR THIS COURSE :"<<endl;
	for(unsigned i=0;i<this->eligible.size();i++)
	{
		cout<<"\t";
		this->eligible[i].display_eligibilities();
	}

	cout<<"  - CENTERS AVAILABLE FOR THIS COURSE :"<<endl;
	for(unsigned j=0;j<this->center.size();j++)
	{
		cout<<"\t";
		this->center[j].display_centers();
	}
	cout<<endl<<endl;
}

void Course::add_eligibilities(eligibilities& e)
{
	this->eligible.push_back(e);
}
void Course::add_centers(centers& c)
{
	this->center.push_back(c);
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}
