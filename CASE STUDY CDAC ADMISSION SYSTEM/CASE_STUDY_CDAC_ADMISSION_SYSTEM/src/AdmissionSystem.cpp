/*
 * AdmissionSystem.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "AdmissionSystem.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

AdmissionSystem::AdmissionSystem() {
	// TODO Auto-generated constructor stub
	this->degree = {};
	this->capacitie = {};
	this->center = {};
	this->course = {};
	this->student = {};
	this->eligibilitie = {};
	this->preferences = {};

}
AdmissionSystem::AdmissionSystem(vector<degrees> degree,vector<courses> course,vector<eligibilities> eligibilitie,vector<centers> center,vector<capacities> capacitie,vector<students> student,vector<preference> preferences )
{
	this->degree = degree;
	this->capacitie = capacitie;
	this->center = center;
	this->course = course;
	this->student = student;
	this->eligibilitie = eligibilitie;
	this->preferences = preferences;
}

int AdmissionSystem::is_seats_are_full(string id,string course)
{
	for(unsigned i=0;i<this->capacitie.size();i++)
	{
		if(this->capacitie[i].getCenterId() == id && this->capacitie[i].getCourseName() == course)
		{
			if(this->capacitie[i].getCapacity() == this->capacitie[i].getFilledCapacity())
			{
				return 1;
			}
		}
	}
	return 0;
}

void AdmissionSystem::increment_capacity_size_by_one(string id,string course)
{
	for(unsigned i=0;i<this->capacitie.size();i++)
	{
		if(this->capacitie[i].getCenterId() == id && this->capacitie[i].getCourseName() == course)
		{
			int filled_capacity = this->capacitie[i].getFilledCapacity();
			filled_capacity += 1;
			this->capacitie[i].setFilledCapacity(filled_capacity);
		}
	}
}


const vector<capacities>& AdmissionSystem::getCapacitie() const {
	return capacitie;
}

void AdmissionSystem::setCapacitie(const vector<capacities>& capacitie) {
	this->capacitie = capacitie;
}

const vector<centers>& AdmissionSystem::getCenter() const {
	return center;
}

void AdmissionSystem::setCenter(const vector<centers>& center) {
	this->center = center;
}

const vector<courses>& AdmissionSystem::getCourse() const {
	return course;
}

void AdmissionSystem::setCourse(const vector<courses>& course) {
	this->course = course;
}

const vector<degrees>& AdmissionSystem::getDegree() const {
	return degree;
}

void AdmissionSystem::setDegree(const vector<degrees>& degree) {
	this->degree = degree;
}

const vector<eligibilities>& AdmissionSystem::getEligibilitie() const {
	return eligibilitie;
}

void AdmissionSystem::setEligibilitie(
		const vector<eligibilities>& eligibilitie) {
	this->eligibilitie = eligibilitie;
}

const vector<preference>& AdmissionSystem::getPreferences() const {
	return preferences;
}

void AdmissionSystem::setPreferences(const vector<preference>& preferences) {
	this->preferences = preferences;
}

const vector<students>& AdmissionSystem::getStudent() const {
	return student;
}

void AdmissionSystem::setStudent(const vector<students>& student) {
	this->student = student;
}

void AdmissionSystem::display_degrees()
{
	for(unsigned i=0;i<this->degree.size();i++)
	{
		this->degree[i].display_degrees();
	}
}
void AdmissionSystem::display_courses()
{
	for(unsigned i=0;i<this->course.size();i++)
	{
		this->course[i].display_courses();
	}
}
void AdmissionSystem::display_eligibilities()
{
	for(unsigned i=0;i<this->eligibilitie.size();i++)
	{
		this->eligibilitie[i].display_eligibilities();
	}
}
void AdmissionSystem::display_centers()
{
	for(unsigned i=0;i<this->center.size();i++)
	{
		this->center[i].display_centers();
	}
}
void AdmissionSystem::display_capacities()
{
	for(unsigned i=0;i<this->capacitie.size();i++)
	{
		this->capacitie[i].display_capacities();
	}
}
void AdmissionSystem::display_students()
{
	for(unsigned i=0;i<this->student.size();i++)
	{
		this->student[i].display_students();
	}
}
void AdmissionSystem::display_preference()
{
	for(unsigned i=0;i<this->preferences.size();i++)
	{
		this->preferences[i].display_pref();
	}
}

void AdmissionSystem::load_Files(AdmissionSystem & a)
{
	// Loading Degree data from file
	ifstream if_degree("file/degrees.txt");
	if(!if_degree)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}
	string line1;
	while(getline(if_degree,line1))
	{
		//string token[4];
		//stringstream str(line);

		//for(int i=0;i<4;i++)
		//{
		//	getline(str,token[i],',');
		//}
		degrees obj(line1);
		a.degree.push_back(obj);
	}
	if_degree.close();



	// Loading Course data from file
	ifstream if_courses("file/courses.csv");
	if(!if_courses)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}
	string line2;
	while(getline(if_courses,line2))
	{
		string token[4];
		stringstream str(line2);

		for(int i=0;i<4;i++)
		{
			getline(str,token[i],',');
		}
		courses obj(stoi(token[0]),token[1],stod(token[2]),token[3]);
		//a.course.push_back(obj);
		a.course.push_back(obj);
	}
	if_courses.close();


	// Loading eligibilities data from file
	ifstream if_eligibilities("file/eligibilities.csv");
	if(!if_eligibilities)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}
	string line3;
	while(getline(if_eligibilities,line3))
	{
		string token[3];
		stringstream str(line3);

		for(int i=0;i<3;i++)
		{
			getline(str,token[i],',');
		}
		eligibilities obj(token[0],token[1],stod(token[2]));
		a.eligibilitie.push_back(obj);
	}
	if_eligibilities.close();



	// Loading centers data from file
	ifstream if_centers("file/centers.csv");
	if(!if_centers)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}
	string line4;
	while(getline(if_centers,line4))
	{
		string token[5];
		stringstream str(line4);

		for(int i=0;i<5;i++)
		{
			getline(str,token[i],',');
		}
		centers obj(token[0],token[1],token[2],token[3],token[4]);
		a.center.push_back(obj);
	}
	if_centers.close();



	// Loading Capacity data from file
	ifstream if_capacities("file/capacities.csv");

	if(!if_capacities)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}

	string line5;
	while(getline(if_capacities,line5))
	{
		string token[4];
		stringstream str(line5);

		for(int i=0;i<4;i++)
		{
			getline(str,token[i],',');
		}
		capacities obj(token[0],token[1],stod(token[2]),stoi(token[3]));
		a.capacitie.push_back(obj);
	}
	if_capacities.close();


	// Loading students data from file
	ifstream if_students("file/students.csv");

	if(!if_students)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}

	string line6;
	while(getline(if_students,line6))
	{
		string token[13];
		stringstream str(line6);

		for(int i=0;i<13;i++)
		{
			getline(str,token[i],',');
		}
		students obj(stoi(token[0]),token[1],stoi(token[2]),stoi(token[3]),stoi(token[4]),token[5],stod(token[6]),stoi(token[7]),token[8],token[9],stod(token[10]),stoi(token[11]),token[12]);
		a.student.push_back(obj);
	}
	if_students.close();


	// Loading preference data from file
	ifstream if_preference("file/preferences.csv");

	if(!if_preference)
	{
		cout<<"Failed to open file"<<endl;
		return ;
	}

	string line7;
	while(getline(if_preference,line7))
	{
		string token[4];
		stringstream str(line7);

		for(int i=0;i<4;i++)
		{
			getline(str,token[i],',');
		}
		preference obj(stoi(token[0]),stoi(token[1]),token[2],token[3]);
		a.preferences.push_back(obj);
	}
	if_preference.close();
}

AdmissionSystem::~AdmissionSystem() {
	// TODO Auto-generated destructor stub
}

